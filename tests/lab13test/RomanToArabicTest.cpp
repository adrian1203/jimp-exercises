//
// Created by mwypych on 01.06.17.
//
#include <gtest/gtest.h>
#include "../../lab13/arabicroman/ArabicToRoman.h"

using namespace arabicroman;

class RomanArabicTest: public ::testing::Test{
public:
};
TEST_F(RomanArabicTest, DoConvertTo){
    EXPECT_EQ("", ConversionToArabic(""));
}
TEST_F(RomanArabicTest, DoConvertTo1){
    EXPECT_EQ("1", ConversionToArabic("I"));
}
TEST_F(RomanArabicTest, DoConvertTo23){
    EXPECT_EQ("23", ConversionToArabic("XXIII"));
}
TEST_F(RomanArabicTest, DoConvertTo256){
    EXPECT_EQ("256", ConversionToArabic("CCLVI"));
}
TEST_F(RomanArabicTest, DoConvertTo3589){
    EXPECT_EQ("3589", ConversionToArabic("MMMDLXXXIX"));
}
TEST_F(RomanArabicTest, DoConvertToERROR){
    EXPECT_EQ("ERROR", ConversionToArabic("MMMMDLXXXIX"));
}
