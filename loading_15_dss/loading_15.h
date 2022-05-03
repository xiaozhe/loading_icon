#ifndef LOADING_15_H
#define LOADING_15_H

#include <QObject>
#include <QWidget>

#include "tools_widget.h";
using namespace XZ::Tools;

namespace XZ {
namespace Wgt {


class loading_15 : public QWidget
{
    Q_OBJECT
public:
    explicit loading_15(QWidget *parent = nullptr);
    ~loading_15();

private:

protected:
    void paintEvent(QPaintEvent *) override;

private:
    enum Img_Type{
        IT_B, IT_C, IT_D, IT_E,
    };
    QImage * m_img_B001;
    QImage * m_img_C001;
    QImage * m_img_D001;
    QImage * m_img_D002;
    QImage * m_img_D003;
    QImage * m_img_D004;
    QImage * m_img_D005;
    QImage * m_img_E001;
    QImage * m_img_E002;
    QImage * m_img_E003;
    QImage * m_img_E004;
    QImage * m_img_E005;

private:
    quint8 m_timer_times_run;
    QTimer * m_timer_repaint;

    void fun_paint_loading(QPainter *_painter);
    
private slots:
    void slot_timer_repaint();

signals:

private:
    qreal get_rotate_B(int _pic, int _num);
    qreal get_rotate_C(int _pic, int _num);
    qreal get_rotate_D_1(int _num);
    qreal get_rotate_D_2(int _num);
    qreal get_rotate_D_3(int _num);
    qreal get_rotate_D_4(int _num);
    qreal get_rotate_D_5(int _num);
    qreal get_rotate_D(int _pic, int _num);
    qreal get_rotate_E_1(int _num);
    qreal get_rotate_E_2(int _num);
    qreal get_rotate_E_3(int _num);
    qreal get_rotate_E_4(int _num);
    qreal get_rotate_E_5(int _num);
    qreal get_rotate_E(int _pic, int _num);

    qreal get_rotate(int _type, int _pic, int _num);
};

}}

#endif // loading_15_H
