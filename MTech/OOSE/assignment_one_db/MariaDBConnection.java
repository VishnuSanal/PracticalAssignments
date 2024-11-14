package assignment_one_db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class MariaDBConnection {
    private static Connection connection = null;

    static Connection getConnection() throws ClassNotFoundException, SQLException {
        if (connection == null) {
            Class.forName("org.mariadb.jdbc.Driver");

            connection = DriverManager.getConnection(
                    "jdbc:mariadb://localhost:3306/test",
                    "root",
                    "root"
            );
        }

        return connection;
    }

}
