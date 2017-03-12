#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main () {
  const string window_name = "Drawing";
  Mat canvas(500, 500, CV_8UC3);
  rectangle(canvas, Point(100, 100), Point(400, 400), Scalar(0, 255, 255), CV_FILLED);
  line(canvas, Point(100, 100), Point(400, 100), Scalar(0, 0, 200), 3, 4);
  line(canvas, Point(100, 200), Point(400, 200), Scalar(0, 200, 0), 5, 8);
  line(canvas, Point(100, 300), Point(400, 300), Scalar(200, 0, 0), 10, CV_AA);
  namedWindow(window_name);
  imshow(window_name, canvas);
  waitKey();
  return 0;
}
