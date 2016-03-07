/**
 * NAME : RAHUL SHINDE
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, checkMine)
{
	Field minefield;
  bool flag = false;
	minefield.placeMine(4,5);
  try
  {
      ASSERT_TRUE( minefield.isSafe(4,5) );
  }
  catch(...)
  {
    flag = true;
  }
  ASSERT_FALSE(flag);
}

TEST(FieldTest, checkSafe)
{
	Field minefield;
  bool flag = false;
	minefield.placeMine(4,5);
  try
  {
      ASSERT_FALSE( minefield.isSafe(5,5) );
  }
  catch(...)
  {
    flag = true;
  }
  ASSERT_FALSE(flag);
}

TEST(FieldTest, checkAdjacent)
{
	Field minefield;
  minefield.revealAdjacent(7,5);
  ASSERT_EQ( EMPTY_HIDDEN, minefield.get(7,5) );
}

TEST(FieldTest, checkForZero)
{
    Field minefield;
    minefield.revealAdjacent(0,0);
    ASSERT_EQ( EMPTY_HIDDEN, minefield.get(0,0) );
}


TEST(FieldTest, checkForNine)
{
    Field minefield;
    minefield.revealAdjacent(9,9);
    ASSERT_EQ( EMPTY_HIDDEN, minefield.get(9,9) );
}
