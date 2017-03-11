#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const int slider_middle = 2;
const int slider_max = slider_middle << 1;
int slider_value = 2;

int main ();
Mat scale (Mat);
Mat doPyrDown (Mat, int = 1);
Mat doPyrUp (Mat, int = 1);

int main () {
  VideoCapture capture(0);
  const string window_name_source = "Original";
  const string window_name_scaled = "Scaled Image";
  namedWindow(window_name_source);
  namedWindow(window_name_scaled);
  moveWindow(window_name_source, 0, 0);
  moveWindow(window_name_scaled, 255, 12);
  createTrackbar("Zoom", window_name_source, &slider_value, slider_max);
  do {
    Mat sourceframe;
    capture >> sourceframe;
    Mat scaledframe = scale(sourceframe);
    imshow(window_name_source, sourceframe);
    imshow(window_name_scaled, scaledframe);
  } while (waitKey(33) < 0);
  return 0;
}

Mat scale (Mat source) {
  return slider_value < slider_middle
    ? doPyrDown(source, slider_middle - slider_value)
    : doPyrUp(source, slider_value - slider_middle)
  ;
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

Mat doPyrUp (Mat source, int ratio) {
  Mat result = source;
  Size size = source.size();
  while (ratio) {
    size.width <<= 1;
    size.height <<= 1;
    pyrUp(result, result, size);
    --ratio;
  }
  return result;
}
