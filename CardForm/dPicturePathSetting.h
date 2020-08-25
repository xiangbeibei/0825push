#ifndef DPICTUREPATHSETTING_H
#define DPICTUREPATHSETTING_H

#include <QDialog>

namespace Ui {
class dPicturePathSetting;
}

class dPicturePathSetting : public QDialog
{
    Q_OBJECT

public:
    explicit dPicturePathSetting(QWidget *parent = 0);
    ~dPicturePathSetting();

private:
    Ui::dPicturePathSetting *ui;
};

#endif // DPICTUREPATHSETTING_H
