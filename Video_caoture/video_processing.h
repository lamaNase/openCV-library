#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QPixmap>
#include <QThread>
#include <QTimer>

// Shared resources
std::vector<std::pair<cv::Mat,int>> frameBuffer;
std::mutex bufferMutex;
std::atomic<bool> isRunning(true);

std::atomic<bool> played(true);

int width = 400;
int height = 300;

// Frames
cv::Mat display, flip, rotate, removeRed;
std::mutex displayMutex, flipMutex, rotateMutex, removeRedMutex;

// Qimage that will be shown on the window
QImage qimage;
std::mutex imageMutex;
cv::Mat combinedDisplay(height * 2, width * 2, CV_8UC3, cv::Scalar(0, 0, 0));


// Function declarations
void captureFrame(cv::VideoCapture cap);
void displayVideo();
void flipVideo();
void rotateVideo(double angle);
void removeRedChannel();
void makeThreads(cv::VideoCapture cap, double angle);

