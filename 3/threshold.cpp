#include <string>
#include <cstdlib>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

auto threshold_value = 0;
auto threshold_type = 3;
const auto max_value = 255;
const auto max_type = 4;
const auto max_bin_value = 255;

Mat source, target, gray;
const string window_name = "Threshold Demostration";
const string trackbar_type = ""
  "Type:\n"
  "0. Binary\n"
  "1. Inverted Binary\n"
  "2. Truncate\n"
  "3. To Zero\n"
  "4. To Inverted Zero";
const string trackbar_value = "Value";

int main ();
void demo (int, void *);

int main () {
  source = imread("bottles");
  cvtColor(source, gray, COLOR_RGB2GRAY);
  namedWindow(window_name);
  createTrackbar(trackbar_type, window_name, &threshold_type, max_type, demo);
  createTrackbar(trackbar_value, window_name, &threshold_value, max_value, demo);
  demo(0, NULL);
  while (waitKey(20) < 0) {}
  return 0;
}

void demo (int, void *) {
  threshold(gray, target, threshold_value, max_bin_value, threshold_type);
  imshow(window_name, target);
}
