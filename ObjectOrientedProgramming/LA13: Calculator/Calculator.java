import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator implements ActionListener {

    private static final char[] buttons = {'7', '8', '9', '*', '4', '5', '6', '/', '1', '2', '3', '-', '0', '=', 'C', '+'};

    private static double first = 0, second = 0;
    private static char operation = '~';

    private final JLabel label = new JLabel("0");

    public Calculator() {

        JFrame frame = new JFrame("Calculator");

        frame.setSize(500, 500);

        int x = 0, y = 0;

        for (int i = 0; i < buttons.length; i++) {

            JButton button = new JButton(String.valueOf(buttons[i]));

            button.setBounds(x++ * 70 + 20, y * 70 + 20, 50, 50);

            if ((i - 3) % 4 == 0) {
                x = 0;
                y++;
            }

            button.addActionListener(this);

            frame.add(button);

        }

        label.setBounds(20, 300, 320, 50);

        frame.add(label);

        frame.setLayout(null);
        frame.setVisible(true);

    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {

        if (operation == '`') {
            resetCalculator();
            label.setText("0");
        }

        char c = actionEvent.getActionCommand().charAt(0);

        if (Character.isDigit(c)) {
            label.setText(label.getText() + " " + c);

            if (operation == '~')
                first = first * 10 + Integer.parseInt(actionEvent.getActionCommand());
            else
                second = second * 10 + Integer.parseInt(actionEvent.getActionCommand());

            return;
        }

        if (c == '+' || c == '-' || c == '*' || c == '/') {

            if (operation == '~') {

                label.setText(first + " " + c);

                operation = c;

            }

            return;

        }

        if (c == '=') {

            label.setText(
                    label.getText() + " = " + doOperation()
            );

            operation = '`';
        }

        if (c == 'C')
            resetCalculator();

    }

    private void resetCalculator() {
        operation = '~';
        first = second = 0;
        label.setText("");
    }

    private String doOperation() {

        try {

            if (operation == '+')
                return String.valueOf(first + second);

            if (operation == '-')
                return String.valueOf(first - second);

            if (operation == '*')
                return String.valueOf(first * second);

            if (operation == '/')
                return String.valueOf(first / second);

        } catch (ArithmeticException e) {
            e.printStackTrace();
            resetCalculator();
            return "Invalid";
        }

        return "Invalid";

    }
}