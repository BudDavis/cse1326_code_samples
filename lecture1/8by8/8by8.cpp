#include <iostream>
#include <cstring>
/*
 * this program solves the '8 queen problem'
 * for info, see https://en.wikipedia.org/wiki/Eight_queens_puzzle
 *
 * 'iterative repair' algorithm
 *
 */

const int N=8;

/*
 *
 * Data structures:
 *
 * consider the board.  it is an 8x8, with the top right square being 'white'.
 * as for indexing, think of it like this:
 *
 *       int board[N][N];
 *                [row][column]
 *
 * the 0,0 would be the top right when printed on the screen.  7,7 would be
 * bottom right.
 *
 * however, almost all of the time the state of a 'board' will be stored as a
 * list of queen positions.
 *
 */

typedef  int board_t[N][N];

typedef struct
{
	bool valid; // the valid flags lets me test the functions without the complexity of 8 queens at a time
	int row;
	int col;
} queen_pos_t;

typedef queen_pos_t queen_positions_t[N];

bool is_white(int row, int col)
{
	return (col+row)%2==0;
}

void print(queen_positions_t q)
{
	for (int row=0;row<N;row++)
	{
		for (int col=0;col<N;col++)
		{
			bool isQueen = false;
			// check and see if this row,col is has a queen on it
			// could be any one in the list
			for (int i=0;i<N;i++)
			{
				if (q[i].row == row && q[i].col==col && q[i].valid)
				{
					isQueen = true;
				}
			}

			if (is_white(row,col))
			{
				if (isQueen)
					std::cout << " Q ";
				else
					std::cout << "   ";
			}
			else
			{
				if (isQueen)
					std::cout << "\033[43m" << " Q " << "\033[0m" ;
				else
					std::cout << "\033[43m" << "   " << "\033[0m" ;
			}
		}
		std::cout << std::endl;
	}
}

int num_conflicts(queen_positions_t q,int row,int col)
{
	// returns the number of conflicts for a specific [row][col]
	int retval = 0;
        //std::cout << "checking pos " << row << " " << col << std::endl;
	for (unsigned int i=0;i<N;i++)
	{
		if (q[i].valid && !(q[i].row==row && q[i].col==col))
		{
			//std::cout << "point is " << q[i].row << " " << q[i].col << " ";
			double m;
		        if (q[i].row-row == 0)
			{
				// they are in the same row
				retval++;
				//std::cout << "they are in the same row" << std::endl;
			}
			else if (q[i].col-col ==0)
			{
				retval++;
				//std::cout << "they are in the same column" << std::endl;
				// should never get here
			}
			else
			{
				m = (double(q[i].col-col)) / (q[i].row-row);
				if (m==-1 || m==1)
				{
					retval++;
					//std::cout << "they are on the diagonal" << std::endl;
				}
				else
				{
					//std::cout << "no conflict" << std::endl;
				}
			}
		}	
	}
	return retval;
}

bool qconflicts(queen_positions_t q, int *idx)
{
	// check all the queens for conflicts
	// returns a true if there are any.
	// the index of the 'highest conflict' queen is returned 
	int conflicts[N] = {0};
	int max = -1;
	for (int i=0;i<N;i++)
	{
		if (q[i].valid)
		{
			conflicts[i]= num_conflicts(q,q[i].row,q[i].col);
			if (conflicts[i] && conflicts[i]>max)
			{
				max = conflicts[i];
				*idx = i;
			}
		}
	}
	std::cout << "qconflicts" << std::endl;
	for (int i=0;i<N;i++)
		std::cout << "conflicts[" << i << "]=" << conflicts[i] << std::endl;
        std::cout << "the point with the most conflicts is " << q[*idx].row << " " << q[*idx].col << std::endl;
	std::cout << "max = " << max << std::endl;
	return max!=-1;
}

int find_idx(queen_positions_t q,int col)
{
	int idx = -1;
	for (int i=0;i<N;i++)
	{
		if (q[i].valid && q[i].col == col)
		{
			idx = i;
		}
	}
	return idx;
}

int destination(queen_positions_t q, int col)
{
	// given a column, find the best place to place the queen.
	// it will have the minimum number of conflicts.  int retval; for (int row=0;row<N;row++)
	int results[N] = {0};
	for (int row=0;row<N;row++)
	{
		queen_positions_t r;
		memcpy(r,q,sizeof(queen_positions_t)); // lazy way to do it
		// find the index in the list we care about
		// note that there is only 1 queen in each column (top level contraint) int idx=-1;
		int idx = find_idx(r,col);
		// remove the queen in position idx
		r[idx].valid = false;
		r[idx].row = -1;
		r[idx].col = -1;
		//
		r[idx].valid = true;
		r[idx].row  = row;
		r[idx].col = col;
		results[row] =  num_conflicts(r,r[idx].row,r[idx].col);
		std::cout << row << "" << results[row] << std::endl;
	}
	int min = 999;
	int minIdx = -1;
	for (int i=0;i<N;i++)
	{
		if (results[i]<min)
		{
			min = results[i];
			minIdx = i;
		}
	}
	std::cout << "the min is " << minIdx << std::endl;
	std::cout << "row = " << minIdx << " col = " << col << std::endl;
	return minIdx;
}

#ifndef UNIT_TEST
int main(int argc, char* argv[])
{
	// make a list of queen positions
	//queen_positions_t q={ {true,0,0},{true,1,1},{true,2,2},{true,3,3},{true,4,4},{true,5,5},{true,6,6},{true,7,7} };
        //queen_positions_t q={ {true,0,0},{true,6,1},{true,4,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,2,7} }; // a solution
        queen_positions_t q={ {true,0,0},{true,6,1},{true,2,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,2,7} }; // a solution

	print(q);
        int idx;
	while (qconflicts(q,&idx))
	{
		std::cout << "the col being targeted is " << q[idx].col << std::endl;
		int dest = destination(q, q[idx].col);
		std::cout << "the destination is " << std::endl;
		// swap them
		//std::cout << "SWAPPING " << q[idx].row << " and " << smallestIdx << std::endl;
                //q[idx].row = smallestIdx;
		print(q);
	}

	std::cout << std::endl;
	return 0;
}
#endif
