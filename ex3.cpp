/******************************
* Yaniv Hajaj
* 316411578
* course number:818312001
* teaching assistant:Gerson Or
* ex 3
*******************************/
#include <stdio.h>
#include <math.h>
#define _CTR_SECURE_NO_WARNINGS
#define MAX_SIZE 30
#define MIN_SIZE 5
#define copIsThere 1
#define ThiefIsThere 2
#define noOnehere 3
#define inCorner 1
#define inMargin 1
#define copsWon 1
#define thiefWon 2
#define WHorsesWON 1
#define BHorsesWON 2
#define Blocked 1
#define NotBlocked 2
#define WantToPlay 1
#define DontWantToPlay 2
#define StillPlaying 1
#define gameOver 2

#pragma warning(disable:4996)
void PrintGameBoard(int position[6][2], char GameTable[MAX_SIZE][MAX_SIZE], int rows, int colomns,int copCounter);
int PrepareBoard(int position[6][2],char GameTable[MAX_SIZE][MAX_SIZE],int rows, int colomns);
void ourApp();
void printNames(int exitflag);
int getRows();
int getColumns(int row);
int game1(int r, int c);
void arrangeArrayPosition(int position[6][2],int copCounter);
int IsSomebodyThere(int position[6][2], int copCounter,int moveToRow, int moveToColumn);
void game2();
int isHorseBlocked(char board3x3[3][3], int MoveFromX, int MoveFromy);
void printHorsesBoard(char board3x3[3][3]);
void checkWin(int winner);

