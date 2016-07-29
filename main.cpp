#include "telaprincipal.h"
#include <QApplication>
#include "algoritmosordenacao.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TelaPrincipal w;
    w.show();

    return a.exec();
}
