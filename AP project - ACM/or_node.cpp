#include "or_node.h"

bool OrNode::validate( bool fatherExist, set<Node*> testCase) {
  bool thisExist = exist(testCase);

  if( !basicValidate(fatherExist, testCase) )
    return false;

  if( thisExist ) {
    bool condition = false; // at least one of the sub-features must be selected
    for (size_t i = 0; i < children.size(); i++)
      if( children[i]->exist(testCase) )
        condition = true;

    if(!condition)
      return false;
  }

  return true;
}
