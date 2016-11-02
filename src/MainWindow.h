#pragma once

#include <QMainWindow>
#include <QFontDialog>
#include <QFileDialog>

#include "ui_n_a_p.h"

class MainWindow : public QMainWindow, private Ui::MainWindow {
Q_OBJECT
private:
    QString lastFileName;

    void refreshTitle() {
        if (lastFileName.isNull()) {
            setWindowTitle("Unnamed");
        } else {
            setWindowTitle(lastFileName.replace("/", "\\"));
        }

    }

public:
    MainWindow() {
        setupUi(this);
        refreshTitle();
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
        lastFileName = fileName;
        refreshTitle();
    }

    void on_actionFont_triggered() {
        plainTextEdit->setFont(QFontDialog::getFont(NULL, plainTextEdit->font(), this));
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
        lastFileName = fileName;
        refreshTitle();

    }

};

