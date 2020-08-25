#include "dmwidget.h"
#include "ui_dmwidget.h"
#include "selectwidget.h"
#include "database.h"
#include "JlCompress.h"
#include "zip.h"
#include<QGridLayout>
#include<QToolButton>
#include<QLabel>
#include<QIcon>
#include<QHBoxLayout>
#include<QPalette>
#include<QColor>
#include<QTreeWidget>
#include<QStandardItemModel>
#include<QTableWidget>
#include<QPainter>
#include<QMouseEvent>
#include<QLineEdit>
#include<QContextMenuEvent>
#include<QInputDialog>
#include<QMessageBox>
#include<QTableView>
#include<QHeaderView>
#include<QStandardItem>
#include<QtSql/qsql.h>
#include<Qtsql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QItemSelectionModel>
#include<QModelIndexList>
#include<QDebug>
#include<QFileDialog>
#include<fstream>
#include<iostream>
#include<QDir>
#include<QProgressDialog>
#include<Windows.h>
#if _MSC_VER >= 1571
#pragma execution_character_set("utf-8")
#endif
DMWidget::DMWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DMWidget)
{
    /*-----------------------界面总设计----------------------*/
    ui->setupUi(this);
    this->setFixedSize(975,571);
    QColor backgroundcolor(1,192,198);
    QPalette backgroundpalette;
    backgroundpalette=QPalette(backgroundcolor);
    setAutoFillBackground(true);
    backgroundpalette.setColor(QPalette::Background,backgroundcolor);
    setPalette(backgroundpalette);
    this->setWindowIcon(QIcon(":/image/Image/icons8-name-tag-64.ico"));
    select=new selectWidget();//查询页面

    /*-----------------------第一行控件管理----------------------*/
    //标题头
    DataManagerTitle=new QLabel(this);
    DataManagerTitle->setText("数据管理");
    DataManagerTitle->setStyleSheet("color:white;font-size:24px;font-weight:bold");
    DataManagerTitle->setGeometry(QRect(10,10,111,31));
    DataManagerTitle->show();
    BackButton=new QToolButton;

    //返回按钮
    QIcon exiticon;
    exiticon.addFile(QStringLiteral(":/image/Image/quit.ico"),QSize(),QIcon::Normal,QIcon::Off);
    BackButton=new QToolButton(this);
    BackButton->setAutoRaise(true);
    BackButton->setStyleSheet("QToolButton{background:rgb(1,192,198);color:white;font-size:24px}");
    BackButton->setIcon(exiticon);
    BackButton->setIconSize(QSize(28,28));
    BackButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    BackButton->setText("返回");
    BackButton->setGeometry(870,10,90,31);
    BackButton->show();
    //返回按钮槽
    connect(BackButton,SIGNAL(clicked(bool)),this,SLOT(exitslot()));

    /*-----------------------第二行控件管理----------------------*/


    //查询按钮
    SelectButton=new QToolButton(this);
    SelectButton->setStyleSheet("QToolButton{border:3px solid white;background:rgb(1,192,198);color:white;font-size:20px;font-weight:bold}");
    QIcon selecticon;
    selecticon.addFile(QStringLiteral(":/image/Image/search.ico"),QSize(),QIcon::Normal,QIcon::Off);
    SelectButton->setText("查询");
    SelectButton->setAutoRaise(true);
    SelectButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    SelectButton->setIcon(selecticon);
    SelectButton->setGeometry(0,46,100,45);
    SelectButton->setIconSize(QSize(28,28));
    SelectButton->show();


    //删除按钮
    DeleteButton=new QToolButton(this);
    DeleteButton->setStyleSheet("QToolButton{border:3px solid white;background:rgb(1,192,198);color:white;font-size:20px;font-weight:bold}");
    QIcon deleteicon;
    deleteicon.addFile(QStringLiteral(":/image/Image/delete.ico"),QSize(),QIcon::Normal,QIcon::Off);
    DeleteButton->setText("删除");
    DeleteButton->setAutoRaise(true);
    DeleteButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    DeleteButton->setIcon(deleteicon);
    DeleteButton->setIconSize(QSize(28,28));
    DeleteButton->setGeometry(90,46,100,45);
    DeleteButton->show();
    Treeitem_select=false;


    //打印按钮
    PrintButton= new QToolButton(this);
    QIcon printicon;
    printicon.addFile(QStringLiteral(":/image/Image/print.ico"),QSize(),QIcon::Normal,QIcon::Off);
    PrintButton->setStyleSheet("QToolButton{border:3px solid white;background:rgb(1,192,198);color:white;font-size:20px;font-weight:bold}");
    PrintButton->setText("打印");
    PrintButton->setAutoRaise(true);
    PrintButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    PrintButton->setIcon(printicon);
    PrintButton->setIconSize(QSize(28,28));
    PrintButton->setGeometry(180,46,100,45);
    PrintButton->show();
    print=new PrintManager;


    //导出按钮
    ExportButton=new QToolButton(this);
    QIcon exporticon;
    exporticon.addFile(QStringLiteral(":/image/Image/export.ico"),QSize(),QIcon::Normal,QIcon::Off);
    ExportButton->setStyleSheet("QToolButton{border:3px solid white;background:rgb(1,192,198);color:white;font-size:20px;font-weight:bold}");
    ExportButton->setText("导出");
    ExportButton->setAutoRaise(true);
    ExportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ExportButton->setIcon(exporticon);
    ExportButton->setIconSize(QSize(28,28));
    ExportButton->setGeometry(270,46,100,45);
    ExportButton->show();


    //导入按钮
    ImportButton=new QToolButton(this);
    QIcon importicon;
    importicon.addFile(QStringLiteral(":/image/Image/import.png"),QSize(),QIcon::Normal,QIcon::Off);
    ImportButton->setStyleSheet("QToolButton{border:3px solid white;background:rgb(1,192,198);color:white;font-size:20px;font-weight:bold}");
    ImportButton->setText("导入");
    ImportButton->setAutoRaise(true);
    ImportButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ImportButton->setIcon(importicon);
    ImportButton->setIconSize(QSize(25,25));
    ImportButton->setGeometry(360,46,100,45);
    ImportButton->show();


    //备份按钮
    BackupButton=new QToolButton(this);
    QIcon backupicon;
    backupicon.addFile(QStringLiteral(":/image/Image/backup.png"),QSize(),QIcon::Normal,QIcon::Off);
    BackupButton->setStyleSheet("QToolButton{border:3px solid white;background:rgb(1,192,198);color:white;font-size:20px;font-weight:bold}");
    BackupButton->setText("备份");
    BackupButton->setAutoRaise(true);
    BackupButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    BackupButton->setIcon(backupicon);
    BackupButton->setIconSize(QSize(28,28));
    BackupButton->setGeometry(450,46,100,45);
    BackupButton->show();
    //第二行按钮功能实现槽
    connect(SelectButton,SIGNAL(clicked(bool)),SLOT(openselect()));//查询
    connect(DeleteButton,SIGNAL(clicked(bool)),SLOT(ondeletebutton())); //删除
    connect(ExportButton,SIGNAL(clicked(bool)),SLOT(exportexcel()));//导出
    connect(ImportButton,SIGNAL(clicked(bool)),SLOT(importdatabase()));//导入
    connect(BackupButton,SIGNAL(clicked(bool)),SLOT(backupdatabase()));//备份
    connect(PrintButton,SIGNAL(clicked(bool)),SLOT(clicked_Print()));//打印


    /*-----------------------第三行右边上层-----------------------*/

    //圆角框
    groupbox=new QGroupBox(this);
    groupbox->setTitle(QString());
    groupbox->setStyleSheet("QGroupBox{border:3px solid white;border-radius:10px}");
    groupbox->setGeometry(180,100,771,181);
    groupbox->show();
    //显示控件初始化
    showinit();
    //刷新按钮槽
    connect(flushbtn,SIGNAL(clicked(bool)),SLOT(showdata()));

    /*-----------------------右边下层----------------------*/
    Treewidget=new QTreeWidget(this);
    tableview=new QTableView(this);
    tableview->setGeometry(180,270,771,261);
    tableview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    tableview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    tableview->setShowGrid(false);
    tableview->horizontalHeader()->setStretchLastSection(true);
    tableview->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    tableview->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    tableview->verticalHeader()->setVisible(false);
    model=new QSqlQueryModel;
    tableviewinit();//包含树形结构初始化
    //选择记录刷新显示结果槽
    connect(tableview,SIGNAL(clicked(QModelIndex)),SLOT(getdata()));

    showfirstrow();

    /*-----------------------状态栏----------------------*/

    //记录条数
    recordcount=new QLabel(this);
    recordcount->setText("共有");
    recordcount->setStyleSheet("color:white");
    recordcount->setGeometry(450,540,31,16);
    recordcount->show();

    record=new QLabel(this);
    record->setText("   ");
    record->setStyleSheet("color:white");
    record->setGeometry(480,542,21,16);
    record->show();

    recordcount2=new QLabel(this);
    recordcount2->setText("条记录");
    recordcount2->setStyleSheet("color:white");
    recordcount2->setGeometry(510,540,41,16);
    recordcount2->show();

    //当前页码
    pagecount=new QLabel(this);
    pagecount->setText("页次：");
    pagecount->setStyleSheet("color:white");
    pagecount->setGeometry(600,540,41,16);
    pagecount->show();

    page=new QLabel(this);
    updatestatus();
    page->setStyleSheet("color:white");
    page->setGeometry(640,540,50,16);
    page->show();

    //跳页按钮
    Pgup=new QPushButton(this);
    Pgup->setText("上一页");
    Pgup->setStyleSheet("QPushButton{background:rgb(1,192,198);color:white}");
    Pgup->setFlat(true);
    Pgup->setGeometry(710,537,51,21);
    Pgup->show();
    Pgup->setEnabled(false);


    Pgdown=new QPushButton(this);
    Pgdown->setText("下一页");
    Pgdown->setFlat(true);
    Pgdown->setStyleSheet("QPushButton{background:rgb(1,192,198);color:white}");
    Pgdown->setGeometry(766,537,51,21);
    Pgdown->show();
    Pgdown->setEnabled(true);


    Pgchange=new QPushButton(this);
    Pgchange->setText("跳转到:");
    Pgchange->setFlat(true);
    Pgchange->setStyleSheet("color:white");
    Pgchange->setStyleSheet("QPushButton{background:rgb(1,192,198);color:white}");
    Pgchange->setGeometry(860,537,51,21);
    Pgchange->show();


    Pgedit=new QLineEdit(this);
    Pgedit->setGeometry(910,540,41,16);
    Pgedit->setStyleSheet("QLineEdit{border:0px solid white}");
    Pgedit->show();
    //页面变换槽
    connect(Pgup,SIGNAL(clicked(bool)),SLOT(onpageupclick()));//上一页
    connect(Pgdown,SIGNAL(clicked(bool)),SLOT(onpagedownclick()));//下一页
    connect(Pgchange,SIGNAL(clicked(bool)),SLOT(onswitchpageclick()));//跳转页

    loadingwindow=new LoadingWindow;
    loadingwindow->setLoadingText("正在导出为excel，请稍等......");
    progress=new ProgressThread(this);
    importloading=new LoadingWindow;
    importloading->setLoadingText("正在导入数据，请稍等......");
    importprogress=new ImportThread(this);
    backuploading=new LoadingWindow;
    backuploading->setLoadingText("正在备份数据，请稍等......");
    backupprogress=new BackupThread(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}
/* ------------------鼠标事件重写-------------------------*/
DMWidget::~DMWidget()
{
    delete ui;
    delete print;
}
//鼠标事件
void DMWidget::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void DMWidget::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void DMWidget::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    move(x()+dx,y()+dy);
}
/* ------------------初始化结果显示-------------------------*/
//初始化信息显示控件
void DMWidget::showinit()
{
    //人脸采集显示
    picture1label=new QLabel(groupbox);
    picture1label->setStyleSheet("QLabel{border:2px solid white;}");
    picture1label->setGeometry(50,15,111,121);
    picture1label->show();
    textlabel1=new QLabel(groupbox);
    textlabel1->setText("[人脸采集图]");
    textlabel1->setStyleSheet("QLabel{color:white;font-size:14px;font-weight:bold}");
    textlabel1->setGeometry(60,145,91,20);
    textlabel1->show();

    //验证结果图标
    resultlabel=new QLabel(groupbox);
    resultlabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/验证通过.png")));
    resultlabel->setScaledContents(true);
    resultlabel->setGeometry(210,35,81,81);
    resultlabel->show();
    textlabel2=new QLabel(groupbox);
    textlabel2->setText("[比对结果]");
    textlabel2->setStyleSheet("QLabel{color:white;font-size:14px;font-weight:bold}");
    textlabel2->setGeometry(210,145,81,16);
    textlabel2->show();

    //身份证头像显示
    picture2label=new QLabel(groupbox);
    picture2label->setStyleSheet("QLabel{border:2px solid white;}");
    picture2label->setGeometry(340,15,111,121);
    picture2label->show();
    textlabel3=new QLabel(groupbox);
    textlabel3->setText("[身份证头像]");
    textlabel3->setStyleSheet("QLabel{color:white;font-size:14px;font-weight:bold}");
    textlabel3->setGeometry(350,145,91,16);



    //身份证信息结果显示
    //姓名
    namelabel=new QLabel(groupbox);
    namelabel->setText("姓名：");
    namelabel->setGeometry(480,35,41,16);
    namelabel->show();
    nameresult=new QLabel(groupbox);
    namelabel->setStyleSheet("QLabel{color:white;font-size:15px;font-weight:bold}" );
    nameresult->setStyleSheet("QLabel{color:white;font-size:15px;font-weight:bold}" );
    nameresult->setGeometry(565,35,161,16);
    nameresult->show();

    //身份证号
    IDlabel=new QLabel(groupbox);
    IDlabel->setText("身份证号：");
    IDlabel->setGeometry(480,65,72,16);
    IDlabel->show();
    IDresult=new QLabel(groupbox);
    IDlabel->setStyleSheet("QLabel{color:white;font-size:15px;font-weight:bold}" );
    IDresult->setStyleSheet("QLabel{color:white;font-size:15px;font-weight:bold}" );
    IDresult->setGeometry(565,65,161,16);
    IDresult->show();

    //比对时间精确到秒
    Timelabel=new QLabel(groupbox);
    Timelabel->setText("比对时间：");
    Timelabel->setGeometry(480,95,72,16);
    Timelabel->show();
    Timeresult=new QLabel(groupbox);
    Timelabel->setStyleSheet("QLabel{color:white;font-size:15px;font-weight:bold}" );
    Timeresult->setStyleSheet("QLabel{color:white;font-size:15px;font-weight:bold}" );
    Timeresult->setGeometry(565,95,161,16);
    Timeresult->show();
    minutelabel=new QLabel(groupbox);
    minutelabel->setStyleSheet("QLabel{color:white;font-size:15px;font-weight:bold}" );
    minutelabel->setGeometry(565,115,161,16);
    minutelabel->show();


    //刷新按钮
    flushbtn=new QPushButton(groupbox);
    flushbtn->setText("刷新");
    flushbtn->setGeometry(710,145,41,21);
    flushbtn->setStyleSheet("QPushButton{background:rgb(1,192,198);color:white;font:12px}");
    flushbtn->setFlat(true);
    flushbtn->show();
    //showfirstrow();在tableview初始化之后调用
}
//显示当前条件下第一行数据自动刷新
void DMWidget::showfirstrow()
{
    //在当前模型中获取第一条数据
    if(model->rowCount()==0)
    {
        return;
    }
    nameresult->setText(model->data(model->index(0,2),Qt::DisplayRole).toString());
    IDresult->setText(model->data(model->index(0,3),Qt::DisplayRole).toString());
    QString datetime=model->data(model->index(0,0),Qt::DisplayRole).toString();
    QStringList datetimelist=datetime.split(" ");
    QString date=datetimelist.at(0);
    QString time=datetimelist.at(1);
    Timeresult->setText(date);
    minutelabel->setText(time);
    getresult(model->data(model->index(0,1),Qt::DisplayRole).toString());
    //根据时间查询第一条记录人脸采集图和身份证头像
    faceimagepath=data->getfaceimage(datetime);
    idimagepath=data->getidimage(datetime);
    QImage idimage;
    idimage.load(QString("%1").arg(idimagepath));
    idimage = idimage.scaled(111,121,Qt::KeepAspectRatio);
    picture2label->setAlignment(Qt::AlignCenter);
    picture2label->setPixmap(QPixmap::fromImage(idimage));
    QImage faceimage;
    faceimage.load(QString("%1").arg(faceimagepath));
    faceimage = faceimage.scaled(111,121,Qt::KeepAspectRatio);
    picture1label->setAlignment(Qt::AlignCenter);
    picture1label->setPixmap(QPixmap::fromImage(faceimage));
}
/* ------------------绘图事件重写-------------------------*/
void DMWidget::paintEvent(QPaintEvent *e)
{
    QPainter painterline(this);
    QPen penline;
    penline.setColor(Qt::white);
    penline.setWidth(3);
    painterline.setPen(penline);

    painterline.drawLine(QPoint(0,46),QPoint(975,46));
    painterline.drawLine(QPoint(0,90),QPoint(975,90));


    QPainter paintrect1(this);
    QPen penrect1;
    penrect1.setColor(Qt::white);
    penrect1.setWidth(6);
    paintrect1.setPen(penrect1);
    paintrect1.drawRect(QRect(0,0,975,571));

}
/* ------------------树形结构操作--------------------------*/
//初始化树结构
void DMWidget::Treewidgetinit()
{
    delete Treewidget;
    Treewidget=new QTreeWidget(this);
    Treewidget->setGeometry(20,100,140,431);
    Treewidget->show();
    Treewidget->setHeaderLabel("日期");

}
//删除所有树节点
void DMWidget::deleteTreeItem()
{
    for(int i=0;i<Treewidget->topLevelItemCount();i++)
    {
        for(int j=0;j<Treewidget->topLevelItem(i)->childCount();j++)
        {
            for(int k=0;k<Treewidget->topLevelItem(i)->child(j)->childCount();k++)
            {
                delete Treewidget->topLevelItem(i)->child(j)->child(k);
            }
            delete Treewidget->topLevelItem(i)->child(j);
        }
        delete Treewidget->topLevelItem(i);
    }
}
//根据数据库时间生成树节点
void DMWidget::TreewidgetIteminit()
{
    deleteTreeItem();
    int count=data->selectdata_all(" ");
    for(int row=0;row<count;row++)
    {//在数据库对象中的结构体数组中查询获取时间
        QString Time_date=data->alldata[row].Time;
        QStringList Time_temp_List=Time_date.split(" ");//时间分离
        QStringList Time_list=Time_temp_List.at(0).split('/');//日期分离
        //分离日期生成树节点
        QString year=Time_list.at(0)+" 年";
        QString month=Time_list.at(1)+" 月";
        QString day=Time_list.at(2)+" 日";
        bool day_flag=false;
        bool month_flag=false;
        bool year_flag=false;
        for(int i=0;i<Treewidget->topLevelItemCount();i++)
        {
            if(Treewidget->topLevelItem(i)->text(0)==year)
            {
                for(int j=0;j<Treewidget->topLevelItem(i)->childCount();j++)
                {
                    if(Treewidget->topLevelItem(i)->child(j)->text(0)==month)
                    {
                        for(int m=0;m<Treewidget->topLevelItem(i)->child(j)->childCount();m++)
                        {

                            if(Treewidget->topLevelItem(i)->child(j)->child(m)->text(0)==day)
                            {
                                day_flag=true;
                                break;
                            }
                        }
                        if(!day_flag)
                        {
                            QTreeWidgetItem *day_item=new QTreeWidgetItem;
                            day_item->setText(0,day);
                            Treewidget->topLevelItem(i)->child(j)->addChild(day_item);
                        }
                        month_flag=true;
                        break;
                    }
                }
                if(!month_flag)
                {
                    QTreeWidgetItem *month_item=new QTreeWidgetItem;
                    QTreeWidgetItem *day_item=new QTreeWidgetItem;
                    month_item->setText(0,month);
                    day_item->setText(0,day);
                    month_item->addChild(day_item);
                    Treewidget->topLevelItem(i)->addChild(month_item);
                }
                year_flag=true;
                break;
            }
        }
        if(!year_flag)
        {
            QTreeWidgetItem *year_item=new QTreeWidgetItem;
            QTreeWidgetItem *month_item=new QTreeWidgetItem;
            QTreeWidgetItem *day_item=new QTreeWidgetItem;
            year_item->setText(0,year);
            month_item->setText(0,month);
            day_item->setText(0,day);
            month_item->addChild(day_item);
            year_item->addChild(month_item);
            int yearcount=Treewidget->topLevelItemCount();
            Treewidget->insertTopLevelItem(yearcount,year_item);
        }
    }

}
//初始化数据库model表形结构
void DMWidget::tableviewinit()
{
    model->clear();
    picture1label->clear();
    picture2label->clear();
    resultlabel->clear();
    nameresult->clear();
    IDresult->clear();
    Timeresult->clear();
    minutelabel->clear();

    Treewidgetinit();//初始化树
    TreewidgetIteminit();//生成树节点
    data->selectdata_noimage(model,"",0);//所有数据分页
    currentPage=1;
    Gettotalcount();//全记录数
    GetPagecount();//全页数
    tableview->setModel(model);
    model->setHeaderData(0,Qt::Horizontal,"检验时间");
    model->setHeaderData(1,Qt::Horizontal,"比对结果");
    model->setHeaderData(2,Qt::Horizontal,"姓名");
    model->setHeaderData(3,Qt::Horizontal,"身份证号");
    model->setHeaderData(4,Qt::Horizontal,"性别");
    model->setHeaderData(5,Qt::Horizontal,"民族");
    model->setHeaderData(6,Qt::Horizontal,"出生日期");
    model->setHeaderData(7,Qt::Horizontal,"住址");
    model->setHeaderData(8,Qt::Horizontal,"签发机关");
    model->setHeaderData(9,Qt::Horizontal,"有效期限");
    tableview->setColumnWidth(0,150);
    tableview->setColumnWidth(1,80);
    tableview->setColumnWidth(2,80);
    tableview->setColumnWidth(3,200);
    tableview->setColumnWidth(4,80);
    tableview->setColumnWidth(5,80);
    tableview->setColumnWidth(6,120);
    tableview->setColumnWidth(7,300);
    tableview->setColumnWidth(8,300);
    tableview->setColumnWidth(9,170);
    tableview->show();
    connect(Treewidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),SLOT(treeitemclicked(QTreeWidgetItem*,int)));
}
/* ------------------状态栏更新-------------------------*/
//初始化翻页按钮工作状态
void DMWidget::initpagebutton()
{
    if(currentPage==1)//如果是在第一页
    {
        if(totalpage==1)//如果只有一页
        {
            Pgup->setEnabled(false);
            Pgdown->setEnabled(false);
        }
        else
        {
            Pgup->setEnabled(false);
            Pgdown->setEnabled(true);
        }
    }
    else if(currentPage==totalpage)//如果在最后一页
    {
        Pgup->setEnabled(true);
        Pgdown->setEnabled(false);
    }
    else
    {
        Pgup->setEnabled(true);
        Pgdown->setEnabled(true);
    }
}
//在当前查询或翻页条件下更新所有相关状态显示
void DMWidget::updateall()
{
    currentPage=1;//当前页设置为1
    Gettotalcount();//得到当前条件下的记录条数
    GetPagecount();//计算当前条件下的分页页数
    initpagebutton();//初始化翻页按钮的工作状态
    recordquery(0);//分页查询
    updatestatus();//更新状态栏
    data->selectdata_all(conditions);
    showfirstrow();//更新显示控件显示第一行数据
}
//显示对应日期下的表数据like查询数据库更新表
void DMWidget::treeitemclicked(QTreeWidgetItem *item, int column)
{
    if(item->parent()==NULL)
    {
        QString temp=item->text(column).mid(0,4);
        conditions=QString("and Time LIKE '%1%'").arg(temp);
        updateall();
        Treeitem_select=true;
    }
    else if(item->parent()->parent())
    {
        QString temp_day=item->text(column).mid(0,2);
        QString temp_month=item->parent()->text(column).mid(0,2);
        QString temp_year=item->parent()->parent()->text(column).mid(0,4);
        QString temp=temp_year+"/"+temp_month+"/"+temp_day;
        conditions=QString("and Time LIKE '%1%'").arg(temp);
        updateall();
        Treeitem_select=true;
    }
    else if(item->parent())
    {
        QString temp_year=item->parent()->text(column).mid(0,4);
        QString temp_month=item->text(column).mid(0,2);
        QString temp=temp_year+"/"+temp_month;
        conditions=QString("and Time LIKE '%1%'").arg(temp);
        updateall();
        Treeitem_select=true;
    }
}
//给总记录数totalcount赋值
void DMWidget::Gettotalcount()
{
    totalcount=data->selectdata_all(conditions);//赋值
}
//计算总页数并给totalpage赋值
void DMWidget::GetPagecount()
{
    if((totalcount/PageRecordCount)*PageRecordCount<totalcount)//不足一页
    {
        totalpage =totalcount/PageRecordCount+1;
    }
    else
    {
        totalpage =totalcount/PageRecordCount;
    }
}
//分页查询
void DMWidget::recordquery(int limitIndex)
{
    data->selectdata_noimage(model,conditions,limitIndex);
}
//更新状态栏
void DMWidget::updatestatus()
{
    QString currenttext=QString("%1 / %2").arg(currentPage).arg(totalpage);
    page->setText(currenttext);
    QString count=QString::number(totalcount,10);
    record->setText(count);
    record->setAlignment(Qt::AlignHCenter);
}
//上一页槽
void DMWidget::onpageupclick()
{
    int limitIndex=(currentPage-2)*PageRecordCount;
    recordquery(limitIndex);//分页查询
    currentPage-=1;
    updatestatus();
    initpagebutton();
}
//下一页槽
void DMWidget::onpagedownclick()
{
    int limitIndex=currentPage*PageRecordCount;
    recordquery(limitIndex);//分页查询
    currentPage+=1;
    updatestatus();
    initpagebutton();
}
//跳转页槽
void DMWidget::onswitchpageclick()
{
    //得到输入字符串
    QString  pgtext = Pgedit->text();
    //数字正则表达式
    QRegExp regExp("-?[0-9]*");
    //判断是否为数字
    if(!regExp.exactMatch( pgtext))
    {
        QMessageBox::information(this, tr("提示"), tr("请输入数字!"));
        return;
    }
    //是否为空
    if( pgtext.isEmpty())
    {
        QMessageBox::information(this, tr("提示"), tr("请输入跳转页面!"));
        return;
    }
    //得到页数
    int pageIndex =  pgtext.toInt();
    //判断是否有指定页
    if(pageIndex > totalpage || pageIndex < 1)
    {
        QMessageBox::information(this, tr("提示"), tr("没有指定的页面，请重新输入!"));
        return;
    }
    //得到查询起始行号
    int limitIndex = (pageIndex-1) * PageRecordCount;
    //记录查询
    recordquery(limitIndex);
    //设置当前页
    currentPage = pageIndex;
    //刷新状态
    updatestatus();
    initpagebutton();
}
//获取被选中行的数据槽
void DMWidget::getdata()
{
    int row=tableview->currentIndex().row();
    showname=model->data(model->index(row,2),Qt::DisplayRole).toString();
    showid=model->data(model->index(row,3),Qt::DisplayRole).toString();
    QString datetime=model->data(model->index(row,0),Qt::DisplayRole).toString();
    QStringList datetimelist=datetime.split(" ");
    showdate=datetimelist.at(0);
    showtime=datetimelist.at(1);
    showresult=model->data(model->index(row,1),Qt::DisplayRole).toString();

    faceimagepath=data->getfaceimage(datetime);
    idimagepath=data->getidimage(datetime);
    nameresult->setText(showname);
    IDresult->setText(showid);
    Timeresult->setText(showdate);
    minutelabel->setText(showtime);
    getresult(showresult);
    QImage idimage;
    idimage.load(QString("%1").arg(idimagepath));
    idimage = idimage.scaled(111,121,Qt::KeepAspectRatio);
    picture2label->setAlignment(Qt::AlignCenter);
    picture2label->setPixmap(QPixmap::fromImage(idimage));
    QImage faceimage;
    faceimage.load(QString("%1").arg(faceimagepath));
    faceimage = faceimage.scaled(111,121,Qt::KeepAspectRatio);
    picture1label->setAlignment(Qt::AlignCenter);
    picture1label->setPixmap(QPixmap::fromImage(faceimage));
    //暂存一条信息
    Alldata single_data;
    single_data.Time=model->data(model->index(row,0),Qt::DisplayRole).toString();
    single_data.Result=model->data(model->index(row,1),Qt::DisplayRole).toString();
    single_data.Name=model->data(model->index(row,2),Qt::DisplayRole).toString();
    single_data.ID=model->data(model->index(row,3),Qt::DisplayRole).toString();
    single_data.Gender=model->data(model->index(row,4),Qt::DisplayRole).toString();
    single_data.Nation=model->data(model->index(row,5),Qt::DisplayRole).toString();
    single_data.Birthtime=model->data(model->index(row,6),Qt::DisplayRole).toString();
    single_data.Home=model->data(model->index(row,7),Qt::DisplayRole).toString();
    single_data.Office=model->data(model->index(row,8),Qt::DisplayRole).toString();
    single_data.ValidTime=model->data(model->index(row,9),Qt::DisplayRole).toString();
    single_data.idimage=idimagepath;
    single_data.faceimage=faceimagepath;
    print->CreateHTML(single_data);
}
//获取被选中行的比对结果
void DMWidget::getresult(QString result_temp)
{
    if(result_temp=="匹配")
    {
        resultlabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Image/Right.png")));
    }
    else if(result_temp=="不匹配" || result_temp == "未比对")
    {
        resultlabel->setPixmap(QPixmap(QString::fromUtf8(":/image/Image/Wrong.png")));
    }
}
//刷新显示结果槽
void DMWidget::showdata()
{
    nameresult->setText(showname);
    IDresult->setText(showid);
    Timeresult->setText(showdate);
    minutelabel->setText(showtime);
    getresult(showresult);
    QImage idimage;
    idimage.load(QString("%1").arg(idimagepath));
    idimage = idimage.scaled(111,121,Qt::KeepAspectRatio);
    picture2label->setAlignment(Qt::AlignCenter);
    picture2label->setPixmap(QPixmap::fromImage(idimage));
    QImage faceimage;
    faceimage.load(QString("%1").arg(faceimagepath));
    faceimage = faceimage.scaled(111,121,Qt::KeepAspectRatio);
    picture1label->setAlignment(Qt::AlignCenter);
    picture1label->setPixmap(QPixmap::fromImage(faceimage));
}
//删除
void DMWidget::ondeletebutton()
{
    QItemSelectionModel *selection=tableview->selectionModel();
    QModelIndexList selected=selection->selectedIndexes();
    if(selected.size()<=0)
    {
        if(Treeitem_select)
        {
            int ok=QMessageBox::warning(this,QString("删除选定记录"),QString("是否确定删除当前日期下的%1条记录？").arg(QString::number(totalcount,10)),QMessageBox::Yes,QMessageBox::No);
            if(ok==QMessageBox::No)
            {
                return;
            }
            else
            {
                QString temp=conditions.mid(4);
                data->deletedata(temp);
            }
        }
        else
        {
            QMessageBox::information(this,QString("提示"),QString("请选择至少一条记录！"));
            return;
        }
    }
    else
    {
        int ok=QMessageBox::warning(this,QString("删除选定记录"),QString("是否确定删除%1条选定记录？").arg(QString::number(selected.size()/10)),QMessageBox::Yes,QMessageBox::No);
        if(ok==QMessageBox::No)
        {
            return;
        }
        else
        {
            foreach(QModelIndex index,selected)
            {
                if(index.column()==0)
                {
                    QString date_temp=model->data(index,Qt::DisplayRole).toString();
                    QString temp=QString("Time = '%1'").arg(date_temp);
                    data->deletedata(temp);
                }
            }

        }
    }
    tableviewinit();
    updateall();
}
//打开查询条件窗口
void DMWidget::openselect()
{
    connect(select,SIGNAL(sendSQL(QString)),SLOT(receivedata(QString)));
    select->show();
}
//多条件查询
void DMWidget::receivedata(QString data)
{
    conditions=data;
    updateall();
    if(model->rowCount()==0)
    {
        QMessageBox::information(this,"提示","该查询条件下没有数据");
    }
}
//导出成excel

