class Solution {
public:
    
    vector<int> primes(int n) {
        vector<int> res;
        for(int i = 2; i < 1000 && n > 1; i += 1 + (i % 2)) {
            if(n % i == 0) {
                res.push_back(i);
                while((n% i) == 0) n /= i;
            }
        }
        if(n > 1) res.push_back(n);
        return res;
    }
    
    int findValidSplit(vector<int>& nums) {
        
        map<int, int> mp;
        vector<long long> line(10001, 0);
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
            for(int f: primes(nums[i])) {
                if(!mp.count(f)) {
                    mp[f] = i;
                }
                line[mp[f]]++;
                line[i]--;
            }
        
        partial_sum(line.begin(), line.end(), line.begin());
        int res = find(line.begin(), line.end(), 0) - line.begin();
        return res < (nums.size() - 1)? res : -1;
    }
};