#include <opencv/highgui.h>

int main () {
  cv::Mat image = cv::imread("image/alpha");
  cv::namedWindow("window");
  cv::imshow("window", image);
  cv::waitKey();
  return 0;
}

