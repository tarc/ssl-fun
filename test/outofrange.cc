#define BOOST_TEST_MODULE BasicTest
#include <boost/test/unit_test.hpp>

#include "target.h"

BOOST_AUTO_TEST_CASE( basic_teste )
{
	Target target05( "uaioruiwe:32422332342343" );
	BOOST_CHECK( !target05 );
}
