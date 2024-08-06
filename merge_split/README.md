# Simple merge split image channels code

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




## flipped image 🔁

The colord image now splited into three single channels again as shown below:




