#ifndef LOADING_06_H
#define LOADING_06_H

#include <QObject>
#include <QWidget>

namespace XZ {
namespace Wgt {


class loading_06 : public QWidget
{
    Q_OBJECT
public:
    explicit loading_06(QWidget *parent = nullptr);
    ~loading_06();

private:
    void draw_roate_image(QPainter *_paint, qreal _rot, QImage * _img, QRect & _tar);

protected:
    void paintEvent(QPaintEvent *) override;

private:
    QImage * m_img_A001;
    QImage * m_img_F001; qreal m_f001[4], m_rotate_f001;
    QImage * m_img_F002; qreal m_f002[4], m_rotate_f002;
    QImage * m_img_F003; qreal m_f003[4], m_rotate_f003;
    QImage * m_img_F004; qreal m_f004[4], m_rotate_f004;
    QImage * m_img_G001; qreal            m_rotate_g001;
    QImage * m_img_H001; qreal            m_rotate_h001;

    QImage * m_img_I001; qreal m_i001[4], m_rotate_i001;
    QImage * m_img_I002; qreal m_i002[4], m_rotate_i002;
    QImage * m_img_I003; qreal m_i003[4], m_rotate_i003;
    QImage * m_img_I004; qreal m_i004[4], m_rotate_i004;

    QImage * m_img_J001;
    QImage * m_img_J002;
    QImage * m_img_J003;
    QImage * m_img_J004;

    QImage * m_img_K001; qreal            m_rotate_k001;

    QImage * m_img_L001;
    QImage * m_img_L002;
    QImage * m_img_L003;

private:
    bool load_img(QImage *& _img, QString _file);

private:
    quint8 m_circle_stage;
    quint8 m_circle_stage_times;
    quint8 m_timer_times_run;
    QTimer * m_timer_repaint;

    void fun_paint_loading(QPainter *_painter);
    
private slots:
    void slot_timer_repaint();

signals:

};

}}

#endif // LOADING_06_H
