#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main ();
void displaySingleImage (const Mat, const string, const int, const int);

int main () {
  Mat source = imread("image/.jpeg");
  Mat target(source.size(), source.type());
  Mat graysc(target.size(), CV_8UC1);
  cvtColor(source, graysc, CV_RGB2GRAY);
  int max_gray_x = 0, max_gray_y = 0;
  for (int i = 0; i != target.cols; ++i) {
    for (int j = 0; j != target.rows; ++j) {
      Vec3b & target_rgb = target.at<Vec3b>(j, i);
      if (i > 50 || j > 50) {
        target_rgb = source.at<Vec3b>(j, i);
      } else if (i <= 20 && j <= 20) {
        target_rgb = source.at<Vec3b>(i + 100, j + 100);
      }
      if (graysc.at<unsigned char>(max_gray_y, max_gray_x) < graysc.at<unsigned char>(j, i)) {
        max_gray_x = i;
        max_gray_y = j;
      }
    }
  }
  cout
    << "Highest grayscale pixel is at ("
    << max_gray_x << ", " << max_gray_y
    << ") and equal to " << source.at<Vec3b>(max_gray_y, max_gray_x)
    << endl
  ;
  target.at<Vec3b>(max_gray_y, max_gray_x) = Vec3b(0, 0, 0);
  displaySingleImage(source, "Original", 100, 100);
  displaySingleImage(graysc, "Grayscaled", 100, 450);
  displaySingleImage(target, "Processed", 512, 100);
  waitKey();
  return 0;
}

void displaySingleImage (const Mat image, const string window, const int winx, const int winy) {
  namedWindow(window, CV_WINDOW_NORMAL);
  moveWindow(window, winx, winy);
  imshow(window, image);
}
