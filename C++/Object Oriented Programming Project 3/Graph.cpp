#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "Matrix.h"

using namespace std;

Graph::Graph()
{ /* nothing to do */ }

Graph::Graph(vector<Vertex *> vertices, vector<Edge *> edges) :
  m_vertices(vertices), m_edges(edges)
{
  //check if vertex object is null
  for (int i = 0; i < vertices.size(); i++)
    if (vertices[i] == NULL) {
      cerr << "Error: Graph constructor expects non-null vertices." << endl;
      exit(1);
    }
  //check if edge object is null
  for (int i = 0; i < edges.size(); i++)
    if (edges[i]->GetV1() == NULL || edges[i]->GetV2() == NULL) {
      cerr << "Error: Graph constructor expects edges with non-null vertices." << endl;
      exit(1);
    }
}      

bool Graph::LoadFromFile(string fileName) {
  int numVertices;
  int v1, v2;
  vector<Vertex*> vertices;
  vector<Edge*> edges;
  ifstream dataFile;
      
  /* Set exception flags for file input stream */ 

  dataFile.exceptions(ios::failbit | ios::badbit);

  try {
  
    dataFile.open(fileName.c_str());
    dataFile >> numVertices;

    for ( int i = 0; i < numVertices; i++ ){
      vertices.push_back( new Vertex() );
    }

    dataFile >> v1 >> v2;

    while ( v1 > 0 && v2 > 0 ) {
      if (v1 <= numVertices && v2 <= numVertices ){
	edges.push_back( new Edge(vertices[v1-1], vertices[v2-1]) );
      dataFile >> v1 >> v2;
      }}

    dataFile.close();
  }
  catch (exception e) {
    return false;
  }

  m_vertices = vertices;
  m_edges = edges;

  return true;
}

int Graph::GetNumVertices() const{

  //returns number of vertices in the graph object
  int numVertices = m_vertices.size();
  return numVertices;

}  

int Graph::GetNumEdges() const{

  //returns number of edges in the graph object
  return (m_edges.size());

}

vector<Vertex *> Graph::GetVertices() const{

  //returns the vector of vertices in the graph object
  return m_vertices;

}

vector<Edge *> Graph::GetEdges() const{

  //returns the vector of edges in the graph object
  return m_edges;

}

Matrix Graph::GetAdjacencyMatrix() const{

  //retreive vertices and number of vertices
  int numVertices = Graph::GetNumVertices();
  Matrix matrix(numVertices, numVertices);
  double zero = 0.0;
  double one = 1.0;
  //retreive edges and number of edges
  int numEdges = Graph::GetNumEdges();
  vector<Edge *> tempEdges = Graph::GetEdges();
  //set diagonal cells of matrix to one and rest to zero
  for (int i = 0;i<numVertices;i++){
    for (int j = 0;j<numVertices;j++){
      if (i == j){
        matrix.Set(i,j,one);
      }
      else{
	matrix.Set(i,j,zero);
      }
    }
  }
  //set cells that correspond to vertices to one
  for (int i = 0;i<numEdges;i++){
    Edge* edge = tempEdges[i];
    Vertex* v1 = edge->GetV1(); //call vertex accessor
    Vertex* v2 = edge->GetV2(); //call vertex accessor
    int vertex1 = v1->GetID();
    vertex1 = vertex1 % numVertices;
    int vertex2 = v2->GetID();
    vertex2 = vertex2 % numVertices;
    matrix.Set(vertex1,vertex2,one); //set cell to one
    matrix.Set(vertex2,vertex1,one); //set cell to one
  }
  return matrix;

}


vector<Vertex *> Graph::GetConnectedComponent(Vertex *v) const{

  //retreive vector of vertices
  int numVertices = Graph::GetNumVertices(); //retreive number of vertices
  int vertexID = v->GetID();
  double one = 1.0;
  double doubleZero = 0.0;
  int zero = 0;
  vector<double> vecProduct1;
  vector<double> vecProduct2;
  vector<Vertex *> tempVertices = Graph::GetVertices();

  //Create column vector                                                                
  vector<double> column;
  for(int i = 0;i<numVertices;i++){
    if (i == vertexID){
      column.push_back(one);
    }
    else{
      column.push_back(doubleZero);
    }
  }

  Matrix matrix(numVertices, numVertices);
  matrix = Graph::GetAdjacencyMatrix(); //retreive adjacency matrix
  vecProduct1 = column;
  bool flag = true;
  do{
    //compute matrix-vector product                                                 
    vecProduct1 = matrix.Matvec(vecProduct1);
    //Convert nonzero numbers to ones
    for (int i = 0;i<vecProduct1.size();i++){
      if (vecProduct1[i]>doubleZero){
	vecProduct1[i] = one;
      }
    }
    vecProduct2 = matrix.Matvec(vecProduct1);
    //Convert nonzero numbers to ones
    for (int i = 0;i<vecProduct2.size();i++){
      if (vecProduct2[i]>doubleZero){
	vecProduct2[i] = one;
      }
    }
    if (vecProduct2 == vecProduct1){
      flag = false;
    }
  }
  while(flag == true);

  //create vector of the conncected vertices
  vector<Vertex *> connected;
  for (int i = 0;i<numVertices;i++){
    if (vecProduct2[i]>doubleZero){
      Vertex* returnVert = tempVertices[i];
      connected.push_back(returnVert);
	}
  }
  if (connected.size()>zero){
    return connected;
  }
  else{
    vector<Vertex *> empty;
    return empty;
  }
}
