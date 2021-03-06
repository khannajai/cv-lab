// Lab-5 template file provided by Kaustubh Pathak
// Add your code in all places where it says "Fill-in".

#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"

using namespace std;
using namespace cv;

int main()
{

	//-- Localize the object
	std::vector<Point2f> srcPoints;
	std::vector<Point2f> dstPoints;

	// Example: Point V
	dstPoints.push_back(Point2f(0, 0)); srcPoints.push_back(Point2f(69, 354));
	// Fill-in:
	// Push all other points A, B, C,...,Z

	// Fill-in: use the OpenCV findHomography to compute the homography matrix H.
	// Take the third parameter as just 0, which means use regular method using all points. 
	

	cout << "The computed homography matrix size is: " << endl;
	cout << "rows: "<< H.rows << ", cols= "<< H.cols << endl;
	for (int i = 0; i < H.rows; ++i) {
		for (int j = 0; j < H.cols; ++j) {
			cout << H.at<float>(i, j) << ",\t";
		}
		cout << endl;
	}
	
	Mat Img = imread("donald_annotated_points.png" , 1);
	Mat Out_Img;

	// Fill-in:
	// Use the warpPerspective method of OpenCV to convert the input image Img to
	// the corrected image Out_Img of size 300x300 using H.

	imshow("Input", Img);
	imshow("Output", Out_Img);
	imwrite("donald_annotated_points_out.png", Out_Img);
	waitKey(0);

}

