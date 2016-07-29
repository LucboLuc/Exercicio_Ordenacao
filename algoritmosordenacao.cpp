#include "algoritmosordenacao.h"
#include <QDebug>
AlgoritmosOrdenacao::AlgoritmosOrdenacao()
{

}

QList<long> AlgoritmosOrdenacao::radixSortComBubbleSort(QList<long> &vector)
{
    for(long i = 1; i <= maximoValor(vector); i*=10)
        vector = bubbleSort(vector,i);

    return vector;
}

QList<long> AlgoritmosOrdenacao::radixSortComInsertionSort(QList<long> &vector)
{
    for(long i = 1; i <= maximoValor(vector); i*=10)
        vector = insertionSort(vector,i);

    return vector;
}

QList<long> AlgoritmosOrdenacao::radixSortComCounting(QList<long> &vector)
{
    for(long i = 1; i <= maximoValor(vector); i*=10)
        vector = countingSort(vector,i);

    return vector;
}

QList<long> AlgoritmosOrdenacao::radixSortComMerge(QList<long> &vector)
{
    for(long i = 1; i <= maximoValor(vector); i*=10)
        mergeSort(vector,0,vector.size()-1,i);

    return vector;
}

QList<long> AlgoritmosOrdenacao::bubbleCrescente(QList<long> &vector)
{
    for(int i=vector.size()-1; i >= 1; i--){
        for( int j=0; j < i ; j++){
            if(vector[j] > vector[j+1]){
                long aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
    return vector;
}

QList<long> AlgoritmosOrdenacao::bubbleDecrescente(QList<long> &vector)
{
    for(int i=vector.size()-1; i >= 1; i--){
        for( int j=0; j < i ; j++){
            if(vector[j] <  vector[j+1]){
                long aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
    return vector;
}

QList<long> AlgoritmosOrdenacao::bubbleSort(QList<long> vector, long numeroDecimal)
{
    for(int i=vector.size()-1; i >= 1; i--){
        for( int j=0; j < i ; j++){
            if(digitoDoNumero(vector[j], numeroDecimal)>digitoDoNumero(vector[j+1],numeroDecimal)){
                long aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
    return vector;
}

QList<long> AlgoritmosOrdenacao::selectionSort(QList<long> vector, long numeroDecimal)
{
    long i, j, min, aux;
    for (i = 0; i < (vector.size()-1); i++) {
        min = i;
        for (j = (i+1); j < vector.size(); j++) {
          if(digitoDoNumero(vector[j],numeroDecimal) < digitoDoNumero(vector[min],numeroDecimal))
            min = j;
        }
        if (i != min) {
          aux = vector[i];
          vector[i] = vector[min];
          vector[min] = aux;
        }
    }
    return vector;
}

QList<long> AlgoritmosOrdenacao::insertionSort(QList<long> vector, long numeroDecimal)
{

    long i, j, atual;

    for (i = 1; i < vector.size(); i++){
        atual = vector[i];
        j = i - 1;

        while ((j >= 0) && (digitoDoNumero(atual,numeroDecimal) < digitoDoNumero(vector[j],numeroDecimal)))
        {
            vector[j + 1] = vector[j];
            j = j - 1;
        }

        vector[j + 1] = atual;
    }
    return vector;
}

void AlgoritmosOrdenacao::mergeSort(QList<long> &vector, long l, long r,  long numeroDecimal)
{

    if (l < r)
        {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            long m = l+(r-l)/2;

            // Sort first and second halves
            mergeSort(vector, l, m, numeroDecimal);
            mergeSort(vector, m+1, r, numeroDecimal);

            merge(vector, l, m, r, numeroDecimal);
        }
}

void AlgoritmosOrdenacao::merge(QList<long> &vector, long l, long m, long r, long numeroDecimal)
{
    long i, j, k;
    long n1 = m - l + 1;
    long n2 =  r - m;

    /* create temp arrays */
    long L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = vector[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vector[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (digitoDoNumero(L[i], numeroDecimal) <= (digitoDoNumero(R[j], numeroDecimal)))
        {
            vector[k] = L[i];
            i++;
        }
        else
        {
            vector[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        vector[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        vector[k] = R[j];
        j++;
        k++;
    }
}

QList<long> AlgoritmosOrdenacao::countingSort(QList<long> vector, long numeroDecimal)
{
    QList<long> aux, saida;; // output array
    long i;

    for(long i = 0; i <= vector.size()-1; i++)
        saida.append(0);

    for(long i = 0; i < 10; i++)
        aux.append(0);

    // Store count of occurrences in count[]
    for (i = 0; i < vector.size(); i++)
        aux[ digitoDoNumero(vector[i],numeroDecimal) ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        aux[i] += aux[i - 1];

    // Build the output array
    for (i = vector.size() - 1; i >= 0; i--)
    {
        saida[aux[ digitoDoNumero(vector[i],numeroDecimal) ] - 1] = vector[i];
        aux[digitoDoNumero(vector[i],numeroDecimal)]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < vector.size(); i++)
        vector[i] = saida[i];

    return saida;
}

int AlgoritmosOrdenacao::digitoDoNumero(long numero, long numeracaoDecimal)
{
    return (numero/numeracaoDecimal) % 10;
}

long AlgoritmosOrdenacao::maximoValor(QList<long> vector)
{
    long maximo = vector[0];
    for(long i : vector){
        if(maximo < i)
            maximo = i;
    }

    return maximo;
}
