/*
 * file_struct.h
 *
 *  Created on: Nov 15, 2014
 *      Author: draringi
 */

#ifndef FILE_STRUCT_H_
#define FILE_STRUCT_H_

using namespace std;

typedef struct {
	string filename;
	int label;
}file_struct;

file_struct read_line(string filename);

#endif /* FILE_STRUCT_H_ */
