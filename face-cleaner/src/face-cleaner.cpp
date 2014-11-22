/*
 * face-cleaner.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#include "face-cleaner.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "load_file.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

namespace facerecognition {

Mat clean_face(Mat face, int recog) {
	CascadeClassifier filter;
	if (recog == 1) {
		filter.load( FACE_FILTER_ALT);
	} else {
		filter.load( FACE_FILTER);
	}
	vector<Rect> faces;
	Mat gray_face;
	if (face.channels() == 3) {
		cvtColor(face, gray_face, CV_BGR2GRAY);
	} else {
		face.copyTo(gray_face);
	}
	filter.detectMultiScale(gray_face, faces, 1.1, 2, 0, Size(0, 0));
	Rect roi;
	vector<Rect>::iterator it;
	for (it = faces.begin(); it != faces.end(); it++) {
		if (it->area() > roi.area()) {
			roi = (*it);
		}
	}
	// 40x40 gives 1600
	if (roi.area() < 1600) {
		if (recog != 1) {
			throw;
		}
		filter.load( FACE_PROFILE);
		filter.detectMultiScale(gray_face, faces, 1.1, 2, 0, Size(0, 0));
		for (it = faces.begin(); it != faces.end(); it++) {
			if (it->area() > roi.area()) {
				roi = (*it);
			}
		}
		if (roi.area() < 2000) {
			throw;
		}
	}
	Mat tmp(gray_face, roi);
	tmp.convertTo(tmp, CV_8UC3);
	equalizeHist(tmp, tmp);
	resize(tmp, gray_face, Size(150, 150));
	return gray_face.clone();

}

}

const char* clean_and_save(char* input, char* tmp_base, int recog) {
	Mat img = facerecognition::load_file(input);
	Mat output;
	try {
		output = facerecognition::clean_face(img, recog);
	} catch (...) {
		return NULL;
	}
	string output_file = TMP_FOLDER;
	output_file.append(tmp_base);
	output_file.append(".pgm");
	imwrite(output_file, output);
	printf("%s\n", output_file.c_str());
	return output_file.c_str();
}
