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

using namespace std;

int main (int argc, char *argv[]){
	string trainfile;
	bool train_set = false;
	queue<string> image_list;
	int flag;
	while ((flag = getopt (argc, argv, "o:")) != -1){
		switch(flag){
		case 'o':
			trainfile = optarg;
			train_set = true;
			break;
		case '?':
			if (optopt == 'o'){
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
	int index;
	for (index = optind; index < argc; index++){
		image_list.push(argv[index]);
	}
	//Now that the command line has been parsed, let us make use of it.
	buildTrainer(trainfile, image_list);
}
