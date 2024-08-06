# Simple flipping image code

This small program perform flipping an input image using openCV
library in C++. The program requires the user to enter the path
of an input image and a path of an image where the flipped image
will be aaved in.

# Flip options 🔧

in my code I used the flip 1 as shown in the following line code

> cv::flip(image, flipped_image, 1);

this flipps the image horizontally
other options:

- **0**: Flip vertically (around the x-axis).
- **1**: Flip horizontally (around the y-axis).
- **-1**: Flip both vertically and horizontally.
	
# How can you run the code ❓

### You can run the program through executing the following commands:

>**mkdir build**

>**cd build**

>**cmake ..**

>**make**

>**./image_flip ../sample.png ../flipped.png**


📝 Note: replace '../sample.png' with the path of the input image

# Example 💡

## input image 🖼️

![sample](https://github.com/user-attachments/assets/1e25bdf4-724d-4b9e-bb18-6eb15917d884)

## flipped image 🔁

![flipped](https://github.com/user-attachments/assets/90298211-71ee-479c-9505-b89199ccbc48)

<<<<<<< HEAD

=======
>>>>>>> origin/main
