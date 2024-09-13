//KCC - ativ06 - Calculo de Quantidade de Dias Entre Duas Datas
//Kaua Cordeiro Cavalheiro - 26/05/2023

#include <stdio.h>
int fAnoBissexto(int a);
int fQtdBissextos(int ano1, int ano2);
int fDataValida(int d, int m, int a);
int fDiasInicioAno(int d, int m, int a);
int fDiasFimAno(int d, int m, int a);

main()
{
	//declaracao das variaveis
	int diaInicial, mesInicial, anoInicial; 
    int diaFinal, mesFinal, anoFinal;
    int qtdDiasInicial, qtdDiasFinal;
    int qtdDiasTotais;
	
	printf("\t----Ativ-06----\n\n");
	
	do {
		//entrada da data inicial
        printf("Digite a data inicial (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &diaInicial, &mesInicial, &anoInicial);
        
        if(diaInicial == 0)//saida do loop
		{
			printf("Programa encerrado.\n");
			break;   
		}
		
		fDataValida(diaInicial, mesInicial, anoInicial);//teste da data inicial
		
		//entrada da data final
		printf("Digite a data final (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &diaFinal, &mesFinal, &anoFinal);
        
        fDataValida(diaFinal, mesFinal, anoFinal);//teste da data final
        
        //testa se o ano final ? menor que o ano inicial
    	if (anoInicial > anoFinal || (anoInicial == anoFinal && mesInicial > mesFinal) || (anoInicial == anoFinal && mesInicial == mesFinal && diaInicial > diaFinal))
            {
			printf("A data inicial deve ser anterior ? data final.\n");
            continue;
			}
		
		//calculos
		int qtdBissextos = fQtdBissextos(anoInicial, anoFinal);//atribui a funcao para qtd de dias bissextos
		qtdDiasFinal = fDiasFimAno(diaInicial, mesInicial, anoInicial);//calculo dos dias do ano inicial (da data ate o fim desse ano)
		qtdDiasInicial = fDiasInicioAno(diaFinal, mesFinal, anoFinal);//calculo dos dias do ano final (do comeco desse ano ate a data)
			
		//calculo final dos dias	
		qtdDiasTotais = (anoFinal - (anoInicial + 1))*365;
		qtdDiasTotais = qtdDiasTotais + qtdBissextos + qtdDiasFinal + qtdDiasInicial;
		
		if(anoInicial = anoFinal)
			qtdDiasTotais--;
        
        printf("Dias entre as datas: %d\n\n", qtdDiasTotais);
        printf("------------------------------------------------\n\n");
		
	
	}while (diaInicial != 0);
	
}

int fAnoBissexto(int a) //calculo ano bissexto
{ 
	return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

int fQtdBissextos(int ano1, int ano2) 
{
    int qtdBissextos = 0;
    int i;
    
    for (i = ano1 + 1; i < ano2; i++) {
        if (fAnoBissexto(i))
            qtdBissextos++;
    }
    
    return qtdBissextos;
}

int fDiasInicioAno(int d, int m, int a) //funcao pra calculo de dias desde o inicio do ano
{
    int dias = d;
    int mes;

    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (mes = 1; mes < m; mes++) 
		{
        dias += diasPorMes[mes - 1]; // "dias += diasPorMes" equivalente a "dias = dias + dias por mes"
        if (mes == 2 && fAnoBissexto(a))
        dias++;
    	}

    return dias;
}

int fDiasFimAno(int d, int m, int a) //funcao pra calculo de dias ate o fim do ano
{
	int diasFim = 365; //dias totais do ano 

    if (fAnoBissexto(a)) 
    diasFim++;
	
	return diasFim - fDiasInicioAno(d, m, a);
}

int fDataValida(int d, int m, int a)
{	
	if(a < 1600 || a > 3000)
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