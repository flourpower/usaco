/*
ID: odenaau1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <locale>
#include <ctype.h>

using namespace std;



int main() {
	ofstream fout ("crypt1.out");
    	ifstream fin ("crypt1.in");
	int i, set_size, buffer;  
	vector<int> ints;
	fin >> set_size;
    	for(i = 0; i < set_size; i++){
		fin >> buffer;
		ints.push_back(buffer);
	}
	int a,b,c,d,e;
	for(a = 0; a < set_size; a++){
		if (ints[a] == 0)
			continue
		for(b = 0; b < set_size; b++){
			for (c = 0; c < set_size; c++)
				if (ints[c] == 0)
					continue
				for(d = 0; d < set_size; d++){
					for(e = 0; e < set_size;e++){
						//do out the multiplication here
						//then filter
					}
				}
		}
	}
	cout << "the set has size: " << set_size << endl; 
	for(i = 0; i < set_size; i++){
		cout << ints[i] << " "; 
	}
	cout << endl;
}








