#include <vector>
#include <cstdio>
#include <opencv/highgui.h>

using namespace cv;

int main () {
  namedWindow("window", CV_WINDOW_NORMAL);
  VideoCapture video("video/.mp4");
  for ( ; ; ) {
    Mat frame;
    video >> frame;
    if (frame.empty()) break;
    imshow("window", frame);
    if (waitKey(30) >= 0) break;
  }
  return EXIT_SUCCESS;
}
