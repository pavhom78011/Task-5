#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myPen.setColor(Qt::black);
    menu=menuBar()->addMenu("&Save as");
    myPen.setWidth(3);
}
void MainWindow::ConnectButtonsAndWaitFotClick()
{
    menu->addAction(action);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    QEventLoop loop;
    QObject::connect(ui->radioButton,&QRadioButton::clicked,&loop,[&](){i=1;loop.quit();});
    QObject::connect(ui->radioButton_2,&QRadioButton::clicked,&loop,[&](){i=2;loop.quit();});
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,[&](){scene->clear();});
    QObject::connect(action,&QAction::triggered,qApp,[&](){image=ui->graphicsView->grab().toImage();QString file=dialog->getSaveFileName(this,tr("Save"),QDir::rootPath(),tr("Image(*.jpg *.png)"));image.save(file);});
    ui->dateEdit->setDate(QDate::currentDate());
    loop.exec();
}
void MainWindow::TakeTextAndSetPenColor()
{
    str=ui->comboBox->currentText();
    if(str=="green")
    {
        myPen.setColor(Qt::green);
    }
    if(str=="red")
    {
        myPen.setColor(Qt::red);
    }
    if(ui->lineEdit->text()!="")
    {
        myPen.setWidth((ui->lineEdit->text()).toInt());
    }
}
void MainWindow::ConnectWithReady()
{
    QEventLoop loop;
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,&loop,&QEventLoop::quit);
    loop.exec();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(one.x()==0 and one.y()==0)
    {
        one=ui->graphicsView->mapToScene(event->pos());
        scene->addRect(one.x(),one.y(),3,3,myPen);
    }
    else
    {
        two=ui->graphicsView->mapToScene(event->pos());
        scene->addRect(two.x(),two.y(),3,3,myPen);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    str=ui->comboBox->currentText();
    if(str=="green")
    {
        myPen.setColor(Qt::green);
    }
    if(str=="red")
    {
        myPen.setColor(Qt::red);
    }
    if(str=="black")
    {
        myPen.setColor(Qt::black);
    }
    scene->addRect(event->x(),event->y(),3,3,myPen);
}
void MainWindow::SetLine()
{
    QGraphicsLineItem *line=new QGraphicsLineItem();
    line=scene->addLine(one.x(),one.y(),two.x(),two.y(),myPen);
    line->setFlag(QGraphicsItem::ItemIsMovable);
}
void MainWindow::SetCircle()
{
    QGraphicsEllipseItem *circle=new QGraphicsEllipseItem();
    float x=one.x()-two.x();
    float y=one.y()-two.y();
    if(x<0)
    {
        x=-x;
    }
    if(y<0)
    {
        y=-y;
    }
    if(one.y()>two.y() && one.x()<two.x())
    {
        one.ry()-=y;
    }
    if(one.y()>two.y() && one.x()>two.x())
    {
        one.ry()-=y;
        one.rx()-=x;
    }
    if(one.y()<two.y() && one.x()>two.x())
    {
        one.rx()-=x;
    }
    circle=scene->addEllipse(one.x(),one.y(),x,y,myPen);
}
int MainWindow::GetI()
{
    return i;
}
void MainWindow::Clear()
{
    one.setX(0);
    one.setY(0);
    two.setX(0);
    two.setY(0);
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton->setAutoExclusive(true);
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setAutoExclusive(true);
    myPen.setColor(Qt::black);
}
MainWindow::~MainWindow()
{
    delete ui;
}
