#include <opencv/highgui.h>

int main () {
  auto image = cv::imread("image/alpha");
  cv::namedWindow("window");
  cv::imshow("window", image);
  cv::waitKey();
  return 0;
}

