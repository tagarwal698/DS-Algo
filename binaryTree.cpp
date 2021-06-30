//All major operations on binary trees
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
template < class c > rge<c> range(c i, c j) { return rge<c> {i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

struct debug {
	~debug() { cerr << endl; }

	//eni(!=) cerr << boolalpha << i; ris; }        Part 1

	template < class c > typename \
	enable_if < sizeof dud<c>(0) != 1, debug& >::type operator<<(c i) {
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


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class node {
public:
	int data;
	node * left;
	node * right;

	node(int data) {
		this->data = data;
		right = NULL;
		left = NULL;
	}
};

node* buildtree() {
	int d;
	cin >> d;

	if (d == -1) return NULL;

	node *n = new node(d);
	n->left = buildtree();
	n->right = buildtree();

	return n;
}

node* levelorderbuild() {
	int d;
	cin >> d;

	node * root = new node(d);
	queue<node*> arr;
	arr.push(root);
	while (!arr.empty()) {
		node * temp = arr.front();
		arr.pop();
		int c1; cin >> c1;
		int c2; cin >> c2;
		if (c1 != -1) {
			temp->left = new node(c1);
			arr.push(temp->left);
		}
		// else
		// 	temp -> left = NULL;
		if (c2 != -1) {
			temp->right = new node(c2);
			arr.push(temp->right);
		}
		// else
		// 	temp->right = NULL;
	}
	return root;


}

void levelordertraversal(node*root) {
	// queue<node*> arr;
	// arr.push(root);
	// arr.push(NULL);

	// while (!arr.empty()) {
	// 	node* temp = arr.front();
	// 	if (temp == NULL) {
	// 		cout << endl;
	// 		arr.pop();
	// 		if (!arr.empty())
	// 			arr.push(NULL);
	// 	}
	// 	else {
	// 		arr.pop();
	// 		cout << temp->data << " ";
	// 		if (temp->left)	arr.push(temp->left);
	// 		if (temp->right)	arr.push(temp->right);
	// 	}
	// }
	// return;

	queue<node*> arr;
	arr.push(root);
	arr.push(NULL);
	while (!arr.empty()) {
		node * temp = arr.front();
		if (temp == NULL) {
			cout << endl;
			arr.pop();
			if (!arr.empty()) {
				arr.push(NULL);
			}
		}
		else {
			arr.pop();
			cout << temp->data << " ";
			if (temp->left) arr.push(temp->left);
			if (temp->right) arr.push(temp->right);
		}
	}
	return;
}

int height(node * root) {
	if (root == NULL)
		return 0;
	int h1 = height(root->left);
	int h2 = height(root->right);
	return 1 + max(h1, h2);
}

int diameter(node * root) { //O(n^2)
	if (root == NULL)
		return 0;

	int d1 = height(root->left) + height(root->right); // for diameter passing from the root node
	int d2 = diameter(root->left); 	//for diameter passing from the left subtree
	int d3 = diameter(root->right); // for diameter passing from the right subtree
	return max(d1, max(d2, d3));
}

class hdpair {
public:
	int height;
	int diameter;
};

hdpair optimisedDiameter(node * root) {
	hdpair p;
	if (root == NULL) {
		p.height = p.diameter = 0;
		return p;
	}
	hdpair left = optimisedDiameter(root->left);
	hdpair right = optimisedDiameter(root->right);

	p.height = max(left.height , right.height) + 1;

	int d1 = left.height + right.height;
	int d2 = left.diameter;
	int d3 = right.diameter;
	p.diameter = max(d1, max(d2, d3));
	return p;

}

int replaceSum(node * root) {
	if (root == NULL) return 0;
	if (root->left == NULL and	root->right == NULL) {
		return	root->data;
	}

	int lts = replaceSum(root->left);
	int rts = replaceSum(root->right);
	int temp = root->data;
	root->data = lts + rts;
	return temp + root->data;
}


// class bpair {
// public:
// 	int height;
// 	bool balance;
// };

// bpair heightbalanced(node*root) {
// 	bpair arr;

// 	if (root == NULL) {
// 		arr.height = 0;
// 		arr.balance = true;
// 		return arr;
// 	}

// 	bpair left = heightbalanced(root->left);
// 	bpair right = heightbalanced(root->right);

// 	arr.height = max(left.height, right.height) + 1;

// 	if (abs(left.height - right.height) <= 1 and (left.balance and right.balance))
// 		arr.balance = true;
// 	else
// 		arr.balance = false;

// 	return arr;
// }

pair<int, bool> heightbalanced(node * root) {
	pair<int, bool> arr, left, right;

	if (root == NULL) {
		arr.first = 0;
		arr.second = true;
		return arr;
	}


	left = heightbalanced(root->left);
	right = heightbalanced(root->right);

	int height = max(left.first, right.first) + 1;

	if (abs(left.first - right.first) <= 1 and left.second and right.second)
		return make_pair(height, true);
	return make_pair(height, false);

}


int32_t main()
{
	c_p_c();
	node* root = levelorderbuild();
	levelordertraversal(root);
	cout << endl;
	// replaceSum(root);
	// levelordertraversal(root);
	// pair<int, bool> p = heightbalanced(root);
	// if (p.second)
	// 	cout << "true" << endl;
	// else
	// 	cout << "false" << endl;

	// cout << optimisedDiameter(root).diameter << endl;
}
