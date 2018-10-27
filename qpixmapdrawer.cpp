#include "qpixmapdrawer.h"

#include <QPainter>
QPixmapDrawer::QPixmapDrawer(QWidget *parent) : QLabel (parent)
{

}

void QPixmapDrawer::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, *_pixmap);
}
