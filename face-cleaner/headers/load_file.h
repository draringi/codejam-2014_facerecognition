/*
 * load_file.h
 *
 *  Created on: Nov 15, 2014
 *      Author: draringi
 */

#ifndef LOAD_FILE_H_
#define LOAD_FILE_H_

#include <opencv2/core/core.hpp>
#include <string>

using namespace std;

namespace facerecognition {
cv::Mat load_file(char* filename);
}
#endif /* LOAD_FILE_H_ */
