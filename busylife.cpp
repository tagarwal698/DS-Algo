#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ff 					first
#define ss 					second
#define int 				long long
#define ll					long long int
#define pb 					push_back
#define mp 					make_pair
#define pii					pair<int,int>
#define vi					vector<int>
#define mii					map<int,int>
#define pqb					priority_queue<int>
#define pqs					priority_queue<int,vi,greater<int>>
#define setbits(x)			__builtin_popcountll(x) //number of setbits
#define zrobits(x)			__builtin_ctzll(x) //number of zeros before 1 from the right
#define mod					1000000007
#define inf					1e18
#define ps(x,y)				fixed<<setprecision(y)<<x //converts x upto y decimal places
#define mk(arr,n,type)		type *arr=new type[n];
#define w(t)				int t; cin>>t; while(t--)
mt19937						rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(arr,arr+n,rng)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
#endif
}

int busylife(vector <pair<int, int>> arr){

	int n = arr.size();
	sort(arr.begin(),arr.end());
	int count = 1;
	for (int i = 0; i <=n-2; ++i)
	{
		if(arr[i].second<arr[i+1].first)	count++;
		if(count==3)	break;
	}
	return count;

}

int32_t main()
{
	c_p_c();
	int n;
	cin >> n;
	vector <pair <int, int>> arr(n);
	int m, k;
	for (int i = 0; i < n; ++i)
	{
		cin >> m; cin >> k; arr.push_back(make_pair(m,n));
	}

		for (int i = 0; i < n; ++i)
	{
		cout << arr[i].first << " " << arr[i].second << endl;
	}
	auto result = busylife(arr);
	cout << result << endl;

}