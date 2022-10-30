#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>
#include <glut.h>
#define pi (2*acos(0.0))
#define sqrt2 (sqrt(2))

typedef struct point
{
	double x,y,z;
}Point;
int slidetmp;
int winangle = 0;
int doorangle = 0;
int tmp=0;
int drotate = 0;
bool drawAxes = true;
float tyreAngle = 0;
float boxred = 0, boxgreen = 0, boxblue = 0;
float quadAngle = 0;
float boxAngle = 0;
float doorslide = 0;
double boxScaleFactor = 1;
float tyreScaleFactor = 1;
float tinyBoxAngle = 0;
float background = 0;
float windowup =0;

Point pos, u, r, l;

void displayAxes()
{
	if(drawAxes)
	{
		glBegin(GL_LINES);
		{
		    glColor3f(1.0, 0, 0);

			glVertex3f( 500,0,0); // a point on pos x axis
			glVertex3f(-500,0,0); // a point on neg x axis

			glColor3f(0, 1.0, 0);

			glVertex3f(0,-500,0); // a point on pos y axis
			glVertex3f(0, 500,0); // a point on neg y axis

			glColor3f(0, 0, 1.0);

			glVertex3f(0,0, 500);  // a point on pos z axis
			glVertex3f(0,0,-500);   // a point on neg z axis
		}
		glEnd();
	}
}

Point func(Point vect, Point perp, int dir)
{
    double c = cos(pi/180);
    double s = dir * sin(pi/180);
    Point point;
    point.x = c * vect.x + s * perp.x;
    point.y = c * vect.y + s * perp.y;
    point.z = c * vect.z + s * perp.z;
    c = sqrt(point.x*point.x + point.y*point.y + point.z*point.z);
    point.x /= c;
    point.y /= c;
    point.z /= c;
    return point;
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){
		case '1': {
            Point l1 = func(l, r, -1);
            r = func(r, l, 1);
            l = l1;
            break;
		}
		case '2': {
            Point l1 = func(l, r, 1);
            r = func(r, l, -1);
            l = l1;
            break;
		}

		case '3': {
            Point u1 = func(u, l, -1);
            l = func(l, u, 1);
            u = u1;
            break;
        }
        case '4': {
            Point u1 = func(u, l, 1);
            l = func(l, u, -1);
            u = u1;
            break;
        }
        case '5': {
            Point r1 = func(r, u, -1);
            u = func(u, r, 1);
            r = r1;
            break;
        }
        case '6':{
            Point r1 = func(r, u, 1);
            u = func(u, r, -1);
            r = r1;
            break;
        }
        case '7':{
            tyreScaleFactor += 0.2;
            break;
        }
        case '8':{
            tyreScaleFactor -= 0.2;
            break;
        }
        case '9':{
            if (winangle == -50)
                break;
            else
            {
                winangle -= 2;
                break;
            }
        }
        case '0':{
            if (winangle == 0)
                break;
            else
            {
                winangle += 2;
                break;
            }
        }

        case 'l':{
		        boxAngle -= 5;
		        //printf("BoxAngle %f\n", boxAngle);
		        break;
		    }
        case 'L':{
		        boxAngle -= 5;
		        //printf("BoxAngle %f\n", boxAngle);
		        break;
		    }
        case 'r':{
		        boxAngle += 5;
		        //printf("BoxAngle %f\n", boxAngle);
		        break;
		    }
        case 'R':{
		        boxAngle += 5;
		        //printf("BoxAngle %f\n", boxAngle);
		        break;
		    }
        case 'U':{
            //printf("boxScaleFactor %f\n", boxScaleFactor);
            if (int(boxScaleFactor)== 2)
                break;
            else
            {
                boxScaleFactor= boxScaleFactor+ .1;
                break;
            }
        }
        case 'u':{
           // printf("boxScaleFactor %f\n", boxScaleFactor);
            if (int(boxScaleFactor)== 2)
                break;
            else
            {
                boxScaleFactor= boxScaleFactor+ .1;
                break;
            }
        }

        case 'd':{

            if (boxScaleFactor >0)
            {
                boxScaleFactor-= .1;
                    if(boxScaleFactor<0)
                        boxScaleFactor=0;
               // printf("boxScaleFactor %f\n", boxScaleFactor);
                break;
            }
        }
        case 'D':{

            if (boxScaleFactor >0)
            {
                boxScaleFactor-= .1;
                    if(boxScaleFactor<0)
                        boxScaleFactor=0;
                //printf("boxScaleFactor %f\n", boxScaleFactor);
                break;
            }
        }


		default:
			break;
	}
}
Point campos(Point vect, Point perp, int dir)  ///Changes camera position
{
    //Point point;
    vect.x = (vect.x +  4* dir*perp.x);
    vect.y = (vect.y +  4* dir*perp.y);
    vect.z = (vect.z +  4* dir*perp.z);
    return vect;
}
void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN: // down arrow
		    {
		        pos = campos(pos,l,-1);
                break;
		    }

		case GLUT_KEY_UP:   // up arrow
		    {
		        pos = campos(pos,l, 1);
                break;
		    }

		case GLUT_KEY_RIGHT:    // right arrow
		    {
		        pos = campos(pos,r,1);
                break;
		    }

		case GLUT_KEY_LEFT:     // left arrow
		    {
		        pos = campos(pos,r,-1);
                break;
		    }

		case GLUT_KEY_PAGE_UP:
		    {
                pos = campos(pos,u,1);
                break;
		    }

		case GLUT_KEY_PAGE_DOWN:
		    {
		        pos = campos(pos,u,-1);
                break;
		    }

		case GLUT_KEY_HOME:{
            if (doorslide == 50)
                break;
            else
            {
                doorslide+= 5;
                //printf("doorslide %f\n", boxScaleFactor);
                break;
            }
        }

        case GLUT_KEY_END:{
            if (doorslide == 0)
                break;
            else
            {
                doorslide-= 5;
                //printf("doorslide %f\n", boxScaleFactor);
                break;
            }
        }
		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_RIGHT_BUTTON:
			if(state == GLUT_DOWN) // 2 times?? in ONE click? -- solution is checking DOWN or UP
            {
                printf("Mouse Right Button Clicked\n");
			}
			else if(state == GLUT_UP)
            {
                printf("Mouse Right Button Released\n");
            }
            break;
		default:
			break;
	}
}

