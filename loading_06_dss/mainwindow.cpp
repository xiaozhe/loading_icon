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

    setGeometry(450, 250, 300, 300);

    m_load06 = new XZ::Wgt::loading_06(this);
    m_load06->setObjectName("loading06");
    m_load06->setGeometry(100, 150, 100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    m_load06->show();
    this->ui->pb_merge_png->show();
}


void MainWindow::on_pb_merge_png_clicked()
{
    QImage * img_save = new QImage(3600, 100, QImage::Format_ARGB32);
    img_save->fill(QColor(0, 0, 0, 0));
    QPainter * p_qp_img = new QPainter();

    p_qp_img->begin(img_save);
    for(int ifor0 = 1; ifor0 < 37; ifor0 ++){
        QString sLoad = QString("./loading_06_%1.png").arg(ifor0, 3, 10, QChar('0'));
        if( QFile::exists(sLoad)){
            QImage imgLoad;
            imgLoad.load(sLoad);

            QRect rectTar(100 * (ifor0 - 1), 0, 100, 100);
            p_qp_img->drawImage(rectTar, imgLoad);
        }
    }
    p_qp_img->end();
    QString sMerge = QString("./animation_merge.png");
    img_save->save(sMerge, "png", 80);
    delete img_save;
    delete p_qp_img;
}

void MainWindow::on_pb_color_replace_clicked()
{
    QString sSrc = QString("./animation_merge.png");
    if( ! QFile::exists(sSrc)) return;

    QImage * img_src = new QImage();
    img_src->load(sSrc);

    t_u_color_rgb * rgbSrc = reinterpret_cast<t_u_color_rgb *>(img_src->bits());
    int iCountBits = img_src->width() * img_src->height();
    while( iCountBits -- > 0 ){
        rgbSrc->rgba = (rgbSrc->rgba_bits[3] > 0) ? 0xD0FFFFFF : rgbSrc->rgba; // A R G B
        rgbSrc ++;
    }

    QString sTar = QString("./animation_merge_white.png");
    img_src->save(sTar, "png", 80);
    delete img_src;
}
