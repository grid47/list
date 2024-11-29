
+++
authors = ["grid47"]
title = "Leetcode 2558: Take Gifts From the Richest Pile"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2558: Take Gifts From the Richest Pile in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_Nh-PvC1Wkg"
youtube_upload_date="2023-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_Nh-PvC1Wkg/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `gifts` where each element represents the number of gifts in different piles. Every second, you pick the pile with the most gifts and leave behind the floor of the square root of the number of gifts. Repeat this operation for `k` seconds, and return the total number of gifts left in all piles.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array `gifts` representing the number of gifts in different piles. Also, an integer `k` representing the number of seconds.
- **Example:** `gifts = [100, 64, 25, 16], k = 3`
- **Constraints:**
	- 1 <= gifts.length <= 1000
	- 1 <= gifts[i] <= 10^9
	- 1 <= k <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The total number of gifts left after performing the operation for `k` seconds.
- **Example:** `36`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** After performing the operation `k` times, return the total number of gifts remaining in all piles.

- 1. Create a max heap to efficiently get the pile with the most gifts.
- 2. For `k` seconds, pick the pile with the most gifts, compute the floor of the square root of the number of gifts, and replace the number of gifts in that pile with the result.
- 3. After `k` operations, sum the remaining gifts in all piles.
{{< dots >}}
### Problem Assumptions ✅
- The array `gifts` is initially non-empty.
- The number of seconds `k` is always valid.
{{< dots >}}
## Examples 🧩
- **Input:** `gifts = [100, 64, 25, 16], k = 3`  \
  **Explanation:** After 3 seconds of choosing the pile with the most gifts, the remaining gifts will be 36.

- **Input:** `gifts = [1, 1, 1, 1], k = 3`  \
  **Explanation:** After 3 seconds, no pile can have fewer than 1 gift, so the total number of remaining gifts is 4.

{{< dots >}}
## Approach 🚀
The key is to use a max heap to always select the pile with the most gifts efficiently. After selecting the pile, compute the floor of the square root of the pile and update it.

### Initial Thoughts 💭
- To solve this efficiently, we need a data structure that can give us the largest pile in constant time.
- A max heap (or priority queue) will help in efficiently getting and updating the pile with the maximum number of gifts.
{{< dots >}}
### Edge Cases 🌐
- The array `gifts` is guaranteed to be non-empty.
- Handle large values of gifts (up to 10^9) efficiently.
- If all piles have 1 gift, no pile can be reduced further, and the total will remain constant.
- Ensure the algorithm handles arrays with up to 1000 elements and operates within the time limit for large values of `gifts[i]`.
{{< dots >}}
## Code 💻
```cpp
  long long pickGifts(vector<int>& g, int k) {
make_heap(g.begin(), g.end());
while(k--) {
    pop_heap(begin(g), end(g));
    g.back() = sqrt(g.back());
    push_heap(begin(g), end(g));
}
return accumulate(begin(g), end(g), 0LL);
  }
```

The function 'pickGifts' takes a vector of integers 'g' and an integer 'k'. It processes the vector by repeatedly taking the largest gift (the root of the heap), modifying it, and placing it back into the heap. The process repeats 'k' times, and then it returns the total sum of the modified values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  long long pickGifts(vector<int>& g, int k) {
	```
	The function 'pickGifts' is defined, taking a vector of integers 'g' and an integer 'k' as input. It returns a long long integer representing the total sum after 'k' operations.

2. **Heap Initialization**
	```cpp
	make_heap(g.begin(), g.end());
	```
	The function initializes the vector 'g' as a max heap using the 'make_heap' function. This allows efficient access to the largest element in 'g'.

3. **Loop Start**
	```cpp
	while(k--) {
	```
	A while loop begins, which will run 'k' times, where each iteration modifies the largest element in the heap.

4. **Heap Pop**
	```cpp
	    pop_heap(begin(g), end(g));
	```
	The largest element in the heap is removed using 'pop_heap'. This moves the largest element to the end of the vector 'g'.

5. **Element Modification**
	```cpp
	    g.back() = sqrt(g.back());
	```
	The largest element (now at the back of the vector) is replaced with its square root. This simulates 'modifying' the gift.

6. **Heap Push**
	```cpp
	    push_heap(begin(g), end(g));
	```
	The modified element is pushed back into the heap to restore the heap property.

7. **Return Result**
	```cpp
	return accumulate(begin(g), end(g), 0LL);
	```
	After 'k' iterations, the function returns the sum of all the elements in the heap using the 'accumulate' function, starting with an initial sum of 0.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k * log n), where n is the number of piles and k is the number of seconds.
- **Average Case:** O(k * log n), since in each of the `k` operations, we perform a log n operation for heap insertion/removal.
- **Worst Case:** O(k * log n), which is the time complexity for handling all `k` seconds with `n` piles.



### Space Complexity 💾
- **Best Case:** O(n), as the space complexity depends on the number of piles.
- **Worst Case:** O(n), where n is the number of piles, as we need space to store the heap.

The space complexity is dominated by the space required to store the heap of piles.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/)

---
{{< youtube _Nh-PvC1Wkg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
