class TaskManager {
  set<pair<int, int>, greater<pair<int, int>>> pt;
  unordered_map<int, pair<int, int>> ht;
  unordered_map<int, int> temp;

public:
  TaskManager(vector<vector<int>> &tasks) {
    for (const auto &task : tasks) {
      ht[task[1]] = make_pair(task[0], task[2]);
      pt.emplace(make_pair(task[2], task[1]));
    }
  }

  void add(int userId, int taskId, int priority) {
    ht[taskId] = make_pair(userId, priority);
    pt.emplace(make_pair(priority, taskId));
  }

  void edit(int taskId, int newPriority) { temp[taskId] = newPriority; }

  void rmv(int taskId) {
    int p = ht[taskId].second;
    temp.erase(taskId);
    ht.erase(taskId);
    pt.erase({p, taskId});
  }

  int execTop() {
    if (pt.empty())
      return -1;
    for (const auto &[t, p] : temp) {
      int temp_p = ht[t].second;
      ht[t].second = p;
      pt.erase({temp_p, t});
      pt.emplace(make_pair(p, t));
    }
    int out = pt.begin()->second;
    pt.erase(pt.begin());
    temp.clear();
    int user = ht[out].first;
    ht.erase(out);
    return user;
  }
};
