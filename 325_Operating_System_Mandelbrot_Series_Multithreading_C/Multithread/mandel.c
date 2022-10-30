#include "bitmap.h"
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#define n 5
#include<time.h>
struct bitmap *bbm;
double xxmin,xxmax, yymin,yymax;
int mmax,ppp;
struct value
{
    double xmin, xmax, ymin, ymax;
    int max, id,width, height, act_height, a,base,limit;
    struct bitmap *bm;
};

int iteration_to_color( int i, int max );
int iterations_at_point( double x, double y, int max );
void compute_image( struct bitmap *bm, double xmin, double xmax, double ymin, double ymax, int max );
void create_thread( struct bitmap *bm, double xmin, double xmax, double ymin, double ymax, int max );
void *compute_with_thread(void *p);
void *threadfunc(void *p);

int main()
{
	clock_t begin = clock();

    double s=2.00;

    for(int i=1; i<=50; i++)
    {
        multiplefile(i,s);
        s=s*.6698;

    }
     clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\n\nTotal Time: %lf",time_spent);


}
int multiplefile(int number,double s)
{
    char outfile[50];
    sprintf(outfile,"mandel%d.bmp",number+1);
    double xcenter = .265000;
    double ycenter = .003500;
    double scale = s;
    int    image_width = 500;
    int    image_height = 500;
    int    max = 1000;



    // Display the configuration of the image.
    printf("mandel: x=%.3lf y=%.3lf scale=%.3lf max=%d outfile=%s\n",xcenter,ycenter,scale,max,outfile);


    // Create a bitmap of the appropriate size.
    struct bitmap *bm = bitmap_create(image_width,image_height);
    // Fill it with a dark blue, for debugging
    bitmap_reset(bm,MAKE_RGBA(0,0,255,0));

    // Compute the Mandelbrot image
    compute_image(bm,xcenter-scale,xcenter+scale,ycenter-scale,ycenter+scale,max);

    // Save the image in the stated file.
    if(!bitmap_save(bm,outfile))
    {
        //fprintf(stderr,"mandel: couldn't write to %s: %s\n",outfile,strerror(errno));
        return 1;
    }
    return 0;
    exit(EXIT_SUCCESS);
}


void compute_image( struct bitmap *bm, double xmin, double xmax, double ymin, double ymax, int max )
{
    pthread_t thread[n];
    //struct value data;
    int width = bitmap_width(bm);
    int height = bitmap_height(bm);
    //data.act_height = height;
    bbm =bm;
    xxmin=xmin;
    xxmax=xmax; 
    yymin=ymin; 
    yymax=ymax;
    mmax=max;
    for(int t=0; t<n; t++)
    {
        
        pthread_create(&thread[t], NULL, threadfunc, (void*)t);
        pthread_join(thread[t], NULL);
    }
    

}
void *threadfunc(void *p)
{
    int i,j;
    //struct value *data = (struct value*) p;
    ppp=(int*)p;
   // printf("\n PPP value: %d", ppp);
    //int sss=
    for(j = ppp*100; j < (ppp*100+100); j++)
    {
        for(i=0; i<500; i++)
        {
            // Determine the point in x,y space for that pixel.

                        double x = xxmin + i*(xxmax-xxmin)/500;
			double y = yymin + j*(yymax-yymin)/500;

			// Compute the iterations at that point.
			int iters = iterations_at_point(x,y,mmax);

			// Set the pixel in the bitmap.
			bitmap_set(bbm,i,j,iters);

        }
    }
}

/*
Compute an entire Mandelbrot image, writing each point to the given bitmap.
Scale the image to the range (xmin-xmax,ymin-ymax), limiting iterations to "max"
*/

/*
Return the number of iterations at point x, y
in the Mandelbrot space, up to a maximum of max.
*/

int iterations_at_point( double x, double y, int max )
{
    double x0 = x;
    double y0 = y;

    int iter = 0;

    while( (x*x + y*y <= 4) && iter < max )
    {

        double xt = x*x - y*y + x0;
        double yt = 2*x*y + y0;

        x = xt;
        y = yt;

        iter++;
    }

    return iteration_to_color(iter,max);
}

/*
Convert a iteration number to an RGBA color.
Here, we just scale to gray with a maximum of imax.
Modify this function to make more interesting colors.
*/


int iteration_to_color( int i, int max )
{
   	int gray = 255*i/max;
    int r= (255*i)/max;
    int l=(255*i*i)/max;
	return MAKE_RGBA(r,gray,l,0);
}

