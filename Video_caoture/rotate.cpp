
void rotateVideo(double angle) {
	int frameIndex = 0;
	
	while (isRunning) {
		cv::Mat frame, rotatedFram;
        	{
        	    std::lock_guard<std::mutex> lock(frameMutex);
        	    if (sharedFrame.empty()) continue;
        	    frame = sharedFrame.clone();
        	}
		
		// Get the rotation matrix
        	cv::Point2f center(frame.cols / 2.0, frame.rows / 2.0); // get the center point 
        	cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0);

		// rotate the frame
		cv::warpAffine(frame, rotatedFram, rotationMatrix, frame.size());
		
		// Print the frame index on the image
        	std::string text = "Frame: " + std::to_string(frameIndex++);
        	cv::putText(rotatedFram, text, cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 
        		1, cv::Scalar(255, 255, 255), 2);
        	
        	cv::imshow("rotated video",rotatedFram); // show the flipped video
        	
        	if (cv::waitKey(30) >= 0) break; // Exit on any key press
	}
	
	cv::destroyAllWindows();
}
