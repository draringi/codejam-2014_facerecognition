/*
 * core.c
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "face-cleaner.h"

int main(int argc, char* argv[]){
	if (argc < 2){
		fprintf(stderr, "Usage: %s IMAGEFILE", argv[0]);
		exit(EXIT_FAILURE);
	}
	char* filename = argv[1];
	char* tmp_filename_base = crypt(filename, filename);
	char* output_name = (char*) clean_and_save(filename, tmp_filename_base);
	printf("%s\n", output_name);
	return(EXIT_SUCCESS);
}
