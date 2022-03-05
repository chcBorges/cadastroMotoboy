#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limpaTela system("cls");
#define pausaTela system("pause");

typedef struct moto{
    char *modelo, *placa, *cor;

    int ano;
} MOTO;

typedef struct motoboy{
    char *nome, *telefone, *endereco;

    MOTO motoca;
} MOTOBOY;

void menu(int *opcao, int qtdEntregadores){
    menuPrincipal:
    do{
        limpaTela

    printf("<=====-MENU PRINCIPAL-=====>\n\t");
        printf("0 - SAIR\n\t");
        printf("1 - MOTOBOYS\n\t");
        printf("2 - EMPRESAS\n\n");
        printf("Digite uma opcao valida: ");

        scanf("%d", opcao);
    } while((*opcao < 0) || (*opcao > 2));

    if(*opcao == 0){
        return;
    }
    else if(*opcao == 1){
        int qtdMenu = 1;

        do{
            limpaTela

          //printf("<=====-MENU PRINCIPAL-=====>\n");
            printf("<=====-MENU MOTOBOYS-======>\n\t");     //1
            printf("0 - VOLTAR\n\t");
            printf("1 - ADICIONAR MOTOBOY\n");              //11

            if(qtdEntregadores){
                printf("\t2 - REMOVER MOTOBOY\n");          //12
                printf("\t3 - VER DADOS DO MOTOBOY\n");       //13

                qtdMenu = 3;
            }
            printf("\nDigite uma opcao valida: ");

            scanf("%d", opcao);
        } while((*opcao < 0) || (*opcao > qtdMenu));

        if(*opcao == 0){
            goto menuPrincipal;
        }
        else if(*opcao == 1){
            *opcao = 11;
        }
        else if(*opcao == 2){
            *opcao = 12;
        }
        else if(*opcao == 3){
            *opcao = 13;
        }
    }
    else if(*opcao == 2){
        do{
            limpaTela

          //printf("<=====-MENU PRINCIPAL-=====>\n");
            printf("<=====-MENU EMPRESAS-======>\n\t");     //2
            printf("0 - VOLTAR\n\t");
            printf("1 - ADICIONAR EMPRESA\n\n");            //21
            printf("Digite uma opcao valida: ");

            scanf("%d", opcao);
        } while((*opcao < 0) || (*opcao > 1));

        if(*opcao == 0){
            goto menuPrincipal;
        }
        else if(*opcao == 1){
            *opcao = 21;
        }
    }
}

void adicionarMotoboy(MOTOBOY *entregadores, int *qtdEntregadores){
    char buffer[100];

    limpaTela

  //printf("<=====-MENU PRINCIPAL-=====>\n\t");
  //printf("<=-MENU ADICIONAR MOTOBOY-=>\n\t");
    printf("<====-DADOS DO CONDUTOR-===>\n\t");

    printf("Nome: ");
    scanf(" %[^\n]", buffer);

    entregadores[*qtdEntregadores].nome = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(entregadores[*qtdEntregadores].nome, buffer);

    printf("\tTelefone: ");
    scanf(" %[^\n]", buffer);

    entregadores[*qtdEntregadores].telefone = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(entregadores[*qtdEntregadores].telefone, buffer);

    printf("\tEndereco: ");
    scanf(" %[^\n]", buffer);

    entregadores[*qtdEntregadores].endereco = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(entregadores[*qtdEntregadores].endereco, buffer);
    
  //printf("<=====-MENU PRINCIPAL-=====>\n\t");
  //printf("<=-MENU ADICIONAR MOTOBOY-=>\n\t");
  //printf("<====-DADOS DO CONDUTOR-===>\n\t");
    printf("<====-DADOS DO VEICULO-====>\n\t");

    printf("Modelo da moto: ");
    scanf(" %[^\n]", buffer);

    entregadores[*qtdEntregadores].motoca.modelo = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(entregadores[*qtdEntregadores].motoca.modelo, buffer);

    printf("\tAno: ");
    scanf(" %[^\n]", buffer);

    entregadores[*qtdEntregadores].motoca.ano = atoi(buffer);

    printf("\tCor: ");
    scanf(" %[^\n]", buffer);

    entregadores[*qtdEntregadores].motoca.cor = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(entregadores[*qtdEntregadores].motoca.cor, buffer);

    printf("\tPlaca: ");
    scanf(" %[^\n]", buffer);

    entregadores[*qtdEntregadores].motoca.placa = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(entregadores[*qtdEntregadores].motoca.placa, buffer);

    limpaTela

  //printf("<=====-MENU PRINCIPAL-=====>\n\t");
  //printf("<======-VER MOTOBOYS-======>");
    printf("<=======-MOTOBOY #%2d-======>\n", *qtdEntregadores+1);
    printf("<====-DADOS DO CONDUTOR-===>\n");
    printf("NOME: %s\n", entregadores[*qtdEntregadores].nome);
    printf("TELEFONE: %s\n", entregadores[*qtdEntregadores].telefone);
    printf("ENDERECO: %s\n\n", entregadores[*qtdEntregadores].endereco);
    printf("<====-DADOS DO VEICULO-====>\n");
    printf("MODELO DA MOTO: %s\n", entregadores[*qtdEntregadores].motoca.modelo);
    printf("ANO DA MOTO: %d\n", entregadores[*qtdEntregadores].motoca.ano);
    printf("COR DA MOTO: %s\n", entregadores[*qtdEntregadores].motoca.cor);
    printf("PLACA DA MOTO: %s\n\n", entregadores[*qtdEntregadores].motoca.placa);

    printf("Motoboy adicionado com sucesso!\n\n");

    *qtdEntregadores += 1;

    pausaTela

    return;
}

