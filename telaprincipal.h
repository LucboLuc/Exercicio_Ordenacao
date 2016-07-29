#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include "algoritmosordenacao.h"
#include <QTextEdit>
#include <QLabel>

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPrincipal(QWidget *parent = 0);
    ~TelaPrincipal();

private slots:
    void gerarVector();
    void ordenarVector();
    void aplicarAlgoritmosDeOrdenacao();
    void on_pushButton_Executador_clicked();
    long gerarNumeros();
    void plotarEntrada();
    void plotarSaida(QTextEdit *saida);
    void plotarTempo(QLabel *tempo, double tempoMedioExecucao);
    void limparAreaDeEntrada();
    void limparAreaDeSaida();
    void reiniciarVector();
    void verificarCampos();

private:
    Ui::TelaPrincipal *ui;
    QList<long> vector, vectorDesordenado;
    AlgoritmosOrdenacao algoritmoOrdenacao;
};

#endif // TELAPRINCIPAL_H
