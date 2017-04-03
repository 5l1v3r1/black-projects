#include "feature_model.h"

FeatureModel::~FeatureModel() {
  for(map<string, Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    delete it->second;
}

vector<Node*> FeatureModel::findAllNodes( vector<string> nodeList ) {

  vector<Node*> result;
  for (size_t i = 0; i < nodeList.size(); i++) {
    if( nodes.find(nodeList[i]) == nodes.end() )
      throw NodeNotFound( nodeList[i] );

    result.push_back( nodes[nodeList[i]] );
  }
  return result;

}

void FeatureModel::addSampleNode( string name ) {
  if( nodes.find(name) != nodes.end() )
    throw NodeExist( name );
  nodes[name] = new SampleNode();
}

void FeatureModel::addAlternativeNode( string name, vector<string> children ) {
  if( nodes.find(name) != nodes.end() )
    throw NodeExist( name );
  nodes[name] = new AlternativeNode( findAllNodes(children) );
}

void FeatureModel::addMandatoryNode( string name, vector<string> children ) {
  if( nodes.find(name) != nodes.end() )
    throw NodeExist( name );
  nodes[name] = new MandatoryNode( findAllNodes(children) );
}

void FeatureModel::addOptionalNode( string name, vector<string> children ) {
  if( nodes.find(name) != nodes.end() )
    throw NodeExist( name );
  nodes[name] = new OptionalNode( findAllNodes(children) );
}

void FeatureModel::addOrNode( string name, vector<string> children ) {
  if( nodes.find(name) != nodes.end() )
    throw NodeExist( name );
  nodes[name] = new OrNode( findAllNodes(children) );
}

void FeatureModel::setRoot( string name ) {
  root = nodes[name];
}

bool FeatureModel::validate( vector<string> testCase ) {

  try {

    vector<Node*> testCaseNodesV = findAllNodes( testCase );
    set<Node*> testCaseNodes( testCaseNodesV.begin(), testCaseNodesV.end() ); // create set from vector

    if( root != NULL )
      return root->validate( true, testCaseNodes );
    else
      throw RootNotSet();

  } catch( NodeNotFound ) {
    return false;
  }

}
