#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

const string source_window = "Original";
const string target_window = "Adjusted";
const int max_gain = 100;
const int max_bias = 100;
int gain = max_gain >> 1;
int bias = max_bias >> 1;
Mat source, target;

int main ();
void onSliderRolls (int, void *);

int main () {
  source = imread("image/.jpg");
  target = Mat(source.size(), source.type());
  onSliderRolls(0, NULL);
  namedWindow(source_window, WINDOW_NORMAL);
  namedWindow(target_window, WINDOW_NORMAL);
  moveWindow(source_window, 0, 0);
  moveWindow(target_window, 300, 25);
  imshow(source_window, source);
  createTrackbar("Brightness", target_window, &gain, max_gain, onSliderRolls);
  createTrackbar("Contrast", target_window, &bias, max_bias, onSliderRolls);
  onSliderRolls(0, NULL);
  waitKey();
  return 0;
}

void onSliderRolls (int, void *) {
  for (int x = 0; x != source.cols; ++x) {
    for (int y = 0; y != source.rows; ++y) {
      Vec3b & source_pixel = source.at<Vec3b>(y, x);
      Vec3b & target_pixel = target.at<Vec3b>(y, x);
      for (int i = 0; i != 3; ++i) {
        target_pixel[i] = saturate_cast<unsigned char>(0.01f * double(gain) * double(source_pixel[i]) + bias);
      }
    }
  }
  imshow(target_window, target);
}
