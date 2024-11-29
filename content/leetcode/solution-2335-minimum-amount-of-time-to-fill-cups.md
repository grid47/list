
+++
authors = ["grid47"]
title = "Leetcode 2335: Minimum Amount of Time to Fill Cups"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2335: Minimum Amount of Time to Fill Cups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jcfxf8gjVbE"
youtube_upload_date="2022-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/jcfxf8gjVbE/maxresdefault.jpg"
comments = true
+++



---
You have a water dispenser that dispenses cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water. You are given an array 'amount' where amount[0], amount[1], and amount[2] represent the number of cold, warm, and hot water cups you need to fill, respectively. Your task is to determine the minimum number of seconds required to fill all the cups.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array 'amount' of length 3, where each element represents the number of cups to be filled with cold, warm, and hot water, respectively.
- **Example:** `amount = [3, 6, 2]`
- **Constraints:**
	- amount.length == 3
	- 0 <= amount[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of seconds needed to fill up all the cups.
- **Example:** `6`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of seconds required to fill all cups, utilizing the option of filling two cups per second or one cup per second.

- Determine the maximum cups to be filled of any type.
- Calculate the total cups to be filled (sum of all cups).
- Find the maximum time required, either by filling two cups at a time or by the total sum divided by 2.
{{< dots >}}
### Problem Assumptions ✅
- The number of cups to fill can be zero for any type of water, meaning that filling cups of that type is not needed.
{{< dots >}}
## Examples 🧩
- **Input:** `amount = [8, 4, 2]`  \
  **Explanation:** By efficiently pairing the cold, warm, and hot water cups, it can be completed in 6 seconds.

{{< dots >}}
## Approach 🚀
To minimize the time, we should try to fill up two cups at once as much as possible, pairing different types of cups. The process is driven by the need to fill the cups with the maximum number of cups first.

### Initial Thoughts 💭
- We can reduce the total time by filling two cups at once.
- Filling up the cups with the largest difference should be prioritized.
- First calculate the maximum number of cups that need to be filled, then compute the sum of cups.
- The minimum time is either based on pairing the cups or based on the sum divided by 2.
{{< dots >}}
### Edge Cases 🌐
- No cups to fill would result in 0 seconds.
- When the values in 'amount' are large, the solution must still compute the result efficiently.
- If any amount[i] is 0, only the remaining cups need to be filled.
- Handle cases with no cups or large input sizes efficiently.
{{< dots >}}
## Code 💻
```cpp
int fillCups(vector<int>& A) {
    int mx = 0, sum = 0;
    for(int& a: A) {
        mx = max(a, mx);
        sum += a;
    }
    return max(mx, (sum + 1) / 2); 
}
```

This is the complete implementation of the function 'fillCups', which calculates the minimum number of moves required to fill cups with water based on given constraints.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Block**
	```cpp
	int fillCups(vector<int>& A) {
	```
	Define the function 'fillCups' that takes a vector of integers A, representing the number of cups of each type.

2. **Variable Initialization**
	```cpp
	    int mx = 0, sum = 0;
	```
	Initialize variables: 'mx' to store the maximum cup count, and 'sum' to store the total sum of all cups.

3. **Loop**
	```cpp
	    for(int& a: A) {
	```
	Iterate over each element in the vector 'A', which represents the cup counts.

4. **Update Maximum**
	```cpp
	        mx = max(a, mx);
	```
	Update the maximum cup count 'mx' with the current value 'a' if it is greater than the current maximum.

5. **Accumulate Sum**
	```cpp
	        sum += a;
	```
	Add the current cup count 'a' to the total sum.

6. **Return Result**
	```cpp
	    return max(mx, (sum + 1) / 2);
	```
	Return the maximum of the 'mx' (maximum cup count) or half of the total cups, rounded up, representing the minimum number of moves required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for small inputs.
- **Average Case:** O(1) as the problem only involves simple calculations.
- **Worst Case:** O(1), as the solution does not involve iterating over large arrays or complex operations.

The time complexity is constant.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1) as only a few variables are used.

Space complexity is constant as the space used does not depend on input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/)

---
{{< youtube jcfxf8gjVbE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
