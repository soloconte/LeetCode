#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num = 0;

void drawSolution(vector<string> &ans, vector<int> &solution){
	int n = solution.size();
	ans.clear();
	for (auto pos : solution){
		string ts;
		ts.clear();
		int i = 0;
		while (i < pos){
			ts += '.';
			i++;
		}
		ts += 'Q';
		i++;
		while (i < n){
			ts += '.';
			i++;
		}
		ans.push_back(ts);
	}
}

bool validPos(int col, const vector<int> &solution){
	int n = solution.size();
	for (int i = 0; i < n; i++){
		if (col == solution[i]) return false;
		if ((col + n) == (solution[i] + i)) return false;
		if ((col - n) == (solution[i] - i)) return false;
	}
	return true;
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ans;
	ans.clear();
	vector<string> tmp;
	vector<int> solution;
	solution.clear();
	vector<int> st(n, 0);
	while (true)
	{
		int row = solution.size();
		if (row == n){
			num++;
			drawSolution(tmp, solution);
			ans.push_back(tmp);
			st[row - 1]++;
			solution.pop_back();
		}
		else{
			int col = st[row];
			while ((col < n) && (!validPos(col, solution))) col++;
			if (col == n){
				if (row == 0) break;
				else{
					st[row - 1]++;
					for (auto i = row; i < n; i++)
						st[i] = 0;
					solution.pop_back();
				}
			}
			else{
				st[row] = col;
				solution.push_back(col);
			}
		}
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	auto ans = solveNQueens(n);
	for (auto solution : ans){
		for (auto line : solution)
			cout << line << endl;
		cout << "--------------------------" << endl;
	}
	cout << num << endl;
	return 0;
}