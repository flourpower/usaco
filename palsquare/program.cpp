/*
ID: odenaau1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool palindrome(string str){
	int i;
	for(i = 0; i < str.length(); i++){
		if(str.at(i) != str.at(str.length() - i - 1))
			return false;
	}
	return true;
}

char to_chr(int n){
	if (n == 0)
		return '0';
	else if (n == 1)
		return '1';
	else if (n == 2)
		return '2';
	else if (n == 3)
		return '3';
	else if (n == 4)
		return '4';
	else if (n == 5)
		return '5';
	else if (n == 6)
		return '6';
	else if (n == 7)
		return '7';
	else if (n == 8)
		return '8';
	else if (n == 9)
		return '9';
	else if (n == 10)
		return 'A';
	else if (n == 11)
		return 'B';
	else if (n == 12)
		return 'C';
	else if (n == 13)
		return 'D';
	else if (n == 14)
		return 'E';
	else if (n == 15)
		return 'F';
	else if (n == 16)
		return 'G';
	else if (n == 17)
		return 'H';
	else if (n == 18)
		return 'I';
	else if (n == 19)
		return 'J';
	else if (n == 20)
		return 'K';
}

string base_b(int n, int base){
	string answer;
	string aux;
	while(n > 0){
		aux.push_back(to_chr(n % base));
		n = n / base;
	}
	for (string::reverse_iterator it = aux.rbegin(); it != aux.rend(); it++){
		answer.push_back(*it);
	}
	return answer;
}

int main() {
	int i;
	ofstream fout ("palsquare.out");
    	ifstream fin ("palsquare.in");
    	int base;
    	fin >> base;
	for (i = 1; i <= 300; i++){
		if (palindrome(base_b(i*i, base)))
			fout << base_b(i, base) << " " << base_b(i*i,base) << endl;
	}
	
}








