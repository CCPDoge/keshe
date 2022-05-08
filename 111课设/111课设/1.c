#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

int menu_out;
int menu_select()
{
	int c;
	scanf("%d", &c);	
	return c;
}

void FindNum()
{
	int i = 0;
	printf("丢失数字的等式为:\n3[]*6237=[]3*3564\n");
	for (i; i <= 9; i++)
		if (((30 + i) * 6237) == ((i * 10 + 3) * 3564))
		{
			printf("丢失的数字为:%d\n", i);
			printf("原本的等式为:\n3%d*6237=%d3*3564\n", i, i);
		}
}

void FindRoot()
{
	double a, b, c, disc, x1, x2, r, i;
	char t;
	printf("Please input three numbers:");
Loop:   scanf("%lf %lf %lf", &a, &b, &c);
		printf("The equation");
		if (fabs(a) <= 1e-6)
			printf("is not a quadratic\n");
		else
		{
			disc = b * b - 4 * a * c;
			if (fabs(disc) <= 1e-6)
				printf("has two equal roots:%8.4f\n", -b / (2 * a));
			else
				if (disc > 1e-6)
				{
					x1 = (-b + sqrt(disc)) / (2 * a);
					x2 = (-b - sqrt(disc)) / (2 * a);
					printf("has distinct real roots:%8.4f and %8.4f\n", x1, x2);
				}
				else
				{
					r = -b / (2 * a);
					i = sqrt(-disc) / (2 * a);
					printf("has complex roots:\n");
					printf("%8.4f+%8.4fi\n", r, i);
					printf("%8.4f-%8.4fi\n", r, i);
				}
		}
		printf("n 继续，其它键退出\n");
		t = getchar();
		if (getchar()=='n')
			goto Loop;
}

void Detective()
{
	int i = 31, sum = 0;
	int  a, b, c, d;
	printf("已知：甲：牌照三、四位相同;\n");
	printf("      乙：牌号为31XXXX;\n");
	printf("      丙：牌照五、六位相同;\n");
	printf("      丁：三~六位是一个整数的平方;\n");
	printf("由线索可得:\n");
	for (i; i < 100; i++)
	{	 
		a = (i * i) / 1000;
		b = ((i * i) / 100) % 10;
		c = ((i * i) / 10) % 10;
		d = (i * i) % 10;
		if (a == b && c == d) break;
	}
	printf("车牌号为%d\n", sum = 310000 + a * 1000 + b * 100 + c * 10 + d);
}

void Monkey()
{
	int n, i;
	n = 1;
	for (i = 2; i <= 10; i++)
	{
		n = (n + 1) * 2;
	}
	printf("原来一共有%d个桃子。\n", n);
}

void Print_Diamond(int lines)
{
	int i, j, k;
	for (i = 1; i <= lines; i++)
	{
		if (i % 2 == 0)
			printf("\n");
		else
		{
			for (j = 1; j <= ((lines - 1) / 2 - (i - 1) / 2); j++)
				printf(" ");
			for (k = 1; k <= i; k++)
				printf("*");
		}
	}
	for (i = 1; i <= (lines - 1); i++)
	{
		if (i % 2 == 0)
		{
			for (j = 1; j <= i / 2; j++)
				printf(" ");
			for (k = 1; k <= (lines - i); k++)
				printf("*");
		}
		else
			printf("\n");
	}
}

void Diamond()
{
	int lines;
	printf("Please input lines:");
	while(1)
	{
		scanf("%d", &lines);
		if ((lines % 2) == 0)
			printf("Please input an odd number:");
		else
		{
			Print_Diamond(lines);
			break;
		}
	}
}

void Calculator()
{
	FILE* in , * out ;
	int x, y, ret=0;
	char w;
	if ((in = fopen("express.txt", "r")) == NULL)
	{
		printf("CAN'T OPEN THE FILE!\n");
		exit(0);
	}
	if ((out = fopen("result.txt", "w")) == NULL)
	{
		printf("CAN'T OPEN THE FILE!\n");
		exit(0);
	}
	while (!feof(in))
	{
		fscanf(in,"%d%c%d", &x, &w, &y);
		switch (w)
		{
			case '+':		ret = x + y;		break;
			case '-':		ret = x - y;		break;
			case '*':		ret = x * y;		break;
			case '/':		ret = x / y;		break;
			default:		printf("输入错误，请重新输入！\n"); break;
		}
		fprintf(out,"%d%c%d=%d\n", x, w, y, ret);
	}
	fclose(in);
	fclose(out);
}

int main()
{
	int a[100] = {0};
	int i,j,n=0;
	char c;
	printf("输入z，开始运行功能，其它键退出\n");
	c = getchar();
	for (i = 0; c == 'z'; )
	{
Mm:	system("cls");
	printf("***************************\n");
	printf("************menu***********\n");
	printf("***************************\n");
	printf("       1.FindNum\n");
	printf("       2.FindRoot\n");
	printf("       3.Detective\n");
	printf("       4.Monkey\n");
	printf("       5.Diamond\n");
	printf("       6.Calculator\n");
	printf("       0.GoodBye!\n");
	printf("       Input 1-6,0:\n");
	printf("***************************\n");
	switch (j=menu_select())
			{
				case 1:
					system("cls");
					menu_out = 1;
					FindNum();
					printf("\n");
					break;

				case 2:
					system("cls");
					menu_out = 1;
					FindRoot();
					printf("\n");
					break;

				case 3:
					system("cls");
					menu_out = 1;
					Detective();
					printf("\n");
					break;

				case 4:
					system("cls");
					menu_out = 1;
					Monkey();
					printf("\n");
					break;

				case 5:
					system("cls");
					menu_out = 1;
					Diamond();
					printf("\n");
					break;

				case 6:
					system("cls");
					menu_out = 1;
					Calculator();
					printf("\n");
					break;

				case 0:
					system("cls");
					printf("GoodBye!");
					printf("\n");
					break;

				default:break;
			}
		a[i] = j;
		printf("z 继续，其它键退出\n");
		c = getchar();
		if (getchar() == 'z')
		{
			n++;
			i++;
			goto Mm;
		}
	}
	for (i = 0; i <= n; i++)
		printf("%d	", a[i]);
	return 0;
}