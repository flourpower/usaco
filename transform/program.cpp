/*
ID: odenaau1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
Read in the size of the square
Read the first square into an array
read the second square into an array
call a series of transforms and compare with the other square
*/


using namespace std;


void print_matrix(vector<vector <char> > a1, int size);
void copy(vector<vector <char> > &a1, vector<vector <char> > &a2, int size);

//see if 2 squares are the same
bool same(vector<vector <char> > a1, vector<vector <char> > a2, int size){
	int i, j;
	int answer = 1;
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			if (a1[i][j] != a2[i][j])
				answer *= 0;
		}
	}
	return answer;
}


void transpose(vector<vector <char> > &a1, int size){
	int i,j;
	vector<vector <char> > a2(size, vector <char>(size));
	copy(a1, a2, size);
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			a1[i][j] = a2[j][i];
		}
	}
}

void reflect_horizontal(vector<vector <char> > &a1, int size){
	int i,j;
	vector<vector <char> > a2(size, vector <char>(size));
	copy(a1, a2, size);
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			//cout << i << " " << j << endl;
			a1[i][j] = a2[i][size - j - 1];
			//cout << a1[i][j] << endl;
		}
	}
}

void copy(vector<vector <char> > &a1, vector<vector <char> > &a2, int size){
	int i,j;
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			a2[i][j] = a1[i][j];
		}
	}
}


bool ninety(vector<vector <char> > a1, vector<vector <char> > a2, int size){
	vector<vector <char> > a3(size, vector <char>(size));
	copy(a1, a3, size);
	transpose(a3, size);
	//print_matrix(a3, size);
	reflect_horizontal(a3, size);// this and last rotate 90
	//print_matrix(a3,size);
	return same(a3, a2, size);
}

bool one_eighty(vector<vector <char> > a1, vector<vector <char> > a2, int size){
	vector<vector <char> > a3(size, vector <char>(size));
	copy(a1, a3, size);
	transpose(a3, size);
	reflect_horizontal(a3, size);
	transpose(a3, size);
	reflect_horizontal(a3, size);
	return same(a3, a2, size);
}

bool two_seventy(vector<vector <char> > a1, vector<vector <char> > a2, int size){
	vector<vector <char> > a3(size, vector <char>(size));
	copy(a1, a3, size);
	transpose(a3, size);
	reflect_horizontal(a3, size);
	transpose(a3, size);
	reflect_horizontal(a3, size);
	transpose(a3, size);
	reflect_horizontal(a3, size);
	return same(a3, a2, size);
}

void print_matrix(vector<vector <char> > a1, int size){
	int i,j;
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			cout << a1[i][j];
		}
		cout << endl;
	}
}

int main() {
	ofstream fout ("transform.out");
    	ifstream fin ("transform.in");
    	int size, i = 0, j = 0;
    	fin >> size;
	vector<vector <char> > a1(size, vector <char>(size));
	vector<vector <char> > a2(size, vector <char>(size));
	vector<vector <char> > a3(size, vector <char>(size));
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			fin >> a1[i][j];
		}
	}
 	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			fin >> a2[i][j];
		}
	}   	
	//cout << "same: " << same(a1, a2, size) << endl;;
	//cout << "the size is: " << size << endl;
	copy(a1, a3, size);
	reflect_horizontal(a3, size);
	if (ninety(a1, a2, size))
		fout << 1 << endl;
	else if(one_eighty(a1, a2, size))
		fout << 2 << endl;
	else if(two_seventy(a1, a2, size))
		fout << 3 << endl;
	else if(same (a3,a2, size) )
		fout << 4 << endl;
	else if( ninety(a3, a2, size) || one_eighty(a3, a2, size) || two_seventy(a3, a2, size))
		fout << 5 << endl;
	else if (same(a1, a2, size))
		fout << 6 << endl;
	else 
		fout << 7 << endl;
    	return 0;
}








