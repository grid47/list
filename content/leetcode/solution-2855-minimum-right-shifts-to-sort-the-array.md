
+++
authors = ["grid47"]
title = "Leetcode 2855: Minimum Right Shifts to Sort the Array"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2855: Minimum Right Shifts to Sort the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "k3uIpQ54LVY"
youtube_upload_date="2023-09-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/k3uIpQ54LVY/maxresdefault.webp"
comments = true
+++



---
You are given a list of distinct positive integers. Your task is to determine the minimum number of right shifts needed to sort the list in ascending order, or return -1 if it is not possible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of distinct positive integers.
- **Example:** `nums = [4, 5, 6, 1, 2, 3]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100
	- nums contains distinct integers.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of right shifts required to sort the list in ascending order, or -1 if it is not possible.
- **Example:** `Output: 3`
- **Constraints:**
	- The output is an integer, either the number of shifts or -1 if it's impossible.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if it's possible to sort the list with right shifts and calculate the minimum number of shifts.

- Check if the list is already sorted. If it is, return 0.
- If the list is not sorted, check if it can be sorted by performing right shifts. If so, return the number of shifts required.
- If it is not possible to sort the list, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The list contains distinct positive integers.
- The list is cyclic, meaning shifts wrap around the end of the list.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 5, 6, 1, 2, 3]`  \
  **Explanation:** After 3 right shifts, the list becomes sorted as [1, 2, 3, 4, 5, 6].

- **Input:** `nums = [1, 2, 3]`  \
  **Explanation:** The list is already sorted, so no right shifts are needed.

- **Input:** `nums = [3, 1, 2]`  \
  **Explanation:** It's impossible to sort the list with right shifts because no number of right shifts will sort it.

{{< dots >}}
## Approach 🚀
The approach involves checking if the list is already sorted or if it can be sorted by performing right shifts. The key idea is to track how the elements shift cyclically.

### Initial Thoughts 💭
- The list may already be sorted, in which case no shifts are needed.
- If the list is not sorted, check if the elements can be sorted by performing right shifts.
- The main challenge is to identify if the list can be sorted by right shifts, and if so, calculate the minimum number of shifts.
{{< dots >}}
### Edge Cases 🌐
- If the list has a single element, it is trivially sorted.
- For larger inputs, the list should still be checked for the possibility of sorting with right shifts.
- If the list is already sorted, no shifts are required.
- The input list contains distinct integers between 1 and 100.
{{< dots >}}
## Code 💻
```cpp
int minimumRightShifts(vector<int>& nums) {
    int  n = nums.size(),ind = -1,cnt = 0;
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            if(cnt==0){
            ind = i+1;
            cnt++;
            }else return -1;
        }
    }
    if(ind==-1) return 0;
    if(nums[n-1]>nums[0]) return -1;
    return n-ind;
}
```

This function calculates the minimum number of right shifts needed to make a given vector sorted. If the array is already sorted or can be sorted by a single rotation, it returns the minimum number of shifts. Otherwise, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumRightShifts(vector<int>& nums) {
	```
	The function definition begins here. It takes a vector of integers 'nums' as input and returns an integer representing the minimum right shifts.

2. **Variable Initialization**
	```cpp
	    int  n = nums.size(),ind = -1,cnt = 0;
	```
	Initialize variables: 'n' is the size of the array, 'ind' is used to store the index where the first decrease is found, and 'cnt' counts the number of decreases.

3. **Loop Start**
	```cpp
	    for(int i=0;i<n-1;i++){
	```
	Start a loop to iterate through the array from the first element to the second-to-last element.

4. **Condition Check**
	```cpp
	        if(nums[i]>nums[i+1]){
	```
	Check if the current element is greater than the next element, indicating a decrease in the array.

5. **Inner Condition Check**
	```cpp
	            if(cnt==0){
	```
	Check if this is the first decrease found. If yes, the 'ind' is set to the index of the decrease, and the decrease count 'cnt' is incremented.

6. **Set Index**
	```cpp
	            ind = i+1;
	```
	Set 'ind' to the index of the first decrease (i+1) in the array.

7. **Increment Counter**
	```cpp
	            cnt++;
	```
	Increment the 'cnt' variable, indicating that a decrease has been found.

8. **Else Return**
	```cpp
	            }else return -1;
	```
	If a second decrease is found, return -1, indicating that it's not possible to sort the array by a single right shift.

9. **Condition Check**
	```cpp
	    if(ind==-1) return 0;
	```
	Check if no decrease was found ('ind' is still -1), indicating that the array is already sorted. In this case, return 0.

10. **Condition Check**
	```cpp
	    if(nums[n-1]>nums[0]) return -1;
	```
	Check if the last element is greater than the first element. If so, it means the array cannot be rotated to a sorted order, so return -1.

11. **Return Statement**
	```cpp
	    return n-ind;
	```
	Return the number of shifts needed to sort the array, which is the difference between the array size 'n' and the index of the first decrease 'ind'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the list, as we only need to check the list once for sorting and shifts.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we do not use any extra space except for a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/description/)

---
{{< youtube k3uIpQ54LVY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
