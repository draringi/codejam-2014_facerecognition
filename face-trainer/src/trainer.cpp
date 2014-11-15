/*
 * trainer.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */


#include "trainer.h"
#include <facerecogntion/face-cleaner.h>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <FreeImage.h>

using namespace std;
using namespace cv;

void buildTrainer(string trainfile, queue<string> img_names){
	vector<Mat> img_vector;
	vector<int> img_label;
	while(!img_names.empty()){
		string img_name = img_names.front();
		img_names.pop();
		size_t loc = img_name.find_first_of('_', 0);
		if(loc == 0){
			fprintf (stderr, "Images must not start with '_'\n'%s' does not\n", img_name.c_str());
			abort();
		}
		if(loc == string::npos){
			fprintf (stderr, "'%s' does not match naming convention\n", img_name.c_str());
			abort();
		}
		string label = img_name.substr(0, loc);
		string file_format;
		loc = img_name.find_last_of('.', 1);
		if(loc == string::npos){
			fprintf (stderr, "'%s' has no file extension\n", img_name.c_str());
			abort();
		}
		file_format = img_name.substr(loc + 1, string::npos);
		transform(file_format.begin(), file_format.end(), file_format.begin(), ::tolower);
		Mat img;
		if(file_format == "bmp"||file_format == "dib"||file_format == "pbm"||file_format == "pgm"||file_format == "ppm"||file_format == "sr"||file_format == "ras"){
			img = imread(img_name, CV_LOAD_IMAGE_GRAYSCALE);
		} else if(file_format == "jpeg"||file_format == "jpg"||file_format == "jpe"||file_format == "jp2"||file_format == "png"||file_format == "tiff"||file_format == "tif"){
			img = imread(img_name, CV_LOAD_IMAGE_GRAYSCALE);
		} else if(file_format == "gif") {
			FIBITMAP *src;
			src = FreeImage_Load(FIF_GIF, img_name.c_str(), GIF_DEFAULT);
			img = Mat(FreeImage_GetHeight(src), FreeImage_GetWidth(src), CV_32FC3, FreeImage_GetScanLine(src, 0)).clone();
			flip(img, img, 0);
		} else {
			fprintf (stderr, "'%s' is not a supported extension\n", file_format.c_str());
		}
	}

}
