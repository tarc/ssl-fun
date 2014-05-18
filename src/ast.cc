#include <iostream>  
#include <cstdlib>
#include <cstdint>
#include <iterator>

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

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
	po::options_description show("Available options");
	po::variables_map vm;

	string target;

	try
	{
		po::options_description desc("Hidden options");
		show.add_options()
			("help,h", "Show this help message")
			;
		desc.add_options()
			("target", po::value< string >(&target), "Target host")
			;
		desc.add(show);

		po::positional_options_description posDesc;
		posDesc.add("target", 1);

		po::store(po::command_line_parser(argc, argv).
				options(desc).
				positional(posDesc).run(), vm);
		po::notify(vm);

	}
	catch(exception &e)
	{
		cerr << "Error: " << e.what() << endl;
		return EXIT_FAILURE;
	}
	catch(...)
	{
		cerr << "Unknown exception!" << endl;
	}

	if (vm.count("help"))
	{
		boost::filesystem::path p = argv[0];
		cout << "Usage: " << p.stem().string() << " [options]" << endl;
		cout << show;
	}

	if (vm.count("target"))
	{
		cout << target << endl;
	}

	return EXIT_SUCCESS;
}
