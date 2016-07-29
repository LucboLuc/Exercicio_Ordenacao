#ifndef ALGORITMOSORDENACAO_H
#define ALGORITMOSORDENACAO_H

#include<QList>
class AlgoritmosOrdenacao
{
public:
    AlgoritmosOrdenacao();
    QList<long> radixSortComBubbleSort(QList<long> &vector);
    QList<long> radixSortComInsertionSort(QList<long> &vector);
    QList<long> radixSortComCounting(QList<long> &vector);
    QList<long> radixSortComMerge(QList<long> &vector);
    QList<long> bubbleCrescente(QList<long> &vector);
    QList<long> bubbleDecrescente(QList<long> &vector);

private:
    QList<long> bubbleSort(QList<long> vector, long numeroDecimal);
    QList<long> selectionSort(QList<long> vector, long numeroDecimal);
    QList<long> insertionSort(QList<long> vector, long numeroDecimal);
    void mergeSort(QList<long> &vector, long l, long r, long numeroDecimal);
    void merge(QList<long> &vector, long l, long m, long r, long numeroDecimal);
    QList<long> countingSort(QList<long> vector, long numeroDecimal);

    int digitoDoNumero(long numero, long numeracaoDecimal);
    long maximoValor(QList<long> vector);
};

#endif // ALGORITMOSORDENACAO_H
