/*
 * file_load.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 *
 */

#include "load_file.h"
#include "file_type.h"
#include "load_gif.h"
#include <opencv2/highgui/highgui.hpp>


namespace facerecognition {

bool supported(string ext){
	return ext == "jpeg" || ext == "png" || ext == "jpg" || ext == "bmp" || ext == "ras" || ext == "sr" || ext == "jpe";
}

using namespace cv;

Mat load_file(char* filename){
	string ext = get_file_extension(filename);
	Mat file;
	if(ext == "gif"){
		file = gif2ipl(filename);
	} else if (supported(ext)){
		file = imread(filename, 0);
	}
	return file;
}

}


