#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main ();
Mat doPyrDown (Mat);

int main () {
  CvCapture * capture = cvCreateCameraCapture(0);
  IplImage * frame;
  const string window_name = "Demo";
  namedWindow(window_name);
  do {
    frame = cvQueryFrame(capture);
    if (frame) {
      Mat smallerframe = doPyrDown(Mat(frame));
      imshow(window_name, smallerframe);
    } else {
      break;
    }
  } while (waitKey(33) < 0);
  cvReleaseCapture(&capture);
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
