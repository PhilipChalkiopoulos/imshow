/*
 * imshow.cpp
 *
 *  Created on: Dec 14, 2018
 *      Author: ellabuser
 */

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/core.hpp>
#include "fbdraw.h"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	Mat image;
	dev_fb fb;
	fb_init(&fb);

	image = imread("upatras.png", CV_LOAD_IMAGE_COLOR);   // Read the file

	if(! image.data )                              // Check for invalid input
	{
		cout <<  "Could not open or find the image" << std::endl ;
		return -1;
	}

	int channels = image.channels();
	int nRows = image.rows;
	int nCols = image.cols * channels;
	int i,j,x,y;
	uchar r,g,b;
	for( i = 0; i < nRows; ++i)
	{
		for ( j = 0; j < nCols; j=j+3)
		{
			x = i ;
			y = j/3 ;

			r = image.at<char>(i,j);
			g = image.at<char>(i,j+1);
			b = image.at<char>(i,j+2);
			//printf("[%d][%d],%d,%d,%d\n",y,x,point,point+1,point+2);
			fb_drawPixel(&fb,y,x+350,b,g,r); //if we want offset of the image x+ y+
		}
	}
	return 0;
}
