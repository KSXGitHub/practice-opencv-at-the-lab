#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const string window_name = "Hough Circle Detection";
const string canny_threshold_trackbar_name = "Canny Threshold";
const string accumulator_threshold_trackbar_name = "Accumulator Threshold";
const int canny_threshold_initial_value = 200;
const int accumulator_threshold_initial_value = 50;
const int max_accumulator_threshold = 200;
const int max_canny_threshold = 255;

int main ();
void houghDetect (const Mat &, const Mat &, int canny_threshold, int accumulator_threshold);

int main () {

  // Import
  int source = imread("image/rgb");
  
  // Create gray image
  Mat gray;
  cvtColor(source, gray, CV_RGB2GRAY);

  // Reduce the noise
  GaussianBlur(gray, gray, Size(9, 9), 2, 2);

  // Graphical User Interface
  int canny_threshold = canny_threshold_initial_value;
  int accumulator_threshold = accumulator_threshold_initial_value;
  namedWindow(window_name, CV_WINDOW_NORMAL);
  createTrackbar(canny_threshold_trackbar_name, window_name, &canny_threshold, max_canny_threshold);

  return 0;

}

