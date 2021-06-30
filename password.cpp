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

    			string str, str1;
                long long i;
                cin >> str;
                if(str.size()==1) { cout<<str<<endl; return 0;}
                long long n = str.size();
                for ( i = 0; i < n; i++)
                {
                    if(compute_hash(str.substr(0,i+1))!=compute_hash(str.substr(n-1-i, i+1))) continue;
                    else{
                        if(i<n-1){
                        if(compute_hash(str.substr(0,i+2))==compute_hash(str.substr(n-i-2,i+2)))  continue;
                        else break;
                    }
                    }
                }


                for(long long j=i+1;j<n-1-i;j++) str1.push_back(str.at(j));   
                std::size_t found = str1.find(str.substr(0,i+1));
                if (found==std::string::npos){  
                    cout << "Just a legend" << endl;
                }
                else cout<<str.substr(0,i+1)<<endl;
            }        

