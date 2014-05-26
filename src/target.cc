#include <cstdint>

#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>

#include "target.h"

bool
Target::parseUrl(const string &targetStr)
{
	boost::match_results<string::const_iterator> matches;
	static const boost::regex urlParser("([\\w.]+)(?::(\\d+))?");

	if(regex_match(targetStr, matches, urlParser,
				boost::match_default))
	{
		host = matches[1];

		if (!matches[2].matched)
		{
			port = 80;
			return true;
		}

		try
		{
			port = boost::lexical_cast<uint16_t> (matches[2]);
		}
		catch (boost::bad_lexical_cast)
		{
			return false;
		}

		return true;
	}

	return false;
}


