package assignment_one_db;

import java.sql.*;

public class StudentDAOImpl implements StudentDAO {

    private Connection connection = null;

    public StudentDAOImpl() throws SQLException, ClassNotFoundException {
        connection = MariaDBConnection.getConnection();
//        connection = MySQLDBConnection.getConnection();
    }

    @Override
    public void fetchStudentList() throws SQLException {
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
