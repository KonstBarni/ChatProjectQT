#include <iostream>
#include "DataBase.h"
#include <memory>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlRecord>



bool DataBase::connect(QString host, unsigned int port, QString dbname, QString user, QString password)
{
    addDatabaseForm dbParams;
    QStringList par = dbParams.getResult();

    if(!par.empty())
    {
        _mysql = QSqlDatabase::addDatabase("QMYSQL");
        _mysql.setHostName(par[0]);
        _mysql.setPort(par[1].toInt());
        _mysql.setDatabaseName(par[2]);
        _mysql.setUserName(par[3]);
        _mysql.setPassword(par[4]);
        if (!_mysql.open()){
            _connection = false;
            QMessageBox::warning(nullptr, "Error", _mysql.lastError().text());
        }
        else {
            _connection = true;
            qDebug("success");
            executeQueryWithoutResult("use " +par[2]+ ";");
        }
    }
    return _connection;
}

bool DataBase::hasConnection()
{
    return _connection;
}

QVector<QString> DataBase::queryResult(QString queryText)
{
    QVector<QString> result;
    QSqlQuery query(_mysql);
    query.prepare(queryText);
    if (!query.exec()) {
        QMessageBox::warning(nullptr, "Error", query.lastError().text());
    }
    while (query.next()) {
        int count = query.record().count();
        for (int i = 0; i < count; i++) {
            result.push_back(query.value(i).toString());
        }
    }

    return result;
}

void DataBase::executeQueryWithoutResult(QString queryText)
{
    QSqlQuery query(_mysql);
    query.prepare(queryText);
    if (!query.exec()) {
        QMessageBox::warning(nullptr, "Error", query.lastError().text());
    }
}

void DataBase::close()
{
    _mysql.close();
}

DataBase::DataBase()
{
    _connection = false;
}

DataBase::~DataBase()
{
    close();
}
