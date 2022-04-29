#include "loading_06.h"

#include <QPainter>
#include <QMatrix>
#include <QTimer>
#include <QDebug>

namespace XZ {
namespace Wgt {

bool loading_06::load_img(QImage *&_img, QString _file)
{
    _img = new QImage();
    _img->load(_file);
    return true;
}

void loading_06::slot_timer_repaint()
{
    m_circle_stage_times ++;

    if( m_circle_stage_times == 10 ){
        m_circle_stage_times = 1;

        m_circle_stage ++;
        if( m_circle_stage == 4){
            m_circle_stage = 0;
        }
    }

    int iTimesRun = m_circle_stage * 9 + m_circle_stage_times;

    m_rotate_h001 = (360.0 / 18.0) * iTimesRun * -1;
    m_rotate_g001 = (360.0 / 36.0) * iTimesRun;
    m_rotate_k001 = (360.0 / 36.0) * iTimesRun;

//    m_rotate_g001 = 0;
//    m_rotate_k001 = 0;
//    if(iTimesRun % 2 == 0){
//        m_rotate_g001 = 2.5;
//        m_rotate_k001 = 3.0;
//    }

//    int iInterval = 100;
//    if( m_circle_stage == 0 ) iInterval = 500;
//    if( m_circle_stage == 1 && m_circle_stage_times == 0 ) iInterval = 5000;
//    m_timer_repaint->setInterval( iInterval );

    switch (m_circle_stage) {
    case 0 :
        m_rotate_f001 = m_circle_stage_times * m_f001[0];
        m_rotate_f002 = m_circle_stage_times * m_f002[0];
        m_rotate_f003 = m_circle_stage_times * m_f003[0];
        m_rotate_f004 = m_circle_stage_times * m_f004[0];

        m_rotate_i001 = m_circle_stage_times * m_i001[0];
        m_rotate_i002 = m_circle_stage_times * m_i002[0];
        m_rotate_i003 = m_circle_stage_times * m_i003[0];
        m_rotate_i004 = m_circle_stage_times * m_i004[0];
        break;
    case 1 :
        m_rotate_f001 = m_circle_stage_times * m_f001[1] + m_f001[0] * 9;
        m_rotate_f002 = m_circle_stage_times * m_f002[1] + m_f002[0] * 9;
        m_rotate_f003 = m_circle_stage_times * m_f003[1] + m_f003[0] * 9;
        m_rotate_f004 = m_circle_stage_times * m_f004[1] + m_f004[0] * 9;

        m_rotate_i001 = m_circle_stage_times * m_f001[1] + m_i001[0] * 9;
        m_rotate_i002 = m_circle_stage_times * m_f002[1] + m_i002[0] * 9;
        m_rotate_i003 = m_circle_stage_times * m_f003[1] + m_i003[0] * 9;
        m_rotate_i004 = m_circle_stage_times * m_f004[1] + m_i004[0] * 9;
        break;
    case 2 :
        m_rotate_f001 = m_circle_stage_times * m_f001[2] + m_f001[0] * 9 + m_f001[1] * 9;
        m_rotate_f002 = m_circle_stage_times * m_f002[2] + m_f002[0] * 9 + m_f002[1] * 9;
        m_rotate_f003 = m_circle_stage_times * m_f003[2] + m_f003[0] * 9 + m_f003[1] * 9;
        m_rotate_f004 = m_circle_stage_times * m_f004[2] + m_f004[0] * 9 + m_f004[1] * 9;

        m_rotate_i001 = m_circle_stage_times * m_f001[2] + m_i001[0] * 9 + m_i001[1] * 9;
        m_rotate_i002 = m_circle_stage_times * m_f002[2] + m_i002[0] * 9 + m_i002[1] * 9;
        m_rotate_i003 = m_circle_stage_times * m_f003[2] + m_i003[0] * 9 + m_i003[1] * 9;
        m_rotate_i004 = m_circle_stage_times * m_f004[2] + m_i004[0] * 9 + m_i004[1] * 9;
        break;
    case 3 :
        m_rotate_f001 = m_circle_stage_times * m_f001[3] + m_f001[0] * 9 + m_f001[1] * 9 + m_f001[2] * 9;
        m_rotate_f002 = m_circle_stage_times * m_f002[3] + m_f002[0] * 9 + m_f002[1] * 9 + m_f002[2] * 9;
        m_rotate_f003 = m_circle_stage_times * m_f003[3] + m_f003[0] * 9 + m_f003[1] * 9 + m_f003[2] * 9;
        m_rotate_f004 = m_circle_stage_times * m_f004[3] + m_f004[0] * 9 + m_f004[1] * 9 + m_f004[2] * 9;

        m_rotate_i001 = m_circle_stage_times * m_i001[3] + 337.5;
        m_rotate_i002 = m_circle_stage_times * m_i002[3] + 337.5;
        m_rotate_i003 = m_circle_stage_times * m_i003[3] + 337.5;
        m_rotate_i004 = m_circle_stage_times * m_i004[3] + 337.5;
        break;
    }

    this->repaint();
}

loading_06::loading_06(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_StyledBackground, true);

