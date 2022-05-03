#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QPainter>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setGeometry(450, 250, 560, 320);

    m_load16 = new XZ::Wgt::loading_16(this);
    m_load16->setObjectName("loading06");
    m_load16->setGeometry(100, 160, 360, 120);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    m_load16->show();
    this->ui->pb_merge_png->show();
}


void MainWindow::on_pb_merge_png_clicked()
{
    qreal rHeight = 64.0;                          //120缩小到64
    qreal rWidth  = 64.0 / 120.0 * 360.0;
    qreal rWidthAll = rWidth * 36;
    QImage * img_save = new QImage(rWidthAll, rHeight, QImage::Format_ARGB32);
    img_save->fill(QColor(0, 0, 0, 0));
    QPainter * p_qp_img = new QPainter();

    p_qp_img->begin(img_save);
    for(int ifor0 = 1; ifor0 < 37; ifor0 ++){
        QString sLoad = QString("./loading_16_%1.png").arg(ifor0, 3, 10, QChar('0'));
        if( QFile::exists(sLoad)){
            QImage imgLoad;
            imgLoad.load(sLoad);

            QRect rectTar(rWidth * (ifor0 - 1), 0, rWidth, rHeight);
            QRect rectSrc(0, 0, imgLoad.width(), imgLoad.height());
            p_qp_img->drawImage(rectTar, imgLoad, rectSrc);
        }
    }
    p_qp_img->end();
    QString sMerge = QString("./loading_16_merge.png");
    img_save->save(sMerge, "png", 80);
    delete img_save;
    delete p_qp_img;
}

void MainWindow::on_pb_color_replace_clicked()
{
    QString sSrc = QString("./loading_16_merge.png");
    if( ! QFile::exists(sSrc)) return;

    QImage * img_src = new QImage();
    img_src->load(sSrc);

    t_u_color_rgb * rgbSrc = reinterpret_cast<t_u_color_rgb *>(img_src->bits());
    int iCountBits = img_src->width() * img_src->height();
    while( iCountBits -- > 0 ){
        rgbSrc->rgba = (rgbSrc->rgba_bits[3] > 0) ? 0xD0FFFFFF : rgbSrc->rgba; // A R G B
        rgbSrc ++;
    }

    QString sTar = QString("./loading_16_m_white.png");
    img_src->save(sTar, "png", 80);
    delete img_src;
}
