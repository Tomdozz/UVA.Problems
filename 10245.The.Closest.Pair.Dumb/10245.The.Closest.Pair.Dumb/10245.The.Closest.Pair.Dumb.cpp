// 10245.The.Closest.Pair.Dumb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long double lag;
typedef pair<lag, lag> Point;
lag Dist(const Point& a, const Point& b) {
	lag x = a.first - b.first, y = a.second - b.second;
	return x*x + y*y;
}
int main() {
	cout.precision(4);
	cout << fixed;
	unsigned n;
	lag dist;
	Point x[10005];
	while (cin >> n, n) {
		dist = 100000001.0;
		for (unsigned i = 0; i<n; i++)
			cin >> x[i].first >> x[i].second;
		for (unsigned i = 0; i<n; i++) {
			for (unsigned j = i + 1; j<n; j++) {
				dist = min(dist, Dist(x[i], x[j]));
			}
		}
		if (dist == 100000001.0) cout << "INFINITY" << endl;
		else cout << sqrt(dist) << endl;
	}
}

