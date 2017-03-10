#include <iostream>
#include <string>
#include <ctime>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main () {
  const string window_name = "Camera";
  const string output_file = string("output/exercise-4.recorded-in-") + to_string(time(0)) + string(".avi");
  VideoCapture input(0);
  if (!input.isOpened()) {
    cerr << "Could not connect to camera\nExiting.\n";
    return 1;
  }
  Size size(input.get(CV_CAP_PROP_FRAME_WIDTH), input.get(CV_CAP_PROP_FRAME_HEIGHT));
  VideoWriter output(output_file, CV_FOURCC('M', 'J', 'P', 'G'), 10, size, true);
  if (!output.isOpened()) {
    cerr << "Could not open " << output_file << " to write to\nExiting.\n";
    return 2;
  }
  cerr << "Recording to " << output_file << endl;
  namedWindow(window_name);
  do {
    Mat frame;
    input >> frame;
    output << frame;
    imshow(window_name, frame);
  } while (waitKey(33) < 0);
  cerr << "Done.\n";
  return 0;
}

