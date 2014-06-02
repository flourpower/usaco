/*
ID: odenaau1
PROG: packrec
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

bool by_volume(pair<int, int> x, pair<int, int> y){
	return (x.first * x.second) < (y.first * y.second);
}

bool by_first(pair<int, int> x, pair<int, int> y){
	return x.first < y.first;
}

int main() {
	ofstream fout ("packrec.out");
    	ifstream fin ("packrec.in");
	int i, w, l;  
	vector<pair <int, int> > recs;
    	for(i = 0; i < 4; i++){
		fin >> w >> l;
		recs.push_back(make_pair(w,l));
	}
	//begin debug
	for (i = 0; i < 4; i++){
		cout << recs[i].first << " "  << recs[i].second << endl;
	}
	//end debug
	//add solutions to this, we'll sort and prune later
	vector<pair <int,int> > solutions, tmp_sol;	
	//solutions.push_back(make_pair(100,100));//can remove this later
	//cout << solutions[0].first << " " << solutions[0].second << endl;
	//for each of 6 types
		//add solutions for that type
	//type 1
	int a,b,c,d;
	int best = 10000;
	int tmp = 10000;
	int w1, w2, w3, w4, l1, l2, l3, l4, w_best, l_best, l_max;
	for (a = 0; a < 2; a++){
		if (a == 0){
			w1 = recs[0].first;
			l1 = recs[0].second;
		}
		else {
			w1 = recs[0].second;
			l1 = recs[0].first;
		}
		for(b = 0; b < 2; b++){
			if (b == 0){
				w2 = recs[1].first;
				l2 = recs[1].second;
			}
			else{
				w2 = recs[1].second;
				l2 = recs[1].first;
			}
			for(c = 0; c < 2; c++){
				if (c == 0){
					w3 = recs[2].first;
					l3 = recs[2].second;
				}
				else {
					w3 = recs[2].second;
					l3 = recs[2].first;
				}
				for (d = 0; d < 2; d++){
					if (d == 0){
						w4 = recs[3].first;
						l4 = recs[3].second;
					}
					else{
						w4 = recs[3].second;
						l4 = recs[3].first;
					}
					int myints[] = {l1, l2, l3, l4};
					l_max = *max_element(myints, myints+7);
					tmp = (w1+w2+w3+w4)*l_max;
					if (tmp < best){
						best = tmp;
						w_best = w1+w2+w3+w4;
						l_best = l_max;
					}	
				}
			}
		}
	}
	solutions.push_back(make_pair(w_best, l_best));
	//sort solutions by product of elements
	sort(solutions.begin(), solutions.end(), by_volume);
	//cout << solutions[0].first << " " << solutions[0].second << endl;
	//get the product of the first solution
	int answer, len;
	answer = solutions[0].first * solutions[0].second;
	fout << answer << endl;;
	//delete all solutions with product more than this
	len = 0;
	while (solutions[len].first * solutions[len].second == answer){len++;}
	//sort solutions by first element	
	sort(solutions.begin(), solutions.end(), by_first);
	for(i = 0; i < len; i++){
		fout << solutions[i].first;
		fout << " ";
		fout << solutions[i].second;
		fout << endl;
	}
}








