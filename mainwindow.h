#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QEventLoop>
#include <QPen>
#include <QFileDialog>
#include <QAction>
#include <QMenu>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int i{};
    QPointF one;
    QPointF two;
    QPointF oneRelease;
    QGraphicsScene *scene=new QGraphicsScene();
    QPen myPen;
    QString str;
    QMenu *menu=new QMenu;
    QAction *action=new QAction("&Save as",this);
    QFileDialog *dialog=new QFileDialog;
    QImage image;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ConnectButtonsAndWaitFotClick();
    void TakeTextAndSetPenColor();
    void ConnectWithReady();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void SetLine();
    void SetCircle();
    void Clear();
    int GetI();
    int Getx1();
    int Getx2();
    int Gety1();
    int Gety2();
    private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
