#include "loading_15.h"

#include <QPainter>
#include <QMatrix>
#include <QTimer>
#include <QDebug>
#include <QFile>

namespace XZ {
namespace Wgt {

void loading_15::slot_timer_repaint()
{
    m_timer_times_run ++;
    if( m_timer_times_run > 40 ){
        m_timer_times_run = 1;
    }

    this->repaint();
}

loading_15::loading_15(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_StyledBackground, true);

    XTWidget::load_img( m_img_B001, ":/imgs/img_15/360_B0001.png" );
    XTWidget::load_img( m_img_C001, ":/imgs/img_15/360_C0001.png" );
    XTWidget::load_img( m_img_D001, ":/imgs/img_15/360_D0001.png" );
    XTWidget::load_img( m_img_D002, ":/imgs/img_15/360_D0002.png" );
    XTWidget::load_img( m_img_D003, ":/imgs/img_15/360_D0003.png" );
    XTWidget::load_img( m_img_D004, ":/imgs/img_15/360_D0004.png" );
    XTWidget::load_img( m_img_D005, ":/imgs/img_15/360_D0005.png" );
    XTWidget::load_img( m_img_E001, ":/imgs/img_15/360_E0001.png" );
    XTWidget::load_img( m_img_E002, ":/imgs/img_15/360_E0002.png" );
    XTWidget::load_img( m_img_E003, ":/imgs/img_15/360_E0003.png" );
    XTWidget::load_img( m_img_E004, ":/imgs/img_15/360_E0004.png" );
    XTWidget::load_img( m_img_E005, ":/imgs/img_15/360_E0005.png" );

    m_timer_repaint = new QTimer(this);
    m_timer_repaint->setInterval( 100 );
    connect(m_timer_repaint, SIGNAL(timeout()), this, SLOT(slot_timer_repaint()));
    m_timer_repaint->start();

    slot_timer_repaint();
}

loading_15::~loading_15()
{
    m_timer_repaint->stop();

    delete m_img_B001;
    delete m_img_C001;
    delete m_img_D001;
    delete m_img_D002;
    delete m_img_D003;
    delete m_img_D004;
    delete m_img_D005;
    delete m_img_E001;
    delete m_img_E002;
    delete m_img_E003;
    delete m_img_E004;
    delete m_img_E005;
}

void loading_15::fun_paint_loading(QPainter * _painter)
{
    QRect rectB001(195, 160, 140, 140);
    XTWidget::draw_roate_image(_painter, get_rotate(IT_B, 1, m_timer_times_run), m_img_B001, rectB001 );
    QRect rectC001(20, 70, 200, 200);
    XTWidget::draw_roate_image(_painter, get_rotate(IT_C, 1, m_timer_times_run), m_img_C001, rectC001 );

    QRect rectDraw(0, 0, 360, 360);

    XTWidget::draw_roate_image(_painter, get_rotate(IT_E, 1, m_timer_times_run), m_img_E001, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_E, 2, m_timer_times_run), m_img_E002, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_E, 3, m_timer_times_run), m_img_E003, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_E, 4, m_timer_times_run), m_img_E004, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_E, 5, m_timer_times_run), m_img_E005, rectDraw );

//    XTWidget::draw_roate_image(_painter, get_rotate(IT_D, 1, m_timer_times_run), m_img_D001, rectDraw );
//    XTWidget::draw_roate_image(_painter, get_rotate(IT_D, 2, m_timer_times_run), m_img_D002, rectDraw );
//    XTWidget::draw_roate_image(_painter, get_rotate(IT_D, 3, m_timer_times_run), m_img_D003, rectDraw );
//    XTWidget::draw_roate_image(_painter, get_rotate(IT_D, 4, m_timer_times_run), m_img_D004, rectDraw );
//    XTWidget::draw_roate_image(_painter, get_rotate(IT_D, 5, m_timer_times_run), m_img_D005, rectDraw );
}

