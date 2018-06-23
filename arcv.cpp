#include "opencv2/opencv.hpp"
#include <iostream>
#include <opencv2/aruco.hpp>

using namespace cv;
using namespace std;

int main() {
  // waitKey(10);
  VideoCapture cap(0);

  // Check if camera opened successfully
  if (!cap.isOpened()) {
    cout << "Error opening video stream" << endl;
    return -1;
  }

  // Default resolution of the frame is obtained.The default resolution is
  // system dependent.
  int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
  int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

  // Define the codec and create VideoWriter object.The output is stored in
  // 'outcpp.avi' file.
  VideoWriter video("outcpp.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10,
                    Size(frame_width, frame_height));

  while (1) {

    vector<int> markerIds;
    vector<vector<Point2f>> markerCorners, rejectedCandidates;
    cv::aruco::DetectorParameters parameters;
    cv::aruco::Dictionary dictionary =
        cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);

    Mat frame;

    // Capture frame-by-frame
    cap >> frame;

    // If the frame is empty, break immediately
    if (frame.empty())
      break;

    // cv::aruco::detectMarkers(frame, dictionary, markerCorners, markerIds,
    // parameters, rejectedCandidates);

    // Write the frame into the file 'outcpp.avi'
    video.write(frame);

    // Display the resulting frame
    imshow("Frame", frame);

    // Press  ESC on keyboard to  exit
    char c = (char)waitKey(1);
    if (c == 27)
      break;
  }

  // When everything done, release the video capture and write object
  cap.release();
  video.release();

  // Closes all the windows
  destroyAllWindows();
  return 0;
}
