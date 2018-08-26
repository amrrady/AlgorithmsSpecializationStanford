/*
 * main.cpp
 *
 *  Created on: Aug 26, 2018
 *      Author: arady
 */
#include "../Course1_PS02/countArrayInversions.hpp"

#include <iostream>
#include <fstream>

using namespace std;

int main(){

	vector<int> v;
	fstream inFile;
	inFile.open("Course1_PS02/IntegerArray.txt");

	if(inFile.is_open()){

		int temp = 0;

		while(inFile>>temp)
			v.push_back(temp);

	}else{

		cout << "Can't read the file" << endl;
	}

	cout << "Number Of Inversion is: " << countArrayInversions(v) << endl;;

	return 0;
}
