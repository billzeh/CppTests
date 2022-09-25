//
// Created by bill on 9/24/2022.
//

#include <gtest/gtest.h>
#include <lib/library.h>

TEST(TestLibrary, helloTest) {
   EXPECT_NO_THROW(hello());
}
