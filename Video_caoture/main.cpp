#include "video_processing.h"
#include "display.cpp"
#include "flip.cpp"
#include "rotate.cpp"
#include "removeRed.cpp"
#include "showWindow.cpp"


void captureFrame(cv::VideoCapture cap) {
    int frameIndex = 0;
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

void makeThreads(cv::VideoCapture cap, double angle) {
    	std::thread captureThread(captureFrame, cap);
	std::thread displayThread(displayVideo);
	std::thread flipThread(flipVideo);
	std::thread rotateThread(rotateVideo, angle);
	std::thread removeRedThread(removeRedChannel);
	std::thread updateFramesThread(updateFrames);
	
	captureThread.join();
	displayThread.join();
	flipThread.join();
	rotateThread.join();
	removeRedThread.join();
	updateFramesThread.join();
	
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
