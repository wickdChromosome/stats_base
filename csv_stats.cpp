/*
This is supposed to be a template file that has everything set up 
for statistical analysis from a csv file 
*/

/* LAST COMPILED ON __DATE __ __TIME__*/



#include <vector>
#include <string>
#include <fstream>

#include "matplotlibcpp.h"
#include "csv.h"

namespace plt = matplotlibcpp;
using namespace std;

int 
main () 
{

	/* Vectors for the data */
	vector<string> IDs;
	vector<int> col1s;
	vector<int> col2s;

	/* Read in the csv */
	const string INFILENAME= "test.csv"; // input file name
	const int PROCESS_COLS = 3; // number of columns you are going to use

	io::CSVReader<PROCESS_COLS> in(INFILENAME);
	in.read_header(io::ignore_extra_column, "ID", "col1", "col2");
	string ID; int col1; int col2;
	while(in.read_row(ID, col1, col2)){
	
		/*NOW ITS YOUR TIME TO SHINE*/
		IDs.push_back(ID);			
		col1s.push_back(col1);			
		col2s.push_back(col2);			

	}


	



	/* PLOT SOME SHIT */
	plt::plot(col1s,col2s);
	plt::show();

}

