#include "telaprincipal.h"
#include "ui_telaprincipal.h"
#include <QDebug>
#include <QElapsedTimer>

#include <QTime>

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    connect(ui->comboBox_TamanhoVector, SIGNAL(activated(QString)), this, SLOT(verificarCampos()));
    connect(ui->comboBox_OrdemVector,SIGNAL(activated(QString)),this,SLOT(verificarCampos()));
    connect(ui->spinBox_QuantidadeEnsaios,SIGNAL(valueChanged(int)),this,SLOT(verificarCampos()));
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::gerarVector()
{
//    limparAreaDeEntrada();

    vector.clear();

    long tamanhoVector = ui->comboBox_TamanhoVector->currentText().toLong();

    for(int i=0;i<tamanhoVector;i++)
        vector.append(gerarNumeros());

     vectorDesordenado = vector;

//    plotarEntrada();
}

void TelaPrincipal::ordenarVector()
{
    QString ordenacao = ui->comboBox_OrdemVector->currentText();

    if(ordenacao == "CRESCENTE")
        algoritmoOrdenacao.bubbleCrescente(vector);
    else
        if(ordenacao == "DECRESCENTE")
            algoritmoOrdenacao.bubbleDecrescente(vector);

    limparAreaDeEntrada();

    plotarEntrada();
}

void TelaPrincipal::aplicarAlgoritmosDeOrdenacao()
{
    double soma = 0.0, media=0.0;
    int quantidadeEnsaios = ui->spinBox_QuantidadeEnsaios->value();
    limparAreaDeSaida();

    QElapsedTimer tempo;

    for(int i = 0; i < quantidadeEnsaios; i++){
        reiniciarVector();
        tempo.start();
        algoritmoOrdenacao.radixSortComBubbleSort(vector);
        soma += tempo.elapsed();
    }
    media = soma/quantidadeEnsaios;
    plotarSaida(ui->textEdit_BubbleSortSaida);
    plotarTempo(ui->label_TempoBubble, media);

    soma=0;
    for(int i = 0; i < quantidadeEnsaios; i++){
        reiniciarVector();
        tempo.start();
        algoritmoOrdenacao.radixSortComInsertionSort(vector);
        soma += tempo.elapsed();
    }
    media = soma/quantidadeEnsaios;
    plotarSaida(ui->textEdit_SelectionSortSaida);
    plotarTempo(ui->label_TempoSelection, media);


    soma=0;
    for(int i = 0; i < quantidadeEnsaios; i++){
        reiniciarVector();
        tempo.start();
        algoritmoOrdenacao.radixSortComCounting(vector);
        soma += tempo.elapsed();
    }
    media = soma/quantidadeEnsaios;
    plotarSaida(ui->textEdit_CountingSortSaida);
    plotarTempo(ui->label_TempoCounting, media);

    soma=0;
    for(int i = 0; i < quantidadeEnsaios; i++){
        reiniciarVector();
        tempo.start();
        algoritmoOrdenacao.radixSortComMerge(vector);
        soma += tempo.elapsed();
    }
    media = soma/quantidadeEnsaios;
    plotarSaida(ui->textEdit_MergeSortSaida);
    plotarTempo(ui->label_TempoMerge, media);
}

void TelaPrincipal::on_pushButton_Executador_clicked()
{
    gerarVector();
    ordenarVector();
    aplicarAlgoritmosDeOrdenacao();
}

long TelaPrincipal::gerarNumeros()
{
    return qrand() % ((9999999999 + 1) - 1000000000) + 1000000000;
}

void TelaPrincipal::plotarEntrada()
{
    long tamanhoVector = ui->comboBox_TamanhoVector->currentText().toLong();

    for(long i = 0; i < tamanhoVector; i++){
        ui->textEdit_BubbleSortEntrada->append(QString::number(vector[i]));
        ui->textEdit_SelectionSortEntrada->append(QString::number(vector[i]));
        ui->textEdit_MergeSortEntrada->append(QString::number(vector[i]));
        ui->textEdit_CountingSortEntrada->append(QString::number(vector[i]));
    }
}

void TelaPrincipal::plotarSaida(QTextEdit *saida)
{
    long tamanhoVector = ui->comboBox_TamanhoVector->currentText().toLong();

    for(long i = 0;i < tamanhoVector; i++){
        saida->append(QString::number(vector[i]));
    }
}

void TelaPrincipal::plotarTempo(QLabel *tempo, double tempoMedioExecucao)
{
    tempo->setText("Tempo Médio: "+QString::number(tempoMedioExecucao));
}

void TelaPrincipal::limparAreaDeEntrada()
{
    ui->textEdit_BubbleSortEntrada->clear();
    ui->textEdit_SelectionSortEntrada->clear();
    ui->textEdit_MergeSortEntrada->clear();
    ui->textEdit_CountingSortEntrada->clear();
}

void TelaPrincipal::limparAreaDeSaida()
{
    ui->textEdit_BubbleSortSaida->clear();
    ui->textEdit_SelectionSortSaida->clear();
    ui->textEdit_MergeSortSaida->clear();
    ui->textEdit_CountingSortSaida->clear();
}

void TelaPrincipal::reiniciarVector()
{
    vector = vectorDesordenado;
}

void TelaPrincipal::verificarCampos()
{
    if(ui->comboBox_TamanhoVector->currentText()!="(NENHUM)"){
        ui->comboBox_OrdemVector->setEnabled(true);
        if(ui->comboBox_OrdemVector->currentText()!="(NENHUM)"){
            ui->spinBox_QuantidadeEnsaios->setEnabled(true);
            if(ui->spinBox_QuantidadeEnsaios->value()!=0)
                ui->pushButton_Executador->setEnabled(true);
            else
                ui->pushButton_Executador->setEnabled(false);
        }else{
            ui->spinBox_QuantidadeEnsaios->setEnabled(false);
            ui->pushButton_Executador->setEnabled(false);
        }
    }else{
        ui->comboBox_OrdemVector->setEnabled(false);
        ui->spinBox_QuantidadeEnsaios->setEnabled(false);
        ui->pushButton_Executador->setEnabled(false);
    }
}
