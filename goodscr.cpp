#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <string>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    int m=0;
    while(t--){
        int n,k;
        cin >> n >> k ;
        string str;
        cin >> str;
        int count=0;
        int i = 1;
        while(i<=ceil(n/2))
        {
            if(str[i-1]!=str[n-i])  count++;
            i++;
    }
        m++;
        if(count != k) cout << "Case #" << m << ": " << abs(count - k) <<endl;
        else cout <<"Case #" << m << ": " << "0" << endl;
}       

}