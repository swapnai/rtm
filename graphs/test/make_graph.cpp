#include "gtest/gtest.h"
#include "graph.hpp"

#include <string>

using namespace std;

TEST(graphsTest, default_ctor) {
  rytm::graph *g = new rytm::graph();
  EXPECT_TRUE(g != nullptr);
}

TEST(graphsTest, instream_ctor) {

  string input_graph = "5,4,1:3,1:2,2:4,4:0";
  istringstream is(input_graph);

  rytm::graph *g = new rytm::graph(is);
  ostringstream os;
  os << *g;

  EXPECT_TRUE(os.str() == input_graph);

  is.clear();
  is.str(input_graph);
  rytm::graph copy_of_g;
  is >> copy_of_g;

  EXPECT_TRUE( *g == copy_of_g);
}

TEST(graphsTest, get_apis) {

  istringstream is("6,3,1:3,1:2,5:0");
  rytm::graph g;
  is >> g;

  EXPECT_TRUE(g.get_max_node() == 6);
  EXPECT_TRUE(g.get_max_edge() == 3);
  EXPECT_EQ(g.get_nodes_from(1), vector<int>({3, 2}));
  EXPECT_EQ(g.get_nodes_from(5), vector<int>({0}));
  EXPECT_EQ(g.get_nodes_to(3), vector<int>({1}));
  EXPECT_EQ(g.get_nodes_to(2), vector<int>({1}));
  EXPECT_EQ(g.get_nodes_to(0), vector<int>({5}));
  //negative test
  EXPECT_NE(g.get_nodes_from(4), vector<int>({0, 3}));
}

TEST(graphsTest, set_apis) {

  istringstream is("3,3,2:1,1:2,0:1");
  rytm::graph g;
  is >> g;

  EXPECT_TRUE(g.get_max_node() == 3);
  EXPECT_TRUE(g.get_max_edge() == 3);
    
  g.add_edge(4, 2);
  EXPECT_TRUE(g.get_max_node() == 4);
  EXPECT_TRUE(g.get_max_edge() == 4);
  EXPECT_EQ(g.get_nodes_from(2), vector<int>({1}));
  EXPECT_EQ(g.get_nodes_to(2), vector<int>({1, 4}));
  g.add_node(7);
  EXPECT_EQ(g.get_nodes_to(7), vector<int>({}));
  g.set_max_node(9);
  EXPECT_EQ(g.get_max_node(),  9);
  g.add_edge(9, 7);
  EXPECT_TRUE(g.get_max_edge() == 5);
  EXPECT_EQ(g.get_nodes_to(7), vector<int>({9}));
}
