# Simple convert image type code 🖼️ ⚫ ⚪ 🎨

This small program perform reading colored image (with three) channels
and prints its type. Then it convert this image into single channel image
(greyscale image) and prints its type. The program recieve the path of the
input image and saves the greyscale image with name 'greyImage.png'.


# Command line output 🖥️


![Screenshot from 2024-08-06 20-44-41](https://github.com/user-attachments/assets/99393669-6a78-4474-8c94-5a7d60b99aee)


📝 Note: 

- 16 means the type CV_8UC3:8-bit unsigned 3 channels.
- 0 means the type CV_8UC1: 8-bit unsigned single channel.

# How can you run the code ❓

### You can run the program through executing the following commands:

>**mkdir build**

>**cd build**

>**cmake ..**

>**make**

>**./image_types_channels ../sample.png**


⚠️ Note: replace '../sample.png' with the path of the input image

# Example 💡

## input image (colord image) 🎨

![sample](https://github.com/user-attachments/assets/1e25bdf4-724d-4b9e-bb18-6eb15917d884)

## greyscaled image 🌑

![greyImage](https://github.com/user-attachments/assets/33f07506-9507-42a4-96a0-971065cc522d)

