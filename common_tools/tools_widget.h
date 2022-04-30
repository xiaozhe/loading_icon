#ifndef XTWIDGET_TOOLS_XZ_H
#define XTWIDGET_TOOLS_XZ_H

#include <QObject>
#include <QWidget>

namespace XZ {
namespace Tools {


class XTWidget
{
public:
    static void draw_roate_image(QPainter *_paint, qreal _rot, QImage * _img, QRect & _tar);
    static bool load_img(QImage *& _img, QString _file);

};

}}

#endif // XTWIDGET_TOOLS_XZ_H
