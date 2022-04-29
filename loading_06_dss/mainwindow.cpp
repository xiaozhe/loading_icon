#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setGeometry(450, 250, 300, 300);

    m_load06 = new XZ::Wgt::loading_06(this);
    m_load06->setObjectName("loading06");
    m_load06->setGeometry(100, 100, 100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    m_load06->show();
}

