class Solution {
public:
  bool canBeValid(string s, string locked) {
    if (s.size() & 1)
      return false;

    deque<pair<char, int>> dq1, dq2;
    for (int i = 0; i < s.size(); i++) {
      if (locked[i] == '1') {
        dq2.push_back(make_pair(s[i], i));
      } else {
        dq1.push_back(make_pair(s[i], i));
      }
    }

    deque<pair<char, int>> dq3;
    while (!dq2.empty()) {
      char c = dq2.front().first;
      int i = dq2.front().second;
      dq2.pop_front();

      if (c == '(') {
        dq3.push_back(make_pair(c, i));
      } else {
        if (!dq3.empty()) {
          dq3.pop_back();
        } else if (!dq1.empty() && dq1.front().second < i) {
          dq1.pop_front();
        } else {
          return false;
        }
      }
    }
    while (!dq3.empty()) {
      if (!dq1.empty() && (dq1.back().second > dq3.back().second)) {
        dq1.pop_back();
        dq3.pop_back();
      } else {
        return false;
      }
    }
    return true;
  }
};
