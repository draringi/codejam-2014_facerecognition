/*
 * trainer.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#include "trainer.h"
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "file_struct.h"

using namespace std;
using namespace cv;

void buildTrainer(string trainfile, queue<file_struct> img_names) {
	vector<Mat> img_vector;
	vector<int> img_labels;
	while (!img_names.empty()) {
		file_struct img_struct = img_names.front();
		img_names.pop();
		string img_name = img_struct.filename;
		Mat img;
		printf("Loading %s:\t", img_name.c_str());
		img = imread(img_name, CV_LOAD_IMAGE_GRAYSCALE);
		img_vector.push_back(img);
		img_labels.push_back(img_struct.label);
		printf("LOADED\n");
	}
	printf("Length of img_vector: %d\tLength of img_labels: %d \n",
			img_vector.size(), img_labels.size());
	printf("Initiating Recognition Algorithm...\n");
	Ptr<FaceRecognizer> model = RECOGNITION_ALGO_BUILDER;
	printf("Training Recognition Algorithm...\n");
	model->train(img_vector, img_labels);
	printf("Saving Trained Recognition Algorithm to %s\n", trainfile.c_str());
	model->save(trainfile);
	printf("All Done\n");
}
