#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(), v.end() 
#define sort(v) sort(ALL(v)) 
#define reverse(v) reverse(ALL(v)) 

typedef long long ll;
typedef vector<int> vi;

//start
int w[3005];
int dp[10005][305];
int main()
{
	int s, n;
	cin >> s >> n; s++; n++;
	
	for (int i = 1; i < n; i++)
		cin >> w[i];

	for (int i = 0; i < n; i++)
		dp[0][i] = 0;
	for (int i = 0; i < s; i++)
		dp[i][0] = 0;


	for (int i = 1; i < s; i++) {

		for (int j = 1; j < n; j++) {
			if (i - w[j] >= 0)
				dp[i][j] = max(dp[i][j - 1], dp[i - w[j]][j - 1] + w[j]);
			else
				dp[i][j] = dp[i][j - 1];
		}
	}

	/*for (int i = 0; i < s; i++) {
		for (int j = 0; j < n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/

	cout << dp[s - 1][n - 1];



}