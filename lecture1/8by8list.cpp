#include <iostream>


/*
 * this program solves the '8 queen problem'
 * for info, see https://en.wikipedia.org/wiki/Eight_queens_puzzle
 *
 * 'iterative repair' algorithm
 *
 */


const int N=8;

bool is_white(int board[N][N],int row, int col)
{
	if ( (col+row)%2==0 )
		return true;
	else
		return false;
}

bool is_black(int board[N][N],int row,int col)
{
	return !is_white(board,row,col);
}

void print(int board[N][N])
{
	for (unsigned int row=0;row<N;row++)
	{
		for (unsigned int col=0;col<N;col++)
		{
			if (is_white(board,row,col))
			{
				if (board[row][col])
					std::cout << " Q ";
				else
					std::cout << "   ";
			}
			else
			{
				if (board[row][col])
					std::cout << "\033[43m" << " Q " << "\033[0m" ;
				else
					std::cout << "\033[43m" << "   " << "\033[0m" ;
			}
		}
		std::cout << std::endl;
	}
}

bool find_most_conflicts(int board[N][N],int *row, int *col)
{
	// returns a 0 if there are no conflicts. also means the puzzle is solved.
        // processes the whole board !!
	//
	// clear out the current conflict count
	for (unsigned int i=0;i<N;i++)
		for (unsigned int j=0;j<N;j++)
			if (board[i][j])
				board[i][j]=1;
	// calculate the conflicts
	bool conflicts = true;
	for (unsigned int r=0;r<N;r++)
	{
		for (unsigned int c=0;c<N;c++)
		{
			if (board[r][c])
			{
				//is there a queen on the same row?
				for (unsigned int col=0;col<N;col++)
				{
					if (col==c)
						continue;
					//std::cout << "col is " << col << std::endl;
					if (board[r][col])
					{
						board[r][c]++;
						conflicts = true;
					}
				}
				//is there a queen on the same col?
				//is there a queen on the diagonal
			}
		}
	}

	std::cout << "board[0,0] = " << board[0][0] <<std::endl;
	std::cout << "board[0,1] = " << board[0][1] <<std::endl;
	std::cout << "board[0,2] = " << board[0][2] <<std::endl;
	std::cout << "board[7,7] = " << board[7][7] <<std::endl;
	// if not any, return a 0
	std::cout << "conflicts = " << conflicts << std::endl;

	if (!conflicts)
		return false;
	// pick the largest
	// (there is at least one if noConflicts is false)
	int max=0;
	for (unsigned int r=0;r<N;r++)
	{
		for (unsigned int c=0;c<N;c++)
		{
			if (board[r][c]>max)
			{
				max = board[r][c];
				*row = r;
				*col = c;
			}
		}
	}
	// return it
	// row and col are set in the above loop
	std::cout << "row="<<*row<<" col="<<*col<<" max="<<max<<std::endl;

	return true;
}

void move(int board[N][N],int row, int col)
{
	// moves the queen at row,col to a better place
}

int main(int argc, char* argv[])
{
	int board[N][N]={0};
	//  a value in a position means it has a  queen
	//       [rows][columns]
	//       top left is 0,0
	//
	//       when the initial board is created, only 1 queen is allowed
	//       per column
	//
	board[0][0] = 1;
	board[0][1] = 1;
	board[0][2] = 1;
	board[7][7] = 1;
#if 0
	board[0][2] = 1;
	board[0][3] = 1;
	board[0][4] = 1;
	board[0][5] = 1;
	board[0][6] = 1;
	board[0][7] = 1;
#endif
	print(board);

	int row;
	int col;
	while (find_most_conflicts(board,&row,&col))
	{
		std::cout << std::endl;
		move(board,row,col);
		print(board);
		break;
	}
	std::cout << std::endl;
	return 0;
}
