#include "video_processing.h"
#include "display.cpp"
#include "flip.cpp"
#include "rotate.cpp"
#include "removeRed.cpp"
#include "showWindow.cpp"

<<<<<<< HEAD
void captureFrame(cv::VideoCapture cap) {
    int frameIndex = 0;
    
=======

void captureFrame(cv::VideoCapture& cap) {
    int frameIndex = 0;
>>>>>>> origin/main
    while (isRunning) {
    	
    	while (!played);
    	
        cv::Mat frame;
        cap >> frame;
        if (frame.empty()) {
            //std::cerr << "Failed to capture" << std::endl;
            isRunning = false;
            break;
        }

        std::unique_lock<std::mutex> lock(bufferMutex);
        frameBuffer.push_back(std::make_pair(frame.clone(),frameIndex));
        frameIndex++;
    }
}

<<<<<<< HEAD
void makeThreads(cv::VideoCapture cap, double angle) {
	QThread *captureThread = QThread::create([&cap]() {
        	captureFrame(cap);
    	});
    	captureThread->start();
	std::thread displayThread(displayVideo);
	std::thread flipThread(flipVideo);
	std::thread rotateThread(rotateVideo, angle);
	std::thread removeRedThread(removeRedChannel);
	std::thread updateFramesThread(updateFrames);
	
	captureThread->wait();
	displayThread.join();
	flipThread.join();
	rotateThread.join();
	removeRedThread.join();
	updateFramesThread.join();
	
	delete captureThread;
=======
void showFramesInSections() {
    cv::namedWindow("Combined Display", cv::WINDOW_AUTOSIZE);
    
    // Create a large image to hold all sections
    int width  = 450;
    int height = 350;
	    
    cv::Mat combinedDisplay(height * 2, width * 2, CV_8UC3, cv::Scalar(0, 0, 0));
    
    while (isRunning) {
    	
    	cv::Mat resizedFrame1, resizedFrame2, resizedFrame3, resizedFrame4;
    	if (!display.empty()) {
    		std::unique_lock<std::mutex> lock(displayMutex);
    		cv::resize(display, resizedFrame1, cv::Size(width, height));
    		resizedFrame1.copyTo(combinedDisplay(cv::Rect(0, 0, width, height)));
    	}
    	if (!flip.empty()) {
    		std::unique_lock<std::mutex> lock(flipMutex);
    		cv::resize(flip, resizedFrame2, cv::Size(width, height));
    		resizedFrame2.copyTo(combinedDisplay(cv::Rect(width, 0, width, height)));
    	}
    	if (!rotate.empty()) {
    		std::unique_lock<std::mutex> lock(rotateMutex);
    		cv::resize(rotate, resizedFrame3, cv::Size(width, height));
    		resizedFrame3.copyTo(combinedDisplay(cv::Rect(0, height, width, height)));
    	}
    	if (!removeRed.empty()) {
    		std::unique_lock<std::mutex> lock(removeRedMutex);
    		cv::resize(removeRed, resizedFrame4, cv::Size(width, height));
    		resizedFrame4.copyTo(combinedDisplay(cv::Rect(width, height, width, height)));
    	}
    	// Show the combined display
    	cv::imshow("Combined Display", combinedDisplay);
    	
    	if (cv::waitKey(30) >= 0) break;
    }
    
    isRunning = false;
    cv::destroyAllWindows();
>>>>>>> origin/main
}


int main(int argc, char *argv[])  {

	cv::VideoCapture cap(0); // open the camera
	
	//check if the camera is opened successfully
	if (!cap.isOpened()){
		std::cerr << "Can't open the camera" << std::endl;
		return -1;
	}
	
	double angle;
    	std::cout << "Enter the rotation angle: ";
    	std::cin >> angle;
    	
    	// Use QThread for the make threads
    	QThread *makeThreadsThread = QThread::create([&cap, angle]() {
        	makeThreads(cap, angle);
    	});
	
	// Start the threads
    	makeThreadsThread->start();
	
	// main thread here
	std::cout << "Main thread starts" << std::endl;
        showFramesInSections(argc, argv);
    	
	
	// Ensure the threads finish before exiting
    	makeThreadsThread->wait();
	
    	delete makeThreadsThread;
	
    	cap.release();
	
	return 0;
}
