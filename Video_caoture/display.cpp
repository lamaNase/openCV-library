
void displayVideo() {
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
        	
        
        	// Print the frame index on the image
        	std::string text = "Display, ";
        	text += "Frame: " + std::to_string(frameIndex);
        	cv::putText(frame, text, cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 
        		1, cv::Scalar(255, 255, 255), 2);
	
        	// Lock the mutex for frame1 before writing to it
        	{
        	    std::unique_lock<std::mutex> lock(displayMutex);
        	    display = frame.clone();
        	}
        	
        	
		//if (cv::waitKey(30) >= 0) break;
	}
}

