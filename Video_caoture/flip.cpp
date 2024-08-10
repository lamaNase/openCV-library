void flipVideo() {
	int frameIndex = 0;
	while (isRunning) {
	
		cv::Mat flippedFrame;
        	cv::Mat frame;
		std::unique_lock<std::mutex> lock(bufferMutex);
		
        	if (!frameBuffer.empty() && frameBuffer.size() > frameIndex) {
        		frame = frameBuffer.at(frameIndex);
        		frameIndex++;
		} else 
			continue;
        	
        	
		cv::flip(frame, flippedFrame,0); // flip the fram vertically
		
		// Print the frame index on the image
		std::string text = "Flip, ";
        	text += "Frame: " + std::to_string(frameIndex++);
        	cv::putText(flippedFrame, text, cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 
        		1, cv::Scalar(255, 255, 255), 2);
        	
        	
        	// Lock the mutex for frame2 before writing to it
        	{
        	    std::unique_lock<std::mutex> lock(frame2Mutex);
        	    frame2 = flippedFrame.clone();
        	}
        	
        	if (cv::waitKey(30) >= 0) break;
        	
	}
}
