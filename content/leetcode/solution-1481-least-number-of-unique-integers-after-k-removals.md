
+++
authors = ["grid47"]
title = "Leetcode 1481: Least Number of Unique Integers after K Removals"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1481: Least Number of Unique Integers after K Removals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Nsp_ta7SlEk"
youtube_upload_date="2024-02-16"
youtube_thumbnail="https://i.ytimg.com/vi/Nsp_ta7SlEk/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers arr and an integer k. You need to remove exactly k elements from the array and find the minimum number of unique integers that remain in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers arr and an integer k.
- **Example:** `[10, 10, 20], k = 1`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- 1 <= arr[i] <= 10^9
	- 0 <= k <= arr.length

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the minimum number of unique integers remaining after removing exactly k elements.
- **Example:** `1`
- **Constraints:**
	- The result is guaranteed to be a valid integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove exactly k elements while minimizing the number of unique integers left in the array.

- Count the frequency of each element in the array.
- Sort the elements by their frequency in ascending order.
- Remove elements starting from the least frequent until exactly k elements are removed.
- Return the number of unique elements remaining.
{{< dots >}}
### Problem Assumptions ✅
- The array can contain duplicate elements.
- The value of k can be zero, meaning no elements need to be removed.
{{< dots >}}
## Examples 🧩
- **Input:** `[10, 10, 20], k = 1`  \
  **Explanation:** Here, the optimal approach is to remove the single `20`, leaving only `10` as the remaining unique integer.

{{< dots >}}
## Approach 🚀
To solve this problem, count the frequency of each element, sort the elements based on frequency, and remove the least frequent elements first to minimize the number of unique integers remaining.

### Initial Thoughts 💭
- The problem requires reducing the number of unique elements after removal, so we should focus on removing the least frequent elements.
- By sorting the elements based on their frequencies, we can efficiently determine which elements to remove.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return 0 since no elements are left.
- Ensure the solution handles arrays with up to 10^5 elements efficiently.
- If k is 0, no elements are removed, and the number of unique elements should be returned as is.
- The algorithm must be efficient enough to handle the upper limit of input size.
{{< dots >}}
## Code 💻
```cpp
int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    for(auto m : arr) mp[m]++;

    sort(begin(arr), end(arr), [&](int x, int y) {
        return mp[x] != mp[y] ? mp[x] < mp[y] : x < y;
    });

    unordered_set<int> st;
    for(int i = k; i < arr.size(); i++) st.insert(arr[i]);

    return st.size();
}
```

The function `findLeastNumOfUniqueInts` is designed to find the least number of unique integers remaining after removing `k` elements from the input array. It counts the frequency of each integer, sorts the array based on the frequency of the integers, and then removes the `k` most frequent elements. Finally, it returns the number of unique integers left in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method**
	```cpp
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
	```
	This is the function signature for `findLeastNumOfUniqueInts`, which takes an array `arr` and an integer `k` as inputs and returns the number of unique integers left after removing `k` elements.

2. **Data Structure**
	```cpp
	    unordered_map<int, int> mp;
	```
	An unordered map `mp` is created to store the frequency of each integer in the array `arr`.

3. **Loop**
	```cpp
	    for(auto m : arr) mp[m]++;
	```
	This loop iterates through each element in the array `arr` and increments its frequency in the unordered map `mp`.

4. **Sorting Logic**
	```cpp
	    sort(begin(arr), end(arr), [&](int x, int y) {
	```
	The `sort` function sorts the elements in `arr` using a custom comparator. It compares the frequency of the integers from the map `mp`.

5. **Comparison**
	```cpp
	        return mp[x] != mp[y] ? mp[x] < mp[y] : x < y;
	```
	The comparator sorts first by frequency (`mp[x] < mp[y]`), and if the frequencies are equal, it sorts by the integer value itself (`x < y`).

6. **Loop**
	```cpp
	    unordered_set<int> st;
	```
	An unordered set `st` is used to store the unique integers remaining after removing `k` elements from the array.

7. **Removal**
	```cpp
	    for(int i = k; i < arr.size(); i++) st.insert(arr[i]);
	```
	Starting from index `k`, the remaining elements are inserted into the unordered set `st`, effectively removing the first `k` elements.

8. **Return**
	```cpp
	    return st.size();
	```
	The function returns the size of the set `st`, which is the count of unique integers left in the array after removal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for sorting the elements based on frequency.
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n), where n is the length of the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n) for storing the frequency map and the sorted list of elements.

The space complexity is O(n) due to the storage required for the frequency map and the sorted elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/)

---
{{< youtube Nsp_ta7SlEk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
