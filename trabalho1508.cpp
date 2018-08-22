#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MenuPrincipal();
void Entrada();
void Saida();
void Ordenacao();
void Busca();

#define Max 10

typedef struct _FichaOS{
        int num,servico;
        char data[11];
        char NomeClient[20];
        float valor;
        }FichaOS;
        
FichaOS OS[Max];
int opcao,op_ord,n,op_busca;

main()
{
      int fim=0;
      do
      {
         MenuPrincipal();      
         switch (opcao)
         {
             case 1:Entrada();
                    break;
             case 2:Saida();
                    break;
             case 3:Ordenacao();
                    break;
             case 4:Busca();
                     break;
             case 5:fim=1;
                    break;
             default: printf("Opcao invalida\n");
                      getch();
         }
      }while (!(fim));
      printf("Fim do programa");
      getch();
}

void MenuPrincipal()
{
     system("cls");
     printf("         M E N U   P R I N C I P A L\n");
     printf("\n1 - Entrada de Dados\n");
     printf("\n2 - Saida de Dados\n");
     printf("\n3 - Ordenacao\n");  
     printf("\n4 - Busca\n");        
     printf("\n5 - Sair\n");
     printf("\nEscolha uma das opcoes:");
     scanf("%d",&opcao);
}
void Entrada()
{
     int i;
     char x;
     system("cls");
     printf("           E N T R A D A  D E  D A D OS\n");     
     printf("Digite a quantidade de OS (maximo 10):");
     scanf("%d",&n);
     for (i=0;i<n;i++)
      {
          x=getchar();
          printf("Digite o nome do Cliente:");
          gets(OS[i].NomeClient);
          printf("Digite o numero da OS:");
          scanf("%d",&OS[i].num);
          printf("Digite a data da OS:");
          scanf("%s",OS[i].data);         
          printf("Digite o tipo de servico (1/2/3/4):");
          scanf("%d",&OS[i].servico);
          printf("Digite o valor da OS:");
          scanf("%f",&OS[i].valor);
      }    
}
void Saida()
{
     int i;
     system("cls");
     printf("         S A I D A  D E  D A D O S  -  L I S T A G E M\n");
     printf("\nNum.OS          data                  Clientes              Servico    Valor(R$)\n");
     for (i=0;i<n;i++)
          {    
             printf("%6d %18s %20s",OS[i].num,OS[i].data,OS[i].NomeClient);      
             switch (OS[i].servico)
             { 
                    case 1: printf("%20s","Revisao");
                            break;
                    case 2: printf("%20s","Troca de Oleo");
                            break;
                    case 3: printf("%20s","Reposicao de pecas");
                            break;
                    case 4: printf("%20s","Recall");
                            break;
             }         
             printf("%13.2f\n",OS[i].valor);      
             
          }  

     getch();
}


void Ordenacao()
{
      void MenuOrdenacao();
      void Crescente();
      void Decrescente();
      int fim_ord=0;
      do
      {
         MenuOrdenacao();      
         switch (op_ord)
         {
             case 1:Crescente();
                    fim_ord=1;
                    break;
             case 2:Decrescente();
                    fim_ord=1;
                    break;
             case 3:fim_ord=1;
                    break;
             default: printf("Opcao invalida\n");
                      getch();
         }
      }while (!(fim_ord));
}

void MenuOrdenacao()
{
     system("cls");
     printf("         M E N U   D E  O R D E N A C A O\n");
     printf("\n1 - Crescente\n");
     printf("\n2 - Decrescente\n");
     printf("\n3 - Sair\n");
     printf("\nEscolha uma das opcoes:");
     scanf("%d",&op_ord);
}
void Crescente()
{
     int i,j;
     FichaOS OSAux;
     for (i=0;i<n-1;i++)   
          for (j=i+1;j<n;j++)   
                if (OS[i].valor > OS[j].valor)
                {
                   OSAux = OS[i];
                   OS[i] = OS[j];
                   OS[j] = OSAux;
                }
     printf("\nDados Ordenados\n");
     getch();
}

void Decrescente()
{
     int i,j;
     FichaOS OSAux;
     for (i=0;i<n-1;i++)   
          for (j=i+1;j<n;j++)   
                if (OS[i].valor < OS[j].valor)
                {
                   OSAux = OS[i];
                   OS[i] = OS[j];
                   OS[j] = OSAux;
                }
     printf("\nDados Ordenados\n");
     getch();
 }
 void Busca()
 {
     void MenuBusca();
     void Sequencial();
     void Binaria();
     int fim_busca=0;
     do
     {
         MenuBusca();
         switch(op_busca)
         {
             
          case 1:Sequencial();
                    fim_busca=1;
                    break;
             case 2:Binaria();
                     Crescente();
                    fim_busca=1;
                    break;
             case 3:fim_busca=1;
                    break;
             default: printf("Opcao invalida\n");
                      getch();
         }
      }while (!(fim_busca));
        
 }
 void MenuBusca()
 {
     system("cls");
     printf("         M E N U   D E  BUSCA\n");
     printf("\n1 - Sequencial\n");
     printf("\n2 - Binaria\n");
     printf("\n3 - Sair\n");
     printf("\nEscolha uma das opcoes:");
     scanf("%d",&op_busca);
}
void Sequencial()
{
    int m,i;
    int x;
    int encontrou;
        printf("Digite o numero da Os:");
        scanf("%d",&x);
        i=0;
        encontrou=0;
        while((i<n)&(!encontrou))
            if(OS[i].num==x)
            {
                encontrou=1;
                m=i;
            }
            else
            i++;
            if(encontrou)
                printf("Valor da OS = %1.2f", OS[m].valor);
            else
                printf("Os não encontrada");
    getch();
}
void Binaria()
{
    int m,i,e,d;
    int x;
    int encontrou;
    e=0;
    d=n-1;
    encontrou=0;
    while((e<=d)&&(!encontrou))
    {
        m=(e+d)/2;
        if(OS[m].num==x)
            encontrou=1;
        else if(OS[m].num<x)
               e=m+1;
             else
             d=m-1;
    }
    if(encontrou)
        printf("O valor da Os = %1.2f",OS[m].valor);
    else
        printf("Os não encontrada");
getch();
}
