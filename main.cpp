#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    repeat:
    w.ConnectButtonsAndWaitFotClick();
    w.ConnectWithReady();
    w.TakeTextAndSetPenColor();
    if(w.GetI()==1)
    {
        w.SetLine();
    }
    if(w.GetI()==2)
    {
        w.SetCircle();
    }
    w.Clear();
    goto repeat;
    return a.exec();
}
