/*
 * core.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: Michael Williams
 */

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "recognize.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("USAGE: %s FACE_IMAGE FACE_DB\n", argv[0]);
		printf(
				"\tFACE_IMAGE:\tpath to image of face to"
				" be recognized\n\tFACE_DB:\tpath to learnt face db\n");
		return EXIT_FAILURE;
	}
	string img_filename = argv[1];
	string db_filename = argv[2];
	int id = determine_id(img_filename, db_filename);
	printf("%d\n", id);
	return EXIT_SUCCESS;
}
