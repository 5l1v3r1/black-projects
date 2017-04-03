#ifndef _ALTERNATIVE_NODE_
#define _ALTERNATIVE_NODE_

#include "node.h"

using namespace std;

class AlternativeNode : public Node {
public:

  AlternativeNode( vector<Node*> _children ) : Node(_children) {}
  bool validate( bool fatherExist, set<Node*> testCase);

private:
};

#endif /* _ALTERNATIVE_NODE_ */
