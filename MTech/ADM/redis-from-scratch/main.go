// https://www.build-redis-from-scratch.dev/en/introduction

package main

import (
	"fmt"
	"net"
	"strings"
)

func main() {

	listener, err := net.Listen("tcp", ":6379")
	if err != nil {
		fmt.Println("listen: ", err)
		return
	}

	aof, err := NewAof("database.aof")
	if err != nil {
		fmt.Println("aof: ", err)
		return
	}
	defer aof.Close()

	aof.Read(func(value Value) {
		command := strings.ToUpper(value.array[0].bulk)
		args := value.array[1:]

		handler, ok := Handlers[command]
		if !ok {
			fmt.Println("Invalid command: ", command)
			return
		}

		handler(args)
	})

	connection, err := listener.Accept()
	if err != nil {
		fmt.Println("accept: ", err)
		return
	}

	defer connection.Close()

	for {
		response := NewResponse(connection)
		value, err := response.Read()
		if err != nil {
			fmt.Println("response read: ", err)
			return
		}

		if value.typ != "array" {
			fmt.Println("Invalid request, expected array")
			continue
		}

		if len(value.array) == 0 {
			fmt.Println("Invalid request, expected array length > 0")
			continue
		}

		command := strings.ToUpper(value.array[0].bulk)
		args := value.array[1:]

		writer := NewWriter(connection)

		handler, ok := Handlers[command]
		if !ok {
			fmt.Println("Invalid command: ", command)
			writer.Write(Value{typ: "string", str: ""})
			continue
		}

		if command == "SET" || command == "HSET" {
			aof.Write(value)
		}

		result := handler(args)
		writer.Write(result)
	}
}
