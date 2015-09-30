#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //crip = new Cipher();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_encrypt_btn_clicked()
{
    ui->encryption_field->clear();
    if(ui->key_field->text() != crip.getKey())
        crip.setKey(ui->key_field->text());
    ui->encryption_field->setText(crip.encrypt(ui->text_field->toPlainText()));
}

void MainWindow::on_decrypt_btn_clicked()
{
    ui->text_field->clear();
    if(ui->key_field->text() != crip.getKey())
        crip.setKey(ui->key_field->text());
    ui->text_field->setText(crip.decrypt(ui->encryption_field->toPlainText()));
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
           tr("*.txt"));
    if (fileName != "")
    {
           QFile file(fileName);
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
               return;
           }
           QTextStream in(&file);
           ui->encryption_field->setText(in.readAll());
           file.close();
    }
   // ui->encryption_field->setText(dialog->defaultSuffix());
}

void MainWindow::on_actionOpen_decrypted_text_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
           tr("*.txt"));
    if (fileName != "")
    {
           QFile file(fileName);
           if (!file.open(QIODevice::ReadOnly))
           {
               QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
               return;
           }
           QTextStream in(&file);
           ui->text_field->setText(in.readAll());
           file.close();
    }
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("(*.txt)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        } else {
            QTextStream stream(&file);
            stream << ui->encryption_field->toPlainText();
            stream.flush();
            file.close();
        }
    }
}
