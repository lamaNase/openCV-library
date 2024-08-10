#include "video_processing.h"
#include "display.cpp"
#include "flip.cpp"
#include "rotate.cpp"
#include "removeRed.cpp"


void captureFrame(cv::VideoCapture& cap) {
    while (isRunning) {
        cv::Mat frame;
        cap >> frame;
        if (frame.empty()) {
            isRunning = false;
            break;
        }

        std::unique_lock<std::mutex> lock(bufferMutex);
        
        frameBuffer.push_back(frame.clone());
    }
}

void showFramesInSections() {
    cv::namedWindow("Combined Display", cv::WINDOW_AUTOSIZE);
    
    // Create a large image to hold all sections
    int width  = 450;
    int height = 350;
	    
    cv::Mat combinedDisplay(height * 2, width * 2, CV_8UC3, cv::Scalar(0, 0, 0));
    
    while (isRunning) {
    	
    	cv::Mat resizedFrame1, resizedFrame2, resizedFrame3, resizedFrame4;
    	if (!frame1.empty()) {
    		std::unique_lock<std::mutex> lock(frame1Mutex);
    		cv::resize(frame1, resizedFrame1, cv::Size(width, height));
    		resizedFrame1.copyTo(combinedDisplay(cv::Rect(0, 0, width, height)));
    	}
    	if (!frame2.empty()) {
    		std::unique_lock<std::mutex> lock(frame2Mutex);
    		cv::resize(frame2, resizedFrame2, cv::Size(width, height));
    		resizedFrame2.copyTo(combinedDisplay(cv::Rect(width, 0, width, height)));
    	}
    	if (!frame3.empty()) {
    		std::unique_lock<std::mutex> lock(frame3Mutex);
    		cv::resize(frame3, resizedFrame3, cv::Size(width, height));
    		resizedFrame3.copyTo(combinedDisplay(cv::Rect(0, height, width, height)));
    	}
    	if (!frame4.empty()) {
    		std::unique_lock<std::mutex> lock(frame4Mutex);
    		cv::resize(frame4, resizedFrame4, cv::Size(width, height));
    		resizedFrame4.copyTo(combinedDisplay(cv::Rect(width, height, width, height)));
    	}
    	// Show the combined display
    	cv::imshow("Combined Display", combinedDisplay);
    	
    	if (cv::waitKey(30) >= 0) break;
    }
    
    isRunning = false;
    cv::destroyAllWindows();
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
	std::thread displayMainWindowThread(showFramesInSections);
	std::thread displayThread(displayVideo);
	std::thread flipThread(flipVideo);
	std::thread rotateThread(rotateVideo, angle);
	std::thread removeRedThread(removeRedChannel);
	
	// Join threads to the main thread
	captureThread.join();
	displayMainWindowThread.join();
	displayThread.join();
	flipThread.join();
	rotateThread.join();
	removeRedThread.join();
	
	
    	cap.release();
	
	return 0;
}
