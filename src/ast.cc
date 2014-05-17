#include <iostream>  
#include <cstdlib>
#include <cstdint>

#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include <boost/program_options.hpp>

class RandomFSA
{
	public:
		enum State {READING, GETTING};
		enum Input {READ, GOT};

		State transitionFunction(Input symbol);


	private:
		State state;

};

namespace po = boost::program_options;

int main(int argc, char **argv)
{
	po::options_description desc("Available options");
	desc.add_options()
		("help", "help message")
		("port", po::value<uint16_t>, "host port")
		;


	return EXIT_SUCCESS;
}
