// UnitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Counter.h"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

std::stringstream test1("Nieco.");
std::stringstream test2("Draco dormiens nunquam titillandus.");
std::stringstream test3("Tvorba Softverovych systemov.");
std::stringstream test4("Mitochondria is the powerhouse of the cell.");
std::stringstream test5("But now, I'm free.\n There are ... no strings on me.");
std::stringstream test6("Tatramed Medical Software \n Liscie Udolie 9 \n 841 04 \n Bratislava");

TEST_CASE("Prebehia kontrola retazcov", "[pocitadlo]"){
	REQUIRE(pocitadlo<char>(test1) == 6);
	REQUIRE(pocitadlo<char>(test2) == 32);
	REQUIRE(pocitadlo<string>(test3) == 3);
	REQUIRE(pocitadlo<string>(test4) == 7);
	REQUIRE(pocitadlo<Line>(test5) == 2);
	REQUIRE(pocitadlo<Line>(test6) == 4);
}

