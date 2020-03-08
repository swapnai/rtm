#include "graph.hpp"

using namespace std;
namespace will
{
  graph::graph(): MAX_NODES(0), MAX_EDGES(0) {}

  graph::graph(istream& is)
    
  {
    is >> MAX_NODES >> MAX_EDGES;
    for( int i = 0; i < MAX_NODES; i++)
      {
	adj_list[i] = set<int>();
      }
    int from;
    int to;
    int count = 0;
    while(is >> from)
      {
	is >> to;
	adj_list[from].insert(to);
	
      }
    count++;
    
    //todo: should we infer from istream? 
    if( count != MAX_EDGES)
      {
	//todo: swapna: make logger
	cout << "WARN: inconsistent EDGE count!" << endl;
	
      }
  }
  
  ostream& operator<< (ostream& os, const graph& g)
  {
    os << "No of Nodes: " << g.MAX_NODES << " No of edges: " << g.MAX_EDGES;
    os << endl;
    os << "Edges: " << endl;
 
    for( auto &to_nodes: g.adj_list)
      {
	int from = to_nodes.first;
	for(auto &to: to_nodes.second)
	  {
	    os << from << " --> " << to << endl;
	  }
	
    }
    os << endl;
    return os;
    
  }


  istream& operator>> (istream& is, graph& g)
  {
    is >> g.MAX_NODES >> g.MAX_EDGES;
    for( int i = 0; i < g.MAX_EDGES; i++)
      {
	int to, from;
	is >> from >> to;
	g.adj_list[from].insert(to);
      }
    return is;
    
  }
}

