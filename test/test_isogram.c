#include "vendor/unity.h"
#include "../src/isogram.h"
#include "vendor/unity_internals.h"
#include <stdlib.h>

void test_empty_string(void)
{
   TEST_ASSERT_TRUE(is_isogram(""));
}

void test_short_isogram_word() {
    TEST_ASSERT_TRUE(is_isogram("Auto"));
}

void butter_is_no_isogram() {
    TEST_ASSERT_FALSE(is_isogram("butter"));
}

void test_long_isograms() {
    TEST_ASSERT_TRUE(is_isogram("Dialogschwerpunkt")); 
    TEST_ASSERT_TRUE(is_isogram("Pokalbeschriftung")); 
}

void test_long_non_isograms() {
    TEST_ASSERT_FALSE(is_isogram("griechisch")); 
    TEST_ASSERT_FALSE(is_isogram("abcedefghijklmnopqrstuvwxyz")); 
}

void upperCase_and_LowerCase_should_count_as_same_Character() {
    TEST_ASSERT_FALSE(is_isogram ("Aal")); 
}

void test_spaces_should_not_count() {
    TEST_ASSERT_FALSE(is_isogram ("Dialoag schwer punkt"));
}

int main(void)
{
   UnityBegin("isIsogram");

    RUN_TEST(test_empty_string);
    RUN_TEST(test_short_isogram_word);
    RUN_TEST(butter_is_no_isogram);
    RUN_TEST(test_long_isograms); 
    RUN_TEST(test_long_non_isograms); 
    RUN_TEST(upperCase_and_LowerCase_should_count_as_same_Character);
    RUN_TEST(test_spaces_should_not_count); 

   UnityEnd();
   return 0;
}
