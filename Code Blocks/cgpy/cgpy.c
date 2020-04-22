#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//for main program
void ProcessMenu(int value);
void RenderScene(void);
void SetupRC();
void SpecialKeys(int key, int x, int y);
void ChangeSize(int w, int h);
void keyboard(unsigned char keyy,int x,int y);
void myMouse(int button,int state,int x,int y);
void menu();
int fullscreen=0;
//Translation variable
GLfloat xtr=0.0;
GLfloat ytr=0.0;
GLfloat ztr=0.0;
// Rotation amounts
 GLfloat xRot = 0.0f;
 GLfloat yRot = 0.0f;
//Scaling variable
GLfloat zm=1.0;
char str[]= "PROJECT NAME: Interactive object module using OpenGL";
char str1[]= "MYSURU ROYAL INSTITUTE OF TECHNOLOGY,MYSURU";
char str2[]="COMPUTER GRAPHICS VISUALISATION LABORATORY MINI PROJECT";
char str3[]="PREPARED BY:";
char str4[]="GURU PRASAD S ";
char str5[]="YASHAS P and PRAJWAL H S";
char str6[]="GUIDED BY:";
char str7[]="Dr.LOKESH M R and Mr.CHETHAN RAJ C";
char str8[]="Assistant Professors";
char str9[]="MRIT,Mysuru";
char str10[]="CSE Department";
char str11[]="T H A N K Y O U";
void stringdisplay(float a,float c,char *A,int flag)
{
	int j,len=0;
	len=strlen(A)-1;
	glRasterPos2f(a,c);
	if(!flag)
	{
		for(j=0;j<=len;j++)
  	  	   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)A[j]);
	}
	else
	{
		for(j=0;j<=len;j++)
  	  	   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)A[j]);
	}
}
//background screen
void screen()
{
	glColor3f(0.329412,0.329412,0.329412);
	glBegin(GL_POLYGON);
	glVertex3f(-5.0,-5.0,-1.899);
	glVertex3f(5.0,-5.0,-1.899);
	glVertex3f(5.0,5.0,-1.899);
	glVertex3f(-5.0,5.0,-1.899);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-3.1,-1.64,-1.89);
	glVertex3f(3.1,-1.64,-1.89);
	glVertex3f(3.1,1.64,-1.89);
	glVertex3f(-3.1,1.64,-1.89);
	glEnd();
	glColor3f(0.329412,0.329412,0.329412);
	glBegin(GL_POLYGON);
	glVertex3f(-2.6,-1.28,-1.88);
	glVertex3f(2.6,-1.28,-1.88);
	glVertex3f(2.6,1.28,-1.88);
	glVertex3f(-2.6,1.28,-1.88);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-2.1,-0.92,-1.87);
	glVertex3f(2.1,-0.92,-1.87);
	glVertex3f(2.1,0.92,-1.87);
	glVertex3f(-2.1,0.92,-1.87);
	glEnd();
}
//key board function
void keyboard(unsigned char keyy,int x,int y)
{
	if(keyy=='d'||keyy=='D')
	  xtr+=0.2;
	if(keyy=='a'||keyy=='A')
	  xtr-=0.2;
        if(keyy=='w'||keyy=='W')
          ytr+=0.2;
        if(keyy=='z'||keyy=='Z')
	  ytr-=0.2;
	if(keyy=='r'||keyy=='R')
	{
		xtr=0.0;
		ytr=0.0;
		zm=1.0;
	}
	if(keyy=='+'||keyy=='=')
           zm+=0.1;                 /* Zoom in */
	if(keyy=='-'||keyy=='_')
	   zm-=0.1;  /* Zoom out */
	if(keyy=='Q'|| keyy=='q')
	   exit(0);

	if(keyy=='1')  ProcessMenu(2);
	else if(keyy=='b') ProcessMenu(3);
	else if(keyy=='c') ProcessMenu(4);
	else if(keyy=='2') ProcessMenu(5);
	else if(keyy=='e') ProcessMenu(6);
	else if(keyy=='f') ProcessMenu(7);
	else if(keyy=='g') ProcessMenu(8);
	else if(keyy=='h') ProcessMenu(9);
	else if(keyy=='i') ProcessMenu(10);
	else if(keyy=='j') ProcessMenu(11);
	else if(keyy=='k') ProcessMenu(12);
	else if(keyy=='l') ProcessMenu(13);
	else if(keyy=='m') ProcessMenu(14);
	else if(keyy=='n') ProcessMenu(15);
	else if(keyy=='o') ProcessMenu(16);
	else if(keyy=='p') ProcessMenu(17);
	else if(keyy=='3') ProcessMenu(18);
	else if(keyy=='4') ProcessMenu(19);
	else if(keyy=='s') ProcessMenu(20);
	else if(keyy=='t') ProcessMenu(21);
	else if(keyy=='u') ProcessMenu(22);
	else if(keyy=='v') ProcessMenu(23);
	else if(keyy=='5') ProcessMenu(24);
	else if(keyy=='x') ProcessMenu(25);
	else if(keyy=='y') ProcessMenu(26);
	else if(keyy=='6') ProcessMenu(27);
	else if(keyy=='7') ProcessMenu(28);
	else if(keyy=='8') ProcessMenu(29);
	else if(keyy=='9') ProcessMenu(30);
	// Refresh the Window
	glutPostRedisplay();
}
void SpecialKeys(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
	  xRot-= 5.0f;
	if(key == GLUT_KEY_DOWN)
 	  xRot += 5.0f;
	if(key == GLUT_KEY_LEFT)
	  yRot -= 5.0f;
	if(key == GLUT_KEY_RIGHT)
	  yRot += 5.0f;
	if(key > 356.0f)
	  xRot = 0.0f;
	if(key < -1.0f)
 	  xRot = 355.0f;
	if(key > 356.0f)
	  yRot = 0.0f;
	if(key < -1.0f)
	  yRot = 355.0f;
	if (key == GLUT_KEY_F1)
	  fullscreen = !fullscreen;
	if (fullscreen)
	  glutFullScreen();
	// Refresh the Window
	glutPostRedisplay();
}
typedef float point[3];
point v[]={{0.0, 0.0, 1.0}, {0.0, 0.942809, -0.33333},
          {-0.816497, -0.471405, -0.333333}, {0.816497, -0.471405, -0.333333}};
