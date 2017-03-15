/**
 * NOTE:
 * * Already did in ../1/alpha-with-trackbar.cpp
 **/

#include <string>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

const int alpha_max = 100;
Mat alpha_img, beta_img;
const string window_name = "Mix two images";

int main ();
void onSliderRolls (int, void *);

int main () {
  alpha_img = imread("image/alpha");
  beta_img = imread("image/beta");
  int alpha = 50;
  namedWindow(window_name, CV_WINDOW_NORMAL);
  createTrackbar("Alpha/Beta (%):", window_name, &alpha, alpha_max, onSliderRolls);
  onSliderRolls(alpha, NULL);
  waitKey();
  return 0;
}

void onSliderRolls (int alpha, void *) {
  cout << "Alpha: " << alpha << '%' << endl;
  const double actual_alpha = double(alpha) / alpha_max;
  const double actual_beta = 1.0f - actual_alpha;
  Mat mixed_img;
  addWeighted(alpha_img, actual_alpha, beta_img, actual_beta, 0.0f, mixed_img);
  imshow(window_name, mixed_img);
}
