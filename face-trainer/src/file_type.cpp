/*
 * file_type.c
 *
 *  Created on: Nov 15, 2014
 *      Author: draringi
 */


#include <string.h>
#include "file_type.h"

char* get_file_extension(const char* str){
	char* ptr = strrchr(str, '.');
	if(ptr==NULL){
		return NULL;
	}
	ptr++;
	return ptr;
}
