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

		friend std::ostream&
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
	private:
		string host;
		uint16_t port;
		bool matches;
};

#endif // TARGET_H_
