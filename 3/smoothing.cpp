#include <string>
#include <cstdlib>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>

#define CAPTION(caption) if (displayCaption(caption)) return 0
#define DISPLAY if (displayBlurred()) return 0
#define LOOP(i) for (int i = 1; i < MAX::KERNEL_LENGTH; i += 2)

using namespace std;
using namespace cv;

namespace DELAY {
  const int CAPTION = 1500;
  const int BLUR = 100;
}

namespace MAX {
  const int KERNEL_LENGTH = 31;
}

string window_name = "Smoothing Demonstration";
Mat source, target;

int main ();
bool displayCaption (string);
bool displayBlurred (int = DELAY::BLUR);

int main () {

  // Create window
  namedWindow(window_name, CV_WINDOW_NORMAL);

  // Load images
  source = imread("image/lena");

  // Original Image
  CAPTION("Original Image");
  target = source.clone();
  if (displayBlurred(DELAY::CAPTION)) return 0;

  // Homogeneous Blur
  CAPTION("Homogeneous Blur");
  LOOP(i) {
    blur(source, target, Size(i, i), Point(-1, -1));
    DISPLAY;
  }

  // Gaussian Blur
  CAPTION("Gaussian Blur");
  LOOP(i) {
    GaussianBlur(source, target, Size(i, i), 0, 0);
    DISPLAY;
  }

  // Median Blur
  CAPTION("Median Blur");
  LOOP(i) {
    medianBlur(source, target, i);
    DISPLAY;
  }

  // Bilateral Blur
  CAPTION("Bilateral Blur");
  LOOP(i) {
    bilateralFilter(source, target, i, i * 2, i / 2);
    DISPLAY;
  }

  // Finalization
  CAPTION("End");
  CAPTION("Press any key...");
  return 0;

}

bool displayCaption (string caption) {
  Mat image = Mat::zeros(source.size(), source.type());
  putText(image, caption, Point(source.cols >> 2, source.rows >> 1), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));
  imshow(window_name, image);
  return waitKey(DELAY::CAPTION) >= 0;
}

bool displayBlurred (int delay) {
  imshow(window_name, target);
  return waitKey(delay) >= 0;
}
