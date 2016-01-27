#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <conio.h>

using namespace cv;
using namespace std;
Mat frame;


 int main( int argc, char** argv )
 {
	

   VideoCapture cap("rtsp://admin:12345@10.133.4.54//Streaming/Channels/2");
   if (!cap.isOpened())
   {
	   cout << "Cannot open the web cam" << endl;
	   return -1;
    }
    
   while(waitKey(30)!=27){
	  cap>>frame;
	  namedWindow("oryginal", WINDOW_AUTOSIZE );
		imshow("oryginal",frame);
   }
  

   return 0;
   

}
