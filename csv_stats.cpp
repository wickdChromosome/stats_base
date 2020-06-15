/*
This is supposed to be a template file that has everything set up 
for statistical analysis from a csv file 
*/

/* Plots the aFC distribution for each tissue*/



#include <vector>
#include <string>
#include <fstream>
#include <map>

//#include <boost/accumulators/accumulators.hpp>
//#include <boost/accumulators/statistics.hpp>

#include "matplotlibcpp.h"
#include "csv.h"

namespace plt = matplotlibcpp;
using namespace std;
//using namespace boost::accumulators;

map<string, double> read_csv(const string &filename, const string &afccol) {

	const int PROCESS_COLS = 2; // number of columns you are going to use
	map<string, double> new_data;

	io::CSVReader<PROCESS_COLS, io::trim_chars<' '>, io::no_quote_escape<','>, io::throw_on_overflow > in(filename);
	in.read_header(io::ignore_extra_column, "variant_id", afccol);
	double afc; string eqtl_id;
	while(in.read_row(eqtl_id, afc)) {
      	/*NOW ITS YOUR TIME TO SHINE*/
		new_data[eqtl_id] = afc;			

	}

	return new_data;
}


int main (int argc, char *argv[]) 
{

	/* Accumulators for the data */
	//accumulator_set<double, features<tag::mean, tag::median> > acc;

	/* Maps for the data */

	map<string, double> new_data;

        /* Read in the csv */
	const string newdata = argv[2]; // input file name
	const string stephandata = argv[1]; // input file name
	const string tname = argv[3]; // tissue name

	auto stephanmap = read_csv(stephandata, tname);
	auto newdatamap = read_csv(newdata, "log2_aFC");
	
	//WOOO lets merge this shit in a really inefficient manner
	vector<double> match1;
	vector<double> match2;
	for (auto const& mapel : stephanmap) {

		for (auto const& newmapel : newdatamap) {

			// if the key is the same as the new one, 22
			if (mapel.first == newmapel.first) {

				match1.push_back(mapel.second);
				match2.push_back(newmapel.second);

			}
		
		}

	}

	/* PLOT SOME SHIT */
	plt::scatter(match1,match2);
	plt::save("imshow.png");
	return 0;
}

