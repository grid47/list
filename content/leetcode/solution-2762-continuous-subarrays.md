
+++
authors = ["grid47"]
title = "Leetcode 2762: Continuous Subarrays"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2762: Continuous Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Sliding Window","Heap (Priority Queue)","Ordered Set","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TDB2fGaYzMg"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/TDB2fGaYzMg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int i = 0, j = 0,n=nums.size();
        map<int,int> mp;
        while(j<n) {
            mp[nums[j]]++;
            while(mp.size()>3 || abs(mp.begin()->first - mp.rbegin()->first) > 2) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            long long temp = j-i+1;
            res = res + temp;
            j++;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the total number of subarrays in an integer array `nums` such that:
1. The subarray contains no more than 3 distinct elements.
2. The difference between the maximum and minimum elements of the subarray is no greater than 2.

We are to return the count of all such valid subarrays.

### Approach

To solve this problem, we can use a sliding window approach combined with a hash map (or a frequency map) to efficiently track the elements inside the window.

#### Key Observations:
1. **Sliding Window**: We maintain a sliding window where we can expand the right end of the window (`j`) and contract the left end (`i`) to ensure the subarray satisfies the given conditions.
2. **Valid Subarray Conditions**:
   - The subarray must contain at most 3 distinct integers.
   - The absolute difference between the maximum and minimum values in the subarray should not exceed 2.
   
3. **Sliding Window Expansion**:
   - We increment the right pointer (`j`) and include `nums[j]` in the window, updating its frequency in the map.
   - If the window becomes invalid (i.e., it contains more than 3 distinct elements or the difference between the maximum and minimum elements exceeds 2), we move the left pointer (`i`) to the right, removing elements from the window until the window becomes valid again.

4. **Count of Valid Subarrays**:
   - For every valid window, all subarrays ending at `j` and starting from any index `i` to `j` are valid. The number of such subarrays is `j - i + 1`, and we add this to our result.

#### Code Breakdown (Step by Step)

1. **Variable Initialization**:
   ```cpp
   long long res = 0;
   int i = 0, j = 0, n = nums.size();
   map<int, int> mp;
   ```
   - `res` will store the result, i.e., the total count of valid subarrays.
   - `i` and `j` are pointers representing the left and right ends of the sliding window.
   - `n` stores the size of the input array `nums`.
   - `mp` is a frequency map to keep track of the elements in the current window.

2. **Sliding Window Loop**:
   ```cpp
   while (j < n) {
       mp[nums[j]]++;  // Add the current element to the frequency map
   ```
   - We start iterating with the right pointer `j` from 0 to `n-1`.
   - For each element `nums[j]`, we increment its count in the map.

3. **Window Validation**:
   ```cpp
   while (mp.size() > 3 || abs(mp.begin()->first - mp.rbegin()->first) > 2) {
       mp[nums[i]]--;  // Reduce the frequency of nums[i]
       if (mp[nums[i]] == 0)
           mp.erase(nums[i]);  // If the frequency becomes 0, remove the element from the map
       i++;  // Move the left pointer to the right to shrink the window
   }
   ```
   - If the window becomes invalid, we move the left pointer `i` to the right, reducing the frequency of the element `nums[i]` in the map.
   - If the frequency of `nums[i]` becomes 0, we remove it from the map.
   - We continue adjusting `i` until the window becomes valid again (i.e., it contains at most 3 distinct elements, and the difference between the maximum and minimum values in the window is no greater than 2).

4. **Counting Valid Subarrays**:
   ```cpp
   long long temp = j - i + 1;
   res = res + temp;  // Add the number of valid subarrays to the result
   ```
   - For every valid window, the number of valid subarrays is equal to the length of the current window, which is `j - i + 1`.
   - We add this value to the result.

5. **Increment the Right Pointer**:
   ```cpp
   j++;  // Move the right pointer to expand the window
   ```
   - We then increment the right pointer `j` to expand the window and continue the process.

6. **Return the Final Result**:
   ```cpp
   return res;
   ```
   - Once the loop ends, the result `res` will contain the total count of all valid subarrays, and we return this value.

### Complexity Analysis

#### Time Complexity:

1. **Sliding Window Expansion and Contraction**:
   - The main loop iterates through each element once with the right pointer `j`, and for each `j`, we may increment the left pointer `i` multiple times. However, each element is added and removed from the map at most once.
   - Therefore, the total time complexity of the sliding window approach is \( O(n) \), where `n` is the length of the input array `nums`.

2. **Operations on the Map**:
   - Inserting and removing elements from the map takes \( O(\log k) \), where `k` is the number of distinct elements in the map. Since the map size is constrained by the number of distinct elements (which is at most 3 in the window), the operations on the map take \( O(\log 3) = O(1) \).

Thus, the overall time complexity is \( O(n) \).

#### Space Complexity:

1. **Map Storage**:
   - The map `mp` stores at most 3 distinct elements at any point in time (due to the constraint on the number of distinct elements in the window), so the space complexity for the map is \( O(3) = O(1) \).

2. **Result Variable**:
   - The result variable `res` stores the total number of valid subarrays, which requires \( O(1) \) space.

Thus, the overall space complexity is \( O(1) \).

### Conclusion

The solution uses an efficient sliding window approach to count the number of valid subarrays that meet the given conditions. By maintaining a frequency map of the elements in the current window and adjusting the window dynamically, the algorithm ensures that we count all valid subarrays in linear time, with a space complexity of constant space. This makes the solution highly efficient and suitable for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/continuous-subarrays/description/)

---
{{< youtube TDB2fGaYzMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
