
+++
authors = ["grid47"]
title = "Leetcode 2856: Minimum Array Length After Pair Removals"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2856: Minimum Array Length After Pair Removals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6IPtNE3fIew"
youtube_upload_date="2023-09-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6IPtNE3fIew/maxresdefault.webp"
comments = true
+++



---
You are given a non-decreasing sorted integer array. Perform operations to remove pairs of elements where nums[i] < nums[j] and return the minimum length of the array after the operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sorted list of integers.
- **Example:** `nums = [1, 2, 3, 4]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- nums is sorted in non-decreasing order.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum length of the array after applying the operations.
- **Example:** `Output: 0`
- **Constraints:**
	- The output is an integer, representing the remaining array length.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the minimum length of the array after applying zero or more operations to remove pairs.

- Count the frequency of each element in the array.
- Identify the largest frequency of any element.
- Based on the frequency, determine how many elements can be removed.
- Return the minimum remaining length based on the possible operations.
{{< dots >}}
### Problem Assumptions ✅
- The input array is sorted in non-decreasing order.
- Only valid pairs can be removed (i.e., nums[i] < nums[j]).
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3, 4]`  \
  **Explanation:** All elements can be removed in pairs, leaving the array empty.

- **Input:** `nums = [1, 1, 2, 2, 3, 3]`  \
  **Explanation:** All elements can be removed in pairs, leaving the array empty.

- **Input:** `nums = [1000000000, 1000000000]`  \
  **Explanation:** Both elements are equal, so no pairs can be removed, and the array remains with 2 elements.

- **Input:** `nums = [2, 3, 4, 4, 4]`  \
  **Explanation:** One element can be removed (either 2 or 3), leaving one element.

{{< dots >}}
## Approach 🚀
The approach is to count the frequency of each element and decide how many pairs can be removed based on the largest frequencies.

### Initial Thoughts 💭
- The problem can be reduced to counting frequencies and checking how many pairs can be removed.
- If no valid pairs exist (i.e., all elements are the same), the answer will be the size of the array.
- The key insight is that elements with the same value cannot form a valid pair. The task is to find how many pairs can be removed by checking frequencies.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the result is 0.
- For large inputs, ensure that counting frequencies and removing elements is efficient.
- If all elements are the same, no pairs can be removed, and the array will remain unchanged.
- The array must contain distinct integers, sorted in non-decreasing order.
{{< dots >}}
## Code 💻
```cpp
int minLengthAfterRemovals(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i : nums){
        mp[i]++;
    }
    int maxi = 0;
    for(auto it : mp){
        maxi = max(maxi, it.second);
    }
    if(maxi <= n/2){
        if(n%2){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 2*maxi - n;
    
    
}
```

This function calculates the minimum length of a vector after removing elements based on their frequencies. The goal is to ensure that the frequency of the most frequent element does not exceed half the size of the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minLengthAfterRemovals(vector<int>& nums) {
	```
	The function definition starts here. It takes a vector of integers 'nums' and returns the minimum length after removals.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initialize the variable 'n' to the size of the input vector 'nums'.

3. **Map Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	Initialize an unordered map 'mp' to store the frequency of each element in the vector.

4. **Loop Start**
	```cpp
	    for(int i : nums){
	```
	Start a loop to iterate through each element 'i' in the vector 'nums'.

5. **Frequency Count**
	```cpp
	        mp[i]++;
	```
	Increment the count for the current element 'i' in the map 'mp'.

6. **Max Frequency Initialization**
	```cpp
	    int maxi = 0;
	```
	Initialize 'maxi' to store the maximum frequency found in the map.

7. **Frequency Loop**
	```cpp
	    for(auto it : mp){
	```
	Start a loop to iterate through each element in the frequency map 'mp'.

8. **Update Maximum Frequency**
	```cpp
	        maxi = max(maxi, it.second);
	```
	Update the 'maxi' variable with the maximum frequency found in the map.

9. **Condition Check**
	```cpp
	    if(maxi <= n/2){
	```
	Check if the maximum frequency is less than or equal to half the size of the vector.

10. **Odd Size Check**
	```cpp
	        if(n%2){
	```
	If the size of the vector 'n' is odd, return 1.

11. **Return 1**
	```cpp
	            return 1;
	```
	Return 1 if the array size is odd and the maximum frequency is less than or equal to half the size.

12. **Even Size Check**
	```cpp
	        else{
	```
	If the size of the vector 'n' is even, return 0.

13. **Return 0**
	```cpp
	            return 0;
	```
	Return 0 if the array size is even and the maximum frequency is less than or equal to half the size.

14. **Return Calculation**
	```cpp
	    return 2*maxi - n;
	```
	Return the result of '2*maxi - n', which is the minimum length after removals.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the array once to count frequencies and check the conditions.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the frequency count stored in a hash map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-array-length-after-pair-removals/description/)

---
{{< youtube 6IPtNE3fIew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
