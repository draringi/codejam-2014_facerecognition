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
#include "file_type.h"
#include "load_gif.h"

using namespace std;
using namespace cv;

void buildTrainer(string trainfile, queue<string> img_names){
	vector<Mat> img_vector;
	vector<int> img_labels;
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
		char* file_ext = get_file_extension(img_name.c_str());
		if(file_ext == NULL){
			fprintf (stderr, "'%s' has no file extension\n", img_name.c_str());
			abort();
		}
		file_format = file_ext;
		transform(file_format.begin(), file_format.end(), file_format.begin(), ::tolower);
		Mat img;
		printf("Loading %s:\t", img_name.c_str());
		if(file_format == "bmp"||file_format == "dib"||file_format == "pbm"||file_format == "pgm"||file_format == "ppm"||file_format == "sr"||file_format == "ras"){
			img = imread(img_name, CV_LOAD_IMAGE_GRAYSCALE);
		} else if(file_format == "jpeg"||file_format == "jpg"||file_format == "jpe"||file_format == "jp2"||file_format == "png"||file_format == "tiff"||file_format == "tif"){
			img = imread(img_name, CV_LOAD_IMAGE_GRAYSCALE);
		} else if(file_format == "gif") {
			img = Mat(gif2ipl(img_name.c_str()), true);
		} else {
			fprintf (stderr, "'%s' is not a supported extension\n", file_format.c_str());
		}
		Mat cleaned_image;
		facerecogntion::clean_face(img, &cleaned_image)
		img_vector.push_back(cleaned_image);
		img_labels.push_back(atoi(label.c_str()));
		printf("LOADED\n");
	}
	printf("Length of img_vector: %d\tLength of img_labels: %d \n", img_vector.size(), img_labels.size());
	printf("Initiating Recognition Algorithm...\n");
	Ptr<FaceRecognizer> model = RECOGNITION_ALGO_BUILDER;
	printf("Training Recognition Algorithm...\n");
	model->train(img_vector, img_labels);
	printf("Saving Trained Recognition Algorithm to %s\n", trainfile.c_str());
	model->save(trainfile);
	printf("All Done\n");
}
