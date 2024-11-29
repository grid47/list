
+++
authors = ["grid47"]
title = "Leetcode 2171: Removing Minimum Number of Magic Beans"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2171: Removing Minimum Number of Magic Beans in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Enumeration","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MAECrl0V0xs"
youtube_upload_date="2022-02-13"
youtube_thumbnail="https://i.ytimg.com/vi/MAECrl0V0xs/maxresdefault.jpg"
comments = true
+++



---
You are given an array of positive integers representing the number of magic beans in each bag. Your task is to remove some beans (possibly none) from each bag so that the number of beans in each remaining non-empty bag is equal. You need to find the minimum number of beans to remove.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers, where each integer represents the number of beans in a particular magic bag.
- **Example:** `[8, 3, 7, 5]`
- **Constraints:**
	- 1 <= beans.length <= 10^5
	- 1 <= beans[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the minimum number of beans that need to be removed.
- **Example:** `7`
- **Constraints:**
	- The output must be an integer value representing the minimum beans to be removed.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove the minimum number of beans while ensuring that all remaining non-empty bags have the same number of beans.

- Calculate the sum of all beans in the array.
- Sort the array to facilitate efficient calculation of removals.
- For each possible number of beans to keep in each bag, compute the total removals required, and track the minimum removals.
{{< dots >}}
### Problem Assumptions ✅
- The number of bags (beans.length) is at least 1.
- The integers representing the beans in each bag are positive.
{{< dots >}}
## Examples 🧩
- **Input:** `[8, 3, 7, 5]`  \
  **Explanation:** In this example, the optimal solution is to remove 7 beans in total by making the bags have 3 beans each.

{{< dots >}}
## Approach 🚀
The approach is to calculate the total sum of beans and explore the different possible configurations of bags with equal numbers of beans.

### Initial Thoughts 💭
- Sorting the array allows efficient calculation of the total number of beans to be removed.
- The problem involves iterating over the bags to find the most efficient way of removing beans.
{{< dots >}}
### Edge Cases 🌐
- The array will not be empty as per the constraints.
- Ensure the solution handles large arrays efficiently with lengths up to 10^5.
- Consider cases where all the bags contain the same number of beans.
- Ensure the solution works within the provided input constraints.
{{< dots >}}
## Code 💻
```cpp
long long minimumRemoval(vector<int>& beans) {
    int n = beans.size();
    long long sum = accumulate(begin(beans), end(beans), 0L);
    sort(beans.begin(), beans.end());
    long long res = LLONG_MAX;
    for (int i = 0; i < n; i++)
        res = min(res, sum - (long long) (n - i) * beans[i]);
    
    return res;
}
```

This code defines a function `minimumRemoval` that minimizes the number of beans to be removed to balance the remaining beans. It calculates the minimal sum of removal by sorting the input and iterating over the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long minimumRemoval(vector<int>& beans) {
	```
	Define the function `minimumRemoval`, which takes a vector of integers `beans` and returns a long long integer. This function aims to calculate the minimum beans that need to be removed.

2. **Variable Initialization**
	```cpp
	    int n = beans.size();
	```
	Initialize the variable `n` to the size of the `beans` vector, representing the total number of elements in the vector.

3. **Sum Calculation**
	```cpp
	    long long sum = accumulate(begin(beans), end(beans), 0L);
	```
	Use the `accumulate` function to calculate the total sum of the `beans` vector. The initial value of the sum is 0L, and the result is stored in `sum`.

4. **Sorting**
	```cpp
	    sort(beans.begin(), beans.end());
	```
	Sort the `beans` vector in ascending order. Sorting helps in calculating the minimum removals efficiently.

5. **Variable Initialization**
	```cpp
	    long long res = LLONG_MAX;
	```
	Initialize the variable `res` to `LLONG_MAX`, representing the minimum removal result, which will be updated during the iteration.

6. **Loop Start**
	```cpp
	    for (int i = 0; i < n; i++)
	```
	Start a loop that iterates through each element in the `beans` vector. The variable `i` tracks the current index.

7. **Update Minimum Removal**
	```cpp
	        res = min(res, sum - (long long) (n - i) * beans[i]);
	```
	For each iteration, update `res` with the minimum value between the current `res` and the difference between `sum` and the calculated removal cost for the current index `i`.

8. **Return Result**
	```cpp
	    return res;
	```
	Return the final result, which is the minimum number of beans that need to be removed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/description/)

---
{{< youtube MAECrl0V0xs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
