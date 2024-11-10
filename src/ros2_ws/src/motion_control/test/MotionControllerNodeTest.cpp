#include <gtest/gtest.h>

TEST(motion_control, hello_world_test)
{
  ASSERT_EQ(5, 2 + 3);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}