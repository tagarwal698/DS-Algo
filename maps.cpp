#include <iostream>
#include <map> // ordered maps. They use binary search tree.
#include <unordered_map> // unordered maps. They use hashing.

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	map<int, float> mp;
	mp[7] = 3.0;
	mp[1] = 4.2;
	mp[6] = 7.8;
	unordered_map<int, int> ump;
	ump[2] = 2;
	ump[9] = 7;
	ump[3] = 16;
	mp.insert({2,3.4});
	if(mp.find(2) == mp.end()) cout << "Not Found" << endl;
	else cout<<"Found" << endl;
	cout<<mp[7]<<endl;
	// looping over a map
	for(auto it = mp.begin(); it!=mp.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}