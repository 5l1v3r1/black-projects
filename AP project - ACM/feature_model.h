#ifndef _FEATUREMODEL_
#define _FEATUREMODEL_

#include <string>
#include <map>
#include <set>

#include <iostream>

#include "node.h"
#include "exception.h"

#include "alternative_node.h"
#include "mandatory_node.h"
#include "optional_node.h"
#include "sample_node.h"
#include "or_node.h"

using namespace std;

class FeatureModel {
public:
  FeatureModel() {}
  ~FeatureModel();

  void setRoot( string name );
  void addAlternativeNode( string name, vector<string> children );
  void addMandatoryNode( string name, vector<string> children );
  void addOptionalNode( string name, vector<string> children );
  void addOrNode( string name, vector<string> children );
  void addSampleNode( string name );

  bool validate( vector<string> testCase );
  vector<Node*> findAllNodes( vector<string> nodeList );

private:
  map<string, Node*> nodes;
  Node* root;
};

#endif /* _FEATUREMODEL_ */
