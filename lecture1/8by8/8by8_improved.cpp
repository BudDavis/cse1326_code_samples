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
 *
 */

typedef  int board_t[N][N];

typedef int qpos_t[N];
// note that the index is the same is the column number

typedef int conflicts_t[N];

board_t mask={{0}};

int sum(conflicts_t a)
{
	int retval = 0;
	for (int i=0;i<N;i++)
	{
		retval+=a[i];
	}
	return retval;
}

void copy(conflicts_t dest, conflicts_t src)
{
	// of course, memcpy would have worked
	for (int i=0;i<N;i++)
	{
		dest[i] = src[i];
	}
}

void copyQpos(qpos_t dest, qpos_t src)
{
	// of course, memcpy would have worked
	for (int i=0;i<N;i++)
	{
		dest[i] = src[i];
	}
}
void zero(conflicts_t c)
{
	// of course, bzero would have worked
	conflicts_t z = {0};
	copy(c,z);
}

int findMaxIdx(conflicts_t c,board_t mask)
{
	// given c, which is a list of conflicts, and a mask
	// which is a count of the number of times this element has been selected

	static int history[N] = {0};

	// find the min
	int max = 0;
	for (int i=0;i<N;i++)
	{
		if (c[i]>max)
		{
			max=c[i];
		}
	}
	std::cout << "the max is " << max << std::endl;
	// the max has been found, now let's find the position
	// with the same value (the max) that has been used the least
        int usedLeast=999;
	int usedLeastIdx=999;
	for (int i=0;i<N;i++)
	{
		if (max == c[i])
		{
			if (history[i]<usedLeast)
			{
				usedLeastIdx = i; 
				usedLeast = history[i];
			}
		}
	}
        history[usedLeastIdx]++;	
	return usedLeastIdx;
}

bool is_white(int row, int col)
{
	return (col+row)%2==0;
}

void printConflictVector(conflicts_t c)
{
	std::cout << "conflicts ";
	for (int i=0;i<N;i++)
	{
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;
}

void print(qpos_t q)
{
	// just a reminder, q is an array where the column is the index, and the
	// row is the value

	// process the whole board
	// and display any queens in the correct row,col
	for (int row=0;row<N;row++)
	{
		for (int col=0;col<N;col++)
		{
			bool isQueen = q[col]==row;
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

int singleConflict(qpos_t q, int idx)
{
	// checks a single member of q, for all conflicst.  the specific member of q is
	// specified by idx.  (note the idx is also the column number)
	int conflicts = 0;
	for (int i=0;i<N;i++)
	{
		if (i==idx)
		{
			// don't need to consider itself
			continue;
		}
		if (q[idx]==q[i])
		{
			// same row
			conflicts++;
		}
		//std::cout << "m = " << double(i-c) / double(q[i]-q[c]) << std::endl;
		double m =  double(i-idx) / double(q[i]-q[idx]);
		if ( m==-1 || m==1 )
		{
			conflicts++;
		}
	}
	return conflicts;
}

bool conflicts(qpos_t q, conflicts_t conflicts)
{
	// returns a true if there are conflicts

	for (int c=0;c<N;(c)++)
	{
		conflicts[c] = singleConflict(q, c);
	}
	return sum(conflicts);
}

void queenToMove(qpos_t q, conflicts_t c,int *row, int *col)
{
	// decide which queen needs to move.
	// c is full of valid data, so this problem is 
	// really how to detect the queen with the highest score
	int maxIdx = findMaxIdx(c,mask);

	*row = q[maxIdx];
	*col = maxIdx;
	return;
}

void whereToMove(qpos_t q,int row,int col,int* toRow,int* toCol)
{
	// check every possible row in this column, and select
	// the lowest conflict value
	//
	qpos_t local_q;

	static int history[N] = {0};

	conflicts_t c = {0};

	for (int i=0;i<N;i++)
	{
		conflicts_t local_c = {0};
		if (row==i)
		{
			c[i]=99;
			continue;
		}
		copyQpos(local_q,q);
		// put the queen here
		local_q[col] = i;
                c[i] = singleConflict(local_q,col);
		//std::cout << "calculating c[i] for i = " << i << " value " << c[i] << std::endl;
		//std::cout << std::endl;
                //print(local_q);
		//printConflictVector(local_c);
		//std::cout << std::endl;
	}
	std::cout << "checking each pos in the row ";
	printConflictVector(c);
	// find the min value
	int min = 99;
	for (int i=0;i<N;i++)
	{
		if (c[i]<min)
		{
			min = c[i];
		}
	}
	int minHistory = 999;
	int minHistoryIdx = -1;
	for (int i=0;i<N;i++)
	{
		if (c[i]==min)
		{
			if (c[i]<minHistory)
			{
				minHistory = c[i];
				minHistoryIdx = i;
			}
		}
	}
	std::cout << "minHistory IDX is " << minHistoryIdx << " min is " << minHistory << std::endl;
	history[minHistoryIdx]++;
        *toRow = minHistoryIdx;
	*toCol = col;


}

void move(qpos_t q,int row,int col,int toRow,int toCol)
{
	// hardly worth having a function to do this...
	// (all of the extra parameters probably need to be deleted)
	q[toCol] = toRow;
}

#ifndef UNIT_TEST
int main(int argc, char* argv[])
{
	std::cout << "[Row,Col]" << std::endl;
	qpos_t q = {0,1,2,3,4,5,6,7};
	//qpos_t q = {0,0,0,0,0,0,0,0};
	//qpos_t q = {7,7,7,7,7,7,7,7};
	//qpos_t q = {0,6,4,7,1,3,5,2}; // a solution
	//qpos_t q = {1,6,4,7,1,3,5,2};

	std::cout << "Original" << std::endl;
        print(q);
	conflicts_t c = {0};
        int passes = 0; // detect infinite loops
	while ( conflicts(q,c)  && passes++<999 )
	{
		std::cout << std::endl;
		std::cout << "Pass " << passes << std::endl;
		int row;
		int col;
                queenToMove(q, c, &row, &col);
		int toRow;
		int toCol;
		whereToMove(q,row,col,&toRow,&toCol);
		move(q,row,col,toRow,toCol);
		std::cout << "Pass " << passes << std::endl;
		print(q);
		printConflictVector(c);
		std::cout << "the queen to move is " << row << " " << col << std::endl;
		std::cout << "moving " << row << " col " << col << " to " << toRow << "  " << toCol << std::endl;
		// get ready for the next pass through
		zero(c);
	}
	std::cout << std::endl;
	return 0;
}
#endif
