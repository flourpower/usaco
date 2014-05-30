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
	int a,b,c,d,e; //individual letters
	int fst, snd; //first and second rows of problem
	int l1, l2, l3; //snd, third, and fourth answers
	int current, answer;
	int l1f, l2f, l3f, l1s, l2s, l3s, l1t, l2t, l3t, l3ff;
	answer = 0; //so far, no unique solutions 
	for(a = 0; a < set_size; a++){
		for(b = 0; b < set_size; b++){
			for (c = 0; c < set_size; c++)
				for(d = 0; d < set_size; d++){
					for(e = 0; e < set_size;e++){
						//do out the multiplication here
						//then filter
						if (ints[c] == 0)
							cout << "help " << c << endl;
						fst = ints[c]*100 + ints[d]*10 + ints[e];
						snd = ints[a]*10 + ints[b];
						l1 = ints[b] * fst;
						l2 = ints[a] * fst;
						l3 = fst * snd;
						current = 1;
						//l3 has 4 digits exactly
						if (l3 < 1000 || l3 > 9999){current *= 0;}
						//l2 has 3 digits exactly
						if (l2 < 100 || l2 > 999){current *= 0;}
						//l1 has 3 digits exactly
						if (l1 < 100 || l1 > 999){current *= 0;}
						//first  digit of l1 is in set
						
						l1f  = l1 % 10;
						l1s  = ((l1 - l1f)/ 10) % 10; 
						l1t  = (l1 - l1f - (l1s * 10)) / 100;
						l2f  = l2 % 10;
						l2s  = ((l2 - l2f)/ 10) % 10;
						l2t  = (l2 - l2f - (l2s * 10)) / 100;
						l3f  = l3 % 10;
						l3s  = ((l3 - l3f)/ 10) % 10; 
						l3t  = ((l3 - l3f - (l3s * 10) ) / 100) % 10; 
						l3ff = (l3 - l3f - (l3s * 10) - (l3t * 100)) / 1000;
						if (find(ints.begin(), ints.end(),l1f) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l1s) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l1t) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l2f) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l2s) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l2t) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l3f) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l3s) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l3t) == ints.end()){
							current*=0;
						}
						if (find(ints.begin(), ints.end(),l3ff) == ints.end()){
							current*=0;
						}
						
						if (current == 1){
							answer++;
							cout << ints[c] << ints[d] << ints[e] << " ";
							cout << fst << " " << snd << endl;	
						}
					}
				}
		}
	}
	cout << "the set has size: " << set_size << endl; 
	for(i = 0; i < set_size; i++){
		cout << ints[i] << " "; 
	}
	cout << endl;
	fout << answer << endl;
}








