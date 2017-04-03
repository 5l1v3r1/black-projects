#ifndef _OPTIONAL_NODE_
#define _OPTIONAL_NODE_

#include "node.h"

using namespace std;

class OptionalNode : public Node {
public:

  OptionalNode( vector<Node*> _children ) : Node(_children) {}
  bool validate( bool fatherExist, set<Node*> testCase);
  
private:
};

#endif /* _OPTIONAL_NODE_ */
