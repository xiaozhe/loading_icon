#include "loading_02.h"

#include <QPainter>
#include <QMatrix>
#include <QTimer>
#include <QDebug>
#include <QFile>

namespace XZ {
namespace Wgt {

void loading_02::slot_timer_repaint()
{
    m_timer_times_run ++;
    if( m_timer_times_run > 40 ){
        m_timer_times_run = 1;
    }

    this->repaint();
}

loading_02::loading_02(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_StyledBackground, true);

    XTWidget::load_img( m_img_A001, ":/imgs/img_02/100_A001.png" );
    XTWidget::load_img( m_img_B001, ":/imgs/img_02/100_B001.png" );
    XTWidget::load_img( m_img_C001, ":/imgs/img_02/100_C001.png" );
    XTWidget::load_img( m_img_C002, ":/imgs/img_02/100_C002.png" );
    XTWidget::load_img( m_img_D001, ":/imgs/img_02/100_D001.png" );
    XTWidget::load_img( m_img_E001, ":/imgs/img_02/100_E001.png" );
    XTWidget::load_img( m_img_F001, ":/imgs/img_02/100_F001.png" );
    XTWidget::load_img( m_img_F002, ":/imgs/img_02/100_F002.png" );
    XTWidget::load_img( m_img_F003, ":/imgs/img_02/100_F003.png" );
    XTWidget::load_img( m_img_F004, ":/imgs/img_02/100_F004.png" );
    XTWidget::load_img( m_img_F005, ":/imgs/img_02/100_F005.png" );
    XTWidget::load_img( m_img_F006, ":/imgs/img_02/100_F006.png" );
    XTWidget::load_img( m_img_G001, ":/imgs/img_02/100_G001.png" );
    XTWidget::load_img( m_img_G002, ":/imgs/img_02/100_G002.png" );
    XTWidget::load_img( m_img_G003, ":/imgs/img_02/100_G003.png" );
    XTWidget::load_img( m_img_G004, ":/imgs/img_02/100_G004.png" );
    XTWidget::load_img( m_img_G005, ":/imgs/img_02/100_G005.png" );

    m_timer_repaint = new QTimer(this);
    m_timer_repaint->setInterval( 100 );
    connect(m_timer_repaint, SIGNAL(timeout()), this, SLOT(slot_timer_repaint()));
    m_timer_repaint->start();

    slot_timer_repaint();
}

loading_02::~loading_02()
{
    m_timer_repaint->stop();

    delete m_img_A001;
    delete m_img_B001;
    delete m_img_C001;
    delete m_img_C002;
    delete m_img_D001;
    delete m_img_E001;
    delete m_img_F001;
    delete m_img_F002;
    delete m_img_F003;
    delete m_img_F004;
    delete m_img_F005;
    delete m_img_F006;
    delete m_img_G001;
    delete m_img_G002;
    delete m_img_G003;
    delete m_img_G004;
    delete m_img_G005;
}

void loading_02::fun_paint_loading(QPainter * _painter)
{
    QRect rectDraw(0, 0, 100, 100);

    XTWidget::draw_roate_image(_painter, get_rotate(IT_A, 1, m_timer_times_run), m_img_A001, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_B, 1, m_timer_times_run), m_img_B001, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_C, 1, m_timer_times_run), m_img_C001, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_C, 2, m_timer_times_run), m_img_C002, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_D, 1, m_timer_times_run), m_img_D001, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_E, 1, m_timer_times_run), m_img_E001, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_F, 1, m_timer_times_run), m_img_F001, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_F, 2, m_timer_times_run), m_img_F002, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_F, 3, m_timer_times_run), m_img_F003, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_F, 4, m_timer_times_run), m_img_F004, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_F, 5, m_timer_times_run), m_img_F005, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_F, 6, m_timer_times_run), m_img_F006, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_G, 1, m_timer_times_run), m_img_G001, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_G, 2, m_timer_times_run), m_img_G002, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_G, 3, m_timer_times_run), m_img_G003, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_G, 4, m_timer_times_run), m_img_G004, rectDraw );
    XTWidget::draw_roate_image(_painter, get_rotate(IT_G, 5, m_timer_times_run), m_img_G005, rectDraw );

}

void loading_02::paintEvent(QPaintEvent *)
{
    QPainter qpPaint;
    qpPaint.begin( this );
    fun_paint_loading(&qpPaint);
    qpPaint.end();

    QString sSave = QString("./loading_02_%1.png").arg(m_timer_times_run, 3, 10, QChar('0'));
    if( ! QFile::exists( sSave )){
        QImage * img_save = new QImage(100, 100, QImage::Format_ARGB32);
        img_save->fill(QColor(0, 0, 0, 0));
        QPainter * p_qp_img = new QPainter();

        p_qp_img->begin(img_save);
        fun_paint_loading(p_qp_img);
        p_qp_img->end();
        img_save->save(sSave, "png", 100);
        delete img_save;
        delete p_qp_img;
    }

//    QString sLog = QString("");
//    sLog += QString("%1").arg(m_rotate_f001, 8, 'g', 3, QChar(' '));
//    sLog += QString("%1").arg(m_rotate_f002, 8, 'g', 3, QChar(' '));
//    sLog += QString("%1").arg(m_rotate_f003, 8, 'g', 3, QChar(' '));
//    sLog += QString("%1").arg(m_rotate_f004, 8, 'g', 3, QChar(' '));
//    qDebug() << sLog;
}

