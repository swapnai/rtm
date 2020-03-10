#include "gtest/gtest.h"
#include "graph.hpp"

TEST(graphsTest, test1) {
  will::graph* g = new will::graph();
  EXPECT_TRUE(g != nullptr);

}
