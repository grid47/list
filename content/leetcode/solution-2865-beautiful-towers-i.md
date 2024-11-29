
+++
authors = ["grid47"]
title = "Leetcode 2865: Beautiful Towers I"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2865: Beautiful Towers I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iCJCmaPjP4M"
youtube_upload_date="2023-09-24"
youtube_thumbnail="https://i.ytimg.com/vi/iCJCmaPjP4M/maxresdefault.jpg"
comments = true
+++



---
You are given an array heights representing the number of bricks in n consecutive towers. Your task is to remove some bricks to form a mountain-shaped tower arrangement. In this arrangement, the tower heights are non-decreasing, reaching a maximum peak value with one or multiple consecutive towers and then non-increasing. Return the maximum possible sum of heights of a mountain-shaped tower arrangement.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers representing the heights of the towers. You are to remove some bricks to form a mountain-shaped arrangement.
- **Example:** `heights = [4, 6, 2, 3, 5]`
- **Constraints:**
	- 1 <= n <= 1000
	- 1 <= heights[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible sum of the heights of the towers after removing some bricks to form a mountain-shaped arrangement.
- **Example:** `For input heights = [4, 6, 2, 3, 5], the output is 15.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rearrange the towers into a mountain shape by removing some bricks, maximizing the sum of heights in the process.

- For each tower, calculate the possible sum by removing bricks on both sides to create a mountain-shaped arrangement.
- Iterate over all possible peaks and find the one that results in the maximum sum.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least one tower.
- The number of bricks in each tower is always greater than 0.
{{< dots >}}
## Examples 🧩
- **Input:** `For input heights = [4, 6, 2, 3, 5], the output is 15.`  \
  **Explanation:** By removing bricks and forming a mountain shape, we maximize the sum of the tower heights to 15.

{{< dots >}}
## Approach 🚀
We will compute the maximum possible sum of heights by iterating through each possible peak and adjusting the tower heights accordingly.

### Initial Thoughts 💭
- The solution requires us to check every possible peak in the tower arrangement.
- For each peak, we will adjust the neighboring towers to form a valid mountain shape.
- The main challenge is to compute the sum efficiently for each possible peak and find the maximum sum.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty as per the constraints.
- The solution must handle arrays of size 1000 efficiently.
- If all towers have the same height, the mountain shape will be symmetric with the peak at any index.
- Ensure that the sum is maximized after removing bricks to form the mountain shape.
{{< dots >}}
## Code 💻
```cpp

#define ll long long

long long maximumSumOfHeights(vector<int>& a) {
    int n=a.size();
    
   ll int ans=0;
    for(int i=0;i<n;i++){
        ll int sum = a[i];
        int prev=a[i];
        for(int j=i-1;j>=0;j--){
            prev = min(a[j],prev);
            sum += prev;
        }
        prev=a[i];
        for(int j=i+1;j<n;j++){
            prev = min(a[j],prev);
            sum += prev;
        }
        
        if(sum > ans) ans=sum;
    }
    
    return ans;
}
```

This function calculates the maximum sum of heights that can be achieved by considering the heights from an array, with each height being the minimum of its neighboring heights during accumulation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Macro Definition**
	```cpp
	#define ll long long
	```
	Define a macro 'll' as an alias for 'long long' to simplify the code.

2. **Function Start**
	```cpp
	long long maximumSumOfHeights(vector<int>& a) {
	```
	Start of the function definition for maximumSumOfHeights, which takes a vector of integers as input.

3. **Variable Initialization**
	```cpp
	    int n=a.size();
	```
	Initialize the variable 'n' to store the size of the input array 'a'.

4. **Variable Declaration**
	```cpp
	   ll int ans=0;
	```
	Declare a variable 'ans' of type 'long long' to store the maximum sum of heights found.

5. **Outer Loop Start**
	```cpp
	    for(int i=0;i<n;i++){
	```
	Start the outer loop that iterates over each element in the array 'a'.

6. **Inner Sum Initialization**
	```cpp
	        ll int sum = a[i];
	```
	Initialize the variable 'sum' to the value of the current element of the array.

7. **Prev Variable Initialization**
	```cpp
	        int prev=a[i];
	```
	Initialize the 'prev' variable to the current element 'a[i]', representing the previous minimum height.

8. **Leftward Loop Start**
	```cpp
	        for(int j=i-1;j>=0;j--){
	```
	Start the inner loop that iterates leftwards from the current index 'i'.

9. **Leftward Min Calculation**
	```cpp
	            prev = min(a[j],prev);
	```
	Update the 'prev' variable to the minimum value between 'prev' and 'a[j]'.

10. **Leftward Sum Update**
	```cpp
	            sum += prev;
	```
	Add the current 'prev' value to 'sum' to accumulate the sum of heights from the left side.

11. **Rightward Loop Start**
	```cpp
	        prev=a[i];
	```
	Reset the 'prev' variable to the current element 'a[i]' before starting the rightward loop.

12. **Rightward Loop Start**
	```cpp
	        for(int j=i+1;j<n;j++){
	```
	Start the inner loop that iterates rightwards from the current index 'i'.

13. **Rightward Min Calculation**
	```cpp
	            prev = min(a[j],prev);
	```
	Update the 'prev' variable to the minimum value between 'prev' and 'a[j]'.

14. **Rightward Sum Update**
	```cpp
	            sum += prev;
	```
	Add the current 'prev' value to 'sum' to accumulate the sum of heights from the right side.

15. **Max Sum Check**
	```cpp
	        if(sum > ans) ans=sum;
	```
	Check if the current 'sum' is greater than the current 'ans' value, and update 'ans' if true.

16. **Return Statement**
	```cpp
	    return ans;
	```
	Return the value of 'ans', which holds the maximum sum of heights.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The algorithm involves iterating over all possible peaks and calculating the sum for each peak, resulting in a time complexity of O(n^2).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we only need a few extra variables to store the sum and indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/beautiful-towers-i/description/)

---
{{< youtube iCJCmaPjP4M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