int main()
{
	ourApp();
	return 0;
}
void ourApp()
{
	int rows=0, columns=0,winner=0, ExitFlag = WantToPlay;
	char WanToPlay;
	printNames(ExitFlag);
	printf("Let's choose the size:\n");
	rows = getRows();
	columns = getColumns(rows);
	printf("Do you want to play [y/n]?\n");
	scanf(" %c",&WanToPlay);
	while (WanToPlay == 'y')  //while the player press yes start the games and than ask if want to play again
	{
		winner=game1(rows, columns);
		checkWin(winner);
		game2();
		printf("Do you want to play [y/n]?\n");
		scanf(" %c", &WanToPlay);
	} 
		ExitFlag = DontWantToPlay;
		printNames(ExitFlag);
}
void printNames(int exitflag)
{
	static char firstName[10];
	static char lastName[10];

	if (exitflag == WantToPlay) 
	{
		scanf(" %s", firstName);
		scanf(" %s", lastName);
		printf("Hello %s %s, welcome to our app!\n", firstName, lastName); 
	}
	if (exitflag == DontWantToPlay)  //if the the player doesnt want to play
	{
		printf("Bye, %s %s.\n", firstName, lastName);
	}
}
int getRows()
{
	int row;
	scanf("%d",&row);
	if (row < MIN_SIZE)
		row = MIN_SIZE;
	if (row > MAX_SIZE)
		row = MAX_SIZE;
	return row;
}
int getColumns(int row)
{
	int column=0;
	scanf("%d", &column);
	if (column < MIN_SIZE)
		column = MIN_SIZE;
	if (column > MAX_SIZE)
		column = MAX_SIZE;
	if (column == -1)
		column = row;
	return column;
}
int game1(int rows, int colomns)
{
	int copCounter, IsInCorners, IsInMargin = 0, countMoves=0;
	int moveFromX = 0, moveFromY = 0, moveToX = 0, moveToY = 0, NearestCop = 0;
	double minNormatL=0, NormatL=0;
	char GameTable[MAX_SIZE][MAX_SIZE];//array need fixed value to start with so i choose the Maxsize
	int position[6][2];//keep the position of the cops and the thief(thief location at row 1)
	for (int i = 0; i < 6; i++) //initial array with -1
	{
		for (int j = 0; j < 2; j++)
			position[i][j] = -1;
	}

	copCounter=PrepareBoard(position, GameTable, rows, colomns);
	printf("Well, Let's play! \n");
	printf("Initial states:\n");
	PrintGameBoard(position, GameTable, rows, colomns, copCounter);

	//special case
	if ((copCounter == 1) && ((position[0][5] + position[1][5] + position[0][0] + position[0][1]) % 2 == 0))
	{
			return thiefWon;
	}
	while(countMoves<15)
	{
		arrangeArrayPosition(position, copCounter);
		printf("Cops:\n");
		//this loop prints the possible moves
		for (int i = 0; i < copCounter; i++)
		{
			IsInCorners = 0;
			IsInMargin = 0;
			//check up left corner and print
			if ((position[i][0] == 0) && (position[i][1] == 0))
			{
				if (IsSomebodyThere(position, copCounter, 1, 0) != copIsThere)
					printf("[0,0] -> [1,0]\n");
				if (IsSomebodyThere(position, copCounter, 0, 1) != copIsThere)
					printf("[0,0] -> [0,1]\n");
				IsInCorners = inCorner;
			}
			//check bottom left corner and print
			if ((position[i][0] == rows) && (position[i][1] == 0))
			{
				if (IsSomebodyThere(position, copCounter, (rows - 1), 0) != copIsThere)
					printf("[%d,0] -> [%d,0]\n", rows, rows - 1);
				if (IsSomebodyThere(position, copCounter, rows, 1) != copIsThere)
					printf("[%d,0] -> [%d,1]\n", rows, rows);
				IsInCorners = inCorner;
			}
			//check up right corner and print
			if ((position[i][0] == 0) && (position[i][1] == colomns))
			{
				if (IsSomebodyThere(position, copCounter, 1, colomns) != copIsThere)
					printf("[0,%d] -> [1,%d]\n", colomns, colomns);
				if (IsSomebodyThere(position, copCounter, 0, colomns - 1) != copIsThere)
					printf("[0,%d] -> [0,%d]\n", colomns, colomns - 1);
				IsInCorners = inCorner;
			}
			//check bottom right corner and print
			if ((position[i][0] == rows) && (position[i][1] == colomns))
			{
				if (IsSomebodyThere(position, copCounter, (rows - 1), colomns) != copIsThere)
					printf("[%d,%d] -> [%d,%d]\n", rows, colomns, rows - 1, colomns);
				if (IsSomebodyThere(position, copCounter, rows, colomns - 1) != copIsThere)
					printf("[%d,%d] -> [%d,%d]\n", rows, colomns, rows, colomns - 1);
				IsInCorners = inCorner;
			}
			//the cop movment is not from one of the corners
			if (IsInCorners != inCorner)
			{
				if ((position[i][0] != rows-1) && (IsSomebodyThere(position, copCounter, position[i][0] + 1, position[i][1]) != copIsThere))
					printf("[%d,%d] -> [%d,%d]\n", position[i][0], position[i][1], position[i][0] + 1, position[i][1]);//can move down
				if ((position[i][0] != 0) && (IsSomebodyThere(position, copCounter, position[i][0] - 1, position[i][1]) != copIsThere))
					printf("[%d,%d] -> [%d,%d]\n", position[i][0], position[i][1], position[i][0] - 1, position[i][1]);//can move up
				if ((position[i][1] != colomns-1) && (IsSomebodyThere(position, copCounter, position[i][0], position[i][1] + 1) != copIsThere))
					printf("[%d,%d] -> [%d,%d]\n", position[i][0], position[i][1], position[i][0], position[i][1] + 1);//can move right
				if ((position[i][1] != 0) && (IsSomebodyThere(position, copCounter, position[i][0], position[i][1] - 1) != copIsThere))
					printf("[%d,%d] -> [%d,%d]\n", position[i][0], position[i][1], position[i][0], position[i][1] - 1);//can move left
			}
		}
		
		scanf("%d",&moveFromX);
		scanf("%d",&moveFromY);
		scanf("%d",&moveToX);
		scanf("%d",&moveToY);
		if (IsSomebodyThere(position, copCounter, moveToX, moveToY) == ThiefIsThere)//if cop move to thief position
		{
			GameTable[moveFromX][moveFromY] = '-';
			GameTable[moveToX][moveToY] = 'C';
			PrintGameBoard(position, GameTable, rows, colomns, copCounter);
			return copsWon;//end of game***
		}

		GameTable[moveFromX][moveFromY] = '-';//move cop to the right position
		GameTable[moveToX][moveToY] = 'C';
		for (int i = 0; i < copCounter; i++)//check which of the cups in array position need to move and move him
		{
			if (position[i][0]==moveFromX && position[i][1] == moveFromY)
			{
				position[i][0] = moveToX;
				position[i][1] = moveToY;
			}
		}
		PrintGameBoard(position, GameTable, rows, colomns, copCounter);
		printf("Rob:\n");
		 
			//move thief
		minNormatL = (double)pow((double)position[0][0] - (double)position[5][0], 2) + (double)pow((double)position[0][1] - (double)position[5][1], 2);
		minNormatL = (double)sqrt(minNormatL);
		for (int i = 1; i < copCounter; i++)//check which cop is nearest
		{
			NormatL = (double)pow((double)position[i][0] - (double)position[5][0], 2) + (double)pow((double)position[i][1] - (double)position[5][1], 2);
			NormatL = (double)sqrt((double)NormatL);
			if (NormatL < minNormatL)
			{
				minNormatL = NormatL;
				NearestCop = i;
			}
		}
		
		if (position[NearestCop][0] < position[5][0])//closet cop is in row above
			if (position[5][0] == rows - 1 || IsSomebodyThere(position, copCounter, position[5][0] + 1, position[5][1]) == copIsThere)//if thief has no place to go
			{
				PrintGameBoard(position, GameTable, rows, colomns, copCounter); //thief turn is over,cop benith or end of board
			}
			else //thief can move down
			{
				GameTable[position[5][0]][position[5][1]] = '-';
				position[5][0] = position[5][0] + 1;
				GameTable[position[5][0]][position[5][1]] = 'R';
				PrintGameBoard(position, GameTable, rows, colomns, copCounter);
			}

		if (position[NearestCop][0] > position[5][0])//closet cop is in row benith
			if (position[5][0] == 0 || IsSomebodyThere(position, copCounter, position[5][0] - 1, position[5][1]) == copIsThere)//if thief has no place to go
			{
				PrintGameBoard(position, GameTable, rows, colomns, copCounter); //thief turn is over,cop above or end of board
			}
			else //thief can move up
			{
				GameTable[position[5][0]][position[5][1]] = '-';
				position[5][0] = position[5][0] - 1;
				GameTable[position[5][0]][position[5][1]] = 'R';
				PrintGameBoard(position, GameTable, rows, colomns, copCounter);
			}

		if (position[NearestCop][0] == position[5][0])//closest cop is in the same row
			if (position[NearestCop][1] < position[5][1])//closest cop in the left --C--T--
			{
				if (position[5][1] == colomns - 1 || IsSomebodyThere(position, copCounter, position[5][0], position[5][1] + 1) == copIsThere)//if thief has no place to go
				{
					PrintGameBoard(position, GameTable, rows, colomns, copCounter); //thief turn is over,cop in the right or end of board
				}
				else //thief can move right
				{
					GameTable[position[5][0]][position[5][1]] = '-';
					position[5][1] = position[5][1] + 1;
					GameTable[position[5][0]][position[5][1]] = 'R';
					PrintGameBoard(position, GameTable, rows, colomns, copCounter);
				}
			}
			else//closest cop is in the right --T--C--
			{
				if (position[5][1] == 0 || IsSomebodyThere(position, copCounter, position[5][0], position[5][1] - 1) == copIsThere)//if thief has no place to go
				{
					PrintGameBoard(position, GameTable, rows, colomns, copCounter); //thief turn is over,cop in the right or end of board
				}
				else //thief can move left
				{
					GameTable[position[5][0]][position[5][1]] = '-';
					position[5][1] = position[5][1] - 1;
					GameTable[position[5][0]][position[5][1]] = 'R';
					PrintGameBoard(position, GameTable, rows, colomns, copCounter);
				}
			}
		countMoves++;
	    
	}
	return thiefWon;//end of the game***
	PrintGameBoard(position, GameTable, rows, colomns, copCounter);
}
void arrangeArrayPosition(int position[6][2],int copCounter) //arange the position od the players in order to print the right moves
{
	int holder;//keeps the lowest umber in the columns
	if (copCounter == 1)//if number of cups are 1 no need to lkgf,arange anything  
		return;
	else
	{
		for (int i = 0; i < copCounter; i++) //arrange the columns.
			for (int j = 0; j < copCounter-1; j++)
			{
				if (position[j][1] > position[j + 1][1])
				{
					holder = position[j][1];
					position[j][1]= position[j+1][1];
					position[j+1][1]=holder;
					holder = position[j][0];
					position[j][0] = position[j + 1][0];
					position[j + 1][0] = holder;
				}
			}
		for (int i = 0; i < copCounter; i++) //arrange the rows.
			for (int j = 0; j < copCounter-1; j++)
			{
				if ((position[j][1] == position[j + 1][1]) && (position[j][0] > position[j + 1][0])) 
				{
					holder = position[j][0];
					position[j][0] = position[j+1][0];
					position[j+1][0] = holder;
				}
			}
	}
}
int IsSomebodyThere(int position[6][2], int copCounter, int moveToRow, int moveToColumn)
{
	if (position[5][0] == moveToRow && position[5][1] == moveToColumn)
		return ThiefIsThere; //if there is a cop in this position return ThiefIsThere
	for (int i = 0; i < copCounter; i++)
	{
		if ((position[i][0] == moveToRow) && (position[i][1] == moveToColumn))
			return copIsThere;//if there is a cop in this position return copIsThere
	}
	return noOnehere;//if there isn't a cop in this position return noOnehere
}
void PrintGameBoard(int position[6][2], char GameTable[MAX_SIZE][MAX_SIZE], int rows, int colomns,int copCounter)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colomns; j++)
			printf("%c", GameTable[i][j]);
		printf("\n");
	}
	
}
int PrepareBoard(int Position[6][2], char GameTable[MAX_SIZE][MAX_SIZE], int rows, int colomns)
{
	int HowManyCops = 0, copRow = 0, copColumn = 0;
	int copCounter=0;
	{
	for (int i = 0; i < rows; i++) //put '-' signs all around the board
		for (int j = 0; j < colomns; j++)
		{
			GameTable[i][j] = '-';
		}
    }
	GameTable[(rows - 1) / 2][(colomns - 1) / 2] = 'R';//place the thief
	Position[5][0] = (rows - 1) / 2;
	Position[5][1] = (colomns - 1) / 2;
	printf("How many cops (1-5)?\n");
	scanf("%d", &HowManyCops);
	
	for (int k = 0; k < HowManyCops; k++)
	{
		printf("Let's choose a cell:\n");
		do
		{
		scanf("%d", &copRow);
		scanf("%d", &copColumn);
		} while (GameTable[copRow][copColumn] == 'R' || GameTable[copRow][copColumn] == 'C');//the thief or a cop ate already in this position
		GameTable[copRow][copColumn] = 'C'; //place the cop
		Position[copCounter][0] = copRow; //place the cop row position in the array
		Position[copCounter][1] = copColumn; //place the cop column position in the array
		copCounter++;
	}
	return copCounter;
}
void game2()
{
	char board3x3[3][3];
	int horseArray[4][2];
	int isPlayin=StillPlaying;
	horseArray[0][0] = 0;
	horseArray[0][1] = 0;
	horseArray[1][0] = 0;
	horseArray[1][1] = 2;
	horseArray[2][0] = 2;
	horseArray[2][1] = 0;
	horseArray[3][0] = 2;
	horseArray[3][1] = 2;

	board3x3[0][0] = 'W';
	board3x3[1][0] = '-';
	board3x3[2][0] = 'B';
	board3x3[0][1] = '-';
	board3x3[1][1] = '-';
	board3x3[2][1] = '-';
	board3x3[0][2] = 'W';
	board3x3[1][2] = '-';
	board3x3[2][2] = 'B';
	int countNumOfMoves=0, moveFromX, moveFromY, moveToX, moveToY;
	printHorsesBoard(board3x3);
	while (countNumOfMoves<15&& isPlayin == StillPlaying)
	{
		printf("W:\n");  //white play first

		scanf("%d", &moveFromX); //take numbers from user
		scanf("%d", &moveFromY);
		scanf("%d", &moveToX);
		scanf("%d", &moveToY); 

		board3x3[moveFromX][moveFromY] = '-';
		board3x3[moveToX][moveToY] = 'W';
		//horses array update
		if (horseArray[0][0] == moveFromX && horseArray[0][1] == moveFromY)//check which white player need to move
		{
			horseArray[0][0] = moveToX;
			horseArray[0][1] = moveToY;
		}
		else
		{
			horseArray[1][0] = moveToX;
			horseArray[1][1] = moveToY;
		}

		
		//blacks have no place to move print white won
		if (isHorseBlocked(board3x3, horseArray[2][0], horseArray[2][1]) == Blocked && isHorseBlocked(board3x3, horseArray[3][0], horseArray[3][1]) == Blocked)
		{
			printHorsesBoard(board3x3);
			printf("The whites won!\n");
			isPlayin=gameOver;
		}
		printHorsesBoard(board3x3);
		//blacks turn
		printf("B:\n");

		//user input blabk movment
		scanf("%d", &moveFromX); //take numbers from user
		scanf("%d", &moveFromY);
		scanf("%d", &moveToX);
		scanf("%d", &moveToY);
		//horses array update
		if (horseArray[2][0] == moveFromX && horseArray[2][1] == moveFromY)//check which black player need to move
		{
			horseArray[2][0] = moveToX;
			horseArray[2][1] = moveToY;
		}
		else
		{
			horseArray[3][0] = moveToX;
			horseArray[3][1] = moveToY;
		}
		//table array update
		board3x3[moveFromX][moveFromY] = '-';
		board3x3[moveToX][moveToY] = 'B';
		//is white blocked?
		if (isHorseBlocked(board3x3, horseArray[0][0], horseArray[0][1]) == Blocked && isHorseBlocked(board3x3, horseArray[1][0], horseArray[1][1]) == Blocked)
		{
			printHorsesBoard(board3x3);
			printf("The blacks won!\n");
			isPlayin = gameOver;
		}
		if(isPlayin == StillPlaying)
		printHorsesBoard(board3x3);
		countNumOfMoves++;
	}
	if(countNumOfMoves==15)
	  printf("Tie\n");
}

