
#include <iostream>
#include <stdio.h>
#include <complex.h>
#include <tgmath.h>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


void display() {

    std::cout << "Display function called" << std::endl;

    // clear color
    glClear(GL_COLOR_BUFFER_BIT);

    // definitions 
    const int width = 800;
    const int height = 600;

    const double xMin = -2.0;
    const double xMax = 1.0;
    const double yMin = -1.5;
    const double yMax = 1.5;

    const int maxIterations = 100;

    // loop for iterating the pixels
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            double real = xMin + (xMax - xMin) * (x / static_cast<double>(width));
            double imag = yMin + (yMax - yMin) * (y / static_cast<double>(height));

            // perform iteration
            std::complex<double> c(real, imag);
            std::complex<double> z(0.0, 0.0);

            int iterations = 0;

            while (iterations < maxIterations && std::abs(z) < 2.0) {
                z = z * z + c;
                ++iterations;
            }

            // setting the colors
            double t = static_cast<double>(iterations) /maxIterations;
            glColor3d(t, t, t);

            // render
            glBegin(GL_POINTS);
            glVertex2f(static_cast<GLfloat>(x), static_cast<GLfloat>(y));
            glEnd();
        }
    }

    // swap to display image
    glutSwapBuffers();
}

int main (int argc, char** argv) {
    
    std::cout << "Hello world" << std::endl;

    // initialize GLUT and create the window
    glutInit(&argc,  argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mandelbrot");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL context error: " << error << std::endl;
        return 1;
    }

    // setting display
    glutDisplayFunc(display);

    // clear colorr
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // entering loop
    glutMainLoop();
    return 0;
}
