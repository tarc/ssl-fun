#include <iostream>  
#include <cstdlib>
#include <cstdint>
#include <iterator>

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

using namespace std;

class RandomFSA
{
	public:
		enum State {READING, GETTING};
		enum Input {READ, GOT};

		State transitionFunction(Input symbol);


	private:
		State state;

};

int main(int argc, char **argv)
{
	po::options_description desc("Available options");
	desc.add_options()
		("help", "help message")
		("host", po::value<string>(), "host address")
		("port", po::value<uint16_t>(), "host port")
		;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (vm.count("help"))
	{
		cout << desc << "\n";
		return EXIT_FAILURE;
	}

	if (vm.count("port"))
	{
		cout << "Port: " << vm["port"].as<uint16_t>() << "\n";
	}
	else
	{
		cout << "Port not set.\n";
	}

	return EXIT_SUCCESS;
}
