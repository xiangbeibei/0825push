#include "selectwidget.h"
#include "ui_selectwidget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QDateEdit>
#include<QGridLayout>
#include<QPalette>
#include<QPushButton>
#include<QColor>
#include<QMouseEvent>
#include<QPainter>
#include<QPen>
#include<QCheckBox>
#include<QToolButton>
#include<QMessageBox>
#include<QDebug>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
selectWidget::selectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectWidget)
{
    ui->setupUi(this);
    this->setFixedSize(337,308);
    this->setWindowIcon(QIcon(":/image/Image/icons8-name-tag-64.ico"));
    /*------标题设置-----*/
    s_Title=new QLabel(this);
    s_Title->setText("查询条件设置");
    s_Title->setStyleSheet("color:white;font-size:20px;font-weight:bold");
    s_Title->setGeometry(20,16,141,20);
    s_Title->show();
     /*------背景颜色-----*/
    //颜色修改
    QColor backgroundcolor(1,192,198);
    QPalette backgroundpalette;
    backgroundpalette=QPalette(backgroundcolor);
    setAutoFillBackground(true);
    backgroundpalette.setColor(QPalette::Background,backgroundcolor);
    backgroundpalette.setColor(QPalette::Button,backgroundcolor);
    setPalette(backgroundpalette);
     /*------选项设置-----*/
//姓名
    namecheckbox=new  QCheckBox(this);

    namecheckbox->setGeometry(40,70,19,19);
    namecheckbox->show();
    s_namelabel=new QLabel(this);
    s_namelabel->setText(tr("姓    名:"));
    s_namelabel->setStyleSheet("color:white;font-size:14px");
    s_namelabel->setGeometry(65,70,81,19);
    s_namelabel->show();
    nameEdit=new QLineEdit(this);
    nameEdit->setGeometry(150,70,150,19);
    nameEdit->show();

//身份证
    idcheckbox=new QCheckBox(this);

    idcheckbox->setGeometry(40,100,19,19);
    idcheckbox->show();
    s_IDlabel=new QLabel(this);
    s_IDlabel->setText("身份证号:");
    s_IDlabel->setStyleSheet("color:white;font-size:14px");
    s_IDlabel->setGeometry(65,100,81,19);
    s_IDlabel->show();
    IDEdit=new QLineEdit(this);
    IDEdit->setGeometry(150,100,150,19);
    IDEdit->show();

//性别
    gendercheckbox=new QCheckBox(this);
    gendercheckbox->setGeometry(40,130,19,19);

    gendercheckbox->show();
    s_genderlabel=new QLabel(this);
    s_genderlabel->setText(tr("性    别:"));
    s_genderlabel->setStyleSheet("color:white;font-size:14px");
    s_genderlabel->setGeometry(65,130,81,19);
    s_genderlabel->show();
    genderCombox=new QComboBox(this);
    genderCombox->addItem("男");
    genderCombox->addItem("女");
    genderCombox->setGeometry(150,130,150,19);
    genderCombox->show();

//比对结果
    resultcheckbox=new QCheckBox(this);

    resultcheckbox->setGeometry(40,160,19,19);
    resultcheckbox->show();
    s_resultlabel=new QLabel(this);
    s_resultlabel->setText(tr("比对结果:"));
    s_resultlabel->setStyleSheet("color:white;font-size:14px");
    s_resultlabel->setGeometry(65,160,81,19);
    s_resultlabel->show();
    resultCombox=new QComboBox(this);
    resultCombox->addItem("匹配");
    resultCombox->addItem("不匹配");
    resultCombox->addItem("未比对");
    resultCombox->setGeometry(150,160,150,19);
    resultCombox->show();

//开始时间
    begintimecheckbox=new QCheckBox(this);

    begintimecheckbox->setGeometry(40,190,19,19);
    begintimecheckbox->show();
    s_begindate=new QLabel(this);
    s_begindate->setText(tr("开始时间:"));
    s_begindate->setStyleSheet("color:white;font-size:14px");
    s_begindate->setGeometry(65,190,81,19);
    s_begindate->show();
    beginEdit=new QDateEdit(this);
    beginEdit->setCalendarPopup(true);
    beginEdit->setGeometry(150,190,150,19);
    QDate date=QDate::currentDate();
    beginEdit->setDisplayFormat("yyyy/MM/dd");
    beginEdit->setDate(date);
    beginEdit->show();

//结束时间
    endTimecheckbox=new QCheckBox(this);
    endTimecheckbox->setGeometry(40,220,19,19);
    endTimecheckbox->show();

    s_endlabel=new QLabel(this);
    s_endlabel->setText(tr("结束时间:"));
    s_endlabel->setStyleSheet("color:white;font-size:14px");
    s_endlabel->setGeometry(65,220,81,19);
    s_endlabel->show();
    endEdit=new QDateEdit(this);
    endEdit->setCalendarPopup(true);
    endEdit->setGeometry(150,220,150,19);
    endEdit->setDate(date);
    endEdit->setDisplayFormat("yyyy/MM/dd");
    endEdit->show();

//按钮
    OKbutton=new QToolButton(this);
    Cancelbutton=new QToolButton(this);
    OKbutton->setText("查询");
    Cancelbutton->setText("取消");
    OKbutton->setStyleSheet("QToolButton{border:2px solid white;background-color:rgb(1,192,198);color:white}");
    Cancelbutton->setStyleSheet("QToolButton{border:2px solid white;background-color:rgb(1,192,198);color:white}");
    OKbutton->setGeometry(50,260,61,25);
    Cancelbutton->setGeometry(220,260,61,25);
    OKbutton->show();
    Cancelbutton->show();
    connect(Cancelbutton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(OKbutton,SIGNAL(clicked(bool)),this,SLOT(on_selectbutton()));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
}

/*------------------鼠标事件-----------------------*/
selectWidget::~selectWidget()
{
    delete ui;
}
void selectWidget::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void selectWidget::mouseMoveEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    last=e->globalPos();
    move(x()+dx,y()+dy);
}
void selectWidget::mouseReleaseEvent(QMouseEvent *e)
{
    int dx=e->globalX()-last.x();
    int dy=e->globalY()-last.y();

    move(x()+dx,y()+dy);
}