void DMWidget::exportexcel()
{
//    exportType = EXPORT_INIT;
//    QMessageBox ExportMessage(QMessageBox::Warning,tr("导出提示"),tr("请选择本机中已安装的办公软件类型"),QMessageBox::Ok|QMessageBox::Cancel|QMessageBox::Yes);
//    ExportMessage.setButtonText(QMessageBox::Ok,tr("Office"));
//    ExportMessage.setButtonText(QMessageBox::Cancel,tr("取消"));
//    ExportMessage.setButtonText(QMessageBox::Yes,tr("WPS"));
//    auto ret = ExportMessage.exec();
//    if( ret == QMessageBox::Ok)
//    {
//        exportType = EXPORT_OFFICE;
//    }
//    if(ret == QMessageBox::Yes)
//    {
//        exportType = EXPORT_WPS;
//    }
//    if(ret == QMessageBox::Cancel)
//    {
//        ExportMessage.close();
//        return;
//    }
    QMessageBox ExportMessage(QMessageBox::Warning,tr("导出提示"),tr("请确认是否正确安装Office软件"),QMessageBox::Ok|QMessageBox::Cancel);
    ExportMessage.setButtonText(QMessageBox::Ok,tr("确定"));
    ExportMessage.setButtonText(QMessageBox::Cancel,tr("取消"));
    if(ExportMessage.exec()==QMessageBox::Cancel)
    {
        ExportMessage.close();
        return;
    }

    excel_filename=QFileDialog::getSaveFileName(NULL,tr("保存excel文件"),"","Excel(*.xlsx *.xls)",NULL,QFileDialog::DontUseNativeDialog);

    if(excel_filename.isEmpty())
    {
        QMessageBox::information(this,"提示","输入文件名");
        return;
    }
    else
    {
        loadingwindow->show();
        delete progress;
        progress=new ProgressThread(this);
        connect(progress,SIGNAL(send_startcmd(int)),this,SLOT(close_loading(int)));

        progress->start();

    }
}

