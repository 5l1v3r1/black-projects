#include "sample_node.h"

bool SampleNode::validate( bool fatherExist, set<Node*> testCase) {
  if( !basicValidate(fatherExist, testCase) )
    return false;

  return true;
};
