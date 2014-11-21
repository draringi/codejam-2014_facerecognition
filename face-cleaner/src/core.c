/*
 * core.c
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "face-cleaner.h"

int main(int argc, char* argv[]){
	if (argc < 2){
		fprintf(stderr, "Usage: %s IMAGEFILE", argv[0]);
		exit(EXIT_FAILURE);
	}
	char* filename = argv[1];
	int recog = 0;
	if(argc > 2){
		recog = 1;
	}
	char* tmp_filename_base = strrchr(filename, '/');
	if(tmp_filename_base == NULL){
		tmp_filename_base = filename;
	} else{
		tmp_filename_base++;
	}
	char* output_name = (char*) clean_and_save(filename, tmp_filename_base, recog);
	printf("%s\n", output_name);
	return(EXIT_SUCCESS);
}
