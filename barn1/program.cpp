/*
ID: odenaau1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout ("barn1.out");
    	ifstream fin ("barn1.in");
    	int boards, stalls, cows;
    	fin >> boards >> stalls >> cows;
	int i, tmp;
	vector<int> cow_vector, diff_vector;
	for (i = 0; i < cows; i++){
		fin >> tmp;
		cow_vector.push_back(tmp);
	}
	sort(cow_vector.begin(), cow_vector.end());
	for(i = 0; i < cows - 1; i++){
		diff_vector.push_back(cow_vector[i+1] - cow_vector[i] - 1);
	}
	sort(diff_vector.begin(), diff_vector.end());
	boards -= 1;
	i = cows - 2;
	int answer, front, back;
	answer = 0;
	while(boards > 0){
		answer += diff_vector[i];
		i--;
		boards--;
	}
	front = cow_vector[0] - 1;
	back = stalls - cow_vector[cows - 1];
	int print_me;
	print_me = stalls - (answer + front + back);
	if (i < 0)
		print_me = cows;
	fout << print_me << endl;
}








