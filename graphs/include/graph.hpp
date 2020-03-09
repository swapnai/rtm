#include <iostream>
#include <map>
#include <set>
#include <tuple>

using namespace std;

namespace will
{
  class graph
  {
  public:
    graph();

    graph(istream& in);

    int get_max_node();
    int get_max_edge();
    tuple<int*, unsigned int> get_nodes_from(int n);
    tuple<int*, unsigned int> get_nodes_to(int n);
    pair<int, int> get_edges();

    void add_edge(int to, int from);
    void add_node(int n);
    void set_max_node(int n);
    //bool is_dag();
    

    virtual ~graph() = default;
    
    friend ostream& operator<<(ostream& os, const graph& g);
    friend istream& operator>>(istream& is, graph& g);
  private:
    int MAX_NODES;
    int MAX_EDGES;
    map<int, set<int>> adj_list;
    

  };
  
}

