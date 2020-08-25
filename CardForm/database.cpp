#include "database.h"
#include <QObject>
#include <QWidget>
#include <QString>
#include<QtSql/qsql.h>
#include<Qtsql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<QVariant>
#include<QMessageBox>
#include<QDir>
#include<QFileDialog>

#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
database* database::main_database=NULL;
database::database()
{
    QFile database_file(DATABASE_PATH);
    if(database_file.exists())
    {
        if(!connect_database(DATABASE_PATH))//构造函数默认数据库地址
        {
            qDebug()<<"连接失败";
            QMessageBox::warning(NULL,"提示","打开数据库失败","确定");
        }
    }
    else
    {
        QString dbPath = "./data/";
        QDir dbDir;
        if(!dbDir.exists(dbPath))
            dbDir.mkpath(dbPath);
        creat_database();
    }
}
void database::creat_database()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_PATH);
    db.open();
    QSqlQuery create_table_query;
    QString table_str=QString("CREATE TABLE DATAMANAGER (Time varchar NOT NULL PRIMARY KEY,");
    table_str+=QString("Result varchar NOT NULL,");
    table_str+=QString("Name varchar NOT NULL,");
    table_str+=QString("ID varchar NOT NULL,");
    table_str+=QString("Gender varchar NOT NULL,");
    table_str+=QString("Nation varchar,");
    table_str+=QString("Bithtime TEXT NOT NULL,");
    table_str+=QString("Home TEXT,");
    table_str+=QString("Office TEXT,");
    table_str+=QString("ValidTime TEXT,");
    table_str+=QString("idimage TEXT,");
    table_str+=QString("faceimage TEXT)");
    bool success=create_table_query.exec(table_str);
    if(!success)
    {
        QMessageBox::warning(NULL,"提示","数据库表创建失败","确定");
        return;
    }
}
void database::database_close()
{
    db.close();//断开数据库连接
}
bool database::connect_database(QString dbpath)//根据路径连接数据库
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbpath);
    if(db.isOpen())
    {
        db.close();
    }
    bool ok=db.open();
    return ok;
}
/*-----------------根据条件查询所有数据并存入结构体---------------------*/
int database::selectdata_all(QString conditions)
{
    alldata.clear();
    int record_count=0;//数据库总记录数
    if(!db.open())
    {
        db.open();
    }
    QSqlQuery query;
    QString str=QString("select * from DATAMANAGER where 1=1 ");
    str+=conditions;
    str+="order by Time ";//以检验时间排序
    bool success=query.exec(str);
    if(!success)
    {
        return -1;
    }
    else
    {
        if(query.last()!=NULL)
        {
            query.last();
            int num=query.at()+1;//根据数据库总记录数动态定义结构体数组大小
               for(int i=0;i<=num;i++)
               {
                   Alldata a;
                   alldata.append(a);
               }
            qDebug()<<num;
        }
        else
        {
            return 0;
        }
        query.first();
        while(true)//把数据存入结构体数组
        {
            alldata[record_count].Time=query.value(0).toString();           //检验时间
            alldata[record_count].Result=query.value(1).toString();         //结果
            alldata[record_count].Name=query.value(2).toString();           //姓名
            alldata[record_count].ID=query.value(3).toString();             //身份证号
            alldata[record_count].Gender=query.value(4).toString();         //性别
            alldata[record_count].Nation=query.value(5).toString();         //民族
            alldata[record_count].Birthtime=query.value(6).toString();      //生日
            alldata[record_count].Home=query.value(7).toString();           //家庭住址
            alldata[record_count].Office=query.value(8).toString();         //签发单位
            alldata[record_count].ValidTime=query.value(9).toString();      //有效日期
            alldata[record_count].idimage=query.value(10).toString();     //采集头像
            alldata[record_count].faceimage=query.value(11).toString();       //身份证头像
            record_count++;
            if(!query.next())
            {
                break;
            }
        }
    }
    query.clear();
    db.close();
    return record_count;
}
/*-----------------作为model显示无图片路径的查询，包含分页查询---------------------*/
bool database::selectdata_noimage(QSqlQueryModel *model, QString condition,int limitIndex)//参数为model指针，查询条件，分页起始记录
{
    if(!db.isOpen())
    {
        db.open();
    }
    QString str=QString("select  Time,Result,Name,ID,Gender,Nation,Bithtime,Home,Office,ValidTime  from DATAMANAGER where 1=1 ");
    str+=condition;
    str+="order by Time desc ";
    str+=QString("limit %1,%2").arg(QString::number(limitIndex)).arg(QString::number(PageRecordCount));//选取该页的记录使用limit查询

    model->setQuery(str);
    db.close();
    return true;
}
/*-----------------根据条件删除指定记录---------------------*/
bool database::deletedata(QString condition)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str="delete from DATAMANAGER where ";
    Str+=condition;

    bool success=query.exec(Str);
    if(!success)
    {
        return false;
    }
    query.clear();
    db.close();
    return true;
}
/*-----------------根据条件返回人脸采集头像---------------------*/
QString database::getfaceimage(QString condition)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery squery;
    QString faceimagepath;
    squery.prepare("select faceimage from DATAMANAGER where Time=:time");
    squery.bindValue(":time",condition);
    squery.exec();
    squery.next();
    faceimagepath=squery.value(0).toString();
    return faceimagepath;
}
/*-----------------根据条件返回身份证头像---------------------*/
QString database::getidimage(QString condition)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery squery;
    QString idimagepath;
    squery.prepare("select idimage from DATAMANAGER where Time=:time;");
    squery.bindValue(":time",condition);
    squery.exec();
    squery.next();
    idimagepath=squery.value(0).toString();
    return idimagepath;
}
/*-----------------导入数据库信息插入默认数据库---------------------*/
int database::insertdata(int count)
{
    if(!db.isOpen())
    {
        db.open();
    }
    int import_count=0;
    for(int i=0;i<count;i++)
    {
        QSqlQuery query;
        query.prepare("select count(*) from DATAMANAGER where Time=:time;");
        query.bindValue(":time",alldata[i].Time);
        query.exec();
        query.next();
        if(query.value(0).toInt()==0)//数据查重并插入
        {
            QSqlQuery s_query;
            QString str=QString("insert into DATAMANAGER values(");
            str+=QString("'%1'").arg(alldata[i].Time);
            str+=QString(",'%1'").arg(alldata[i].Result);
            str+=QString(",'%1'").arg(alldata[i].Name);
            str+=QString(",''%1'").arg(alldata[i].ID);
            str+=QString(",'%1'").arg(alldata[i].Gender);
            str+=QString(",'%1'").arg(alldata[i].Nation);
            str+=QString(",'%1'").arg(alldata[i].Birthtime);
            str+=QString(",'%1'").arg(alldata[i].Home);
            str+=QString(",'%1'").arg(alldata[i].Office);
            str+=QString(",'%1'").arg(alldata[i].ValidTime);
            str+=QString(",'%1'").arg(alldata[i].idimage);
            str+=QString(",'%1');").arg(alldata[i].faceimage);
            bool success = s_query.exec(str);
            if(!success)
            {
                qDebug()<<"false";
            }
            else
            {
                qDebug()<<"success";
                import_count++;
            }
            s_query.clear();

        }
    }
    return import_count;
    //     QMessageBox::warning(NULL,"提示",QString("成功导入%1条记录").arg(QString::number(import_count)),"确定");
}
/*-----------------传结构体数组信息插入默认数据库---------------------*/
void database::insertstructdata(Alldata all_data)
{
    if(!db.isOpen())
    {
        db.open();
    }
    //int import_count=0;
    QSqlQuery s_query;
    QString str=QString("insert into DATAMANAGER values(");
    str+=QString("'%1'").arg(all_data.Time);
    str+=QString(",'%1'").arg(all_data.Result);
    str+=QString(",'%1'").arg(all_data.Name);
    str+=QString(",'''%1'").arg(all_data.ID);
    str+=QString(",'%1'").arg(all_data.Gender);
    str+=QString(",'%1'").arg(all_data.Nation);
    str+=QString(",'%1'").arg(all_data.Birthtime);
    str+=QString(",'%1'").arg(all_data.Home);
    str+=QString(",'%1'").arg(all_data.Office);
    str+=QString(",'%1'").arg(all_data.ValidTime);
    str+=QString(",'%1'").arg(all_data.idimage);
    str+=QString(",'%1');").arg(all_data.faceimage);
    bool success = s_query.exec(str);
    if(!success)
    {
        qDebug()<<"false";
    }
    else
    {
        qDebug()<<"success";
        //import_count++;
    }
    s_query.clear();

    // QMessageBox::warning(NULL,"提示",QString("成功导入%1条记录").arg(QString::number(import_count)),"确定");
}
