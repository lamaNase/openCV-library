# OpenCV Library in C++ 💠

OpenCV (Open Source Computer Vision Library) is an open-source computer vision 
and machine learning software library. It contains more than 2500 optimized 
algorithms, which can be used for various tasks such as detecting and recognizing 
faces, identifying objects, classifying human actions in videos, tracking camera 
movements, extracting 3D models of objects, and much more.

# Types in openCV 📊
In OpenCV, images are represented as matrices, and these matrices can have different 
data types depending on the nature of the image data. The most commonly used types are:

  1. **CV_8UC1**: 8-bit unsigned single-channel (grayscale) image.
  2. **CV_8UC3**: 8-bit unsigned 3-channel (color) image, usually in BGR format.
  3. **CV_16UC1**: 16-bit unsigned single-channel image.
  4. **CV_32FC1**: 32-bit float single-channel image.
  5. **CV_64FC1**: 64-bit float single-channel image.

# Channels 🎨

Channels represent the different color components in an image. For example, a typical 
color image has 3 channels corresponding to Blue, Green, and Red (BGR) in OpenCV. 
A grayscale image has only one channel.

# Merge & Split 🔄

OpenCV provides functions to merge multiple single-channel images into one multi-channel 
image and to split a multi-channel image into separate single-channel images.

  ## split()
    OpenCV provides functions to merge multiple single-channel images into one multi-channel 
    image and to split a multi-channel image into separate single-channel images.

  ## merge()
    The merge() function in OpenCV is used to combine several single-channel images into a 
    single multi-channel image.


# Functions Supported by OpenCV 🔍🖼️

## 1. Basic Operations on Images:

  - **cv::imread** 📥 : Load an image from file.
  - **cv::imshow** 🖼️ : Display an image in a window.
  - **cv::imwrite** 📤 : Save an image to file.

## 2. Image Processing

  - **cv::cvtColor**  🌈   : Convert an image from one color space to another.
  - **cv::GaussianBlur** 🌫️ : Apply Gaussian blurring to an image.
  - **cv::threshold**  ⚖️  : Apply a fixed-level threshold to each array element.
  - **cv::Canny**  ✂️      : Apply the Canny edge detector.

## 3. Geometric Transformations:

  - **cv::resize**  📏   : Resize an image.
  - **cv::warpAffine** 🔁 : Apply an affine transformation to an image.
  - **cv::rotate**  🔁   : Rotate an image by 90, 180, or 270 degrees.

## 4. Drawing Functions:

  - **cv::line**   ➖   : Draw a line.
  - **cv::circle**  ⭕  : Draw a circle.
  - **cv::rectangle** ⬛ : Draw a rectangle.
  - **cv::putText** ✏️  : Draw a text string.

## 5. Feature Detection and Description:

  - **cv::goodFeaturesToTrack** 🔎 : Detect corners in an image.
  - **cv::ORB** 🌟            : ORB keypoint detector and descriptor.
  - **cv::BRISK** ⚙️             : Binary Robust Invariant Scalable Keypoints.

## 6. Object Detection:

  - **cv::CascadeClassifier** 🎯 : Detect objects using a cascade of boosted classifiers.
  - **cv::HOGDescriptor** 📏    : Histogram of Oriented Gradients descriptor and object detector.

## 7. Video Analysis:

  - **cv::VideoCapture** 📹           : Capture video from a file or camera.
  - **cv::BackgroundSubtractorMOG2** 🎬 : Gaussian Mixture-based Background/Foreground Segmentation Algorithm.

## 8. Machine Learning:

  - **cv::ml::SVM** 📈      : Support Vector Machines.
  - **cv::ml::KNearest** 🔍 : k-Nearest Neighbors.
  - **cv::ml::RTrees** 🌲   : Random Trees.


