package assignment_one_db;

import java.sql.*;

public class SQLConnection {

    static void printStudentList() throws SQLException, ClassNotFoundException {

        String url = "jdbc:mysql://localhost:3306/test";

        String username = "root";
        String password = "root";

        Class.forName("org.mariadb.jdbc.Driver");

        Connection connection = DriverManager.getConnection(url, username, password);

        String query = "SELECT * FROM STUDENTS";

        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(query);
        resultSet.next();

        while (resultSet.next()) {
            System.out.println(resultSet.getString("ID") + " : " + resultSet.getString("NAME"));
        }

        statement.close();
        connection.close();
    }

}
