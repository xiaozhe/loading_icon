#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "loading_06.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef union union_color_rgb
{
    uint rgba;
    uchar rgba_bits[4];
} t_u_color_rgb;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void showEvent(QShowEvent *) override;

private slots:
    void on_pb_merge_png_clicked();

    void on_pb_color_replace_clicked();

private:
    Ui::MainWindow *ui;

    XZ::Wgt::loading_06 * m_load06;
};
#endif // MAINWINDOW_H
