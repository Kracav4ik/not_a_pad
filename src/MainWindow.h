#pragma once

#include <QMainWindow>

#include "ui_n_a_p.h"

class MainWindow: public QMainWindow, private Ui::MainWindow{
    Q_OBJECT
public:
    MainWindowa() {
        setupUi(this);
        show();
    }
};

