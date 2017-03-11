#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main () {
  namedWindow("window", CV_WINDOW_NORMAL);
  VideoCapture video("video/.mp4");
  const int delay = 1000.0f / video.get(CV_CAP_PROP_FPS);
  do {
    Mat frame;
    video >> frame;
    if (frame.empty()) break;
    imshow("window", frame);
    cout << "framerate = " << video.get(CV_CAP_PROP_FPS) << endl;
  } while (waitKey(delay) < 0);
  return EXIT_SUCCESS;
}
