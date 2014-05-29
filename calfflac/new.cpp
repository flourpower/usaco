/*
ID: odenaau1
PROG: calfflac
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
	ofstream fout ("calfflac.out");
    	ifstream fin ("calfflac.in");
    	char buffer;
	int i, j, k, p, len, current, max, 
		start, finish, new_j, new_k, parity;
	vector<char> chrs, final;
    	while (fin >> noskipws >> buffer){
		chrs.push_back(tolower(buffer));
		final.push_back(buffer);
	}
	len = chrs.size();
	//find the longest even palindrome
	
	//init the length placeholders
	current = 0;
	max = 0;
	//for every letter
	for(i = 0; i < len; i++){
		//if (i ==  23)
		//	cout << "index: " <<  i << " char: " << chrs[i] << endl;
		j = i; //start both counters at i
		k = i;
		current = 1;
		//while we are within bounds and both sides the same
		while(j > 0 && k < (len - 1) && chrs[j] == chrs[k]){
			new_j = j - 1;
			new_k = k + 1;
			while( (! isalpha(chrs[new_j])) && new_j >= 0 ){new_j--;}
			while( (! isalpha(chrs[new_k])) && new_k <= (len - 1)){new_k++;}
			//if (i == 23)
			//	cout << new_j << " " << new_k << endl;
			if(chrs[new_j] == chrs[new_k]){
				j = new_j;
				k = new_k;
				current += 2;
			}
			else{
				break;
			}

		}
		if (current > max){ //then update max and the pointers
			max = current;
			start = j;
			finish = k;
			parity = 1;
		}
	}
	
	//find the longest odd palindrome	
	//for every pair of 2 letters
	for(i = 0; i < len - 1; i++){
		j = i;
		k = i + 1;
		while( ! isalpha(chrs[k])){
			k++;
		}
		current = 2;
		if (chrs[j] != chrs[k])
			continue;
		
		while(j > 0 && k < (len - 1) && chrs[j] == chrs[k]){
			new_j = j - 1;
			new_k = k + 1;
			while( (! isalpha(chrs[new_j])) && new_j >= 0 ){new_j--;}
			while( (! isalpha(chrs[new_k])) && new_k <= (len - 1)){new_k++;}
			if(chrs[new_j] == chrs[new_k]){
				j = new_j;
				k = new_k;
				current += 2;
			}
			else{
				break;
			}

		}	
	
		if (current > max){
			max = current;
			start = j;
			finish = k;
			parity = 0;
		}
	}	
	//finish up
	fout << "parity: " << parity << endl;
	fout << max << endl;
	for (i = start; i <= finish; i++){
		fout << final[i];
	}
	fout << endl;
}








