/*
This is supposed to be a template file that has everything set up 
for statistical analysis from a csv file 
*/

/* LAST COMPILED ON __DATE __ __TIME__*/


#include "csv.h"
#include <dlib/statistics.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using namespace dlib;

int 
main () 
{

	string INFILENAME= argv[1]; // input file name
	int PROCESS_COLS = argv[2]; // number	of columns you are going to use

	io::CSVReader<PROCESS_COLS> in(INFILENAME);
	in.read_header(io::ignore_extra_column, "col1", "col2");
	std::string vendor; int size; double speed;
	while(in.read_row(col1, col2)){
	
		/*NOW ITS YOUR TIME TO SHINE*/
					


	}

}

