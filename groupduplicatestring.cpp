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

    vector<vector<int>> group_identical_strings(vector <string> &s)
    {
        int n = s.size();
        vector <pair<long long, int>> hashes(n);
        for(int i=0; i<n; i++){
            hashes[i] = {compute_hash(s[i]),i};
        }
        sort(hashes.begin(), hashes.end());

        vector<vector<int>> groups;
        for(int i=0; i<n; i++){
            if(i==0|| hashes[i].first!=hashes[i-1].first)   groups.emplace_back();
                groups.back().push_back(hashes[i].second);
        }
        return groups;
    }

    int main()
    {
    	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
		#endif
            int m;
            cin>>m;
        	vector<string> p;
        for (int i = 0; i < m; i++)
        {   
            cin >> p[i];
        }
            vector<vector<int>> v = group_identical_strings(p);
            for (int i = 0; i < p.size(); i++)
            {
                for (int j = 0; j < p.size(); j++)
                cout << p[v[i][j]] << " " ;
                cout<<endl;
            }
    	
    	return 0;
    }