// OpenCV Headers
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
// C++ Standard Libraries
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iostream>
//gdal libraries
#include "gdal/gdal_priv.h"
#include "gdal/cpl_conv.h"
#include "gdal.h"

#include <cstdlib>


using namespace std;  
using namespace cv;
// define the corner points
// Note that GDAL library can natively determine this


float origen_z=0;
char TrackbarName[50];
int  rowf;
int  rowi;

int  colf;
int  coli;

int cell_size=2;

int Y1;

int rectangulo_x_down;
int rectangulo_y_down;

int rectangulo_x_up;
int rectangulo_y_up;

int contador_L=0;

FILE *fp;
FILE *fp2;
FILE *fp3;

cv::Mat realimage;
cv::Mat image; 
cv::Mat dem; 
cv::Mat demcropped;
cv::Mat demcropped2;
cv::Mat miniDem;
cv::Mat miniDem2;
cv::Mat miniDem3;
cv::Mat miniLaCabrera;
cv::Mat whiteImage;
cv::Mat goalsImage;
cv::Mat showImage;
cv::Mat copiashowImage;

  
int x;
int y;
char key;
int alpha_slider;
const int alpha_slider_max = 80; 
double alpha=0;


cv::Point2d tl( 712213.000, 4176289.000 );  
cv::Point2d bl( 712213.000, 4174715.000 );  
cv::Point2d tr( 714935.000, 4176289.000 );  
cv::Point2d br( 714935.000, 4176289.000 ); 

// determine dem corners
cv::Point2d dem_bl( 712213.000, 4174715.000);
cv::Point2d dem_tr( 714935.000, 4176289.000);

// List of  function prototypes
cv::Point2d lerp( const cv::Point2d&, const cv::Point2d&, const double& );
cv::Point2d world2dem( const cv::Point2d&, const cv::Size&);
cv::Point2d pixel2world( const int&, const int&, const cv::Size& );


float Remap ( float value, float from1, float to1, float from2, float to2) {
    return (value - from1) / (to1 - from1) * (to2 - from2) + from2;
}

float MAX_angle(float a,float b, float c,float d,float f,float g,float h,float i)
{

return max(max(max(max(max(max(max(a,b),c),d),f),g),h),i);

}



