#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int q;
map<int, vector<string>> maps;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	maps[1967].push_back("DavidBowie");
	maps[1969].push_back("SpaceOddity");
	maps[1970].push_back("TheManWhoSoldTheWorld");
	maps[1971].push_back("HunkyDory");
	maps[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	maps[1973].push_back("AladdinSane");
	maps[1973].push_back("PinUps");
	maps[1974].push_back("DiamondDogs");
	maps[1975].push_back("YoungAmericans");
	maps[1976].push_back("StationToStation");
	maps[1977].push_back("Low");
	maps[1977].push_back("Heroes");
	maps[1979].push_back("Lodger");
	maps[1980].push_back("ScaryMonstersAndSuperCreeps");
	maps[1983].push_back("LetsDance");
	maps[1984].push_back("Tonight");
	maps[1987].push_back("NeverLetMeDown");
	maps[1993].push_back("BlackTieWhiteNoise");
	maps[1995].push_back("1.Outside");
	maps[1997].push_back("Earthling");
	maps[1999].push_back("Hours");
	maps[2002].push_back("Heathen");
	maps[2003].push_back("Reality");
	maps[2013].push_back("TheNextDay");
	maps[2016].push_back("BlackStar");
	//input
	cin >> q;
	//solve
	while (q--) {
		int s, e;
		cin >> s >> e;
		vector<pair<int,string>> output;
		int cnt = 0;
		for (int i = s; i <= e; i++) {
			for (int j = 0; j < maps[i].size(); j++) {
				cnt += 1;
				output.push_back({ i, maps[i][j] });
			}
		}
		cout << cnt << '\n';
		for (int i = 0; i < output.size(); i++) {
			cout << output[i].first << ' ' << output[i].second << '\n';
		}
	}
}