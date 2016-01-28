#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <conio.h>

using namespace cv;
using namespace std;

Mat frame, imgTemp, tmpFrame, tmpFrame2;

BackgroundSubtractorMOG2 bg(100, 100, false);

 int main( int argc, char** argv )
 {	

   VideoCapture cap("rtsp://admin:12345@10.133.4.54//Streaming/Channels/2");
   if (!cap.isOpened())
   {
	   cout << "Cannot open the web cam" << endl;
	   return -1;
    }
   
   cap.read(imgTemp);

   while(waitKey(30)!=27){
	  cap>>frame;
	  vector < std::vector < cv::Point > >contours;

	  bg.operator()(frame,tmpFrame);

	  bg.getBackgroundImage(tmpFrame2);
	  findContours(tmpFrame, contours,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	  drawContours(frame,contours, -1,cv::Scalar(255,0,0),2);
	  
	  namedWindow("oryginal", WINDOW_AUTOSIZE );
		imshow("oryginal",frame);
   }
  

   return 0;
   

}