void loading_15::paintEvent(QPaintEvent *)
{
    QPainter qpPaint;
    qpPaint.begin( this );
    fun_paint_loading(&qpPaint);
    qpPaint.end();

    QString sSave = QString("./loading_15_%1.png").arg(m_timer_times_run, 3, 10, QChar('0'));
    if( ! QFile::exists( sSave )){
        QImage * img_save = new QImage(360, 360, QImage::Format_ARGB32);
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

qreal loading_15::get_rotate_B(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return -1 * 360.0 / 40.0 * _num ;
}

qreal loading_15::get_rotate_C(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return -1 * 360.0 / 20.0 * _num ;
}

qreal loading_15::get_rotate_D_1(int _num){
    static qreal g_d_1 = 0.0;
    if( _num < 6){
        g_d_1 = (-1 * 160.0 / 5.0) * _num;
    }
    else if( _num < 11){
        g_d_1 = -160.0 + (-170.0 / 5.0) * (_num - 5);
    }
    else{
        g_d_1 = -330.0 + ( -1 * (_num - 10) );
    }
    return g_d_1;
}
qreal loading_15::get_rotate_D_2(int _num){
    static qreal g_d_2 = 0.0;
    if( _num < 6){
        g_d_2 = (-1 * 170.0 / 5.0) * _num;
    }
    else if( _num < 11){
        g_d_2 = -170.0 + (-160.0 / 5.0 * (_num - 5));
    }
    else{
        g_d_2 = -330.0 + ( -1 * (_num - 10) );
    }
    return g_d_2;
}
qreal loading_15::get_rotate_D_3(int _num){
    static qreal g_d_3 = 0.0;
    if( _num < 6){
        g_d_3 =  (-1 * 180.0 / 5.0) * _num;
    }
    else if( _num < 11){
        return -180.0 + ((-150 / 5) * (_num - 5));
    }
    else{
        g_d_3 =  -330.0 + ( -1 * (_num - 10) );
    }
    return g_d_3;
}
qreal loading_15::get_rotate_D_4(int _num){
    static qreal g_d_4 = 0.0;
    if( _num < 6){
        g_d_4 =  (-1 * 190.0 / 5.0) * _num;
    }
    else if( _num < 11){
        g_d_4 =  -190.0 + (-1 * (140.0 / 5.0) * (_num - 5));
    }
    else{
        g_d_4 =  -330.0 + ( -1 * (_num - 10) );
    }
    return g_d_4;
}
qreal loading_15::get_rotate_D_5(int _num){
    static qreal g_d_5 = 0.0;
    if( _num < 6){
        g_d_5 = (-1 * 200.0 / 5.0) * _num;
    }
    else if( _num < 11){
        g_d_5 =  -200.0 + (-1 * (130.0 / 5.0) * (_num - 5));
    }
    else{
        g_d_5 =  -330.0 + ( -1 * (_num - 10) );
    }
    return g_d_5;
}

qreal loading_15::get_rotate_D(int _pic, int _num)
{
    switch (_pic) {
    case 1 : return get_rotate_D_1(_num);
    case 2 : return get_rotate_D_2(_num);
    case 3 : return get_rotate_D_3(_num);
    case 4 : return get_rotate_D_4(_num);
    case 5 : return get_rotate_D_5(_num);
    default: return 0.0;
    }
}

qreal loading_15::get_rotate_E_1(int _num){
    if( _num < 11){
        return (10.0 / 10.0) * _num;
    }
    else if( _num < 21){
        return 10.0 + (90.0 / 10.0) * (_num - 10);
    }
    else if( _num < 31){
        return 10.0 + 90.0 + 180.0 / 10 * (_num - 20);
    }
    else if(_num < 41){
        return 10.0 + 90.0 + 180.0 + (80.0 / 10)  * (_num - 30);
    }
    return 0.0;
}
qreal loading_15::get_rotate_E_2(int _num){
    if( _num < 11){
        return (30.0 / 10.0) * _num;
    }
    else if( _num < 21){
        return 30.0 + (70.0 / 10.0) * (_num - 10);
    }
    else if( _num < 31){
        return 30.0 + 70.0 + 200.0 / 10 * (_num - 20);
    }
    else if(_num < 41){
        return 30.0 + 70.0 + 200.0 + (60.0 / 10)  * (_num - 30);
    }
    return 0.0;
}
qreal loading_15::get_rotate_E_3(int _num){
    if( _num < 11){
        return (50.0 / 10.0) * _num;
    }
    else if( _num < 21){
        return 50.0 + (50.0 / 10.0) * (_num - 10);
    }
    else if( _num < 31){
        return 50.0 + 50.0 + 220.0 / 10 * (_num - 20);
    }
    else if(_num < 41){
        return 50.0 + 50.0 + 220.0 + (40.0 / 10)  * (_num - 30);
    }
    return 0.0;
}
qreal loading_15::get_rotate_E_4(int _num){
    if( _num < 11){
        return (70.0 / 10.0) * _num;
    }
    else if( _num < 21){
        return 70.0 + (30.0 / 10.0) * (_num - 10);
    }
    else if( _num < 31){
        return 70.0 + 30.0 + 240.0 / 10 * (_num - 20);
    }
    else if(_num < 41){
        return 70.0 + 30.0 + 240.0 + (20.0 / 10)  * (_num - 30);
    }
    return 0.0;
}
qreal loading_15::get_rotate_E_5(int _num){
    if( _num < 11){
        return (90.0 / 10.0) * _num;
    }
    else if( _num < 21){
        return 90.0 + (10.0 / 10.0) * (_num - 10);
    }
    else if( _num < 31){
        return 90.0 + 10.0 + 260.0 / 10 * (_num - 20);
    }
    else if(_num < 41){
        return 0.00;
    }
    return 0.0;
}

qreal loading_15::get_rotate_E(int _pic, int _num)
{
    switch (_pic) {
    case 1 : return get_rotate_E_1(_num);
    case 2 : return get_rotate_E_2(_num);
    case 3 : return get_rotate_E_3(_num);
    case 4 : return get_rotate_E_4(_num);
    case 5 : return get_rotate_E_5(_num);
    default: return 0.0;
    }
}

qreal loading_15::get_rotate(int _type, int _pic, int _num)
{
    switch (_type) {
    case IT_B : return get_rotate_B(_pic, _num);
    case IT_C : return get_rotate_C(_pic, _num);
    case IT_D : return get_rotate_D(_pic, _num);
    case IT_E : return get_rotate_E(_pic, _num);
    default: return 0.0;
    }
}



}}
