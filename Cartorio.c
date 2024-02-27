#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registro() //Fun��o respons�vel pelo cadastro de usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo, o "w" significa escrever no arquivo
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa para alterar
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa para alterar
	fprintf(file, nome);
	fclose(file); //Fecha o arquivo

	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa para alterar
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa para alterar
	fprintf(file,sobrenome);
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa para alterar
	fprintf(file, ",");
	fclose(file); //Fehcar o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" significa para alterar
	fprintf(file, cargo);
	fclose(file); //Fecha o arquivo
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //Scaneia o CPF digitado pelo usu�rio
	
	FILE *file;
	file = fopen(cpf, "r"); //Abrir o arquivo e ler os dados localizados na vari�vel CPF
	
	if(file == NULL) //Si n�o achar o CPF no arquivo informar n�o localizado
	{
		printf("CPF n�o localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Busca as informa��es no arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e "r" significa ler o arquivo
	
	if(file == NULL) //Caso n�o ache o CPF digitado pelo usu�rio
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //La�o de repeti��o
	{
	
		system("cls"); // "cls" respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\t### Cart�rio da E.B.A.C ###\n\n"); //In�cio do menu
		printf("Escola a op��o desejada abaixo:\n\n");
		printf("\t1 | Registro de nomes\n");
		printf("\t2 | Consultar nomes\n");
		printf("\t3 | Deletar nomes\n\n"); 
		printf("\t4 | Sair do sistema\n\n");
		printf("Opc�o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando esoclha do usu�rio
		
		system("cls"); // "cls" respons�vel por limpar a tela
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("A op��o selecionada n�o existe!\n");
			system("pause");
			break;
		} //fim da sele��o
	}
}
