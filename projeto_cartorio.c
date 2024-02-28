#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	
	//início criação de variáveis/strings (conjunto de variáveis)
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da criação de variáveis/strings (conjunto de variáveis)
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o W é de "escrever"
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}	

int consulta() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	//início criação de variáveis/strings (conjunto de variáveis)
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/strings (conjunto de variáveis)
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a strings
	
	FILE *file; //comando para abrir o arquivo e relacionar a ele
	file = fopen(cpf, "r"); //comando para abrir o arquivo e ler
	
	if(file == NULL) 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar() //Função responsável por deletar os usuários no sistema
{
	//início criação de variáveis/strings (conjunto de variáveis)
	char cpf[40];
	//final da criação de variáveis/strings (conjunto de variáveis)

	printf("Digite o CPF a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a strings
	
	remove(cpf); //comando que remove o arquivo criado relacionado ao dado pedido
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;	
		} //Fim da seleção
	}
}
