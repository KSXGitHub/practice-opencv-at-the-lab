#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main () {
  Mat mat(500, 500, CV_8UC1, Scalar::all(0));
  const string title = "Black";
  namedWindow(title);
  imshow(title, mat);
  waitKey();
  return 0;
}
