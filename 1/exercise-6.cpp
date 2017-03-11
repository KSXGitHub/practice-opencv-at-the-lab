#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main ();
void waitKeyWindow (int = 0, int = WINDOW_AUTOSIZE);

int main () {
  waitKeyWindow(0);
  waitKeyWindow(3000);
  return 0;
}

void waitKeyWindow (int delay, int flags) {
  const string title = string("waitKey(") + to_string(delay) + string(")");
  namedWindow(title, flags);
  cout << title << ": " << waitKey(delay) << endl;
  destroyWindow(title);
}
