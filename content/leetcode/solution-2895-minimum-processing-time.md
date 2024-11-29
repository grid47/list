
+++
authors = ["grid47"]
title = "Leetcode 2895: Minimum Processing Time"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2895: Minimum Processing Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ju6ArOqNhxM"
youtube_upload_date="2023-10-08"
youtube_thumbnail="https://i.ytimg.com/vi/Ju6ArOqNhxM/maxresdefault.jpg"
comments = true
+++



---
You are given multiple processors with 4 cores each and tasks that need to be assigned to these processors. The goal is to compute the minimum time needed to complete all tasks, where the time taken by a processor is determined by the maximum completion time of its assigned tasks.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays: processorTime and tasks.
- **Example:** `processorTime = [5, 10], tasks = [1, 2, 3, 4, 6, 7, 2, 3]`
- **Constraints:**
	- 1 <= n == processorTime.length <= 25000
	- 1 <= tasks.length <= 10^5
	- tasks.length == 4 * n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum time required to complete all tasks, where the time is determined by the maximum time a processor finishes its assigned tasks.
- **Example:** `For input processorTime = [5, 10], tasks = [1, 2, 3, 4, 6, 7, 2, 3], the output is 16.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to assign tasks to processors and calculate the minimum total time required to complete all tasks.

- Sort both the processorTime array and the tasks array.
- Assign the most time-consuming tasks to the processors in a way that minimizes the total time.
- Calculate the maximum time taken by each processor and return the maximum of those times.
{{< dots >}}
### Problem Assumptions ✅
- The processorTime array is already sorted or can be sorted efficiently.
- The number of tasks is always a multiple of the number of processors.
{{< dots >}}
## Examples 🧩
- **Input:** `For input processorTime = [5, 10], tasks = [1, 2, 3, 4, 6, 7, 2, 3], the output is 16.`  \
  **Explanation:** Tasks are assigned to processors such that the total time is minimized. The first processor will finish its tasks at time 16, and the second processor will finish at time 14. The minimum time is 16.

{{< dots >}}
## Approach 🚀
The approach involves sorting the processors and tasks, and assigning the tasks in a way that minimizes the overall completion time.

### Initial Thoughts 💭
- The number of tasks is fixed at 4 times the number of processors.
- We need to minimize the time by assigning tasks to processors optimally.
- Sorting both the processors and tasks can help in assigning the largest tasks to processors in a way that minimizes the total time.
{{< dots >}}
### Edge Cases 🌐
- The processorTime and tasks arrays should never be empty due to the problem's constraints.
- The solution must efficiently handle the maximum constraints of up to 25000 processors and 100000 tasks.
- Handle cases where processors have very high or very low availability times compared to the tasks.
- Ensure that the approach works for cases where processorTime and tasks arrays are large.
{{< dots >}}
## Code 💻
```cpp
int minProcessingTime(vector<int>& t, vector<int>& v) {
    int n=v.size();
    sort(t.begin(),t.end());
    sort(v.begin(),v.end());
    int j=n-1;
    int m=t.size();
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int c=0;
        while(c<4)
        {
            ans=max(ans,t[i]+v[j]);
            c++;
            j--;
        }
    }
    return ans;
}
```

This function calculates the minimum processing time by sorting two vectors, `t` and `v`, and pairing elements to maximize the processing time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minProcessingTime(vector<int>& t, vector<int>& v) {
	```
	Define the function that calculates the minimum processing time by sorting and pairing elements from two vectors.

2. **Variable Initialization**
	```cpp
	    int n=v.size();
	```
	Get the size of the vector `v` and store it in variable `n`.

3. **Sorting**
	```cpp
	    sort(t.begin(),t.end());
	```
	Sort the vector `t` in ascending order.

4. **Sorting**
	```cpp
	    sort(v.begin(),v.end());
	```
	Sort the vector `v` in ascending order.

5. **Variable Initialization**
	```cpp
	    int j=n-1;
	```
	Initialize `j` to the last index of vector `v`.

6. **Variable Initialization**
	```cpp
	    int m=t.size();
	```
	Get the size of the vector `t` and store it in variable `m`.

7. **Variable Initialization**
	```cpp
	    int ans=0;
	```
	Initialize `ans` to 0. This will store the maximum processing time.

8. **For Loop**
	```cpp
	    for(int i=0;i<m;i++)
	```
	Start a loop to iterate over the elements of vector `t`.

9. **Variable Initialization**
	```cpp
	        int c=0;
	```
	Initialize the counter variable `c` to 0, which will be used for the inner while loop.

10. **While Loop**
	```cpp
	        while(c<4)
	```
	Start a while loop that runs 4 times for each element in `t`.

11. **Max Function**
	```cpp
	            ans=max(ans,t[i]+v[j]);
	```
	Calculate the sum of the current elements `t[i]` and `v[j]`, and update `ans` if the sum is larger.

12. **Counter Update**
	```cpp
	            c++;
	```
	Increment the counter variable `c`.

13. **Pointer Update**
	```cpp
	            j--;
	```
	Decrement the pointer `j` to move to the next element in vector `v`.

14. **Return Statement**
	```cpp
	    return ans;
	```
	Return the calculated maximum processing time stored in `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting of processorTime and tasks arrays.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we store both the processorTime and tasks arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-processing-time/description/)

---
{{< youtube Ju6ArOqNhxM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
