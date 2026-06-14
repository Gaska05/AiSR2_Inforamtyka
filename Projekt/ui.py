from PyQt6.QtWidgets import QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QListWidget, QMessageBox, QComboBox, \
    QSpinBox, QLabel
from logic import MundialLogic


class MundialUI(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Symulator Tabeli Mundialu")
        self.setGeometry(700, 200, 800, 600)

        self.logic = MundialLogic()

        self.layout = QVBoxLayout()

        self.standings_list = QListWidget()
        self.layout.addWidget(self.standings_list)

        self.input_layout = QHBoxLayout()

        self.team1_combo = QComboBox()
        self.team1_combo.addItems(self.logic.get_team_names())
        self.input_layout.addWidget(self.team1_combo)

        self.score1_input = QSpinBox()
        self.score1_input.setRange(0, 99)
        self.input_layout.addWidget(self.score1_input)

        self.separator_label = QLabel("-")
        self.input_layout.addWidget(self.separator_label)

        self.score2_input = QSpinBox()
        self.score2_input.setRange(0, 99)
        self.input_layout.addWidget(self.score2_input)

        self.team2_combo = QComboBox()
        self.team2_combo.addItems(self.logic.get_team_names())
        self.input_layout.addWidget(self.team2_combo)

        self.layout.addLayout(self.input_layout)

        self.add_button = QPushButton("Dodaj Wynik")
        self.add_button.clicked.connect(self.add_result)
        self.layout.addWidget(self.add_button)

        self.reset_button = QPushButton("Resetuj Tabelę")
        self.reset_button.clicked.connect(self.reset_data)
        self.layout.addWidget(self.reset_button)

        self.setLayout(self.layout)

        self.update_standings()

    def add_result(self):
        team1 = self.team1_combo.currentText()
        team2 = self.team2_combo.currentText()
        g1 = self.score1_input.value()
        g2 = self.score2_input.value()

        success, message = self.logic.add_match(team1, team2, g1, g2)

        if success:
            self.score1_input.setValue(0)
            self.score2_input.setValue(0)
            self.update_standings()
        else:
            QMessageBox.warning(self, "Błąd", message)

    def reset_data(self):
        self.logic.reset_standings()
        self.score1_input.setValue(0)
        self.score2_input.setValue(0)
        self.update_standings()

    def update_standings(self):
        self.standings_list.clear()
        self.standings_list.addItems(self.logic.get_standings())