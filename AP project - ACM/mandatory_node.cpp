#include "mandatory_node.h"

bool MandatoryNode::validate( bool fatherExist, set<Node*> testCase) {
  bool thisExist = exist(testCase);

  if( !basicValidate(fatherExist, testCase) )
    return false;

  // child feature is required.
  if( thisExist )
    for (size_t i = 0; i < children.size(); i++)
      if( !children[i]->exist(testCase) )
        return false;

  return true;
}
