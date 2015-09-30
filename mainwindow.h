#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cipher.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_encrypt_btn_clicked();

    void on_decrypt_btn_clicked();

    void on_actionOpen_triggered();

    void on_actionOpen_decrypted_text_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    Cipher crip;
};

#endif // MAINWINDOW_H
