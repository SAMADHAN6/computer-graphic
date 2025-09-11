#include <GL/glut.h>
#include <iostream>

using namespace std;

int circle_xc, circle_yc, circle_r;

// Initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    gluOrtho2D(0, 600, 0, 600);       // Define the 2D orthographic projection
}

// DDA Circle Drawing Function
void ddacircle(int xc, int yc, int r) {
    float x = 0;
    float y = r;
    float P = 1 - r; // Initial decision parameter for Bresenham-like approach, adaptable to DDA concepts

    glBegin(GL_POINTS);
    while (x <= y) {
        // Plot points in all 8 octants
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        x++;
        if (P < 0) {
            P += 2 * x + 1;
        } else {
            y--;
            P += 2 * (x - y) + 1;
        }
    }
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    ddacircle(circle_xc, circle_yc, circle_r);
    glFlush();
}

// Main function
int main(int argc, char** argv) {
    cout << "Enter circle center (xc yc): ";
    cin >> circle_xc >> circle_yc;

    cout << "Enter circle radius (r): ";
    cin >> circle_r;

    glutInit(&argc, argv);                      // Initialize GLUT
    glutInitWindowSize(600, 600);               // Set window size
    glutInitWindowPosition(100, 100);           // Set window position
    glutCreateWindow("DDA Circle Drawing");     // Create window with title

    init();                                     // Call initialization function
    glutDisplayFunc(display);                    // Register display callback
    glutMainLoop();                             // Enter GLUT event processing loop

    return 0;
}
