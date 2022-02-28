#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#define ll long long
#define MAX_VALUE 200000000
#define MIN_VALUE 200000000
using namespace std;

struct node {
	bool valid;
	int child[10];
	node() {
		valid = false;
		for (int i = 0; i < 10; i++) {
			child[i] = -1;
		}
	}
};
vector<node> trie;
int create_node() {
	node node;
	trie.push_back(node);
	return (int)trie.size() - 1;
}
void trie_add(int trie_idx, string& s, int s_idx) {
	if (s.length() == s_idx) {
		trie[trie_idx].valid = true;
		return;
	}
	if (trie[trie_idx].child[s[s_idx] - '0'] == -1) {
		int new_node_idx = create_node();
		trie[trie_idx].child[s[s_idx] - '0'] = new_node_idx;
		trie_add(new_node_idx,s,s_idx+1);
	}
	else {
		trie_add(trie[trie_idx].child[s[s_idx] - '0'], s, s_idx + 1);
	}
}
bool checking(int trie_idx) {
	for (int i = 0; i < 10; i++) {
		if (trie[trie_idx].child[i] != -1) {
			if (trie[trie_idx].valid) {
				//½ÇÆÐ
				return false;
			}
			else {
				if (checking(trie[trie_idx].child[i]) == false) {
					return false;
				}
			}
		}
	}
	return true;
}
int t;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	cin >> t;
	while (t--) {
		//init
		trie.clear();
		int root_idx = create_node();
		cin >> n;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			trie_add(root_idx, s, 0);
		}
		if (checking(root_idx))cout << "YES\n";
		else cout << "NO\n";
	}
}