#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()// Fun��o respons�vel por cadastrar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
    //In�cio de vari�veis/string
    char arquivo[40];  
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo [40];
    //Final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado:");//coletando informa��es do usu�rio
    scanf ("%s", cpf);//refere-se a string(armazenar informa��es)
    
    strcpy(arquivo, cpf);//Respons�vel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file= fopen(arquivo, "w");//cria o arquivo
    fprintf(file,cpf);//salva o valor da vari�vel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastado:");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta() 
{
	
    setlocale(LC_ALL, "Portuguese");	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n");
	}
    while(fgets(conteudo, 200, file) != NULL)
    {
	printf("\nEssas s�o as informa��es do usu�rio:");
	printf("%s", conteudo);
	printf ("\n\n");
    }
    
system("pause");

}

int deletar ()
{
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    
    printf("Digite o cpf do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    remove (cpf);
    
    FILE* file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Usu�rio n�o se encontra no sistema.\n");
    	system("pause");
	}
    
}
	
int main()
{
    int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	    
    	setlocale(LC_ALL, "Portuguese");
	    printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
	    printf("Escolha a op��o desejada do menu: \n\n");
	    printf("\t1 Registrar Nomes\n");
	    printf("\t2 Consultar Nomes\n");
	    printf("\t3 Deletar Nomes\n"); // Fim do menu
	
	    scanf("%d",&opcao);// Armazenando a escolha do usu�rio
	
	    system("cls");// Respons�vel por limpar a tela
	    
	    switch(opcao)//Inicio da sele��o de menu
	    {
	    	case 1:
		    registro();//chamada de fun��es
	    	break;
	    	
	    	case 2:
	    	consulta();
	    	break;
	    	
	    	case 3:
	    	deletar();
    		break;
    		
    		default:
    		printf("Essa op��o n�o est� dispon�vel\n");
    		system("pause");
    		break;			
		}//fim de sele��o
		
    }
}