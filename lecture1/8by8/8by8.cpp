#include <iostream>
#include <cassert>
#include <random>
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
	// process the whole board
	// and display any queens in the correct row,col
	for (int row=0;row<N;row++)
	{
		for (int col=0;col<N;col++)
		{
			bool isQueen = false;
			// check and see if this row,col is has a queen on it
			// could be any one in the list
			for (int i=0;i<N;i++)
			{
				if (q[i].valid && (q[i].row == row) && (q[i].col==col))
				{
					isQueen = true;
				}
			}

			// this is an ugly piece of code...
			if (is_white(row,col))
			{
				if (isQueen)
				{
					std::cout << " Q ";
				}
				else
				{
					std::cout << "   ";
				}
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
	for (unsigned int i=0;i<N;i++)
	{
		if (q[i].valid && !(q[i].row==row && q[i].col==col))
		{
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
				assert(1);
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
	bool noConflicts=true;
	for (int i=0;i<N;i++)
	{
		if (q[i].valid)
		{
			conflicts[i]= num_conflicts(q,q[i].row,q[i].col);
			if (conflicts[i] && conflicts[i]>max)
			{
				noConflicts = false;
				max = conflicts[i];
				*idx = i;
			}
		}
	}
	if (!noConflicts)
	{
		std::cout << "conflicts " << std::endl;
		std::cout << '\t';
		for (int i=0;i<N;i++)
		{
			if (*idx == i)
			{
				// red
				std::cout << "\033[31m";
			}

			std::cout << "[" << q[i].row << "," << q[i].col << "] = " << conflicts[i] << " ";

			if (*idx == i)
			{
				// reset to normal text
				std::cout <<  "\033[0m";
			}
		}
        }
	if (noConflicts)
	{
		std::cout << "solved" << std::endl;	
		return false;
	}
	else
	{
        	std::cout << std::endl;
		return max!=-1;
	}
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

int destination(queen_positions_t q, int col, int row_)
{
	// given a column, find the best place to place the queen.
	// it will have the minimum number of conflicts.
	int results[N] = {99};
	queen_positions_t r;
	std::cout << "in destination row = " << row_ << " " << "col = " << col << std::endl;
	for (int row=0;row<N;row++)
	{
		for (int i=0;i<N;i++)
		{
			r[i] = q[i];
		}
		//memcpy(r,q,sizeof(queen_positions_t)); // lazy way to do it
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
		if (row == row_)
		{
			results[row] = 99;
		}
		else
		{
			results[row] =  num_conflicts(r,r[idx].row,r[idx].col);
		}
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
	// print out the details
	std::cout << "targets" << std::endl;
	std::cout << '\t';
	for (int i=0;i<N;i++)
	{
		// print out the min in green
		if (i==minIdx)
		{
			std::cout << "\033[32m";
                }
		std::cout << "[" << i << "," << col << "] = " << results[i] << " ";
		if (i==minIdx)
		{
			std::cout << "\033[0m";
		}
	}
	std::cout << std::endl;
	return minIdx;
}

void move_queen(queen_positions_t q,int idx)
{
	// there are conflicts, and the idx points to the biggest one
	int dest = destination(q, q[idx].col,q[idx].row);

	// swap them
	std::cout << "swapping" << std::endl;
	std::cout << '\t';
	std::cout <<  "[" << q[idx].row << "," << q[idx].col << "] and ";
			
	q[idx].row = dest;

	std::cout << "[" << q[idx].row << "," << q[idx].col << "]" << std::endl;
	print(q);
}

#ifndef UNIT_TEST
int main(int argc, char* argv[])
{
	// make a list of queen positions
	//queen_positions_t q={ {true,0,0},{true,1,1},{true,2,2},{true,3,3},{true,4,4},{true,5,5},{true,6,6},{true,7,7} };
        queen_positions_t q={ {true,0,0},{true,6,1},{true,4,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,2,7} }; // a solution
        //queen_positions_t q={ {true,0,0},{true,6,1},{true,2,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,2,7} }; 
	std::cout << "original" << std::endl;
	print(q);
        int idx;
	while (qconflicts(q,&idx))
	{
		move_queen(q,idx);
	}

	std::cout << std::endl;
	return 0;
}
#endif
