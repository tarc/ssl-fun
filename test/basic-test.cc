#define BOOST_TEST_MODULE BasicTest
#include <boost/test/unit_test.hpp>

#include "target.h"

BOOST_AUTO_TEST_CASE( basic_teste )
{
	Target target01( "www.google.com:8080" );
	BOOST_CHECK( target01 );

	Target target02( "192.168.9.2:8080" );
	BOOST_CHECK( target02 );

	Target target03( "192.168.9.2" );
	BOOST_CHECK( target03 );

	Target target04( "casadavovo" );
	BOOST_CHECK( target04 );
}
