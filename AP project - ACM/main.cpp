#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "feature_model.h"

using namespace std;

enum nodeKind { Mandatory, Optional, Alternative, Or, Sample };

vector<string> split( string s, char delim ) {
  stringstream ss(s);
  string item;
  vector<string> tokens;
  while (getline(ss, item, delim))
      tokens.push_back(item);
  return tokens;
}

void addNode( FeatureModel& F, string name, nodeKind kind, vector<string> children = vector<string> (0) ) {
  switch (kind) {
    case Mandatory:
      F.addMandatoryNode( name, children );
      break;
    case Optional:
      F.addOptionalNode( name, children );
      break;
    case Alternative:
      F.addAlternativeNode( name, children );
      break;
    case Or:
      F.addOrNode( name, children );
      break;
    case Sample:
      F.addSampleNode( name );
      break;
  }
}

inline bool isOptional(const string& s) { return s[0] == '?'; }
inline bool isNotOptional(const string& s) { return s[0] != '?'; }

string optionalString( vector<string> optionalNodes ) {
  string optionalString;
  for (size_t i = 0; i < optionalNodes.size(); i++) {
    optionalNodes[i].erase( optionalNodes[i].begin() );
    optionalString += (optionalNodes[i] + "$");
  }
  return optionalString;
}

void generateFeatureModel( FeatureModel& F, map<string, string>& fModel, string root ) {
  if( fModel.find(root) != fModel.end() ) {  // if not found generate sampleNode!

    string s = fModel[root];
    nodeKind kind;
    vector<string> nodes;

    if( s.find("+") != string::npos ) {

      vector<string> tmp = split( s, '+' );
      vector<string> optionalNodes;
      copy_if(tmp.begin(), tmp.end(), back_inserter(optionalNodes), isOptional);
      copy_if(tmp.begin(), tmp.end(), back_inserter(nodes), isNotOptional);

      // create an optionalNode
      if( optionalNodes.size() != 0 ) {
        fModel[ root + "(?)" ] = optionalString( optionalNodes );
        nodes.push_back( root + "(?)" );
      }

      kind = Mandatory;

    } else if( s.find("^") != string::npos ) {
      nodes = split( s, '^' );
      kind = Alternative;
    } else if( s.find("$") != string::npos ) {
      nodes = split( s, '$' );
      kind = Optional;
    } else {
      nodes = split( s, '|' );
      kind = Or;
    }

    for (size_t i = 0; i < nodes.size(); i++)
      generateFeatureModel( F, fModel, nodes[i] );
    addNode( F, root, kind, nodes );

  } else {
    addNode( F, root, Sample );
  }
}

map<string, string> getFeatureModel( FeatureModel& F, string& root ) {
  string line;
  map<string, string> fModel;
  while( getline(cin, line) ) {
    if( line == "#" )
      break;

    // remove blanks from line
    line.erase( remove_if( line.begin(), line.end(), ::isspace ), line.end() );

    // fill feature model
    fModel[ split(line, '=')[0] ] = split(line, '=')[1];

    // set root as first key
    if(root == "")
      root = split(line, '=')[0];
  }
  return fModel;
}

void getTestCase( FeatureModel& F ) {
  string line;
  while( getline(cin, line) ) {

    if( line == "##" )
      break;

    // remove blanks from line
    line.erase( remove_if( line.begin(), line.end(), ::isspace ), line.end() );

    line.erase( line.begin() );   // remove {
    line.erase( line.end() - 1 );   // remove }

    vector<string> testCase = split( line, ',' );
    cout << ( F.validate(testCase)? "Valid" : "Invalid" ) << endl;

  }
}

int main() {
  while( cin ) {

    FeatureModel F;
    string root;

    map<string, string> fModel = getFeatureModel( F, root );
    generateFeatureModel( F, fModel, root );
    F.setRoot( root );

    getTestCase( F );

    if( !fModel.empty() )
      cout << "##" << endl;
  }
}
