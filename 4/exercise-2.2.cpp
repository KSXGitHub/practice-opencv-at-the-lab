#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const string source_window = "Original";
const string fltrim_window = "Filtered";
const string binary_window = "Binary";
const int threshold_max_value = 255;
const int threshold_max_type = 4;
Mat source, fltrim, binary;
int threshold_value = threshold_max_value >> 1;
int threshold_type = threshold_max_type >> 1;

int main ();
void onSliderRolls (int, void *);

int main () {
  source = imread("image/.jpg");
  GaussianBlur(source, fltrim, Size(3, 3), 0);
  namedWindow(source_window, CV_WINDOW_NORMAL);
  namedWindow(fltrim_window, CV_WINDOW_NORMAL);
  namedWindow(binary_window, CV_WINDOW_NORMAL);
  moveWindow(source_window, 10, 10);
  moveWindow(fltrim_window, 360, 10);
  moveWindow(binary_window, 10, 250);
  createTrackbar("Value", binary_window, &threshold_value, threshold_max_value, onSliderRolls);
  createTrackbar("Type", binary_window, &threshold_type, threshold_max_type, onSliderRolls);
  imshow(source_window, source);
  imshow(fltrim_window, fltrim);
  onSliderRolls(0, NULL);
  waitKey();
  return 0;
}

void onSliderRolls (int, void *) {
  threshold(fltrim, binary, threshold_value, 255, threshold_type);
  imshow(binary_window, binary);
}
