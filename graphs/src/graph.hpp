#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

namespace rytm
{
  class graph
  {
  public:
    graph();

    graph(istream& in);

    int get_max_node();
    int get_max_edge();
    vector<int> get_nodes_from(int n);
    vector<int> get_nodes_to(int n);
    map<int, vector<int>> get_adj_list();

    void add_edge(int to, int from);
    bool add_node(int n);
    bool set_max_node(int n);
    //bool is_dag();
    bool operator== (const graph& in_g);

    virtual ~graph() = default;
    
    friend ostream& operator<<(ostream& os, const graph& g);
    friend istream& operator>>(istream& is, graph& g);
    
  private:
    int MAX_NODES;
    int MAX_EDGES;
    map<int, vector<int>> adj_list;

  };
  
}

