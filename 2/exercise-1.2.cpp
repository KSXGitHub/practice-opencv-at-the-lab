#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main () {
  Mat mat(5, 5, CV_8UC1);
  randu(mat, 0, 200);
  const auto title = "The Random Matrix";
  cout << title << ":\n" << mat << endl;
  cin.get();
  return 0;
}
