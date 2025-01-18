struct Lowest_Common_Ancestor
{
    vector<vector<int>> LCA;
    vector<int> Degree;

    void dfs(int u, int p)
    {
        LCA[u][0] = p;
        for (auto &x : graph[u])
        {
            if (x != p)
            {
                Degree[x] = Degree[u] + 1;
                dfs(x, u);
            }
        }
    }

    Lowest_Common_Ancestor()
    {
        LCA.clear();
        Degree.clear();
        LCA.resize(graph.size(), vector<int>((int)(log2(graph.size())) + 1));
        Degree.resize(graph.size(), 1);

        dfs(1, -1);

        for (int j = 1; j < LCA[0].size(); j++)
            for (int i = 1; i < graph.size(); i++)
                if (LCA[i][j - 1] == -1)
                    LCA[i][j] = -1;
                else
                    LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
    }

    void binary_shifting(int &X, int k)
    {
        int p = LCA[X].size() - 1;
        for (int i = p; k > 0; i--)
        {
            if (k >= (1 << i))
            {
                X = LCA[X][i];
                k -= (1 << i);
            }
        }
    }

    int father(int X, int Y)
    {
        if (Degree[X] < Degree[Y])
            swap(X, Y);
        if (Degree[X] != Degree[Y])
            binary_shifting(X, Degree[X] - Degree[Y]);
        for(int k = LCA[0].size() - 1; k >= 0; k --){
            if(LCA[X][k] != LCA[Y][k]){
                X = LCA[X][k];
                Y = LCA[Y][k];
            }
        }
        if(X != Y)
            X = LCA[X][0];
        return X;
    }

    int dist(int X, int Y){
        int ans = 0;
        if(Degree[X] < Degree[Y])
            swap(X, Y);
        if(Degree[X] != Degree[Y])
            ans += Degree[X] - Degree[Y], binary_shifting(X, Degree[X] - Degree[Y]);
        for(int k = LCA[0].size() - 1; k >= 0; k --){
            if(LCA[X][k] != LCA[Y][k]){
                X = LCA[X][k];
                Y = LCA[Y][k];
                ans += (1 << (k + 1));
            }
        }
        if(X != Y)
            ans += 2;
        return ans;
    }
};
