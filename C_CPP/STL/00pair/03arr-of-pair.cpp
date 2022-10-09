#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};
    v.push_back(make_pair(7, 8));

    cout << v[0].first << " " << v[0].second << endl; // 1 2

    for (auto &p : v)
        cout << p.first << " " << p.second << endl;

	pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
	for(auto &p:arr)
		cout<<p.first<<" "<<p.second<<endl;

    return 0;
}