qreal loading_02::get_rotate_B(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return -1 * 360.0 / 20.0 * _num ;
}

qreal loading_02::get_rotate_C_2(int _num)
{
    return get_rotate_C_1(_num);
    //return 0.0;
}

qreal loading_02::get_rotate_C_1(int _num)
{
    if( _num < 11){
        return (-1 * 90.0 / 10.0) * _num;
    }
    else if( _num < 21){
        return (-1 * 90.0);
    }
    else if( _num < 31){
        return (-1 * 90.0) + (-1 * 270.0 / 10.0) * _num;
    }
    return 0.0;
}

qreal loading_02::get_rotate_C(int _pic, int _num)
{
    switch (_pic) {
    case 1 : return get_rotate_C_1(_num);
    case 2 : return get_rotate_C_2(_num);
    default: return 0.0;
    }
}

qreal loading_02::get_rotate_D(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return 1 * 360.0 / 40.0 * _num ;
}

qreal loading_02::get_rotate_E(int _pic, int _num)
{
    Q_UNUSED(_pic);
    return 180.0 / 40.0 * _num ;
}

qreal loading_02::get_rotate_F_1(int _num){
    if( _num < 11){
        return (-1 * 55.0 / 10.0) * _num;
    }
    else if( _num < 16){
        return -55.0 + (-280.0 / 5.0) * (_num - 10);
    }
    else{
        return -335.0 + ( -1 * (_num - 15) );
    }
    return 0.0;
}
qreal loading_02::get_rotate_F_2(int _num){
    if( _num < 11){
        return (-1 * 90.0 / 10.0) * _num;
    }
    else if( _num < 16){
        return -90.0 + (-1 * (_num - 10));
    }
    else if( _num < 21){
        return -95.0 + ( -1 * (245.0 / 5.0) * (_num - 15) );
    }
    else{
        return -340.0 + ( -1 * (_num - 20) );
    }
    return 0.0;
}
qreal loading_02::get_rotate_F_3(int _num){
    if( _num < 11){
        return (-1 * 165.0 / 10.0) * _num;
    }
    else if( _num < 21){
        return -165.0 + (-1 * (_num - 10));
    }
    else if( _num < 26){
        return -170.0 + ( -1 * (175.0 / 5.0) * (_num - 20) );
    }
    else{
        return -345.0 + ( -1 * (_num - 25) );
    }
    return 0.0;
}
qreal loading_02::get_rotate_F_4(int _num){
    if( _num < 11){
        return (-1 * 205.0 / 10.0) * _num;
    }
    else if( _num < 26){
        return -205.0 + (-1 * (_num - 10));
    }
    else if( _num < 31){
        return -220.0 + ( -1 * (130.0 / 5.0) * (_num - 25) );
    }
    else{
        return -350.0 + ( -1 * (_num - 30) );
    }
    return 0.0;
}
qreal loading_02::get_rotate_F_5(int _num){
    if( _num < 11){
        return (-1 * 240.0 / 10.0) * _num;
    }
    else if( _num < 31){
        return -240.0 + (-1 * (_num - 10));
    }
    else if( _num < 35){
        return -260.0 + ( -1 * (95.0 / 5.0) * (_num - 30) );
    }
    else{
        return -355.0 + ( -1 * (_num - 35) );
    }
    return 0.0;
}
qreal loading_02::get_rotate_F_6(int _num){
    if( _num < 11){
        return (-1 * 283.0 / 10.0) * _num;
    }
    else if( _num < 35){
        return -283.0 + (-1 * (_num - 10));
    }
    else if( _num < 41){
        return -308.0 + ( -1 * (52.0 / 5.0) * (_num - 35) );
    }
    return 0.0;
}

qreal loading_02::get_rotate_F(int _pic, int _num)
{
    switch (_pic) {
    case 1 : return get_rotate_F_1(_num);
    case 2 : return get_rotate_F_2(_num);
    case 3 : return get_rotate_F_3(_num);
    case 4 : return get_rotate_F_4(_num);
    case 5 : return get_rotate_F_5(_num);
    case 6 : return get_rotate_F_6(_num);
    default: return 0.0;
    }
}

qreal loading_02::get_rotate_G_1(int _num){
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
qreal loading_02::get_rotate_G_2(int _num){
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
qreal loading_02::get_rotate_G_3(int _num){
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
qreal loading_02::get_rotate_G_4(int _num){
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
qreal loading_02::get_rotate_G_5(int _num){
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

qreal loading_02::get_rotate_G(int _pic, int _num)
{
    switch (_pic) {
    case 1 : return get_rotate_G_1(_num);
    case 2 : return get_rotate_G_2(_num);
    case 3 : return get_rotate_G_3(_num);
    case 4 : return get_rotate_G_4(_num);
    case 5 : return get_rotate_G_5(_num);
    default: return 0.0;
    }
}

qreal loading_02::get_rotate(int _type, int _pic, int _num)
{
    switch (_type) {
    case IT_B : return get_rotate_B(_pic, _num);
    case IT_C : return get_rotate_C(_pic, _num);
    case IT_D : return get_rotate_D(_pic, _num);
    case IT_E : return get_rotate_E(_pic, _num);
    case IT_F : return get_rotate_F(_pic, _num);
    case IT_G : return get_rotate_G(_pic, _num);
    default: return 0.0;
    }
}



}}
