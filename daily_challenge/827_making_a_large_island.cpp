class Solution {
  struct Cord {
    int r;
    int c;
  };
  vector<int> root;
  vector<int> members;

public:
  int largestIsland(vector<vector<int>> &grid) {
    const int n = grid.size(), elements = n * n;
    root.resize(elements);
    members.resize(elements, 1);

    for (int i = 0; i < elements; i++)
      root[i] = i;

    vector<Cord> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<bool> v(elements);
    queue<Cord> q;
    // fill union set
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!grid[i][j])
          continue;
        q.push({i, j});
        int idx = i * n + j;
        while (!q.empty()) {
          int r = q.front().r;
          int c = q.front().c;
          q.pop();
          int temp_idx = r * n + c;
          if (v[temp_idx])
            continue;
          v[temp_idx] = true;
          insert(idx, temp_idx);
          for (const auto &d : directions) {
            int row = d.r + r, col = d.c + c;
            if (row >= 0 && col >= 0 && row < n && col < n && grid[row][col])
              q.push({row, col});
          }
        }
      }
    }
    // try merging union sets if they are 1 distance apart
    int out = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int idx = i * n + j;
        if (grid[i][j]) {
          out = max(members[findRoot(idx)], out);
          continue;
        }
        int cnt = 1;
        unordered_set<int> visit;
        for (const auto &d : directions) {
          int row = d.r + i, col = d.c + j;
          if (row >= 0 && col >= 0 && row < n && col < n && grid[row][col]) {
            int rt = findRoot(row * n + col);
            if (visit.find(rt) == visit.end()) {
              cnt += members[rt];
              visit.insert(rt);
            }
          }
        }
        if (cnt > out)
          out = cnt;
      }
    }
    return out;
  }

private:
  int findRoot(int a) {
    int r = root[a];
    while (r != root[r])
      r = root[r];
    return r;
  }
  void insert(int a, int b) {
    int r1 = findRoot(a);
    int r2 = findRoot(b);

    if (r1 == r2)
      return;

    if (members[r1] < members[r2])
      swap(r1, r2);

    members[r1] += members[r2];
    root[r2] = r1;
  }
};
