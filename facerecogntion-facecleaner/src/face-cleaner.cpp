/*
 * face-cleaner.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#include "face-cleaner.h"
#include <vector>
#include <stdio.h>
#include "load_file.h"
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

namespace facerecognition{

Mat clean_face(Mat face){
	CascadeClassifier filter;
	filter.load( FACE_FILTER );
	vector<Rect> faces;
	Mat gray_face;
	if(face.channels()==3){
		cvtColor( face, gray_face, CV_BGR2GRAY );
	} else {
		face.copyTo(gray_face);
	}
	filter.detectMultiScale( gray_face, faces, 1.1, 2, 0, Size(0, 0) );
	Rect roi;
	vector<Rect>::iterator it;
	for(it=faces.begin(); it != faces.end(); it++){
		if(it->area() > roi.area()){
			roi = (*it);
		}
	}
	Mat tmp = gray_face(roi);
	tmp.convertTo(tmp, CV_8UC3);
	equalizeHist( tmp, tmp );
	tmp.copyTo(gray_face);
	return gray_face.clone();

}

}

const char* clean_and_save(char* input, char* tmp_base){
	Mat img = facerecognition::load_file(input);
	printf("INPUT: %d\n", img.total);
	output = facerecognition::clean_face(img);
	printf("INPUT: %d\n", output.total);
	string output_file = TMP_FOLDER;
	output_file.append(tmp_base);
	output_file.append(".png");
	imwrite(output_file, output);
	return output_file.c_str();
}
