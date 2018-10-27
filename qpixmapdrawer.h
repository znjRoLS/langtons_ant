#pragma once

#include <QLabel>

class QPixmapDrawer : public QLabel
{
public:
    QPixmapDrawer(QWidget *parent);

    QPixmap *_pixmap;
protected:
    void paintEvent(QPaintEvent *) override;
private:
    int iter_num = 0;
private:
};