void displayTyre(float tyreRadius, float tyreWidth, int id)
{
    int tyreSlices = 10;
    float sliceWidth = (2 * M_PI * tyreRadius) / tyreSlices;
    float sliceAngle = 360 / tyreSlices;

    float halfTyreWidth = tyreWidth / 2, quartTyreWidth = halfTyreWidth / 2;
    float halfSliceWidth = sliceWidth / 2;


    if(id==1) ///Spikes inside the tyre
    {
        for(int i=0; i<tyreSlices; i++)
        {
            if (i%2 ==0)
            {
                    glColor3f(1, 0, 0);
                  //  tmp =0;
            }
            else
            {
                    glColor3f(0, 0, 1);
                   // tmp = 1;
            }
            glPushMatrix();
            glRotatef(sliceAngle*i, 1, 0, 0);
            glBegin(GL_QUADS);
            {
                    glVertex3f(halfTyreWidth,-tyreRadius/2, 0);
                    glVertex3f(-halfTyreWidth, -tyreRadius/2, 0);
                    glVertex3f(-halfTyreWidth, -tyreRadius, 0);
                    glVertex3f(halfTyreWidth, -tyreRadius, 0);
            }

    glEnd();
    glPopMatrix();

        }
    }
    ///Creates the small and large tyre
    for(int i=0; i<tyreSlices; i++)
    {
        if (i%2==0)
        {
               glColor3f(1, 1, 1);
        }
        else
        {
            glColor3f(0, 0, 0);
        }
        glPushMatrix();
        glRotatef(sliceAngle*i, 1, 0, 0);
        glTranslatef(0, tyreRadius, 0);
        glBegin(GL_QUADS);
        {
            glVertex3f(halfTyreWidth, 0, halfSliceWidth);
            glVertex3f(halfTyreWidth, 0, -halfSliceWidth);
            glVertex3f(-halfTyreWidth, 0, -halfSliceWidth);
            glVertex3f(-halfTyreWidth, 0, halfSliceWidth);
        }
        glEnd();
        glPopMatrix();
    }
}

