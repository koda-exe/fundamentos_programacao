/*============================================================================*/
/* ICSF13 - 2024-1 - TRABALHO 3                                               */
/*----------------------------------------------------------------------------*/
/** Maria Eduarda De L D                                                      */
/** Namie M Y                                                                 */
/** Yasmin Lis M G                                                            */
/*============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabalho3.h"

#define BRANCO 255
#define PRETO 0
#define CAMINHO -1
#define FUNDO -2
/*============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabalho3.h"

#define BRANCO 255
#define PRETO 0
#define CAMINHO -1
#define FUNDO -2

/*============================================================================*/
/** Este arquivo transforma uma imagem de escala cinza em fundo == branco
 *  e labirinto == preto, acha o comeco desse labirinto, percorre e acha o
 * .caminho mais curto ate o fim */
/*============================================================================*/

/** parametros:
/// Imagem1C* img: de entrada uma imagem em escala de cinza. retorna o numero de
/// passos do caminho entre a entrada e a saída mais próxima.
/// Coordenada** caminho: de saida e um ponteiro para um vetor de coordenadas.

///  O vetor deve ser alocado dentro da funcao, e deve ter exatamente o numero
/// de posicoes retornado. Um caminho valido começa com x=0, termina comx=largura-1,
/// e tem a cada passo um vizinho do passo anterior. Uma coordenada e vizinha de outra se estiver
/// imediatamente acima, abaixo, a direita ou a esquerda (mas nao em diagonal!).*/

/**funcao que padroniza o que e preto==0 e branco==255.*/
void pretoBranco (Imagem1C* img)
{
    int i, j;

    //loop aninhado percorre matriz
    for(i=0; i<img->altura; i++)
    {
        for(j=0; j<img->largura; j++)
        {
            //valores abaixo de 79 na escala cinza cravamos em 0
            if(dados[i][j]>79)
                dados[i][j]==BRANCO;
            //valores acima de 79 cravamos em 255
            else
                dados[i][j]==PRETO;

        }
    }
    //salvaImagem1C(img, "aaaa.bmp");
}
/**funcao aloca matriz */
int** alocaMatriz(int nl, int nc)
{
    int **mat;
    int i;

    mat=(int**)malloc(nl*sizeof(int*));

    for(i=0;i<nl;i++)
        mat[i]=(int*)malloc(nc*sizeof(int));

    return(mat);
}
/** Essa funcao esta achando comeco do caminho que iremos percorrer
no labirinto*/
void inicializaMat(Imagem1C* img, int**mat, int nl, int nc)
{
    int i, j;

    for(i = 0; i < img->altura; i++)
        if(img->dados[i][0] == PRETO)
            mat[i][0] = 0;//inicio, custo 0

    for(i = 0; i < nl; i++)
        for(j = 0; j < nc; j++)
        {
            if(img->dados[i][j] == PRETO)
                mat[i][j] = CAMINHO;
            else
                mat[i][j] = FUNDO;
        }
}


void preencheMatrizCusto(Imagem1C* img, int** mat, Coordenada inicio)
{
    int i, j, k, novoX, novoY;
    int achou = 0, custo_atual = 0;
    int dx[4] = {0, 0, 1, -1};//desloca para as 4 posições adjacentes
    int dy[4] = {1, -1, 0, 0};

    while(!achou)
    {
        achou = 0;
        for(i = 0; i < img->altura; i++)
        {
            for(j = 0; j < img->largura; j++)
            {
                if(mat[i][j] == custo_atual)
                {
                    for(k = 0; k < 4; k++)
                    {
                       novoX += dx[i];
                       novoY += dy[i];
                       if
                    }
                }
            }
        }
    }

}
/** funcao mostra o caminho mais curto para o final do labirinto*/
int encontraCaminho (Imagem1C* img, Coordenada** caminho)
{
    Coordenada inicio;
    int **mat_custo;
    int i, j, tam;
    //alocar o vetor caminho da coordenada
    pretoBranco(img);
    //alocar o vetor caminho da coordenada
    *caminho=(Coordenada*)malloc(tam * sizeof(Coordenada));
    //p preencher: (*caminho)[i] = algo

    mat_custo = alocaMatriz(img->altura, img->largura);
    inicializaMat(img, mat_custo, img->altura, img->largura);

    preencheMatrizCusto(img, mat_custo, inicio);


    return 0;

}
///* imagem em escala de cinza e uma matriz que varia 0 a 255, do preto ao branco(bitmap)*/
