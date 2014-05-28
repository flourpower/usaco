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

bool p_help(string str);

int palindrome(vector<char> & chrs, int len, int j){
	//strip non a-Z chars and call palindrome(str)
	locale loc;
	string str;
	int i;
	for(i = j; i < j + len; i++){
		if(isalpha(chrs[i]))
			str.push_back(tolower(chrs[i]));
	}
	if(p_help(str)){
		return str.length();
	} 
	return (-1);
}

bool p_help(string str){
	int i;
	for(i = 0; i < str.length(); i++){
		if(str.at(i) != str.at(str.length() - i - 1))
			return false;
	}
	return true;
}

int main() {
	ofstream fout ("calfflac.out");
    	ifstream fin ("calfflac.in");
    	char buffer;
	int len, j, k, p;
	vector<char> chrs;
    	while (fin >> noskipws >> buffer){
		chrs.push_back(buffer);
	}
	int size = chrs.size();
	int start = size;
	int answer;
	if (start > 2000)
		start = 2000;
	for(len = start; len > 0; len--){
		for(j = 0; j+len < size; j++){
			answer = palindrome(chrs, len, j);
			if (answer > 0){
				fout << answer << endl;
				p = 0;
				while(! isalnum(chrs[j + p]))
					p++;
				for (k = p; k < len - 1; k++){
					fout << chrs[j+k];
				}
				fout << endl;
				return 0;
			}
		}
	}
}








