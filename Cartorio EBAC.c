#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> ///biblioteca de alocações de texto por região

int registro()
{
     printf("Você escolheu o registro de nomes!\n");
	 system("pause");
}
int consulta()
{
      printf("Você escolheu consultar nomes!\n") ;
	  system("pause");
}
int deletar()
{
       printf("Você escolheu deletar nomes!\n") ;
	   system("pause");
}
       
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls");
        
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenamento a escolha do usuário
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;	

			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("essa opção não está disponivel!\n");
			system("pause");
			break;
		}
	}
}
    