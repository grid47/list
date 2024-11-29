
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
comments = true
+++



---
Given an array of positive integers nums and an integer p, your task is to remove the smallest subarray (contiguous elements) such that the sum of the remaining elements is divisible by p. If it's impossible, return -1. Note that the entire array cannot be removed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a positive integer array nums and an integer p. The length of nums is between 1 and 10^5, and each element of nums is between 1 and 10^9. The value of p is also between 1 and 10^9.
- **Example:** `Input: nums = [4, 2, 3, 5], p = 8`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 1 <= p <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the smallest subarray that you need to remove so that the sum of the remaining elements is divisible by p. If no such subarray exists, return -1.
- **Example:** `Output: 2`
- **Constraints:**
	- If the whole array cannot be removed and no solution exists, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest subarray that, when removed, ensures the sum of the remaining elements is divisible by p. This involves checking the remainders when elements are added up and removing the minimum contiguous subarray that achieves the result.

- 1. Calculate the total sum of the array.
- 2. If the total sum is already divisible by p, no removal is needed, and the answer is 0.
- 3. Compute the remainder when the sum of the array is divided by p.
- 4. Traverse the array, maintaining a running sum modulo p, and check if a valid subarray exists whose removal makes the total sum divisible by p.
- 5. Keep track of the minimum length of such a subarray and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The array nums contains only positive integers.
- It's guaranteed that the array is non-empty and contains at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [4, 2, 3, 5], p = 8`  \
  **Explanation:** The sum of the array is 14. To make it divisible by 8, we need to remove the subarray [2, 3] (which has sum 5). The remaining sum is 9, which is divisible by 8. Hence, the smallest subarray to remove is of length 2.

- **Input:** `Input: nums = [5, 5, 5, 5], p = 7`  \
  **Explanation:** The sum of the array is 20. We cannot remove any single element or any subarray to get a sum divisible by 7. Hence, the result is -1.

{{< dots >}}
## Approach 🚀
The approach is to find the minimum subarray that can be removed by tracking the remainders of the running sum and identifying when a valid removal is possible. This allows us to minimize the length of the subarray removed.

### Initial Thoughts 💭
- We need to work with running sums and modulo operations to efficiently check the divisibility condition.
- The challenge is to minimize the length of the subarray that needs to be removed.
- The problem can be solved by efficiently maintaining the prefix sum and searching for the smallest valid subarray using a hash map to store the remainders.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where nums has only one element, which cannot be removed completely.
- Ensure the solution handles large arrays efficiently.
- Handle cases where the sum of the array is already divisible by p (in which case no removal is needed).
- Handle cases where no subarray removal can make the sum divisible by p.
- Make sure the solution works within the given time and space constraints.
{{< dots >}}
## Code 💻
```cpp
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

```

This function finds the minimum length of a contiguous subarray whose sum is divisible by a given integer `p`. The function uses a prefix sum approach with modulo operations to efficiently track potential subarrays.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minSubarray(vector<int>& nums, int p) {
	```
	This is the function declaration for `minSubarray`, which takes a vector of integers `nums` and an integer `p` as parameters.

2. **Variable Initialization**
	```cpp
	    map<int, int> mp;
	```
	This initializes a map `mp` to store the remainders of prefix sums, with the index of their last occurrence.

3. **Variable Initialization**
	```cpp
	    mp[0] = -1;
	```
	We initialize the map `mp` with an entry for remainder 0 at index -1, which helps handle cases where the subarray starts from the beginning.

4. **Variable Initialization**
	```cpp
	    int n = nums.size(), res = n, cur = 0, need = 0, want = 0;   
	```
	Here we initialize the variables: `n` for the size of `nums`, `res` for tracking the minimum length of the subarray, `cur` for the current prefix sum modulo `p`, `need` for the target remainder, and `want` for the desired remainder.

5. **Prefix Sum Calculation**
	```cpp
	    for(int a : nums)
	```
	This loop iterates over each element `a` in the `nums` array.

6. **Prefix Sum Calculation**
	```cpp
	        need = (need + a) % p;
	```
	This line computes the cumulative sum modulo `p`, storing the result in `need`, which represents the target remainder for the subarray.

7. **Loop (Main)**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates over each index `i` of the `nums` array to compute the current prefix sum and check if a valid subarray exists.

8. **Prefix Sum Update**
	```cpp
	
	```
	Within this loop, we update the current prefix sum and check for previously seen remainders.

9. **Prefix Sum Update**
	```cpp
	        cur = (cur + nums[i]) % p;
	```
	We update the current prefix sum `cur` with the value of `nums[i]` modulo `p`.

10. **Map Update**
	```cpp
	        mp[cur] = i;
	```
	This stores the index `i` for the current remainder `cur` in the map `mp`.

11. **Target Remainder Calculation**
	```cpp
	        want = (cur - need + p) % p;
	```
	This calculates the remainder `want` which is the target remainder we need to find in the map to form a valid subarray.

12. **Subarray Search**
	```cpp
	        if (mp.count(want))
	```
	This checks if the map contains the target remainder `want`. If it does, we can potentially form a valid subarray.

13. **Result Update**
	```cpp
	        res = min(res, i - mp[want]);
	```
	If a valid subarray is found, this updates the result `res` with the minimum length of the subarray.

14. **Return Statement**
	```cpp
	    return res < n? res : -1;
	```
	This checks if a valid subarray was found. If the result `res` is less than the size of `nums`, it returns `res`; otherwise, it returns -1 to indicate no valid subarray was found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - If the total sum is divisible by p, no subarray needs to be removed.
- **Average Case:** O(n) - We iterate over the array once to compute the prefix sums and check for the valid subarrays.
- **Worst Case:** O(n) - The algorithm runs in linear time with respect to the number of elements.

The time complexity is linear due to the single traversal of the array.

### Space Complexity 💾
- **Best Case:** O(n) - The space complexity remains linear due to the use of a hash map to track the remainder indices.
- **Worst Case:** O(n) - We store the prefix sums and their corresponding indices in a hash map.

The space complexity is linear in the worst case, depending on the number of unique remainders.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-sum-divisible-by-p/description/)

---
{{< youtube tZXsLAyE0SE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
