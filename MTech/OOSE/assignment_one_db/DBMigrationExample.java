package assignment_one_db;

public class DBMigrationExample {
    public static void main(String[] args) throws Exception {
        SQLRepository.printStudentList();
        OracleRepository.printStudentList();
    }
}
