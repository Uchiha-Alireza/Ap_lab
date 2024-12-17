#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <set>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_2->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    ui->pushButton->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_I));
    ui->pushButton_3->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_E));
    ui->pushButton_4->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_L));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &l1)
{
    CheckInputs();
}


void MainWindow::on_lineEdit_2_textChanged(const QString &l2)
{
    CheckInputs();
}

void MainWindow::on_lineEdit_3_textChanged(const QString &l3)
{
    CheckInputs();
}

void MainWindow::CheckInputs(){
    if (!ui->lineEdit->text().isEmpty() &&
        !ui->lineEdit_2->text().isEmpty()&&
        !ui->lineEdit_3->text().isEmpty()) {
            ui->pushButton_7->setEnabled(true);
    }
    else {
        ui->pushButton_7->setEnabled(false);

    }
}

void MainWindow::on_pushButton_7_clicked()
{
    QString name = ui->lineEdit->text();
    QString number = ui->lineEdit_2->text();
    QString type = ui->lineEdit_3->text();
    if (Cbooks.find(name) != Cbooks.end()) {
        ui->label_7->setStyleSheet("color:red");
        ui->label_7->setText("This contact already exists!");
        return;
    }
    Cbooks[name].push_back(std::make_pair(type, number));
    qDebug() << "Contact added: " << name << " - " << number << " (" << type << ")";
    ui->label_7->setStyleSheet("color:green");
    ui->label_7->setText("Add contact successful.");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    CheckInputs();
}

void MainWindow::CheckInputs2()
{
    if (!ui->lineEdit_4->text().isEmpty() &&
        !ui->lineEdit_5->text().isEmpty()&&
        !ui->lineEdit_6->text().isEmpty()) {
        ui->pushButton_8->setEnabled(true);
    }
    else {
        ui->pushButton_8->setEnabled(false);

    }
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    CheckInputs2();
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    CheckInputs2();
}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    CheckInputs2();
}

void MainWindow::on_pushButton_8_clicked()
{
    QString oldName = ui->lineEdit_4->text();
    QString newNumber = ui->lineEdit_5->text();
    QString newType = ui->lineEdit_6->text();
    if (Cbooks.find(oldName) != Cbooks.end()) {
        auto &contacts = Cbooks[oldName];
        bool updated = false;
        for (auto &contact : contacts) {
            if (contact.first == newType) {
                contact.second = newNumber;
                updated = true;
                break;
            }
        }
        if (!updated) {
            contacts.push_back({newType, newNumber});
        }
        ui->label_11->setStyleSheet("color:green");
        ui->label_11->setText("Contact updated successfully.");
    } else {
        ui->label_11->setStyleSheet("color:red");
        ui->label_11->setText("Contact does not exist.");
    }
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    CheckInputs2();
}

void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    CheckInputs3();
}

void MainWindow::CheckInputs3()
{
    if (!ui->lineEdit_7->text().isEmpty()) {
        ui->pushButton_9->setEnabled(true);
    }
    else {
        ui->pushButton_9->setEnabled(false);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    QString name = ui->lineEdit_7->text();
    if (Cbooks.find(name) != Cbooks.end()) {
        Cbooks.erase(name);
        ui->label_14->setStyleSheet("color:green");
        ui->label_14->setText("Contact deleted successfully.");
    } else {
        ui->label_14->setStyleSheet("color:red");
        ui->label_14->setText("Contact does not exist.");
    }
    ui->lineEdit_7->clear();
    CheckInputs3();
}

void MainWindow::CheckInputs4()
{
    if (!ui->lineEdit_8->text().isEmpty()) {
        ui->pushButton_10->setEnabled(true);
    }
    else {
        ui->pushButton_10->setEnabled(false);
    }
}

void MainWindow::on_lineEdit_8_textChanged(const QString &arg1)
{
    CheckInputs4();
}


void MainWindow::on_pushButton_10_clicked()
{
    QString name = ui->lineEdit_8->text();
    QString labelMessage;
    QString labelColor;
    if (Cbooks.find(name) != Cbooks.end()) {
        std::list<std::pair<QString, QString>> contacts = Cbooks[name];
        Favorite[name] = contacts;
        labelMessage = "Contact added to favorites successfully.";
        labelColor = "green";
    } else {
        labelMessage = "Contact does not exist in the main list.";
        labelColor = "red";
    }
    ui->label_17->setStyleSheet("color:" + labelColor);
    ui->label_17->setText(labelMessage);
    ui->lineEdit_8->clear();
}

void MainWindow::CheckInputs5()
{
    if (!ui->lineEdit_9->text().isEmpty()) {
        ui->pushButton_11->setEnabled(true);
    }
    else {
        ui->pushButton_11->setEnabled(false);
    }
}

void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    CheckInputs5();
}

void MainWindow::on_pushButton_11_clicked()
{
    QString name = ui->lineEdit_9->text();
    QString labelMessage;
    QString labelColor;
    if (Favorite.find(name) != Favorite.end()) {
        Favorite.erase(name);
        labelMessage = "Contact removed from favorites successfully.";
        labelColor = "green";
    } else {
        labelMessage = "Contact does not exist in favorites.";
        labelColor = "red";
    }
    ui->label_20->setStyleSheet("color:" + labelColor);
    ui->label_20->setText(labelMessage);
    ui->lineEdit_9->clear();
}

void MainWindow::on_pushButton_12_clicked()
{
    QString output;
    if (Cbooks.empty()) {
        output = "No Contacts!";
    } else {
        for (const auto &contact : Cbooks) {
            QString name = contact.first;
            for (const auto &info : contact.second) {
                QString type = info.first;
                QString number = info.second;
                output += "Name: " + name + "\n";
                output += "Number: " + number + "\n";
                output += "Type: " + type + "\n\n";
            }
        }
    }
    ui->textEdit->setPlainText(output);
}

