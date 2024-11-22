
+++
authors = ["grid47"]
title = "Leetcode 523: Continuous Subarray Sum"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 523: Continuous Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/523.webp"
youtube = "OKcrLfR-8mE"
youtube_upload_date="2022-03-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/OKcrLfR-8mE/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/523.webp" 
    alt="An array where the sum of a continuous subarray is highlighted with glowing elements."
    caption="Solution to LeetCode 523: Continuous Subarray Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum %= k;
            if (mp.count(sum))
            {
                if (i - mp[sum] > 1) 
                    return true;
            }
            else mp[sum] = i;
        }
        return false;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires checking if there exists a continuous subarray of length at least two within a given list of integers, `nums`, such that the sum of the subarray is a multiple of an integer `k`. In other words, we need to find out if any subarray's sum, divided by `k`, yields a remainder of zero.

### Approach

This problem can be efficiently solved using modular arithmetic and a hashmap (or dictionary). The approach hinges on understanding that if two cumulative sums at different indices leave the same remainder when divided by `k`, then the sum of the numbers between these indices is divisible by `k`. This technique allows us to track remainders of cumulative sums and determine if we encounter a repeated remainder in a non-overlapping subarray.

Here’s the approach broken down:

1. **Initialize Variables**:
   - `sum` is used to accumulate the cumulative sum of `nums` as we iterate through the array.
   - `mp` is a hashmap to store the remainders of `sum` modulo `k` and their corresponding indices, allowing us to detect cycles in remainders.
   - Initialize `mp` with `{0: -1}` to handle cases where a valid subarray starts from the beginning of `nums`.

2. **Iterate through the Array**:
   - For each element in `nums`, add it to `sum` to get the cumulative sum up to that index.
   - Calculate `sum % k` to get the remainder of the cumulative sum when divided by `k`.

3. **Check for Repeated Remainders**:
   - If this remainder has been seen before (exists in `mp`), it means there’s a subarray whose sum is divisible by `k`.
   - Check the distance between the current index and the last index where this remainder was seen. If the distance is greater than 1, we found a valid subarray, so return `true`.
   - If the remainder is new, store it in `mp` along with its index.

4. **Return False if No Valid Subarray is Found**:
   - If the loop completes without finding a valid subarray, return `false`.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
map<int, int> mp;
mp[0] = -1;
int sum = 0;
```

- `mp` is initialized with `{0: -1}`. This handles cases where a valid subarray starts from the beginning of `nums`.
- `sum` is initialized to 0 and will be used to calculate cumulative sums.

#### Step 2: Loop Through the Array

```cpp
for(int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    sum %= k;
```

- The `for` loop iterates through each element in `nums`.
- For each element, `sum += nums[i]` updates the cumulative sum.
- `sum %= k` takes the remainder of `sum` divided by `k`.

#### Step 3: Check if the Remainder Exists in `mp`

```cpp
if (mp.count(sum)) {
    if (i - mp[sum] > 1) 
        return true;
}
else {
    mp[sum] = i;
}
```

- If `sum` is already a key in `mp`, this indicates a possible subarray with a sum that’s divisible by `k`.
- Check if `i - mp[sum] > 1` to ensure the subarray has a length of at least 2. If true, return `true`.
- If `sum` isn’t in `mp`, store `sum` in `mp` with its corresponding index `i`.

#### Step 4: Return False if No Valid Subarray Found

```cpp
return false;
```

- If the function completes the loop without finding any valid subarray, it returns `false`.

### Complexity

#### Time Complexity
- The time complexity is **O(n)**, where `n` is the length of `nums`, because we only iterate through `nums` once.

#### Space Complexity
- The space complexity is **O(min(k, n))**, as the hashmap `mp` stores at most `min(k, n)` keys due to the `sum % k` operation, where each unique remainder requires storage.

### Conclusion

This solution efficiently finds a continuous subarray with a sum that’s a multiple of `k` by leveraging modular arithmetic and a hashmap. Using modular properties to track remainders allows for a compact, optimized solution compared to traditional approaches that might involve nested loops or explicit subarray calculations. This approach is ideal for large datasets, providing a clear path to solving the problem in linear time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/continuous-subarray-sum/description/)

---
{{< youtube OKcrLfR-8mE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
