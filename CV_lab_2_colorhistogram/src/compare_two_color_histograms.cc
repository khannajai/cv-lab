
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include "luv_color_histogram.hh"
#include "hsv_hue_histogram.hh"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace jir;
using namespace boost;
using namespace boost::filesystem;
using namespace cv;
using namespace hsv;

bool verify_folder(path& p){
	if (!exists(p)){
		cerr<< "Folder "<< p.c_str()<< " does not exist"<< endl;
		return false;
	}
	if (!(is_directory(p))){
		cerr<< p.c_str()<< " is not a folder."<< endl;
		return false;
	}
	return true;
}

void load(path& p, vector<LuvColorHistogram>& hist_vector, vector<string>& path_vector){
	directory_iterator it(p);
	directory_iterator end_it;
	for (it;it!=end_it;it++)
	{
		path imagePath(it->path());
		LuvColorHistogram hist;
		if (hist.load(imagePath.c_str()))
		{
			hist_vector.push_back(hist);
			path_vector.push_back(imagePath.c_str());
		}
	}
}

void load(path& p, vector<HsvHueHistogram>& hist_vector, vector<string>& path_vector){
	directory_iterator it(p);
	directory_iterator end_it;
	for (it;it!=end_it;it++)
	{
		path imagePath(it->path());
		HsvHueHistogram hist;
		if (hist.load(imagePath.c_str()))
		{
			hist_vector.push_back(hist);
			path_vector.push_back(imagePath.c_str());
		}
	}
}

void compare_hist_vectors(const vector<LuvColorHistogram>& h1, const vector<LuvColorHistogram>& h2, vector<string>& paths1, vector<string> paths2){

	vector<LuvColorHistogram>::const_iterator it1= h1.begin();
	int c1(0);
	for (; it1 != h1.end(); ++it1){
		vector<LuvColorHistogram>::const_iterator it2= h2.begin();
		int c2(0);
		double min1=1;
		int min1_index;
		double min2=1;
		int min2_index;
		for (; it2 != h2.end(); ++it2) {
			cout << c1 << "<->" << c2 << " : " << it1->compare(*it2) << endl;
			double distance=it1->compare(*it2);
			if (distance<min1)
			{
				min1=distance;
				min1_index=c2;
			}
			else if(distance>min1 && distance<min2)
			{
				min2=distance;
				min2_index=c2;
			}			


			++c2;
		}
		Mat imageTrain;
		imageTrain = imread(paths1[c1],1);
		namedWindow("Display Image", WINDOW_AUTOSIZE);
		imshow("Display Image", imageTrain);
		waitKey(0);
		Mat imageTest1;
		imageTest1= imread(paths2[min1_index],1);
		namedWindow("Display Image", WINDOW_AUTOSIZE);
		imshow("Display Image", imageTest1);
		waitKey(0);
		Mat imageTest2;
		imageTest2=imread(paths2[min2_index],1);
		namedWindow("Display Image", WINDOW_AUTOSIZE);
		imshow("Display Image", imageTest2);
		waitKey(0);
		

		
		++c1;
	}
		// Fill-in: iterate over h2 and compare it1 and it2
                // For each histogram in h1, find the closest two in h2.
                // Ideally, you should also show the corresponding images, or at least the file-names for quick verification.
		
	
}

void compare_hist_vectors(const vector<HsvHueHistogram>& h1, const vector<HsvHueHistogram>& h2, vector<string>& paths1, vector<string> paths2){
	
		vector<HsvHueHistogram>::const_iterator it1= h1.begin();
		int c1(0);
		for (; it1 != h1.end(); ++it1){
			vector<HsvHueHistogram>::const_iterator it2= h2.begin();
			int c2(0);
			double min1=1;
			int min1_index;
			double min2=1;
			int min2_index;
			for (; it2 != h2.end(); ++it2) {
				cout << c1 << "<->" << c2 << " : " << it1->compare(*it2) << endl;
				double distance=it1->compare(*it2);
				if (distance<min1)
				{
					min1=distance;
					min1_index=c2;
				}
				else if(distance>min1 && distance<min2)
				{
					min2=distance;
					min2_index=c2;
				}			
	
	
				++c2;
			}
			Mat imageTrain;
			imageTrain = imread(paths1[c1],1);
			namedWindow("Display Image", WINDOW_AUTOSIZE);
			imshow("Display Image", imageTrain);
			waitKey(0);
			Mat imageTest1;
			imageTest1= imread(paths2[min1_index],1);
			namedWindow("Display Image", WINDOW_AUTOSIZE);
			imshow("Display Image", imageTest1);
			waitKey(0);
			Mat imageTest2;
			imageTest2=imread(paths2[min2_index],1);
			namedWindow("Display Image", WINDOW_AUTOSIZE);
			imshow("Display Image", imageTest2);
			waitKey(0);
			
	
			
			++c1;
		}
			// Fill-in: iterate over h2 and compare it1 and it2
					// For each histogram in h1, find the closest two in h2.
					// Ideally, you should also show the corresponding images, or at least the file-names for quick verification.
			
		
	}



int main(int argc, const char* argv[]) {

	if (argc < 3){
		cerr<< "Usage: \n"<< argv[0]<< " [training folder name] [test folder name]"<< endl;
		return -1;
	}

	path p_train (argv[1]);
	if (!verify_folder(p_train)) return -1;

	path p_test(argv[2]);
	if (!verify_folder(p_test)) return -1;
	
	vector<string> paths_train;
	vector<string> paths_test;
	/*
	vector<LuvColorHistogram> histograms_train_luv;
	vector<LuvColorHistogram> histograms_test_luv;
	*/
	vector<HsvHueHistogram> histograms_train_hsv;
	vector<HsvHueHistogram> histograms_test_hsv;

	/*
	load(p_train, histograms_train_luv, paths_train);
	cout<< "*** loaded "<< histograms_train_luv.size()<< "luv training samples."<< endl;

	load(p_test, histograms_test_luv, paths_test);
	cout << "*** loaded " << histograms_test_luv.size() << "luv testing samples." << endl;

	cout<< "Comparing luv color histograms"<< endl;
	compare_hist_vectors(histograms_train_luv, histograms_test_luv, paths_train, paths_test);
	*/
	load(p_train, histograms_train_hsv, paths_train);
	cout<< "*** loaded "<< histograms_train_hsv.size()<< "hsv training samples."<< endl;

	load(p_test, histograms_test_hsv, paths_test);
	cout << "*** loaded " << histograms_test_hsv.size() << "hsv testing samples." << endl;

	cout<< "Comparing hsv color histograms"<< endl;
	compare_hist_vectors(histograms_train_hsv, histograms_test_hsv, paths_train, paths_test);


}
