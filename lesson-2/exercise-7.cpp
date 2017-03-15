#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main () {
  const string window_name = "Drawing";
  Mat canvas(500, 500, CV_8UC3);
  rectangle(canvas, Point(200, 50), Point(300, 150), Scalar(0, 0, 200), 3, 4);
  rectangle(canvas, Point(200, 200), Point(300, 300), Scalar(0, 200, 0), 5, 8);
  circle(canvas, Point(250, 250), 50, Scalar(0, 200, 0), 8, 8);
  rectangle(canvas, Point(200, 350), Point(300, 450), Scalar(200, 0, 0), CV_FILLED, CV_AA);
  namedWindow(window_name);
  imshow(window_name, canvas);
  waitKey();
  return 0;
}