int DMWidget::export_start()
{
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    QAxObject *excel = new QAxObject("Excel.Application");;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *workSheets;
    QAxObject *workSheet;
    if(excel->isNull())
    {
        if(excel != Q_NULLPTR)
        {
            excel->dynamicCall("Quit()");
            delete excel;
            excel = Q_NULLPTR;
        }
        QMessageBox::critical(0,"错误信息","没有找到Excel应用程序");
        return 201;
    }
    excel->setProperty("SetVisible (bool Visible)",false);
    workBooks=excel->querySubObject("WorkBooks");
    if(workBooks == Q_NULLPTR)
    {
        QMessageBox::critical(0,"错误信息","取得Excel的workbooks失败");
        return 201;
    }
    workBooks->dynamicCall("Add");
    workBook=excel->querySubObject("ActiveWorkBook");
    if(workBook == Q_NULLPTR)
    {
        QMessageBox::critical(0,"错误信息","打开Excel的Workbook失败");
        return 201;
    }
    workSheets=workBook->querySubObject("Sheets");
    if(workSheets == Q_NULLPTR)
    {
        QMessageBox::critical(0,"错误信息","打开Excel的sheets失败");
        return 201;
    }
    workSheet=workBook->querySubObject("Sheets(int)",1);
    if(workSheet == Q_NULLPTR)
    {
        QMessageBox::critical(0,"错误信息","打开Excel的sheet失败");
        return 201;
    }
    QList<QList<QVariant>> m_data;
    QList<QVariant> header_data;
    header_data.append("检验时间");
    header_data.append("比对结果");
    header_data.append("姓名");
    header_data.append("身份证号");
    header_data.append("性别");
    header_data.append("民族");
    header_data.append("出生日期");
    header_data.append("住址");
    header_data.append("签发机关");
    header_data.append("有效期限");
    header_data.append("身份证头像路径");
    header_data.append("人脸采集图路径");
    m_data.append(header_data);
    for(int i = 0; i < totalcount; i++)
    {
        QList<QVariant> info_data;
        info_data.append(data->alldata[i].Time);
        info_data.append(data->alldata[i].Result);
        info_data.append(data->alldata[i].Name);
        info_data.append(data->alldata[i].ID);
        info_data.append(data->alldata[i].Gender);
        info_data.append(data->alldata[i].Nation);
        info_data.append(data->alldata[i].Birthtime);
        info_data.append(data->alldata[i].Home);
        info_data.append(data->alldata[i].Office);
        info_data.append(data->alldata[i].ValidTime);
        info_data.append(data->alldata[i].idimage);
        info_data.append(data->alldata[i].faceimage);
        m_data.append(info_data);
    }
    int row = m_data.size();
    QString rangeStr = QString("A1:L%1").arg(QString::number(row));
    QAxObject *range=workSheet->querySubObject("Range(const QString&)",rangeStr);
    qDebug()<<"debug4";
    if(NULL == range || range->isNull())
    {
        return 201;
    }
    QVariant var;
    QVariantList vars;
    for(int i = 0; i < row; i++)
    {
        vars.append(QVariant(m_data[i]));
    }
    var = QVariant(vars);
    range->setProperty("Value",var);
    delete range;
    workBook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(excel_filename));
    workBook->dynamicCall("Close(Boolen)",false);
    excel->dynamicCall("Quit(void)");

    return 200;
}
void DMWidget::close_loading(int num)
{
    if(num == 200)
    {
        loadingwindow->close();
        QMessageBox::information(this,"提示","Excel文件导出成功");
    }
    else
    {
        loadingwindow->close();
        QMessageBox::information(this,"提示","Excel文件导出失败");
    }
}

