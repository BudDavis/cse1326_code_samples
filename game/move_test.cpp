#define BOOST_TEST_MODULE valid 
#include <boost/test/included/unit_test.hpp>
struct TempSensor
{
    double value;
    double highest;
    double lowest;
    TempSensor(double V)
    {
        highest = V;
        lowest = V;
        value = V;
    }
    updateValue(double V)
    {
        value = V;
        if (value<lowest)
            lowest = V;
        if (value>highest)
            highest = V;
    }
}
BOOST_AUTO_TEST_CASE(test_highest)
{


}




