//
//  KaragerMinimumCutAlgorithm.cpp
//  KaragerAlgorithmMinCuts
//
//  Created by Amr Rady on 6/2/18.
//  Copyright © 2018 Amr Rady. All rights reserved.
//
#include "../Course1_PS04/KaragerMinimumCutAlgorithm.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "../Course1_PS04/graphRepresentationPractice.h"


using namespace std;



int
findSubsetParent(vector<Subset>& subsets, int i){
    if(subsets[i].getParent() != i)
        subsets[i].setParent(findSubsetParent(subsets, subsets[i].getParent()));

    return subsets[i].getParent();
}


void
unionVertices(vector<Subset>& subsets, int src, int dest){

    if(subsets[src].getRank() > subsets[dest].getRank())
        subsets[dest].setParent(subsets[src].getParent());
    else if(subsets[src].getRank() < subsets[dest].getRank())
        subsets[src].setParent(subsets[dest].getParent());
    else{
        subsets[dest].setParent(subsets[src].getParent());
        subsets[src].setRank(subsets[src].getRank() + 1);
    }
}

int
karagerMinCutAlgorithm(Graph& graph){

   //srand(time(NULL));
    // prepare subsets
    vector<Subset> subsets(graph.getNumberOfVertices());
    for (int v=0, n=graph.getNumberOfVertices(); v < n; v++) {
        subsets[v].setParent(v);
        subsets[v].setRank(0);
    }
    // loop to contract vertics
    while(graph.getNumberOfVertices() > 2){
        int randomEdge = rand() % graph.getGraphEdges().size();
        int parentSrc  = findSubsetParent(subsets, graph.getGraphEdges()[randomEdge].getSrc());
        int parentDest = findSubsetParent(subsets, graph.getGraphEdges()[randomEdge].getDest());

        if(parentSrc != parentDest){
            graph.setNumberOfVertices(graph.getNumberOfVertices() - 1);
            unionVertices(subsets, parentSrc, parentDest);
            //cout << "Contracting Edge Between : " << parentSrc << " --- " << parentDest <<  endl;
        }
    }

    int minCuts = 0;
    
    for (int i=0, n=graph.getGraphEdges().size(); i < n ; i++) {
        int parentSrc  = findSubsetParent(subsets, graph.getGraphEdges()[i].getSrc());
        int parentDest = findSubsetParent(subsets, graph.getGraphEdges()[i].getDest());
        
        if(parentSrc != parentDest){
            minCuts++;
        }
    }

    // cout << "Cut found by Karger's randomized algo is " << minCuts << endl;
    return minCuts;
}
