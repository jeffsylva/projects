/**@file AllegroTest.cc
*  @brief Implementation of the AllegroTest program.
*  
*  This contains the implementation of the functions of the AllegroTest program to be used to generate test cases.
*  
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

#include "AllegroTest.h"
bool collision(int x1, int y1, int x2, int y2, int a, int b, int c, int d)
{
   if(( (x2>(x1-c))&&(y2>(y1-d)) )&&( (x2<(x1+a))&&(y2>(y1-b)) )
      && ((x2>(x1-c))&&(y2<(y2+d))) &&((x2<(x1+a))&&(y2<(y1+b))))
   {
      return true;   
   }
   else
   {
      return false;
   }
}

bool collision1(int x1,int y1,int x2,int y2,int a, int b, int c, int d)
{
	 if(( (x2>(x1-c))&&(y2>(y1-d)) )&&( (x2<(x1+a))&&(y2>(y1-b)) )
	    && ((x2>(x1-c))&&(y2<(y2+d))) &&((x2<(x1+a))&&(y2<(y1+b))))
	 {
	    return true;
	 }
	 else
	 {
	    return false;
	 }
}
	 

	    

