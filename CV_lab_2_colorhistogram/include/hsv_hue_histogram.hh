#ifndef __HSV_COLOR_HISTOGRAM
#define __HSV_COLOR_HISTOGRAM

#include <vector>
#include <ostream>
#include <string>
//#include <Eigen/Dense>
#include <boost/shared_ptr.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace hsv {
    
class HsvHueHistogram{
    public:
        /**
		 * @param nr_bins_h h range is [, ]
		 * @param nr_bins_s s range is [, ]
		 * @param nr_bins_v v range is [, ]
		 */
		HsvHueHistogram(unsigned int nr_bins_h=20);
		
		/* The normalization constant is nr_samples().
		 */
	   	void normalize(void);
		
		
        /** loads an image and computes its (normalized) histogram.
		 * Normalization is only done if accumulate= false
		 * @param image_path_name fully qualified path.
		 * @param accumulate if true, the current histogram will not be reset but updated.
		 * You should not load with accumulate=true after normalizing.
		 * @return if successful.
		 */
        
        bool load(const std::string& image_path_name, bool accumulate= false);
        
		
		/**
		 * Loads from the image using the mask. Normalization is only done if accumulate= false.
		 * @param image of encoding CV_8UC3
		 * @param mask
		 * @param accumulate
		 * @return
		 */
        bool load(const cv::Mat& image, const cv::Mat& mask, bool accumulate= false);

        int nr_samples(void){
			return _nr_samples;
		}

		
		/** Compare two histograms by using the Bhattacharyya distance.
		 * Note: the object other should have been created using the same constructor parameter.
		 */
		double compare(const HsvHueHistogram& other) const;

		/**
		 * @return the histogram is a 3D array of size nr_bins_l*nr_bins_u*nr_bins_v.
		 * In OpenCV MatND is typedefed to just Mat.
		 * Its elements can be accessed as hist(l_bin,u_bin,v_bin).
		 */
		const cv::MatND& get_histogram(void) const{
			return _hist;
		}

		int get_nr_bins_h(void) const{
			return _histSize[0];
		}

		int get_nr_of_bins(void) const{
			return _histSize[0];
		}

		/**
		 * @param v will be cleared and filled with the histogram values in the nested order L(u(v))
		 */
		// void get_histogram_as_vector(Eigen::VectorXf& v) const;

		/**
		 * The opposite of get_histogram_as_vector
		 */
		//void set_histogram_from_vector(const Eigen::VectorXf& v,
		//		unsigned int nr_bins_l, unsigned int nr_bins_u, unsigned int nr_bins_v);

    protected:
		int _histSize[1];
		float _h_ranges[2];
		cv::MatND _hist; ///< This will be normalized (sum=1) in the load function.
		int _nr_samples; //normalisation constant; total number of samples
		cv::Mat _color_hsv; // cached from the last computation



    
    }; 
} 


#endif