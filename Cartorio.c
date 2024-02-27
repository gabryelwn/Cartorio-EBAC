#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registro() //Função responsável pelo cadastro de usuários no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo, o "w" significa escrever no arquivo
	fprintf(file,cpf); //Salva o valor da variável
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
	scanf("%s", cpf); //Scaneia o CPF digitado pelo usuário
	
	FILE *file;
	file = fopen(cpf, "r"); //Abrir o arquivo e ler os dados localizados na variável CPF
	
	if(file == NULL) //Si não achar o CPF no arquivo informar não localizado
	{
		printf("CPF não localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Busca as informações no arquivo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e "r" significa ler o arquivo
	
	if(file == NULL) //Caso não ache o CPF digitado pelo usuário
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //Laço de repetição
	{
	
		system("cls"); // "cls" responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("\t### Cartório da E.B.A.C ###\n\n"); //Início do menu
		printf("Escola a opção desejada abaixo:\n\n");
		printf("\t1 | Registro de nomes\n");
		printf("\t2 | Consultar nomes\n");
		printf("\t3 | Deletar nomes\n\n"); 
		printf("\t4 | Sair do sistema\n\n");
		printf("Opcão: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando esoclha do usuário
		
		system("cls"); // "cls" responsável por limpar a tela
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("A opção selecionada não existe!\n");
			system("pause");
			break;
		} //fim da seleção
	}
}
