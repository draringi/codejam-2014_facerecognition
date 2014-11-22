/*
 * trainer.h
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#ifndef TRAINER_H_
#define TRAINER_H_

#define RECOGNITION_ALGO_BUILDER createLBPHFaceRecognizer(2, 8, 8, 8, 105)

#include <queue>
#include <string>
#include "file_struct.h"

void buildTrainer(std::string trainfile, std::queue<file_struct> img_names);

#endif /* TRAINER_H_ */
