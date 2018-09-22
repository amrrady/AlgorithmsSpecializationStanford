///*
// * main.cpp
// *
// *  Created on: Aug 26, 2018
// *      Author: arady
// */
//#include "../Course1_PS02/countArrayInversions.hpp"
//#include "../Course1_PS03/quickSort.hpp"
//#include "../Course1_PS04/KaragerMinimumCutAlgorithm.h"
//#include "../Course1_PS04/graphRepresentationPractice.h"
//#include <iostream>
//#include <fstream>
//#include <sstream>
//
//using namespace std;
//
//
//void readAdjacencyList(string fileName, Graph& graph){
//   ifstream infile(fileName);
//   string line;
//    if(!infile.is_open())
//    {
//        cout << "can't read " << fileName << endl;
//        return;
//    }
//  while (getline(infile, line))
//   {
//       istringstream is( line );
//       int srcVertex = 0;
//       is >> srcVertex;
//       int destVertex;
//       while( is >> destVertex ) {
//           graph.getGraphEdges().push_back(Edge(srcVertex - 1, destVertex - 1));
//       }
//   }
//}
//
//int main(){
//
//	vector<int> v;
//	//fstream inFile;
//	//inFile.open("Course1_PS04/kargerMinCut.txt");
////	if(inFile.is_open()){
////
////		int temp = 0;
////
////		while(inFile>>temp)
////			v.push_back(temp);
////
////	}else{
////
////		cout << "Can't read the file" << endl;
////	}
//
//
//
//    Graph graph(200,0);
//    readAdjacencyList("Course1_PS04/kargerMinCut.txt", graph);
//    int edgeCuts = karagerMinCutAlgorithm(graph);
//    //int edgeCuts = edgeCuts;
//    int minCuts = edgeCuts;
//
//    for (int i=0; i< 2000; i++) {
//        Graph tgraph(200,0);
//        readAdjacencyList("Course1_PS04/kargerMinCut.txt", tgraph);
//        edgeCuts = karagerMinCutAlgorithm(tgraph);
//        if(edgeCuts < minCuts){
//            minCuts = edgeCuts;
//            // since the representation add 2 edges for eah 2 connected vertices
//            // we have to divide by 2
//            cout << "Minimum Cuts = " << minCuts / 2 <<endl;
//        }
//    }
//	return 0;
//}
