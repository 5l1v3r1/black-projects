#ifndef _MANDATORY_NODE_
#define _MANDATORY_NODE_

#include "node.h"

using namespace std;

class MandatoryNode : public Node {
public:

  MandatoryNode( vector<Node*> _children ) : Node(_children) {}
  bool validate( bool fatherExist, set<Node*> testCase);
  
private:
};

#endif /* _MANDATORY_NODE_ */
