#include <iostream>
#include <string>
#include <ctime>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main ();
Mat doPyrDown (Mat);

int main () {
  const string output_prefix = "output/exercise-2.frame-at-";
  const string output_suffix = ".jpg";
  VideoCapture capture(0);
  const string window_name = "Demo";
  namedWindow(window_name);
  do {
    Mat frame;
    capture >> frame;
    Mat smallerframe = doPyrDown(frame);
    imshow(window_name, smallerframe);
    imwrite(output_prefix + to_string(int(time(NULL))) + output_suffix, smallerframe);
  } while (waitKey(33) < 0);
  capture.release();
  return 0;
}

Mat doPyrDown (Mat source) {
  Mat result;
  Size size = source.size();
  size.width >>= 1;
  size.height >>= 1;
  pyrDown(source, result, size);
  return result;
}
