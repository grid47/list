class UF {
public:
    vector<int> parent;
    vector<int> rank;

    UF(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void join(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};


class Solution {
public:
    
    vector<int> factors(int num) {
        vector<int> ans;
        for(int j = 2; j * j <= num; j++) {
            while(num % j == 0) {
                num /= j;
                ans.push_back(j);
            }
        }
        if(num != 1) ans.push_back(num);
        return ans;
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        
        int n  = nums.size();
        UF *uf = new UF(n);
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            vector<int> fact = factors(num);
            for (int x : fact) {
                if(mp.count(x)) {
                    uf->join(i, mp[x]);
                } else {
                    mp[x] = i;
                }
            }
        }
 
        for(int i = 0; i < nums.size(); i++) {
            if(uf->find(i) != uf->find(0)) return false;
        }
        return true;
    }
};