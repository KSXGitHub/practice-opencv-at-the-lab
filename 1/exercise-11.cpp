#include <string>
#include <cstdio>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main () {
  const string left_window = "Left Video";
  const string right_window = "Right Video";
  namedWindow(left_window, CV_WINDOW_NORMAL);
  namedWindow(right_window, CV_WINDOW_NORMAL);
  moveWindow(right_window, 300, 25);
  VideoCapture left_video("video/.mp4");
  VideoCapture right_video("video/.m4a");
  const int delay = 32;
  do {
    Mat left_frame, right_frame;
    left_video >> left_frame;
    right_video >> right_frame;
    const bool left_empty = left_frame.empty(), right_empty = right_frame.empty();
    if (!left_empty) imshow(left_window, left_frame);
    if (!right_empty) imshow(right_window, right_frame);
  } while (waitKey(delay) < 0);
  return EXIT_SUCCESS;
}