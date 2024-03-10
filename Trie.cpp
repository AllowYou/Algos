struct node
{
    int val;
    map<int, int> child;
 
    node(){
        val = 0;
    }
};
 
struct Trie
{
    vector<node> trie;
 
    void init(vector<str> &a)
    {
        trie.push_back(node());
        for (int i = 0; i < a.size(); i++){
            add(a[i]);
        }
    }
 
    void add(str &s)
    {
        int index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int pos = s[i] - 'a';
            if (trie[index].child[pos] == 0)
            {
                trie[index].child[pos] = trie.size();
                trie.push_back(node());
            }
            index = trie[index].child[pos];
            trie[index].val++;
        }
    }
};