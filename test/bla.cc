#define BOOST_TEST_MODULE BasicTest
#include <boost/test/unit_test.hpp>

#include "target.h"

BOOST_AUTO_TEST_CASE( basic_teste )
{
	Target target( "www.google.com:8080bla" );

	BOOST_CHECK( target );
}
