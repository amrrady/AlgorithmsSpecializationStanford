//
//  graphRepresentationPractice.hpp
//  KaragerAlgorithmMinCuts
//
//  Created by Amr Rady on 6/2/18.
//  Copyright © 2018 Amr Rady. All rights reserved.
//

#ifndef graphRepresentationPractice_h
#define graphRepresentationPractice_h

#include <vector>
using namespace std;

class Edge{
public:
    
    Edge():src(0),dest(0){}
    Edge(int src, int dest):src(src),dest(dest){}
    
    int  getSrc()const{ return src; }
    void setSrc(int src){ this->src = src; }
    
    int  getDest()const{return dest;}
    void setDest(int dest) {this->dest = dest;}
    
private:
    int src;
    int dest;
};


class Graph{
public:
    Graph(): numberOfVertices(0),graphEdges(0){}
    Graph(int numberOfVertices, int numberOfEdges):numberOfVertices(numberOfVertices), graphEdges(numberOfEdges){}
    
    int  getNumberOfVertices()const{return numberOfVertices;}
    void setNumberOfVertices(int numberOfVertices) {this->numberOfVertices = numberOfVertices;}
    void cleanGraph(){numberOfVertices = 0; graphEdges.clear();}
    vector<Edge>& getGraphEdges(){return graphEdges;}
private:
    int numberOfVertices;
    vector<Edge> graphEdges;
};


class Subset{
public:
    Subset() : parent(0), rank(0){}
    Subset(int parent, int rank) : parent(parent), rank(rank){}
    
    int  getParent()const{return parent;}
    void setParent(int parent){this->parent = parent;}
    
    int  getRank()const {return rank;}
    void setRank(int rank){this->rank = rank;}
    
private:
    int parent;
    int rank;
};

#endif
