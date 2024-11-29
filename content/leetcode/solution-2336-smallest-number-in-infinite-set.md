
+++
authors = ["grid47"]
title = "Leetcode 2336: Smallest Number in Infinite Set"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2336: Smallest Number in Infinite Set in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_gGX_2ZNa2E"
youtube_upload_date="2022-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/_gGX_2ZNa2E/maxresdefault.jpg"
comments = true
+++



---
You have a set containing all positive integers starting from 1. You need to implement a class SmallestInfiniteSet that has the following methods: 

- SmallestInfiniteSet() Initializes the set to contain all positive integers starting from 1.
- popSmallest() Removes and returns the smallest integer in the set.
- addBack(int num) Adds a positive integer num back into the set, if it’s not already present in the set.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of method calls on the SmallestInfiniteSet class.
- **Example:** `Input: ["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest"] 
Output: [null, null, 1, 2, 3]`
- **Constraints:**
	- 1 <= num <= 1000
	- At most 1000 calls will be made in total to popSmallest and addBack.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of the return values of the method calls in the input sequence.
- **Example:** `[null, null, 1, 2, 3]`
- **Constraints:**
	- The output list will contain the return values of each operation in the order they were executed.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to design a set data structure that efficiently supports removing the smallest element and adding an element back into the set if it's not already there.

- Initialize an empty set and maintain a counter to track the smallest number.
- For each popSmallest operation, check if the set is non-empty and pop the smallest number from the set.
- For each addBack operation, ensure the number is less than the current counter and not already in the set before adding it back.
{{< dots >}}
### Problem Assumptions ✅
- The smallest number in the set is always the first positive integer not yet removed or added back.
{{< dots >}}
## Examples 🧩
- **Input:** `["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest"]`  \
  **Explanation:** The sequence of operations ensures that the smallest integers are popped and numbers can be re-added as needed.

{{< dots >}}
## Approach 🚀
To solve the problem, maintain an ongoing counter to track the smallest number not yet popped. Use a set to store numbers that are added back to the infinite set.

### Initial Thoughts 💭
- The set should handle duplicate insertions gracefully and should always prioritize the smallest available number.
- We can use a counter variable that tracks the smallest number, along with a set to track any numbers that are added back to the infinite set.
{{< dots >}}
### Edge Cases 🌐
- No edge cases related to empty inputs, as the set is always initialized and can be called multiple times.
- The problem must handle up to 1000 operations efficiently.
- Handle the case where a number is added back multiple times or when the set has large numbers.
- Ensure the solution works with at most 1000 operations.
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
- **Best Case:** O(1) when the set is empty and we simply pop the counter value.
- **Average Case:** O(1) for both popSmallest and addBack operations as they involve constant time checks.
- **Worst Case:** O(log n) when adding back numbers to the set and when removing from the set.

The time complexity is constant for most operations, but adding numbers back involves managing the set.

### Space Complexity 💾
- **Best Case:** O(1) if no numbers are added back.
- **Worst Case:** O(n) where n is the number of numbers added back to the set.

Space complexity depends on the number of elements in the set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-number-in-infinite-set/description/)

---
{{< youtube _gGX_2ZNa2E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
