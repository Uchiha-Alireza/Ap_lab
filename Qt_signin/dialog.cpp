#include "dialog.h"
#include "ui_dialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QPushButton>
#include <QCryptographicHash>
#include <QFile>
#include <QTextStream>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->register_2->setEnabled(false);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}
Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_lineEdit_4_textChanged(const QString &email)
{
    checkAllFieldsFilled();
    QRegularExpression emailPattern("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$");
    QRegularExpressionValidator validator(emailPattern, this);
    int pos=0;
    QString temp=email;
    if (validator.validate(temp, pos) != QValidator::Acceptable) {
        ui->lableErrore->setText("                                                                                                                                              Invalid email Format!");
        ui->lableErrore->setStyleSheet("color:red");
        ui->lableErrore->setVisible(true);
        ui->register_2->setEnabled(false);
    } else {
        ui->lableErrore->setVisible(false);
        checkRegistrationValidity();
    }
}
void Dialog::on_lineEdit_5_textChanged(const QString &age)
{
    checkAllFieldsFilled();
    bool ok;
    int ageValue = age.toInt(&ok);
    if (!ok) {
        ui->lableErrore_age->setText("Please enter a valid number.");
        ui->lableErrore_age->setStyleSheet("color:red");
        ui->lableErrore_age->setVisible(true);
        ui->buttonBox->setEnabled(false);
        ui->register_2->setEnabled(false);
    } else if (ageValue < 0 || ageValue > 100) {
        ui->lableErrore_age->setText("Please enter a valid age between 0 and 120.");
        ui->lableErrore_age->setStyleSheet("color:red");
        ui->lableErrore_age->setVisible(true);
        ui->register_2->setEnabled(false);
    } else {
        ui->lableErrore_age->setVisible(false);
        checkRegistrationValidity();
    }
}
void Dialog::checkRegistrationValidity()
{
    bool isValid = true;
    QString email = ui->lineEdit_4->text();
    QString age = ui->lineEdit_5->text();
    QRegularExpression emailPattern("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$");
    QRegularExpressionValidator validator(emailPattern, this);
    int pos = 0;
    if (validator.validate(email, pos) != QValidator::Acceptable) {
        isValid = false;
    }
    bool ok;
    int ageValue = age.toInt(&ok);
    if (!ok || ageValue <= 0 || ageValue > 150) {
        isValid = false;
    }
    if (isValid) {
        ui->register_2->setEnabled(true);
    } else {
        ui->register_2->setEnabled(false);
    }
}


void Dialog::on_lineEdit_textChanged(const QString &username)
{
    checkAllFieldsFilled();
}


void Dialog::on_lineEdit_2_textChanged(const QString &password)
{
    checkAllFieldsFilled();
}
void Dialog::on_lineEdit_3_textChanged(const QString &name)
{
    checkAllFieldsFilled();
}
void Dialog::checkAllFieldsFilled()
{
    bool allFilled =
        !ui->lineEdit->text().isEmpty() &&
        !ui->lineEdit_2->text().isEmpty() &&
        !ui->lineEdit_4->text().isEmpty() &&
        !ui->lineEdit_5->text().isEmpty();
    if (allFilled) {
        ui->register_2->setEnabled(true);
    } else {
        ui->register_2->setEnabled(false);
    }
}
void Dialog::on_register_2_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString name = ui->lineEdit_3->text();
    QString email = ui->lineEdit_4->text();
    QString age = ui->lineEdit_5->text();
    QString gender = ui->comboBox->currentText();
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
    QFile file("E:/Ap_lab/Ap_lab/Qt_signin/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->labelr->setText("Cannot open file for saving data!");
        ui->labelr->setStyleSheet("color:red");
        ui->labelr->setVisible(true);
        return;
    }
    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        QString existingUsername = line.split(",").first();
        if (existingUsername == username) {
            ui->labelr->setText("The username already exists. Please choose another username!");
            ui->labelr->setStyleSheet("color:red");
            file.close();
            return;
        }
    }
    file.close();
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        ui->labelr->setText("Cannot open file for saving data!");
        ui->labelr->setStyleSheet("color:red");
        ui->labelr->setVisible(true);
        return;
    }
    QTextStream out(&file);
    out << username << "," << hashedPassword << "," << name << "," << email << "," << age << "," << gender << "\n";
    file.close();
    ui->labelr->setText("Registration successful!");
    ui->labelr->setStyleSheet("color:green");
    ui->labelr->setVisible(true);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}
