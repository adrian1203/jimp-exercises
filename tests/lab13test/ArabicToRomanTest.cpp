//
// Created by mwypych on 01.06.17.
//
#include <gtest/gtest.h>
#include "../../lab13/arabicroman/ArabicToRoman.h"

using namespace arabicroman;

class ArabicRomanTest: public ::testing::Test{
public:
};
TEST_F(ArabicRomanTest, DoConvertToERROR){
    EXPECT_EQ("", ConversionToRoman(4252));
}
TEST_F(ArabicRomanTest, DoConvertToERROR1){
    EXPECT_EQ("", ConversionToRoman(-2));
}
TEST_F(ArabicRomanTest, DoConvertToI){
    EXPECT_EQ("I", ConversionToRoman(1));
}

TEST_F(ArabicRomanTest, DoConvertToC){
    EXPECT_EQ("C", ConversionToRoman(100));
}
TEST_F(ArabicRomanTest, DoConvertToXXX){
    EXPECT_EQ("XXX", ConversionToRoman(30));
}
TEST_F(ArabicRomanTest, DoConvertToMMMCMXCIX){
    EXPECT_EQ("MMMCMXCIX", ConversionToRoman(3999));
}
TEST_F(ArabicRomanTest, DoConvertToDCCCLXXV){
    EXPECT_EQ("DCCCLXXV", ConversionToRoman(875));
}