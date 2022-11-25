#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct contacts
{
    /* data */
    char nome[20];
    char sobrenome[50];
    long int numero;
    char email[50];

};

typedef struct contacts contacts;


void def(contacts *agenda);
void list(contacts *agenda);
void show(contacts *agenda);
void add(contacts *agenda);
void edit(contacts *agenda);
void exclude(contacts *agenda);

int main(){
    int option;
    contacts agenda[10];
    printf("Bem vindo a sua agenda telefonica: \n");
    def(agenda);
        do{
        
        printf("Escolha\n1 - Listar seus contatos \n2 - Ver um unico contato\n3 - Adicionar\n4 - Modificar um contato\n5 - Excluir contato\n6 - Sair\n");
        scanf("%d", &option);
            switch (option)
            {
            case 1:
                list(agenda);
                break;
            case 2:
                show(agenda);
                break;
            case 3:
                add(agenda);
                break;
            case 4:
                edit(agenda);
                break;
            case 5:
                exclude(agenda);
                break;
            case 6:
                puts("Obrigado por usar nosso programa");
                break;
            
            default:
                puts("Digite uma informação valida");
                break;
            }
        }while (option != 6);
    
}

void def( contacts *agenda){

    strcpy(agenda[0].nome, "samu");
    strcpy(agenda[0].sobrenome, "Saude");
    agenda[0].numero = 192;
    strcpy(agenda[0].email, "samu@gmail.com");
    
    strcpy(agenda[1].nome, "policia");
    strcpy(agenda[1].sobrenome, "segurança");
    agenda[1].numero = 190;
    strcpy(agenda[1].email, "policia@gmail.com");

    strcpy(agenda[2].nome, "bombeiros");
    strcpy(agenda[2].sobrenome, "incendio");
    agenda[2].numero = 191;
    strcpy(agenda[2].email, "bombeiro@gmail.com");
    
     for(size_t i=3; i < 10; i++){
       
        strcpy(agenda[i].nome, "");
        strcpy(agenda[i].sobrenome, "");
        agenda[i].numero = 0;
        strcpy(agenda[i].email, "");
    }

        
    
}


void list(contacts *agenda){
    puts("Aqui esta sua lista de contatos");
    for(size_t i=0; i < 10; i++){
        int is = strcmp(agenda[i].nome, "");
        if(!is){
            puts("Em branco");
            puts("");
            puts("");
            puts("");
        }
        else{
        printf("Nome: %s\t",agenda[i].nome );
        printf("Sobrenome: %s\t",agenda[i].sobrenome  );
        printf("Numero: %ld\t",agenda[i].numero );
        printf("Email: %s\t",agenda[i].email );
        puts("");
        puts("");
        puts("");
        }
    }
}

void show(contacts *agenda){
    int exist=0;
    char nome[20];
    puts("Qual contato voce quer ver?");
    scanf("%s",nome);
     for(size_t i=0; i < 10; i++){
        int is = strcmp(agenda[i].nome, nome);
        if(!is){
            printf("Nome: %s\t",agenda[i].nome );
            printf("Sobrenome: %s\t",agenda[i].sobrenome  );
            printf("Numero: %ld\t",agenda[i].numero );
            printf("Email: %s\t",agenda[i].email );
            exist=1;
        }
     }
     if(exist==0){
        puts("Não existe contato com esse nome");
     }
}

void add(contacts *agenda){
    for(size_t i=0; i < 10; i++){
     int is = strcmp(agenda[i].nome, "");
        if(!is){
            puts("digite o nome do contato: ");
            scanf("%s",agenda[i].nome);
            puts("digite o sobrenome do contato: ");
            scanf("%s",agenda[i].sobrenome);
            puts("digite o numero do contato: ");
            scanf("%ld",&agenda[i].numero);
            puts("digite o email do contato: ");
            scanf("%s",agenda[i].email);
            
            i=10;
        }
    }
}

void edit(contacts *agenda){
    puts("Qual contato voce deseja modificar");
     int exist=0;
    char nome[20];
    scanf("%s",nome);
     for(size_t i=0; i < 10; i++){
        int is = strcmp(agenda[i].nome, nome);
        if(!is){
            puts("digite o nome do contato: ");
            scanf("%s",agenda[i].nome);
            puts("digite o sobrenome do contato: ");
            scanf("%s",agenda[i].sobrenome);
            puts("digite o numero do contato: ");
            scanf("%ld",&agenda[i].numero);
            puts("digite o email do contato: ");
            scanf("%s",agenda[i].email);
            exist = 1;
        }
     }
    if (exist == 0){
        puts("Não existe contato com esse nome");

    }
    
    
}
void exclude(contacts *agenda){
    puts("Qual contato voce deseja excluir?");
    int exist=0;
    char nome[20];
    scanf("%s",nome);
     for(size_t i=0; i < 10; i++){
        int is = strcmp(agenda[i].nome, nome);
        if(!is){
        strcpy(agenda[i].nome, "");
        strcpy(agenda[i].sobrenome, "");
        agenda[i].numero = 0;
        strcpy(agenda[i].email, "");
        exist=1;
        }
     }
    if (exist == 0){
        puts("Não existe contato com esse nome");

    }
}


