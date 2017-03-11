#include <vector>
#include <cstdio>
#include <opencv/highgui.h>

using namespace cv;

int main () {
  namedWindow("window", CV_WINDOW_NORMAL);
  VideoCapture video("video/.mp4");
  do {
    Mat frame;
    video >> frame;
    if (frame.empty()) break;
    imshow("window", frame);
  } while (waitKey(30) < 0);
  return EXIT_SUCCESS;
}
