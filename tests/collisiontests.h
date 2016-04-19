/**@file collisiontests.h
*  @brief A test driven development method to run some tests on the Delta Force game.
*
*  This contains various tests to check for the two types of collisions in the delta force game 
*
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

#ifndef __COLLISIONTESTS_H
#define __COLLISIONTESTS_H

#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#include "AllegroTest.h"

class CollisionTests: public CppUnit::TestFixture {
  public:
   
   CPPUNIT_TEST_SUITE(CollisionTests);
   CPPUNIT_TEST(collisiontest);
   CPPUNIT_TEST(collisiontest1);
   CPPUNIT_TEST(bulletcollsiontest);
   CPPUNIT_TEST(bulletcollsiontest1);
   CPPUNIT_TEST_SUITE_END();

   void collisiontest()
   {
      CPPUNIT_ASSERT(collision(35, 35, 35, 35, 30, 35, 30, 35) == true);
   }
   void collisiontest1()
   {
      CPPUNIT_ASSERT(collision(35, 35, 200, 200, 10, 10, 10, 10) == false);
   }
   void bulletcollsiontest()
   {
      CPPUNIT_ASSERT(collision1(35, 35, 35, 35, 20, 10, 30, 35) == true);
   }

   void bulletcollsiontest1()
   {
      CPPUNIT_ASSERT(collision1(35, 35, 200, 200, 20, 10, 30, 35) == false);
   }
};
#endif
