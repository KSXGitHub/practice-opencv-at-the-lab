#include <cstdlib>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat source, erosion_target, dilation_target;
auto erosion_elem = 0;
auto erosion_size = 0;
auto dilation_elem = 0;
auto dilation_size = 0;
const auto max_elem = 2;
const auto max_size = 21;
const int morp_elements [] = {MORPH_RECT, MORPH_CROSS, MORPH_ELLIPSE};

int main ();
void erosion (int, void *);
void dilation (int, void *);
void morp (int, int, Mat &, string, bool);

int main () {
  source = imread("lena");
  namedWindow("erosion");
  namedWindow("dilation");
  moveWindow("dilation", source.cols, 0);
  createTrackbar("Element\n- 0: Rect\n- 1: Cross\n- 2: Ellipse", "erosion", &erosion_elem, max_elem, erosion);
  createTrackbar("Kernel Size\n (2n + 1)", "erosion", &erosion_size, max_size, erosion);
  createTrackbar("Element\n- 0: Rect\n- 1: Cross\n- 2: Ellipse", "dilation", &dilation_elem, max_elem, dilation);
  createTrackbar("Kernel Size\n (2n + 1)", "dilation", &dilation_size, max_size, dilation);
  erosion(0, NULL);
  dilation(0, NULL);
  waitKey(0);
  return 0;
}

void erosion (int, void *) {
  morp(erosion_elem, erosion_size, erosion_target, "erosion", true);
}

void dilation (int, void *) {
  morp(dilation_elem, dilation_size, dilation_target, "dilation", false);
}

void morp (int element_index, int isize, Mat & target, string window_name, bool method) {
  auto type = morp_elements[element_index];
  auto size = 2 * isize + 1;
  auto element = getStructuringElement(type, Size(size, size), Point(isize, isize));
  if (method) {
    erode(source, target, element);
  } else {
    dilate(source, target, element);
  }
  imshow(window_name, target);
}
