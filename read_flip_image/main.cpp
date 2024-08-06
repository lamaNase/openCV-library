#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_image> <output_image>" << std::endl;
        return -1;
    }

    // Read the image from file
    cv::Mat image = cv::imread(argv[1]);
    if (image.empty()) {
        std::cerr << "Error: Unable to open image file!" << std::endl;
        return -1;
    }

    // Flip the image horizontally
    cv::Mat flipped_image;
    cv::flip(image, flipped_image, 1);

    // Save the flipped image to file
    if (!cv::imwrite(argv[2], flipped_image)) {
        std::cerr << "Error: Unable to save image file!" << std::endl;
        return -1;
    }

    std::cout << "Image successfully flipped and saved to " << argv[2] << std::endl;
    return 0;
}

