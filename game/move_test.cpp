#include "board.hpp"
#include "move.hpp"
#include "position.hpp"



#define BOOST_TEST_MODULE legalMoves 
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(legal_move_1)
{
    board B;
    move M(position(1,1),position(1,3));
    BOOST_CHECK( B.legal_move(M));
}
