# Simple merge split image channels code 🔀

This small program perform merge three single channels into one image
with three channel (RGB image) and show the result. After that, it splits
that image's channels into three single channels.

	
# How can you run the code ❓

### You can run the program through executing the following commands:

>**mkdir build**

>**cd build**

>**cmake ..**

>**make**

>**./merge_split**



# Example 💡

In this code, I have defined three single channels with the values (255,255,0)
which means (white,white,blue) and I've combined these channels into one colord image.
And finally, this new image is splited to make three images each with single channel
means greyscale image again.

## merged image 🖼️

Since the three single channels were (white, white, black) then the resulting
color corrosponds to (0, 0, 1) -> (Red, Green, Blue) means the resulting image 
will have blue color as shown below:


![Screenshot from 2024-08-06 21-24-34](https://github.com/user-attachments/assets/38600757-cb89-47f7-a463-74b0db70e58d)



## splited images ⚫ ⚪

The colord image now splited into three single channels again as shown below:


![Screenshot from 2024-08-06 21-25-12](https://github.com/user-attachments/assets/fe35bb5b-2235-4974-a7d4-f1b927785f36)


