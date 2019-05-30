#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
typedef float point[3];

point V[]={{0.0,0.0,1.0},{0.0,0.9,-0.3},{-0.8,-0.5,-0.3},{0.8,-0.5,-0.3}};
int n;

void triangle(point a,point b,point c)
{
glBegin(GL_POLYGON);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}
void divide_triangle(point a,point b,point c,int m)
{
point v1,v2,v3;
int i,j;
if(m>0)
{
for(j=0;j<3;j++)
v1[j]=(a[j]+b[j])/2;
for(j=0;j<3;j++)
v2[j]=(a[j]+c[j])/2;
for(j=0;j<3;j++)
v3[j]=(b[j]+c[j])/2;
divide_triangle(a,v1,v2,m-1);//12
divide_triangle(c,v2,v3,m-1);//23
divide_triangle(b,v3,v1,m-1);//31
}
else (triangle(a,b,c));
}
void tetrahedron(int m)
{
glColor3f(1.0,0.0,0.0);
divide_triangle(V[0],V[1],V[2],m);//012
glColor3f(0.0,0.0,0.0);           //321
divide_triangle(V[3],V[2],V[1],m);//031
glColor3f(0.0,0.0,1.0);           //023
divide_triangle(V[0],V[3],V[1],m);
glColor3f(0.0,1.0,0.0);
divide_triangle(V[0],V[2],V[3],m);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
tetrahedron(n);
glFlush();
}
void myReshape(int w,int h)
{
glClearColor(1.0,1.0,1.0,1.0);
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2.0, 2.0, -2.0 , 2.0, -10.0, 10.0);
glMatrixMode(GL_MODELVIEW);
}
void main(int argc,char **argv)
{
printf("Enter the number of division");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowPosition(100,50);
glutInitWindowSize(500,500);
glutCreateWindow("Tetrahedron");
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
}
