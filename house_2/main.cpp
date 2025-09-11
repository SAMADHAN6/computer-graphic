#include <GL/glut.h>
void displayMe(void)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.2f);
         glVertex3f(0.0,0.0,0.0);
         glVertex3f(0.2,0.0,0.0);
         glVertex3f(0.2,0.4,0.0);
         glVertex3f(0.0,0.4,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(0.0,0.4);
        glVertex2f(0.1,0.6);
        glVertex2f(0.2,0.4);

    glEnd();
//3
    glBegin(GL_POLYGON);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(0.5,0.6);
        glVertex2f(0.2,0.4);
        glVertex2f(0.2,0.0);
        glVertex2f(0.5,0.2);

    glEnd();
//door
    glBegin(GL_POLYGON);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(0.1,0.0);
        glVertex2f(0.15,0.0);
        glVertex2f(0.15,0.2);
        glVertex2f(0.1,0.2);


    glEnd();
    glBegin(GL_POLYGON);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(0.1,0.6);
        glVertex2f(0.2,0.4);
        glVertex2f(0.5,0.6);
        glVertex2f(0.4,0.8);


    glEnd();

    glColor3f(0.f, 0.9f, 0.5f);

glBegin(GL_QUADS);
    glVertex2f(-0.3f,  -0.2f);
    glVertex2f(-0.3f, -0.7f);
    glVertex2f( -0.2f, -0.7f);
    glVertex2f( -0.2f,  -0.2f);
glEnd();

glBegin(GL_QUADS);
    glVertex2f(-0.5f,  -0.5f);
    glVertex2f(-0.5f, -0.4f);
    glVertex2f( 0.0f, -0.4f);
    glVertex2f( 0.0f,  -0.5f);
glEnd();






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
