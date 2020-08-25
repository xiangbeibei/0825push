#ifndef DATABASE_H
#define DATABASE_H
#define DATABASE_PATH "./data/database.db"
#include <QString>
#include<QtSql/qsql.h>
#include<Qtsql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
/*--------------数据转存结构体-------------------*/
typedef struct Alldata
{
    QString Time;
    QString Result;
    QString Name;
    QString ID;
    QString Gender;
    QString Nation;
    QString Birthtime;
    QString Home;
    QString Office;
    QString ValidTime;
    QString idimage;
    QString faceimage;
}Alldata;



class database
{
public:
    //~database();
    bool connect_database(QString dbpath);//连接数据库
    void creat_database();
    int selectdata_all(QString conditions);//查询所有数据
    bool selectdata_noimage(QSqlQueryModel* model,QString condition,int limitIndex);//作为model显示无图片路径的查询，包含分页查询
    bool deletedata(QString condition);//数据删除操作
    int insertdata(int count);//导入插入操作（查重）
    QString getfaceimage(QString condition);//获取人脸图片路径
    QString getidimage(QString condition);//获取身份证头像路径
    void database_close();//断开数据库连接
    void insertstructdata(Alldata all_data);//结构体数组指针，结构体数组长度
    static database* getmain_database()
    {
        if(main_database==NULL)
        {
            main_database=new database;
        }
        return main_database;
    }
    static database* Get_database()
    {
        return getmain_database();
    }

public:
//    Alldata *alldata;//结构体
    QVector<Alldata> alldata;
private:
    static database *main_database;
    database();
    QSqlDatabase db;//数据库
    enum      {PageRecordCount = 20};//每页记录数

};

#endif // DATABASE_H

