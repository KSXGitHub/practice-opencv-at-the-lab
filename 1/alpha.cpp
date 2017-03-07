#include <iostream>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

int main () {
  double alpha, beta;
  auto srcalpha = imread("image/alpha");
  auto srcbeta = imread("image/beta");
  cout << "Enter alpha: ";
  cin >> alpha;
  if (alpha < 0 || alpha > 1) {
    cout << "Alpha must be in range of [0; 1]\n";
    return 1;
  }
  beta = 1 - alpha;
  namedWindow("window", WINDOW_AUTOSIZE);
  Mat dst;
  addWeighted(srcalpha, alpha, srcbeta, beta, 0, dst);
  imshow("window", dst);
  waitKey(0);
  return 0;
}