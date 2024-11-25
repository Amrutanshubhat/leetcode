class Solution {
  unordered_map<string, int> ht;
  queue<pair<string, int>> q;

public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string target = "123450";
    string s;

    for (size_t i = 0; i < board.size(); i++)
      for (size_t j = 0; j < board[0].size(); j++)
        s.push_back(board[i][j] + '0');

    q.push(make_pair(s, 0));
    ht[s] = 0;

    while (!q.empty()) {
      string x = q.front().first;
      int cnt = q.front().second;
      q.pop();
      int idx = x.find('0');
      switch (idx % 3) {
      case 0: {
        // right swap
        ht_insert(x, idx, idx + 1, cnt);
        break;
      }
      case 1: {
        // right
        ht_insert(x, idx, idx + 1, cnt);

        // left
        ht_insert(x, idx, idx - 1, cnt);
        break;
      }

      case 2: {
        // left swap
        ht_insert(x, idx, idx - 1, cnt);
        break;
      }
      }
      // up or down
      int y = (idx / 3) == 0 ? 3 + (idx % 3) : idx % 3;
      ht_insert(x, idx, y, cnt);
    }
    return ht.find(target) == ht.end() ? -1 : ht[target];
  }

private:
  void swap(string &s, int x, int y) {
    char c = s[x];
    s[x] = s[y];
    s[y] = c;
  }
  void ht_insert(string &s, int x, int y, int cnt) {
    swap(s, x, y);
    if ((ht.find(s) == ht.end()) || ht[s] > cnt + 1) {
      q.push({s, cnt + 1});
      ht[s] = cnt + 1;
    }
    swap(s, x, y);
  }
};
