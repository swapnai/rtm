#include "gtest/gtest.h"
#include "graph.hpp"

using namespace std;

TEST(graphsTest, default_ctor) {
  rytm::graph *g = new rytm::graph();
  EXPECT_TRUE(g != nullptr);

}

TEST(graphsTest, instream_ctor) {

  string input_graph = "5,4,1:3,2:4,1:2,4:0";
  istringstream is(input_graph);
  
  rytm::graph *g = new rytm::graph(is);
  ostringstream os;
  os << g;
  rytm::graph copy_of_g;
  is >> copy_of_g;
  // EXPECT_TRUE(g != nullptr);

}
