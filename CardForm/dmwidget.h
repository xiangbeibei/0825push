#ifndef DMWIDGET_H
#define DMWIDGET_H

#include"selectwidget.h"
#include"database.h"
#include <QWidget>
#include<QLabel>
#include<QToolButton>
#include<QIcon>
#include<QHBoxLayout>
#include<QSplitter>
#include<QTreeWidget>
#include<QTableWidget>
#include<QMouseEvent>
#include<QPainter>
#include<QPushButton>
#include<QGroupBox>
#include<QMenu>
#include<QAction>
#include<QContextMenuEvent>
#include<QTableView>
#include<QStandardItemModel>
#include<QTreeWidgetItem>
#include<QtSql/qsql.h>
#include<Qtsql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QPainter>
#include<QAxObject>
#include <ActiveQt/QAxObject>
#include<QThread>
#include<QProgressDialog>
#include "loadingwindow.h"
#include "PrintManager.h"
#define EXPORT_INIT 0
#define EXPORT_OFFICE 1
#define EXPORT_WPS 2
class ProgressThread;
class ImportThread;
class BackupThread;
namespace Ui {
class DMWidget;
}

class DMWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DMWidget(QWidget *parent = 0);
    ~DMWidget();
/*--------------基本控件---------------------*/
private:
    Ui::DMWidget *ui;
    //第一行
    QLabel *DataManagerTitle;//数据管理标题
    QToolButton *BackButton;//返回键
    QHBoxLayout *FirstRow;//第一行水平布局管理器
    //第二行
    QHBoxLayout *SecondRow;//第二行水平布局管理器
    QToolButton *SelectButton;//查询键
    QToolButton *DeleteButton;//删除键
    QToolButton *PrintButton;//打印键
    QToolButton *ExportButton;//导出键
    QToolButton *ImportButton;//导入键
    QToolButton *BackupButton;//备份键
    //第三行
    QTreeWidget *Treewidget;//树形浏览框

    QGroupBox *groupbox;//显示圆角矩形框

    QLabel *picture1label;//人脸采集图
    QLabel *resultlabel;//比对结果标志
    QLabel *picture2label;//身份证头像
    QLabel *textlabel1;//人脸采集标签
    QLabel *textlabel2;//比对结果标签
    QLabel *textlabel3;//身份证头像标签

    QLabel *namelabel;//姓名显示标签
    QLabel *IDlabel;//身份证号显示标签
    QLabel *Timelabel;//比对时间显示标签
    QLabel *nameresult;//姓名结果
    QLabel *IDresult;//身份证号结果
    QLabel *Timeresult;//比对时间结果
    QLabel *minutelabel;//比对时间分钟秒
    QPushButton *flushbtn;//刷新按钮

    QString showname;//姓名显示内容
    QString showid;//身份证号显示内容
    QString showdate;//比对日期显示内容
    QString showtime;//比对时间显示内容
    QString showresult;//比对结果显示内容
    QString faceimagepath;//人脸采集图片路径
    QString idimagepath;//身份证头像图片路径

public:
    void showinit();//结果显示控件初始化，并显示第一条记录的信息
    void showfirstrow();//自动显示第一行的结果
    //状态栏
private:
    QLabel *recordcount;//记录标签
    QLabel *record;//记录数
    QLabel *recordcount2;//记录标签2
    QLabel *pagecount;//当前页码标签
    QLabel *page;//当前页数
    QPushButton *Pgup;//上一页
    QPushButton *Pgdown;//下一页
    QPushButton *Pgchange;//跳转页码
    QLineEdit *Pgedit;//页码输入框

//关闭信号
signals:
    void exitsignal(bool open);
public slots:
    void exitslot();
/*--------------树形结构和表结构实现---------------------*/
public:
    void Treewidgetinit();//树形结构初始化
    void deleteTreeItem();//删除所有树节点
    void TreewidgetIteminit();//根据数据库时间生成树节点
public slots:
    void openselect();//打开查询条件
    void treeitemclicked(QTreeWidgetItem *item,int column);//点击树节点显示不同表数据
/*---------------数据库和表------------------------*/
private:
    QSqlQueryModel *model;//数据库显示模型
    QTableView *tableview;//结果表
    database *data = database::Get_database();//数据库对象

public:
    void tableviewinit();//初始化结果表
    void getresult(QString result_temp);//选择比对结果图标
public slots://显示结果槽
    void getdata();//点击记录刷新显示结果
    void showdata();//点击刷新按钮显示结果

/*--------------状态栏实现--------------------------*/

private:

    QString conditions;//变化的查询条件
public:
    void Gettotalcount();//获取数据库总记录数
    void GetPagecount();//获取总页数
    void recordquery(int limitIndex);//记录查询
    void updatestatus();//更新状态栏
    void initpagebutton();//初始化翻页按钮工作状态
    void updateall();//在当前查询或翻页条件下更新所有相关状态显示
private:
    int currentPage;//当前页码
    int totalcount;//总记录条数
    int totalpage;//总页数
     enum      {PageRecordCount = 20};//每页记录数

public slots:
    void onpageupclick();//上一页
    void onpagedownclick();//下一页
    void onswitchpageclick();//跳转到
/*--------------实现删除选定行--------------------------*/
private:
    bool Treeitem_select;
public slots:
    void ondeletebutton();//删除按钮槽
/*--------------多条件查询记录--------------------------*/
private:
    selectWidget *select;
public slots:
    void receivedata(QString data);//接收查询页面查询条件槽

/*--------------导出为excel文件--------------------------*/
private:
    LoadingWindow *loadingwindow;
    ProgressThread *progress;
    QString excel_filename;
public slots:
    void exportexcel();//导出为excel文件槽
    void close_loading(int num);
public:
    int export_start();
/*--------------导入数据库--------------------------*/
private:
    LoadingWindow *importloading;
    ImportThread *importprogress;
    QString import_filename;
    bool copyDirectory(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
public slots:
    void importdatabase();
    void close_importloading(int num);

public:
    int import_start();
/*--------------备份数据库--------------------------*/
private:
    LoadingWindow *backuploading;
    BackupThread *backupprogress;
    QString backup_dirname;
public slots:
    void backupdatabase();
    void close_backuploading(bool ok);
public:
    bool backup_start();

 /*--------------打印凭证---------------------*/
private:
    PrintManager *print;
public slots:
    void clicked_Print();

 /*--------------重写鼠标事件，使窗口可移动---------------------*/
    private:
        QPoint last;//智能指针
    protected://重写鼠标事件，使窗口可移动
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);
        void mouseReleaseEvent(QMouseEvent *e);
        void paintEvent(QPaintEvent *e);
};


class ProgressThread : public QThread
{
    Q_OBJECT
public:
    ProgressThread(DMWidget *win);
signals:
    void send_startcmd(int cmd);

private:
    DMWidget *win;
    void run();
};

class ImportThread : public QThread
{
    Q_OBJECT
public:
    ImportThread(DMWidget *win);

signals:
    void send_importcmd(int cmd);

private:
    DMWidget *win;

    void run();
};
//备份线程
class BackupThread : public QThread
{
    Q_OBJECT
public:
    BackupThread(DMWidget *win);

signals:
    void send_backupcmd(bool ok);

private:
    DMWidget *win;

    void run();
};
#endif // DMWIDGET_H
