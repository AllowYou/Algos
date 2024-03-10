struct SegTree
{
    int size = 1;
    vector<int> XOR;

    SegTree(vector<int> &a)
    {
        while ((int)a.size() > size)
            size <<= 1;
        XOR.resize(size << 1);
        build(a, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (lx == rx - 1)
        {
            if (lx < (int)a.size())
                XOR[x] = a[lx];
            return;
        }
        int m = (lx + rx) >> 1;
        build(a, (x << 1) + 1, lx, m);
        build(a, (x << 1) + 2, m, rx);
        XOR[x] = XOR[(x << 1) + 1] ^ XOR[(x << 1) + 2];
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx == lx + 1)
        {
            XOR[x] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m)
            set(i, v, (x << 1) + 1, lx, m);
        else
            set(i, v, (x << 1) + 2, m, rx);
        XOR[x] = XOR[(x << 1) + 1] ^ XOR[(x << 1) + 2];
    }

    inline void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int Xor(int l, int r, int x, int lx, int rx)
    {
        if (l <= lx and rx <= r)
            return XOR[x];
        if (rx <= l or r <= lx)
            return 0;
        int m = (lx + rx) >> 1;
        return Xor(l, r, (x << 1) + 1, lx, m) ^ Xor(l, r, (x << 1) + 2, m, rx);
    }

    inline int Xor(int l, int r)
    {
        return Xor(l, r, 0, 0, size);
    }
};

struct HLD
{
    vector<int> NumberOfChild, Parent, InWhichSegmentTree, IndexOfLine;
    vector<vector<int>> hld;
    vector<SegTree> s;
    int n;

    void dfs(int u, int p, vector<vector<int>> &tree)
    {
        NumberOfChild[u] = 1;
        for (auto &x : tree[u])
            if (x != p)
                dfs(x, u, tree), NumberOfChild[u] += NumberOfChild[x];
    }

    HLD(vector<int> &a, vector<vector<int>> &tree)
    {
        n = a.size();
        NumberOfChild.resize(n);
        Parent.resize(n);
        InWhichSegmentTree.resize(n);
        IndexOfLine.resize(n);

        Parent[0] = -1;
        InWhichSegmentTree[0] = 0;
        IndexOfLine[0] = 0;
        hld.push_back({a[0]});
        dfs(0, -1, tree);

        queue<pair<int, int>> q;
        q.push({0, -1});

        while (!q.empty())
        {
            pair<int, int> u = q.front();
            q.pop();

            if (NumberOfChild[u.fs] == 1)
                continue;
            vector<pair<int, int>> c;
            for (auto &x : tree[u.fs])
                if (x != u.ss)
                    c.push_back({NumberOfChild[x], x});
            sort(all(c), greater<pair<int, int>>());
            Parent[c[0].ss] = Parent[u.fs];
            InWhichSegmentTree[c[0].ss] = InWhichSegmentTree[u.fs];
            IndexOfLine[c[0].ss] = IndexOfLine[u.fs] + 1;
            hld[InWhichSegmentTree[c[0].ss]].push_back(a[c[0].ss]);
            q.push({c[0].ss, u.fs});
            for (int i = 1; i < (int)c.size(); i++)
            {
                Parent[c[i].ss] = u.fs;
                InWhichSegmentTree[c[i].ss] = hld.size();
                IndexOfLine[c[i].ss] = 0;
                hld.push_back({a[c[i].ss]});
                q.push({c[i].ss, u.fs});
            }
        }
        for (int i = 0; i < hld.size(); i++)
            s.push_back(SegTree(hld[i]));
    }

    inline void set(int a, int b)
    {
        s[InWhichSegmentTree[a]].set(IndexOfLine[a], b);
    }

    int query(int a, int b)
    {
        int ans = 0;
        while (true)
        {
            int x = InWhichSegmentTree[a], y = InWhichSegmentTree[b];
            if (x == y)
                break;
            if (x > y)
            {
                ans ^= s[x].Xor(0, IndexOfLine[a] + 1);
                a = Parent[a];
            }
            else
            {
                ans ^= s[y].Xor(0, IndexOfLine[b] + 1);
                b = Parent[b];
            }
        }
        return ans ^= s[InWhichSegmentTree[a]].Xor(min(IndexOfLine[a], IndexOfLine[b]), max(IndexOfLine[a], IndexOfLine[b]) + 1);
    }
};