void newAlgorithm3()
{

demcropped=dem;


//demcropped = dem(Range((int)dem_bl_cropped.y,(int)dem_tr_cropped.y),Range((int)dem_bl_cropped.x,(int)dem_tr_cropped.x) );

demcropped2= Mat::zeros(demcropped.size(), CV_16SC1); 

int iWidth=demcropped.cols;
int iHeight=demcropped.rows;


double pixel_x;
double pixel_y;

float sobel_x[3][3] =	
{ { -1, 0, 1 },
{ -2, 0, 2 },
{ -1, 0, 1 } };

float sobel_y[3][3] =
{ { -1, -2, -1 },
{ 0,  0,  0 },
{ 1,  2,  1 } };

for(  x=1; x< iWidth-1; x++ ){
for(  y=1;  y<iHeight-1; y++ ){

/*
if(x==iWidth-5 && y==5)
{

circle(goalsImage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0);
circle(realimage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0); 
}

if(x==5 && y==iHeight-5)
{

circle(realimage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0); 
circle(goalsImage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0);
}

if(x==5 && y==5)
{

circle(realimage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0); 
circle(goalsImage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0);
}

if(x==iWidth-10 && y==iHeight-10)
{

circle(goalsImage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0);
circle(realimage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0); 
}

if((x==(iWidth/2)) && (y==(iHeight/2)) )
{ 
origen_z= demcropped.at<short>({(x),(y)});
circle(goalsImage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0);
circle(realimage, Point(x, y), 3, Scalar(0,0,0), FILLED,LINE_8,0); 
}
*/

//int val=demcropped.at<short>({(x),(y)})); 

pixel_x = (sobel_x[0][0] * demcropped.at<short>({(x-1),(y-1)})) 
	+ (sobel_x[0][1] * demcropped.at<short>({(x),(y-1)  }))
	+ (sobel_x[0][2] * demcropped.at<short>({(x+1),(y-1)}))
	+ (sobel_x[1][0] * demcropped.at<short>({(x-1),(y)  }))
	+ (sobel_x[1][1] * demcropped.at<short>({(x),(y)    }))
	+ (sobel_x[1][2] * demcropped.at<short>({(x+1),(y)  }))
	+ (sobel_x[2][0] * demcropped.at<short>({(x-1),(y+1)}))
	+ (sobel_x[2][1] * demcropped.at<short>({(x),(y+1)  }))
	+ (sobel_x[2][2] * demcropped.at<short>({(x+1),(y+1)}));
	
pixel_x=pixel_x/(8*cell_size);

pixel_y = ( sobel_y[0][0] * demcropped.at<short>({(x-1),(y-1) }))
	+ (sobel_y[0][1] *  demcropped.at<short>({(x),(y-1)   }))
	+ (sobel_y[0][2] *  demcropped.at<short>({(x+1),(y-1) }))
	+ (sobel_y[1][0] *  demcropped.at<short>({(x-1),(y)   }))
	+ (sobel_y[1][1] *  demcropped.at<short>({(x),(y)     }))
	+ (sobel_y[1][2] *  demcropped.at<short>({(x+1),(y)   }))
	+ (sobel_y[2][0] *  demcropped.at<short>({(x-1),(y+1) }))
	+ (sobel_y[2][1] *  demcropped.at<short>({(x),(y+1)   }))
	+ (sobel_y[2][2] *  demcropped.at<short>({(x+1),(y+1) }));
 
 
pixel_y=pixel_y/(8*cell_size);

int val = (sqrt((pixel_x * pixel_x) + (pixel_y * pixel_y)))*100;		

if(val>255) val=255;

demcropped2.at<short>(y,x)= val;

 }
 }
 

threshold(demcropped2,miniDem,alpha, 255, THRESH_BINARY_INV );
//opped2,miniDem,alpha, 255, THRESH_BINARY_INV );
//miniDem.convertTo(miniDem,CV_8U);
}


static void on_trackbar_alpha( int, void* )
{
alpha = (double) alpha_slider ;
threshold(demcropped2, miniDem,alpha, 255, THRESH_BINARY_INV );
miniDem.convertTo(miniDem,CV_8U);
//resize(miniDem,miniDem, {500,500},INTER_LINEAR);
if(key==50) imshow( "Sobel Gradient",miniDem);
}

////////////
void drawCircle2( int event, int x, int y, int, void* param) 
{

Y1=abs(y-miniDem.size().height);

cv::Point2d geo=pixel2world(x,y,dem.size());

cout << "UTM coordinates (WGS84):   "
    << "lat = " << geo.x 
    << "  lon = " << geo.y 
    << "  height (m) = "   << (demcropped.at<short>({(x),(y)}))
    << endl;
        
if ((event == EVENT_LBUTTONDOWN )&& contador_L==0  ) 		  
{
contador_L=1;

circle(miniLaCabrera, Point(x, y), 3, Scalar(255,0,0), FILLED,LINE_8,0); //red 255,0,0 blue 0,0,255
circle(goalsImage, Point(x, y), 3, Scalar(255,0,0), FILLED,LINE_8,0); 
circle(realimage, Point(x, y), 3, Scalar(255,0,0), FILLED,LINE_8,0); 
circle(miniDem2, Point(x, y), 3, Scalar(255,0,0), FILLED,LINE_8,0); 
circle(miniDem, Point(x, y), 3, Scalar(255,0,0), FILLED,LINE_8,0); 
fp2 = fopen("/home/juanmat/catkin_ws/src/path_planning_sims/path_planning_intro/unit4_pp/maps/map_coords.txt","w");
fprintf(fp2,"%d,%d,%d,",x,Y1,(demcropped.at<short>({(x),(y)})));
imshow( "Sobel Gradient",miniDem);
}
else
{
	if ( (event == EVENT_LBUTTONDOWN ) && contador_L==1  )
	{
		contador_L=2;
		circle(miniLaCabrera, Point(x, y), 3, Scalar(0,0,255), FILLED,LINE_8,0); 
		circle(realimage, Point(x, y), 3, Scalar(0,0,255), FILLED,LINE_8,0); 
		circle(goalsImage, Point(x, y), 3, Scalar(0,0,255), FILLED,LINE_8,0); 
		circle(miniDem2, Point(x, y), 3, Scalar(255,0,0), FILLED,LINE_8,0);  
		circle(miniDem, Point(x, y), 3, Scalar(255,0,0), FILLED,LINE_8,0);  
		//circle(miniDem, Point(x, y), 3, Scalar(0,0,255), FILLED,LINE_8,0); 
		
		fprintf(fp2,"%d,%d,%d,%d",x,Y1,(demcropped.at<short>({(x),(y)})),int(origen_z));
		fclose(fp2);
		imshow( "Sobel Gradient",miniDem);
		 
	 //destroyWindow("La Cabrera");
	
	}
}
x=0;
y=0;

}
////////////

