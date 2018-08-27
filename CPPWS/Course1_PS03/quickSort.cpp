//
//  quickSort.cpp
//  Stanford_Algorithms_1
//
//  Created by Amr Rady on 5/15/18.
//  Copyright © 2018 Amr Rady. All rights reserved.
//

#include "quickSort.hpp"

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

unsigned long long int numberOfComparison = 0;


void quickSortAlg(vector<int> & arr, unsigned int left, unsigned int right, pivotType pType){

	srand (time(NULL));

    unsigned int numberOfElements = right - left + 1;
    if(numberOfElements <= 1) return;

    numberOfComparison += (numberOfElements - 1);



	if(pType == firstElement){
		;//do nothing
	}else if(pType == lastElement){
		swap(arr[left], arr[right]);
	}else if(pType == medianOfThreeElement){
		swap(arr[left], arr[ (left + right)/2]);
	}else if(pType == randomElement){
	    unsigned int randomIndex = rand()%((right - left) + 1) + left;
	    swap(arr[left], arr[randomIndex]);
	}



    int pivot = arr[left];
    unsigned int i = left+1;
    
    for (unsigned int j = left+1; j <= right; j++){
        if(arr[j] < pivot){
            swap(arr[j] , arr[i]);
            i++;
        }
    }
    
    swap(arr[left], arr[i-1]);
    

    quickSortAlg(arr, left, i-2, pType);
    quickSortAlg(arr,  i, right, pType);
    
}

void quickSort(vector<int> & arr, pivotType p){
	numberOfComparison = 0;
    unsigned int left = 0;
    unsigned int right = arr.size() - 1;
    quickSortAlg(arr, left, right,p);
    
    cout <<"number of comparison : " << numberOfComparison << endl;
    //138382
}
