
+++
authors = ["grid47"]
title = "Leetcode 2841: Maximum Sum of Almost Unique Subarray"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2841: Maximum Sum of Almost Unique Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "L8BHtlpLCQw"
youtube_upload_date="2023-09-02"
youtube_thumbnail="https://i.ytimg.com/vi/L8BHtlpLCQw/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array nums and two positive integers m and k. Return the maximum sum out of all almost unique subarrays of length k in nums. A subarray is almost unique if it contains at least m distinct elements. If no such subarray exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums and two integers m and k.
- **Example:** `nums = [1, 3, 5, 7, 1, 8], m = 2, k = 3`
- **Constraints:**
	- 1 <= nums.length <= 2 * 10^4
	- 1 <= m <= k <= nums.length
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of any almost unique subarray of length k, or return 0 if no such subarray exists.
- **Example:** `16`
- **Constraints:**
	- The output should be the maximum sum of a valid subarray or 0 if no valid subarray is found.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum sum of subarrays of length k with at least m distinct elements.

- Initialize a sliding window of size k and a map to track the frequency of elements in the window.
- Iterate through the array, adjusting the window to include k elements while maintaining the condition of having at least m distinct elements.
- Track the sum of the elements in the window and update the maximum sum when the window contains at least m distinct elements.
{{< dots >}}
### Problem Assumptions ✅
- The array contains only positive integers.
- The solution should be efficient enough to handle arrays up to the length of 2 * 10^4.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 3, 5, 7, 1, 8], m = 2, k = 3`  \
  **Explanation:** We can form the following subarrays of length 3: [1, 3, 5], [3, 5, 7], [5, 7, 1], [7, 1, 8]. The maximum sum of the valid subarray with at least 2 distinct elements is 16, from the subarray [7, 1, 8].

- **Input:** `nums = [9, 9, 1, 5, 6, 6], m = 2, k = 3`  \
  **Explanation:** The subarray [9, 9, 1] has a sum of 19 and contains at least 2 distinct elements, so it is valid. The maximum sum is 20, as no other valid subarray has a greater sum.

- **Input:** `nums = [1, 1, 1, 1], m = 2, k = 2`  \
  **Explanation:** No subarrays of length 2 contain at least 2 distinct elements, so the result is 0.

{{< dots >}}
## Approach 🚀
The approach involves using a sliding window to efficiently find subarrays of size k and check if they contain at least m distinct elements.

### Initial Thoughts 💭
- We need to efficiently find subarrays of length k with at least m distinct elements.
- A sliding window approach with a hashmap can help track distinct elements and their frequencies.
- By iterating through the array and maintaining a window of size k, we can ensure that the solution works in linear time.
{{< dots >}}
### Edge Cases 🌐
- The array will not be empty, as nums.length >= 1.
- The algorithm should efficiently handle arrays with up to 20,000 elements.
- All elements in nums could be the same, leading to no valid subarray if m > 1.
- Ensure the sliding window is implemented efficiently to handle the largest input sizes.
{{< dots >}}
## Code 💻
```cpp
long long maxSum(vector<int>& nums, int size, int k) {
    unordered_map<int,int> m;
    long long sum=0;
    long long maxi=0;
    int i=0;
    int j=0;
    
    while(j<nums.size())
    {
        m[nums[j]]++;
        sum+=nums[j];
        
        if(j-i+1>k)
        {
            m[nums[i]]--;
            sum-=nums[i];
                
            if(m[nums[i]]==0)
            {
                m.erase(nums[i]);    
            }
            
            i++;
        }
        
        
        
        if(j-i+1==k)
        {
            if(m.size() >= size)
            {
                maxi=max(sum , maxi);
                // cout<<maxi<<endl;
            }
        }
        
        j++;
    }
    
    return maxi;
}
```

This function calculates the maximum sum of a subarray of size k, ensuring that the subarray contains at least a given number of distinct elements (size). It iterates over the array while maintaining the sum of the current window and adjusting it when necessary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	long long maxSum(vector<int>& nums, int size, int k) {
	```
	Function definition to find the maximum sum of subarray with at least 'size' distinct elements and subarray length 'k'.

2. **Initialization**
	```cpp
	    unordered_map<int,int> m;
	```
	Create a map to track the frequency of elements within the sliding window.

3. **Initialization**
	```cpp
	    long long sum=0;
	```
	Variable to store the sum of elements within the current sliding window.

4. **Initialization**
	```cpp
	    long long maxi=0;
	```
	Variable to store the maximum sum found during the iteration.

5. **Initialization**
	```cpp
	    int i=0;
	```
	Left pointer of the sliding window, used to maintain the window size.

6. **Initialization**
	```cpp
	    int j=0;
	```
	Right pointer of the sliding window, used to iterate through the array.

7. **Loop**
	```cpp
	    while(j<nums.size())
	```
	Start the sliding window loop over the array.

8. **Window Expansion**
	```cpp
	        m[nums[j]]++;
	```
	Increase the count of the current element in the map.

9. **Window Expansion**
	```cpp
	        sum+=nums[j];
	```
	Add the current element to the sum of the sliding window.

10. **Check Window Size**
	```cpp
	        if(j-i+1>k)
	```
	Check if the window size exceeds 'k'. If true, adjust the window by moving the left pointer.

11. **Window Shrinking**
	```cpp
	            m[nums[i]]--;
	```
	Decrease the count of the element at the left pointer.

12. **Window Shrinking**
	```cpp
	            sum-=nums[i];
	```
	Subtract the element at the left pointer from the sum.

13. **Window Shrinking**
	```cpp
	            if(m[nums[i]]==0)
	```
	If the element at the left pointer has no more occurrences in the map, remove it.

14. **Window Shrinking**
	```cpp
	                m.erase(nums[i]);
	```
	Erase the element from the map if its count reaches zero.

15. **Update Left Pointer**
	```cpp
	            i++;
	```
	Move the left pointer to shrink the window.

16. **Window Validation**
	```cpp
	        if(j-i+1==k)
	```
	Check if the current window size matches 'k'.

17. **Max Sum Check**
	```cpp
	            if(m.size() >= size)
	```
	If the window contains at least 'size' distinct elements, check if the sum is a new maximum.

18. **Max Sum Update**
	```cpp
	                maxi=max(sum , maxi);
	```
	Update the maximum sum if the current sum is larger.

19. **Window Expansion**
	```cpp
	            j++;
	```
	Move the right pointer to expand the window.

20. **Return Result**
	```cpp
	    return maxi;
	```
	Return the maximum sum found during the loop.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), because we only pass through the array once, adjusting the sliding window.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k) due to the storage required for the sliding window and the hashmap of size k.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/description/)

---
{{< youtube L8BHtlpLCQw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
