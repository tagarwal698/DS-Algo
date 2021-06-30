#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;


#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {

/*sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);*/

template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

struct debug {
	~debug() { cerr << endl; }
	
	//eni(!=) cerr << boolalpha << i; ris; }        Part 1
	
	template < class c > typename \
	enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
		cerr << boolalpha << i;
		return * this;
	}
	
	//eni(==) ris << range(begin(i), end(i)); }     Part 2
	
	template < class c > typename \
	enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
		return * this << range(begin(i), end(i)); 
	}
	
	/*sim, class b dor(pair < b, c > d) {           Part 3
		ris << "(" << d.first << ", " << d.second << ")";
	}*/
	
	template < class c, class b > debug & operator << (pair < b, c > d) {
		return * this << "(" << d.first << ", " << d.second << ")";
	}
	
	/*sim dor(rge<c> d) {                           Part 4
		*this << "[";
		for (auto it = d.b; it != d.e; ++it)
			*this << ", " + 2 * (it == d.b) << *it;
		ris << "]";
	}*/
	
	template < class c > debug & operator <<(rge<c> d) {
		*this << "[";
		for (auto it = d.b; it != d.e; ++it)
			*this << ", " + 2 * (it == d.b) << *it;
		return * this << "]";
	}
	
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "




void c_p_c(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
#endif
}

	void subarrtar(vector<int> arr, int k){
	int n = arr.size();
	int i = 0, j = 0;
	int sum = 0;
	int count = 0;
	while(j<arr.size()){
		sum = sum + arr[j];
		j++;
		cout << sum << endl;

		while(sum>k and i<j){
			sum = sum - arr[i];
			i++;
		}
	
		if(sum == k){ count++; }

		}
	}
	
	


int32_t main()
{
	c_p_c();
	vector <int> arr;
	int temp;
	int n;
	cin >> n;
	int k; cin >> k;
	for(int i = 0; i < n; i++){
		cin >> temp; arr.push_back(temp);
	}
	subarrtar(arr, k);
	// for(auto i : result)
	// 	cout << i.first << " " << i.second << endl;
	//cout << result << endl;

}
