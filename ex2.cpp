/******************************
* Yaniv Hajaj
* 316411578
* course number:818312001
* teaching assistant:Gerson Or
* ex 1
*******************************/

#define _CTR_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
void choice_one(long int phone);
void choice_two(int parameter);
void choice_three(int num1,int num2);
void choice_four(int A, int B, int C);
#define LARGE 1
#define EVENPHONE 1
#define SPECIAL 1
#define VARIED 1

int main()
{
	
	char firstN,lastN;
	printf("Hello, what is the first letter of your name?\n");
	/*
	*assuming the user insert char type varible and the char is a letter.
	*if the char is lowercase letter i will change it to uppercase.
	*/
	scanf("%c\n", &firstN);
	scanf("%c", &lastN);
	if (firstN >= 'a' && firstN <= 'z')
		firstN -= 32;
	if (lastN >= 'a' && lastN <= 'z')
		lastN -= 32;
	printf("Hello %c. %c, welcome to our menu!\n", firstN, lastN);
	printf("Choose 1 for phone, 2 for David, 3 for Mersenne, 4 for equation, -1 for exit\n");
	int choose;
	//take number that represent the choose of the user. and do it repeatedly untli insert -1.
	do
	{
		scanf("%d", &choose);
		if (choose == 1)
		{
			long int phone = 0;
			printf("Enter phone number (9 digits)\n");
			//if the number start with 0 it less than 9 digit(less than 100,000,000) so we need to ask the number again
			do
				scanf("%ld", &phone);
			while (phone < 100000000);
			choice_one(phone);
		}
		if (choose == 2)
		{
			int parameter = 0;
			printf("Enter size number:\n");
			do
				scanf("%d", &parameter);
			//check if the parameter is within the range 6<parameter<78
			while (parameter < 7 || parameter>77 || parameter % 2 == 0);
			choice_two(parameter);
		}
		if (choose == 3)
		{
			int right = 0, left = 0;
			printf("Enter two numbers:\n");
			do
				scanf("%d%d", &right, &left);
			//check if the numbers are positive
			while (left < 0 || right < 0);
			//check which one of the numberd is bigger in order to determine the range
			if (right < left)
				choice_three(right, left);
			else
				choice_three(left, right);

		}
		if (choose == 4)
		{
			int A, B, C, holder;
			printf("Enter three numbers:\n");
			scanf("%d%d%d", &A, &B, &C);
			//print the equation in the right way.
			holder = A * -1;
			if (A < -1)
				printf("-%dx^2 ", holder);
			if (A == -1)
				printf("-x^2 ");
			if ((A > 1))
				printf("%dx^2 ", A);
			if (A == 1)
				printf("x^2 ");
			holder = B * -1;
			if (B < -1 && A != 0)
				printf("- %dx ", holder);
			if (B < -1&&A==0)
				printf("-%dx ", holder);
			if ((B == -1) && (A == 0))
				printf("-x ");
			if (B == -1 && (A != 0))
				printf("- x ");
			if ((B > 1) && (A == 0))
				printf("%dx ", B);
			if ((B == 1) && (A == 0))
				printf("x ");
			if (B == 1 && (A != 0))
				printf("+ x ");
			if (B > 1 && (A != 0))
				printf("+ %dx ", B);
			holder = C * -1;
			if ((C < 0) && ((A != 0) || (B != 0)))
				printf("- %d ", holder);
			if ((C < 0) && ((A == 0) && (B == 0)))
				printf("-%d ", holder);
			if ((C > 0) && ((A != 0) || (B != 0)))
				printf("+ %d ", C);
			if ((C > 0) && ((A == 0) && (B == 0)))
				printf("%d ", C);

			//check the cases in which A=0.
			//i dont want to enter the function choice_four with A=0 when i already know what is the sulotion
			float linearPolinom;
			if ((A == 0))
			{
				if (B == 0)
				{
					if ((C == 0))
						//0 0 0
					{
						printf("0 = 0\n");
						printf("Infinite solutions!\n");
					}
					if ((C != 0))
						//0 0 C
					{
						printf("= 0\n");
						printf("No solution!\n");
					}
				}
				else
					if (C == 0)
						//0 B 0
					{
						printf("= 0\n");
						printf("x1 = 0.000\n");
					}
					else
						//0 B C
					{
						linearPolinom = (float)-C / B;
						printf("= 0\n");
						printf("x1 = %0.3f\n", linearPolinom);
					}
			}
			else
				//A!=0
				choice_four(A, B, C);
		}
		if(choose<=4&&choose>=1)
			printf("Choose 1 for phone, 2 for David, 3 for Mersenne, 4 for equation, -1 for exit\n");
	}
	while (choose != -1);
	printf("Thank you, %c. %c, have a nice day!\n", firstN, lastN);
}

void choice_one(long int phone)
{
	//each d represent the the number of time the digit show in the phone number.
	int d0 = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, d7 = 0, d8 = 0, d9 = 0;
	int isEven = 0, isSpecial = 0, isVaried = 0, isLarge = 0, digit = 0, sum = 0, counterEven = 0;
	//check if the phone number is even
	if (phone % 2 == 0)
	{
		isEven = EVENPHONE;
		printf("The number is even\n");
	}
	else
		printf("The number is odd\n");

	/*
	*disassemble the digits and take the sum of them
	*d represent the digit. it count wheater a digit is shown more than twise.
	*counterEven count even digits appearance
	* sum add the digits togheter
	*/
	for (int i = 1; i <= 9; i++)
	{
		digit = phone % 10;
		phone /= 10;
		switch (digit)
		{
		case 0:d0++;
			break;
		case 1:d1++;
			break;
		case 2:d2++;
			break;
		case 3:d3++;
			break;
		case 4:d4++;
			break;
		case 5:d5++;
			break;
		case 6:d6++;
			break;
		case 7:d7++;
			break;
		case 8:d8++;
			break;
		case 9:d9++;
			break;
		}
		if (digit % 2 == 0)
			counterEven++;
		sum = sum + digit;
	}

	if (sum > 40)
	{
		printf("The number is large\n");
		isLarge = LARGE;
	}
	if (sum < 30)
		printf("The number is small\n");
	if (sum >= 30 && sum <= 40)
		printf("The number is medium\n");
	if (counterEven <= 2 || counterEven >= 7)
	{
		printf("The number is special\n");
		isSpecial = SPECIAL;
	}
	else
		printf("The number is not special\n");
	//a digit show 2 or less times inside the number
	if (d0 <= 2 && d1 <= 2 && d2 <= 2 && d3 <= 2 && d4 <= 2 && d5 <= 2 && d6 <= 2 && d7 <= 2 && d8 <= 2 && d9 <= 2)
	{
		isVaried = VARIED;
		printf("The number is varied\n");
    }
	else
		printf("The number is not varied\n");
	if (isVaried && isSpecial && isEven && isLarge)
		printf("The number is amazing!\n");
}
void choice_two(int parameter)
{
	//holder keeps the parmeter. help to run the lopp 3 times (with +-2)on different parametrs. 
	int holder;
	
	/*
	* the big loop run from -2 to 2 (3 times). each time with the parameter(+-2)
	* the second loop run on the rows from 1-9.
	* the switch helps to know the row number and print the right char.
	* for instancerow 1/9 are the same so it will print the same row.
	* the loops inside the switch allocate the right char in order to create the shape
	*/
	for (int j = -2; j <= 2; j=j+2)
	{
		holder = parameter + j;
		for (int i = 1; i <= 9; i++)
		{
			switch (i)
			{
			case 1:
			case 9:
				for (int k = 1; k <= (holder * 2) - 1; k++)
				{
					if (holder == k)
						printf("O");
					else
						printf("-");
				}
				break;
			case 2:
			case 8:
				for (int k = 1; k <= (holder * 2) - 1; k++)
				{
					if ((holder == k - 1) || (holder == k + 1))
						printf("O");
					else
						printf("-");
				}
				break;
			case 3:
			case 7:
				for (int k = 1; k <= (holder * 2) - 1; k++)
				{
					printf("O");
				}
				break;
			case 4:
			case 6:
				for (int k = 1; k <= (holder * 2) - 1; k++)
				{
					if ((k == 2) || (k == ((holder * 2) - 2)))
						printf("O");
					else
						printf("-");
				}
				break;
			case 5:
				for (int k = 1; k <= (holder * 2) - 1; k++)
				{
					if ((k == 3) || (k == ((holder * 2) - 3)))
						printf("O");
					else
						printf("-");
				}
				break;
			}
		printf("\n");
		}
		printf("\n");
	}
	  
}
void choice_three(int left,int right)
{
	//numFloat keeps the number in float type, numInteger keep the number in int type
	float numFloat=(float)left;
	int numInteger;
	int flag = 0;

	/*
	* devide the number(integer and float) by 2 each time.
	* than cheack if integer(casting to float) is smaller than the integer itself devided by 2.
	* exit whan the vlue is 1
	* for example: (int)(9/2 = 4) != (float)(9.000/2 = 4.500) 
	*/
	for (int i = left; i <= right; i++)
	{
		numFloat = (float)(i + 1);
		numInteger = i + 1;
		while(numFloat==(float)numInteger&&numFloat!=1)
		{
			numFloat /= 2;
			numInteger /= 2;
		}
		if (numFloat == (float)numInteger && (i != 0))
		{
			printf("%d\n", i);
			flag++;
		}
	}
	if(flag==0)
		printf("None\n");

}
//A is not 0
void choice_four(int A, int B, int C)
{
	printf("= 0\n");
    double x1, x2, Real, Im, determinant;
    determinant = (pow(B, 2) - ((double)A*(double)C*4));
	//check if determinent is >=0
    if (determinant >= 0)
	{
		x1 = ((-B + sqrt(determinant)) / ((double)A * 2));
		x2 = ((-B - sqrt(determinant)) / ((double)A * 2));
		// x1=x2 so print only x1
		if (x1 == x2)
		{
			if(x1==-0.000)
				printf("x1 = 0.000\n");
			else
			    printf("x1 = %0.3f\n", x1);
		}
		else
			// x1<x2 or x2<x1 so print only the biger first
		{
			if (x1 > x2)
			{
				if (x1 == -0.000 || x2 == -0.000)
				{
					if (x1 == -0.000)
					{
						printf("x1 = 0.000\n");
						printf("x2 = %0.3f\n", x2);
					}
					if (x2 == -0.000)
					{
						printf("x1 = %0.3f\n", x1);
						printf("x2 = 0.000\n");
					}

				}
				else 
				{
					printf("x1 = %0.3f\n", x1);
					printf("x2 = %0.3f\n", x2);
				}
			}
			else //x2>x1
			{
				if (x1 == -0.000 || x2 == -0.000)
				{
					if (x2 == -0.000)
					{
						printf("x1 = 0.000\n");
						printf("x2 = %0.3f\n", x1);
					}
					if (x1 == -0.000)
					{
						printf("x1 = %0.3f\n", x2);
						printf("x2 = 0.000\n");
					}

				}
				else
				{
					printf("x1 = %0.3f\n", x2);
					printf("x2 = %0.3f\n", x1);
				}
			}
		}
	}
	// determinent is <0
	else
	  {
		 Im = (sqrt(-1 * determinant));
		 Im =Im/((double)A*2);
	     Real = (float)-B / (2 * A);
		 //if the real part of the number is 0 (bi)
		 if (Real == 0)
		 {
			 //b is not 1 or -1
			 if((Im != 1 )&& (Im != -1))
			 {
				 printf("x1 = %0.3fi\n", Im);
				 Im = Im * -1;
				 printf("x2 = %0.3fi\n", Im);
			 }
			 //just i
			 if ((Im == 1)|| (Im == -1))
			 {
				 printf("x1 = i\n");
				 printf("x2 = -i\n");
			 }

		 }
		 //number is (a+bi)
		 else
		 {
			 //Im is 1 so print only i (a+i) or Im is -1 so print only -i (a-i)
			 if (Im == 1|| Im == -1)
			 {
				 printf("x1 = %0.3f + i\n", Real);
				 printf("x2 = %0.3f - i\n", Real);
			 }
			 if ((Im > 0)&& (Im != 1))
			 {
				 printf("x1 = %0.3f + %0.3fi\n", Real, Im);
				 printf("x2 = %0.3f - %0.3fi\n", Real, Im);
			 }
			 if ((Im < 0 )&& (Im != -1))
			 {
				 //IM<0, turn IM into positive and print the biger first (+)
				 Im = Im * -1;
				 printf("x1 = %0.3f + %0.3fi\n", Real, Im);
				 printf("x2 = %0.3f - %0.3fi\n", Real, Im);
			 }
		 }
	  }

	  
	
}

	



	


