/*
 * load_gif.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: Michael Williams
 */

#include <opencv/cv.h>
#include <FreeImage.h>
#include "load_gif.h"

IplImage* gif2ipl(const char* filename) {
	FreeImage_Initialise();         //load the FreeImage function lib
	FREE_IMAGE_FORMAT fif = FIF_GIF;
	FIBITMAP* fiBmp = FreeImage_Load(fif, filename, GIF_DEFAULT);

	int width = FreeImage_GetWidth(fiBmp);
	;
	int height = FreeImage_GetHeight(fiBmp);

	RGBQUAD* ptrPalette = FreeImage_GetPalette(fiBmp);

	BYTE intens;
	BYTE* pIntensity = &intens;

	IplImage* iplImg = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);

	iplImg->origin = 1; //should set to 1-top-left structure(Windows bitmap style)

	for (int i = 0; i < height; i++) {
		char* ptrImgDataPerLine = iplImg->imageData + i * iplImg->widthStep;

		for (int j = 0; j < width; j++) {
			//get the pixel index
			FreeImage_GetPixelIndex(fiBmp, j, i, pIntensity);

			ptrImgDataPerLine[3 * j] = ptrPalette[intens].rgbBlue;
			ptrImgDataPerLine[3 * j + 1] = ptrPalette[intens].rgbGreen;
			ptrImgDataPerLine[3 * j + 2] = ptrPalette[intens].rgbRed;
		}
	}

	FreeImage_Unload(fiBmp);
	FreeImage_DeInitialise();

	return iplImg;
}
