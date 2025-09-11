#include <GL/glut.h>
void displayMe(void)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.2f);
         glVertex3f(0.0,0.0,0.0);
         glVertex3f(0.5,0.0,0.0);
         glVertex3f(0.5,0.5,0.0);
         glVertex3f(0.0,0.5,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(0.0,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.25,0.75);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(0.2,0.0);
        glVertex2f(0.3,0.0);
        glVertex2f(0.2,0.25);
        glVertex2f(0.3,0.25);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(0.1,0.4);
        glVertex2f(0.1,0.3);
        glVertex2f(0.15,0.3);
        glVertex2f(0.15,0.4);


    glEnd();
    glBegin(GL_POLYGON);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(0.3,0.3);
        glVertex2f(0.3,0.4);
        glVertex2f(0.35,0.4);
        glVertex2f(0.35,0.3);

    glEnd();


    glBegin(GL_POLYGON);

        glColor3f(0.0f,1.0f,1.0f);
        glVertex2f(0.7,0.0);
        glVertex2f(0.8,0.0);
        glVertex2f(0.8,0.4);
        glVertex2f(0.7,0.4);

    glEnd();

    glBegin(GL_POLYGON);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(0.6,0.4);
        glVertex2f(0.9,0.4);
        glVertex2f(0.8,0.7);


    glEnd();
// mountains

    glBegin(GL_POLYGON);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-0.9,0.0);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.0,0.0);


    glEnd();









    glFlush();

}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("sweet_home");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
