//conway's game of life
#include<iostream>
#include<func.h>
using namespace std;

struct grid
{
	int row = 30;
	int col = 50;
	char grid[30][50];
	int simPattern[30] = {10,21,10,22,10,23,10,24,10,25,11,21,11,22,11,23,11,24,11,25,12,21,12,22,12,23,12,24,12,25};	//2* size of number of live cells
}g;

void makeGrid()
{
	int patternCounter = 0;
	for(int row = 0; row < g.row; row++)
	{
		for(int col = 0; col < g.col; col++)
		{
			if(row == 0 or row == g.row - 1 or col == 0 or col == g.col - 1)
			{
				g.grid[row][col] = '#';
			}
			else
			{
				g.grid[row][col] = ' ';
			}
		}
	}
	while(patternCounter < 30)
	{
		g.grid[g.simPattern[patternCounter]][g.simPattern[patternCounter + 1]] = 'Û';
		patternCounter += 2;
	}
}

void printGrid()
{
	gotoxy(0,0);
	for(int row = 0; row < g.row; row++)
	{
		for(int col = 0; col < g.col; col++)
		{
			cout<<" "<<g.grid[row][col];
		}
		cout<<endl;
	}
}

void messshitup()
{
	int counter = 0;
	for(int row = 0; row < g.row; row++)
	{
		for(int col = 0; col < g.col; col++)
		{
			if(g.grid[row][col] == 'Û')
			{
				for(int i = row - 1; i <= row + 1; i++)
				{
					for(int j = col - 1; j<= col+1; j++)
					{
						if(i == row and j == col)
						{
							continue;
						}
						else
						{
							if(g.grid[i][j] == 'Û')
							{
								counter++;
							}
						}
					}
				}
				if(counter >= 2 && counter <= 3)
				{
					continue;
				}
				else
				{
					g.grid[row][col] = ' ';
				}
				counter = 0;
			}
			else if(g.grid[row][col] == ' ')
			{
				for(int i = row - 1; i <= row + 1; i++)
				{
					for(int j = col - 1; j<= col+1; j++)
					{
						if(i == row and j == col)
						{
							continue;
						}
						else
						{
							if(g.grid[i][j] == 'Û')
							{
								counter++;
							}
						}
					}
				}
				if(counter == 3)
				{
					g.grid[row][col] = 'Û';
				}
				else
				{
					continue;
				}
				counter = 0;
			}
		}
	}
}

int main()
{
	makeGrid();
	while(true)
	{
		printGrid();
		delay(100);
		messshitup();
	}
	return 0;
}
