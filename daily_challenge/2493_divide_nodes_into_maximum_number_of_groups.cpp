class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n+1);
        vector<int> p(n+1, -1), d(n+1, 0);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            Union(edge[0], edge[1], p, d);
        }
        unordered_map<int, int> group;
        for (int i = 1; i <= n; i++) {
            int cnt = get_group_cnt(adj, i, n);
            if (cnt == -1) return -1;
            int root = find(i, p);
            group[root] = max(group[root], cnt);
        }

        int tot = 0;
        for (auto [node, cnt] : group) {
            tot += cnt;
        }
        return tot;
    }

private:
    int find(int x, vector<int> &p) {
        while (p[x] != -1) x = p[x];
        return x;
    }

    void Union(int a, int b, vector<int> &p, vector<int> &d) {
        a = find(a, p), b = find(b, p);
        if (a == b) return;
        if (d[a] < d[b]) swap(a, b);
        p[b] = a;
        if (d[a] == d[b]) d[a]++;
    }

    int get_group_cnt(vector<vector<int>> &adj, int node, int n) {
        queue<int> q;
        vector<int> visit(n+1, -1);
        q.push(node);
        visit[node] = 0;
        int max_h = 0;

        while (!q.empty()) {
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                int cur = q.front();
                q.pop();
                for (const auto&nbr: adj[cur]) {
                    if (visit[nbr] == -1) {
                        visit[nbr] = max_h + 1;
                        q.push(nbr);
                    } else {
                        if (visit[nbr] == max_h) {
                            return -1;
                        }
                    }
                }
            }
            max_h++;
        }
        return max_h;
    }
};
