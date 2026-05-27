#define BOOST_TEST_MODULE MyTestModule
#include <boost/test/included/unit_test.hpp>

// this is a hack, to make this first homework very simple to compile
#define UNIT_TEST
#include "8by8.cpp"

BOOST_AUTO_TEST_CASE(positions)
{
//bool qconflicts(queen_positions_t q, int *idx)
	{
		// valid solutions, should have no conflicts
		queen_positions_t q={ {true,0,0},{true,6,1},{true,4,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,2,7} };
		print(q);
		int t;
		BOOST_TEST( false == qconflicts(q,&t));
	}
	{
		queen_positions_t q={ {true,0,0},{true,6,1},{true,3,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,2,7} };
		print(q);
		int t;
		BOOST_TEST( true == qconflicts(q,&t));
		BOOST_TEST ( t == 2 );
		std::cout << t << std::endl;
	}
	{
		queen_positions_t q={ {true,0,0},{true,6,1},{true,4,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,3,7} };
		print(q);
		int t;
		BOOST_TEST( true == qconflicts(q,&t));
		BOOST_TEST ( t == 7 );
		std::cout << t << std::endl;
	}
		//queen_positions_t q={ {true,0,0},{true,6,1},{true,4,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,3,7} };
}
//bool qconflicts(queen_positions_t q, int *idx)
BOOST_AUTO_TEST_CASE(num_conflicts_1) 
{
//	int num_conflicts(queen_positions_t q,int row,int col)
	{ // one queen
		queen_positions_t q={ {true,0,0} };
		print(q);
		BOOST_TEST( 0 == num_conflicts(q,0,0));
		std::cout << std::endl;
	}
	{ // two queens, no conflict
		queen_positions_t q={ {true,0,0},{true,2,3} };
		print(q);
		BOOST_TEST( 0 == num_conflicts(q,2,3));
		std::cout << std::endl;
	}
	{ // two queens, conflict same row
		queen_positions_t q={ {true,0,0},{true,0,1} };
		print(q);
		BOOST_TEST( 1 == num_conflicts(q,0,0));
		std::cout << std::endl;
	}
	{ // two queens, conflict same column (should never happen) 
		queen_positions_t q={ {true,0,0},{true,1,0} };
		print(q);
		BOOST_TEST( 1 == num_conflicts(q,0,0));
		std::cout << std::endl;
	}
	{ // two queens, conflict diagonal
		queen_positions_t q={ {true,0,0},{true,1,1} };
		print(q);
		BOOST_TEST( 1 == num_conflicts(q,0,0));
		BOOST_TEST( 1 == num_conflicts(q,1,1));
		std::cout << std::endl;
	}
	{ // two queens check entire column
	        int results[]={1,0,0,0,0,0,0,1};
	        for (int i=0;i<N;i++)
		{
			queen_positions_t q={ {true,0,0},{true,i,7} };
			print(q);
			BOOST_TEST( results[i] == num_conflicts(q,0,0));
			BOOST_TEST( results[i] == num_conflicts(q,i,7));
			std::cout << std::endl;
		}
	}
	{ // two queens, conflict diagonal
		queen_positions_t q={ {true,0,0},{true,1,1} };
		print(q);
		BOOST_TEST( 1 == num_conflicts(q,0,0));
		BOOST_TEST( 1 == num_conflicts(q,1,1));
		std::cout << std::endl;
	}
	{ // solution.  should have no conflicts
		queen_positions_t q={ {true,0,0},{true,6,1},{true,4,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,2,7} };
		print(q);
		for (int i=0;i<N;i++)
		{
			BOOST_TEST( 0 == num_conflicts(q,q[i].row,q[i].col));
		}
		std::cout << std::endl;
	}
	{ // conflicts
		queen_positions_t q={ {true,0,0},{true,6,1},{true,3,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,2,7} };
		print(q);
		int results[]={0,0,2,0,1,1,0,0};
		for (int i=0;i<N;i++)
		{
			BOOST_TEST( results[i] == num_conflicts(q,q[i].row,q[i].col));
		}
		std::cout << std::endl;
	}
	{ // conflicts
		queen_positions_t q={ {true,0,0},{true,6,1},{true,4,2},{true,7,3},{true,1,4},{true,3,5},{true,5,6},{true,3,7} };
		print(q);
		int results[]={0,0,0,1,0,1,0,2};
		for (int i=0;i<N;i++)
		{
			std::cout << "results["<<i<<"]="<< num_conflicts(q,q[i].row,q[i].col) << std::endl;
			BOOST_TEST( results[i] == num_conflicts(q,q[i].row,q[i].col));
		}
		std::cout << std::endl;
	}
	//queen_positions_t q={ {true,0,0},{true,1,1},{true,2,2},{true,3,3},{true,4,4},{true,5,5},{true,6,6},{true,7,7} };
	//print(q);
} 
