#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QDateEdit>
#include<QToolButton>
#include<QMouseEvent>
#include<QCheckBox>
namespace Ui {
class selectWidget;
}

class selectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit selectWidget(QWidget *parent = 0);
    ~selectWidget();

private:
    Ui::selectWidget *ui;
    /*-----选项标签-----*/
    QLabel *s_Title;
    QLabel *s_namelabel;
    QLabel *s_IDlabel;
    QLabel *s_genderlabel;
    QLabel *s_resultlabel;
    QLabel *s_begindate;
    QLabel *s_endlabel;
    /*-----选项输入框------*/
    QLineEdit *nameEdit;
    QLineEdit *IDEdit;
    QComboBox *genderCombox;
    QComboBox *resultCombox;
    QDateEdit *beginEdit;
    QDateEdit *endEdit;
    /*-----按钮----------*/
    QToolButton *OKbutton;
    QToolButton *Cancelbutton;
    /*-----复选框----------*/
    QCheckBox *namecheckbox;
    QCheckBox *idcheckbox;
    QCheckBox *gendercheckbox;
    QCheckBox *resultcheckbox;
    QCheckBox *begintimecheckbox;
    QCheckBox *endTimecheckbox;

    QPoint last;
protected://重写鼠标事件，使窗口可移动
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void paintEvent(QPaintEvent *e);
     /*-----查询实现----------*/
public:
    void query_condition();
signals:
    void sendSQL(QString);
public slots:
    void on_selectbutton();
private:
    QString statement;

};

#endif // SELECTWIDGET_H
