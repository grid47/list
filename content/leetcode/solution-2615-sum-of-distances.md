
+++
authors = ["grid47"]
title = "Leetcode 2615: Sum of Distances"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2615: Sum of Distances in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "b620guqinSc"
youtube_upload_date="2023-04-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b620guqinSc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        /*
        
        [1,3,1,1,2]
         0,1,2,3,4
        
         0
           0  
         2   2
         5   3 4
                 0
        */
        
        unordered_map<int, double> mp, cnt;
        int n = nums.size();
        vector<long long> arr(n, 0);
        for(int i = 0; i < n; i++) {
            arr[i] = cnt[nums[i]] * i - mp[nums[i]];
            mp[nums[i]] += i;
            cnt[nums[i]] += 1;
        }
        mp.clear(), cnt.clear();        
        for(int i = n - 1; i >= 0; i--) {
            arr[i] += mp[nums[i]] - cnt[nums[i]] * i;
            mp[nums[i]] += i;
            cnt[nums[i]] += 1;
        }
        return arr;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are given an array `nums` of size `n`, and we need to compute a new array `arr` such that for each element `arr[i]` in the array, it stores the sum of the absolute differences between `nums[i]` and each of its occurrences to the left and right in the array. The value at `arr[i]` will represent how far each occurrence of `nums[i]` is from the current index `i` in the array.

### Approach

To solve this problem efficiently, a brute force approach that checks each index against all other indices would be too slow, especially for large input sizes. Instead, we can leverage data structures to store cumulative information and reduce redundant computations. Specifically, we will use two passes through the array and two hash maps (`mp` and `cnt`) to compute the required distances efficiently in linear time.

### Code Breakdown (Step by Step)

1. **Initialization**:
   We start by initializing a few variables:
   - `mp`: This unordered map will store the cumulative sum of indices for each number in the array as we iterate through the array.
   - `cnt`: This unordered map will track how many times each number has been encountered so far.
   - `arr`: This vector will store the final results (i.e., the sum of absolute differences for each index in `nums`).

```cpp
unordered_map<int, double> mp, cnt;
int n = nums.size();
vector<long long> arr(n, 0);
```

Here, we initialize `mp` and `cnt` as empty hash maps. `arr` is initialized with all zeros, and its size is equal to the size of the input array `nums`.

2. **First Pass - Left Side Calculation**:
   In the first loop, we traverse the array from left to right. For each index `i`, we compute the sum of the absolute differences between the current element `nums[i]` and all previous occurrences of `nums[i]`.

   The formula for calculating the sum of the absolute differences for the current index `i` is:
   - `arr[i] = cnt[nums[i]] * i - mp[nums[i]]`
   
   Here:
   - `cnt[nums[i]]` keeps track of how many times `nums[i]` has appeared so far (since the previous index).
   - `mp[nums[i]]` stores the cumulative sum of indices where `nums[i]` appeared before index `i`. By multiplying the count by `i` and subtracting the cumulative sum of indices, we calculate the sum of absolute differences for all the previous occurrences of `nums[i]`.

   After calculating `arr[i]`, we update the `mp` and `cnt` maps to include the current index `i`:
   - `mp[nums[i]] += i`: Update the cumulative sum of indices.
   - `cnt[nums[i]] += 1`: Increment the count of occurrences of `nums[i]`.

```cpp
for(int i = 0; i < n; i++) {
    arr[i] = cnt[nums[i]] * i - mp[nums[i]];
    mp[nums[i]] += i;
    cnt[nums[i]] += 1;
}
```

3. **Second Pass - Right Side Calculation**:
   After the first pass, we have computed the sum of absolute differences for each index on the left side of `nums[i]`. Now we need to compute the distances for the right side (i.e., for indices after `i`).

   In the second loop, we traverse the array from right to left. Similar to the first pass, we update `arr[i]` by adding the sum of absolute differences from all occurrences of `nums[i]` on the right side.

   The formula for the right-side distance is:
   - `arr[i] += mp[nums[i]] - cnt[nums[i]] * i`
   
   Here:
   - `mp[nums[i]]` holds the cumulative sum of indices for `nums[i]` from the right side.
   - `cnt[nums[i]] * i` accounts for the total contribution of the right-side elements to the absolute differences.

   After updating `arr[i]`, we update the `mp` and `cnt` maps again:
   - `mp[nums[i]] += i`: Update the cumulative sum of indices.
   - `cnt[nums[i]] += 1`: Increment the count of occurrences of `nums[i]`.

```cpp
mp.clear(), cnt.clear();        
for(int i = n - 1; i >= 0; i--) {
    arr[i] += mp[nums[i]] - cnt[nums[i]] * i;
    mp[nums[i]] += i;
    cnt[nums[i]] += 1;
}
```

4. **Final Result**:
   After both passes, the `arr` array will contain the sum of the absolute differences for each element `nums[i]` with respect to all other occurrences of `nums[i]` to the left and right. The function returns the array `arr`.

```cpp
return arr;
```

### Complexity Analysis

#### Time Complexity:
- **First Pass (Left-to-Right)**: 
   - We traverse the array `nums` once, performing constant-time operations (map lookups and updates) at each index. Thus, the time complexity of the first pass is \(O(n)\), where `n` is the size of the array.
   
- **Second Pass (Right-to-Left)**:
   - Similarly, the second pass also requires traversing the array once and performing constant-time operations at each index. Thus, the time complexity of the second pass is also \(O(n)\).
   
- **Overall Time Complexity**:
   - Since both passes are linear, the overall time complexity is \(O(n)\).

#### Space Complexity:
- **Space for Maps (`mp` and `cnt`)**:
   - The two maps (`mp` and `cnt`) store information about the elements in the array, and in the worst case, they store data for all distinct elements. Thus, the space complexity for these maps is \(O(n)\).
   
- **Space for Output Array `arr`**:
   - We use an additional array `arr` of size `n` to store the results. This also contributes \(O(n)\) space.

- **Overall Space Complexity**:
   - The overall space complexity is \(O(n)\), as both the maps and the output array require linear space.

### Conclusion

This solution efficiently computes the sum of absolute differences between each element and all its occurrences in the array using two linear passes through the array. By utilizing hash maps to store cumulative information about each element’s index and count, we avoid the need for nested loops, resulting in an optimal \(O(n)\) time complexity solution. This makes the approach scalable for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-distances/description/)

---
{{< youtube b620guqinSc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
