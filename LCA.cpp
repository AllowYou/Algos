struct Lowest_Common_Ancestor
{
    vector<vector<int>> LCA;
    vector<int> Degree;

    void dfs(int u, int p, vector<vector<int>> &tree)
    {
        LCA[u][0] = p;
        for (auto &x : tree[u])
        {
            if (x != p)
            {
                Degree[x] = Degree[u] + 1;
                dfs(x, u, tree);
            }
        }
    }

    Lowest_Common_Ancestor(vector<vector<int>> &tree)
    {
        LCA.resize(tree.size(), vector<int>((int)(log2(tree.size())) + 1));
        Degree.resize(tree.size(), 1);

        dfs(1, -1, tree);

        for (int i = 1; i <= tree.size() - 1; i++)
            for (int j = 1; j < LCA[i].size(); j++)
                if (LCA[i][j - 1] == -1)
                    LCA[i][j] = -1;
                else
                    LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
    }

    void binary_shifting(int &X, int k)
    {
        for (int i = LCA[X].size(); i >= 0; i--)
        {
            if (k >= (1 << i))
            {
                X = LCA[X][i];
                k -= (1 << i);
            }
        }
    }

    int lca(int X, int Y)
    {
        if (Degree[X] < Degree[Y])
            swap(X, Y);
        if (Degree[X] != Degree[Y])
            binary_shifting(X, Degree[X] - Degree[Y]);
        int k = LCA[0].size() - 1;
        while (X != Y)
        {
            int l = 0, r = k;
            while (l < r)
            {
                int m = (l + r + 1) >> 1;
                if (LCA[X][m] == LCA[Y][m])
                    r = m - 1;
                else
                    l = m;
            }
            X = LCA[X][l];
            Y = LCA[Y][l];
            k = l;
        }
        return X;
    }
};