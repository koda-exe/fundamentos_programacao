/*============================================================================*/
/* ICSF13 - 2024-1 - TRABALHO 2                                               */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                                                            */
/* Yasmin Lis Maravalhas Goncalves                                            */
/*============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "trabalho2.h"
#include "wavfile.h"

///Funcao 1: modifica o compimento da onda de um sinal
///      Parâmetros: double* dados: vetor de dados.
///                   int n_amostras: número de amostras no vetor.
///                   double ganho: modificador do ganho
///A função percorre todas as amostras no vetor dados e
///ajusta o volume de cada amostra multiplicar pelo valor de ganho.
///Este ajuste é feito in-place, ou seja, o próprio vetor de entrada é modificado diretamente.
void mudaGanho (double* dados, int n_amostras, double ganho)
{
    int i;//variavel de controle de interação i.

    for(i=0; i<n_amostras; i++)//loop para percorrer o vetor dados
    {
        dados[i]= dados[i]*ganho;//multiplica o valor atual do vetor pelo ganho.
    }
}

///Funcao 2:
///Parâmetros: double* dados: vetor de dados.
///            int n_amostras: número de amostras no vetor.
///            int tam_ciclo: número de amostras em um ciclo.
///A função aplica um efeito de tremolo estilo dente de serra ao vetor dados.
///O ganho começa em 0 e aumenta linearmente até atingir tam_ciclo - 1.
///Quando o ganho atinge o valor tam_ciclo, ele é resetado para 0 e o ciclo se repete.
///Isso faz com que cada amostra no vetor dados seja multiplicada por um fator que oscila de 0 a 1
/// em um padrão dente de serra com um ciclo de duração especificada por tam_ciclo.
///O resultado é uma modulação periódica do volume do sinal, dando a impressão de um efeito tremolo.
void tremoloDenteDeSerra (double* dados, int n_amostras, int tam_ciclo)
{

    double ganho = 0.0;// Inicializa a variável 'ganho' que será usada para calcular o fator de multiplicação
    int i;

    for(i=0; i <n_amostras; i++) // Loop através de todas as amostras do vetor 'dados
    {
        // Multiplica a amostra atual pelo ganho normalizado (ganho dividido pelo tamanho do ciclo - 1)
        dados[i] = dados[i]*(ganho/(tam_ciclo-1));

        ganho++;// Incrementa o ganho


        // Se o ganho atinge o valor do tamanho do ciclo, ele é resetado para 0
        if(ganho == tam_ciclo)
        {
            ganho = 0;
        }
    }
}

///Funcao 3:
///Parâmetros: double* dados: vetor de dados.
///                int n_amostras: número de amostras no vetor.
///                int taxa: taxa de amostragem do sinal.
///                double freq: frequência da onda.
///                int ascendente: se for igual a 0, a onda é descendente, do
///                contrário, a onda é ascendente.*/
///A função preenche um vetor de amostras com uma onda dente de serra,
///que pode ser ascendente ou descendente.
///A onda é gerada calculando a posição de cada amostra dentro do ciclo da onda
///e ajustando o valor da amostra com base em se a onda está na primeira ou na segunda metade do ciclo,
///seguindo um padrão linear que varia de 0 a 1 ou de 0 a -1 para descendente.
void geraOndaDenteDeSerra(double* dados, int n_amostras, int taxa, double freq, int ascendente)
{
   // Calcula o período da onda em amostras
    double periodo = (double)taxa / freq;

    // Preenche o buffer com a onda dente de serra
    for (int i = 0; i < n_amostras; ++i)
    {
        // Calcula a posição no ciclo, que varia entre 0 e 1
        double posicao_no_ciclo = fmod((double)i / periodo, 1.0);

        // Se a onda for ascendente
        if (ascendente)
        {
            if (posicao_no_ciclo < 0.5)
            {
                // Primeira metade do ciclo: cresce de 0 a 1
                dados[i] = posicao_no_ciclo * 2.0;
            }
            else
            {
                // Segunda metade do ciclo: cresce de -1 a 0
                dados[i] = (posicao_no_ciclo - 0.5) * 2.0 - 1.0;
            }
        }
        // Se a onda for descendente
        else
        {
            if (posicao_no_ciclo < 0.5)
            {
                // Primeira metade do ciclo: decresce de 0 a -1
                dados[i] = -posicao_no_ciclo * 2.0;
            }
            else
            {
                // Segunda metade do ciclo: decresce de 1 a 0
                dados[i] = -(posicao_no_ciclo - 0.5) * 2.0 + 1.0;
        }
    }
}

///Funcao 4:
///Parâmetros: double* dados: vetor de dados.
///                int n_amostras: número de amostras no vetor.
///                Valor de retorno: o checksum calculado.
///Nessa função tenho que mudar as amostras q iniciam em 0 quando chega na 1
///para negativo -1 até 0 que mudará para positivo novamente, mas se atentando q nem
///sempre vai ser um inteiro e sim float que vai se aprosimar do valor.
///Nessa funcao converte valor em um inteiro de um byte,
///depois usa a operação XOR para combinar este valor no checksum acumulado e verifica se está corrompida.
unsigned char checksum (double* dados, int n_amostras)
{
    int i, arredonda, recebeDados;
    unsigned char chk=0; // Inicializa a variável 'chk' com 0, que armazenará o checksum

    /* Loop para percorrer todas as amostras no vetor 'dados' */
    for(i=0; i<n_amostras; i++)
    {
        //converte o valor da amostra atual para numero em valor absoluto em inteiro em 8 bits ou 1 byte, e arredondando.
        recebeDados=((int)(fabs(dados[i])*255) + 0.5);

        //se o numero for maior que 255, crava em 255;
        if(recebeDados>255)
        {
            recebeDados = 255;
        }
        //operação bit a bit  com ^ para somar cada n_bit de cada amostra.
        // Aplica a operação XOR (^) entre 'chk' e 'recebeDados'
        chk ^=recebeDados;
    }
    // Retorna o checksum calculado
    return (chk);
}
