#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ff 					first
#define ss 					second
#define int 					long long
#define ll					long long int
#define pb 					push_back
#define mp 					make_pair
#define pii					pair<int,int>
#define vi					vector<int>
#define mii					map<int,int>
#define pqb					priority_queue<int>
#define pqs					priority_queue<int,vi,greater<int>>
#define setbits(x)				__builtin_popcountll(x) //number of setbits
#define zrobits(x)				__builtin_ctzll(x) //number of zeros before 1 from the right
#define mod					1000000007
#define inf					1e18
#define ps(x,y)					fixed<<setprecision(y)<<x //converts x upto y decimal places
#define mk(arr,n,type)				type *arr=new type[n];
#define w(t)					int t; cin>>t; while(t--)
mt19937						rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(arr,arr+n,rng)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

pair <int, int> minimumdiff(vector <int> a, vector <int> b) {
	pair <int, int> result;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int min = abs(a[0] - b[0]);
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (abs(a[i] - b[j]) <= min) {
			result.first = a[i];
			result.second = b[j];
			min = abs(a[i] - b[j]);
		}
		if ((a[i] - b[j]) < 0)	i++;
		else j++;
	}
	return result;
}

int32_t main() {
	c_p_c();
	vector <int> a;
	vector <int> b;
	int m;
	int n1, n2;
	cin >> n1;
	cin >> n2;
	for (int i = 0; i < n1; i++) int m; cin >> m; a.push_back(m);
	for (int i = 0; i < n2; i++) int m;	cin >> m; b.push_back(m);
	auto result = minimumdiff(a, b);
	cout << result.first << " " << result.second;
}

