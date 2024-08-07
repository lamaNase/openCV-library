
void removeRedChannel() {
    	int frameIndex = 0;
    	
    	while (isRunning) {
        	cv::Mat frame;
        	{
        	    std::lock_guard<std::mutex> lock(frameMutex);
        	    if (sharedFrame.empty()) continue;
        	    frame = sharedFrame.clone();
        	}
	
	        std::vector<cv::Mat> channels;
	        cv::split(frame, channels); // Split the frame into its channels
	        
	        // Set the red channel to zero
	        channels[2] = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC1); 
	        cv::merge(channels, frame); // Merge the channels back together
	
		// Print the frame index on the image
        	std::string text = "Frame: " + std::to_string(frameIndex++);
        	cv::putText(frame, text, cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 
        		1, cv::Scalar(255, 255, 255), 2);
	
	        cv::imshow("No Red Channel Video", frame); // Display the frame
	
	        if (cv::waitKey(30) >= 0) break; // Exit on any key press
	    }
	    
	    cv::destroyAllWindows();
}

