/******************************
* Yaniv Hajaj
* 316411578
* course number:818312001
* teaching assistant:Gerson Or
* ex 1
*******************************/
#define _CTR_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("\"%%%%%% hello \\/\\/orld %%%%%% \"%%s\"\n");
	//declare 4 varibles
	int num1=0;
	int num2=0;
	int num3 = 0;
	int num4 = 0;
	printf("Enter 2 numbers\n");
	scanf("%d%d", &num1,&num2);
	printf("The sum of %d and %d is: %d\n", num1, num2, num1 + num2);
	printf("The sub of %d and %d is: %d\n", num1, num2, num1 - num2);
	printf("The mul of %d and %d is: %d\n", num1, num2, num1 * num2);
	printf("The div of %d and %d is: %d\n", num1, num2, num1/num2);
	printf("The mod of %d and %d is: %d\n", num1, num2, num1%num2);	
	printf("Enter four numbers as password\n");
	scanf("%d%d%d%d", &num1,&num2,&num3,&num4);
	printf("Your password is: %c%c%c%c\n", num1, num2, num3,  num4);
	printf("Enter number with 4 digits\n");
	scanf("%d", &num1);

	/*
	*declare a varible that keeps the sum.
	*than take the last digit of the number with % 
	* multiply this digit by the 10^n
	*sum up the digits in order to reversed the original number
	*/
	int holder=0;
	holder = (num1%10)*1000;
	num1 = num1/10;
	holder += ((num1 % 10) * 100);
	num1 = num1 / 10;
	holder += ((num1 % 10) * 10);
	num1 = num1 / 10;
	holder += num1;
	printf("%d\n",holder);
	printf("Enter phone number\n");
	scanf("%d", &num1);
	printf("Internal number: 0-%d\n",num1);
	printf("Universal number: +972-%d",num1);











}