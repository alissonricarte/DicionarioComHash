#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../includes/verificacao.h"
#include "../includes/dicionario.h"


int main(){
     dicionario* meu_dicionario = inicializar(4); 

   

    exibir_dic(meu_dicionario);


    return 0;
}