cv::Point2d lerp( cv::Point2d const& p1, cv::Point2d const& p2, const double& t ){
 return cv::Point2d( ((1-t)*p1.x) + (t*p2.x),
 ((1-t)*p1.y) + (t*p2.y));
}

/*
 * Given a pixel coordinate and the size of the input image, compute the pixel location
 * on the DEM image.
*/
cv::Point2d world2dem( cv::Point2d const& coordinate, const cv::Size& dem_size ){
 // relate this to the dem points
 // ASSUMING THAT DEM DATA IS ORTHORECTIFIED
 double demRatioX = ((dem_tr.x - coordinate.x)/(dem_tr.x - dem_bl.x));
 double demRatioY = 1-((dem_tr.y - coordinate.y)/(dem_tr.y - dem_bl.y));
 

fprintf(fp,"coordinate.x,coordinate.y,dem_tr.x,dem_tr.y: %f %f %f %f \n",coordinate.x,coordinate.y,dem_tr.x,dem_tr.y);
fprintf(fp,"demRatioX,demRatioY: %f %f \n",demRatioX,demRatioY);


fprintf(fp,"dem.size().width,dem.size().height: %d %d \n",dem.size().width,dem.size().height);
 
 cv::Point2d output;
 output.x = demRatioX * dem.size().width;
 output.y = demRatioY * dem.size().height;
 
  
fprintf(fp,"coutput.x output.y,dem_size.width,dem_size.height: %f %f %d %d\n", output.x,output.y,dem_size.width,dem_size.height);
fprintf(fp,"\n--------------------------------------------------\n\n\n");
 return output;


 
}
/*
 * Convert a pixel coordinate to world coordinates
*/
cv::Point2d pixel2world( const int& x, const int& y, const cv::Size& size ){
 // compute the ratio of the pixel location to its dimension
 double rx = (double)x / miniLaCabrera.size().width;
 double ry = (double)y / miniLaCabrera.size().height;
 // compute LERP of each coordinate
 cv::Point2d rightSide = lerp(tr, br, ry);
 cv::Point2d leftSide = lerp(tl, bl, ry);
 // compute the actual Lat/Lon coordinate of the interpolated coordinate
 return lerp( leftSide, rightSide, rx );
}



/*
 * Add color to a specific pixel color value
*/
void add_color( cv::Vec3b& pix, const uchar& b, const uchar& g, const uchar& r )
{
 if( pix[0] + b < 255 && pix[0] + b >= 0 ){ pix[0] += b; }
 if( pix[1] + g < 255 && pix[1] + g >= 0 ){ pix[1] += g; }
 if( pix[2] + r < 255 && pix[2] + r >= 0 ){ pix[2] += r; }
}

