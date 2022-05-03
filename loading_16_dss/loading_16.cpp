#include "loading_16.h"

#include <QPainter>
#include <QMatrix>
#include <QTimer>
#include <QDebug>
#include <QFile>

namespace XZ {
namespace Wgt {

void loading_16::slot_timer_repaint()
{
    m_count_run ++;
    if( m_count_run > 36 ){
        m_count_run = 1;
    }

    this->repaint();
}

loading_16::loading_16(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_StyledBackground, true);

    XTWidget::load_img( m_img_A001, ":/imgs/img_16/A0001.png" );
    XTWidget::load_img( m_img_B001, ":/imgs/img_16/B0001.png" );
    XTWidget::load_img( m_img_C001, ":/imgs/img_16/C0001.png" );
    XTWidget::load_img( m_img_D001, ":/imgs/img_16/D0001.png" );
    XTWidget::load_img( m_img_E001, ":/imgs/img_16/E0001.png" );

    m_timer_repaint = new QTimer(this);
    m_timer_repaint->setInterval( 100 );
    connect(m_timer_repaint, SIGNAL(timeout()), this, SLOT(slot_timer_repaint()));
    m_timer_repaint->start();

    slot_timer_repaint();
}

loading_16::~loading_16()
{
    m_timer_repaint->stop();

    delete m_img_A001;
    delete m_img_B001;
    delete m_img_C001;
    delete m_img_D001;
    delete m_img_E001;
}

void loading_16::fun_paint_loading(QPainter * _painter)
{
    QRect rectA001(  2,  40,  77,  78); XTWidget::draw_roate_image(_painter, get_rotate(IT_A, 1, m_count_run), m_img_A001, rectA001 );
    QRect rectB001( 71,   8,  91,  91); XTWidget::draw_roate_image(_painter, get_rotate(IT_B, 1, m_count_run), m_img_B001, rectB001 );
    QRect rectC001(158,   9,  90,  91); XTWidget::draw_roate_image(_painter, get_rotate(IT_C, 1, m_count_run), m_img_C001, rectC001 );
    QRect rectD001(238,  49,  69,  69); XTWidget::draw_roate_image(_painter, get_rotate(IT_D, 1, m_count_run), m_img_D001, rectD001 );
    QRect rectE001(295,  19,  64,  64); XTWidget::draw_roate_image(_painter, get_rotate(IT_E, 1, m_count_run), m_img_E001, rectE001 );
}

void loading_16::paintEvent(QPaintEvent *)
{
    QPainter qpPaint;
    qpPaint.begin( this );
    fun_paint_loading(&qpPaint);
    qpPaint.end();

    QString sSave = QString("./loading_16_%1.png").arg(m_count_run, 3, 10, QChar('0'));
    if( ! QFile::exists( sSave )){
        QImage * img_save = new QImage(360, 120, QImage::Format_ARGB32);
        img_save->fill(QColor(0, 0, 0, 0));
        QPainter * p_qp_img = new QPainter();

        p_qp_img->begin(img_save);
        fun_paint_loading(p_qp_img);
        p_qp_img->end();
        img_save->save(sSave, "png", 100);
        delete img_save;
        delete p_qp_img;
    }
}

qreal loading_16::get_rotate_A(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return 1 * 10.0 * _num ;
}

qreal loading_16::get_rotate_B(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return -1 * 10.0 * _num ;
}

qreal loading_16::get_rotate_C(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return 10 * _num ;
}

qreal loading_16::get_rotate_D(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return -1 * 10.0 * _num ;
}

qreal loading_16::get_rotate_E(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return 10 * _num ;
}

qreal loading_16::get_rotate(int _type, int _pic, int _num)
{
    switch (_type) {
    case IT_A : return get_rotate_A(_pic, _num);
    case IT_B : return get_rotate_B(_pic, _num);
    case IT_C : return get_rotate_C(_pic, _num);
    case IT_D : return get_rotate_D(_pic, _num);
    case IT_E : return get_rotate_E(_pic, _num);
    default: return 0.0;
    }
}



}}
