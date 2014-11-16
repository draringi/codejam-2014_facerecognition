/*
 * core.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <queue>
#include <string>
#include "trainer.h"
#include <fstream>
#include <sstream>

using namespace std;

int main (int argc, char *argv[]){
	string trainfile;
	string csv_file;
	bool train_set = false;
	bool csv_set = false;
	queue<file_struct> image_list;
	int flag;
	while ((flag = getopt(argc, argv, "i:o:")) != -1){
		switch(flag){
		case 'o':
			trainfile = optarg;
			train_set = true;
			break;
		case 'i':
			csv_file = optarg;
			csv_set = true;
			break;
		case '?':
			if (optopt == 'o'||optopt == 'i'){
				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
			} else if (isprint (optopt)){
				fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			} else {
				fprintf (stderr,
						"Unknown option character `\\x%x'.\n",
						optopt);
			}
			abort();
		default:
			abort();
		}
	}
	if(!train_set){
		fprintf (stderr, "Output file must be set using -o\n");
		return 1;
	}
	if(!csv_set){
			fprintf (stderr, "CSV file must be set using -i\n");
			return 1;
		}
	ifstream file(csv_file.c_str(), ifstream::in);
	if(!file){
		fprintf (stderr, "CSV file does not exist\n");
		return 1;
	}
	string line;
	while(getline(file, line)){
		image_list.push(read_line(line));
	}
	//Now that the command line has been parsed, let us make use of it.
	printf("Done loading file names. Starting loading files now...\n");
	buildTrainer(trainfile, image_list);
}
