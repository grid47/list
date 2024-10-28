class Solution {
public:
    long long maxSum(vector<int>& nums, int size, int k) {
        unordered_map<int,int> m;
        long long sum=0;
        long long maxi=0;
        int i=0;
        int j=0;
        
        while(j<nums.size())
        {
            m[nums[j]]++;
            sum+=nums[j];
            
            if(j-i+1>k)
            {
                m[nums[i]]--;
                sum-=nums[i];
                    
                if(m[nums[i]]==0)
                {
                    m.erase(nums[i]);    
                }
                
                i++;
            }
            
            
            
            if(j-i+1==k)
            {
                if(m.size() >= size)
                {
                    maxi=max(sum , maxi);
                    // cout<<maxi<<endl;
                }
            }
            
            j++;
        }
        
        return maxi;
    }
};