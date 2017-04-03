#include "alternative_node.h"

bool AlternativeNode::validate( bool fatherExist, set<Node*> testCase) {
  bool thisExist = exist(testCase);

  if( !basicValidate(fatherExist, testCase) )
    return false;

  if( thisExist ) {
    bool condition = false; // one of the sub-features must be selected.
    for (size_t i = 0; i < children.size(); i++) {
      if( children[i]->exist(testCase) ) {
        if(condition)
          return false;
        condition = true;
      }
    }
    if(!condition)
      return false;
  }

  return true;
}
