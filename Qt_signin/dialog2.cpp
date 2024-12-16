#include "dialog2.h"
#include "ui_dialog2.h"
#include <QCryptographicHash>
#include <QFile>

Dialog2::Dialog2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->pushButton->setEnabled(false);
    ui->buttonBox->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    QFile file("E:/Ap_lab/Ap_lab/Qt_signin/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->statuslabel->setText("Error opening file!");
        ui->statuslabel->setStyleSheet("color: red;");
        return;
    }

    QTextStream in(&file);
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    bool userFound = false;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() >= 6) {
            QString fileUsername = parts[0].trimmed();
            QString filePassword = parts[1].trimmed();

            if (fileUsername == username && filePassword == hashedPassword) {
                userFound = true;
                break;
            }
        }
    }
    file.close();
    if (userFound) {
        ui->statuslabel->setText("Login successful!");
        ui->statuslabel->setStyleSheet("color: green;");
    } else {
        ui->statuslabel->setText("Invalid username or password.");
        ui->statuslabel->setStyleSheet("color: red;");
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    }
void Dialog2::on_lineEdit_textChanged(const QString &arg1)
{
    checkFields();
}
void Dialog2::on_lineEdit_2_textChanged(const QString &arg1)
{
    checkFields();
}
void Dialog2::checkFields()
{
    bool areFilled = !ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty();
    ui->pushButton->setEnabled(areFilled);

}
