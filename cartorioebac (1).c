#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsavel por cuidar das string

int registro ()
{
	setlocale(LC_ALL, "portuguese");
	
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf( "Digite o CPF  a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,", CPF: ");
	fprintf(file,cpf); //salvo valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", NOME: ");
	fclose (file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose (file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", SOBRENOME: ");
	fclose (file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose (file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", CARGO : ");
	fclose (file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose (file);
	
	system("pause");
	
}

int consulta()
{
   setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 
	
   char cpf[40];
   char conteudo[200];	
   
   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if (file == NULL)
   {
   printf("\nNão foi possivel abrir o arquivo, não localizado! \n\n"); //realizei modificação visual para ficar mais agradavel de ler
   }
   
   while(fgets(conteudo,200,file)!= NULL)
   {
   printf("\nEssas são as informações do usuário: ");
   printf("%s", conteudo);
   printf("\n\n");
   } 
   
   system("pause");
   
} 

int deletar()
{
	char cpf [40];
	
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	
	{
	printf ("O usuário não encontrado no sistema!.\n");
	
	system("pause");
	}
	else
	{
	fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora você pode remover o arquivo

    printf("Usuário deletado!\n");

    system("pause");
	}
}


int main() 
    {
    setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
    
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	system ("cls");	
	
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	printf("### Cartório da EBAC ### \n\n"); //Inicio do menu
	printf("Escolha a opção desejada do menu \n\n");
	printf("\t1 - Registrar nomes \n");
	printf("\t2 - Consultar nomes \n");
	printf("\t3 - Deletar nomes \n"); 
	printf("Opção: "); //Fim do menu
	
	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	system ("cls");
	
	switch(opcao)
	{
		case 1:
		registro();
		break;
		
		case 2 :
		consulta();
		break;
		
		case 3 :
		deletar();
		break;
		
		default:
		printf("Essa opção não está disponível!\n");
		system ("pause");
		break;
		
			
	    }
	
	}
}

