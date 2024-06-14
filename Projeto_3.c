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
/* struct que retorna na funcao
typedef struct
{
    int x;
    int y;
} Coordenada;

/* struct de entrada em escala cinza
typedef struct
{
	unsigned long largura;
	unsigned long altura;
	unsigned char** dados; /* Matriz de dados.
} Imagem1C;
*/
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
            if(dados[i][j]>100)
                dados[i][j]==PRETO;
            //valores acima de 79 cravamos em 255
            else
                dados[i][j]==BRANCO;

        }
    }
}
/**funcao aloca matriz */
int** alocaMatriz()
{
    for(i=0;i<nl;i++)
        mat[i]=

    return(mat);
}

void preencheMatrizCusto(Imagem1C* img, int** mat, Coordenada inicio)
{

}

int encontraCaminho (Imagem1C* img, Coordenada** caminho)
{
    Coordenada inicio;
    int **mat_custo;
    int i, j, tam;
    //alocar o vetor caminho da coordenada
    *caminho=(Coordenada**)malloc(tam*sizeof(Coordenada*));
}
///* imagem em escala de cinza e uma matriz que varia 0 a 255, do preto ao branco(bitmap)*/
