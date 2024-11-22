
+++
authors = ["grid47"]
title = "Leetcode 2845: Count of Interesting Subarrays"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2845: Count of Interesting Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ao6glAa0ljY"
youtube_upload_date="2023-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/ao6glAa0ljY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
    class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {        
        unordered_map<long long,long long> mp;
        long long ans = 0, prefix = 0, n = nums.size();
        mp[0]++;

        for(int i=0;i<n;i++) {
            if(nums[i]%mod==k) prefix++;

            prefix%=mod;

            if(mp.find((prefix-k+mod)%mod)!=mp.end()) 
                ans += mp[(prefix-k+mod)%mod];

            mp[prefix]++;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array `nums` of integers, we are asked to find the number of subarrays in `nums` such that the sum of the subarray elements satisfies a certain condition. Specifically, the sum of the subarray elements, when taken modulo `mod`, must equal a given value `k`.

The task is to efficiently compute the number of such subarrays.

### Approach

To solve the problem efficiently, we can use the concept of prefix sums combined with a hash map (unordered_map). The key observation is that we can use the prefix sum modulo `mod` to track how many times a particular modulo has occurred before, and this helps us determine when we have found a valid subarray.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Data Structures
```cpp
unordered_map<long long, long long> mp;
long long ans = 0, prefix = 0, n = nums.size();
mp[0]++;
```
- `mp` is an unordered map used to store the count of prefix sums modulo `mod`. The key is the prefix sum modulo `mod`, and the value is the count of how many times this modulo has occurred.
- `ans` is the variable that will store the final result, which is the number of valid subarrays.
- `prefix` keeps track of the current prefix sum modulo `mod`.
- `n` stores the length of the input array `nums`.
- `mp[0] = 1` is initialized to handle the case where the prefix sum modulo `mod` itself equals `k` without needing to look at previous values.

#### Step 2: Loop Through the Array
```cpp
for (int i = 0; i < n; i++) {
    if (nums[i] % mod == k) prefix++;
    prefix %= mod;
```
- We iterate through each element `nums[i]` of the array.
- If the current element `nums[i]` modulo `mod` equals `k`, we increment the `prefix`. This increment tracks how many elements so far have met the condition (i.e., having `nums[i] % mod == k`).
- We then update `prefix` to keep it in the range `[0, mod-1]` by taking the modulo of the current `prefix` with `mod`.

#### Step 3: Check for Valid Subarrays
```cpp
if (mp.find((prefix - k + mod) % mod) != mp.end())
    ans += mp[(prefix - k + mod) % mod];
```
- We check if there is a previously encountered prefix sum that, when added to the current `prefix`, results in a sum that is congruent to `k` modulo `mod`.
- Specifically, we check if `(prefix - k + mod) % mod` has appeared before in the `mp` map. If it has, the number of such occurrences is added to the answer `ans`.
- This step works because if a certain prefix sum modulo `mod` has appeared earlier, it means there exists a subarray (from that earlier position to the current position) whose sum modulo `mod` equals `k`.

#### Step 4: Update the Map
```cpp
mp[prefix]++;
```
- After checking for valid subarrays, we increment the count of the current `prefix` modulo `mod` in the map `mp`. This allows us to track how many times this particular modulo has been encountered, enabling future subarray checks.

#### Step 5: Return the Result
```cpp
return ans;
```
- Finally, after iterating through the entire array, we return the value of `ans`, which contains the number of subarrays that satisfy the condition.

### Complexity

#### Time Complexity:
- **O(n)**: The algorithm loops through each element of the array exactly once. Inside the loop, the operations (updating the map and checking for valid subarrays) take constant time on average. Thus, the overall time complexity is linear in the size of the input array `nums`.

#### Space Complexity:
- **O(mod)**: The space complexity is determined by the size of the map `mp`, which stores counts for each possible value of `prefix % mod`. Since there are `mod` possible values for the prefix sum modulo `mod`, the space complexity is proportional to `mod`. In the worst case, this is a constant space usage, as `mod` is typically small compared to the size of the input array `nums`.

### Conclusion

This solution leverages the power of prefix sums and hash maps to efficiently count the number of subarrays that satisfy the given condition. By maintaining a running `prefix` sum modulo `mod` and using a hash map to track how often each prefix modulo has been seen, we can efficiently compute the number of valid subarrays. The algorithm runs in linear time and uses constant space relative to the modulus, making it highly efficient for large arrays. This approach is much more optimal than a brute force solution, which would involve checking all possible subarrays directly, leading to a much higher time complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-of-interesting-subarrays/description/)

---
{{< youtube ao6glAa0ljY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
