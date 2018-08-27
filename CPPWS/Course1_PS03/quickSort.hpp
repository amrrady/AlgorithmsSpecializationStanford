////
////  quickSort.hpp
////  Stanford_Algorithms_1
////
////  Created by Amr Rady on 5/15/18.
////  Copyright © 2018 Amr Rady. All rights reserved.
////
//
#ifndef quickSort_hpp
#define quickSort_hpp

#include <stdio.h>
#include <vector>


enum pivotType {firstElement, lastElement, medianOfThreeElement, randomElement};

void quickSort(std::vector<int> & arr, pivotType p);

#endif /* quickSort_hpp */
