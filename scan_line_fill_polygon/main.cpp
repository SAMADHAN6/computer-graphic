// Polygon Filling using Scan Line Algorithm
#include <GL/glut.h>
#include <iostream>
using namespace std;

float x1_, x2, x3, x4, y1_, y2, y3, y4;

void draw_pixel(int x, int y) {
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void edgedetect(float x1, float y1, float x2, float y2, int *le, int *re) {
    float temp, x, mx;
    int i;

    // Swap coordinates if needed
    if (y1 > y2) {
        temp = y1; y1 = y2; y2 = temp;
        temp = x1; x1 = x2; x2 = temp;
    }

    if (y1 == y2)
        mx = x2 - x1;
    else
        mx = (x2 - x1) / (y2 - y1);

    x = x1;

    for (i = (int)y1; i <= (int)y2; i++) {
        if (x < le[i])
            le[i] = (int)x;
        if (x > re[i])
            re[i] = (int)x;
        x += mx;
    }
}

void scanfill(float x1, float y1, float x2, float y2,
              float x3, float y3, float x4, float y4) {

    int le[500], re[500];
    int i, y;

    for (i = 0; i < 500; i++) {
        le[i] = 500;
        re[i] = 0;
    }

    edgedetect(x1, y1, x2, y2, le, re);
    edgedetect(x2, y2, x3, y3, le, re);
    edgedetect(x3, y3, x4, y4, le, re);
    edgedetect(x4, y4, x1, y1, le, re);

    for (y = 0; y < 500; y++) {
        if (le[y] <= re[y]) {
            for (i = le[y]; i <= re[y]; i++)
                draw_pixel(i, y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Define the polygon points (example coordinates)
    x1_ = 100; y1_ = 100;
    x2 = 300; y2 = 100;
    x3 = 300; y3 = 300;
    x4 = 100; y4 = 300;

    // Draw filled polygon
    scanfill(x1_, y1_, x2, y2, x3, y3, x4, y4);

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scan Line Polygon Fill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
