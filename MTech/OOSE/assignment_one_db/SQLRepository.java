package assignment_one_db;

import java.sql.*;

public class SQLRepository {

     static void printStudentList() throws SQLException, ClassNotFoundException {

        String url = "jdbc:mysql://localhost:3306/student";

        String username = "vishnu";
        String password = "password";

        Class.forName("com.mysql.cj.jdbc.Driver");

        Connection connection = DriverManager.getConnection(url, username, password);

        String query = "select * from students";

        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(query);
        resultSet.next();

        while (resultSet.next())
            System.out.println("Name: " + resultSet.getString("name"));

        statement.close();
        connection.close();
    }

}
