#ifndef _EXCEPTION_
#define _EXCEPTION_

#include <string>

using namespace std;

class Exception {
public:
    Exception( string _name ) : name(_name) {}
    Exception() {}
    string who() { return name; }
protected:
    string name;
};

class NodeNotFound : public Exception {
public:
    NodeNotFound( string _name ) : Exception(_name) {}
};

class NodeExist : public Exception {
public:
    NodeExist( string _name ) : Exception(_name) {}
};

class RootNotSet : public Exception {
public:
    RootNotSet() : Exception() {}
};


#endif /* _EXCEPTION_ */
