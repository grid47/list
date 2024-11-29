
+++
authors = ["grid47"]
title = "Leetcode 2958: Length of Longest Subarray With at Most K Frequency"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2958: Length of Longest Subarray With at Most K Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "W_KYZGp2QzU"
youtube_upload_date="2024-03-28"
youtube_thumbnail="https://i.ytimg.com/vi/W_KYZGp2QzU/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array nums and an integer k. The frequency of an element is the number of times it appears in the array. A subarray is called good if the frequency of each element in it is less than or equal to k. Your task is to return the length of the longest good subarray in nums.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array 'nums' and an integer 'k'.
- **Example:** `nums = [1, 2, 3, 1, 2, 3, 1, 2], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 1 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest good subarray where each element occurs no more than 'k' times.
- **Example:** `6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the length of the longest subarray where no element occurs more than k times.

- Use a sliding window technique to traverse the array.
- Maintain a count of each element in the window using a map or hash map.
- If any element exceeds the frequency of k, shrink the window from the left until all frequencies are <= k.
- Track and return the maximum length of such a valid window.
{{< dots >}}
### Problem Assumptions ✅
- The input array will have at least one element.
- The value of k will always be valid within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1,2,3,1,2,3,1,2], k = 2`  \
  **Explanation:** The subarray [1,2,3,1,2,3] is the longest subarray where all numbers occur at most twice.

- **Input:** `Input: nums = [5,5,5,5,5,5,5], k = 4`  \
  **Explanation:** The subarray [5,5,5,5] is the longest good subarray, where the number 5 occurs 4 times.

{{< dots >}}
## Approach 🚀
Use the sliding window technique to track the frequency of elements in the subarray. Adjust the window to ensure no element exceeds the allowed frequency 'k'.

### Initial Thoughts 💭
- A sliding window can efficiently track the subarray while adjusting for the frequency condition.
- Sliding window combined with a frequency map will allow efficient updates when elements are added or removed from the window.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element, so no need to handle empty inputs.
- Ensure the solution handles the largest array sizes efficiently, up to 10^5 elements.
- When all elements in the array are the same, the solution should handle the case where only subarrays with length up to 'k' are allowed.
- The array size is up to 100,000 elements, so the solution should run in O(n) time.
{{< dots >}}
## Code 💻
```cpp
int maxSubarrayLength(vector<int>& nums, int k) {
    
    map<int, int> mp;
    int j = 0, res = 1, n = nums.size();
    
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
        while(mp[nums[i]] > k) {
            mp[nums[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    return res;
}
```

This function calculates the length of the longest subarray that contains at most 'k' occurrences of each unique element in the given array 'nums'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxSubarrayLength(vector<int>& nums, int k) {
	```
	Defines the function 'maxSubarrayLength' that takes a vector 'nums' and an integer 'k', and returns the length of the longest subarray where no element appears more than 'k' times.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Declares a map 'mp' to store the frequency of each element in the current window (subarray) of the vector 'nums'.

3. **Variable Initialization**
	```cpp
	    int j = 0, res = 1, n = nums.size();
	```
	Initializes 'j' as the left pointer of the sliding window, 'res' to store the maximum subarray length, and 'n' to store the size of the input array.

4. **For Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a for loop that iterates over the array 'nums' with index 'i', representing the right pointer of the sliding window.

5. **Increment Frequency**
	```cpp
	        mp[nums[i]]++;
	```
	Increments the frequency of the current element 'nums[i]' in the map 'mp'. This keeps track of how many times each element appears in the current window.

6. **While Loop Start**
	```cpp
	        while(mp[nums[i]] > k) {
	```
	Starts a while loop that ensures the frequency of the current element 'nums[i]' does not exceed 'k'. If it does, the window is adjusted.

7. **Decrement Frequency**
	```cpp
	            mp[nums[j]]--;
	```
	Decreases the frequency of the element at the left pointer 'j' in the map 'mp' to reduce the window size and maintain the condition of having at most 'k' occurrences of each element.

8. **Increment Left Pointer**
	```cpp
	            j++;
	```
	Moves the left pointer 'j' of the sliding window to the right, effectively shrinking the window until the frequency condition is met again.

9. **Update Maximum Length**
	```cpp
	        res = max(res, i - j + 1);
	```
	Updates 'res' with the maximum subarray length found so far by comparing the current subarray length (i - j + 1) with the previous maximum.

10. **Return Result**
	```cpp
	    return res;
	```
	Returns the length of the longest subarray found that satisfies the condition of having at most 'k' occurrences of each element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since each element is processed at most twice (once when expanding the window and once when shrinking it).

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the frequency map storing up to n elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/)

---
{{< youtube W_KYZGp2QzU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
