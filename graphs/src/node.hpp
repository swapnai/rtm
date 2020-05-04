#include <iostream>
#include <vector>

class Node; 
using NodeVector = std::vector<std::shared_ptr<Node>>;

class Node {
  
public:
  Node() = default;

  Node(NodeVector& inputs) :
    m_inputs(inputs) {}
  Node(NodeVector& inputs, NodeVector& outputs) :
    m_inputs(inputs), m_outputs(outputs) {}
  NodeVector get_inputs();
  NodeVector get_outputs();
  

private:
  NodeVector m_inputs;
  NodeVector m_outputs;


};
