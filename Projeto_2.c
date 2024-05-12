#include <stdio.h>
#include <stdlib.h>

#include "trabalho2.h"
#include "wavfile.h"

/*Funcao 1: modifica o compimento da onda de um sinal*/
/*Parâmetros: double* dados: vetor de dados.
                  int n_amostras: número de amostras no vetor.
                  double ganho: modificador do ganho*/
/*void mudaGanho (double* dados, int n_amostras, double ganho)
{

}

/*Funcao 2: */
/*Parâmetros: double* dados: vetor de dados.
                int n_amostras: número de amostras no vetor.
                int tam_ciclo: número de amostras em um ciclo.*/
/*void tremoloDenteDeSerra (double* dados, int n_amostras, int tam_ciclo)
{

}

/*Funcao 3: */
/*Parâmetros: double* dados: vetor de dados.
                int n_amostras: número de amostras no vetor.
                int taxa: taxa de amostragem do sinal.
                double freq: frequência da onda.
                int ascendente: se for igual a 0, a onda é descendente, do
                contrário, a onda é ascendente.*/
void geraOndaDenteDeSerra (double* dados, int n_amostras, int taxa, double freq,
int ascendente)
{

}

/*Funcao 4: */
/*Parâmetros: double* dados: vetor de dados.
                int n_amostras: número de amostras no vetor.
                Valor de retorno: o checksum calculado.
    Nessa função tenho que mudar as amostras q iniciam em 0 quando chega na 1
para negativo -1 até 0 que mudará para positivo novamente, mas se atentando q nem
sempre vai ser um inteiro e sim float que vai se aprosimar do valor. */
int ehPar (int n)
{
    if(n%2)
        return (0);

    return (1);
}
/*Nessa funcao verifica se a soma de todas as amostras esta corrompida*/
unsigned char checksum (double* dados, int n_amostras)
{
    int i, somaBits, aux;
    double mult;
    /*esta multiplicando o vetor com 255, se for maior q 255 o resultado
      iguala a 255, transforma o valor em inteiro, soma a cada loop o valor de aux */
    for(i=0; i<n_amostra; i++)
    {
        int chk[i];

        somaBits = 0;
        mult= dados[i] * 255;
        if(mult>255)
            mult=255;

        aux = mult;
        somaBits+=aux;
        //preciso verificar o 8 bit do n-1, com o somaBits se esta ok.
        while(aux)
        {
            somaBits += aux%2;
            aux/=2;//preciso do 8 bit
        }

        if(ehPar(somaBits))
            chk[i] = dados[i];
        else
            chk[i] = dados[i] | 0x80;

    }

    printf("%lf", chk);

}

/*Funções do arquivo wavfile.c estara em uso dentro das funções criadas, são:

int readWavFile (char* filename, WavHeader* header,
double** data_l, double** data_r);
Abre um arquivo wav e lê o seu conteúdo.

int writeWavFile (char* filename, WavHeader* header,
double* data_l, double* data_r);
Escreve os dados de áudio em um arquivo wav. Esta função NÃO testa os dados do cabeçalho, então dados
inconsistentes não serão detectados. Cuidado!

WavHeader generateSignal (int* n_samples, unsigned short num_channels, unsigned
long sample_rate, double** data_l, double** data_r);
Gera um sinal de conteúdo indeterminado. Use esta função se, em vez de ler os dados de um arquivo, você
quiser gerar um sinal.

void generateRandomData (double* data, int n_samples);
Preenche um vetor dado com dados aleatórios (ruído). A função NÃO inicia a semente aleatória.

int writeSamplesAsText (char* filename, double* data,
unsigned long n_samples);
Salva as amostras em um arquivo de texto, uma amostra por linha. Esta função é útil para visualizar os
dados e depurar o trabalho.
*/
