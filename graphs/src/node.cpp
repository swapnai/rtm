#include "node.hpp"


NodeVector Node::get_inputs() {
  return m_inputs;
}

NodeVector Node::get_outputs() {
  return m_outputs;
}
