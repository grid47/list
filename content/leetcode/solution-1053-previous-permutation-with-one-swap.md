
+++
authors = ["grid47"]
title = "Leetcode 1053: Previous Permutation With One Swap"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1053: Previous Permutation With One Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "x_y3nIsbENM"
youtube_upload_date="2021-03-01"
youtube_thumbnail="https://i.ytimg.com/vi/x_y3nIsbENM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int idx = -1, n = arr.size();
        for(int i = n - 1; i > 0; i--) {
            // cout<< arr[i] << " " << arr[i - 1] << '\n';
            if(arr[i] < arr[i - 1]) {
                idx = i - 1;
                break;
            }
        }
        // cout << idx;
        if(idx == -1) return arr;

        for(int i = n - 1; i > idx; i--) {
            if(arr[i] < arr[idx] && arr[i] != arr[i - 1]) {
                swap(arr[i], arr[idx]);
                break;
            }
        }
        return arr;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to implement a function that returns the previous permutation of a given array of integers. A permutation is considered "previous" if it is the largest permutation that is smaller than the current one in lexicographical order. If the current permutation is the smallest, the function should return the same array as no previous permutation exists.

### Approach
The approach to solve this problem involves the following steps:
1. Traverse the array from right to left to find the first pair of indices where the left element is greater than the right element. This identifies the point at which the current permutation can be modified to create a smaller permutation.
2. Once the point of modification is found, search again from the right end of the array to find the largest element that is smaller than the identified element at the left index. 
3. Swap these two elements to create the previous permutation.
4. Return the modified array.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   The function `prevPermOpt1` is defined to take a vector of integers `arr` and return a vector of integers.

   ```cpp
   vector<int> prevPermOpt1(vector<int>& arr) {
   ```

2. **Variable Initialization**:
   We initialize `idx` to `-1` to hold the index where we can make the swap and `n` to the size of the array.

   ```cpp
   int idx = -1, n = arr.size();
   ```

3. **Finding the Point of Modification**:
   We iterate from the end of the array towards the start (excluding the first element). If we find an index `i` such that `arr[i] < arr[i - 1]`, we set `idx` to `i - 1` and break the loop.

   ```cpp
   for(int i = n - 1; i > 0; i--) {
       if(arr[i] < arr[i - 1]) {
           idx = i - 1;
           break;
       }
   }
   ```

4. **Checking if No Modification is Needed**:
   If no index was found (i.e., `idx` remains `-1`), it means the array is sorted in non-increasing order, and we return the original array as there is no previous permutation.

   ```cpp
   if(idx == -1) return arr;
   ```

5. **Finding the Largest Smaller Element**:
   Next, we look for the largest element that is smaller than `arr[idx]` starting from the end of the array and moving left. We ensure that we do not swap with duplicates by checking if `arr[i]` is not equal to `arr[i - 1]`.

   ```cpp
   for(int i = n - 1; i > idx; i--) {
       if(arr[i] < arr[idx] && arr[i] != arr[i - 1]) {
           swap(arr[i], arr[idx]);
           break;
       }
   }
   ```

6. **Returning the Result**:
   Finally, the modified array is returned.

   ```cpp
   return arr;
   }
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the length of the input array. This is because we make a maximum of two passes through the array: one to find the index to modify and another to find the largest smaller element.
  
- **Space Complexity**: The space complexity is \(O(1)\) as we are using a constant amount of extra space for variables, and we are modifying the array in place.

### Conclusion
The `prevPermOpt1` function effectively identifies and generates the previous permutation of the array in linear time. By systematically searching for the appropriate indices to swap, the function guarantees that the result is the largest permutation smaller than the input, adhering to the constraints of permutation ordering.

This solution is particularly useful in scenarios where permutations are critical, such as in combinatorial algorithms or problems involving sequences where the arrangement matters. The approach demonstrates how to manipulate array elements efficiently while maintaining optimal performance.

Overall, this implementation provides a clear and effective method for achieving the desired outcome, making it a valuable addition to any algorithmic toolkit dealing with permutations and their properties.


[`Link to LeetCode Lab`](https://leetcode.com/problems/previous-permutation-with-one-swap/description/)

---
{{< youtube x_y3nIsbENM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
