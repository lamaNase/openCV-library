
void rotateVideo(double angle) {
	int index = 0;
	
	while (isRunning) {
		
		int frameIndex;
		cv::Mat rotatedFram;
        	cv::Mat frame;
		std::unique_lock<std::mutex> lock(bufferMutex);
		
        	if (!frameBuffer.empty() && frameBuffer.size() > index) {
        		frame = frameBuffer.at(index).first.clone();
        		frameIndex = frameBuffer.at(index).second;
        		index++;
		} else 
			continue;
        	
		
		// Get the rotation matrix
        	cv::Point2f center(frame.cols / 2.0, frame.rows / 2.0); // get the center point 
        	cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0);

		// rotate the frame
		cv::warpAffine(frame, rotatedFram, rotationMatrix, frame.size());
		
		// Print the frame index on the image
        	std::string text = "Rotate, ";
        	text += "Frame: " + std::to_string(frameIndex);
        	cv::putText(rotatedFram, text, cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 
        		1, cv::Scalar(255, 255, 255), 2);
        	
        	{
        	    std::unique_lock<std::mutex> lock(rotateMutex);
        	    rotate = rotatedFram.clone();
        	}
        	
        	//if (cv::waitKey(30) >= 0) break;
	}
	
}
