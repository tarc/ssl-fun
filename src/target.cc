#include <boost/regex.hpp>

#include "target.h"

bool
Target::parseUrl(const string &tagetStr)
{
	boost::match_results<string::const_iterator> matches;
	static const boost::regex urlParser("([\\w.]+)(?::(\\d+))?");

	if(regex_match(tagetStr, matches, urlParser,
				boost::match_default))
	{
		host = matches[1];
		port = matches[2].matched ? std::stoi(matches[2]) : 80;
		return true;
	}

	return false;
}

std::ostream&
operator<<(std::ostream& os, const Target &target)
{
	if(target)
	{
		os << target.getHost() << ":" << target.getPort() << endl;
	}
	else
	{
		os << "Invalid target" << endl;
	}

	return os;
}
