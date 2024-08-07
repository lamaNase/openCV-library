void flipVideo() {
	int frameIndex = 0;
	while (isRunning) {
	
		cv::Mat frame, flippedFrame;
        	{
        	    std::lock_guard<std::mutex> lock(frameMutex);
        	    if (sharedFrame.empty()) continue;
        	    frame = sharedFrame.clone();
        	}
        	
		cv::flip(frame, flippedFrame,0); // flip the fram vertically
		
		// Print the frame index on the image
        	std::string text = "Frame: " + std::to_string(frameIndex++);
        	cv::putText(flippedFrame, text, cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 
        		1, cv::Scalar(255, 255, 255), 2);
        	
        	cv::imshow("Fliped video",flippedFrame); // show the flipped video
        	
        	if (cv::waitKey(30) >= 0) break; // Exit on any key press
        	
	}
	
	cv::destroyAllWindows();
}
