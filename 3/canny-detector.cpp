#include <iostream>
#include <cstdlib>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat target, source, source_gray, detected_edges;
string window_name = "Canny Detector";

int main ();
void cannyThreshold (int, void *);

int main () {

  // Read the source image
  source = imread("lena");

  // Convert
  target.create(source.size(), source.type());
  cvtColor(source, source_gray, COLOR_BGR2GRAY);
  
  // Initialize UI
  namedWindow(window_name);
  auto lowThreshold = 0;
  createTrackbar("Minimum Threshold:", window_name, &lowThreshold, 255, cannyThreshold);
  
  // First frame
  cannyThreshold(0, NULL);
  
  // Finalization
  waitKey(0);
  return 0;

}

void cannyThreshold (int lowThreshold, void *) {
  blur(source_gray, detected_edges, Size(3, 3));
  Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * 3, 3);
  target = Scalar::all(0);
  source.copyTo(target, detected_edges);
  imshow(window_name, target);
}
