#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main () {
  const string window_name = "Drawing";
  Mat canvas(500, 500, CV_8UC3);
  ellipse(canvas, Point(400, 150), Size(200, 100), 30, 30 - 100, 30 + 200, Scalar(0, 0, 200), 3, 4);
  ellipse(canvas, Point(200, 200), Size(100, 100), 0, 0, 0 + 360, Scalar(0, 200, 0), 5, 8);
  ellipse(canvas, Point(200, 400), Size(100, 200), 100, 100 - 200, 100 + 100, Scalar(200, 0, 0), CV_FILLED, CV_AA);
  namedWindow(window_name);
  imshow(window_name, canvas);
  waitKey();
  return 0;
}
