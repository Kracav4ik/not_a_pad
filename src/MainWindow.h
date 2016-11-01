#pragma once

#include <QMainWindow>
#include <QFileDialog>

#include "ui_n_a_p.h"

class MainWindow : public QMainWindow, private Ui::MainWindow {
Q_OBJECT
public:
    MainWindow() {
        setupUi(this);
        show();
    }

public slots:

    void on_actionSave_As_triggered() {
        QString fileName = QFileDialog::getSaveFileName(this, "Save file");
        printf("%s\n", fileName.toUtf8().data());
        if (fileName.isNull()) {
            return;
        }
        QFile file(fileName);
        file.open(QIODevice::Text | QIODevice::WriteOnly);
        file.write(plainTextEdit->toPlainText().toUtf8());

    }

    void on_actionOpen_triggered() {
        QString fileName = QFileDialog::getOpenFileName(this, "Open file");
        printf("%s\n", fileName.toUtf8().data());
        if (fileName.isNull()) {
            return;
        }
        QFile file(fileName);
        file.open(QIODevice::Text | QIODevice::ReadOnly);
        QString str = QString::fromUtf8(file.readAll());
        plainTextEdit->setPlainText(str);

    }

};