void displayQuad(float quadLength, float quadWidth ,float id) // width along x axis, length along z axis
{
    float halfQuadWidth = quadWidth / 2, halfQuadLength = quadLength / 2;
    float r,g,b,r1,r2,r3;
    if(id==1)
    {
        r=0,g=0,b=1;
        r1=1,r2=1,r3=1;
    }
    else if (id==2)
    {
        r=1,g=1,b=1;
        r1=0,r2=0,r3=1;
    }
    else
    {
        r=1,g= 1,b= 0;
        r1=1,r2=1,r3=0;
    }

    glBegin(GL_QUADS);
    {

        /** Gradient Fill Quad **/

        glColor3f(r,g, b);
        glVertex3f(halfQuadWidth, 0, halfQuadLength);
        glVertex3f(halfQuadWidth, 0, -halfQuadLength);
        glColor3f(r1,r2,r3);
        glVertex3f(-halfQuadWidth, 0, -halfQuadLength);
        glVertex3f(-halfQuadWidth, 0, halfQuadLength);


    }
    glEnd();

}
void displaywindow(float quadLength, float quadWidth ) // width along x axis, length along z axis
{
    float halfQuadWidth = quadWidth / 2, halfQuadLength = quadLength / 2;
    float r,g,b,r1,r2,r3;

        r=0.992,g= 0.894,b= 0.149;
        r1=0.992,r2=0.894,r3=0.149;
    glBegin(GL_QUADS);
    {
        glColor3f(r,g, b);
        glVertex3f(0, halfQuadWidth, 0);
        glVertex3f(0, halfQuadWidth, -quadLength);
        glColor3f(r1,r2,r3);
        glVertex3f(0, -halfQuadWidth, -quadLength);
        glVertex3f(0, -halfQuadWidth, 0);

    }
    glEnd();

}
void displaybackdoor(float quadLength, float quadWidth, int id ) // width along x axis, length along z axis
{
    float halfQuadWidth = quadWidth / 2, halfQuadLength = quadLength / 2;
    float r,g,b,r1,r2,r3;
    r=0,g=0,b=1;
    r1=1,r2=1,r3=1;
    glBegin(GL_QUADS);
    {
        if(id ==1)
        {
            glColor3f(r1,r2, r3);
            glVertex3f(-quadWidth, 0, halfQuadLength);
            glVertex3f(-quadWidth, 0, -halfQuadLength);
            glColor3f(r,g,b);
            glVertex3f(0,0, -halfQuadLength);
            glVertex3f(0, 0, halfQuadLength);
        }
        else
        {
            glColor3f(r1,r2, r3);
            glVertex3f(quadWidth, 0, halfQuadLength);
            glVertex3f(quadWidth, 0, -halfQuadLength);
            glColor3f(r,g,b);
            glVertex3f(0,0, -halfQuadLength);
            glVertex3f(0, 0, halfQuadLength);
        }
    }
    glEnd();

}
void displayBox(float boxLength, float boxWidth, float boxHeight, float boxred,
                float boxgreen, float boxblue) // length -> x axis, width -> yaxis, height -> z axis
{
    float halfBoxLength = boxLength / 2, halfBoxWidth = boxWidth / 2, halfBoxHeight = boxHeight / 2;
    glBegin(GL_QUADS);
    {
        glColor3f(boxred, boxgreen, boxblue);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);

        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);


        glColor3f(boxred-=0.21, boxgreen-=0.33, boxblue-=0.3);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glColor3f(boxred, boxgreen, boxblue-=0.25);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
    }
    glEnd();
}


