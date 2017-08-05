#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void main() {
	vector<int> g;
	vector<int> s;
	g.push_back(1);
	g.push_back(2);
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);

	sort(g.begin(),g.end());
	sort(s.begin(),s.end());
	int glen = g.size();
	int slen = s.size();

	int gcount = 0;
	int scount = 0;
	int count = 0;
	
	while (gcount < glen && scount < slen) {
		
		if (g[gcount] <= s[scount]) {
			gcount++;
			scount++;
			count++;
		}
		else {
			scount++;
		}
	}
	cout << count;
}