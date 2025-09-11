#include <iostream>
#include <GL/glut.h>
using namespace std;

int x1, y1, x2, y2; // Points given by the user

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;
    int p = 2 * dy - dx;

    while (x <= x2) {
        drawPixel(x, y);
        x++;
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++;
            p = p + 2 * (dy - dx);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0); // Red color
    drawLine(x1, y1, x2, y2); // Use the points given by user
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1); // White background
    glColor3f(0, 0, 0);       // Black drawing color
    glPointSize(3);           // Bigger dots
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500); // Coordinate system
}

int main(int argc, char** argv) {
    cout << "Enter starting point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending point (x2 y2): ";
    cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line with Input");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
