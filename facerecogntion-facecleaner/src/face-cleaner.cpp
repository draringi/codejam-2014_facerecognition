/*
 * face-cleaner.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#include "facerecogntion/face-cleaner.h"
#include <vector>
#include <stdio.h>

using namespace cv;
using namespace std;

namespace facerecogntion{

Mat clean_face(Mat face){
	CascadeClassifier filter;
	filter.load( FACE_FILTER );
	vector<Rect> faces;
	Mat gray_face;
	cvtColor( face, gray_face, CV_BGR2GRAY );
	gray_face.convertTo(gray_face, CV_8UC1);
	equalizeHist( gray_face, gray_face );
	filter.detectMultiScale( gray_face, faces, 1.1, 2, 0, Size(100, 100) );
	Rect roi;
	vector<Rect>::iterator it;
	for(it=faces.begin(); it != faces.end(); it++){
		if(it->area() > roi.area()){
			roi = (*it);
		}
	}
	Mat tmp;
	gray_face(roi).convertTo(tmp, CV_8UC1);
	equalizeHist( tmp, tmp );
	return tmp;

}

}
