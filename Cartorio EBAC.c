#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
 int registro() // Função responsável por cadastrar os usuários
 {
 //inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
 //final da criação    
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando cpf do usuário
	scanf("%s", cpf); //"%s" é para digitar uma string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa de escrever (novo arquivo)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//a é para retomar ao arquivo w que foi criado
	fprintf(file,",");//vírgula para separar
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

 }

 int consulta()
 {
	printf("Você escolheu consultar os nomes!\n");
	system("pause");
    
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL) //caso não achar o arquivo(NULL=Vazio)
    {
      printf("Não foi possível encontrar o arquivo!\n");
    }
    while(fgets(conteudo, 200, file) != NULL)
    { 
      printf("\nEssas são as informações do usuário");
      printf("%s", conteudo);
      printf("\n\n");
    }
 }

 int deletar()
 {
	printf("Você escolheu deletar nomes!\n");
	system("pause");	
    
    char cpf[40];
    
    printf("Digite o CPF que deseja deletar:\n");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file == fopen(cpf,"r");
    
    printf("CPF deletado com sucesso\n"); //mensagem
    
    if(file == NULL) //caso não achar o arquivo (NULL=Vazio)
    {
        printf("O usuário não se encontra no sistema!\n"); //mensagem de erro caso o usuário escolha uma opção que não existe
        system("pause"); 
    }
 }


	
 int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
        printf("\t4 - Sair do programa\n\n");
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //limpar a tela
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro(); // chamando funções que foram criadas
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
            
            case 4:
            printf("Obrigado por utilizar o programa!\n");
            return 0; //sair do sistema
            break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}