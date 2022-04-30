#ifndef LOADING_02_H
#define LOADING_02_H

#include <QObject>
#include <QWidget>

#include "tools_widget.h";
using namespace XZ::Tools;

namespace XZ {
namespace Wgt {


class loading_02 : public QWidget
{
    Q_OBJECT
public:
    explicit loading_02(QWidget *parent = nullptr);
    ~loading_02();

private:

protected:
    void paintEvent(QPaintEvent *) override;

private:
    enum Img_Type{
        IT_A, IT_B, IT_C, IT_D, IT_E, IT_F, IT_G,
    };
    QImage * m_img_A001;
    QImage * m_img_B001;
    QImage * m_img_C001;
    QImage * m_img_C002;
    QImage * m_img_D001;
    QImage * m_img_E001;
    QImage * m_img_F001;
    QImage * m_img_F002;
    QImage * m_img_F003;
    QImage * m_img_F004;
    QImage * m_img_F005;
    QImage * m_img_F006;
    QImage * m_img_G001;
    QImage * m_img_G002;
    QImage * m_img_G003;
    QImage * m_img_G004;
    QImage * m_img_G005;

private:
    bool load_img(QImage *& _img, QString _file);

private:
    quint8 m_timer_times_run;
    QTimer * m_timer_repaint;

    void fun_paint_loading(QPainter *_painter);
    
private slots:
    void slot_timer_repaint();

signals:

private:
    qreal get_rotate_B(int _pic, int _num);
    qreal get_rotate_C_1(int _num);
    qreal get_rotate_C_2(int _num);
    qreal get_rotate_C(int _pic, int _num);
    qreal get_rotate_D(int _pic, int _num);
    qreal get_rotate_E(int _pic, int _num);
    qreal get_rotate_F_1(int _num);
    qreal get_rotate_F_2(int _num);
    qreal get_rotate_F_3(int _num);
    qreal get_rotate_F_4(int _num);
    qreal get_rotate_F_5(int _num);
    qreal get_rotate_F_6(int _num);
    qreal get_rotate_F(int _pic, int _num);
    qreal get_rotate_G_1(int _num);
    qreal get_rotate_G_2(int _num);
    qreal get_rotate_G_3(int _num);
    qreal get_rotate_G_4(int _num);
    qreal get_rotate_G_5(int _num);
    qreal get_rotate_G(int _pic, int _num);

    qreal get_rotate(int _type, int _pic, int _num);
};

}}

#endif // LOADING_02_H
