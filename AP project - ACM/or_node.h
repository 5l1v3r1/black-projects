#ifndef _OR_NODE_
#define _OR_NODE_

#include "node.h"
using namespace std;

class OrNode : public Node {
public:

  OrNode( vector<Node*> _children ) : Node(_children) {}
  bool validate( bool fatherExist, set<Node*> testCase);
  
private:
};

#endif /* _OR_NODE_ */
