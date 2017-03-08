#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main () {
  Mat mat(3, 3, CV_8UC3, Scalar(255, 255, 255));
  cout << "The Matrix:\n" << mat << endl;
  cin.get();
  return 0;
}
