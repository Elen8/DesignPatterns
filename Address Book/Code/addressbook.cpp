
#include "ui_addressbook.h"
#include "addressbook.h"
#include <Parser.h>

AddressBook::AddressBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddressBook)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    DB* db = db->db_ins();
    db->ReadFromFile();
}

AddressBook::~AddressBook()
{
    DB* db = db->db_ins();
    db->SaveToFile();
    delete ui;
}

void AddressBook::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    if (ui->Name->isChecked() && ui->lineEdit_3->text() != "")
    {
        pSearch = std::make_unique<Search>(0);
        pSearch->ClearResults();
        pSearch->SearchBy(0, ui->lineEdit_3->text().toStdString());

        if (pSearch->GetErrorType() == 1)
        {
            pExcept = std::make_unique<ExceptionUser>();
            pExcept->ThrowException("Wrong name input\t");
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(2);
            for (int i = 0; i < pSearch->CountOfResults(); ++i)
            {
                ui->listWidget->addItem(QString::fromStdString(pSearch->GetResultAt(i)));
            }
        }
    }
    else if (ui->Address->isChecked() && ui->lineEdit_3->text() != "")
    {
        pSearch = std::make_unique<Search>(1);
        pSearch->ClearResults();
        pSearch->SearchBy(1, ui->lineEdit_3->text().toStdString());
        if (pSearch->GetErrorType() == 2)
        {
            pExcept = std::make_unique<ExceptionAddress>();
            pExcept->ThrowException("Wrong address input\t");
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(2);
            for (int i = 0; i < pSearch->CountOfResults(); ++i)
            {
                ui->listWidget->addItem(QString::fromStdString(pSearch->GetResultAt(i)));
            }
        }
    }
    else if (ui->ID->isChecked() && ui->lineEdit_3->text() != "")
    {
        pSearch = std::make_unique<Search>(2);
        pSearch->ClearResults();
        pSearch->SearchBy(2, ui->lineEdit_3->text().toStdString());
        if (pSearch->GetErrorType() == 3)
        {
            pExcept = std::make_unique<ExceptionID>();
            pExcept->ThrowException("Wrong ID input\t");
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(2);
            for (int i = 0; i < pSearch->CountOfResults(); ++i)
            {
                ui->listWidget->addItem(QString::fromStdString(pSearch->GetResultAt(i)));
            }
        }
    }
    else
    {
        pExcept = std::make_unique<ExceptionOther>();
        pExcept->ThrowException("Choose any option and fill the blank line!\t");
        return;
    }
    pSearch->ClearResults();

}

void AddressBook::on_pushButton_4_clicked()
{
    ui->listWidget->clear();
    ui->stackedWidget->setCurrentIndex(0);
    ui->listWidget->clear();
    while(ui->listWidget->count()>0)
    {
        ui->listWidget->takeItem(0);
    }

}

void AddressBook::on_RegisterB_pressed()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void AddressBook::on_pushButton_5_clicked()
{
    if (ui->lineEdit_4->text() == "" || ui->lineEdit_5->text() == "")
    {
        pExcept = std::make_unique<ExceptionOther>();
        pExcept->ThrowException("Invalid input!\t");
    }
    else
    {
        std::string user = ui->lineEdit_4->text().toStdString();
        std::string address = ui->lineEdit_5->text().toStdString();
        std::unique_ptr<Registrate> reg = std::make_unique<Registrate>(user, address);
        std::string result = reg->Reg();
        if(std::isdigit(result[0]))
        {
            pExcept = std::make_unique<ExceptionOther>();
            pExcept->ThrowException(result);
            ui->stackedWidget->setCurrentIndex(0);
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
        }
        else
        {
            pExcept = std::make_unique<ExceptionOther>();
            pExcept->ThrowException(result);
        }
    }
}

void AddressBook::on_pushButton_6_clicked()
{
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void ExceptionUser::ThrowException(const std::string& message)
{
    pQB->setText(QString::fromStdString(message));
    pQB->exec();
}

void ExceptionAddress::ThrowException(const std::string& message)
{
    pQB->setText(QString::fromStdString(message));
    pQB->exec();
}

void ExceptionID::ThrowException(const std::string& message)
{
    pQB->setText(QString::fromStdString(message));
    pQB->exec();
}

void ExceptionOther::ThrowException(const std::string& message)
{
    pQB->setText(QString::fromStdString(message));
    pQB->exec();
}
