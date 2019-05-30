#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define PI 3.14
GLfloat t[3][3]={{100.0,175.0,250.0},{300.0,400.0,300.0},{1.0,1.0,1.0}};
GLfloat rot[3][3]={{0},{0},{0}};
GLfloat res[3][3]={{0},{0},{0}};
GLfloat theta;
GLfloat h=100.0;
GLfloat k=300.0;

void multiply()
{
 int i,j,l;
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   res[i][j]=0;
   for(l=0;l<3;l++)
   {
    res[i][j]=res[i][j]+rot[i][l]*t[l][j];
   }
  }
 }
}

void rotate()
{
 GLfloat m,n;
 m=-h*(cos(theta)-1)+k*(sin(theta));
 n=-k*(cos(theta)-1)-h*(sin(theta));
 rot[0][0]=cos(theta);
 rot[0][1]=-sin(theta);
 rot[0][2]=m;
 rot[1][0]=sin(theta);
 rot[1][1]=cos(theta);
 rot[1][2]=n;
 rot[2][0]=0;
 rot[2][1]=0;
 rot[2][2]=1;
 multiply();
}

void draw_triangle()
{
 glColor3f(1.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
  glVertex2f(t[0][0],t[1][0]);
  glVertex2f(t[0][1],t[1][1]);
  glVertex2f(t[0][2],t[1][2]);
 glEnd();
}

void draw_rot_triangle()
{
 glColor3f(0.0,1.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(res[0][0],res[1][0]);
 glVertex2f(res[0][1],res[1][1]);
 glVertex2f(res[0][2],res[1][2]);
 glEnd();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_triangle();
rotate();
draw_rot_triangle();
glFlush();
}

void init()
{
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,500.0,0.0,500.0);
glMatrixMode(GL_MODELVIEW);
}
void main(int argc,char **argv)
{
 printf("enter the theta value");
 scanf("%f",&theta);
 theta=theta*PI/180;
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(500,500);
 glutCreateWindow("triangle rotation");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
}
