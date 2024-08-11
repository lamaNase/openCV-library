
void removeRedChannel() {
    	int index = 0;
    	
    	while (isRunning) {
        	int frameIndex;
        	cv::Mat frame;
		std::unique_lock<std::mutex> lock(bufferMutex);
		
        	if (!frameBuffer.empty() && frameBuffer.size() > index) {
        		frame = frameBuffer.at(index).first.clone();
        		frameIndex = frameBuffer.at(index).second;
        		index++;
		} else 
			continue;
        	
	
	        std::vector<cv::Mat> channels;
	        cv::split(frame, channels); // Split the frame into its channels
	        
	        // Set the red channel to zero
	        channels[2] = cv::Mat::zeros(frame.rows, frame.cols, CV_8UC1); 
	        cv::merge(channels, frame); // Merge the channels back together
	
		// Print the frame index on the image
        	std::string text = "Remove Red Channel, ";
        	text += "Frame: " + std::to_string(frameIndex);
        	cv::putText(frame, text, cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 
        		1, cv::Scalar(255, 255, 255), 2);
	
		{
        	    std::unique_lock<std::mutex> lock(removeRedMutex);
        	    removeRed = frame.clone();
        	}
		
		if (cv::waitKey(30) >= 0) break;
	    }
}
