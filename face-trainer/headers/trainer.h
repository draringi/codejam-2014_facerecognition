/*
 * trainer.h
 *
 *  Created on: Nov 15, 2014
 *      Author: draringi
 */

#ifndef TRAINER_H_
#define TRAINER_H_

#define RECOGNITION_ALGO_BUILDER createFisherFaceRecognizer()

#include <queue>
#include <string>
#include "file_struct.h"

void buildTrainer(std::string trainfile, std::queue<file_struct> img_names);


#endif /* TRAINER_H_ */
