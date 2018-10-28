#pragma once

#include <QLabel>
#include <QImage>

class QPixmapDrawer : public QLabel
{
public:
    QPixmapDrawer(QWidget *parent);

    QImage *_image;
protected:
    void paintEvent(QPaintEvent *) override;
private:
    int iter_num = 0;
private:
};
