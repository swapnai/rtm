#include "graph.hpp"

using namespace std;
namespace rytm
{
  graph::graph(): MAX_NODES(0), MAX_EDGES(0) {}

  graph::graph(istream& is)
    
  {
    is >> MAX_NODES >> MAX_EDGES;
    for( int i = 0; i < MAX_NODES; i++)
      {
	adj_list[i] = vector<int>();
      }
    int from;
    int to;
    int count = 0;
    while(is >> from)
      {
	is >> to;
	adj_list[from].push_back(to);
	
      }
    count++;
    
    //todo: should we infer from istream? 
    if( count != MAX_EDGES)
      {
	//todo: swapna: make logger
	cout << "WARN: inconsistent EDGE count!" << endl;
	
      }
  }
  
  int graph::get_max_node()
  {
    return MAX_NODES;
  }
  
  int graph::get_max_edge()
  {
    return MAX_EDGES;
  }
  
  vector<int> graph::get_nodes_from(int n)
  {
    return adj_list[n];
  }

  vector<int> graph::get_nodes_to(int n)
  {
    vector<int> from_list;
    for(auto &to_nodes: adj_list)
      {
	int from = to_nodes.first;
	for(auto &to: to_nodes.second)
	  {
	    if(to == n)
	      {
		from_list.push_back(from);
		break;
	      }
	  }
      }
    return from_list;
  }

  map<int, vector<int>> graph::get_adj_list()
  {
    return adj_list;
  }

  void graph::add_edge(int to, int from)
  {
    add_node(from);
    adj_list[from].push_back(to);

  }

  bool graph::add_node(int n)
  {
    if(n == MAX_NODES + 1)
      {
	MAX_NODES += 1;
	adj_list[MAX_NODES] = vector<int>();
	return true;
      }
    return false;
  }
  
  ostream& operator<< (ostream& os, const graph& g)
  {
    os << g.MAX_NODES << ',' << g.MAX_EDGES;
    os << ',';
 
    for( auto &to_nodes: g.adj_list)
      {
	int from = to_nodes.first;
	for(auto &to: to_nodes.second)
	  {
	    os << from << ':' << to ;
	  }
	
    }
    return os;
    
  }


  istream& operator>> (istream& is, graph& g)
  {
    char seperator;
    
    is >> g.MAX_NODES >> seperator >> g.MAX_EDGES;
    for( int i = 0; i < g.MAX_EDGES; i++)
      {
	int to, from;
	is >> seperator >> from >> seperator >> to;
	g.adj_list[from].push_back(to);
      }
    return is;
    
  }
  

}

