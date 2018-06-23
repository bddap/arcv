#include <iostream>
#include <opencv2/aruco.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
  VideoCapture cap(0); // 0 means "first webcam"
  if (!cap.isOpened()) {
    cout << "Error opening video stream" << endl;
    return -1;
  }

  // Default resolution of the frame is obtained. The default resolution is
  // system dependent.
  int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
  int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

  vector<int> markerIds;
  vector<vector<Point2f>> markerCorners;
  auto dictionary = aruco::getPredefinedDictionary(aruco::DICT_4X4_50);
  Mat frame;

  while (1) {
    // grab image from camera
    cap >> frame;
    if (frame.empty()) {
      cout << "Got empy frame from webcam." << endl;
      break;
    }

    aruco::detectMarkers(frame, dictionary, markerCorners, markerIds);
    aruco::drawDetectedMarkers(frame, markerCorners, markerIds);

    // write to window
    imshow("arcv", frame);

    // Press  ESC on keyboard to  exit
    if (waitKey(1) == 27)
      break;
  }

  cap.release();
  destroyAllWindows();
  return 0;
}
