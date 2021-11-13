#include<omp.h>
#include<stdio.h>
#include<gd.h>
#include<time.h>

void imageprocess()
{
    FILE *input_file = fopen("lenna.png", "rw");
    
    
    gdImagePtr image = gdImageCreateFromPng(input_file);
    int width = gdImageSX(image);
    int height = gdImageSY(image);

    printf("%d",width);

    int red,blue,green,color;

    #pragma omp parallel for   
    
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<height;j++)
            {
                color=gdImageGetPixel(image,i,j);
                
                red = 255 - gdImageRed(image, color);
                green = 255 - gdImageGreen(image, color);
                blue = 255 - gdImageBlue(image, color);
                
                color  = gdImageColorAllocate(image, red, green, blue);
                
                gdImageSetPixel(image, i, j, color);
            }
        }
        FILE *output_file = fopen("lennabw.png", "w");
        
        freopen("lennabw.png", "w", output_file);
        gdImagePng(image, output_file);
        gdImageDestroy(image);

        fclose(input_file);
        fclose(output_file);
    
}
void main()
{
    clock_t t = clock();
    for(int i=0;i<100;i++)
        imageprocess();
    t=clock()-t;
    double time_taken=t/CLOCKS_PER_SEC;
    printf("them taked %f",time_taken);
}