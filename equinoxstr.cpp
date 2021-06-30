#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

    int main()
    {
    	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
		#endif

		int t;
		cin >> t;
		while(t--){
		    int n, a, b;
		    cin >> n >> a >> b;
		    vector <string> s;
		    for(int i = 0; i<n; i++) {
                string s1;
                cin >> s1;
                s.push_back(s1);
		    }
		    int sa=0, anu=0;
		    
		    for(int i = 0; i<n;i++){
		         if(s[i].at(0) == 'E'||s[i].at(0) == 'Q'||s[i].at(0) == 'U'||s[i].at(0) == 'I'||s[i].at(0) == 'N'||s[i].at(0) == 'O'||s[i].at(0) == 'X')
		            sa = sa+a;
		         else anu = anu+b;
		    }
		    if(sa>anu)   cout << "SARTHAK" << endl;
		    else if(sa<anu) cout << "ANURADHA" << endl;
		    else cout << "DRAW" << endl;
		}
    }