void displayScene()
{
    //Primitive Object dimensions

    float quadLength = 170, quadWidth = 100;
    float largeBoxLength = 300, largeBoxWidth = 180, largeBoxHeight =30;
    float smallBoxLength = 280, smallBoxWidth = 160, smallBoxHeight = 220;
    /** \brief
     *
     * \param
     * \param
     * \return
     *
     */
    float ceilingLength = 300, ceilingWidth = 180, ceilingHeight = 10;
    float tinyBoxLength = 10, tinyBoxWidth = 12, tinyBoxHeight = 10;
    float tyreRadius = 52, tyreWidth = 25;

    /** Stair Creation **/
    float fstairLength = 150, fstairWidth = 70, fstairHeight = 10;
    float sstairLength = 130, sstairWidth = 60, sstairHeight = 10;
    float tstairLength = 110, tstairWidth = 50, tstairHeight = 10;


    /** Upper Most Box **/
    float upBoxLength = 120, upBoxWidth = 30, upHeight =150;

    /** Principal Axes **/
    displayAxes();

    /**/
    glRotatef(boxAngle, 0, 0, 1);
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);

    /** Floor**/

    displayBox(largeBoxLength, largeBoxWidth, largeBoxHeight, boxred = 0,boxgreen=0,boxblue = 0.80);

    /**/

    /** Wall**/

    glPushMatrix();
    glTranslatef(0, 0, (smallBoxHeight/2) + (largeBoxHeight/2)); // places the small box on top of the large box
    displayBox(smallBoxLength, smallBoxWidth, smallBoxHeight, boxred = .80,boxgreen=0,boxblue = 0); // small box
    glPopMatrix();
    /**/

     /** Ceiling **/
    glPushMatrix();
    glTranslatef(0, 0, smallBoxHeight + largeBoxHeight/2); // places the small box on top of the large box
   displayBox(ceilingLength, ceilingWidth, ceilingHeight, boxred = 0,boxgreen=0.80,boxblue = 0); // small box
    glPopMatrix();
    /** Upper Most Box **/
    glPushMatrix();
    glTranslatef(0, 0, smallBoxHeight + largeBoxHeight/2+upHeight/2); // places the small box on top of the large box
   displayBox(upBoxLength, upBoxWidth, upHeight, boxred = 1,boxgreen=0.80,boxblue = .1); // small box
    glPopMatrix();
    /** Stairs Stack **/
    glPushMatrix();
    glTranslatef(0, 0, -(largeBoxHeight/2 - fstairHeight/2));
    glTranslatef(0, (largeBoxWidth/2 + fstairWidth/2), 0);
    displayBox(fstairLength, fstairWidth , fstairHeight, boxred = .627,boxgreen=0.635,boxblue = 0.635);
    glPopMatrix();

    /** 2nd Stair **/
    glPushMatrix();
    glTranslatef(0, 0, -(largeBoxHeight/2 -fstairHeight- fstairHeight/2));
    glTranslatef(0, (largeBoxWidth/2 + sstairWidth/2), 0);
    displayBox(sstairLength, sstairWidth , sstairHeight, boxred = 1,boxgreen=0.80,boxblue = 0);
    glPopMatrix();
    /** 3rd Stair **/
    glPushMatrix();
    glTranslatef(0, 0, -(largeBoxHeight/2-2*fstairHeight-fstairHeight/2));
    glTranslatef(0, (largeBoxWidth/2 + tstairWidth/2), 0);
    displayBox(tstairLength, tstairWidth , tstairHeight, boxred = 1,boxgreen=0.80,boxblue = .9);
    glPopMatrix();

    /** Door **/

    /** First Half of Front Door **/
    glPushMatrix();
    glTranslatef(doorslide, 0, 0);
    glTranslatef(0, 0, largeBoxHeight/2+quadLength/2);
    glTranslatef(0, (smallBoxWidth/2+2), 0);
    glTranslatef(quadWidth/4, 0, 0);
    displayQuad(quadLength, quadWidth/2,1); //1 is an id to see which part of door it is
    glPopMatrix();

    /** 2nd Half of Front Door **/
    glPushMatrix();
    glTranslatef(-doorslide, 0, 0);
    glTranslatef(0, 0, largeBoxHeight/2+quadLength/2);
    glTranslatef(0, (smallBoxWidth/2+2), 0);
    glTranslatef(-quadWidth/4, 0, 0);
    displayQuad(quadLength, quadWidth/2 ,2);
    glPopMatrix();

    /** Back Door **/
    /** First Half of Door **/
    glPushMatrix();
    glTranslatef(0, 0, largeBoxHeight/2+quadLength/2);
    glTranslatef(0, -(smallBoxWidth/2+2), 0);
    glTranslatef(quadWidth/2, 0, 0);
    glRotatef(doorangle,0,0,1);
   displaybackdoor(quadLength, quadWidth/2,1); //1 is an id to see which part of door it is
    glPopMatrix();

    /** 2nd Half of Door **/
    glPushMatrix();
    glTranslatef(0, 0, largeBoxHeight/2+quadLength/2);
    glTranslatef(0, -(smallBoxWidth/2+2), 0);
    glTranslatef(-quadWidth/2, 0, 0);
    glRotatef(-doorangle,0,0,1);
    displaybackdoor(quadLength, quadWidth/2 ,2);
    glPopMatrix();

    /** Upper ceil of front door **/
    float dceillength = 100, dceilWidth = 10, dceilHeight = 10;
    glPushMatrix();
    glTranslatef(0, 0, largeBoxHeight/2+quadLength+dceilHeight/2);
    glTranslatef(0, (smallBoxWidth/2+dceilWidth/2), 0);
    displayBox(dceillength, dceilWidth, dceilHeight, boxred = 0.149,boxgreen=0.905,boxblue = 992);// small box
    glPopMatrix();
    /**/
    /** Upper ceil of Back door **/
    glPushMatrix();
    glTranslatef(0, 0, largeBoxHeight/2+quadLength+dceilHeight/2);
    glTranslatef(0, -(smallBoxWidth/2+dceilWidth/2), 0);
    displayBox(dceillength, dceilWidth, dceilHeight, boxred = 0.149,boxgreen=0.905,boxblue = 992);// small box
    glPopMatrix();


    /** Window **/
    ///left rotating window
    float winlength = 100, winwidth = 80;
    int Angle = 90;
    glPushMatrix();
    glTranslatef(0, 0, largeBoxHeight/2+1.5*winlength);
    glTranslatef(smallBoxLength/2+0.02, 0, 0);
    glRotatef(winangle,0,1,0);
    displaywindow(winlength, winwidth);// small box
    glPopMatrix();
    ///right  sliding window
    glPushMatrix();
    glTranslatef(0, 0, largeBoxHeight/2+winlength);
    glTranslatef(-smallBoxLength/2-.02, 0, 0);
    glRotatef(Angle, 0, 0, 1);
    glTranslatef( 0, 0,windowup);
    displayQuad(winlength, winwidth,0);// small box
    glPopMatrix();

    /** Upper Ceil of left window **/
    glPushMatrix();
    glTranslatef(0, 0, largeBoxHeight/2+3*winlength/2);
    glTranslatef(smallBoxLength/2+dceilWidth/2, 0, 0);
    glRotatef(Angle, 0, 0, 1);
    displayBox(winwidth, dceilWidth, dceilHeight, boxred = 0.149,boxgreen=0.905,boxblue = 992);// small box
    glPopMatrix();
    /**/
    /** Upper ceil of right Window**/
    glPushMatrix();
    glTranslatef(0, 0, largeBoxHeight/2+3*winlength/2);
    glTranslatef(-smallBoxLength/2-dceilWidth/2, 0, 0);
    glRotatef(Angle, 0, 0, 1);
    displayBox(winwidth, dceilWidth, dceilHeight, boxred = 0.149,boxgreen=0.905,boxblue = 992);// small box
    glPopMatrix();

    /** Tyre**/

    glPushMatrix();
    glTranslatef(0, 0, tyreRadius+smallBoxHeight+(largeBoxHeight/2));
    glTranslatef(0, upBoxWidth, 0); // places the tyre on top of both boxes
    glTranslatef(0, 0, tyreRadius/2);
    glRotatef(tyreAngle, 0, 1, 0); //for rotating the fan after clicking
    glRotatef(Angle, 0, 0,1 ); // check what happens to the tyre after exchanging the order of translation and roation
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
    displayTyre(tyreRadius, tyreWidth,1);
    glPopMatrix();

    /** Small Tyre **/
    glPushMatrix();
    glTranslatef(0, 0, tyreRadius+smallBoxHeight+(largeBoxHeight/2));
    glTranslatef(0, upBoxWidth, 0); // places the tyre on top of both boxes
    glTranslatef(0, 0, tyreRadius/2);
    glRotatef(tyreAngle, 0, 1, 0);
    glRotatef(Angle, 0, 0,1 ); // check what happens to the tyre after exchanging the order of translation and roation
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
    displayTyre(tyreRadius/2, tyreWidth,2);
    glPopMatrix();
}

