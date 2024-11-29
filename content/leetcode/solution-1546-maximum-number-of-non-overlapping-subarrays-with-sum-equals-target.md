
+++
authors = ["grid47"]
title = "Leetcode 1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target"
date = "2024-06-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wcDDdRZH1Q0"
youtube_upload_date="2020-08-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wcDDdRZH1Q0/maxresdefault.webp"
comments = true
+++



---
Given an integer array nums and an integer target, return the maximum number of non-empty, non-overlapping subarrays that sum up to the target.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers nums and an integer target. The array nums contains the elements of the array, and target is the sum we want to find in non-overlapping subarrays.
- **Example:** `nums = [1, 1, 1, 1, 1], target = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^4 <= nums[i] <= 10^4
	- 0 <= target <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of non-overlapping subarrays where each subarray's sum equals the target.
- **Example:** `Output: 2`
- **Constraints:**
	- The subarrays must be non-overlapping, and each must sum up to the target.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently find the maximum number of non-overlapping subarrays with a sum equal to the target.

- 1. Track the sum of elements in the current subarray.
- 2. When the sum equals the target, count the subarray and reset the sum to start a new subarray.
- 3. Skip overlapping subarrays to ensure non-overlapping subarrays are counted.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that the input array nums is non-empty, and target is a valid integer.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 1, 1, 1, 1], target = 2`  \
  **Explanation:** There are two non-overlapping subarrays that sum up to the target: [1, 1] and [1, 1].

- **Input:** `nums = [-1, 3, 5, 1, 4, 2, -9], target = 6`  \
  **Explanation:** There are multiple subarrays that sum to 6, but only two non-overlapping subarrays count: [5, 1] and [4, 2].

{{< dots >}}
## Approach 🚀
We can approach this problem by iterating through the array while maintaining a running sum of elements. Whenever the sum matches the target, we count the subarray and reset the sum to start a new subarray.

### Initial Thoughts 💭
- We need to avoid overlapping subarrays. Once we find a valid subarray, we should reset the sum and continue searching.
- A greedy approach will work where we continuously look for subarrays with the sum equal to the target and ensure that they don't overlap.
{{< dots >}}
### Edge Cases 🌐
- The input array is always non-empty according to the constraints.
- For large inputs, ensure the solution handles the array efficiently in linear time.
- If the target is 0, handle cases where the subarrays sum to zero, such as when the array contains consecutive zeros.
- Ensure the solution runs within time limits for all values of n and target.
{{< dots >}}
## Code 💻
```cpp
int maxNonOverlapping(vector<int>& nums, int hit) {
    map<int, int> mp;
    
    int n = nums.size(), sum = 0, right = -1, cnt = 0;
    
    //partial_sum(nums.begin(), nums.end(), nums.begin());
    
    
    mp[0] = -1;
    
    
    for(int i = 0; i < n;i++){
        //cout<< nums[i] << " ";
        sum += nums[i];
        if(mp.count(sum - hit)) {
            int left = mp[sum - hit];
        //    cout << right << " " << left;
            if (right <= left) {
                cnt++;
                right = i;
              }
            }


        mp[sum] = i;
        // cout<< mp[sum] << endl;
      }
        
        

    
    return cnt;
        
}
```

This function calculates the maximum number of non-overlapping subarrays whose sum equals to the target value `hit`. It uses a map to store cumulative sums and updates the result accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxNonOverlapping(vector<int>& nums, int hit) {
	```
	This is the function declaration where `maxNonOverlapping` is defined to take a vector of integers `nums` and an integer `hit` as input, and returns an integer representing the maximum number of non-overlapping subarrays whose sum equals `hit`.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	A map `mp` is created to store cumulative sums as keys and their corresponding indices as values, which will help to track if a certain sum (sum - hit) exists to form non-overlapping subarrays.

3. **Variable Initialization**
	```cpp
	    int n = nums.size(), sum = 0, right = -1, cnt = 0;
	```
	The variables are initialized: `n` stores the size of the `nums` vector, `sum` keeps track of the cumulative sum, `right` stores the index of the last valid subarray, and `cnt` tracks the number of valid subarrays.

4. **Map Initialization**
	```cpp
	    mp[0] = -1;
	```
	Initialize the map with a key-value pair of `0: -1` to handle cases where a subarray starting from index 0 sums to `hit`.

5. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A for loop that iterates over each element in the `nums` vector.

6. **Sum Update**
	```cpp
	        sum += nums[i];
	```
	Update the cumulative sum by adding the current element `nums[i]`.

7. **Condition Check**
	```cpp
	        if(mp.count(sum - hit)) {
	```
	Check if the map contains the key `sum - hit`, which would indicate that a subarray with sum `hit` exists.

8. **Map Lookup**
	```cpp
	            int left = mp[sum - hit];
	```
	If the condition is true, get the index of the subarray's left boundary from the map.

9. **Condition Check**
	```cpp
	            if (right <= left) {
	```
	Check if the current subarray is non-overlapping by ensuring that the `right` boundary is less than or equal to the `left` boundary.

10. **Count Update**
	```cpp
	                cnt++;
	```
	If the subarray is non-overlapping, increment the counter `cnt`.

11. **Right Update**
	```cpp
	                right = i;
	```
	Update the `right` boundary to the current index `i` to mark the end of the last valid subarray.

12. **Map Update**
	```cpp
	        mp[sum] = i;
	```
	Add or update the map with the current cumulative sum `sum` and its corresponding index `i`.

13. **Return Statement**
	```cpp
	    return cnt;
	```
	Return the count of non-overlapping subarrays whose sum equals `hit`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through the array once, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/description/)

---
{{< youtube wcDDdRZH1Q0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