void MainWindow::on_pushButton_13_clicked()
{
    QString output;
    if (Cbooks.empty()) {
        output = "No Contacts!";
    } else {
        for (const auto &contact : Cbooks) {
            for (const auto &info : contact.second) {
                QString number = info.second;
                output += "Number: " + number + "\n";
            }
        }
    }
    ui->textEdit_2->setPlainText(output);
}

void MainWindow::on_pushButton_14_clicked()
{
    QString output;
    if (Favorite.empty()) {
        output = "Favorit list is empty!";
    } else {
        for (const auto &contact : Favorite) {
            QString name = contact.first;
            for (const auto &info : contact.second) {
                QString type = info.first;
                QString number = info.second;
                output += "Name: " + name + "\n";
                output += "Number: " + number + "\n";
                output += "Type: " + type + "\n\n";
            }
        }
    }
    ui->textEdit_3->setPlainText(output);
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile mainFile("E:/Qt/untitled/contacts.txt");
    QFile favoriteFile("E:/Qt/untitled/favorites.txt");
    std::set<QString> existingContacts;
    std::set<QString> existingFavorites;
    if (mainFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&mainFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            existingContacts.insert(line);
        }
        mainFile.close();
    }
    if (favoriteFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&favoriteFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            existingFavorites.insert(line);
        }
        favoriteFile.close();
    }
    if (mainFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&mainFile);
        for (const auto &contact : Cbooks) {
            QString name = contact.first;
            for (const auto &info : contact.second) {
                QString type = info.first;
                QString number = info.second;
                QString line = name + " - " + number + " (" + type + ")";
                if (existingContacts.find(line) == existingContacts.end()) {
                    out << line << "\n";
                    existingContacts.insert(line);
                }
            }
        }
        mainFile.close();
    }
    if (favoriteFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&favoriteFile);
        for (const auto &contact : Favorite) {
            QString name = contact.first;
            for (const auto &info : contact.second) {
                QString type = info.first;
                QString number = info.second;
                QString line = name + " - " + number + " (" + type + ")";
                if (existingFavorites.find(line) == existingFavorites.end()) {
                    out << line << "\n";
                    existingFavorites.insert(line);
                }
            }
        }
        favoriteFile.close();
    }
    ui->label_24->setStyleSheet("color:green");
    ui->label_24->setText("Contacts saved successfully.");
}

void MainWindow::on_pushButton_4_clicked()
{
    QFile mainFile("E:/Qt/untitled/contacts.txt");
        QFile favoriteFile("E:/Qt/untitled/favorites.txt");

        QString labelMessage;
        QString labelColor;

        Cbooks.clear();
        Favorite.clear();

        if (mainFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&mainFile);
            while (!in.atEnd()) {
                QString line = in.readLine();

                QStringList parts = line.split(" - ");
                if (parts.size() == 2) {
                    QString name = parts[0];
                    QStringList subParts = parts[1].split(" (");
                    if (subParts.size() == 2) {
                        QString number = subParts[0];
                        QString type = subParts[1].chopped(1);
                        Cbooks[name].push_back({type, number});
                    }
                }
            }
            mainFile.close();
        } else {
            labelMessage = "Failed to load from contacts file.";
            labelColor = "red";
        }
        if (favoriteFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&favoriteFile);
            while (!in.atEnd()) {
                QString line = in.readLine();

                QStringList parts = line.split(" - ");
                if (parts.size() == 2) {
                    QString name = parts[0];
                    QStringList subParts = parts[1].split(" (");
                    if (subParts.size() == 2) {
                        QString number = subParts[0];
                        QString type = subParts[1].chopped(1);
                        Favorite[name].push_back({type, number});
                    }
                }
            }
            favoriteFile.close();
        } else {
            labelMessage = "Failed to load from favorites file.";
            labelColor = "red";
        }

        if (labelMessage.isEmpty()) {
            labelMessage = "Data loaded successfully.";
            labelColor = "green";
        }

        ui->label_24->setStyleSheet("color:" + labelColor);
        ui->label_24->setText(labelMessage);
}

void MainWindow::on_pushButton_clicked()
{
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                while (!in.atEnd()) {
                    QString line = in.readLine();
                    QStringList parts = line.split(" - ");
                    if (parts.size() >= 2) {
                        QString name = parts[0];
                        QString numberType = parts[1];
                        QStringList numberTypeParts = numberType.split(" (");
                        if (numberTypeParts.size() == 2) {
                            QString number = numberTypeParts[0];
                            QString type = numberTypeParts[1].chopped(1);
                            Cbooks[name].push_back(qMakePair(type, number));
                        }
                    }
                }
                file.close();
                ui->label_24->setStyleSheet("color:green");
                ui->label_24->setText("Contacts loaded successfully.");
            } else {
                ui->label_24->setStyleSheet("color:red");
                ui->label_24->setText("Failed to open file.");
            }
        } else {
            ui->label_24->setStyleSheet("color:red");
            ui->label_24->setText("No file selected.");
        }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->label->setStyleSheet("color:red");
        ui->label->setText("Error opening file for saving.");
        return;
    }
    QTextStream out(&file);
    for (const auto &contact : Cbooks) {
        QString name = contact.first;
        for (const auto &info : contact.second) {
            QString type = info.first;
            QString number = info.second;
            QString line = name + " - " + number + " (" + type + ")";
            out << line << "\n";
        }
    }
    file.close();
    ui->label_24->setStyleSheet("color:green");
    ui->label_24->setText("Contacts exported successfully.");
}

