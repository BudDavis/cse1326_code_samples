#include "move.hpp"
#include "position.hpp"



#define BOOST_TEST_MODULE validMove
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(validMoves)
{
    {
       move M(position(1,1),position(1,3));
       BOOST_CHECK( M.valid_move());
    }
    {
       move M(position(1,1),position(1,3));
       BOOST_CHECK( M.valid_move());
    }
}

BOOST_AUTO_TEST_CASE(validMoves2)
{
    move M(position(8,1),position(8,3));
    BOOST_CHECK( M.valid_move());
}
