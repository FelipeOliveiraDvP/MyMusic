#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define DIM 5
int continua;

typedef struct{
	char nome[30];
	char genero[30];
	int nmr_integrantes,rank;	
}Banda;

//Prototipos das funçoes
int menu(void);
void preencher(Banda bandas[]);
void ranking(Banda bandas[]);
void genero(Banda bandas[]);
void nome(Banda bandas[]);

//Funçao Principal
int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"Portuguese");

	Banda bandas[DIM];

	do{
		system("cls||clear");
		continua = menu();
		
		switch(continua){
			case 1:
				preencher(bandas);
				break;
			case 2:
				ranking(bandas);
				break;
			case 3:
				genero(bandas);
				break;
			case 4:
				nome(bandas);
				break;
			case 0:
				printf("\nObrigado por ultilizar o My Music!\n\n");
				break;	
			default:
				printf("\nOpção Invalida!\n");					
		}
	}while(continua != 0);
	system("pause");
	return 0;
}
//Funçoes
int menu(void){ //  Menu Principal
	int op;
	printf("\t\tMy Music\n-----------------------------------------------\n");
	printf("\tBem vindo ao My Music!\n\nEscolha uma opção para continuar:\n\n");
	printf("[1] Nova Banda\n[2] Selecionar banda por Ranking\n[3] Selecionar Banda por Genero\n[4] Selecionar por nome\n[0] Sair\nOpcao: ");
	scanf("%d",&op);
		switch(op){
			case 1:
				return 1;
				break;
			case 2:
				return 2;
				break;
			case 3:
				return 3;
				break;
			case 4:
				return 4;
				break;
			default:
				return 0;				
		}
}

void preencher(Banda bandas[]){//Cadastra as informaçoes sobre as bandas
	
	int i;
	for(i=0;i<DIM;i++){
		fflush(stdin);
		system("cls||clear");
		printf("\t\tMy Music\n-----------------------------------------------\n");
		printf("Banda Nº %d\n\n",i+1);
	
		printf("Nome da Banda: ");
		scanf(" %s", bandas[i].nome);
		
		printf("Genero(tipo de musica): ");
		scanf(" %s", bandas[i].genero);
		
		printf("Numero de integrantes: ");
		scanf("%d",&bandas[i].nmr_integrantes);
		
		printf("Ranking(colocação) da Banda: ");
		scanf("%d",&bandas[i].rank);		
	}
	printf("\nAperte qualquer tecla para continuar...");
	getch();
	
}

void ranking(Banda bandas[]){ //Mostra a banda no ranking digitado pelo usuario
	int ranking,i;
	system("cls||clear");
	printf("\t\tMy Music\n-----------------------------------------------\n");
	printf("Digite um numero de 1 a 5 para descobrir qual banda se encontra no ranking: ");
	scanf("%d",&ranking);
		if(ranking > DIM)
			printf("\nNaõ ha bandas com esse ranking!\n\n");
		else{
			for(i=0;i<DIM;i++){
			if(bandas[i].rank == ranking)
				printf("\nNome da Banda: %s\nGenero: %s\n",bandas[i].nome,bandas[i].genero);		
			}
		}	
	printf("\nAperte qualquer tecla para continuar...");
	getch();
}

void genero(Banda bandas[]){//Mostra as bandas com o genero digitado pelo usuario
	char compara[17];
	int i,count=0;
	fflush(stdin);
	system("cls||clear");
	printf("\t\tMy Music\n-----------------------------------------------\n");
	printf("Digite um genero musical e veja as bandas nesse estilo: ");
	gets(compara);
		for(i=0;i<=DIM;i++){
			if(!(strcmp(compara,bandas[i].genero))){
				printf("\nNome da banda: %s\nRanking da Banda: %d\n",bandas[i].nome,bandas[i].rank);
				count++;
			}	
		}
		if(count == 0)
			printf("\nNenhuma banda com esse estilo foi encontrada\n");
	printf("\nAperte qualquer tecla para continuar...");
	getch();			
}

void nome(Banda bandas[]){//Mostra o genero e o ranking da banda digitada pelo usuario
	char compara[17];
	int i,count=0;
	fflush(stdin);
	system("cls||clear");
	printf("\t\tMy Music\n-----------------------------------------------\n");
	printf("Digite nome de uma Banda para descobrir seu genero e Ranking: ");
	gets(compara);
		for(i=0;i<=DIM;i++){
			if(!(strcmp(compara,bandas[i].nome))){
				printf("\nGenero: %s\nRanking da Banda: %d\n",bandas[i].genero,bandas[i].rank);
				count++;
			}
		}
		if(count == 0)
			printf("\nNenhuma banda com esse nome foi encontrada\n");
	printf("\nAperte qualquer tecla para continuar...");
	getch();			
}
