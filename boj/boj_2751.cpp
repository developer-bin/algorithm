#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n;
int a[1000001];
int tmp_a[1000001];

void quick_sort(int s, int e) {
	if (s >= e)return;
	int pivot = a[s];
	int i = s + 1;
	int j = e;
	while (i <= j) {
		while (i <= e && a[i] <= pivot)i++;
		while (j >= s + 1 && a[j] >= pivot)j--;
		if (i > j) {
			swap(a[s], a[j]);
		}
		else {
			swap(a[i], a[j]);
		}
	}
	quick_sort(s, j-1);
	quick_sort(j + 1, e);
}
void merge(int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;
	while (i <= mid && j <= e) {
		if (a[i] <= a[j]) {
			tmp_a[k++] = a[i++];
		}
		else {
			tmp_a[k++] = a[j++];
		}
	}
	while (i <= mid)tmp_a[k++] = a[i++];
	while (j <= e)tmp_a[k++] = a[j++];
	for (int i = s; i <= e; i++) {
		a[i] = tmp_a[i];
	}
}
void merge_sort(int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		merge_sort(s, mid);
		merge_sort(mid + 1, e);
		merge(s, e);
	}
}
int main() {
	//init
	//input

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//solve
	merge_sort(0, n-1);
	//print
	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
}