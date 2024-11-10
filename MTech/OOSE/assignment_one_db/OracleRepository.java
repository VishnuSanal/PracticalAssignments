package assignment_one_db;

import java.sql.*;

public class OracleRepository {

    static void printStudentList() throws SQLException, ClassNotFoundException {

        String url = "jdbc:oracle:thin:@localhost:1521:xe";

        String username = "vishnu";
        String password = "password";

        Class.forName("oracle.jdbc.driver.OracleDriver");

        Connection connection = DriverManager.getConnection(url, username, password);

        String query = "select * from student";

        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(query);
        resultSet.next();

        while (resultSet.next())
            System.out.println("Name: " + resultSet.getString("name"));

        statement.close();
        connection.close();
    }

}
