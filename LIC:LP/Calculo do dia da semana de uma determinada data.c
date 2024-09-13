//KCC - ativ06Extra - Calculo do dia da semana de uma determinada data
//Kaua Cordeiro Cavalheiro - 26/05/2023

#include <stdio.h>

int zeller(int dia, int mes, int ano); //funcao baseada no algoritmo de zeller para calculo do dia da semana
int fDataValida(int d, int m, int a);
int fAnoBissexto(int a);

int main() 
{
	//declaracao das variaveis
    int dia, mes, ano;

	printf("\t----Ativ-06Extra----\n\n");//titulo 

	do //loop com saida dia == 0
	{
		//entrada da data para consulta
		printf("Digite a data (dd/mm/aaaa): ");
    	scanf("%d/%d/%d", &dia, &mes, &ano);
    	
    	fDataValida(dia, mes, ano);
    	
		if(dia == 0)//saida do loop
			{
			printf("Saindo do programa...\n");
			break;
			}
    
    	int DiaDaSemana = zeller(dia, mes, ano);//atribui a funcao a uma variavel

		//define se o dia foi ou sera'
		if(ano<2023)
			printf("O dia foi: ");
		else
			printf("O dia sera': ");

		//switch para atribuir o valor da funcao zeller para um dia da semana
    	switch (DiaDaSemana) 
		{
    	    case 0:
    	        printf("Sabado\n\n");
    	        break;
    	    case 1:
    	        printf("Domingo\n\n");
    	        break;
    	    case 2:
    	        printf("Segunda-feira\n\n");
    	        break;
    	    case 3:
    	        printf("Terça-feira\n\n");
    	        break;
    	    case 4:
    	        printf("Quarta-feira\n\n");
    	        break;
    	    case 5:
    	        printf("Quinta-feira\n\n");
    	        break;
    	    case 6:
    	        printf("Sexta-feira\n\n");
    	        break;
    	    default:
    	        printf("Erro: dia da semana invalido\n\n");
    	        break;
    	}
	}while(dia!=0);
}


int fAnoBissexto(int a) //calculo ano bissexto
{ 
	return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

int fDataValida(int d, int m, int a)//verifica a validade da data
{	
	if(a < 1600)
		{
		printf("ano invalido\n\n");
		return 0; 
		}
	
	if (m <= 0 || m > 12)
		{
		printf("mes invalido\n\n");
		return 0;
		}	
	
	int ultimodia = 31;	
	if (m == 2)
		{
		if (fAnoBissexto (a) == 1)
			ultimodia = 29;
		else 
			ultimodia = 28;
		}
			
	if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
		ultimodia = 30;
	
	if (d < 1 || d > ultimodia)
		{
		printf("dia invalido\n\n");
		return 0;
		}
		
	return 1;			
}
    
int zeller(int dia, int mes, int ano) 
{
    if (mes < 3) //janeiro e fevereiro viram os meses 13 e 14, respectivamente, do ano anterior
		{
        mes += 12;
        ano--;
    	}
    
	//calculos do algoritmo de zeller
    int seculo = ano / 100;
    int anoDoSeculo = ano % 100;
    
    int zellerValue = dia + ((13 * (mes + 1)) / 5) + anoDoSeculo + (anoDoSeculo / 4) + (seculo / 4) - (2 * seculo);
    
	//atribuicao de valores de 0 a 6
    int DiaDaSemana = zellerValue % 7;
    if (DiaDaSemana < 0) {
        DiaDaSemana += 7;
    }
    
    return DiaDaSemana;
}    