//导入数据库
void DMWidget::close_importloading(int num)
{

    importloading->close();
    Treewidgetinit();//初始化树
    TreewidgetIteminit();//生成树节点
    data->selectdata_noimage(model,"",0);//所有数据分页
    currentPage=1;
    updateall();
    QMessageBox::warning(NULL,"提示",QString("成功导入%1条记录").arg(QString::number(num)),"确定");
}
int DMWidget::import_start()
{
    data->database_close();
    qDebug()<<import_filename;
    data->connect_database(import_filename);
    int backupcount=data->selectdata_all("");
    data->database_close();
    data->connect_database(DATABASE_PATH);
    QFileInfo fileInfo(import_filename);
    QString photodir = fileInfo.path() + "/" + "photo";
    QString wzdir = fileInfo.path() + "/" + "WZ";
    QDir dirphoto(photodir);
    QDir dirwz(wzdir);
    if(dirphoto.exists())
        copyDirectory(photodir,"data/photo",false);
    if(dirwz.exists())
        copyDirectory(wzdir,"data/WZ",false);
    return data->insertdata(backupcount);
}
void DMWidget::importdatabase()
{
    import_filename=QFileDialog::getOpenFileName(NULL,tr("选择数据库文件"),".","*.db *.sqlite",NULL,QFileDialog::DontUseNativeDialog);
    if(import_filename.isEmpty())
    {
        return;
    }
    else {
        importloading->show();
        delete importprogress;
        importprogress=new ImportThread(this);

        connect(importprogress,SIGNAL(send_importcmd(int)),this,SLOT(close_importloading(int)));
        importprogress->start();

    }
}

