/*
 * recognize.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: Michael Williams
 */

#include "recognize.h"
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int determine_id(string img_name, string db_name){
	Ptr<FaceRecognizer> db = RECOGNITION_ALGO_BUILDER;
	db->load(db_name);
	Mat image = imread(img_name, 0);
	return db->predict(image);
}