void Welcome_message()
{

// Set up the text properties
std::string text = 
"La interfaz de este TFG te permite seleccionar graficamente \nel punto de origen y destino sobre un mapa de ejemplo.\nA continuacion, podras planificar la trayectoria entre los\npuntos mediante la interfaz de Rviz.\n\nPulsando los botones '1', '2','3','4' o '5' podras intercambiar\nentre distintas vistas del mismo mapa. Haciendo click izquierdo podras \nseleccionar el punto deseado como origen, y en segundo lugar \ncomo destino.\n\nPulsando y arrastrando el slider podras variar el grado de \ninclinacion del mapa de coste.Finalmente, podras guardar \nlos resultados pulsando la letra 's' del teclado.\nSi deseas empezar de cero puedes puslar la letra 'r'.\n\nPulsa cualquier tecla para empezar";

int fontFace = FONT_HERSHEY_SIMPLEX;
double fontScale = 1.0;
int thickness = 1.5;
// Get the size of the text
Size textSize = getTextSize("La interfaz de este TFG te permite...........................", fontFace, fontScale, thickness, nullptr);
// Create the canvas with size adjusted to fit the text
Mat canvas(textSize.height * 33, textSize.width * 1.5, CV_8UC3, Scalar(0, 0, 0));
// Calculate the starting position to center the text vertically on the canvas
// Write each line of text
int line = 0;
std::istringstream textStream(text);
std::string lineText;
while (std::getline(textStream, lineText)) 
{
Point textOrg(0, textSize.height * (line + 1));
putText(canvas, lineText, textOrg, fontFace, fontScale, Scalar(255, 255, 255), thickness);
line=line+2;
}
// Display the canvas
imshow("Bienvenido", canvas);
// Wait for a key press and then close the window
waitKey(0);
destroyAllWindows();
}

void print_plan()
{
FILE *fpx;
fpx = fopen( "/home/juanmat/catkin_ws/src/path_planning_sims/path_planning_intro/unit4_pp/maps/map_path.txt","r");
fscanf(fpx, "%*[^\n]");
int aux;
float x1,y1,x2,y2;

while (fscanf(fpx, "%d\t%f,%f\t%f,%f\n",&aux,&x1,&y1,&x2,&y2) == 5) 
{
y1=abs(y1/2-miniDem.size().height);
circle(goalsImage, Point((x1/2), (y1)), 3, Scalar(0,0,0), FILLED,LINE_8,0); 
circle(miniLaCabrera, Point((x1/2), y1), 3, Scalar(0,0,255), FILLED,LINE_8,0); 
circle(realimage, Point((x1/2), y1), 3, Scalar(0,0,255), FILLED,LINE_8,0);  
circle(miniDem2, Point((x1/2), y1), 3, Scalar(255,0,0), FILLED,LINE_8,0);  
circle(miniDem, Point((x1/2), y1), 3, Scalar(255,0,0), FILLED,LINE_8,0);  
//std::cout << (x1/2) << "," << (y1) << std::endl;
}
fclose(fpx);

cv::imwrite("/home/juanmat/Escritorio/final/mapa_sat_planned_1.png",goalsImage);
cv::imwrite("/home/juanmat/Escritorio/final/mapa_sat_planned_2.png",miniLaCabrera);
cv::imwrite("/home/juanmat/Escritorio/final/mapa_sat_planned_3.png",realimage);
cv::imwrite("/home/juanmat/Escritorio/final/mapa_sat_planned_4.png",miniDem2);
cv::imwrite("/home/juanmat/Escritorio/final/mapa_sat_planned_5.png",miniDem);
}

