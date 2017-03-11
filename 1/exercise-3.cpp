#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const string window_name_source = "Scale";
const string window_name_scaled = "Show";
Mat source;

int main ();
void onSliderRolls (int, void *);
Mat doPyrDown (Mat, int = 1);

int main () {
  namedWindow(window_name_source);
  namedWindow(window_name_scaled);
  const int ratio_max = 3;
  int ratio = 0;
  source = imread("image/2x");
  imshow(window_name_source, source);
  moveWindow(window_name_source, 0, 0);
  moveWindow(window_name_scaled, source.cols, 0);
  createTrackbar("Pyramid Down Ratio", window_name_source, &ratio, ratio_max, onSliderRolls);
  onSliderRolls(ratio, NULL);
  waitKey();
  return 0;
}


void onSliderRolls (int ratio, void *) {
  imshow(window_name_scaled, doPyrDown(source, ratio));
}

Mat doPyrDown (Mat source, int ratio) {
  Mat result = source;
  Size size = source.size();
  while (ratio) {
    size.width >>= 1;
    size.height >>= 1;
    pyrDown(result, result, size);
    --ratio;
  }
  return result;
}
