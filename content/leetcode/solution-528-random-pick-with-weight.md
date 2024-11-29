
+++
authors = ["grid47"]
title = "Leetcode 528: Random Pick with Weight"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 528: Random Pick with Weight in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search","Prefix Sum","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/528.webp"
youtube = "oYjDXfo-mt0"
youtube_upload_date="2020-05-22"
youtube_thumbnail="https://i.ytimg.com/vi/oYjDXfo-mt0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/528.webp" 
    alt="A series of objects with different weights, each object softly glowing based on its probability of being picked."
    caption="Solution to LeetCode 528: Random Pick with Weight Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a 0-indexed array of positive integers w, where w[i] describes the weight of the ith index. You need to implement the function pickIndex() which randomly picks an index in the range [0, w.length - 1] (inclusive), and the probability of picking index i is w[i] / sum(w).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array w where each element represents a positive weight.
- **Example:** `[2, 5]`
- **Constraints:**
	- 1 <= w.length <= 10^4
	- 1 <= w[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a randomly selected index i, where the probability of selecting i is proportional to its weight w[i].
- **Example:** `1`
- **Constraints:**
	- The result should be a valid index between 0 and w.length - 1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement pickIndex() in such a way that the probability of selecting each index is proportional to its weight.

- 1. Precompute the cumulative sum of weights in the array.
- 2. Use a random number generator to pick a number in the range of 1 to the total sum of weights.
- 3. Use binary search to find the corresponding index based on the generated random number.
{{< dots >}}
### Problem Assumptions ✅
- The array w contains positive integers representing the weight of each index.
{{< dots >}}
## Examples 🧩
- **Input:** `[2, 5]`  \
  **Explanation:** The total weight is 7, so the probability of picking index 0 is 2/7 and index 1 is 5/7.

- **Input:** `[1]`  \
  **Explanation:** With only one element in the array, the only valid index is 0, so the result is always 0.

{{< dots >}}
## Approach 🚀
The approach involves precomputing a cumulative sum of the weights and then using binary search to pick an index based on a random number.

### Initial Thoughts 💭
- We can treat the array w as a list of intervals where each interval corresponds to a range of cumulative weights.
- By using binary search, we can efficiently find the correct index based on the cumulative sum.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one element, so no need to handle empty input.
- The solution must efficiently handle large arrays with up to 10^4 elements.
- If all elements in the array are the same, each index will have an equal chance of being picked.
- The solution should handle arrays with weights as large as 10^5 efficiently.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> wc;
public:
Solution(vector<int>& w) {
    int n = w.size();
    for(int i = 1; i < n; i++)
        w[i] += w[i - 1];
    wc = w;
}

int pickIndex() {
    
    int x = rand() % wc.back()+1;//[(wc.size() - 1)];        
    int l = 0, r = wc.size() - 1;

    while(l < r) {

        int mid = l + (r - l) / 2;            
        if(wc[mid] == x) return mid;

        if(wc[mid] < x) l = mid + 1;
        else            r = mid;
    
    }
    
    return l;
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
```

This class implements a random weighted picker. It uses a prefix sum approach to convert the problem into a range query problem and employs binary search for efficient index selection. The `pickIndex` function picks an index based on the weighted probability distribution.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class that will contain the constructor for prefix sum calculation and the method for picking a random index based on the prefix sum.

2. **Member Variable Declaration**
	```cpp
	vector<int> wc;
	```
	Declares a vector `wc` which stores the prefix sum of the input weights. This allows for efficient range queries when picking a random index.

3. **Access Modifier**
	```cpp
	public:
	```
	Specifies the start of the public section of the class, making the constructor and methods accessible to external code.

4. **Constructor**
	```cpp
	Solution(vector<int>& w) {
	```
	Constructor for the `Solution` class. It takes a vector of weights `w` and computes the prefix sum, which is stored in the member variable `wc`.

5. **Variable Initialization**
	```cpp
	    int n = w.size();
	```
	Initializes the variable `n` to store the size of the input vector `w`.

6. **Prefix Sum Calculation**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Iterates over the input array `w` to calculate the prefix sum. The prefix sum stores the cumulative sum of weights up to each index.

7. **Prefix Sum Calculation**
	```cpp
	        w[i] += w[i - 1];
	```
	Updates the current element in `w` to be the cumulative sum of the previous element and the current element. This converts the `w` vector into a prefix sum.

8. **Store Prefix Sum**
	```cpp
	    wc = w;
	```
	Stores the computed prefix sum in the member variable `wc` for use in the `pickIndex` method.

9. **Method Definition**
	```cpp
	int pickIndex() {
	```
	Defines the `pickIndex` method, which picks a random index based on the weighted distribution stored in `wc`.

10. **Random Index Generation**
	```cpp
	    int x = rand() % wc.back()+1;//[(wc.size() - 1)];
	```
	Generates a random number `x` between 1 and the total weight (the last element in `wc`). This random number will be used to select an index based on the weighted probabilities.

11. **Variable Initialization**
	```cpp
	    int l = 0, r = wc.size() - 1;
	```
	Initializes two variables `l` and `r` to represent the left and right bounds for binary search on the prefix sum array `wc`.

12. **Binary Search**
	```cpp
	    while(l < r) {
	```
	Starts a binary search loop to find the index in the `wc` array where the random number `x` would fit in the prefix sum.

13. **Binary Search Calculation**
	```cpp
	        int mid = l + (r - l) / 2;
	```
	Calculates the midpoint `mid` of the current range `[l, r]` during binary search.

14. **Binary Search Comparison**
	```cpp
	        if(wc[mid] == x) return mid;
	```
	If the prefix sum at the midpoint `mid` equals the random number `x`, it returns the index `mid` as the selected index.

15. **Binary Search Adjustment**
	```cpp
	        if(wc[mid] < x) l = mid + 1;
	```
	If the value at `wc[mid]` is less than `x`, it means the random number `x` must lie in the right half of the array, so it adjusts the left bound `l`.

16. **Binary Search Adjustment**
	```cpp
	        else            r = mid;
	```
	If the value at `wc[mid]` is greater than `x`, it means the random number `x` must lie in the left half of the array, so it adjusts the right bound `r`.

17. **Return Result**
	```cpp
	    return l;
	```
	Returns the index `l`, which is the position where the random number `x` should be placed in the prefix sum array `wc`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), if the sum and the random number are precomputed and binary search is fast.
- **Average Case:** O(log n), due to the binary search on the cumulative sum.
- **Worst Case:** O(log n), since binary search is always performed on the cumulative sum array.

The time complexity is logarithmic due to binary search.

### Space Complexity 💾
- **Best Case:** O(n), since we are storing the cumulative sum for later use.
- **Worst Case:** O(n), due to the cumulative sum array.

The space complexity is linear due to the storage of the cumulative sum.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/random-pick-with-weight/description/)

---
{{< youtube oYjDXfo-mt0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
