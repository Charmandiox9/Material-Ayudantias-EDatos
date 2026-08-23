#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int rottenApples(vector<vector<int>> mtx) {
    int n = mtx.size();
    int m = mtx[0].size();

    queue<pair<int,int>> q;
    int freshCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mtx[i][j] == 2) {
                q.push({i, j});
            } else if (mtx[i][j] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) return 0;

    int minutes = 0;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    while (!q.empty()) {
        int levelSize = q.size();
        bool rottedSomething = false;

        for (int k = 0; k < levelSize; k++) {
            pair<int,int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    freshCount--;
                    q.push({nx, ny});
                    rottedSomething = true;
                }
            }
        }

        if (rottedSomething) minutes++;
    }

    return freshCount == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> mtx1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << "Resultado 1: " << rottenApples(grid1) << endl;

    vector<vector<int>> mtx2 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 2}
    };
    cout << "Resultado 2: " << rottenApples(grid2) << endl;

    vector<vector<int>> mtx3 = {
        {0, 2}
    };
    cout << "Resultado 3: " << rottenApples(grid3) << endl;

    return 0;
}