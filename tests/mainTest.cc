/**@file mainTest.cc
*  @brief This is the main function for the Test driven development method
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#include "collisiontests.h"

int main() {
   CppUnit::TextUi::TestRunner runner;
   runner.addTest(CollisionTests::suite());
   runner.run();
   return 0;
}

