#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "Matrix.h"

using namespace std;

int Vertex::m_ID;

Vertex::Vertex(){

  m_returnValue = m_ID++; //gives each vertex a unique id
}

int Vertex::GetID() const{
  return m_returnValue; //returns the unique id of the vertex
}


ostream & operator << (ostream& sout, const Vertex& vertex){

  //overload the output operator for vertex objects
  sout<<"ID: "<<vertex.GetID();
  return sout;

}
