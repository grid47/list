
+++
authors = ["grid47"]
title = "Leetcode 1054: Distant Barcodes"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1054: Distant Barcodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MlgCCJ7MfKQ"
youtube_upload_date="2024-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/MlgCCJ7MfKQ/maxresdefault.jpg"
comments = true
+++



---
You are given an array of barcodes where each element represents a barcode. Your task is to rearrange the barcodes such that no two adjacent barcodes are the same. It is guaranteed that a solution exists, and you may return any valid rearrangement.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers, where each element represents a barcode. The goal is to rearrange these integers such that no two adjacent integers are the same.
- **Example:** `Input: barcodes = [4, 4, 7, 7, 8, 8]`
- **Constraints:**
	- 1 <= barcodes.length <= 10,000
	- 1 <= barcodes[i] <= 10,000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of integers, where no two adjacent integers are the same. The arrangement should be a valid permutation of the input array.
- **Example:** `Output: [7, 4, 7, 4, 8, 8]`
- **Constraints:**
	- The output must be a valid permutation of the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rearrange the given barcodes such that no two adjacent barcodes are identical.

- 1. Count the frequency of each barcode in the array.
- 2. Use a greedy approach to place the most frequent barcode in the array first, alternating the placement to ensure no two adjacent barcodes are the same.
- 3. Fill in the remaining barcodes, ensuring the same rule is followed.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains at least one barcode.
- The solution always exists, as guaranteed by the problem statement.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: barcodes = [4, 4, 7, 7, 8, 8]`  \
  **Explanation:** The most frequent barcode is 4, so it is placed in alternating positions. After filling the array with 4s, the remaining 7s and 8s are placed in the remaining positions. The output is [7, 4, 7, 4, 8, 8].

- **Input:** `Input: barcodes = [1, 1, 1, 2, 2, 3]`  \
  **Explanation:** The most frequent barcode is 1, so we start by placing 1 in alternating positions. Then, we place the remaining 2s and 3 in the remaining spots. The output is [1, 2, 1, 2, 1, 3].

{{< dots >}}
## Approach 🚀
The approach involves counting the frequency of each barcode, sorting them in descending order, and placing them in the output array by alternating between positions to ensure no adjacent barcodes are the same.

### Initial Thoughts 💭
- We need to consider the frequency of barcodes to ensure that the most frequent ones are placed first.
- The problem can be solved by sorting the barcodes by frequency and then greedily placing the most frequent barcode in available positions.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs because the array will always contain at least one barcode.
- The algorithm must efficiently handle arrays with up to 10,000 elements.
- If there are only one or two unique barcodes, we need to ensure the arrangement is still valid with no adjacent duplicates.
- The solution is guaranteed to exist as stated in the problem description.
{{< dots >}}
## Code 💻
```cpp
vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
    unordered_map<int, int> mp;
    set<pair<int, int>> st;
    for(int num: b) mp[num]++;
    for(auto it: mp) st.insert({ it.second, it.first });
    for(auto it = st.rbegin(); it != st.rend(); it++) {
        for(auto cnt = 0; cnt < it->first; cnt++, pos += 2) {
            if(pos >= b.size()) pos  = 1;
            b[pos] = it->second;
        }
    }
    return b;
}
```

The code provides a solution for rearranging barcodes such that no two adjacent barcodes are the same. It uses a map to count frequencies and a set to sort them by frequency, placing them alternately in the result array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
	```
	This line defines the function `rearrangeBarcodes` which takes a reference to a vector of integers `b` and an optional integer parameter `pos` (default value 0). The function aims to rearrange the elements of the vector `b` based on the barcode rearranging logic.

2. **Variable Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	An unordered map `mp` is initialized to store the frequency of each number in the barcode array `b`. The key is the barcode number, and the value is its frequency.

3. **Variable Initialization**
	```cpp
	    set<pair<int, int>> st;
	```
	A set `st` is initialized to store pairs of integers, where the first element of the pair is the frequency of a barcode, and the second is the barcode number itself. The set ensures the elements are ordered by frequency in descending order.

4. **Frequency Count**
	```cpp
	    for(int num: b) mp[num]++;
	```
	This loop iterates through the vector `b`, counting the frequency of each barcode and storing it in the unordered map `mp`.

5. **Sorting by Frequency**
	```cpp
	    for(auto it: mp) st.insert({ it.second, it.first });
	```
	This loop iterates over the map `mp` and inserts each barcode along with its frequency as a pair into the set `st`. The set will automatically order the pairs by the frequency in descending order.

6. **Descending Loop**
	```cpp
	    for(auto it = st.rbegin(); it != st.rend(); it++) {
	```
	This loop iterates through the set `st` in reverse order (from the most frequent to the least frequent barcode), using a reverse iterator `rbegin()` and `rend()`.

7. **Placement Logic**
	```cpp
	        for(auto cnt = 0; cnt < it->first; cnt++, pos += 2) {
	```
	This inner loop places the barcodes into the vector `b`. It runs for the frequency of the current barcode (`it->first`). It also increments `pos` by 2 to ensure that the barcodes are placed in alternate positions.

8. **Edge Case Handling**
	```cpp
	            if(pos >= b.size()) pos  = 1;
	```
	This condition checks if `pos` exceeds the size of the vector `b`. If it does, `pos` is reset to 1, ensuring that the placement continues from the second position (odd indices).

9. **Barcode Assignment**
	```cpp
	            b[pos] = it->second;
	```
	The barcode `it->second` (which is the barcode number) is assigned to the position `pos` in the vector `b`.

10. **Return Statement**
	```cpp
	    return b;
	```
	The function returns the modified vector `b` with the rearranged barcodes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step, followed by a linear scan to fill the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we use additional space for counting the frequency of each barcode.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/distant-barcodes/description/)

---
{{< youtube MlgCCJ7MfKQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
