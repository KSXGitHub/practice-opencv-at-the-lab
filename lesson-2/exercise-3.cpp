#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main ();
void displaySingleImage (const Mat, const string, const int, const int);

int main () {
  Mat source = imread("image/.jpg");
  Mat target;
  Mat kernel = (Mat_<char>(3, 3) << 0, 1, 0, 1, -4, 1, 0, 1, 0);
  filter2D(source, target, source.depth(), kernel);
  Scalar s255(255);
  target.row(0).setTo(s255);
  target.row(1).setTo(s255);
  target.row(target.rows - 1).setTo(s255);
  target.row(target.rows - 2).setTo(s255);
  target.col(0).setTo(s255);
  target.col(1).setTo(s255);
  target.col(target.cols - 1).setTo(s255);
  target.col(target.cols - 2).setTo(s255);
  displaySingleImage(source, "Original", 0, 0);
  displaySingleImage(target, "Filtered", 357, 25);
  waitKey();
  return 0;
}

void displaySingleImage (const Mat image, const string window, const int winx, const int winy) {
  namedWindow(window, CV_WINDOW_NORMAL);
  moveWindow(window, winx, winy);
  imshow(window, image);
}
