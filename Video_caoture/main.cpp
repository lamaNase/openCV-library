#include "video_processing.h"
#include "display.cpp"
#include "flip.cpp"
#include "rotate.cpp"
#include "removeRed.cpp"
#include <thread>

// Definition of shared resources
cv::Mat sharedFrame;
std::mutex frameMutex;
std::atomic<bool> isRunning(true);

void captureFrame(cv::VideoCapture& cap) {
    while (isRunning) {
        cv::Mat frame;
        cap >> frame;
        if (frame.empty()) {
            isRunning = false;
            break;
        }
        // write on the shared frame
        {
            std::lock_guard<std::mutex> lock(frameMutex);
            sharedFrame = frame.clone();
        }
    }
}

int main()  {
	cv::VideoCapture cap(0); // open the camera
	
	//check if the camera is opened successfully
	if (!cap.isOpened()){
		std::cerr << "Can't open the camera" << std::endl;
		return -1;
	}
	
	double angle;
    	std::cout << "Enter the rotation angle: ";
    	std::cin >> angle;
	
	// Create threads
	std::thread captureThread(captureFrame, std::ref(cap));
	std::thread displayThread(displayVideo);
	std::thread flipThread(flipVideo);
	std::thread rotateThread(rotateVideo, angle);
	std::thread removeRedThread(removeRedChannel);
	
	// Join threads to the main thread
	captureThread.join();
	displayThread.join();
	flipThread.join();
	rotateThread.join();
	removeRedThread.join();
	
	isRunning = false;
    	cap.release();
    	cv::destroyAllWindows();
	
	
	return 0;
}
