#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>

// Shared resources
std::vector<cv::Mat> frameBuffer;
std::mutex bufferMutex;
std::atomic<bool> isRunning(true);

// Frames
cv::Mat display, flip, rotate, removeRed;
std::mutex displayMutex, flipMutex, rotateMutex, removeRedMutex;

// Function declarations
void captureFrame(cv::VideoCapture& cap);
void displayVideo();
void flipVideo();
void rotateVideo(double angle);
void removeRedChannel();

