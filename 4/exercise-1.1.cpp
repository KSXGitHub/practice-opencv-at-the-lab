#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main ();
void displaySingleImage (const Mat, const string, const int, const int);

int main () {
  Mat source = imread("image/.jpg");
  Mat graysc;
  cvtColor(source, graysc, CV_BGR2GRAY);
  displaySingleImage(source, "Original", 0, 0);
  displaySingleImage(graysc, "Grayscale", 350, 36);
  waitKey();
  return 0;
}

void displaySingleImage (const Mat image, const string window, const int winx, const int winy) {
  namedWindow(window, WINDOW_NORMAL);
  moveWindow(window, winx, winy);
  imshow(window, image);
}
