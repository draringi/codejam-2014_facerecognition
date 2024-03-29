/*
 * load_file.h
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#ifndef LOAD_FILE_H_
#define LOAD_FILE_H_

#include <opencv2/core/core.hpp>
#include <string>

using namespace std;
namespace facerecognition {
bool supported(string ext);
cv::Mat load_file(char* filename);
}
#endif /* LOAD_FILE_H_ */
