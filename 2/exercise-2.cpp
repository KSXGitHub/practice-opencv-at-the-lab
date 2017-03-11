#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main ();
void displaySingleImage (const Mat, const string, const int, const int);

int main () {

  // Load image and create matrices
  Mat source = imread("image/legobatman.jpg");
  Mat target(source.size(), source.type());
  Mat graysc(target.size(), CV_8UC1);
  cvtColor(source, graysc, CV_RGB2GRAY);

  unsigned char max_gray_pixel = 0;

  // Iterate and manipulate pixels
  for (int i = 0; i != target.cols; ++i) {
    for (int j = 0; j != target.rows; ++j) {

      Vec3b & target_rgb = target.at<Vec3b>(j, i);
      unsigned char gray_pixel = graysc.at<unsigned char>(j, i);
      
      // Region ((0, 0), (50, 50)) is black (rgb = [0, 0, 0])
      if (i > 50 || j > 50) {
        target_rgb = source.at<Vec3b>(j, i);
      }
      
      // Copy region ((100, 100), (120, 120)) of source to region ((0, 0), (20, 20)) of target
      if (i <= 20 && j <= 20) {
        target_rgb = source.at<Vec3b>(i + 100, j + 100);
      }

      // Get maximum grayscale pixel
      if (max_gray_pixel < gray_pixel) {
        max_gray_pixel = gray_pixel;
      }

    }
  }

  // Set highest grayscale pixels to zeros
  cout << "Highest grayscale pixel value is " << int(max_gray_pixel) << endl;
  for (int i = 0; i != graysc.cols; ++i) {
    for (int j = 0; j != graysc.rows; ++j) {
      unsigned char & gray_pixel = graysc.at<unsigned char>(j, i);
      if (gray_pixel == max_gray_pixel) {
        cout << "Found pixel at (" << i << ", " << j << ") with value of " << target.at<Vec3b>(j, i) << " has the highest grayscale value\n";
        gray_pixel = 0;
      }
    }
  }
  
  // Display result
  displaySingleImage(source, "Original", 100, 100);
  displaySingleImage(graysc, "Grayscaled", 100, 450);
  displaySingleImage(target, "Processed", 512, 100);

  // Finalizing
  waitKey();
  return 0;

}

void displaySingleImage (const Mat image, const string window, const int winx, const int winy) {
  namedWindow(window, CV_WINDOW_NORMAL);
  moveWindow(window, winx, winy);
  imshow(window, image);
}