int main(  )
{

Welcome_message();

reset_gui:

image = cv::imread("/home/juanmat/Escritorio/final/rio_tinto/mapa_topografico_prueba.tif",cv::IMREAD_LOAD_GDAL| cv::IMREAD_COLOR );
realimage = cv::imread("/home/juanmat/Escritorio/final/rio_tinto/mapa_real_prueba.tif",cv::IMREAD_LOAD_GDAL| cv::IMREAD_COLOR );
//Mat image_show = cv::imread("/home/robcib/Desktop/lacabrera/lacabrera.jpg",cv::IMREAD_LOAD_GDAL| cv::IMREAD_COLOR );
dem = cv::imread("/home/juanmat/Escritorio/final/rio_tinto/mapa_dem_prueba.tif", cv::IMREAD_LOAD_GDAL| cv::IMREAD_ANYDEPTH );
dem.convertTo(dem,CV_16SC1);
resize(realimage,realimage, dem.size(),INTER_LINEAR);

// for sanity sake, make sure GDAL Loads it as a signed short
if( dem.type() != CV_16SC1 ){ throw std::runtime_error("DEM image type must be CV_16SC1"); }

//
double originX;
double originY;

double X_geo_br;
double Y_geo_br;

double X_geo_tr;
double Y_geo_tr;

double X_geo_bl;
double Y_geo_bl;
   
fp3= fopen("/home/juanmat/catkin_ws/src/cv_gdal/src/gdalinfo.txt","r");
fscanf(fp3,"%lf %lf tl\n",&originX,&originY);	
fscanf(fp3,"%lf %lf br\n",&X_geo_br,&Y_geo_br);
fscanf(fp3,"%lf %lf bl\n",&X_geo_bl,&Y_geo_bl);
fscanf(fp3,"%lf %lf tr",&X_geo_tr,&Y_geo_tr);

fclose(fp3);


std::cout << originX << "," << originY <<   " top left coord " << std::endl;
std::cout << X_geo_br << "," << Y_geo_br << " bottom right coord " << std::endl;
std::cout << X_geo_bl << "," << Y_geo_bl << " bottom left coord " << std::endl;
std::cout << X_geo_tr << "," << Y_geo_tr << " top right coord " << std::endl;
                
       
tl= cv::Point2d(originX,originY);
tr= cv::Point2d(X_geo_tr,Y_geo_tr);
bl= cv::Point2d(X_geo_bl,Y_geo_bl);
br= cv::Point2d(X_geo_br,Y_geo_br);

dem_bl= cv::Point2d(X_geo_bl,Y_geo_bl);
dem_tr= cv::Point2d(X_geo_tr,Y_geo_tr);

   
//

cv::Mat whiteImage(dem.size(), CV_8UC3, cv::Scalar(255, 255, 255));
goalsImage=whiteImage;
copiashowImage=whiteImage;

//blank_goal= Mat::zeros(dem.size(), CV_8UC1); 
//threshold(blank_goal,blank_goal,0, 255, THRESH_BINARY_INV );

newAlgorithm3();

//int sizeX=0.6*image.size().width;
//int sizeY=0.6*image.size().height;
resize(image,miniLaCabrera, dem.size(),INTER_LINEAR);
//namedWindow( "La Cabrera", cv::WINDOW_AUTOSIZE  );
//imshow( "La Cabrera",miniLaCabrera);	
//waitKey(0);

//resize(miniDem,miniDem2, {sizeX,sizeY},INTER_LINEAR);
miniDem2=demcropped2;
miniDem2.convertTo(miniDem2,CV_8U);
applyColorMap(miniDem2, miniDem2, COLORMAP_JET);
//imshow( "Gradient Color Map",miniDem2);


imshow( "Real Map",realimage);

while(key!=27) 
{


key = (char)waitKey(0);

   if(key==49)
	 {

          destroyAllWindows();
	  namedWindow( "Real Map", cv::WINDOW_GUI_NORMAL );
	  snprintf( TrackbarName,  sizeof(TrackbarName) , "Percentage of slope:" );
	  createTrackbar( TrackbarName,  "Real Map",  &alpha_slider, alpha_slider_max, on_trackbar_alpha );
	  on_trackbar_alpha( alpha_slider,0 );
	  imshow( "Real Map",realimage);
          /*
		  if(contador_L==0) imshow( "Real Map",realimage);
		  else
		  {
		  addWeighted( goalsImage, 0.5, realimage, 0.5, 0.0, showImage);
		  imshow( "Real Map",showImage);
		  }
          */
          
	 }
	 
	  if(key==50)
	 {
	  destroyAllWindows();
	  namedWindow( "Sobel Gradient", cv::WINDOW_GUI_NORMAL );
	  snprintf( TrackbarName,  sizeof(TrackbarName) , "Percentage of slope:" );
	  createTrackbar( TrackbarName,  "Sobel Gradient",  &alpha_slider, alpha_slider_max, on_trackbar_alpha );
	  on_trackbar_alpha( alpha_slider,0 );
	  //imshow( "Sobel Gradient",miniDem);
     	  //imshow( "Sobel Gradient",miniDem);
	  setMouseCallback("Sobel Gradient", drawCircle2);
	  imshow( "Sobel Gradient",miniDem);

	 }
 
 	 if(key==51)
	 {
	  destroyAllWindows();
	  namedWindow( "La Cabrera", cv::WINDOW_GUI_NORMAL );
	  snprintf( TrackbarName,  sizeof(TrackbarName) , "Percentage of slope:" );
	  createTrackbar( TrackbarName,  "La Cabrera",  &alpha_slider, alpha_slider_max, on_trackbar_alpha );
	  on_trackbar_alpha( alpha_slider,0 );
	  imshow( "La Cabrera",miniLaCabrera);
	 }
 
  	 if(key==52)
	 {
          destroyAllWindows();
	  namedWindow( "Gradient Color Map", cv::WINDOW_GUI_NORMAL );
	  snprintf( TrackbarName,  sizeof(TrackbarName) , "Percentage of slope:" );
	  createTrackbar( TrackbarName,  "Gradient Color Map",  &alpha_slider, alpha_slider_max, on_trackbar_alpha );
	  on_trackbar_alpha( alpha_slider,0 );
	  // imshow( "Gradient Color Map",miniDem2);
	  addWeighted( goalsImage, 0.4, miniDem2, 0.6, 0.0, showImage);
	  imshow( "Gradient Color Map",showImage);
	 }
	 
	     if(key==53)
	 {

          destroyAllWindows();
          namedWindow( "Goals Map", cv::WINDOW_GUI_NORMAL );
	  snprintf( TrackbarName,  sizeof(TrackbarName) , "Percentage of slope:" );
	  createTrackbar( TrackbarName,  "Real Map",  &alpha_slider, alpha_slider_max, on_trackbar_alpha );
	  on_trackbar_alpha( alpha_slider,0 );
	  imshow( "Goals Map",goalsImage); 
	 }
	 
	  if(key==82)
	 {
	  destroyAllWindows();
	  contador_L=0;
	  goto reset_gui;
	
	 }
	 if(key==83)
	 {
	 //destroyAllWindows();
	 cv::imwrite("/home/juanmat/catkin_ws/src/path_planning_sims/path_planning_intro/unit4_pp/maps/unitX_map.pgm",miniDem);
	 cv::imwrite("/home/juanmat/catkin_ws/src/navigation_data/unitX_map.pgm",miniDem);
 	 cv::imwrite("/home/juanmat/catkin_summit_xl/src/summit_xl_common/summit_xl_localization/maps/real/unitX_map.pgm",miniDem);
	 printf("map_saved");
	 printf("\n");
         //std::system("gnome-terminal -- roslaunch unit3_pp unit3_astar_solution.launch");
         std::system("gnome-terminal -- roslaunch unit3_pp unit3_dijkstra_solution.launch");
         //std::system("gnome-terminal -- roslaunch unit3_pp unit3_gbfs_solution.launch");
         //std::system("gnome-terminal -- roslaunch unit4_pp unit4_solution.launch");
	 }
	 

}

print_plan();
return 0;
}