static GLfloat theta[] = {0.0,0.0,0.0};
int n;
void triangle( point a, point b, point c);
void divide_triangle(point a, point b, point c, int m);
void tetrahedron( int m);
void triangle( point a, point b, point c)
/* display one triangle using a line loop for wire frame, a single
normal for constant shading, or three normals for interpolative shading */
{
	glBegin(GL_POLYGON);
	glNormal3fv(a);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}
void divide_triangle(point a, point b, point c, int m)
{
/* triangle subdivision using vertex numbers
righthand rule applied to create outward pointing faces */
	point v1, v2, v3;
	int j;
	if(m>0)
	{
	        for(j=0; j<3; j++) v1[j]=(a[j]+b[j])/2;
	        for(j=0; j<3; j++) v2[j]=(a[j]+c[j])/2;
	        for(j=0; j<3; j++) v3[j]=(b[j]+c[j])/2;
	        divide_triangle(a, v1, v2, m-1);
	        divide_triangle(c, v2, v3, m-1);
	        divide_triangle(b, v3, v1, m-1);
	}
	else
		triangle(a,b,c); /* draw triangle at end of recursion */
}
void tetrahedron( int m)
{
/* Apply triangle subdivision to faces of tetrahedron */
	glColor3f(1.0,1.0,1.0);
	divide_triangle(v[0], v[1], v[2], m);
	glColor3f(0.0,1.0,0.0);
	divide_triangle(v[3], v[2], v[1], m);
	glColor3f(1.0,0.0,0.0);
	divide_triangle(v[0], v[3], v[1], m);
	glColor3f(0.0,0.0,1.0);
	divide_triangle(v[0], v[2], v[3], m);
}
// rect_mesh_vtu.cpp
// Rectangular Mesh using set of points f(i,j)=f(xi,yi) where xi=x0+i*dx, yi=y0+j*dy
#define maxx 20
#define maxy 25
#define dx 0.05
#define dy 0.05
GLfloat x[maxx]={0.0},y[maxy]={0.0};
GLfloat x0=0.2,y00=0.3;  // initial values for x, y
GLint i,j;
// Light values and coordinates
GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };
static int iShape = 1;
// Reset flags as appropriate in response to menu selections
void ProcessMenu(int value)
{
	iShape = value;
	glutPostRedisplay();
}
void ProcessGeoObjects(int value)
{
	iShape=value;
	glutPostRedisplay();
}
// Called to draw scene
void RenderScene(void)
{
	// Clear the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(iShape!=1)
	   screen();
	// Save matrix state and do the rotation
	if(iShape!=1&&iShape!=22)
	{
		glPushMatrix();
		glTranslatef(xtr,ytr,ztr);
		glScalef(zm,zm,zm);
		glRotatef(xRot, 1.0f, 0.0f, 0.0f);
		glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	}
	switch(iShape)
        {
		case 1:
			 glColor3f(1.0,0.0,1.0);
			 stringdisplay(-2.1,1.0,str2,0);
			 glColor3f(0.4,0.7,1.0);
			 stringdisplay(-1.8,1.525,str1,0);
			 glColor3f(0.0,1.0,0.0);
        		 stringdisplay(-1.65,0.4,str,0);//a=-1.6 and b=0.4
			 glColor3f(0.0,1.0,1.0);
			 stringdisplay(1.55,-0.7,str3,0);
			 stringdisplay(1.58,-0.9,str4,0);
			 stringdisplay(1.58,-1.1,str5,0);
			 stringdisplay(-3.1,-0.7,str6,0);
			 stringdisplay(-3.1,-0.85,str7,0);
			 stringdisplay(-3.1,-1.0,str8,0);
			 stringdisplay(-3.1,-1.15,str9,0);
			 stringdisplay(-3.1,-1.3,str10,0);
			 glPointSize(5.0);
			 glColor3f(1.0,0.0,0.0);
         		 glBegin(GL_LINES);
		   	// glVertex2f(-1.7,.35);
		   	 //glVertex2f(1.7,.35);
			 glVertex2f(-3.1,-0.73);
			 glVertex2f(-2.1,-0.73);
			 glVertex2f(2.55,-0.73);
			 glVertex2f(1.55,-0.73);
			 glColor3f(0.0,0.0,1.0);
			 glEnd();
		   	 break;
		case 2:  glColor3f(0.93,0.16,0.96);//med_purple
            		 glutWireCube(1.0f);
            		 break;
	        case 3:
			 glColor3f(0.55,0.09,0.09);//scarlet
        		 glutWireCone(0.30f, 1.1f, 20, 20);
      			 break;
	        case 4:  glColor3f(0.13,0.37,0.31);//hunters green
			 glutWireTorus(0.3f, 1.0f, 10, 25);
            		 break;
	        case 5:  glColor3f(0.439216,0.858824,0.576471);//aquamarine
        		 glutWireDodecahedron();
             		 break;
	        case 6:  glColor3f(0.6,0.8,0.196078);//yellowgreen
        		 glutWireOctahedron();
            		 break;

        	case 7:  glColor3f(0.99,0.8,0.61);//newmidnightblue
            		 glutWireTetrahedron();
           		 break;
	        case 8:	 glColor3f(0.137255,0.556863,0.419608);//sea green
        		 glutWireIcosahedron();
            		 break;
	        case 9:  glColor3f(0.858824,0.439216,0.858824);//orchid
         		 glutWireTeapot(1.0f);
           		 break;
	        case 11: glColor3f(0.309804,0.184314,0.184314);//indian red
        		 glutSolidSphere(1.0f, 25, 25);
           		 break;

        	case 12: glColor3f(0.258824,0.658824,0.435294);//cornflower blue
            		 glutSolidCube(1.0f);
            		 break;
	        case 13: glColor3f(0.556863,0.137255,0.137255);//firebrick
        		 glutSolidCone(0.30, 1.1f, 20, 20);
           		 break;
   	        case 14: glColor3f(0.137255,0.556863,0.137255);//forest green
        		 glutSolidTorus(0.3f, 1.0f, 10, 25);
            		 break;
	        case 15: glColor3f(0.196078,0.8,0.6);//medium aquamarine
         		 glutSolidDodecahedron();
           		 break;
	        case 16: glColor3f(0.22,0.69,0.87);//summersky
        		 glutSolidOctahedron();
           		 break;
	        case 17: glColor3f(0.82,0.57,0.46);//feldspar
        		 glutSolidTetrahedron();
            		 break;
	        case 18: glColor3f(0.85,0.85,0.95);//quartz
        		 glutSolidIcosahedron();
            		 break;
		case 20:
        		 tetrahedron(3);
			 break;
		case 21:
			 glColor3f(0.89,0.47,0.20);//mandarin orange
			 glutWireSphere(1.0f, 25, 25);
 			 break;
		case 22:
			 glColor3f(1.0,0.3,0.3);
			 stringdisplay(-0.5,-0.1,str11,1);
			 glColor3f(1.0,0.0,0.9);
         		 glBegin(GL_LINES);
		   	 glVertex2f(-1.7,-0.15);
		   	 glVertex2f(1.7,-0.15);
			 glEnd();
			 break;
		case 23:
			 glColor3f(1.0,0.0,0.0);
			 glScalef(1.0,1.0,1.0);
			//glTranslatef(0.9,0.5,0.0);
			 glutSolidSphere(0.5f, 25, 25);
		         glColor3f(0.0,0.0,1.0);
			 glTranslatef(0.0,0.0,0.7);
			 glScalef(.65,.65,.65);
			 glutSolidSphere(0.5f, 25, 25);
			 glColor3f(0.0,1.0,0.0);
			 glTranslatef(0.5,0.0,0.8);
			 glScalef(.65,.65,.65);
			 glutSolidSphere(0.5f, 25, 25);
			 glColor3f(1.0,1.0,0.0);
			 glTranslatef(0.5,0.0,-0.9);
			 glScalef(.65,.65,.65);
			 glutSolidSphere(0.5f, 25, 25);
			 glColor3f(0.0,1.0,1.0);
			 glTranslatef(0.0,0.0,-1.0);
			 glScalef(.55,.55,.55);
			 glutSolidSphere(0.5f, 25, 25);
			 glColor3f(0.0,1.0,0.0);
			 glTranslatef(-0.6,0.0,-1.1);
			 glScalef(.65,.65,.65);
			 glutSolidSphere(0.5f, 25, 25);
 			 glColor3f(1.0,1.0,0.7);
			 glTranslatef(-1.0,0.0,0.5);
			 glScalef(.85,.85,.85);
			 glutSolidSphere(0.5f, 25, 25);
			 glColor3f(0.0,1.0,0.0);
			 glTranslatef(-0.90,0.0,1.2);
			 glScalef(.65,.65,.65);
			 glutSolidSphere(0.5f, 25, 25);
			 glColor3f(-1.0,0.0,1.1);
			 glTranslatef(-0.9,0.0,-1.3);
			 glScalef(.55,.55,.55);
			 glutSolidSphere(0.5f, 25, 25);
			 glColor3f(-1.1,0.0,1.2);
			 glTranslatef(1.1,0.0,0.0);
			 glScalef(0.6,0.6,0.6);
			 glutSolidSphere(0.5f, 25, 25);
		         break;
		case 24: glColor3f(0.917647, 0.678431, 0.917647);//plum
  			 glutSolidSphere(0.50f, 25, 25);
			 glTranslatef(0.9,0.5,0.0);
			 glutSolidSphere(0.5f, 25, 25);
			 glTranslatef(-1.8,-1.0,0.0);
			 glutSolidSphere(0.5f, 25, 25);
			 glTranslatef(0.9,0.5,0.0);
			 break;
		case 25: glColor3f(0.36, 0.20, 0.09);//bakerschoc
      			 glScalef(.5,.5,.5);
			 glutSolidSphere(0.50f, 25, 25);
			 glScalef(2.0,2.0,2.0);
			 glTranslatef(0.9,0.5,0.0);
			 glutSolidSphere(0.5f, 25, 25);
			 glTranslatef(-1.8,-1.0,0.0);
			 glScalef(.25,.25,.25);
			 glutSolidSphere(0.5f, 25, 25);
 			 glTranslatef(0.9,0.5,0.0);
			 break;
		case 26:
	            	 break;
		case 29:
			/* draw rectangles */
			 for(i=0;i<maxx;i++)
	   	 	   x[i]=x0+i*dx;    // compute x[i]
			 for(j=0;j<maxy;j++)
			   y[j]=y00+j*dy;  // compute y[i]
			 glColor3f(1.0, 0.0, 1.0);
			 for(i=0;i<maxx-1;i++)
			 for(j=0;j<maxy-1;j++)
			 {
				glColor3f(0.30, 0.80, 0.0);//neon blue
				glBegin(GL_LINE_LOOP);
				glVertex2f(x[i],y[j]);
				glVertex2f(x[i],y[j+1]);
				glVertex2f(x[i+1],y[j+1]);
				glVertex2f(x[i+1],y[j]);
  				glEnd();
				glFlush();
			 }
			 break;
		case 31:
			 exit(0);
		default:

			 glColor3f(0.91,0.76,0.65);//lightwood
        		 glutSolidTeapot(1.0f);
            		 break;
        }
	// Restore transformations
	glPopMatrix();
	// Flush drawing commands
	glutSwapBuffers();
}
// This function does any needed initialization on the rendering
// context.
void SetupRC()
{
	// Black background
	glClearColor(0.0f, 0.0f,0.0f, 0.0f );
	glColor3f(0.0,0.0,1.0);
	glPointSize(5.0);
        // Enable Depth Testing
        glEnable(GL_DEPTH_TEST);
	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable (GL_LIGHT0);
	glShadeModel (GL_SMOOTH);
	// Setup and enable light 0
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glEnable(GL_LIGHT0);
	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);
	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	// All materials hereafter have full specular reflectivity
	// with a high shine
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,specref);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,128);
	// Set drawing color to blue
	//glColor3ub(0,0,0);
	glColor3f(0.0,0.0,1.0);
}
void ChangeSize(int w, int h)
{
	GLfloat	 lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };
	GLfloat nRange = 1.9f;
	// Prevent a divide by zero
	if(h == 0)
	  h = 1;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);
	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
	  glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
	else
	  glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);
	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
}
void menu()
{
	int nSolidMenu;
	int nWireMenu;
	int nMainMenu;
	int glutobject;
	int control;
	int glutfunc;
	int reference;
	int demo;
	// Create the Menu
	nWireMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Cube",2);
	glutAddMenuEntry("Cone",3);
	glutAddMenuEntry("Torus",4);
	glutAddMenuEntry("Dodecahedron",5);
	glutAddMenuEntry("Octahedron",6);
	glutAddMenuEntry("Tetrahedron",7);
	glutAddMenuEntry("Icosahedron",8);
	glutAddMenuEntry("Teapot",9);
	glutAddMenuEntry("Rectangular mesh",29);
	nSolidMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Sphere",11);
	glutAddMenuEntry("Cube",12);
	glutAddMenuEntry("Cone",13);
	glutAddMenuEntry("Torus",14);
	glutAddMenuEntry("Dodecahedron",15);
	glutAddMenuEntry("Octahedron",16);
	glutAddMenuEntry("Tetrahedron",17);
	glutAddMenuEntry("Icosahedron",18);
	glutAddMenuEntry("Teapot",19);
	glutAddMenuEntry("3D Sierpinski gasket",20);
	control= glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Scaling => Zoomin  '+'  and  Zoomout '-'",26);
	glutAddMenuEntry("Translation =>  'd|D' along +X-axis, 'a|a' along -X-axis, 'w|W' along +Y-axis, 'z|Z' along -Y-axis ",26);
	glutAddMenuEntry("Rotation=> 'arrow up and down' about X-axis and 'arrow left and right' about Y-axis",26);
	glutAddMenuEntry("Fullscreen =>'F1'",26);
	glutAddMenuEntry("Reset Object => 'R|r'",26);
	glutAddMenuEntry("Exit Screen => 'Q|q'",26);
	glutobject= glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Solid cone =>        glutSolidCone (GLdouble base, GLdouble height, GLint slices, GLint stacks)",26);
	glutAddMenuEntry("Solid cube =>        glutSolidCube (GLdouble width)",26);
	glutAddMenuEntry("SolidCylinder =>     glutSolidCylinder (GLdouble radius, GLdouble height, GLint slices, GLint stacks)",26);
	glutAddMenuEntry("SolidDodecahedron => glutSolidDodecahedron (void)",26);
	glutAddMenuEntry("SolidIcosahedron =>  glutSolidIcosahedron (void)",26);
	glutAddMenuEntry("SolidOctahedron =>   glutSolidOctahedron (void)",26);
	glutAddMenuEntry("SolidSphere =>       glutSolidSphere (GLdouble radius, GLint slices, GLint stacks)",26);
	glutAddMenuEntry("SolidTeapot =>       glutSolidTeapot (GLdouble size)",26);
	glutAddMenuEntry("SolidTetrahedron => glutSolidTetrahedron (void)",26);
	glutAddMenuEntry("SolidTorus =>        glutSolidTorus (GLdouble dInnerRadius, GLdouble dOuterRadius, GLint nSides, GLint nRings)",26);
	glutAddMenuEntry("WireCone =>         glutWireCone (GLdouble base, GLdouble height, GLint slices, GLint stacks)",26);
	glutAddMenuEntry("WireCube =>         glutWireCube (GLdouble width)",26);
	glutAddMenuEntry("WireCylinder =>      glutWireCylinder (GLdouble radius, GLdouble height, GLint slices, GLint stacks)",26);
	glutAddMenuEntry("WireDodecahedron =>  glutWireDodecahedron (void)",26);
	glutAddMenuEntry("WireIcosahedron =>   glutWireIcosahedron (void)",26);
	glutAddMenuEntry("WireOctahedron =>    glutWireOctahedron (void)",26);
	glutAddMenuEntry("WireSphere =>       glutWireSphere (GLdouble radius, GLint slices, GLint stacks)",26);
	glutAddMenuEntry("WireTeapot =>        glutWireTeapot (GLdouble size)",26);
	glutAddMenuEntry("WireTetrahedron =>   glutWireTetrahedron (void)",26);
	glutAddMenuEntry("WireTorus =>        glutWireTorus (GLdouble dInnerRadius, GLdouble dOuterRadius, GLint nSides, GLint nRings)",26);
	glutAddMenuEntry("",26);
	glutfunc=glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("........................................ROTATION............................................",26);
	glutAddMenuEntry("void glRotate[fd](TYPE angle,TYPE x,TYPE y,TYPE z)  :- Alters the current matrix by rotation of ",26);
	glutAddMenuEntry("angle degree about axis x,y or z,TYPE is either GLfloat or GLdouble",26);
	glutAddMenuEntry("........................................SCALING.............................................",26);
	glutAddMenuEntry(" void glScale[fd](TYPE sx,TYPE sy,TYPE sz)  :- Alters the current matrix by scaling of sx,sy ",26);
	glutAddMenuEntry(" and sz.TYPE is either GLfloat or GLdouble",26);
	glutAddMenuEntry("........................................TRANSLATION...........................................",26);
      	glutAddMenuEntry(" void glTranslate[fd](TYPE dx,TYPE dy,TYPE dz) :- Alters the current matrix by displacement of dx,",26);
      	glutAddMenuEntry("dy and dz. TYPE is either GLfloat or GLdouble",26);
      	glutAddMenuEntry("",26);
      	glutAddMenuEntry("",26);
      	glutAddMenuEntry("",26);
      	glutAddMenuEntry("",26);
	reference=glutCreateMenu(ProcessMenu);
	glutAddMenuEntry(".................................Reference Books..................................",26);
	glutAddMenuEntry("1:Computer Graphics Using OpenGL-F.S. Hill,Jr.-> Pearson Education",26);
	glutAddMenuEntry("2:Computer Graphics-James D Foley,Andries Van Dam->Addision-Wesley",26);
	glutAddMenuEntry("3:Computer Graphics-OpenGL Version-Donald Hearn and Pauline Baker->Pearsion Education",26);
      	glutAddMenuEntry("....................................Web Sites......................................",26);
	glutAddMenuEntry("1: http://opengl.org",26);
	glutAddMenuEntry("2: http://unreal.srk.fer.hr/theredbook",26);
	glutAddMenuEntry("3: http://www.sun.com/software/graphics/opengl/index.xml",26);
      	glutAddMenuEntry("",26);
	demo=glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Rotation Demonstration",21);
	glutAddMenuEntry("Translation Demonstration",24);
	glutAddMenuEntry("Scaling Demonstration",25);
	nMainMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Welcome Page",1);
	glutAddSubMenu("Select Object(Wire)", nWireMenu);
   	glutAddSubMenu("Select Object(Solid)", nSolidMenu);
	glutAddSubMenu("Demonstration",demo);
	glutAddSubMenu("Key Control",control);
        glutAddSubMenu("GLUT Object Function Syntax",glutobject);
        glutAddSubMenu("Transformation Functions Used",glutfunc);
	glutAddMenuEntry("Example",23);
	glutAddSubMenu("References",reference);
	glutAddMenuEntry("Thank You",22);
	glutAddMenuEntry("Exit",31);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Interactive object module using OpenGL");
	glutInitWindowPosition(0,0);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(SpecialKeys);
	glColor3f(1.0,0.0,0.0);
	menu();
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
	return 0;
}



