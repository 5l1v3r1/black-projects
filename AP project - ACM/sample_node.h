#ifndef _SAMPLE_NODE_
#define _SAMPLE_NODE_

#include "node.h"

using namespace std;

class SampleNode : public Node {
public:

  SampleNode() : Node( vector<Node*> (0) ) {}
  bool validate( bool fatherExist, set<Node*> testCase);
  
private:
};

#endif /* _SAMPLE_NODE_ */
