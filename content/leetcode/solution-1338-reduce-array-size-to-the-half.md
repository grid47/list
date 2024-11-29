
+++
authors = ["grid47"]
title = "Leetcode 1338: Reduce Array Size to The Half"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1338: Reduce Array Size to The Half in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an integer array arr. You can choose a set of integers and remove all occurrences of these integers. Your task is to return the minimum size of the set such that at least half of the integers of the array are removed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array arr.
- **Example:** `arr = [1, 1, 2, 2, 3, 3, 4, 5, 5]`
- **Constraints:**
	- 2 <= arr.length <= 10^5
	- arr.length is even.
	- 1 <= arr[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimum size of the set that can be removed to make at least half of the array elements disappear.
- **Example:** `For arr = [1, 1, 2, 2, 3, 3, 4, 5, 5], the output will be 2.`
- **Constraints:**
	- The returned set should be the smallest set that achieves the goal.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum set of integers that should be removed to reduce the size of the array by at least half.

- 1. Count the frequency of each integer in the array.
- 2. Sort the integers by their frequency in descending order.
- 3. Keep removing integers starting from the most frequent until the total number of removed elements is at least half the size of the array.
- 4. Return the number of integers removed.
{{< dots >}}
### Problem Assumptions ✅
- The array may have duplicate integers.
- The array length is always even.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: arr = [1, 1, 2, 2, 3, 3, 4, 5, 5]`  \
  **Explanation:** Choosing the set {1, 5} will remove at least half of the elements from the array.

- **Input:** `Example 2: arr = [4, 4, 4, 4, 5, 5, 5, 5]`  \
  **Explanation:** Choosing either {4} or {5} will remove all elements from the array, achieving the goal with the smallest set.

{{< dots >}}
## Approach 🚀
To solve this problem, count the frequency of each integer, sort the integers by their frequency, and remove the most frequent integers until at least half of the elements are removed.

### Initial Thoughts 💭
- Removing the most frequent integers will reduce the array size the quickest.
- Sorting the integers by frequency will allow us to efficiently determine the smallest set of integers to remove.
{{< dots >}}
### Edge Cases 🌐
- Empty inputs are not valid given the constraints.
- Ensure that the approach works efficiently for large arrays up to the size 10^5.
- If one integer appears enough times, removing just that integer might be sufficient.
- Handle arrays where many integers may have the same frequency.
{{< dots >}}
## Code 💻
```cpp
int minSetSize(vector<int>& arr) {
    unordered_map<int, int> mp;
    for(int c: arr) ++mp[c];

    vector<int> frq;
    for(auto [_, fq] : mp) frq.push_back(fq);

    sort(frq.begin(), frq.end());

    int ans = 0, i = frq.size() - 1, half = arr.size()/2, rm = 0;
    while(rm < half) {
        rm += frq[i--];
        ans++;
    }
    return ans;
}
```

This function finds the minimum size of a set of elements in the array that can remove at least half of the elements in the array. It does so by counting element frequencies, sorting them, and removing elements with the highest frequencies until half of the array is removed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minSetSize(vector<int>& arr) {
	```
	This line defines the function 'minSetSize', which takes a vector of integers 'arr' and returns the minimum number of elements needed to reduce the array by half.

2. **Initialize Frequency Map**
	```cpp
	    unordered_map<int, int> mp;
	```
	We initialize an unordered map 'mp' to store the frequency of each element in the input array.

3. **Count Element Frequencies**
	```cpp
	    for(int c: arr) ++mp[c];
	```
	This loop iterates through each element 'c' in the array and increments its corresponding frequency in the map 'mp'.

4. **Store Frequencies**
	```cpp
	    vector<int> frq;
	```
	We initialize a vector 'frq' to store the frequencies of the elements found in the map 'mp'.

5. **Transfer Frequencies to Vector**
	```cpp
	    for(auto [_, fq] : mp) frq.push_back(fq);
	```
	We iterate through the frequency map and push the frequency values (not the keys) into the 'frq' vector.

6. **Sort Frequencies**
	```cpp
	    sort(frq.begin(), frq.end());
	```
	We sort the frequencies in ascending order so that we can remove the most frequent elements first.

7. **Set Initial Values**
	```cpp
	    int ans = 0, i = frq.size() - 1, half = arr.size()/2, rm = 0;
	```
	Here, we initialize 'ans' to 0 (the count of elements to remove), 'i' to the last index of the frequency vector, 'half' to half the size of the array, and 'rm' to 0 (the count of removed elements).

8. **While Loop**
	```cpp
	    while(rm < half) {
	```
	This while loop runs until we have removed enough elements to reduce the array by half. In each iteration, we remove one of the most frequent elements.

9. **Remove Most Frequent Element**
	```cpp
	        rm += frq[i--];
	```
	We add the frequency of the current most frequent element (at index 'i') to the removed element count 'rm', and decrement the index 'i' to consider the next most frequent element.

10. **Increment Answer**
	```cpp
	        ans++;
	```
	Each time we remove an element, we increment the answer variable 'ans' to track the number of elements removed.

11. **Return Result**
	```cpp
	    return ans;
	```
	Once the while loop finishes, we return the number of elements we need to remove to achieve the goal, stored in 'ans'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the size of the array.
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Sorting the frequencies takes O(n log n), where n is the number of elements in the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the frequency counts of the integers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reduce-array-size-to-the-half/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
