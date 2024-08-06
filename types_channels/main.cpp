#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_image>" << std::endl;
        return -1;
    }

    // Load an image in color (3 channels)
    cv::Mat colorImage = cv::imread(argv[1], cv::IMREAD_COLOR);

    if (colorImage.empty()) {
        std::cerr << "Error loading image!" << std::endl;
        return -1;
    }

    // Display the type and channels of the color image
    std::cout << "Color image type: " << colorImage.type() << std::endl;
    std::cout << "Color image channels: " << colorImage.channels() << std::endl;

    // Convert to grayscale (1 channel)
    cv::Mat grayImage;
    cv::cvtColor(colorImage, grayImage, cv::COLOR_BGR2GRAY);

    // Display the type and channels of the grayscale image
    std::cout << "Grayscale image type: " << grayImage.type() << std::endl;
    std::cout << "Grayscale image channels: " << grayImage.channels() << std::endl;

    // Show the images
    cv::imwrite("../greyImage.png", grayImage );

    cv::waitKey(0); // Wait for a key press to close the windows
    return 0;
}

