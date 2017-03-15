#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const string source_window = "Original";
const string fltrim_window = "Filtered";
const string binary_window = "Binary";
const string lplcim_window = "Laplace";
const int threshold_max_value = 255;
const int threshold_max_type = 4;
const int ddepth = CV_16S;
Mat source, fltrim, binary;
int threshold_value = threshold_max_value >> 1;
int threshold_type = threshold_max_type >> 1;

int main ();
void displaySingleImage (const Mat, const string, const int, const int);
void onSliderRolls (int, void *);

int main () {
  source = imread("image/.jpg");
  GaussianBlur(source, fltrim, Size(3, 3), 0);
  displaySingleImage(source, source_window, 10, 10);
  displaySingleImage(fltrim, fltrim_window, 450, 10);
  namedWindow(binary_window, CV_WINDOW_NORMAL);
  namedWindow(lplcim_window, CV_WINDOW_NORMAL);
  moveWindow(binary_window, 10, 360);
  moveWindow(lplcim_window, 450, 360);
  createTrackbar("Value", binary_window, &threshold_value, threshold_max_value, onSliderRolls);
  createTrackbar("Type", binary_window, &threshold_type, threshold_max_type, onSliderRolls);
  onSliderRolls(0, NULL);
  waitKey();
  return 0;
}

void displaySingleImage (const Mat image, const string window, const int winx, const int winy) {
  namedWindow(window, WINDOW_NORMAL);
  moveWindow(window, winx, winy);
  imshow(window, image);
}

void onSliderRolls (int, void *) {
  Mat lap, lap_abs;
  threshold(fltrim, binary, threshold_value, 255, threshold_type);
  Laplacian(binary, lap, ddepth, 3);
  convertScaleAbs(lap, lap_abs);
  imshow(binary_window, binary);
  imshow(lplcim_window, lap_abs);
}
