#include <iostream>

using namespace std;

// N is the size of the 2D matrix N*N
#define N 9

int  grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

//Printing the ans of the solved sudoku , grid ka print

void sudoku_input()
{ int num;
		cout<<"Enter numbers Starting from left to right-> and then one down "<<endl;
				cout<<"Enter '0' wherever balnk "<<endl;
				for(int i=0;i<9;i++)
				{
					for(int j=0;j<9;j++)
					{
						cin>>num;
						grid[i][j]=num;
					}
				}
}

void change_num()
{ int A,B,C,x;
	cout<<"How many Numbers u wanna Change"<<endl;
				cin>>x;
				cout<<"Row/Column no. starts from 0 and ends at 8"<<endl;
				for(int i =x;i>0;i--){
				
					cout<<"Enter row :"<<endl;
					cin>>A;
					cout<<"Enter column :"<<endl;
					cin>>B;
					cout<<"Enter number : "<<endl;
					cin>>C;
					grid[A][B]=C;
}}
void print(int arr[N][N])
{
	for (int q = 0; q < N; q++)
	{
		for (int p = 0; p < N; p++)
			cout << arr[q][p] << " ";
			cout << endl;
	}
}
//checking whether it is appropraiate to give a particualr no. to a certain position
bool isSafe(int grid[N][N], int row,int col, int num)
{
//	checking in rows
	for (int x = 0; x <= 8; x++)
		if (grid[row][x] == num)
			return false;
//checking in columns
	for (int x = 0; x <= 8; x++)
		if (grid[x][col] == num)
			return false;

//checking in a box 3x3 matrix
	int startRow = row - row % 3,
			startCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i + startRow][j +
							startCol] == num)
				return false;

	return true;
}

//filling empty values
bool solveSudoku(int grid[N][N], int row, int col)
{
//checking if we have reached 8th row and last column
	if (row == N - 1 && col == N)
		return true;
//		here we r returninig true to avoid more backtracking

//when column becomes 9th we shift to next row and next column
	if (col == N) {
		row++;
		col = 0;
	}

	if (grid[row][col] > 0)
		return solveSudoku(grid, row, col + 1);

	for (int num = 1; num <= N; num++)
	{
		
		if (isSafe(grid, row, col, num))
		{
			
//	assuming certain value at defined positiopn and iterrating
			grid[row][col] = num;
		
			// Checking for next possibility with next column
			if (solveSudoku(grid, row, col + 1))
				return true;
		}
	
//	if assumption was wrong again replpacing it with 0
		grid[row][col] = 0;
	}
	return false;
}

// Driver Code
int main()
{  
int A,B,C,n,x,num;
//initialise();
	// 0 means unassigned cells

  cout<<"Sample sudoku"<<endl;
  print(grid);		
  cout<<"1.Enter your own sudoku puzzle. "<<endl;
  cout<<"2.Change a particukar no. from the puzzle."<<endl;
  cout<<"3.Check sudoku puzzle "<<endl;
  cout<<"4.Get answer"<<endl;

while(1){
	cout<<"Select an option: "<<endl;
	cin>>n;

	switch(n)
		{   
			case 1:
			sudoku_input();
				break;
			case 2:
				change_num();
				break;
			case 3:
				print(grid);
				    break;
		    case 4:
		    		if (solveSudoku(grid, 0, 0))
		    		{
					cout<<"SOLVED SUDOKU "<<endl;
						print(grid);
					}
					else
					cout<<"Their aint a solution for this ,Please check ur question again :)"<<endl;
					break;
		}	
		}
}
