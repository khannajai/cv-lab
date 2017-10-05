#include <iostream>
#include <cmath>
#include <algorithm>
#include "hsv_hue_histogram.hh"

using namespace hsv;
using namespace boost;
using namespace std;
using namespace cv;

HsvHueHistogram::HsvHueHistogram(unsigned int nr_bins_h): _nr_samples(0){
	_histSize[0]= int(nr_bins_h);

	_h_ranges[0]= 0.0;
	_h_ranges[1]= 200.0 + 0.01;

}

void HsvHueHistogram::normalize(void){
	if (_nr_samples == 0) return;
	for (int i_h= 0; i_h < get_nr_bins_h(); ++i_h){
		_hist.at<float>(i_h) /= float(_nr_samples);
	}
		
}

void changeHueValues(Mat _color_hsv, float blackThresh, float whiteThresh)
{
	//iterate through _color_hsv
	MatIterator_<Vec3b> it = _color_hsv.begin<Vec3b>();
	MatIterator_<Vec3b> it_end = _color_hsv.end<Vec3b>();
	for (;it!=it_end;it++)
	{
		Vec3b& pixel =*it;
		//change the hue of a white pixel to 190
		if (pixel[1]<whiteThresh)
		{
			pixel[0]=190.0;
		}

		//change the hue of a black pixel to 200
		if (pixel[2]<blackThresh)
		{
			pixel[1]=200.0;
		}
	}
}

bool HsvHueHistogram::load(const Mat& color_img, const Mat& mask, bool accumulate){
	if (!accumulate){
		_nr_samples= 0;
	}

	_nr_samples += color_img.total();

	Mat color_img_float(color_img.size(), CV_32FC3);
	color_img.convertTo(color_img_float, CV_32F, 1.0/255.0); // Each channel BGR is between 0.0 and 1.0 now

	_color_hsv.create(color_img_float.size(), CV_32FC3); // The destination should be preallocated.

	// Read the documentation of cvtColor:
	// http://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#cvtcolor
	cvtColor(color_img_float, _color_hsv, CV_BGR2HSV);

	float blackThresh=20;
	float whiteThresh=20;

	changeHueValues(_color_hsv, blackThresh, whiteThresh);
	
	int channels[] = {0};
	const float* ranges[]= {_h_ranges};

	// Read the documentation at:
    // http://docs.opencv.org/2.4/modules/imgproc/doc/histograms.html
	calcHist( &_color_hsv, 1, channels,  mask /* Mat() if no mask */,
			_hist, 1, _histSize, ranges, true, accumulate);

	// cv::normalize() does not work for dim > 3.
	// cv::normalize( _hist, _normailzed_hist, 0, 1, cv::NORM_MINMAX, -1, Mat());
	// Look at: http://opencv.willowgarage.com/documentation/cpp/basic_structures.html
	// void normalizeColorHist(MatND& hist)
	// cout<< "\t normalized color histogram"<< endl;
	// For CV_COMP_BHATTACHARYYA, normalization is not needed.

	// Explicitly normalize, so that the hist bins add to unity.
	if (!accumulate){
		normalize();
	}

	return true;
}

bool HsvHueHistogram::load(const std::string& image_path_name, bool accumulate){
	Mat color_img= imread(image_path_name.c_str());
	if(!color_img.data){
		std::cerr<< "could not open "<< image_path_name<< endl;
		return false;
	}

	return load(color_img, Mat(), accumulate);
}

double HsvHueHistogram::compare(const HsvHueHistogram& other) const{
	double result= 0.0;
	result= cv::compareHist(_hist, other._hist, CV_COMP_BHATTACHARYYA);
	return result;
}