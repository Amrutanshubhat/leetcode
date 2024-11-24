class Solution {
public:
  bool canAliceWin(int n) {
    char turn = 'a';
    int next = 10;

    while (n >= next) {
      n -= next;
      next--;
      turn = turn == 'a' ? 'b' : 'a';
    }

    if (turn == 'a')
      return false;
    return true;
  }
};
