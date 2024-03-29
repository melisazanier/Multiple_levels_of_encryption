
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



char text[100];
char matrice[130][130];
int point[130][130];

void step1Inversare(char text[]);
void step2Interschimbare(char text[]);
void step3Shiftare(char text[]);
void initializareMatrice(char text[]);
void printCharAsBinary(char c);

void step1Inversare(char text[])
{

	char aux;
	int i = 0, j = strlen(text)-1;
	while ((i <j))
	{
		aux = text[i];
		text[i] = text[j];
		text[j] = aux;
		i++;
		j--;
	}
	printf("Textul dupa primul pas este: %s", text);
	printf("\n");
	step2Interschimbare(text);
}

void step2Interschimbare(char text[])
{
	int x=-1, y=0,count=0;
	char aux;
	while (x != y) {
		x = rand() % strlen(text);
		y = rand() % strlen(text);
		//printf("%d\n", x);
		//printf("%d\n", y);
		aux = text[x];
		text[x] = text[y];
		text[y] = aux;
		count++;
	}
	printf("Textul dupa al doilea pas este: %s", text);
	printf("\nS-a realizat de %d de ori functia random ", count);
	printf("\n");
	step3Shiftare(text);
}

void step3Shiftare(char text[])
{
	int i;
	for (i = 0; i <= strlen(text) - 1; i++)
	{
		if (isupper(text[i]))
		{
			text[i] = text[i] + 5;
		}
		else
     	if (islower(text[i]))
			{
				text[i] = text[i] - 5;
			}
		else
			{
				text[i] = text[i] + 2;
			}
	}
	printf("Textul dupa al treilea pas este: %s", text);
	printf("\n");


	initializareMatrice(text);
}

void initializareMatrice(char text[])
{
	int linie = 0, coloana = 0,a,b;

	matrice[linie][coloana] = text[0];

	while (linie != strlen(text) )
	{
		linie++;
	    coloana = coloana + 2 ;


		matrice[linie][coloana] = text[linie];
	}

	printf("Textul dupa al patrulea pas este: \n");
	for (a = 0; a < linie; a++)
	{
		for (b = 0; b < coloana; b++) {

			if (matrice[a][b] == 0) {
				matrice[a][b] = 'Nul' + (rand() % 128);
				printf("%c ", matrice[a][b]);
			}
			else
				printf("%c ", matrice[a][b]);

		}
		printf("\n");
	}

	for (a = 0; a < linie; a++)
	{
		for (b = 0; b < coloana; b++)

			printCharAsBinary(matrice[a][b]);


		printf("\n");
	}
}

void printCharAsBinary(char c) {
	int i;
	for (i = 0; i < 8; i++) {
		printf("%d", (c >> i) & 0x1);
	}
}


int main()
{
	printf("Introduceti cuvantul pe care dotiti sa-l incriptati: ");
	scanf("%[^\n]s", &text);
	step1Inversare(text);


    return 0;
}

