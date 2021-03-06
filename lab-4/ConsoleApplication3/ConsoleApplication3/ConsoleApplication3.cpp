#include "stdafx.h"

#include <stdio.h>
#include <locale>
#include <cstdio>

#define ENG 26

void encrypt(int n, int a)
{
	FILE *fp1, *fp2;
	fopen_s(&fp1, "input.txt", "r");
	fopen_s(&fp2, "output.txt", "w");
	int flag;
	char c, temp;
	c = getc(fp1);
	while (!feof(fp1))
	{
		flag = 0;
		if (c >= 'A' && c <= 'Z')
		{
			temp = ((c - 'A') * a + n) % ENG;
			c = 'A' + temp;

			if (c > 'Z') c = 'A' + (c - 'Z') - 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'a' && c <= 'z')
		{
			temp = ((c - 'a') * a + n) % ENG;
			c = 'a' + temp;

			if (c > 'z') c = 'a' + (c - 'z') - 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf(fp2, "%c", c);
		c = getc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
}


void decipher(int n, int a)
{
	FILE *fp1, *fp2;
	fopen_s(&fp1, "input.txt", "r");
	fopen_s(&fp2, "output.txt", "w");
	int flag;
	char c, temp;
	c = getc(fp1);
	int i = 0, keyFlag = true;

	while (keyFlag) {
		if (((a * 1 / i) % ENG) == 1) {
			keyFlag = false;
			i++;
		}
	}
	while (!feof(fp1))
	{
		flag = 0;
		if (c >= 'A' && c <= 'Z')
		{	
			temp = (i * (c - 'A') + ENG - n));
			c = 'A' + temp;

			if (c < 'A') c = 'Z' - ('A' - c) + 1;
			fprintf(fp2, "%c", c);

			flag = 1;
		}
		if (c >= 'a' && c <= 'z')	
		{
			temp = (i * (c - 'a') + ENG - n)) % ENG;
			c = 'a' + temp;
			if (c < 'a') c = 'z' - ('a' - c) + 1;
			fprintf(fp2, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf(fp2, "%c", c);
		c = getc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, a;
	printf("Шифрем только английский текст!!!!!\n ------------------------------------------------ \nВозможные значения a: 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23 и 25 \nВведите а:");
	scanf_s("%d", &a);
	getchar();
	printf("Введите натуральное n: ");
	scanf_s("%d", &n);
	getchar();
	if (n < 1) return 0;
	printf("Чтобы зашифровать текст введите a, расшифровать b: ");
	char c;
	scanf_s("%c", &c, 1);
	if (c == 'a') encrypt(n, a);
	if (c == 'b') decipher(n, a);
	system("PAUSE");
	return 0;
}