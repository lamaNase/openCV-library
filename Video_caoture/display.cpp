
void displayVideo() {
	int frameIndex = 0;
    	while (isRunning) {
    	
		cv::Mat frame;
        	{
        	    std::lock_guard<std::mutex> lock(frameMutex);
        	    if (sharedFrame.empty()) continue;
        	    frame = sharedFrame.clone();
        	}
        
        	// Print the frame index on the image
        	std::string text = "Frame: " + std::to_string(frameIndex++);
        	cv::putText(frame, text, cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 
        		1, cv::Scalar(255, 255, 255), 2);
	
        	cv::imshow("Display Video", frame); // Display the frame
	
	        if (cv::waitKey(30) >= 0) break; // Exit on any key press
	}
	    
	isRunning = false;
	cv::destroyAllWindows();
}

