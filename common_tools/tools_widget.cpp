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

    qreal qrSrcWidth = _img->width();
    qreal qrSrcHeigh = _img->height();

    QImage * imgRot = new QImage();
    * imgRot = _img->transformed( matrix );

    qreal qrWidth = imgRot->width();
    qreal qrHeight = imgRot->height();
    qreal qrX = (qrWidth - qrSrcWidth) / 2;
    qreal qrY = (qrHeight - qrSrcHeigh) / 2;
    QRect rectImg(qrX, qrY, qrSrcWidth, qrSrcHeigh);
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
    qDebug() << "can find file: " << _file;
    _img = new QImage();
    return false;
}








}}
