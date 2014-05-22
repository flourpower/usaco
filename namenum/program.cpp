/*
ID: odenaau1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

/*
Read in all of the names from dict.txt into a string set
read each character in the input into an array

*/


using namespace std;

bool valid_help(char c, char k){
	switch (k) {
		case '2':
	    	if(c == 'A' || c == 'B' || c == 'C'){
				return true;
			}
			else{
				return false;
			}
	    break;
		case '3':
	    	if(c == 'D' || c == 'E' || c == 'F'){
				return true;
			}
			else{
				return false;
			}
	    break;
		case '4':
	    	if(c == 'G' || c == 'H' || c == 'I'){
				return true;
			}
			else{
				return false;
			}
	    break;
		case '5':
	    	if(c == 'J' || c == 'K' || c == 'L'){
				return true;
			}
			else{
				return false;
			}
	    break;
		case '6':
	    	if(c == 'M' || c == 'N' || c == 'O'){
				return true;
			}
			else{
				return false;
			}
	    break;
		case '7':
	    	if(c == 'P' || c == 'R' || c == 'S'){
				return true;
			}
			else{
				return false;
			}
	    break;
		case '8':
	    	if(c == 'T' || c == 'U' || c == 'V'){
				return true;
			}
			else{
				return false;
			}
	    break;
		case '9':
	    	if(c == 'W' || c == 'X' || c == 'Y'){
				return true;
			}
			else{
				return false;
			}
	    break;
		default:
			return true;
	  }
}


bool valid(string str, vector<char> chars){
	int i;
	if (str.length() != chars.size()){
		return false;
	}
	for(i = 0; i < str.length() ; i++){
		if (valid_help(str.at(i), chars.at(i))){
			;
		}
		else{
			return false;
		}
	}
	return true;
}

int main() {
	ifstream fdict ("dict.txt");
	string name;
	set<string> names;
	while (fdict >> name)
	{
		names.insert(name);
	}
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    char c;
	vector<char> chars;
	while (fin >> c){
		chars.push_back(c);
	}
	int count = 0;
	for (set<string>::iterator i = names.begin(); i != names.end(); i++){
		if (valid(*i, chars)){
			fout << *i << endl;
			count += 1;
		}
	}
	if (count == 0){
		fout << "NONE" << endl;
	}
    return 0;
}








