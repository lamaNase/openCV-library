#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Create three single-channel images (each with a different color)
    cv::Mat channel1(256, 256, CV_8UC1, cv::Scalar(255)); // White
    cv::Mat channel2(256, 256, CV_8UC1, cv::Scalar(255));   // white
    cv::Mat channel3(256, 256, CV_8UC1, cv::Scalar(0));   // Black

    // Combine the three channels into one multi-channel image (BGR format)
    std::vector<cv::Mat> channels = { channel1, channel2, channel3 };
    cv::Mat colorImage;
    cv::merge(channels, colorImage);

    // Display the combined image
    cv::imshow("Combined Image", colorImage);
    cv::waitKey(0);

    // Split the color image back into its original channels
    cv::Mat splitChannel1, splitChannel2, splitChannel3;
    std::vector<cv::Mat> splitChannels;
    cv::split(colorImage, splitChannels);

    // Extract each channel
    splitChannel1 = splitChannels[0]; // Blue channel
    splitChannel2 = splitChannels[1]; // Green channel
    splitChannel3 = splitChannels[2]; // Red channel

    // Display the split channels
    cv::imshow("Blue Channel", splitChannel1);
    cv::imshow("Green Channel", splitChannel2);
    cv::imshow("Red Channel", splitChannel3);
    cv::waitKey(0);

    return 0;
}

