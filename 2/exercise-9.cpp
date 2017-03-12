#include <string>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main ();
void displaySingleImage (const Mat, const string, const int, const int);

int main () {
  Mat stroke(500, 500, CV_8U);
  Mat filled(500, 500, CV_8U);
  const int count = 4;
  Point poly[1][count];
  poly[0][0] = Point(215, 220);
  poly[0][1] = Point(460, 255);
  poly[0][2] = Point(466, 450);
  poly[0][3] = Point(235, 465);
  const Point * ppt [] = {poly[0]};
  int npt [] = {count};
  polylines(stroke, ppt, npt, 1, true, Scalar(255));
  fillPoly(filled, ppt, npt, 1, Scalar(255));
  displaySingleImage(stroke, "Stroke", 0, 0);
  displaySingleImage(filled, "Filled", 300, 36);
  waitKey();
  return 0;
}

void displaySingleImage (const Mat image, const string window, const int winx, const int winy) {
  namedWindow(window);
  moveWindow(window, winx, winy);
  imshow(window, image);
}
