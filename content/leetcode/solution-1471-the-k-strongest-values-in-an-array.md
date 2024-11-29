
+++
authors = ["grid47"]
title = "Leetcode 1471: The k Strongest Values in an Array"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1471: The k Strongest Values in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "5Hie-4QPNtI"
youtube_upload_date="2020-06-07"
youtube_thumbnail="https://i.ytimg.com/vi/5Hie-4QPNtI/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers and an integer k, you need to find the strongest k elements in the array. The strength of each element is determined by how far it is from the median of the array. If two elements are equidistant from the median, the larger element is considered stronger. Return the k strongest elements in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers and an integer k.
- **Example:** `Input: arr = [4, 8, 1, 6, 3], k = 3`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- -10^5 <= arr[i] <= 10^5
	- 1 <= k <= arr.length

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of the k strongest elements from the array, sorted by strength. If two elements are equally strong, the larger one comes first.
- **Example:** `Output: [8, 6, 4]`
- **Constraints:**
	- The answer can be returned in any arbitrary order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the strongest k elements by comparing the distance of each element from the median and resolving ties based on the element's value.

- Sort the array to calculate the median.
- Calculate the strength of each element as the absolute difference from the median.
- If two elements have the same strength, the larger element is considered stronger.
- Use a priority queue to efficiently extract the k strongest elements.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that all inputs are valid and that the array contains at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [4, 8, 1, 6, 3], k = 3`  \
  **Explanation:** The median of the array is 4, so the elements sorted by their distance from the median are [8, 6, 4, 3, 1]. The strongest 3 elements are [8, 6, 4].

- **Input:** `Input: arr = [1, 1, 2, 3, 3], k = 2`  \
  **Explanation:** The median of the array is 2. The elements sorted by their strength are [3, 3, 1, 1, 2]. The strongest 2 elements are [3, 3].

{{< dots >}}
## Approach 🚀
The problem involves finding the k strongest elements by first sorting the array to calculate the median and then sorting the elements based on their distance from the median.

### Initial Thoughts 💭
- The median can be calculated by sorting the array.
- The strength of each element is defined as the absolute difference between the element and the median.
- After calculating the strength, we can sort the array based on strength and return the top k elements.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least one element, so there is no need to handle empty arrays.
- For large inputs, the solution needs to efficiently calculate the strength of each element and extract the strongest k elements.
- If all elements are the same, the strongest elements will be the largest values based on the number of occurrences.
- The input size can go up to 10^5, so the solution must be optimized for time efficiency.
{{< dots >}}
## Code 💻
```cpp
vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    float m;
    if(n & 1) {
        m = arr[n / 2];
    } else {
        m = arr[n/2-1];
    }
    priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> pq;
    
    for(int i = 0; i < n; i++) {
        // cout << abs(arr[i] - m) << " " << arr[i] << " ";
        pq.push({abs(arr[i] - m), arr[i]});
    }
    vector<int> res;
    while(k--) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
```

The provided solution solves the problem of finding the strongest `k` elements in the array. It uses sorting to identify the median and a priority queue to efficiently select the strongest elements based on their distance from the median.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> getStrongest(vector<int>& arr, int k) {
	```
	This line defines the function `getStrongest` which takes an integer vector `arr` and an integer `k` as inputs, and returns a vector of the `k` strongest integers.

2. **Sorting**
	```cpp
	    sort(arr.begin(), arr.end());
	```
	This line sorts the input array `arr` in ascending order.

3. **Variable Initialization**
	```cpp
	    int n = arr.size();
	```
	This line initializes the variable `n` to the size of the sorted array.

4. **Variable Declaration**
	```cpp
	    float m;
	```
	A float variable `m` is declared to store the median value of the array.

5. **Conditional Expression**
	```cpp
	    if(n & 1) {
	```
	This checks if the number of elements `n` is odd by using the bitwise AND operation.

6. **Median Calculation**
	```cpp
	        m = arr[n / 2];
	```
	If `n` is odd, the median value `m` is set to the middle element of the sorted array.

7. **Median Calculation**
	```cpp
	    } else {
	```
	This part handles the case when `n` is even.

8. **Median Calculation**
	```cpp
	        m = arr[n/2-1];
	```
	If `n` is even, the median is taken as the element just before the middle.

9. **Priority Queue Initialization**
	```cpp
	    priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> pq;
	```
	This line declares a priority queue `pq` which stores pairs of float values (representing the absolute difference from the median) and integers (the array elements).

10. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates through each element of the sorted array to calculate its distance from the median.

11. **Priority Queue Push**
	```cpp
	        pq.push({abs(arr[i] - m), arr[i]});
	```
	This pushes each element and its absolute difference from the median into the priority queue.

12. **Result Vector Declaration**
	```cpp
	    vector<int> res;
	```
	This line initializes an empty vector `res` to store the `k` strongest elements.

13. **While Loop**
	```cpp
	    while(k--) {
	```
	This while loop continues until `k` strongest elements are selected.

14. **Result Collection**
	```cpp
	        res.push_back(pq.top().second);
	```
	This line pops the top element from the priority queue and adds its second value (the original array element) to the result vector.

15. **Priority Queue Pop**
	```cpp
	        pq.pop();
	```
	This line removes the top element from the priority queue after it has been added to the result vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n). Calculating the strength of each element and extracting the k strongest elements both take linear time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the input array and the priority queue used for sorting the elements by strength.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-k-strongest-values-in-an-array/description/)

---
{{< youtube 5Hie-4QPNtI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
