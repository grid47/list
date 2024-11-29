
+++
authors = ["grid47"]
title = "Leetcode 2145: Count the Hidden Sequences"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2145: Count the Hidden Sequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kEhFfpz-qps"
youtube_upload_date="2022-01-22"
youtube_thumbnail="https://i.ytimg.com/vi/kEhFfpz-qps/maxresdefault.jpg"
comments = true
+++



---
You are given an array representing the differences between each pair of consecutive integers of a hidden sequence. You are also given two integers, lower and upper, which define an inclusive range that the elements of the hidden sequence can take. Your task is to determine the number of possible hidden sequences that fit the given differences and lie within the specified range.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the following elements: 
- An integer array differences of size n (1 ≤ n ≤ 10^5), where differences[i] = hidden[i + 1] - hidden[i]. 
- Two integers lower and upper (−10^5 ≤ lower ≤ upper ≤ 10^5) which specify the inclusive range of values the hidden sequence can contain.
- **Example:** `For example, given differences = [2, -5, 3], lower = -4, upper = 6, we are tasked with finding the number of possible hidden sequences.`
- **Constraints:**
	- 1 <= n <= 10^5
	- -10^5 <= differences[i] <= 10^5
	- -10^5 <= lower <= upper <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer that represents the number of valid hidden sequences that lie within the specified range, or 0 if no valid sequences exist.
- **Example:** `For differences = [2, -5, 3], lower = -4, upper = 6, the output would be 3.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the number of possible hidden sequences that satisfy the given differences and lie within the specified range.

- 1. Initialize two variables, mn and mx, to track the minimum and maximum sum encountered during the process of generating the sequence from the given differences.
- 2. Iterate through the differences array and calculate the cumulative sum, updating mn and mx as necessary.
- 3. Check if the range between lower and upper is large enough to accommodate the difference between mx and mn. If not, return 0.
- 4. Otherwise, calculate the number of valid sequences by determining how many positions in the range [lower, upper] can fit the sequence's difference.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that the input array differences is not empty and contains at least one element.
- It is assumed that the given range [lower, upper] is valid, with lower ≤ upper.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: differences = [2, -5, 3], lower = -4, upper = 6.`  \
  **Explanation:** In this case, the possible hidden sequences are: [-3, 0, -5, -2], [0, 5, 0, 3], and [1, 6, 1, 4]. Thus, there are 3 valid sequences, so the output is 3.

- **Input:** `Example 2: differences = [1, -3, 4], lower = 1, upper = 6.`  \
  **Explanation:** Here, the two possible sequences are [3, 4, 1, 5] and [4, 5, 2, 6]. The output is 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a greedy approach by calculating the cumulative sum of the differences and checking if the resulting sequence can fit within the given range [lower, upper].

### Initial Thoughts 💭
- The problem is essentially about adjusting the sequence to fit the given range after applying the cumulative differences.
- The sequence will need to be adjusted so that the difference between the maximum and minimum values is within the bounds defined by lower and upper.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where the input differences array is empty.
- For large input sizes (n up to 100,000), ensure the algorithm runs efficiently with O(n) time complexity.
- Handle the edge cases where differences contain large negative or positive numbers.
- Ensure that the solution handles the case where the hidden sequence cannot fit within the specified range.
{{< dots >}}
## Code 💻
```cpp
int numberOfArrays(vector<int>& diff, long lower, long upper) {
    // last - fist of n + 1 seq
    
    long mn = 0, mx = 0, x = 0;

    for(int k : diff) {
        x += k;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    
    int sum = mx - mn;
    if (upper - lower < sum)
        return 0;
    else {
        
        return (int)(upper - lower) - sum + 1;
        
    }
    
}
```

This function calculates the number of valid arrays that can be formed by considering the difference array and the given bounds. It computes the maximum and minimum prefix sums and checks if the range between 'lower' and 'upper' is large enough to accommodate the sum difference.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numberOfArrays(vector<int>& diff, long lower, long upper) {
	```
	This line defines the function `numberOfArrays`, which takes three parameters: a reference to a vector `diff`, and two long integers `lower` and `upper` representing the bounds of the valid range.

2. **Variable Initialization**
	```cpp
	    long mn = 0, mx = 0, x = 0;
	```
	This initializes three long integers: `mn` for the minimum prefix sum, `mx` for the maximum prefix sum, and `x` for the current running sum of differences.

3. **Loop**
	```cpp
	    for(int k : diff) {
	```
	This starts a loop that iterates over each element `k` in the vector `diff`, representing the difference array.

4. **Accumulate Sum**
	```cpp
	        x += k;
	```
	This adds the current element `k` to the running sum `x`.

5. **Update Maximum**
	```cpp
	        mx = max(mx, x);
	```
	This updates the maximum prefix sum `mx` by comparing it with the current running sum `x`.

6. **Update Minimum**
	```cpp
	        mn = min(mn, x);
	```
	This updates the minimum prefix sum `mn` by comparing it with the current running sum `x`.

7. **Calculate Range**
	```cpp
	    int sum = mx - mn;
	```
	This calculates the difference between the maximum and minimum prefix sums, storing the result in `sum`.

8. **Condition Check**
	```cpp
	    if (upper - lower < sum)
	```
	This condition checks if the difference between the `upper` and `lower` bounds is smaller than the calculated sum `sum`.

9. **Return Zero**
	```cpp
	        return 0;
	```
	If the condition is true, it means the range is too small to accommodate the required sum, so the function returns 0.

10. **Else Block**
	```cpp
	    else {
	```
	If the condition is false (the range is large enough), the function proceeds to the next step.

11. **Return Result**
	```cpp
	        return (int)(upper - lower) - sum + 1;
	```
	This line calculates and returns the number of valid arrays that can be formed by subtracting the sum from the range and adding 1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we need to process each element of the differences array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a few extra variables for tracking the cumulative min and max sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-hidden-sequences/description/)

---
{{< youtube kEhFfpz-qps >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
