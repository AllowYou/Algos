struct SegTree
{
    int size = 1;
    vector<int> tree;

    inline int merge(int a, int b){
        return a ^ b;
    }

    SegTree(vector<int> &a)
    {
        while ((int)a.size() > size)
            size <<= 1;
        tree.resize(size << 1);
        build(a, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (lx == rx - 1)
        {
            if (lx < (int)a.size())
                tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) >> 1;
        build(a, (x << 1) + 1, lx, m);
        build(a, (x << 1) + 2, m, rx);
        tree[x] = merge(tree[(x << 1) + 1], tree[(x << 1) + 2]);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx == lx + 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m)
            set(i, v, (x << 1) + 1, lx, m);
        else
            set(i, v, (x << 1) + 2, m, rx);
        tree[x] = merge(tree[(x << 1) + 1], tree[(x << 1) + 2]);
    }

    inline void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx)
    {
        if (l <= lx and rx <= r)
            return tree[x];
        if (rx <= l or r <= lx)
            return 0;
        int m = (lx + rx) >> 1;
        return merge(query(l, r, (x << 1) + 1, lx, m), query(l, r, (x << 1) + 2, m, rx));
    }

    inline int query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }
};
