#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main () {
  Mat mat(512, 512, CV_8UC3);
  randu(mat, 0, 255);
  const auto title = "The Random Matrix";
  cout << title << ":\n" << mat << endl;
  namedWindow(title);
  imshow(title, mat);
  waitKey();
  return 0;
}