    load_img( m_img_A001, ":/imgs/img_src/200_A001.png" );
    load_img( m_img_F001, ":/imgs/img_src/200_F001.png" );
    load_img( m_img_F002, ":/imgs/img_src/200_F002.png" );
    load_img( m_img_F003, ":/imgs/img_src/200_F003.png" );
    load_img( m_img_F004, ":/imgs/img_src/200_F004.png" );

    load_img( m_img_G001, ":/imgs/img_src/200_G001.png" );
    load_img( m_img_H001, ":/imgs/img_src/200_H001.png" );

    load_img( m_img_I001, ":/imgs/img_src/200_I001.png" );
    load_img( m_img_I002, ":/imgs/img_src/200_I002.png" );
    load_img( m_img_I003, ":/imgs/img_src/200_I003.png" );
    load_img( m_img_I004, ":/imgs/img_src/200_I004.png" );

    load_img( m_img_J001, ":/imgs/img_src/200_J001.png" );
    load_img( m_img_J002, ":/imgs/img_src/200_J002.png" );
    load_img( m_img_J003, ":/imgs/img_src/200_J003.png" );
    load_img( m_img_J004, ":/imgs/img_src/200_J004.png" );

    load_img( m_img_K001, ":/imgs/img_src/200_K001.png" );

    load_img( m_img_L001, ":/imgs/img_src/200_L001.png" );
    load_img( m_img_L002, ":/imgs/img_src/200_L002.png" );
    load_img( m_img_L003, ":/imgs/img_src/200_L003.png" );

    m_f001[0] =  36.0 / 9.0;  m_f001[1] =  9.0 / 9.0; m_f001[3] = 45.0 / 9.0;  m_f001[2] = 306.0 / 9.0 - m_f001[0];
    m_f002[0] = 116.0 / 9.0;  m_f002[1] =  9.0 / 9.0; m_f002[3] = 45.0 / 9.0;  m_f002[2] = 306.0 / 9.0 - m_f002[0];
    m_f003[0] = 196.0 / 9.0;  m_f003[1] =  9.0 / 9.0; m_f003[3] = 45.0 / 9.0;  m_f003[2] = 306.0 / 9.0 - m_f003[0];
    m_f004[0] = 276.0 / 9.0;  m_f004[1] =  9.0 / 9.0; m_f004[3] = 45.0 / 9.0;  m_f004[2] = 306.0 / 9.0 - m_f004[0];

    m_i001[0] =  22.5 / 9.0;  m_i001[1] = 22.5 / 9.0; m_i001[3] = 22.5 / 9.0;  m_i001[2] = 315.0 / 9.0 - m_i001[0];
    m_i002[0] = 102.5 / 9.0;  m_i002[1] = 22.5 / 9.0; m_i002[3] = 22.5 / 9.0;  m_i002[2] = 315.0 / 9.0 - m_i002[0];
    m_i003[0] = 182.5 / 9.0;  m_i003[1] = 22.5 / 9.0; m_i003[3] = 22.5 / 9.0;  m_i003[2] = 315.0 / 9.0 - m_i003[0];
    m_i004[0] = 217.5 / 9.0;  m_i004[1] = 22.5 / 9.0; m_i004[3] = 22.5 / 9.0;  m_i004[2] = 315.0 / 9.0 - m_i004[0];

