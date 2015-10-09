#include <iostream>
#include <vector>
#include "Edge.h"
#include "Graph.h"
#include "Matrix.h"
#include "Vertex.h"


using namespace std;

Edge::Edge(Vertex *v1, Vertex *v2){

  //check if the vertices are null
  if (v1 == NULL){
    cout<<"v1 is null\n";
  }
  else{
    m_v1 = v1; //v1 is not null so set private data member to it
  }
  if (v2 == NULL){
    cout<<"v2 is null\n"; //v2 is not null so set private data member to it
  }
  else{
  m_v2 = v2;
  }

}

Vertex* Edge::GetV1() const{

  //return v1
  return m_v1;
}

Vertex* Edge::GetV2() const{

  //return v2
    return m_v2;
}

void Edge::SetV1(Vertex *v){

  //check if vertex is null
  if (v == NULL){
    cout<<"Warning, v is null\n'";
  }
  else{
    m_v1 = v; //the vertex is not null so set private data member to it
  }

}

void Edge::SetV2(Vertex *v){

  //check if vertex is null
  if (v == NULL){
    cout<<"Warning, v is null\n'";
    //m_v2 = v; 
  }
  else{
    m_v2 = v; //the vertex is not null so set private data member to it
  }

}

ostream& operator << (ostream &sout, const Edge &e){
  
  //overload output operator for edges
  Vertex* v1 = e.m_v1;
  Vertex* v2 = e.m_v2;
  sout<<*v1<<" <--> "<<*v2;
  return sout;

}
