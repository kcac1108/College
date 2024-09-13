//KCC-Ativ04 - Menu Reciclavel
//KAUA CORDEIRO CAVALHEIRO 03/05/2023
/*O programa deve solicitar e carregar em um vetor, 20 numeros inteiros quaisquer, digitados aleatoriamente. 
Depois devera apresentar um menu reciclavel com as seguintes opcoes de apresentacao dos mesmos numeros:
1. apresentar todos os numeros digitados na ordem de entrada
2. apresentar todos os numeros digitados na ordem inversa de entrada
3. apenas os numeros multiplos de 3. 
4. apenas os numeros precedidos na entrada por um numero par
outra opcao qualquer, sair do programa	
*/

#include <stdio.h>
main()
{
	//declaracao das variaveis
	int i, opcao;
	int num[21]; //variavel para string
	
	//entrada dos 20 numeros
	printf("Digite 20 numeros inteiros aleatorios:\n"); 
	for(i=0;i<20; i++)
		{
		printf("digite %d numero: ", i+1);
		scanf("%d", &num[i]);
		}
	//menu reciclavel
	while(1)
		{
		printf("\nEscolha uma opcao:\n");
        printf("1. Apresentar todos os numeros digitados na ordem de entrada\n");
        printf("2. Apresentar todos os numeros digitados na ordem inversa de entrada\n");
        printf("3. Apresentar apenas os numeros multiplos de 3\n");
        printf("4. Apresentar apenas os numeros precedidos na entrada por um numero par\n");
        printf("digite outro numero para sair\n");
        printf("Opcao escolhida: ");
        scanf("%d", &opcao);
			
		//saida dos numeros de acordo com o menu	
		switch (opcao)
			{
			case 1:
				printf("\nNumeros digitados na ordem de entrada:\n");
                for (i = 0; i < 20; i++) 
              		printf("%d(%d)\t", num[i], i+1);
               	break;
            case 2:
               	printf("\nNumeros digitados na ordem inversa:\n");
               	for (i=19;i>=0;i--)
               		printf("%d(%d)\t", num[i], i+1);
               	break;
            case 3:
				printf("\nNumeros multiplos de 3:\n");
				for (i=0;i<20;i++)
					if (num[i] % 3 == 0) 
                        printf("%d(%d)\t", num[i], i+1);
                break;
            case 4:
                printf("\nNumeros precedidos por um numero par:\n");
                for(i=0;i<20;i++)
                	if(num[i-1] % 2 == 0)
                		printf("%d(%d)\t",num[i],i+1);
                break;
            default:
                printf("\nSaindo do programa.\n");
                return 0;         	
			}						
		}	
}