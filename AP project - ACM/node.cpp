#include "node.h"
#include "optional_node.h"

bool Node::exist( set<Node*> testCase ) {

  // OptionalNode allway say I'm exist!
  if( dynamic_cast<OptionalNode*>(this) )
      return true;

  return testCase.find(this) != testCase.end();

}

bool Node::basicValidate( bool fatherExist, set<Node*> testCase ) {
  bool thisExist = exist(testCase);

  // father not exist but child exist!
  if( !dynamic_cast<OptionalNode*>(this) ) {  // normale node

    if( !fatherExist && thisExist )
      return false;

    // validate children nodes
    for (size_t i = 0; i < children.size(); i++)
      if( !children[i]->validate(thisExist, testCase) )
        return false;

  } else {  // optional node

    // validate children nodes
    for (size_t i = 0; i < children.size(); i++)
      if( !children[i]->validate(fatherExist, testCase) )
        return false;

  }

  return true;
}