//备份数据库
void DMWidget::backupdatabase()
{
    data->database_close();
    backup_dirname=QFileDialog::getExistingDirectory(this,"Backup Data",QDir::currentPath(),QFileDialog::DontUseNativeDialog);
    if(backup_dirname.isEmpty())
    {
        return;
    }
    QDateTime time = QDateTime::currentDateTime();
    backup_dirname+="/"+time.toString("yyyy-MM-dd-hhmmss")+"-backup.zip";
    backuploading->show();
    qDebug()<<backup_dirname;
    delete backupprogress;
    backupprogress=new BackupThread(this);
    connect(backupprogress,SIGNAL(send_backupcmd(bool)),this,SLOT(close_backuploading(bool)));
    backupprogress->start();

}
bool DMWidget::backup_start()
{
    bool ok=JlCompress::compressDir(backup_dirname,"./data");
    return ok;
}
void DMWidget::close_backuploading(bool ok)
{
    if(ok)
    {
        backuploading->close();
        QMessageBox::information(this,"提示","数据备份成功!");
    }
    else
    {
        backuploading->close();
        QMessageBox::information(this,"提示","数据备份失败!");
    }
}
//打印
void DMWidget::clicked_Print()
{
    QItemSelectionModel *selection=tableview->selectionModel();
    QModelIndexList selected=selection->selectedIndexes();
    if(selected.size()==0)
    {
        QMessageBox::information(this,"提示","请选择一条数据!");
        return;
    }
    print->PrintDocument();
}

bool DMWidget::copyDirectory(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){
            if(!copyDirectory(fileInfo.filePath(),
                              targetDir.filePath(fileInfo.fileName()),
                              coverFileIfExist))
                return false;
        }
        else{
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }

            if(!QFile::copy(fileInfo.filePath(),
                            targetDir.filePath(fileInfo.fileName()))){
                return false;
            }
        }
    }
    return true;
}


/*****************导出excel线程************************/
ProgressThread::ProgressThread(DMWidget *win)
{
    this->win = win;
}

void ProgressThread::run()
{
    qDebug()<<"正在导出excel";
    emit send_startcmd(win->export_start());
}
/*****************导入数据库线程************************/
ImportThread::ImportThread(DMWidget *win)
{
    this->win = win;
}

void ImportThread::run()
{
    qDebug()<<"正在导入数据";
    emit send_importcmd(win->import_start());
}
/*****************备份数据线程************************/
BackupThread::BackupThread(DMWidget *win)
{
    this->win=win;
}

void BackupThread::run()
{
    qDebug()<<"正在备份数据";
    emit send_backupcmd(win->backup_start());
}
//返回槽
void DMWidget::exitslot()
{
    emit exitsignal(false);
    close();
}
