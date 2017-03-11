#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

const int min_fpsx10 = 1;
VideoCapture video;
int delay;

int main ();
void onSliderRolls (int, void *);

int main () {
  const string window_name = "Video with FPS";
  const string slider_name = "Frame rate (10fps)";
  video = VideoCapture("video/.mp4");
  int fpsx10 = 10 * video.get(CV_CAP_PROP_FPS);
  namedWindow(window_name, WINDOW_NORMAL);
  createTrackbar(slider_name, window_name, &fpsx10, 2468, onSliderRolls);
  onSliderRolls(fpsx10, NULL);
  do {
    Mat frame;
    video >> frame;
    imshow(window_name, frame);
  } while (waitKey(delay) < 0);
  return 0;
}

void onSliderRolls (int fpsx10, void *) {
  delay = 10000 / (fpsx10 > min_fpsx10 ? fpsx10 : min_fpsx10);
}
