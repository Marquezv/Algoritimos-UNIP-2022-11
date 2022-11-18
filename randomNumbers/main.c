#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
// Quando alterar a quantidade de Listas alterar no metodo main

// Adicionar[quantidadeDeListas][TamanhoMaximoDoNome]
char numLists[4][100] = {
                        "numeros5000_decresente.txt",
                        "numeros100_crescente.txt", 
                        "numeros100_convexa.txt",
                        "numeros100_concava.txt" 
                        };


void selection_sort(int num[], int tam) {
    int operacaoSelection = 0;
      int i, j, min, aux;
      for (i = 0; i < (tam-1); i++) 
      {         

         min = i;
         for (j = (i+1); j < tam; j++) {
           if(num[j] < num[min]) 
            min = j;
            operacaoSelection += 1;
         }
         if (i != min) {
            aux = num[i];
            num[i] = num[min];
            num[min] = aux;
            operacaoSelection += 1;
         }
         // printf("%d", repeticaoSelection);
      }
      printf("Quantidade de operações - : %d", operacaoSelection);
}


void read_files(char arq[100], int volume){
    FILE *x;   
    char c;
    int i,op;    
    int qtd;
    int qtd_Volume = volume;
    
    if(volume > 0){
        qtd_Volume = qtd / volume;
    }


    x = fopen(arq,"r"); 
    for (c = getc(x); c != EOF; c = getc(x))
        if (c == '\n') 
            qtd = qtd + 1;
    fclose(x);

    int p[qtd]; 
    x = fopen(arq,"r");      
    rewind(x);
    

   
    while(x != NULL && !feof(x)){ 
          fscanf(x,"%d",&p[i]); 
          i++;
    }
   

    if(qtd_Volume <= 0){
        qtd_Volume = qtd;
    }

    fclose(x);  
    do{     
            // Chamar a Função/Algoritmo passando(int [], e tamanho == qtd_volume)
            selection_sort(p, qtd_Volume);
            printf("\n");
            break;
            
        system("clear");
    }while(op != 4);
}

int main () {
    // Alterar i < [quantidadeDeListas]
    for(int i = 0; i < 4; i++){
        printf("%s --- ", numLists[i]);
        read_files(numLists[i], i);
    }
}