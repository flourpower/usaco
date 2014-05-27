/*
ID: odenaau1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

int main() {
	ofstream fout ("milk.out");
    	ifstream fin ("milk.in");
    	int total_milk, farmer_count;
    	fin >> total_milk >> farmer_count;
	int i, px, qty;
	vector< pair<int,int>  > market;
	for (i = 0; i < farmer_count; i++){
		fin >> px >> qty;
		market.push_back(make_pair(px, qty));
	}
	sort(market.begin(), market.end(), cmp);
	int total_cost = 0;
	i = 0;
	while(total_milk > 0){
		if (market[i].second >= total_milk){
			total_cost += total_milk * market[i].first;
			total_milk = 0;	
		}	
		else{
			total_cost += market[i].first * market[i].second;
			total_milk -= market[i].second;
		}
		i++;
	}
	fout << total_cost << endl;;
}








