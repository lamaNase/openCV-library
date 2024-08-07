#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

// Shared resources
extern cv::Mat sharedFrame;
extern std::mutex frameMutex;
extern std::atomic<bool> isRunning;

// Function declarations
void captureFrame(cv::VideoCapture& cap);
void displayVideo();
void flipVideo();
void rotateVideo(double angle);
void removeRedChannel();

