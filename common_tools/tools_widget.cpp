#include "tools_widget.h"

#include <QPainter>
#include <QMatrix>
#include <QTimer>
#include <QDebug>
#include <QFile>

namespace XZ {
namespace Tools {

void XTWidget::draw_roate_image(QPainter *_paint, qreal _rot, QImage *_img, QRect &_tar)
{
    QMatrix  matrix;
    matrix.rotate( _rot );

    QImage * imgRot = new QImage();
    * imgRot = _img->transformed( matrix );

    qreal qrTWidth = _tar.width();
    qreal qrTHeight = _tar.height();
    qreal qrWidth = imgRot->width();
    qreal qrHeight = imgRot->height();
    qreal qrX = (qrWidth - qrTWidth) / 2;
    qreal qrY = (qrHeight - qrTHeight) / 2;
    QRect rectImg(qrX, qrY, qrTWidth, qrTHeight);
    _paint->drawImage(_tar, * imgRot, rectImg);
    delete  imgRot;
}

bool XTWidget::load_img(QImage *&_img, QString _file)
{
    if( QFile::exists(_file)){
        _img = new QImage();
        _img->load(_file);
        return true;
    }
    _img = new QImage();
    return false;
}








}}
