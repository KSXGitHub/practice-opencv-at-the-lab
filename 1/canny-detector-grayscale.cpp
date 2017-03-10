#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main () {

  // Original image
  const string original_window_name = "Original Image";
  const Mat original_img = imread("image/beta");
  namedWindow(original_window_name);
  imshow(original_window_name, original_img);

  // Gray and Canny image
  Mat gray, edge, draw;
  cvtColor(original_img, gray, CV_RGB2GRAY);
  Canny(gray, edge, 50, 150, 3);
  edge.convertTo(draw, CV_8U);

  // Display canny image
  const string canny_window_name = "Canny Image";
  namedWindow(canny_window_name);
  moveWindow(canny_window_name, original_img.size().width, 0);
  imshow(canny_window_name, draw);
  
  // Finalization
  waitKey();
  return 0;

}
