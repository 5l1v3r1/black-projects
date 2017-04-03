#include "optional_node.h"

bool OptionalNode::validate( bool fatherExist, set<Node*> testCase) {

  if( !basicValidate(fatherExist, testCase) )
    return false;

  // child feature is optional.
  return true;
}
