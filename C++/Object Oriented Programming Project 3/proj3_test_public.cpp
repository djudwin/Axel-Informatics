#include <iostream>
#include <vector>
#include <set>
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "Matrix.h"
//#include "../gtest-1.7.0/include/gtest/gtest.h"
#include "/afs/umbc.edu/users/c/m/cmarron/pub//gtest-1.7.0/include/gtest/gtest.h"

using namespace std;

bool isSymmetric(const Matrix &m);
bool diagIsOne(const Matrix &m);
set<int> degreeSequence(const Matrix &m);

TEST(Project3_BASIC, Vertex_DefaultConstructor_Accessor) {
  const int num_vert = 20;

  vector<Vertex *> v;
  
  for (int i = 0; i < num_vert; i++) 
    v.push_back( new Vertex );

  for (int i = 0; i < num_vert; i++)
    ASSERT_NE((Vertex *) NULL, v[i]);

  for (int i = 1; i < num_vert; i++)
    for (int j = 0; j < i; j++)
      EXPECT_NE(v[i]->GetID(), v[j]->GetID());
}

TEST(Project3_BASIC, Edge_NonDefaultConstructor_Accessor) {
  Vertex *v1 = new Vertex;
  Vertex *v2 = new Vertex;

  Edge e1(v1, v2);

  EXPECT_EQ(v1, e1.GetV1());
  EXPECT_EQ(v2, e1.GetV2());

  Vertex *v3 = new Vertex;

  e1.SetV2(v3);
  e1.SetV1(v2);

  EXPECT_EQ(v2, e1.GetV1());
  EXPECT_EQ(v3, e1.GetV2());
}

TEST(Project3_BASIC, Graph_NonDefaultConstructor) {
  const int num_vert = 50;

  vector<Vertex *> vertices;

  for (int i = 0; i < num_vert; i++) 
    vertices.push_back( new Vertex );

  vector<Edge *> edges;

  for (int i = 0; i < num_vert - 1; i++)
    edges.push_back( new Edge(vertices[i], vertices[i+1]) );
  edges.push_back( new Edge(vertices[0], vertices[num_vert - 1]) );

  Graph G(vertices, edges);

  EXPECT_EQ(vertices, G.GetVertices());
  EXPECT_EQ(edges, G.GetEdges());

}

TEST(Project3_INTERMEDIATE, Graph_GetAdjacencyMatrix_1) {
  Graph G;
  Matrix A;

  G.LoadFromFile("data/v5_c_h.dat");
  A = G.GetAdjacencyMatrix();
  
  EXPECT_EQ(A.GetNumRows(), 5);
  EXPECT_EQ(A.GetNumCols(), 5);

  EXPECT_EQ(isSymmetric(A), true);
  EXPECT_EQ(diagIsOne(A), true);
  
  set<int> deg;

  /* degree sequence is 3 */

  deg.insert(3);

  EXPECT_EQ(degreeSequence(A), deg);
 }

TEST(Project3_INTERMEDIATE, Graph_GetAdjacencyMatrix_2) {
  Graph G;
  Matrix A;

  G.LoadFromFile("data/v20_nc.dat");
  A = G.GetAdjacencyMatrix();
  
  EXPECT_EQ(A.GetNumRows(), 20);
  EXPECT_EQ(A.GetNumCols(), 20);

  EXPECT_EQ(isSymmetric(A), true);
  EXPECT_EQ(diagIsOne(A), true);
  
  set<int> deg;

  /* degree sequence is 1, 2, 3, 4, 5, 6 */

  for (int i = 1; i <= 6; i++)
    deg.insert(i);

  EXPECT_EQ(degreeSequence(A), deg);
 }



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

bool isSymmetric(const Matrix &m) {
  int nrow = m.GetNumRows();
  int ncol = m.GetNumCols();

  if (nrow != ncol)
    return false;
  else if (nrow <= 1)
    return true;
  else {
    for (int i = 1; i < nrow; i++)
      for (int j = 0; j < i; j++)
	if ( m.Get(i,j) != m.Get(j, i) )
	  return false;
  }
  
  return true;
}

bool diagIsOne(const Matrix &m) {
  int nrow = m.GetNumRows();
  int ncol = m.GetNumCols();

  int size = ( nrow < ncol ? nrow : ncol );

  if (size == 0)
    return true;

  for (int i = 0; i < size; i++)
    if ( m.Get(i,i) != 1.0 )
      return false;

  return true;
}

set<int> degreeSequence(const Matrix &m) {
  set<int> deg;

  int nrow = m.GetNumRows();
  int ncol = m.GetNumCols();

  if (nrow != ncol)
    return deg;

  for (int i = 0; i < nrow; i++) {
    double sum = 0.0;
    for (int j = 0; j < ncol; j++)
      sum += m.Get(i, j);
    deg.insert(static_cast<int>(sum));
  }

  return deg;
}
  
