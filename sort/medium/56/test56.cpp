#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) :start(s), end(e) {}
};
static int Comstart(Interval r1, Interval r2);
vector<Interval> Compare(vector<Interval>& intervals);
void main() {
	vector<Interval> intervals = {};
	Interval inter1(1,3);
	Interval inter2(2,6);
	//Interval inter4(8,10);
//	Interval inter3(15,18);
	intervals.push_back(inter1);
	intervals.push_back(inter2);
//	intervals.push_back(inter3);
//	intervals.push_back(inter4);
	//Interval in = intervals[0];
	//cout << in.start << "," << in.end;
	vector<Interval> result = Compare(intervals);
	for (int i = 0;i < result.size();i++) {
		Interval res = result[i];
		cout << res.start << "," << res.end;
	}
}
vector<Interval> Compare(vector<Interval>& intervals) {
	vector<Interval> result;
	Interval curr;
	sort(intervals.begin(), intervals.end(),Comstart);
	if (intervals.size() <= 1) {
		result.push_back(intervals[0]);
		return result;
	}
	curr = intervals[0];
	int length = intervals.size();
	for (int i = 1;i < intervals.size();i++) {
		if (curr.end < intervals[i].start) {
			result.push_back(curr);
			curr = intervals[i];
		}
		else {
			int maxend = max(curr.end,intervals[i].end);
			curr.end = maxend;
		}
		//if (curr.start == intervals[length - 1].start)
			
	}
	result.push_back(curr);
	return result;
}
static int Comstart(Interval r1,Interval r2) {
	return r1.start < r2.start;
}