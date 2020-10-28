
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>




/*
 * THREADS = 4
 * 
 * 0 A 2 = CADA UMA CUIDA DO SCAN DE UMA ESTEIRA
 * 3 = ATUALIZA O DISPLAY
 *  
 * 
 * 
 * 
 */

int main(int argc, char** argv) {

   
    
    // CONTROLE PARA ATIVAÇÃO DA ESTEIRA
    bool esteira_1 = true;
    bool esteira_2 = true;
    bool esteira_3 = true;
     
    // CONTROLE PARA ENCREMENTAR CONTAGEM DA ESTEIRA
    bool inc_esteira_1 = false;
    bool inc_esteira_2 = false;
    bool inc_esteira_3 = false;
    
    // DELAY SIMULADO DO SCAN DO PRODUTO
    int delay_1;
    int delay_2;
    int delay_3;
    
    // CONTAGEM DE PRODUTOS POR ESTEIRA
    int itens_1=0;
    int itens_2=0;
    int itens_3=0;
    
    // TOTAL DE ITENS
    int k =0; 
    
    // SOMAS DO VETOR
    int vetor[1500];
    int pt1=0;
    int pt2=0;
    int pt3=0;
    long int total = 0;
    
    // ZERA VALOR
    for(int i=0;i<1500;i++){
        vetor[i] = 0;
    }
    
    
    
    // ENTARDA DE VALORES
    printf("Insira o delay para esteira 1: ");
    scanf("%i", &delay_1);
    printf("Insira o delay para esteira 2: ");
    scanf("%i", &delay_2);
    printf("Insira o delay para esteira 3: ");
    scanf("%i", &delay_3);
    printf(" valores: %d %d %d", delay_1, delay_2, delay_3);
      
    
     
    while(k < 1500){
                
                // SIMULAÇÃO DO SCAN NA ESTEIRA 1
                if(esteira_1){
                    usleep(delay_1);
                    inc_esteira_1 = true;
                }
                
                // SIMULAÇÃO DO SCAN NA ESTEIRA 2
                if(esteira_2){
                    usleep(delay_2);
                    inc_esteira_2 = true;
                }
                
                // SIMULAÇÃO DO SCAN NA ESTEIRA 3
                if(esteira_3){
                    usleep(delay_3);
                    inc_esteira_3 = true;
                }
                
                // ATUALIZAÇÃO DO DISPLAY
                if(true){
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n-----------------------------------------------------\n");
                    printf("\t ESTEIRA 1 || ESTEIRA 2 || ESTEIRA 3\n");
                    printf("\t    %d          %d          %d\n",itens_1,itens_2,itens_3);
                    printf("TOTAL= %d\n",itens_1+itens_2+itens_3 );
                    printf("-----------------------------------------------------\n");
                }
                
                // ATUALIZAÇÃO DA CONTAGEM DE ITENS
              
                if(inc_esteira_1){
                    itens_1++;
                    inc_esteira_1 = false;
                    vetor[k] = 2;
                    k++;
                }

                if(inc_esteira_2){

                    itens_2++;
                    inc_esteira_2 = false;
                    vetor[k] = 2;

                    k++;
                }

                if(inc_esteira_3 && omp_get_thread_num() == 2){

                    itens_3++;
                    inc_esteira_3 = false;
                    vetor[k] = 2;

                    k++;
                }
                
    }
   
    // DIVISÂO DO VETOR PARA CADA THREAD
    
        if(true){
            for(int m=0; m<500;m++){
                pt1 = pt1 + vetor[m];
            }
        }
                
        if(true){
            for(int n=500; n<1000;n++){
                pt2 = pt2 + vetor[n];
            }
        }
                
        if(true){
        for(int o=1000; o<1500;o++){
                pt3 = pt3 + vetor[o];
            }            
        }
        
         // BARREIRA PARA GARANTIR QUE TODOS AS THREADS CONCLUIRAM SUAS SOMAS
    
    
    total = pt1 + pt2 + pt3;
   
    
    
    printf("\nPESO TOTAL DOS ULTIMOS 1500 ITENS: %ld \n", total);
    
}