void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(background, background, background,0);	//sets background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // sets the current matrix to identity
    gluLookAt(pos.x, pos.y, pos.z, pos.x+l.x, pos.y+l.y, pos.z+l.z, u.x, u.y, u.z); // sets camera position and direction

    displayScene();

	glutSwapBuffers();
}


void animate(){
    tinyBoxAngle += 2;
    if (tmp==1)
        tyreAngle -= 5; /// rotate the fan clockwise
    else if (tmp==2)
        tyreAngle+=1;  ///rotate the fan anti-clockwise
    else if( tmp==0)
        tyreAngle = tyreAngle;     ///stops the fan
    //boxAngle +=1
    if (drotate ==1)
    {
        if(doorangle>=145)
            doorangle=145;    ///rotating  door opens
        else
            doorangle+=1;
    }
    else if (drotate ==2)
    {
        if (doorangle<=0)
            doorangle=0;
        else
            doorangle-=1;  ///rotating door closes
    }
    if(slidetmp==1)
    {
        if(windowup==50)
            windowup=50;
        else
            windowup+=0.5;     ///Sliding window goes up
    }
    else if(slidetmp==2)
    {
        if(windowup<=0)
            windowup=0;
        else
            windowup-=0.5;     ///sliding window goes down
    }
	glutPostRedisplay();
}

