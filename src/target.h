#ifndef TARGET_H_
#define TARGET_H_

#include <string>
#include <cstdint>

using namespace std;

class Target
{
	public:
		Target(const string &targetStr)
			: matches(parseUrl(targetStr))
		{ }

		bool parseUrl(const string &tagetStr);

		operator bool() const
		{ return matches; }

		const string getHost() const
		{ return host; }

		uint16_t getPort() const
		{ return port; }


	private:
		string host;
		uint16_t port;
		bool matches;
};

#endif // TARGET_H_
