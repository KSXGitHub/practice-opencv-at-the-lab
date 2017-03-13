#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const string source_window = "Original";
const string binary_window = "Binary";
const string sblimg_window = "Sobel";
const int threshold_max_value = 255;
const int threshold_max_type = 4;
const int ddepth = CV_16S;
Mat source, binary, sblimg;
int threshold_value = threshold_max_value >> 1;
int threshold_type = threshold_max_type >> 1;

int main ();
void onSliderRolls (int, void *);

int main () {
  source = imread("image/.jpg");
  namedWindow(source_window, CV_WINDOW_NORMAL);
  namedWindow(binary_window, CV_WINDOW_NORMAL);
  namedWindow(sblimg_window, CV_WINDOW_NORMAL);
  moveWindow(source_window, 10, 10);
  moveWindow(binary_window, 10, 250);
  moveWindow(sblimg_window, 360, 10);
  createTrackbar("Value", binary_window, &threshold_value, threshold_max_value, onSliderRolls);
  createTrackbar("Type", binary_window, &threshold_type, threshold_max_type, onSliderRolls);
  imshow(source_window, source);
  onSliderRolls(0, NULL);
  waitKey();
  return 0;
}

void onSliderRolls (int, void *) {
  threshold(source, binary, threshold_value, 255, threshold_type);
  imshow(binary_window, binary);
  Mat grad_x, grad_y, abs_x, abs_y;
  Sobel(binary, grad_x, ddepth, 0, 1);
  Sobel(binary, grad_y, ddepth, 1, 0);
  convertScaleAbs(grad_x, abs_x);
  convertScaleAbs(grad_y, abs_y);
  addWeighted(abs_x, 0.5f, abs_y, 0.5f, 0, sblimg);
  imshow(sblimg_window, sblimg);
}
