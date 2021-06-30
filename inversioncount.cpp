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

int merge(vector <int> &arr, int s, int e){
	int i = s; 
	int mid = (s+e)/2;
	int j = mid+1;
	int count = 0;
	vector <int> temp;
	while(i<=mid and j<=e){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i++]);
		}
		else{ temp.push_back(arr[j++]); count += (mid - i + 1);}
	}

	while(i<=mid)	temp.push_back(arr[i++]);
	while(j<=e)	temp.push_back(arr[j++]);
	int k=0;
	for(int i = s; i<=e; i++)	arr[i] = temp[k++];
		return count;

}

int invcnt(vector <int> &arr, int s, int e){
	if(s>=e)	return 0;
	int mid = (s+e)/2;
	int c1 = invcnt(arr,s,mid);
	int c2 = invcnt(arr,mid+1,e);
	int ci = merge(arr, s, e);
	return c1+c2+ci;
}

int32_t main()
{
	c_p_c();
	int n;
	cin>>n;
	vector <int> arr;
	int temp;
	for(int i=0; i<n; i++)	{
		cin >> temp;
		arr.push_back(temp);
	}
	int s = 0;
	int e = n-1;
    cout << invcnt(arr, s ,e)<< endl;

}