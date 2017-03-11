#include <string>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

const string window_name = "Red Green Blue";
const int slider_min = 0x00;
const int slider_max = 0xFF;
int red = slider_min, green = slider_min, blue = slider_min;

int main ();
void onSliderRolls (int, void *);

int main () {
  namedWindow(window_name);
  createTrackbar("R", window_name, &red, slider_max, onSliderRolls);
  createTrackbar("G", window_name, &green, slider_max, onSliderRolls);
  createTrackbar("B", window_name, &blue, slider_max, onSliderRolls);
  onSliderRolls(0, NULL);
  waitKey(0);
  return 0;
}

void onSliderRolls (int, void *) {
  imshow(window_name, Mat(512, 512, CV_8UC3, Scalar(blue, green, red)));
}
