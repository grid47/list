
+++
authors = ["grid47"]
title = "Leetcode 2799: Count Complete Subarrays in an Array"
date = "2024-02-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2799: Count Complete Subarrays in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1wXkWZtSD28"
youtube_upload_date="2023-07-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1wXkWZtSD28/maxresdefault.webp"
comments = true
+++



---
You are given an array 'nums' consisting of positive integers. A subarray is called complete if the number of distinct elements in the subarray is equal to the number of distinct elements in the entire array. Return the total number of complete subarrays.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed array 'nums' containing positive integers.
- **Example:** `Input: nums = [1, 2, 1, 3, 2]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 2000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of complete subarrays.
- **Example:** `Output: 6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of subarrays where the number of distinct elements equals the number of distinct elements in the entire array.

- Identify the number of distinct elements in the entire array.
- Use a sliding window technique to examine all possible subarrays.
- For each subarray, check if it contains all the distinct elements.
{{< dots >}}
### Problem Assumptions ✅
- The array contains only positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 1, 3, 2]`  \
  **Explanation:** The distinct elements are {1, 2, 3}. The complete subarrays are the ones that contain all these elements.

- **Input:** `Input: nums = [4, 4, 4, 4]`  \
  **Explanation:** Since there's only one distinct element (4), every subarray is a complete subarray.

{{< dots >}}
## Approach 🚀
To solve the problem, we can use a sliding window technique to find subarrays containing all the distinct elements of the array.

### Initial Thoughts 💭
- The number of distinct elements in the entire array is key to determining if a subarray is complete.
- Using a sliding window can help us efficiently track subarrays while checking if they meet the distinct element requirement.
{{< dots >}}
### Edge Cases 🌐
- The input array will always contain at least one element.
- For large inputs, the algorithm needs to efficiently count complete subarrays.
- If the array has only one distinct element, every subarray is a complete subarray.
- The solution must handle arrays up to 1000 elements long.
{{< dots >}}
## Code 💻
```cpp
int countCompleteSubarrays(vector<int>& nums) {
    int cnt = 0;
    set<int> dist;
    map<int, int> mp;
    for(int x: nums)
        dist.insert(x);
    int cur = 0, req = dist.size();
    int j = 0, n = nums.size();
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
        if(mp.size() < req) continue;
        while(mp.size() >= req) {
            cnt+= (n - i);
            mp[nums[j]]--;
            if(mp[nums[j]] == 0)
                mp.erase(nums[j]);
            j++;
        }
    }
    return cnt;
}
```

This function counts the number of subarrays in a given vector `nums` that contain all distinct elements. It uses a sliding window approach with a set to track distinct elements and a map to count element frequencies, ensuring each subarray considered has all required unique elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countCompleteSubarrays(vector<int>& nums) {
	```
	The function `countCompleteSubarrays` is declared, which takes a vector of integers `nums` as input. It returns an integer representing the count of subarrays that contain all distinct elements.

2. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	The variable `cnt` is initialized to 0. This will keep track of the number of complete subarrays.

3. **Set Initialization**
	```cpp
	    set<int> dist;
	```
	A set `dist` is initialized to store all distinct elements in the `nums` vector.

4. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	A map `mp` is initialized to store the frequency of elements within the sliding window of subarrays.

5. **Distinct Elements Count**
	```cpp
	    for(int x: nums)
	```
	A `for` loop iterates through each element `x` in the `nums` vector.

6. **Insert Distinct Elements**
	```cpp
	        dist.insert(x);
	```
	Each element `x` is inserted into the `dist` set to determine the number of distinct elements in the input vector `nums`.

7. **Required Elements Count**
	```cpp
	    int cur = 0, req = dist.size();
	```
	The variable `req` is assigned the number of distinct elements in `nums` (i.e., the size of the `dist` set), which represents the number of unique elements needed in each subarray.

8. **Array Size Initialization**
	```cpp
	    int j = 0, n = nums.size();
	```
	The variable `j` is initialized to 0, which will be used to mark the start of the sliding window. The variable `n` stores the size of the `nums` vector.

9. **Outer Loop for Subarray Exploration**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The outer `for` loop starts from the first element and iterates through the entire `nums` vector.

10. **Map Update**
	```cpp
	        mp[nums[i]]++;
	```
	For each element `nums[i]`, its frequency is incremented in the `mp` map, tracking the number of occurrences of elements in the current subarray.

11. **Early Exit Check**
	```cpp
	        if(mp.size() < req) continue;
	```
	If the size of the `mp` map (i.e., the number of distinct elements in the current subarray) is less than the required number of distinct elements (`req`), the loop continues to the next iteration without further processing.

12. **Inner Loop for Sliding Window**
	```cpp
	        while(mp.size() >= req) {
	```
	Once the sliding window contains all the required distinct elements, a `while` loop begins to reduce the window size from the left side.

13. **Count Valid Subarrays**
	```cpp
	            cnt+= (n - i);
	```
	The number of valid subarrays ending at index `i` is added to `cnt`. All subarrays from the current position `i` to the end of the vector are valid.

14. **Decrease Frequency of Left Element**
	```cpp
	            mp[nums[j]]--;
	```
	The frequency of the element at index `j` is decremented as the sliding window shrinks from the left side.

15. **Remove Element if Frequency is Zero**
	```cpp
	            if(mp[nums[j]] == 0)
	```
	If the frequency of the element at index `j` reaches zero, it is removed from the map `mp`.

16. **Increment Window Start**
	```cpp
	                mp.erase(nums[j]);
	```
	The element `nums[j]` is erased from the map `mp` to ensure that only active elements are being considered.

17. **Move Left Pointer**
	```cpp
	            j++;
	```
	The left pointer `j` is incremented to shrink the sliding window from the left side.

18. **Return Count**
	```cpp
	    return cnt;
	```
	The total count `cnt` of valid subarrays is returned from the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n^2)

The worst-case time complexity is O(n^2) due to iterating through each subarray. In practice, the sliding window optimization can help reduce this.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need to store the frequency counts of elements in the current subarray.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/)

---
{{< youtube 1wXkWZtSD28 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
