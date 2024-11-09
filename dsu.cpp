struct dsu
{
    vector<int> root, size;

    dsu(int n)
    {
        n++;
        root.resize(n);
        iota(all(root), 0);
        size.resize(n, 1);
    }

    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }

    void join(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return;
        if (size[x] < size[y])
            swap(x, y);
        root[y] = x;
        size[x] += size[y];
    }
};
