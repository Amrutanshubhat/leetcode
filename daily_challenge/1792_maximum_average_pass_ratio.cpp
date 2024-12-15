class Solution {
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    priority_queue<pair<double, int>> q;

    for (size_t i = 0; i < classes.size(); i++) {
      double cur_avg = (double)classes[i][0] / classes[i][1];
      double updated_avg = (double)(classes[i][0] + 1) / (1 + classes[i][1]);
      q.emplace(make_pair(updated_avg - cur_avg, i));
    }
    while (extraStudents) {
      int i = q.top().second;
      q.pop();
      classes[i][0]++;
      classes[i][1]++;
      double cur_avg = (double)classes[i][0] / classes[i][1];
      double updated_avg = (double)(classes[i][0] + 1) / (1 + classes[i][1]);
      q.push(make_pair(updated_avg - cur_avg, i));
      extraStudents--;
    }
    double avg = 0;
    while (!q.empty()) {
      int i = q.top().second;
      q.pop();
      avg += (double)classes[i][0] / classes[i][1];
    }
    return avg / classes.size();
  }
};
