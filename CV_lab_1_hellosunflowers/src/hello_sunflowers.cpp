#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("usage: DisplayImage.out <Image_Path>\n");
		return -1;
	}

	Mat image;
	image = imread(argv[1], 1);
	
	if (!image.data)
	{
		printf("No image data \n");
		return -1;
	}
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);
	waitKey(0);
	
	Mat channels[3];
	cv::split(image,channels);  // planes[2] is the red channel
	Mat redimage;
	redimage=channels[2];
	namedWindow("Display Red Image", WINDOW_AUTOSIZE);
	imshow("Display Red Image",redimage);
	waitKey(0);
	namedWindow("Display Green Image", WINDOW_AUTOSIZE);
	imshow("Display Green Image",channels[1]);
	waitKey(0);
	

	
	// Lab 21.9.: Now add code to display the red-part of the image as a gray-scale image!

	return 0;
}