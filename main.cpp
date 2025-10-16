#include <GL/glut.h>
#include <math.h>

int ww = 500, wh = 500;
float fillColor[3] = {1.0, 0.0, 0.0};
float borderColor[3] = {0.0, 0.0, 0.0};

void setPixel(int x, int y, float color[3]) {
    glBegin(GL_POINTS);
    glColor3fv(color);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void getPixel(int x, int y, float pixels[3]) {
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixels);
}

int isSameColor(float c1[3], float c2[3]) {
    float tol = 0.05f;
    return (fabs(c1[0] - c2[0]) < tol &&
            fabs(c1[1] - c2[1]) < tol &&
            fabs(c1[2] - c2[2]) < tol);
}

int isBorderPixel(float pixel[3]) {
    return (pixel[0] < 0.2f && pixel[1] < 0.2f && pixel[2] < 0.2f);
}

void boundaryFill8(int x, int y, float fillColor[3], float borderColor[3]) {
    float current[3];
    getPixel(x, y, current);

    if (isBorderPixel(current) || isSameColor(current, fillColor)) return;

    setPixel(x, y, fillColor);
    boundaryFill8(x + 1, y, fillColor, borderColor);
    boundaryFill8(x - 1, y, fillColor, borderColor);
    boundaryFill8(x, y + 1, fillColor, borderColor);
    boundaryFill8(x, y - 1, fillColor, borderColor);
    boundaryFill8(x + 1, y + 1, fillColor, borderColor);
    boundaryFill8(x - 1, y + 1, fillColor, borderColor);
    boundaryFill8(x + 1, y - 1, fillColor, borderColor);
    boundaryFill8(x - 1, y - 1, fillColor, borderColor);
}

void drawPolygon() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(150, 150);
        glVertex2i(350, 150);
        glVertex2i(350, 350);
        glVertex2i(150, 350);
    glEnd();
    glFlush();
}

void mouse(int btn, int state, int x, int y) {
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int y2 = wh - y;
        boundaryFill8(x, y2, fillColor, borderColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawPolygon();
    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(ww, wh);
    glutCreateWindow("Strict Boundary-Fill 8-Connected ");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    myinit();
    glutMainLoop();
    return 0;
}
