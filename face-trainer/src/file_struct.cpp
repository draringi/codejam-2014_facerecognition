/*
 * file_struct.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#include "file_struct.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

file_struct read_line(string line){
	char* str = (char*) line.c_str();
	char* ptr;
	file_struct result;
	ptr = strtok(str, ";\0");
	result.filename = ptr;
	ptr = strtok(NULL, ";\0");
	result.label = atoi(ptr);
	return result;
}


