#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> ///biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro() // Fun��o respons�vel por cadastrar os usu�rios
{
//inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
//final da cria��o    
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando cpf do usu�rio
	scanf("%s", cpf); //"%s" para digitar uma string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa de escrever (novo arquivo)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//a para retomar ao arquivo w que foi criado
	fprintf(file,",");//v�rgula para separar
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
	printf("Voc� escolheu consultar os nomes!\n");
	system("pause");
    
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL) //caso n�o achar o arquivo(NULL=Vazio)
    {
      printf("N�o foi poss�vel encontrar o arquivo!\n");
    }
    while(fgets(conteudo, 200, file) != NULL)
    { 
      printf("\nEssas s�o as informa��es do usu�rio");
      printf("%s", conteudo);
      printf("\n\n");
    }
     system("pause");
     fclose(file);
}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
	system("pause");	
    
    char cpf[40];
    
    printf("Digite o CPF que deseja deletar:\n");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file == fopen(cpf,"r");
    
    system("pause");
    
    printf("CPF deletado com sucesso\n"); //mensagem
    
    if(file == NULL) //caso n�o achar o arquivo (NULL=Vazio)
    {
        printf("O usu�rio n�o se encontra no sistema!\n"); //mensagem de erro caso o usu�rio escolha uma op��o que n�o existe
         system("pause");
    }
    fclose(file);
}


	
int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\n");
	printf("Digite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //strcmp = compara��o de strings
	
	if(comparacao == 0)//caso usu�rio for diferente retrna 1 no lugar de 0
	{
		system("cls");
		for(laco=1;laco=1;)
		{
	
			system("cls"); //limpar a tela
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
				
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
	        printf("\t4 - Sair do programa\n\n");
			printf("Op��o: ");//fim do menu
					
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
			
			system("cls"); //limpar a tela
		
			switch(opcao) //inicio da sele��o
			{
				case 1:
				registro(); // chamando fun��es que foram criadas
				break;
				
				case 2:
				consulta(); // chamando fun��es que foram criadas
				break;
			
				case 3:
				deletar(); // chamando fun��es que foram criadas
				break;
	            
	            case 4:
	            printf("Obrigado por utilizar o programa!\n");
	            return 0; //sair do sistema
	            break;
			
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
			} //fim da sele��o
		}
	}
	else
		printf("Senha incorreta!");
}
