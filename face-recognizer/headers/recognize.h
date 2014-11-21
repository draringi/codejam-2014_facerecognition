/*
 * recognize.h
 *
 *  Created on: Nov 16, 2014
 *      Author: draringi
 */

#ifndef RECOGNIZE_H_
#define RECOGNIZE_H_

#include <string>

#define RECOGNITION_ALGO_BUILDER createLBPHFaceRecognizer(3, 8, 8, 8, 90)

int determine_id(std::string img_name, std::string db_name);


#endif /* RECOGNIZE_H_ */
