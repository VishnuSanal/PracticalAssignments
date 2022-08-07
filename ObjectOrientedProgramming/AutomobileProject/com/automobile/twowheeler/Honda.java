package com.automobile.twowheeler;

import com.automobile.Vehicle;

public class Honda extends Vehicle{
	
	public String getModelName(){
		return "Honda model name";
	}
	public String getRegisterName(){
		return "Honda register number";
	}
	public String getOwnerName(){
		return "Honda owner name";
	}
	
	public int getSpeed(){
		return 360;
	}
	
	public void cdPlayer(){
		System.out.println("Honda operating CD Player...");
	}
	
}