void init(){
    glClearColor(background, background, background,0); 	//sets background color

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity(); // sets the current matrix to identity
    gluPerspective(80,	1,	1,	1000.0);

	// to understand the following values, read the specification pdf
    double d = 1 / sqrt2;
    pos = {300, 300, 150};
    u = {0, 0, 1};
    r = {-d, d, 0};
    l = {-d, -d, 0};
}



void subMenu(int id)
{
    if(id == 3)
    {
        slidetmp=1;
        //windowup = 50;
    }
    else if(id == 4)
    {
        slidetmp=2;
        //windowup -=50;
    }
}
void ExhaustMenu(int id)
{
    if(id == 5)
    {
        tmp=1;  /// Fan rotates clockwise
    }
    else if(id == 6)
    {
        tmp=2;  /// Fan rotates anti-clockwise
    }
    else if(id == 7)
    {
        tmp=0;  /// Fan stops
    }
}
void DoorMenu(int id)
{
    if (id == 8)
    {
        drotate=1; ///rotating door opens
    }
    else if (id == 9)
    {
        drotate = 2;  ///rotating door closes
    }
}

void mainMenu(int id)
{
    if(id == 10)
    {
        boxScaleFactor=1;
    }
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color
	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);

	int subMenuNo = glutCreateMenu(subMenu);
    glutAddMenuEntry("Slide Up", 3);
	glutAddMenuEntry("Slide Down", 4);
	int ExhaustMenuNo = glutCreateMenu(ExhaustMenu);
    glutAddMenuEntry("Clockwise", 5);
	glutAddMenuEntry("Anti-Clockwise", 6);
    glutAddMenuEntry("Stop", 7);
    int RotatingdoorNo = glutCreateMenu(DoorMenu);
    glutAddMenuEntry("Open", 8);
	glutAddMenuEntry("Close", 9);
    glutCreateMenu(mainMenu);
	glutAddSubMenu("Sliding Window", subMenuNo);
	glutAddSubMenu("Rotating Door", RotatingdoorNo);
	glutAddSubMenu("Exhaust Fan", ExhaustMenuNo);
	glutAddMenuEntry("Original Size", 10);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();		//The main loop of OpenGL, this function never returns

	return 0;
}
