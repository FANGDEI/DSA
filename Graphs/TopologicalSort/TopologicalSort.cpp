int inDeg[N];
queue<int> q;
vector<int> v[M], ans;
void topSort() {
    for (int i=1; i<=n; i++) {
        if (!inDeg[i]) q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans.push_back(now); // 拓扑序列
        for (int i=0; i<v[now].size(); i++) {
            if (--inDeg[v[now][i]] == 0) q.push(v[now][i]);
        }
    }
}