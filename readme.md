# Mandelbrot Set
This program generates and displays the Mandelbrot set using OpenGL and GLUT. The Mandelbrot set is a fractal set that exhibits intricate and complex patterns.

## Prerequisites
- OpenGL
- GLUT (OpenGL Utility Toolkit)
## Usage
1. Compile the program using a C++ compiler with OpenGL and GLUT libraries.

```g++ mandelbrotset.cpp -o mandelbrotset -framework OpenGL -framework GLUT```

2. Run the compiled executable.

```./mandelbrotset```

## Description
The program performs the following steps:
1. Initialize GLUT and create a window for rendering.
2. Set up the OpenGL context and define the coordinate system.
3. Define the display function.
4. Iterate through each pixel of the window.
5. For each pixel, calculate the corresponding complex number in the range of the Mandelbrot set.
6. Perform iterations on the complex number to determine if it belongs to the Mandelbrot set.
7. Set the color based on the number of iterations.
8. Render the pixel using OpenGL points.
9. Swap the buffers to display the generated image.
10. Enter the main loop for event handling.

# NOTES
This is one of my first projects learning C++ this is also one of my first projects using MacOS to develop programs. An issue I was running into is that the program would run great on my Macbook but it strugles to compile on my windows desktop. I am not sure if it is because of the compiler. But this is something I am trying to fix.
