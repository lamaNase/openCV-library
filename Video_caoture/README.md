# Real-Time Video Manipulation  📹 🎬

This project performs some image processing on a video captured
from the webcam. It generates four threads, each one handel a 
specific technique on the video frams as follow:

- **Thread 1 Display**: displays the captured frams with the fram index
- **Thread 2 Flip**: Flips the frams vertically & displays them with the frame index
- **Thread 3 Rotate**: rotates frams with specific angle & displays them with the frame index
- **Thread 4 Remove Red Channel**: Removes the red channel & displays frames with the frame index

# How can you run the code ❓

### You can run the program through executing the following commands:

>**mkdir build**

>**cd build**

>**cmake ..**

>**make**

>**./video_cap**


⚠️ Note: press any key on the kryboard to stop the running of the program


# Example 💡


[Screencast from 08-10-2024 10:12:10 PM.webm](https://github.com/user-attachments/assets/ef149afd-0015-47f4-ad42-58db32baaae6)


