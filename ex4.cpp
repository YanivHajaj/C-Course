/******************************
* Yaniv Hajaj
* 316411578
* course number:818312001
* teaching assistant:Gerson Or
* ex 4
*******************************/

#include <stdio.h>
#define _CTR_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define STR_ARRAY_MAX_SIZE 30
#define Exit 1
#define NoExit 2
int compareStrings(const char* stringPTR1,const char* stringPTR2,int countSameLetter);
int stringLength(char* stringPTR,int counter);
void DiffersInNChars(char* s1, char* s2, int n);

int main()
{
	int diffrenceNumber = 0;
	char wantToExit='n';
	const char* ExitString = "exit";
	char stringArray1[STR_ARRAY_MAX_SIZE];
	char stringArray2[STR_ARRAY_MAX_SIZE];
	while (wantToExit != 'y')
	{
		printf("do you want to exit (y/n)?\n");
		scanf(" %c", &wantToExit);//take a letter from the user
		if (wantToExit == 'y')
			return 0;
		printf("please insert the first string (to exit please insert the word exit):\n");
		scanf(" %s", &stringArray1);//take a string from the user
		if ((compareStrings(stringArray1, ExitString, 0) == 4)&&(stringLength(stringArray1,0)==4))//if the string is the same to'exit' string
		{
		return 0;
	    }
		printf("please insert the second string (to exit please insert the word exit):\n");
		scanf(" %s", &stringArray2);//take another string from the user
		if ((compareStrings(stringArray2, ExitString, 0)==4) && (stringLength(stringArray2, 0) == 4))	//if the string is the same to'exit' string
		return 0;
		printf("please insert difference number:\n");
		scanf("%d", &diffrenceNumber);
		if (stringLength(stringArray2, 0) >= stringLength(stringArray1, 0) && stringLength(stringArray2, 0) < diffrenceNumber)
		{
			return 0;
		}
		if (stringLength(stringArray2, 0) < stringLength(stringArray1, 0) && stringLength(stringArray1, 0) < diffrenceNumber)
		{
			return 0;
		}
		DiffersInNChars(stringArray1, stringArray2, diffrenceNumber);
	}
}
//the function get 2 strings and return the amount of charecter which is the same
int compareStrings(const char* stringPTR1,const char* stringPTR2,int countSameLetter)
{
	if (*stringPTR1 == '\0'|| *stringPTR2 == '\0')
		return countSameLetter;
	if (*stringPTR1 == *stringPTR2)
	{
		return compareStrings(stringPTR1 + 1, stringPTR2 + 1, ++countSameLetter);
	}
	return compareStrings(stringPTR1 + 1, stringPTR2 + 1, countSameLetter);
}
//return the length of the string
int stringLength(char* stringPTR,int counter)
{
	if (*stringPTR=='\0')
	return counter;
	return stringLength(stringPTR+1, ++counter);
}
//print yes or no
void DiffersInNChars(char* s1, char* s2, int n)
{
	if (*s1 == '\0' || *s2 == '\0')
	{
		if (n == 0)
			printf("\"yes\"\n");
		if (n < 0)
			printf("\"no\"\n");
		if (n > 0)
			printf("\"no\"\n");
	}
	else
	{
		if (*s1 == *s2)
			DiffersInNChars(s1 + 1, s2 + 1, n);
		else
			DiffersInNChars(s1 + 1, s2 + 1, n-1);
	}
}

