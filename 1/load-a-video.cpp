#include <vector>
#include <cstdio>
#include <opencv/highgui.h>

using namespace cv;

int main () {
  namedWindow("window");
  VideoCapture video("video/.mp4");
  for ( ; ; ) {
    Mat frame;
    video >> frame;
    imshow("window", frame);
    if (waitKey(30) >= 0) break;
  }
  return EXIT_SUCCESS;
}
