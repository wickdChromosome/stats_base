/*
This is supposed to be a template file that has everything set up 
for statistical analysis from a csv file 
*/

/* LAST COMPILED ON __DATE __ __TIME__*/



#include <vector>
#include <string>
#include <fstream>

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

#include "matplotlibcpp.h"
#include "csv.h"

namespace plt = matplotlibcpp;
using namespace std;
using namespace boost::accumulators;

int 
main () 
{

	/* Accumulators for the data */
	accumulator_set<double, features<tag::mean, tag::median> > acc;

	/* Read in the csv */
	const string INFILENAME= "test.vcf"; // input file name
	const int PROCESS_COLS = 1; // number of columns you are going to use

	io::CSVReader<PROCESS_COLS, io::trim_chars<' '>, io::no_quote_escape<'\t'>, io::throw_on_overflow, io::single_line_comment<'#'> > in(INFILENAME);
	in.read_header(io::ignore_extra_column, "POS");
	int pos;
	while(in.read_row(pos)){
	
		/*NOW ITS YOUR TIME TO SHINE*/
		acc(pos);			

	}

		
	cout << mean(acc) << endl;	



	/* PLOT SOME SHIT */
	//plt::plot(col1s,col2s);
	//plt::show();

}

