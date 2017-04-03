#ifndef _NODE_
#define _NODE_

#include <string>
#include <vector>
#include <set>

using namespace std;

class Node {
public:

  Node( vector<Node*> _children ) : children(_children) {}

  bool exist( set<Node*> testCase );
  bool basicValidate( bool fatherExist, set<Node*> testCase );
  virtual bool validate( bool fatherExist, set<Node*> testCase ) = 0;

protected:
  vector<Node*> children;

private:
};

#endif /* _NODE_ */
