int n;
vector<vector<int>> graph;
vector<bool> used;
vector<int> ans;

void dfs(int v) {
    used[v] = true;
    for (int u : graph[v]) {
        if (!used[u]){
            dfs(u);
        }
    }
    ans.push_back(v);
}

void topological_sort() {
    used.resize(n + 1);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!used[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}