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
/*Mat norm_0_255(InputArray _src) {
    Mat src = _src.getMat();
    // Create and return normalized image:
    Mat dst;
    switch(src.channels()) {
    case 1:
        cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
        break;
    case 3:
        cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
        break;
    default:
        src.copyTo(dst);
        break;
    }
    return dst;
}*/

}