/*----------------绘制边框，线条-----------------------*/
void selectWidget::paintEvent(QPaintEvent *e)
{
    QPainter painterrect(this);
    QPen penrect;
    penrect.setColor(Qt::white);
    penrect.setWidth(6);
    painterrect.setPen(penrect);
    painterrect.drawRect(0,0,337,308);

    QPainter painterline(this);
    QPen penline;
    penline.setColor(Qt::white);
    penline.setWidth(3);
    painterline.setPen(penline);
    painterline.drawLine(0,46,337,46);
}
/*----------------查询按钮槽-----------------------*/
void selectWidget::on_selectbutton()
{
    query_condition();
    emit sendSQL(statement);//发送sql语句信号
    this->close();
}
/*----------------多条件查询SQL语句拼接-----------------------*/
void selectWidget::query_condition()
{
    bool check=true;
     QStringList condition;//查询条件字符串链

    if(namecheckbox->isChecked())
    {
        if(nameEdit->text().isEmpty())
        {
            check=false;
        }
        else
        {
            QString name_condition=QString("and Name like '%1%'").arg(nameEdit->text());
            condition+=name_condition;
        }
    }
    if(idcheckbox->isChecked())
    {
        if(IDEdit->text().isEmpty())
        {
            check=false;
        }
        else
        {
            QString id_condition=QString("and ID='''%1'").arg(IDEdit->text());
            condition+=id_condition;
        }
    }
    if(gendercheckbox->isChecked())
    {
        QString gender_condition=QString("and Gender='%1'").arg(genderCombox->currentText());
        condition+=gender_condition;
    }
    if(resultcheckbox->isChecked())
    {
        QString result_condition=QString("and Result='%1'").arg(resultCombox->currentText());
        condition+=result_condition;
    }
    if(begintimecheckbox->isChecked())//时间查询判断
    {
        if(endTimecheckbox->isChecked())//时间闭区间
        {
            QString time_condition=QString("and Time between '%1' and '%2'").arg(beginEdit->text()).arg(endEdit->text());
            time_condition += QString("or Time like '%1%'").arg(endEdit->text());
            qDebug()<<time_condition;
            condition+=time_condition;
        }
        else//时间右开区间
        {
            QString time_condition=QString("and Time >= '%1'").arg(beginEdit->text());
            condition+=time_condition;
        }
    }
    else if(endTimecheckbox->isChecked())//时间左开区间
    {
        QString time_condition=QString("and Time < '%1'").arg(endEdit->text());
        time_condition += QString("or Time like '%1%'").arg(endEdit->text());
        condition+=time_condition;
    }
    statement="";
   for(int i=0;i<condition.size();i++)
    {
         statement=statement+condition.at(i);
    }
    if(check==false)
    {
         QMessageBox::information(this,"提示","请输入完整查询条件!");
    }
}
