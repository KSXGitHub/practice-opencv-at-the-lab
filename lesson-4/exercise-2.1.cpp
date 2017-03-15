#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const string source_window = "Original";
const string fltrim_window = "Filtered";
const string graysc_window = "Grayscale";

int main ();
void displaySingleImage (const Mat, const string, const int, const int);

int main () {
  Mat source = imread("image/.jpg");
  Mat fltrim, graysc;
  GaussianBlur(source, fltrim, Size(3, 3), 0);
  cvtColor(fltrim, graysc, CV_BGR2GRAY);
  displaySingleImage(source, source_window, 20, 20);
  displaySingleImage(fltrim, fltrim_window, 20, 360);
  displaySingleImage(graysc, graysc_window, 450, 20);
  waitKey();
  return 0;
}

void displaySingleImage (const Mat image, const string window, const int winx, const int winy) {
  namedWindow(window, WINDOW_NORMAL);
  moveWindow(window, winx, winy);
  imshow(window, image);
}
