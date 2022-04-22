#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <list>
#include <stack>
#include <cstdlib>

using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end() 
#define reverse(v) reverse(all(v)) 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;

//start
int a[100005];
int n, k, x;
void solve(int x) {
	int l = -1;
	int r = n;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (a[mid] < x)
			l = mid;
		else
			r = mid;
	}
	if (r < n && a[r] == x)
		cout << "YES\n";
	else
		cout << "NO\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//start int main

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (k--) {
		cin >> x;
		solve(x);
	}
}