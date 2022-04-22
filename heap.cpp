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

vi A;
int heap_size = 0;

void heapify_down() {
	int i = 1;
	while (2 * i <= heap_size) {
		int left = 2 * i;
		int right = 2 * i + 1;
		int j = left;
		if (right <= heap_size && A[right] > A[left])
			j = right;
		if (A[i] >= A[j])
			break;
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i = j;
	}
}

void add_new(int n) {
	heap_size++;
	A.push_back(n);
	int pos = heap_size;
	while (pos > 1) {
		if (A[pos / 2] >= A[pos])
			break;
		int temp = A[pos];
		A[pos] = A[pos / 2];
		A[pos / 2] = temp;
		pos /= 2;
	}
}

int get_max() {
	int maximum = A[1];
	A[1] = A[heap_size];
	A.pop_back();
	heap_size--;
	heapify_down();
	return maximum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	A.push_back(0);
	while (t--) {
		bool w;
		cin >> w;
		if (w == 0) {
			int n;
			cin >> n;
			add_new(n);
		}
		else {
			cout << get_max() << '\n';
		}
	}


}