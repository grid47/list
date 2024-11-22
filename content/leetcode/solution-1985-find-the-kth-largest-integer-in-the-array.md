
+++
authors = ["grid47"]
title = "Leetcode 1985: Find the Kth Largest Integer in the Array"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1985: Find the Kth Largest Integer in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Divide and Conquer","Sorting","Heap (Priority Queue)","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lRCaNiqO3xI"
youtube_upload_date="2021-08-29"
youtube_thumbnail="https://i.ytimg.com/vi/lRCaNiqO3xI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class cmp {
   
public:
    bool operator () (string &b, string &a) {
        
        if (a.size() != b.size())
            return a.length() < b.length();
        
        return a < b;
        
    }
    
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> pq;
        for(int i = 0; i < nums.size(); i++) {
            
            pq.push(nums[i]);
            while(pq.size() > k) {
                pq.pop();
            }


        }
        
        return pq.top();
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the k-th largest number from a list of numbers represented as strings. Given the nature of string comparison, where numbers of different lengths do not directly compare in value when treated as strings, we need a method to compare and sort them accurately. The goal is to efficiently determine the k-th largest string representation of a number from the input list.

### Approach

To solve this problem, we will use a **priority queue** (or a max-heap) that allows us to efficiently manage the top k largest elements. The main steps of the approach are as follows:

1. **Custom Comparator**: Implement a custom comparator to ensure that strings are compared based on their numeric value rather than their lexicographic order. This is important since '100' is larger than '99' but would be incorrectly evaluated if compared purely as strings.
  
2. **Priority Queue**: Use a max-heap to store the k largest numbers found so far. As we iterate through the list of numbers, we will keep the size of the heap to k, ensuring that it only contains the k largest elements.

3. **Iterate and Push**: For each number in the input, we push it onto the heap. If the heap size exceeds k, we remove the smallest element (which would be at the top of the heap).

4. **Return Result**: Once all numbers are processed, the top of the heap will contain the k-th largest number.

### Code Breakdown (Step by Step)

```cpp
class cmp {
public:
    bool operator () (string &b, string &a) {
```
Here we define a custom comparator class `cmp` that overloads the `operator()` to compare two strings, `a` and `b`.

```cpp
        if (a.size() != b.size())
            return a.length() < b.length();
        
        return a < b;
```
In the comparator, we first compare the lengths of the strings. If they are not of the same length, we consider the longer string to be greater. If they are of the same length, we perform a lexicographic comparison.

```cpp
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
```
The `Solution` class defines a method `kthLargestNumber` which takes a vector of strings (`nums`) and an integer (`k`).

```cpp
        priority_queue<string, vector<string>, cmp> pq;
```
We declare a max-heap priority queue `pq` using our custom comparator `cmp`.

```cpp
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
```
We iterate through each number in `nums`, pushing each number onto the priority queue.

```cpp
            while(pq.size() > k) {
                pq.pop();
            }
```
If the size of the priority queue exceeds k, we pop the smallest element, ensuring that the queue maintains only the k largest numbers.

```cpp
        }
        
        return pq.top();
    }
};
```
After processing all numbers, we return the top element of the priority queue, which is the k-th largest number.

### Complexity

- **Time Complexity**: 
  - Pushing an element onto the priority queue takes \(O(\log k)\) time, and we do this for \(n\) elements, leading to a total time complexity of \(O(n \log k)\). 
  - The maximum size of the priority queue is \(k\), so the operations on the heap remain efficient.

- **Space Complexity**: The space complexity is \(O(k)\) due to the storage of up to k elements in the priority queue.

### Conclusion

The solution efficiently finds the k-th largest number represented as a string by leveraging a custom comparator and a priority queue. This approach ensures that we accurately account for numeric values even when represented as strings, thus providing an effective solution to the problem.

### Example Usage

Here's an example of how you can utilize the `kthLargestNumber` method:

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Solution sol;
    vector<string> nums = {"3", "6", "7", "10", "2", "5"};
    int k = 3;
    string result = sol.kthLargestNumber(nums, k);
    cout << "The " << k << "-th largest number is: " << result << endl; // Example output
    return 0;
}
```

### Potential Improvements

1. **Input Validation**: Additional checks can be introduced to handle edge cases, such as when `k` is greater than the size of the input vector or when the input vector is empty.

2. **Custom Data Structures**: If the list of numbers is very large and k is small, other data structures like sorted lists or binary search trees could be explored for potentially better performance.

3. **Memory Optimization**: The implementation could be further optimized in terms of memory if required, especially if the maximum number of strings is known and fixed.

This solution effectively balances clarity, efficiency, and correctness, making it a good candidate for competitive programming challenges where performance is essential.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/)

---
{{< youtube lRCaNiqO3xI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