void verMotoboy(MOTOBOY *entregadores, int qtdEntregadores){
    int opcao;

    do{
        do{
            limpaTela

          //printf("<=====-MENU PRINCIPAL-=====>\n");
            printf("<======-VER MOTOBOY");
            if(qtdEntregadores > 1){
                printf("S-======>\n");
            }
            else{
                printf("-=======>\n");
            }

          //printf("<=====-MENU PRINCIPAL-=====>\n");
          //printf("<======-VER MOTOBOYS-======>\n");
            printf("<=======-VOLTAR - 0-=======>\n");

            for(int i = 0; i <= qtdEntregadores; ++i){
                  //printf("<=====-MENU PRINCIPAL-=====>\n");
                  //printf("<======-VER MOTOBOYS-======>\n");
                    printf("<=======-MOTOBOY #%2d-======>\n", i);
                    printf("NOME: %s\n", entregadores[i].nome);
            }

            printf("\nDigite o numero de um motoboy: ");
            scanf("%d", &opcao);

            limpaTela

            printf("Opcao digitada: %d\n\n", opcao);

            pausaTela
        } while((opcao < 0) || (opcao > qtdEntregadores));

        if(opcao){
            opcao--;

            limpaTela

          //printf("<=====-MENU PRINCIPAL-=====>\n\t");
          //printf("<======-VER MOTOBOYS-======>");
            printf("<=======-MOTOBOY #%2d-======>\n", opcao+1);
            printf("<====-DADOS DO CONDUTOR-===>\n");
            printf("NOME: %s\n", entregadores[opcao].nome);
            printf("TELEFONE: %s\n", entregadores[opcao].telefone);
            printf("ENDERECO: %s\n\n", entregadores[opcao].endereco);
            printf("<====-DADOS DO VEICULO-====>\n");
            printf("MODELO DA MOTO: %s\n", entregadores[opcao].motoca.modelo);
            printf("ANO DA MOTO: %d\n", entregadores[opcao].motoca.ano);
            printf("COR DA MOTO: %s\n", entregadores[opcao].motoca.cor);
            printf("PLACA DA MOTO: %s\n\n", entregadores[opcao].motoca.placa);

            pausaTela

            continue;
        }
    } while(opcao);
}

int main(){
    int opcao, qtdEntregadores = 0;

    MOTOBOY entregadores[15];

    do{
        menu(&opcao, qtdEntregadores);

        limpaTela

        printf("Opcao digitada: %d\n\n", opcao);

        pausaTela
        limpaTela

        if(opcao == 0){
            break;
        }
        else if(opcao == 11){
            adicionarMotoboy(entregadores, &qtdEntregadores);
        }
        else if(opcao == 13){
            verMotoboy(entregadores, qtdEntregadores);
        }
    } while(opcao != 0);

    pausaTela

    return 0;
}