
+++
authors = ["grid47"]
title = "Leetcode 2461: Maximum Sum of Distinct Subarrays With Length K"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2461: Maximum Sum of Distinct Subarrays With Length K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "o8XmnEBQrLs"
youtube_upload_date="2022-11-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/o8XmnEBQrLs/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers and an integer k. You need to find the maximum sum of all possible subarrays of length k, where all elements in the subarray are distinct. If no subarray meets the condition, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer k, where nums represents the array and k is the length of the subarray.
- **Example:** `nums = [1, 5, 4, 2, 9, 9, 9], k = 3`
- **Constraints:**
	- 1 <= k <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of all possible subarrays of length k where all elements are distinct. If no such subarray exists, return 0.
- **Example:** `For nums = [1, 5, 4, 2, 9, 9, 9], k = 3, the output is 15.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the maximum sum of all valid subarrays of length k where all elements are distinct.

- 1. Initialize a sliding window to iterate over the array.
- 2. Maintain a hashmap to track the frequency of each element in the current window.
- 3. If the window size exceeds k or contains duplicates, adjust the window by removing elements from the left.
- 4. For each valid window of size k, calculate the sum and track the maximum sum.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least one element, and k will always be less than or equal to the length of the array.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 5, 4, 2, 9, 9, 9], k = 3`  \
  **Explanation:** The subarrays of nums with length 3 are:
- [1, 5, 4], sum = 10 (valid)
- [5, 4, 2], sum = 11 (valid)
- [4, 2, 9], sum = 15 (valid)
- [2, 9, 9], sum = 20 (invalid, repeated 9)
- [9, 9, 9], sum = 27 (invalid, repeated 9)
The maximum sum of a valid subarray is 15.

{{< dots >}}
## Approach 🚀
We use a sliding window approach to evaluate each subarray of length k. For each window, we ensure that all elements are distinct. If the window is valid, we compute the sum and track the maximum sum.

### Initial Thoughts 💭
- The subarray must be of size k, and all elements in the subarray must be distinct.
- Using a sliding window technique allows us to efficiently evaluate subarrays of size k by adjusting the window as we traverse the array.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty, as the constraints guarantee at least one element.
- The algorithm should handle large inputs efficiently, with arrays up to 100,000 elements.
- If no subarray of length k has distinct elements, the function should return 0.
- The solution must operate within O(n) time complexity to handle the largest inputs.
{{< dots >}}
## Code 💻
```cpp
long long maximumSubarraySum(vector<int>& nums, int k) {
    
    long long sum = 0, ans = 0;
    int n = nums.size(), j = 0;
    
    map<int, int> mp;
    
    for(int i = 0; i < n; i++) {
        
        sum += nums[i];
        mp[nums[i]]++;
        
        while(i - j + 1 > k || mp[nums[i]] > 1) {
            mp[nums[j]]--;
            sum -= nums[j];
            j++;
        }
        if((i - j + 1) == k) {
            ans = max(sum, ans);
        }
    }
    return ans;
}
```

This function finds the maximum sum of a subarray of length `k` in a vector while ensuring no duplicate elements in the subarray.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long maximumSubarraySum(vector<int>& nums, int k) {
	```
	Defines the function to compute the maximum sum of a subarray of size `k`.

2. **Variable Initialization**
	```cpp
	    long long sum = 0, ans = 0;
	```
	Initializes variables to track the current sum and the maximum sum found.

3. **Array Size**
	```cpp
	    int n = nums.size(), j = 0;
	```
	Calculates the size of the input array and initializes a pointer `j` for the sliding window.

4. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Defines a map to count the frequency of elements in the current sliding window.

5. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins the loop to iterate through the array with index `i`.

6. **Update Sum**
	```cpp
	        sum += nums[i];
	```
	Adds the current element to the running sum.

7. **Update Frequency Map**
	```cpp
	        mp[nums[i]]++;
	```
	Increments the frequency count of the current element in the map.

8. **Sliding Window Adjustment**
	```cpp
	        while(i - j + 1 > k || mp[nums[i]] > 1) {
	```
	Adjusts the window size or removes duplicates when the subarray size exceeds `k` or contains duplicates.

9. **Decrement Frequency**
	```cpp
	            mp[nums[j]]--;
	```
	Decrements the frequency count of the element being removed from the sliding window.

10. **Update Sum After Removal**
	```cpp
	            sum -= nums[j];
	```
	Subtracts the value of the removed element from the running sum.

11. **Increment Window Start**
	```cpp
	            j++;
	```
	Moves the start of the sliding window forward by one.

12. **Check Subarray Size**
	```cpp
	        if((i - j + 1) == k) {
	```
	Checks if the current window size is exactly `k`.

13. **Update Maximum**
	```cpp
	            ans = max(sum, ans);
	```
	Updates the maximum sum if the current sum is greater.

14. **Return Result**
	```cpp
	    return ans;
	```
	Returns the maximum sum of any valid subarray of size `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only need to iterate over the array once and adjust the sliding window as needed.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k) due to the hashmap used to store the elements in the sliding window.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/)

---
{{< youtube o8XmnEBQrLs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
