/*============================================================================*/
/* ICSF13 - 2024-1 - TRABALHO 1                                               */
/*----------------------------------------------------------------------------*/
/* Yasmin Lis M G                                                             */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#include "../pacote_t1/trabalho1.h"

unsigned int definePontoDeAcesso (int n_antenas)
{

    int i, j, antena;
    float menor_distancia=FLT_MAX, distancia, maior_distancia=0.0;

    /* ° Note que a distancia entre uma antena i e outra antena j é igual à distancia entre j e i,
         (i+j=j+i) Nao repetir as mesmas comparações como na tabela.
       ° vai retornar o identificador da antena selecionada como sendo o ponto de acesso,
        e a distancia entre o ponto de acesso e a antena, ou seja dois valores em um só.
       ° Prescisa tirar a raiz desse valor com sqrt*/
    for(i=0;i<n_antenas;i++)
    {
        for(j=0;j<n_antenas;j++)
        {
            if(i!=j)//para não comparar mais de uma vez.
            {
                distancia = sqrtf(((pegaX(i)-pegaX(j))*(pegaX(i)-pegaX(j)))+((pegaY(i)-pegaY(j))*(pegaY(i)-pegaY(j))));// formula do calculo distancia euclidiana
                /*sqrtf para raiz quadrada e multiplicaar a cada duas vezes
                para elevar ao quadradro(comparacao das antenas atravez das coordenadas);*/

                if(distancia > maior_distancia)//conferir
                {
                    maior_distancia=distancia;
                }
                /*laço mais interno tem a formula euclidiana e logo a
                seguir a comparacao do qual tem maior distancia*/
            }
        }

        if(maior_distancia < menor_distancia)
        {
            menor_distancia=maior_distancia;
            antena=i;//(identificar a antena)
        }//no laço mais externo se tem a comparação de todos maiores qual e o menor.

            maior_distancia=0.0;//inicializar para 'limpar' as ultimas coodernadas a cada nova comparacao com outra antena.
    }

    int id=((unsigned int)antena<<24);

    int dist_arredondada=((unsigned int)(menor_distancia+0.5));

    unsigned int resposta=(id|dist_arredondada);
    /*de acordo com um indiano no you tube e para fazer desse modo o a operação bit a bit*/

    return (resposta);
}
