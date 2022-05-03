#ifndef LOADING_16_H
#define LOADING_16_H

#include <QObject>
#include <QWidget>

#include "tools_widget.h"
using namespace XZ::Tools;

namespace XZ {
namespace Wgt {


class loading_16 : public QWidget
{
    Q_OBJECT
public:
    explicit loading_16(QWidget *parent = nullptr);
    ~loading_16();

private:

protected:
    void paintEvent(QPaintEvent *) override;

private:
    enum Img_Type{
        IT_A, IT_B, IT_C, IT_D, IT_E,
    };
    QImage * m_img_A001;
    QImage * m_img_B001;
    QImage * m_img_C001;
    QImage * m_img_D001;
    QImage * m_img_E001;

private:
    quint8 m_count_run;
    QTimer * m_timer_repaint;

    void fun_paint_loading(QPainter *_painter);
    
private slots:
    void slot_timer_repaint();

signals:

private:
    qreal get_rotate_A(int _pic, int _num);
    qreal get_rotate_B(int _pic, int _num);
    qreal get_rotate_C(int _pic, int _num);
    qreal get_rotate_D(int _pic, int _num);
    qreal get_rotate_E(int _pic, int _num);

    qreal get_rotate(int _type, int _pic, int _num);
};

}}

#endif // loading_16_H
