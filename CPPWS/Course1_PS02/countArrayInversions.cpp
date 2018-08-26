//
//  countArrayInversions.cpp
//  Stanford_Algorithms_1
//
//  Created by Amr Rady on 5/6/18.
//  Copyright © 2018 Amr Rady. All rights reserved.
//

#include "countArrayInversions.hpp"

#include <iterator>

using namespace std;

unsigned long long int
mergeAndcountArrayInversions(vector<int>& arr, unsigned int left, unsigned int middle, unsigned int right){
    
   unsigned long long int numberOfInversions = 0;
    
    vector<int>::iterator arrStartIt = arr.begin() + left;
    vector<int>::iterator arrMidIt   = arr.begin() + middle + 1; // go one after the last element
    vector<int>::iterator arrEndIt   = arr.begin() + (right + 1); // go one after the last element
    
    vector<int> leftArr(arrStartIt, arrMidIt);
    vector<int> rightArr(arrMidIt, arrEndIt);
    
    
    int i =0, j = 0, k = left;
    
    while ( (i < leftArr.size()) && (j < rightArr.size()) ) {
        
        if(leftArr[i] < rightArr[j]){
            arr[k++] = leftArr[i++];
        }else{
            arr[k++] = rightArr[j++];
            numberOfInversions += leftArr.size() - i;
        }
    }
    
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
    
    
    return numberOfInversions;
}

unsigned long long int
countSubArrayInversions(vector<int>& arr, unsigned int left, unsigned int right){
    
    if(left >= right)  return 0;
    unsigned int middle = left + (right - left) / 2;
    return countSubArrayInversions(arr ,left, middle) + countSubArrayInversions(arr , middle + 1, right) + mergeAndcountArrayInversions(arr, left, middle, right);
}


unsigned long long int
countArrayInversions(vector<int>& arr){
    unsigned int left = 0;
    unsigned int right = arr.size() - 1;
    
    return countSubArrayInversions(arr, left, right);
}









