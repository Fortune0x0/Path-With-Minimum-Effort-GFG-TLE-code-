#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <set>'
#include <unordered_set>
using namespace std;

class Solution {

public:
	int MinimumEffort(int rows, int columns, vector<vector<int>>& heights) {
		queue<pair<pair<int, int>,pair<vector<pair<int, int>>, vector<int>>>> q;

		int n = heights.size();
		int m = heights[0].size();

		q.push({ {0, 0}, {} });

		int ans = 1e9;
		while (!q.empty()) {
			int row = q.front().first.first;
			int col = q.front().first.second;
			vector<int> vec = q.front().second.second;
			vector<pair<int, int>> my_pair = q.front().second.first;
			my_pair.push_back({ row, col });

			q.pop();

			
			
			vector<pair<int, int>> list = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };


			for (auto a : list) {
				int nrow = row + a.first;
				int ncol = col + a.second;

				pair<int, int> p = { nrow, ncol };
				if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && find(my_pair.begin(), my_pair.end(), p) == my_pair.end()) {
					
					

					int x_path = min(heights[row][col], heights[nrow][ncol]);
					int y_path = max(heights[row][col], heights[nrow][ncol]);

					vec.push_back(y_path - x_path);
					if (nrow == n-1 && ncol == m -1) {
						int max_num = *max_element(vec.begin(), vec.end());
						if (max_num < ans) {
							ans = max_num;
						}
					}
					else {
						q.push({ {nrow, ncol},{ my_pair, vec} });
					}
					
					vec.pop_back();
				}
			}
		}

		return ans;
	}
};





int main() {
	Solution solu;
	vector<vector<int>> vec = {
			{1, 2, 2},
			{3, 8, 2},
			{5, 3, 5}};

	vector<vector<int>> vec_2 = {
		{7, 2, 6, 5},
		{3, 1, 10, 8}};
	int ans = solu.MinimumEffort(3, 3, vec);
	cout << ans << endl;

	


	
}