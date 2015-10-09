/******************************************************
 ** File:        proj3.cpp
 ** Project:     CMSC 202 Project 3, Spring 2015
 ** Author:      David Udwin
 ** Date:        March 17, 2015
 ** Email:       udwin1@umbc.edu
 ** Description: This program tests the connected components 
 **              of graphs.  It does this by having a list of
 **              edges inputted, and then assembling an 
 **              adjacency matrix.  This matrix is then used
 **              to computer connected components of an invidivual
 **              vertex.
 ********************************************************/

#include <iostream>
#include <cmath>
#include<vector>
#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"
#include "Matrix.h"

using namespace std;

//Function: userSelection
//Precondtion: Program is run
//Postcondition: Returns users choice of action for the program
char userSelection();

//Function: isFileLoaded
//Precondition: Program is run
//Postcondition: States whether or not a data file is loaded
bool isFileLoaded(Graph& graph);


int main(){

  cout<<"\n";

  Graph graph; //create graph object

  //use do while loop to iterate menu
  bool flag = true;
  bool fileLoaded = false;
  string fileName;
  do {

    //check if there is already a file loaded
    fileLoaded = isFileLoaded(graph); //call function to check if file is loaded
    if (fileLoaded == true){
      cout<<"The data file "<<fileName<<" is currently loaded\n\n";
    }
    //call function to display and prompt for user input
    char selection = userSelection();//function for user input

    //use switch to interperate user input
    switch(selection) {
    case '1':
      {
	//user wishes to input file
	string tempFileName;
	cout<<"\nEnter the file name: "; //prompt user for the file name
	cin>>tempFileName;
	bool work = graph.LoadFromFile(tempFileName); //load file into graph object
	//inform user if they did not select a valid file
	if (work == false){
	  cout<<"Error loading data file ("<<tempFileName<<") .\n\n";
	}
	else{
	  cout<<endl;
	  fileName = tempFileName;
	}
	break;
      }
    case 'v':
    {

      //the user wishes to display to vertices
      vector<Vertex *> tempVertices = graph.GetVertices(); //retrieve the vertices in the graph oject
      int numVertices = graph.GetNumVertices(); //retrieve the number of vertices in the graph object
      cout<<endl;
      //display the vertices
      cout<<"Vertices:\n";
      for (int i = 0;i<numVertices;i++){
	Vertex display;
	display = *tempVertices[i];
	cout<<display<<endl; //vertex object output is overloaded 
      }
      cout<<"\n";
      break;
    }
    case 'e':
      {
	//the user wishes to dispaly edges
	int numEdges = graph.GetNumEdges(); //retrieve the number of edges in the graph object
	vector<Edge *> tempEdges = graph.GetEdges(); //retrieve the edges in the graph object
	cout<<"\nEdges:\n";
	for (int i = 0;i<numEdges;i++){
	  cout<<*tempEdges[i]<<endl; //edge object output is overloaded
	}
	cout<<"\n";
	break;
      }
    case 'c':
      {
	//the user wisehs to find connected component of vertex in graph
	vector<Vertex *> tempVertices = graph.GetVertices(); //retrieve vertices in graph object
	int vertexID;
	int highID = 0;
	int numVertices = graph.GetNumVertices(); //retrieve number of vertices in graph object
	//Find highest and lowest vertex ID
	for (int i = 0;i<numVertices;i++){
	  Vertex* findHighID = tempVertices[i];
	  int findingHighAndLow = findHighID->GetID(); //find the highest id'd vertex in the graph
	  if (findingHighAndLow > highID){
	    highID = findingHighAndLow;
	  }
	}
	int lowID = highID; //find lowest id'd vertex in the graph
	for (int i = 0;i<numVertices;i++){
	  Vertex* findLowID = tempVertices[i];
          int findingHighAndLow = findLowID->GetID();
          if (findingHighAndLow < lowID){
            lowID = findingHighAndLow;
          }
	}
	//prompt user as to which vertex they want connected component of
	cout<<"Find the connected component of a given vertex.\n";
	cout<<"Enter vertex ID:";
	cin>>vertexID;
	//inform user if they picked a vertex that does not exist
	if (vertexID > highID){
	  cout<<"Vertex with ID "<<vertexID<<" not found.\n\n";
	}
	else if (vertexID < lowID){
	  cout<<"Vertex with ID "<<vertexID<<" not found.\n\n";
	}
	//if user picked valid vertex, find connected component
	else{
	  Vertex *v = tempVertices[vertexID];
	  //call function to find connected component
	  vector<Vertex *> connected = graph.GetConnectedComponent(v);
	  //display connected component
	  cout<<"Connected component of vertex with ID "<<vertexID<<":"<<endl;
	  for (int i = 0;i<connected.size();i++){
	    Vertex display = *connected[i];
	    cout<<display<<endl;
	  }
	  cout<<endl;  
	}
	break;
      }
    case 'q':
      {
	//user wishes to quit program
	flag = false;
	cout<<"\nGoodbye!\n";
	break;
      }
      
    default:
      {
	//user entered an invalid input into the menu
	cout<<"\nPlease enter a valid input\n\n";
	break;
      }

    }

  }
  while (flag == true);

  return 0;

}

char userSelection(){

  //display menu options to user
  char selection;
  cout<<"Choose an action from the following menu:\n\n";
  cout<<"  1 - load a graph data file\n";
  cout<<"  v - list the vertices of the loaded graph\n";
  cout<<"  e - list the edges of the loaded graph\n";
  cout<<"  c - list the connected component of a specific vertex\n";
  cout<<"  q - quit\n\n";
  //prompt user to pick one of the options
  cout<<"Selection: ";
  cin>>selection;

  return selection;
}

bool isFileLoaded(Graph& graph){

  //check if a file is already loaded into the program
  bool flag;
  int zero = 0;
  int numVertices = graph.GetNumVertices(); //retrieve number of vertices
  //check if there are any vertices
  if (numVertices > zero){
    flag = true;
  }
  else{
    cout<<"There is no data file loaded.\n\n";
    flag = false;
  }
  //return whether or not a program is loaded
  return flag;
}



