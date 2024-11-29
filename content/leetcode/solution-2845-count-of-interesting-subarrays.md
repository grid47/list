
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
comments = true
+++



---
You are given an array of integers 'nums', a positive integer 'modulo', and a non-negative integer 'k'. Your task is to count the number of subarrays in 'nums' that are interesting. A subarray 'nums[l..r]' is interesting if the count of elements 'nums[i]' such that 'nums[i] % modulo == k' satisfies the condition 'cnt % modulo == k'. Return the total count of such interesting subarrays.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array 'nums', a positive integer 'modulo', and a non-negative integer 'k'.
- **Example:** `nums = [2, 4, 6], modulo = 2, k = 0`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 1 <= modulo <= 10^9
	- 0 <= k < modulo

{{< dots >}}
### Output Specifications 📤
- **Output:** The count of interesting subarrays in the given input.
- **Example:** `Output: 4`
- **Constraints:**
	- The output should be a single integer representing the count of interesting subarrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of subarrays that satisfy the condition where the count of elements divisible by 'modulo' and equal to 'k' satisfies 'cnt % modulo == k'.

- Initialize a map to store the frequency of prefix sums modulo 'modulo'.
- Iterate through the array, updating the prefix sum and checking if the current prefix sum satisfies the condition with previously encountered prefix sums.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty.
- The modulo and k values are valid as per the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 4, 6], modulo = 2, k = 0`  \
  **Explanation:** The subarrays that satisfy the condition are those where the count of elements divisible by 2 and equal to 0 gives a remainder of 0 when divided by 2.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array and using a map to track the frequency of prefix sums modulo 'modulo' to count the interesting subarrays.

### Initial Thoughts 💭
- We need to track the count of elements that satisfy 'nums[i] % modulo == k'.
- The condition 'cnt % modulo == k' can be verified by maintaining a prefix sum modulo 'modulo'.
- The problem can be solved efficiently by using a map to count the prefix sum modulo occurrences.
{{< dots >}}
### Edge Cases 🌐
- No empty input arrays are expected as per the problem statement.
- The algorithm should handle large arrays efficiently, up to the length of 10^5.
- Handle cases where no subarrays satisfy the condition.
- The approach should work within the time and space constraints provided.
{{< dots >}}
## Code 💻
```cpp
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
```

This function calculates the number of interesting subarrays from a list of integers where the subarrays satisfy certain conditions based on modulo arithmetic.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
	```
	Defines the function 'countInterestingSubarrays' which takes a vector of integers, and two integers 'mod' and 'k'.

2. **Variable Declaration**
	```cpp
	    unordered_map<long long,long long> mp;
	```
	Initializes an unordered map 'mp' to store frequencies of mod values encountered during the iteration.

3. **Variable Initialization**
	```cpp
	    long long ans = 0, prefix = 0, n = nums.size();
	```
	Declares and initializes the variables 'ans' to store the result, 'prefix' to track the current modulo sum, and 'n' for the number of elements in the input array.

4. **Map Initialization**
	```cpp
	    mp[0]++;
	```
	Increments the count of mod 0 in the map to account for an initial base case.

5. **Loop Setup**
	```cpp
	    for(int i=0;i<n;i++) {
	```
	Begins a loop that iterates through each element in the input array 'nums'.

6. **Conditional Check**
	```cpp
	        if(nums[i]%mod==k) prefix++;
	```
	Checks if the current element of 'nums' modulo 'mod' equals 'k', and increments the 'prefix' if true.

7. **Prefix Modulo**
	```cpp
	        prefix%=mod;
	```
	Calculates the prefix modulo to ensure the prefix is within the bounds of the modulo value.

8. **Condition Check**
	```cpp
	        if(mp.find((prefix-k+mod)%mod)!=mp.end()) 
	```
	Checks if the adjusted prefix value exists in the map, indicating a valid subarray has been found.

9. **Update Answer**
	```cpp
	            ans += mp[(prefix-k+mod)%mod];
	```
	Adds the frequency of the adjusted prefix to 'ans' to accumulate the number of interesting subarrays.

10. **Update Map**
	```cpp
	        mp[prefix]++;
	```
	Increments the count of the current 'prefix' value in the map.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the total count of interesting subarrays stored in 'ans'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only iterate over the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the map used for storing prefix sums modulo.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-of-interesting-subarrays/description/)

---
{{< youtube ao6glAa0ljY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
