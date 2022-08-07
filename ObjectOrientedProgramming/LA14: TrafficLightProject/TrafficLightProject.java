import javax.swing.*;
import java.awt.*;
import java.util.Objects;

public class TrafficLightProject {

    public TrafficLightProject() {

        JFrame frame = new JFrame("TrafficLightProject");

        JPanel panel = new JPanel();
        panel.setBounds(125, 50, 50, 50);
        frame.add(panel);

        ButtonGroup buttonGroup = new ButtonGroup();

        for (int i = 0; i < 3; i++) {

            JRadioButton radioButton = new JRadioButton(getColorString(i), false);

            radioButton.setBounds(20, 20 * (i + 1), 100, 20);

            frame.add(radioButton);

            buttonGroup.add(radioButton);

            radioButton.addActionListener(
                    actionEvent ->
                            panel.setBackground(
                                    getColor(actionEvent.getActionCommand())
                            )
            );

        }

        buttonGroup.clearSelection();

        frame.setSize(200, 200);

        frame.setLayout(null);
        frame.setVisible(true);

    }

    private String getColorString(int i) {
        if (i == 0)
            return "Green";
        if (i == 1)
            return "Yellow";

        return "Red";
    }

    private Color getColor(String s) {
        if (Objects.equals(s, "Yellow"))
            return Color.YELLOW;
        if (Objects.equals(s, "Green"))
            return Color.GREEN;

        return Color.RED;
    }

}