    m_circle_stage = 0;
    m_circle_stage_times = 0;
    m_timer_repaint = new QTimer(this);
    m_timer_repaint->setInterval( 100 );
    connect(m_timer_repaint, SIGNAL(timeout()), this, SLOT(slot_timer_repaint()));
    m_timer_repaint->start();

}

loading_06::~loading_06()
{
    m_timer_repaint->stop();

    delete m_img_A001;
    delete m_img_F001;
    delete m_img_F002;
    delete m_img_F003;
    delete m_img_F004;
    delete m_img_G001;
    delete m_img_H001;

    delete m_img_I001;
    delete m_img_I002;
    delete m_img_I003;
    delete m_img_I004;

    delete m_img_J001;
    delete m_img_J002;
    delete m_img_J003;
    delete m_img_J004;

    delete m_img_K001;

    delete m_img_L001;
    delete m_img_L002;
    delete m_img_L003;
}

void loading_06::draw_roate_image(QPainter * _paint, qreal _rot, QImage * _img, QRect & _tar)
{
    QMatrix  matrix;
    matrix.rotate( _rot );

    QImage * imgRot = new QImage();
    * imgRot = _img->transformed( matrix );

    qreal qrWidth = imgRot->width();
    qreal qrHeight = imgRot->height();
    qreal qrX = (qrWidth - 200) / 2;
    qreal qrY = (qrHeight - 200) / 2;
    QRect rectImg(qrX, qrY, 200, 200);
    _paint->drawImage(_tar, * imgRot, rectImg);
    delete  imgRot;
}

void loading_06::paintEvent(QPaintEvent *)
{
    QPainter qpPaint;
    qpPaint.begin( this );

    QRect rectDraw(0, 0, 100, 100);
    qpPaint.drawImage(rectDraw, * m_img_A001);
//    qpPaint.drawImage(rectDraw, * m_img_F001);

    draw_roate_image(&qpPaint, m_rotate_f004, m_img_F004, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_f003, m_img_F003, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_f002, m_img_F002, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_f001, m_img_F001, rectDraw );

    draw_roate_image(&qpPaint, m_rotate_g001, m_img_G001, rectDraw );
    //draw_roate_image(&qpPaint, m_rotate_h001, m_img_H001, rectDraw );

//    draw_roate_image(&qpPaint, m_rotate_i004, m_img_I004, rectDraw );
//    draw_roate_image(&qpPaint, m_rotate_i003, m_img_I003, rectDraw );
//    draw_roate_image(&qpPaint, m_rotate_i002, m_img_I002, rectDraw );
//    draw_roate_image(&qpPaint, m_rotate_i001, m_img_I001, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_g001 * -1, m_img_I004, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_g001 * -1, m_img_I003, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_g001 * -1, m_img_I002, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_g001 * -1, m_img_I001, rectDraw );

    draw_roate_image(&qpPaint, m_rotate_f004, m_img_J004, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_f003, m_img_J003, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_f002, m_img_J002, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_f001, m_img_J001, rectDraw );

    draw_roate_image(&qpPaint, m_rotate_k001, m_img_K001, rectDraw );

    draw_roate_image(&qpPaint, m_rotate_k001, m_img_L001, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_k001, m_img_L002, rectDraw );
    draw_roate_image(&qpPaint, m_rotate_k001, m_img_L003, rectDraw );

//    QString sLog = QString("");
//    sLog += QString("%1").arg(m_rotate_f001, 8, 'g', 3, QChar(' '));
//    sLog += QString("%1").arg(m_rotate_f002, 8, 'g', 3, QChar(' '));
//    sLog += QString("%1").arg(m_rotate_f003, 8, 'g', 3, QChar(' '));
//    sLog += QString("%1").arg(m_rotate_f004, 8, 'g', 3, QChar(' '));
//    qDebug() << sLog;
}





}}
