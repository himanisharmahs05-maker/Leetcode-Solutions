class Solution {
public:
    struct Node {
        int child[2] = {-1, -1};
        int cnt = 0;
    };

    vector<Node> trie;

    void insert(int x) {
        int node = 0;
        trie[node].cnt++;

        for (int b = 17; b >= 0; b--) {
            int bit = (x >> b) & 1;

            if (trie[node].child[bit] == -1) {
                trie[node].child[bit] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[bit];
            trie[node].cnt++;
        }
    }

    void remove(int x) {
        int node = 0;
        trie[node].cnt--;

        for (int b = 17; b >= 0; b--) {
            int bit = (x >> b) & 1;
            node = trie[node].child[bit];
            trie[node].cnt--;
        }
    }

    int query(int x) {
        int node = 0;
        int ans = 0;

        for (int b = 17; b >= 0; b--) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;

            if (trie[node].child[want] != -1 &&
                trie[trie[node].child[want]].cnt > 0) {
                ans |= (1 << b);
                node = trie[node].child[want];
            } else {
                node = trie[node].child[bit];
            }
        }

        return ans;
    }

    vector<int> maxGeneticDifference(vector<int>& parents,
                                      vector<vector<int>>& queries) {
        int n = parents.size();

        vector<vector<int>> tree(n);
        int root = -1;

        for (int i = 0; i < n; i++) {
            if (parents[i] == -1)
                root = i;
            else
                tree[parents[i]].push_back(i);
        }

        vector<vector<pair<int,int>>> q(n);

        for (int i = 0; i < queries.size(); i++)
            q[queries[i][0]].push_back({queries[i][1], i});

        vector<int> ans(queries.size());
        trie.push_back(Node());

        function<void(int)> dfs = [&](int u) {
            insert(u);

            for (auto [val, idx] : q[u])
                ans[idx] = query(val);

            for (int v : tree[u])
                dfs(v);

            remove(u);
        };

        dfs(root);

        return ans;
    }
};
