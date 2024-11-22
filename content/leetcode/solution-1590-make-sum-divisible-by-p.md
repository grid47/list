
+++
authors = ["grid47"]
title = "Leetcode 1590: Make Sum Divisible by P"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1590: Make Sum Divisible by P in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tZXsLAyE0SE"
youtube_upload_date="2024-10-03"
youtube_thumbnail="https://i.ytimg.com/vi/tZXsLAyE0SE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        map<int, int> mp;
        mp[0] = -1;
        int n = nums.size(), res = n, cur = 0, need = 0, want = 0;   
        
        for(int a : nums)
            need = (need + a) % p;

        for(int i = 0; i < n; i++) {

            cur = (cur + nums[i]) % p;
            mp[cur] = i;
            want = (cur - need + p) % p;

            if (mp.count(want))
            res = min(res, i - mp[want]);

        }

        return res < n? res : -1;
    }

};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the minimum length of a subarray in an array `nums` such that when the sum of its elements is removed from the array, the remaining elements' sum is divisible by a given integer `p`. If no such subarray exists, we should return -1.

### Approach

To solve this problem efficiently, we will utilize the concept of prefix sums and hash maps. The steps are as follows:

1. **Calculate the Total Remainder**: First, we compute the total sum of the array `nums` modulo `p`. This will give us the remainder that needs to be compensated by removing a subarray.

2. **Use a Hash Map to Track Prefix Remainders**: As we iterate through the array, we will maintain a running sum and track the indices of the remainders we encounter. This will allow us to find subarrays that can adjust the total sum to be divisible by `p`.

3. **Calculate the Required Remainder**: For each element in the array, we calculate what the required remainder would be if we were to remove the current subarray. If this required remainder has been seen before, we can determine the length of the subarray to remove.

4. **Find the Minimum Length**: Throughout the iteration, we will keep track of the minimum length of valid subarrays that can be removed.

5. **Return the Result**: If we found valid subarrays, we return the minimum length; otherwise, we return -1.

### Code Breakdown (Step by Step)

Let’s delve into the code to understand its workings in detail:

```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
```

- **Class and Method Declaration**: We define the `Solution` class and the method `minSubarray`, which takes a vector of integers `nums` and an integer `p`.

```cpp
        map<int, int> mp; // Map to store the last occurrence of each prefix sum remainder
        mp[0] = -1; // Initialize with the case where the prefix sum is zero
        int n = nums.size(), res = n, cur = 0, need = 0, want = 0;   
```

- **Initialization**: We initialize a hash map `mp` to track the indices of the last occurrences of each remainder. We set `mp[0]` to -1 to handle cases where removing a prefix subarray is possible. We also define variables for the size of the array `n`, the result `res` initialized to `n`, and variables for the current prefix sum `cur`, the total remainder needed `need`, and the desired remainder `want`.

```cpp
        for(int a : nums)
            need = (need + a) % p; // Calculate the total remainder needed from the full array
```

- **Calculating Total Remainder**: We iterate through the `nums` array and accumulate the total sum modulo `p` to determine the remainder `need`.

```cpp
        for(int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p; // Update the current prefix sum remainder
            mp[cur] = i; // Store the current index of this remainder
            want = (cur - need + p) % p; // Calculate the required remainder to adjust the sum
```

- **Iterating Through the Array**: We loop through the `nums` array. In each iteration, we update the current prefix sum `cur`, store its last occurrence in the map, and compute the required remainder `want`.

```cpp
            if (mp.count(want))
                res = min(res, i - mp[want]); // If the required remainder exists, calculate the minimum length
```

- **Checking for Valid Subarrays**: We check if the `want` remainder exists in our map. If it does, we calculate the length of the subarray from the last occurrence of `want` to the current index `i`, and we update `res` if this length is smaller than the previous minimum.

```cpp
        return res < n ? res : -1; // Return the minimum length found, or -1 if no valid subarray exists
    }
};
```

- **Final Return Statement**: After iterating through the array, we check if a valid subarray length was found. If `res` is less than `n`, it indicates that we found a valid subarray, so we return its length; otherwise, we return -1.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(n)\), where \(n\) is the number of elements in the `nums` array. This is due to the single pass through the array and the average constant time complexity of operations on the hash map.

- **Space Complexity**: The space complexity is \(O(p)\), where \(p\) is the modulus value. This space is required to store the remainder indices in the hash map.

### Conclusion

This solution efficiently finds the minimum length of a subarray whose removal allows the sum of the remaining elements to be divisible by a specified integer `p`. 

Key takeaways from this solution include:

- **Utilization of Prefix Sums**: By maintaining a running total and its remainder, we can dynamically adjust our search for valid subarrays.
- **Hash Map for Quick Lookups**: The use of a hash map allows for quick access to previously encountered remainders, making it easy to compute the necessary lengths of potential subarrays to remove.
- **Modular Arithmetic**: The problem leverages modular arithmetic to handle the condition of divisibility efficiently.

This algorithm is both efficient and elegant, making it well-suited for scenarios requiring quick calculations involving subarrays and conditions on their sums. The clear structure and logic provide a robust framework for tackling similar problems in array manipulation and mathematical constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/make-sum-divisible-by-p/description/)

---
{{< youtube tZXsLAyE0SE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
