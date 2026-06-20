#define BOOST_TEST_MODULE MyTestModule
#include <boost/test/included/unit_test.hpp>

// this is a hack, to make this first homework very simple to compile
#define UNIT_TEST
#include "8by8_improved.cpp"
#define DEBUG_OUTPUT 1
static void single_conflict_test(qpos_t q,int results[N])
{
#ifdef DEBUG_OUTPUT
#endif
                int actualResults[N] = {0};
		for (int i=0;i<N;i++)
		{
			actualResults[i] = singleConflict(q,i);
			BOOST_TEST(results[i]==actualResults[i]);
		}
#if DEBUG_OUTPUT
			print(q);
			std::cout << std::endl;
			printConflictVector(actualResults);
#endif
}
BOOST_AUTO_TEST_CASE(single_conflict)
{
// Lets test the calculation of a conflict for a single [row,col]
	{
		qpos_t q =    {0,1,2,3,4,5,6,7};
		int results[]={7,7,7,7,7,7,7,7};
		single_conflict_test(q,results);
	}
	{
		qpos_t q =    {0,0,0,0,0,0,0,0};
		int results[]={7,7,7,7,7,7,7,7};
		single_conflict_test(q,results);
	}
	{
		qpos_t q =  {0,6,4,7,1,3,5,2};
		int results[]={0,0,0,0,0,0,0,0};
		single_conflict_test(q,results);
	}
	{
		qpos_t q =  {1,6,4,7,1,3,5,2};
		int results[]={1,0,0,0,1,0,0,0};
		single_conflict_test(q,results);
	}

	//qpos_t q = {0,1,2,3,4,5,6,7};
	//qpos_t q = {7,7,7,7,7,7,7,7};
	//qpos_t q = {0,6,4,7,1,3,5,2}; // a solution
	//qpos_t q = {0,6,4,7,1,3,5,3};
}

