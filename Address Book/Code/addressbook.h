#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QMainWindow>
#include <QMessageBox>
#include <memory>
#include "Search.h"
#include "Registrate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddressBook; }
QT_END_NAMESPACE

class IExceptions;

class AddressBook : public QMainWindow
{
    Q_OBJECT

public:
    AddressBook(QWidget *parent = nullptr);
    ~AddressBook();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_RegisterB_pressed();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::AddressBook *ui;

private:
    std::unique_ptr<Search> pSearch;
    std::unique_ptr<IExceptions> pExcept;
};



class IExceptions
{
public:
    virtual void ThrowException(const std::string&) = 0;

protected:
    std::unique_ptr<QMessageBox> pQB = std::make_unique<QMessageBox>();
};

class ExceptionUser: public IExceptions
{
public:
    void ThrowException(const std::string&) override;
};

class ExceptionAddress: public IExceptions
{
public:
    void ThrowException(const std::string&) override;
};

class ExceptionID: public IExceptions
{
public:
    void ThrowException(const std::string&) override;
};

class ExceptionOther: public IExceptions
{
public:
    void ThrowException(const std::string&) override;
};

#endif // ADDRESSBOOK_H
