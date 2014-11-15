/*
 * trainer.h
 *
 *  Created on: Nov 15, 2014
 *      Author: draringi
 */

#ifndef TRAINER_H_
#define TRAINER_H_

#define RECOGNITION_ALGO_BUILDER createLBPHFaceRecognizer()

#include <queue>
#include <string>

void buildTrainer(std::string trainfile, std::queue<std::string> img_names);


#endif /* TRAINER_H_ */
