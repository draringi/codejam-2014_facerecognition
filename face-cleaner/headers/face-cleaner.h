/*
 * face-cleaner.h
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#ifndef FACE_CLEANER_H_
#define FACE_CLEANER_H_

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define FACE_FILTER "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml"
#define TMP_FOLDER "/tmp/"

namespace facerecognition {
cv::Mat clean_face(cv::Mat face);
}

const char* clean_and_save(char* input, char* tmp_base);

#endif /* FACE_CLEANER_H_ */