int isHorseBlocked(char board3x3[3][3],int MoveFromX,int MoveFromy)
{
	int TwoBlocks=0;
	if (MoveFromX == 0 && MoveFromy == 0)
		if (board3x3[2][1] != '-' && board3x3[1][2] != '-')
			return Blocked;
	if (MoveFromX == 1 && MoveFromy == 0)
		if (board3x3[2][2] != '-' && board3x3[2][2] != '-')
			return Blocked;
	if (MoveFromX == 2 && MoveFromy == 0)
		if (board3x3[0][1] != '-' && board3x3[1][2] != '-')
			return Blocked;
	if (MoveFromX == 2 && MoveFromy == 1)
		if (board3x3[0][0] != '-' && board3x3[0][2] != '-')
			return Blocked;
	if (MoveFromX == 2 && MoveFromy == 2)
		if (board3x3[1][0] != '-' && board3x3[0][1] != '-')
			return Blocked;
	if (MoveFromX == 1 && MoveFromy == 2)
		if (board3x3[0][0] != '-' && board3x3[2][0] != '-')
			return Blocked;
	if (MoveFromX == 0 && MoveFromy == 2)
		if (board3x3[1][0] != '-' && board3x3[2][1] != '-')
			return Blocked;
	if (MoveFromX == 0 && MoveFromy == 1)
		if (board3x3[2][0] != '-' && board3x3[2][2] != '-')
			return Blocked;

		return NotBlocked;//have a place to move
}
void printHorsesBoard(char board3x3[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%c", board3x3[i][j]);
		printf("\n");
	}
}

void checkWin(int winner)
{
	if (winner == copsWon)
	{

		printf("The cops won!\n");
	}
	if (winner == thiefWon)
	{
		printf("The rob managed to escape! \n");
	}
}
