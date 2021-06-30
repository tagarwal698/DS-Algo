#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


    long long compute_hash(string const& s){
    	const int p = 31;
    	const int m = 1e9 + 9;
    	long long hash_value = 0;
    	long long p_pow = 1;
    	for(char c : s){
    		hash_value = (hash_value + (c-'a'+1)*p_pow)%m;
    		p_pow = (p_pow * p) % m;
    	}
    	return hash_value;
    }

    int main()
    {
    	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
		#endif

    	string str;
    	cin >> str;
    	cout << compute_hash(str) << endl;
    	return 0;
    }