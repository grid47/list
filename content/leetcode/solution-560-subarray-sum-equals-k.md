
+++
authors = ["grid47"]
title = "Leetcode 560: Subarray Sum Equals K"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 560: Subarray Sum Equals K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/560.webp"
youtube = "fFVZt-6sgyo"
youtube_upload_date="2021-06-16"
youtube_thumbnail="https://i.ytimg.com/vi/fFVZt-6sgyo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/560.webp" 
    alt="An array where subarrays that sum to `k` are highlighted, each valid sum softly glowing as it is found."
    caption="Solution to LeetCode 560: Subarray Sum Equals K Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array nums of integers and an integer k, find the total number of contiguous subarrays whose sum equals k.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums containing integers and an integer k.
- **Example:** `Input: nums = [2, 1, 3, 4, 1], k = 4`
- **Constraints:**
	- 1 <= nums.length <= 2 * 10^4
	- -1000 <= nums[i] <= 1000
	- -10^7 <= k <= 10^7

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the number of subarrays whose sum equals k.
- **Example:** `Output: 3`
- **Constraints:**
	- The result should be an integer representing the count of subarrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find all subarrays whose sum equals k, we can maintain a running sum and use a hash map to track how many times each sum has occurred.

- Initialize a hash map to store the frequency of sums and a variable to store the result.
- Iterate through the array, updating the running sum.
- Check if the difference between the current running sum and k exists in the hash map. If it does, increment the result by the frequency of that sum.
- Update the hash map to reflect the new sum after processing each element.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty.
- The integer k is within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, 1, 3, 4, 1], k = 4`  \
  **Explanation:** The subarrays that sum to 4 are [2, 1, 3], [4], and [1, 3]. Therefore, the result is 3.

- **Input:** `Input: nums = [1, -1, 2, 3, -2], k = 3`  \
  **Explanation:** The subarrays that sum to 3 are [3] and [1, -1, 2, 3]. Hence, the result is 2.

{{< dots >}}
## Approach 🚀
This problem can be solved efficiently using a prefix sum and a hash map to track the frequency of sums encountered during the iteration.

### Initial Thoughts 💭
- The sum of any subarray can be represented as a difference between two prefix sums.
- By keeping track of prefix sums using a hash map, we can determine how many times the sum equals k without iterating over all possible subarrays.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty as per the problem constraints.
- The solution should efficiently handle input sizes up to 20,000 elements.
- If k is 0, the solution should handle subarrays that sum to zero.
- The solution should work efficiently even when k is a large or small value within the allowed range.
{{< dots >}}
## Code 💻
```cpp
int subarraySum(vector<int>& nums, int k) {
    
    int res = 0;
    
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0, cnt = 0;
    
    for(int i = 0; i < nums.size(); i++) {

        sum += nums[i];
        if(mp.count(sum - k)) cnt += mp[sum - k];
        mp[sum] += 1;
    }

    return cnt;
}
```

This function finds the number of subarrays in a given array `nums` whose sum equals `k`. It uses a hash map (`mp`) to store prefix sums, efficiently counting subarrays that meet the condition.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int subarraySum(vector<int>& nums, int k) {
	```
	Defines the function `subarraySum` which takes a vector of integers `nums` and an integer `k`, and returns the number of subarrays whose sum equals `k`.

2. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Initializes the result variable `res` to store the count of subarrays that sum to `k`.

3. **Hash Map Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	Declares an unordered map `mp` to store prefix sums of the array. The key is the sum, and the value is its frequency of occurrence.

4. **Initialize Prefix Sum**
	```cpp
	    mp[0] = 1;
	```
	Initializes the hash map with the base case, where a prefix sum of `0` occurs once (for the case of an exact match of `k` from the start of the array).

5. **Prefix Sum Initialization**
	```cpp
	    int sum = 0, cnt = 0;
	```
	Initializes `sum` to keep track of the running prefix sum and `cnt` to count the number of valid subarrays.

6. **Iterate Through Array**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Begins a loop to iterate through the array `nums` to calculate prefix sums.

7. **Prefix Sum Update**
	```cpp
	        sum += nums[i];
	```
	Adds the current element `nums[i]` to the running `sum`.

8. **Check for Subarray Sum**
	```cpp
	        if(mp.count(sum - k)) cnt += mp[sum - k];
	```
	Checks if the prefix sum `sum - k` exists in the hash map. If it does, it means a subarray with sum `k` is found, so it adds the count of occurrences of `sum - k` to `cnt`.

9. **Update Hash Map**
	```cpp
	        mp[sum] += 1;
	```
	Increments the frequency of the current prefix sum `sum` in the hash map `mp`.

10. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the total count of subarrays that sum to `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in the size of the input array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the prefix sums in the hash map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subarray-sum-equals-k/description/)

---
{{< youtube fFVZt-6sgyo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
