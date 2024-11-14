package assignment_one_db;

import java.sql.SQLException;

public class Repository {
    static void printStudentList() throws SQLException, ClassNotFoundException {
        new StudentDAOImpl().fetchStudentList();
    }
}
