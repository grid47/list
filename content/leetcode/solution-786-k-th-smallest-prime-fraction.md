
+++
authors = ["grid47"]
title = "Leetcode 786: K-th Smallest Prime Fraction"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 786: K-th Smallest Prime Fraction in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/786.webp"
youtube = "sJdJTXhxqjo"
youtube_upload_date="2021-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/sJdJTXhxqjo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/786.webp" 
    alt="A set of fractions where the kth smallest prime fraction is found, glowing softly as it is identified."
    caption="Solution to LeetCode 786: K-th Smallest Prime Fraction Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a sorted array of prime numbers and the number 1. You need to find the k-th smallest fraction formed by considering all possible fractions arr[i] / arr[j] where i < j. Return the k-th smallest fraction as an array of two integers, where arr[i] is the numerator and arr[j] is the denominator.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sorted array arr containing prime numbers and the number 1. You are also given an integer k.
- **Example:** `Input: arr = [1, 3, 5, 7], k = 4`
- **Constraints:**
	- 2 <= arr.length <= 1000
	- 1 <= arr[i] <= 30,000
	- arr[0] == 1
	- arr[i] is a prime number for i > 0
	- 1 <= k <= arr.length * (arr.length - 1) / 2

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the k-th smallest fraction as an array of two integers. The first integer is the numerator and the second is the denominator of the fraction.
- **Example:** `Output: [3, 7]`
- **Constraints:**
	- The output should be an array of two integers representing the k-th smallest fraction.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the k-th smallest fraction by considering all possible fractions in the form arr[i] / arr[j] where i < j.

- Initialize a priority queue to store the fractions and their indices.
- Push fractions formed by arr[i] and arr[j] into the priority queue.
- Pop the fractions from the priority queue and keep track of the smallest fractions.
- Repeat until the k-th smallest fraction is found.
{{< dots >}}
### Problem Assumptions ✅
- The array arr is sorted in strictly increasing order.
- The number of fractions is bounded by n * (n - 1) / 2.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: arr = [1, 3, 5, 7], k = 4`  \
  **Explanation:** The fractions to be considered in sorted order are: 1/7, 1/5, 1/3, 3/7, 5/7, and 3/5. The 4th smallest fraction is 3/7.

- **Input:** `Example 2: Input: arr = [1, 2, 7], k = 2`  \
  **Explanation:** The fractions to be considered are: 1/7, 1/2, and 2/7. The 2nd smallest fraction is 1/7.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we can use a priority queue to store fractions in ascending order and pop the smallest fraction until the k-th smallest is found.

### Initial Thoughts 💭
- The number of fractions grows quadratically with the size of the array, making an O(n^2) solution inefficient for large arrays.
- We can optimize the process by using a priority queue to store fractions in sorted order and only keep track of the smallest fractions at each step.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least two elements.
- Handle arrays with up to 1000 elements efficiently.
- If arr contains only two elements, the answer is straightforward.
- The value of k is always valid and within the bounds.
{{< dots >}}
## Code 💻
```cpp
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>> pq;

    for(int i = 0; i < n; i++)
    pq.push(make_pair(-1.0*arr[i]/arr[n - 1], make_pair(i, n - 1)));
    int i, j;        
    while(k--) {
        auto p = pq.top().second; pq.pop();
        i = p.first;
        j = p.second;
        pq.push(make_pair(-1.0*arr[i]/arr[j-1], make_pair(i, j - 1)));
    }
    return vector<int>{arr[i], arr[j]};
}
```

This function finds the kth smallest prime fraction from an array of prime numbers using a priority queue.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
	```
	This defines the function `kthSmallestPrimeFraction`, which takes an array of integers `arr` and an integer `k` to return the kth smallest prime fraction.

2. **Variable Initialization**
	```cpp
	    int n = arr.size();
	```
	This line initializes the variable `n` to store the size of the input array `arr`.

3. **Priority Queue Declaration**
	```cpp
	    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>> pq;
	```
	This declares a priority queue `pq` to store pairs of fractions (in negative form for max-heap behavior) and their respective indices.

4. **Loop Over Array**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This starts a loop to iterate over the array `arr`, where `i` represents the index of the first element of the fraction.

5. **Push Fractions to Priority Queue**
	```cpp
	    pq.push(make_pair(-1.0*arr[i]/arr[n - 1], make_pair(i, n - 1)));
	```
	This pushes the fractions formed by the current element `arr[i]` and the last element `arr[n-1]` into the priority queue. Fractions are negated to use the max-heap behavior.

6. **Initialize Indices**
	```cpp
	    int i, j;        
	```
	This declares two integer variables `i` and `j`, which will be used to store the indices of the current pair of fractions being processed.

7. **Main Loop**
	```cpp
	    while(k--) {
	```
	This begins a while loop that runs `k` times, each time extracting the next smallest fraction from the priority queue.

8. **Pop From Queue**
	```cpp
	        auto p = pq.top().second; pq.pop();
	```
	This pops the top fraction from the priority queue and retrieves the pair of indices `i` and `j` corresponding to the fraction.

9. **Update Indices**
	```cpp
	        i = p.first;
	```
	This stores the first index `i` from the popped pair in the variable `i`.

10. **Update Second Index**
	```cpp
	        j = p.second;
	```
	This stores the second index `j` from the popped pair in the variable `j`.

11. **Push New Fraction to Queue**
	```cpp
	        pq.push(make_pair(-1.0*arr[i]/arr[j-1], make_pair(i, j - 1)));
	```
	This pushes the next fraction formed by `arr[i]` and `arr[j-1]` into the priority queue, decrementing `j` to explore the next smaller fraction.

12. **Return Result**
	```cpp
	    return vector<int>{arr[i], arr[j]};
	```
	After extracting the kth smallest fraction, this line returns the fraction as a pair of integers `arr[i]` and `arr[j]`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k log k), since the heap stores and processes up to k fractions.
- **Average Case:** O(k log k), as we process up to k elements.
- **Worst Case:** O(k log k), since we always push and pop fractions from the heap.

The time complexity is dominated by the priority queue operations, which run in log k time.

### Space Complexity 💾
- **Best Case:** O(k), as the space used by the heap depends on k.
- **Worst Case:** O(k), since the heap stores up to k fractions at any given time.

The space complexity is proportional to the number of fractions stored in the heap.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/k-th-smallest-prime-fraction/description/)

---
{{< youtube sJdJTXhxqjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
