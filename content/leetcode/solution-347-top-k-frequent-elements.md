
+++
authors = ["grid47"]
title = "Leetcode 347: Top K Frequent Elements"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 347: Top K Frequent Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Sorting","Heap (Priority Queue)","Bucket Sort","Counting","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/347.webp"
youtube = "jFZx4Q7UL5c"
youtube_upload_date="2023-05-22"
youtube_thumbnail="https://i.ytimg.com/vi/jFZx4Q7UL5c/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/347.webp" 
    alt="A sequence of elements where the most frequent ones glow brightly, showing the top K frequencies."
    caption="Solution to LeetCode 347: Top K Frequent Elements Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array nums and an integer k, return the k most frequent elements from the array. The answer may be returned in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer k.
- **Example:** `nums = [4,4,4,5,5,6], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- -10^4 <= nums[i] <= 10^4
	- k is in the range [1, the number of unique elements in the array]
	- It is guaranteed that the answer is unique

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array containing the k most frequent elements from the input array nums.
- **Example:** `[4, 5]`
- **Constraints:**
	- The answer can be returned in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find and return the k most frequent elements from the input array.

- Count the frequency of each element in the array using a map or hash table.
- Use a priority queue (max heap) to store the elements sorted by their frequency.
- Pop the k most frequent elements from the priority queue.
{{< dots >}}
### Problem Assumptions ✅
- The input is a valid array of integers, and the value of k is within the expected range.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4,4,4,5,5,6], k = 2`  \
  **Explanation:** The most frequent elements are 4 and 5, with 4 appearing 3 times and 5 appearing 2 times. Thus, the output is [4, 5].

- **Input:** `nums = [7], k = 1`  \
  **Explanation:** Since there is only one element, the most frequent element is 7, and the output is [7].

{{< dots >}}
## Approach 🚀
The solution involves counting the frequency of each element and retrieving the k most frequent elements using a heap.

### Initial Thoughts 💭
- We need to count the frequency of each element efficiently and then select the k most frequent ones.
- A priority queue can be used to store the elements by frequency, ensuring that we can extract the top k most frequent ones efficiently.
{{< dots >}}
### Edge Cases 🌐
- An empty array would not be a valid input as per the constraints.
- The solution should handle arrays with a length up to 100,000 efficiently.
- If the array has only one unique element, that element should be returned as the most frequent.
- The solution must be efficient enough to handle the upper bounds of the input size.
{{< dots >}}
## Code 💻
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> ma;
    for(int x: nums)
        ma[x]++;
    
    priority_queue<pair<int, int>> pq;
    
    for(auto [key, val]: ma)
        pq.push(make_pair(val, key));
    
    vector<int> ans;
    while(k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
```

This function returns the k most frequent elements in the input list `nums`. It counts the frequency of each element using a map, then uses a priority queue to order elements by frequency and returns the top k elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> topKFrequent(vector<int>& nums, int k) {
	```
	The function `topKFrequent` takes a reference to a vector of integers `nums` and an integer `k`, and returns a vector of the `k` most frequent elements from `nums`.

2. **Map Declaration**
	```cpp
	    map<int, int> ma;
	```
	Declare a map `ma` where the key is an integer from `nums` and the value is its frequency count.

3. **Loop Over Input**
	```cpp
	    for(int x: nums)
	```
	Iterate over each element `x` in the input vector `nums`.

4. **Frequency Count**
	```cpp
	        ma[x]++;
	```
	For each element `x`, increment its frequency count in the map `ma`.

5. **Priority Queue Declaration**
	```cpp
	    priority_queue<pair<int, int>> pq;
	```
	Declare a priority queue `pq` of pairs where each pair consists of an integer (frequency) and an integer (element). This will be used to sort the elements by their frequencies.

6. **Map Iteration**
	```cpp
	    for(auto [key, val]: ma)
	```
	Iterate through the map `ma`, where `key` is the element and `val` is its frequency.

7. **Push to Priority Queue**
	```cpp
	        pq.push(make_pair(val, key));
	```
	Push each element-frequency pair to the priority queue. Elements with higher frequencies will be prioritized.

8. **Result Vector Declaration**
	```cpp
	    vector<int> ans;
	```
	Declare an empty vector `ans` to store the top `k` frequent elements.

9. **While Loop**
	```cpp
	    while(k--) {
	```
	The loop runs `k` times, extracting the top `k` frequent elements from the priority queue.

10. **Push Top Element to Result**
	```cpp
	        ans.push_back(pq.top().second);
	```
	Push the element (second value of the top pair) from the priority queue to the result vector `ans`.

11. **Pop Top Element from Queue**
	```cpp
	        pq.pop();
	```
	Remove the top element from the priority queue.

12. **Return Result**
	```cpp
	    return ans;
	```
	Return the vector `ans` containing the `k` most frequent elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log k)
- **Worst Case:** O(n log k)

The time complexity is O(n) for counting the frequencies, and O(log k) for each insertion and extraction from the priority queue, resulting in a total time complexity of O(n log k).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the frequency count of each element in the map and the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/top-k-frequent-elements/description/)

---
{{< youtube jFZx4Q7UL5c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
