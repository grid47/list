
+++
authors = ["grid47"]
title = "Leetcode 2022: Convert 1D Array Into 2D Array"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2022: Convert 1D Array Into 2D Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "l-VLzZ2riTc"
youtube_upload_date="2024-09-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/l-VLzZ2riTc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        
        vector<vector<int>> res;
        for (int i = 0; i < m*n; i+=n)
            res.push_back(vector<int>(original.begin()+i, original.begin()+i+n));
            
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to transform a one-dimensional array into a two-dimensional array with specified dimensions. Given an array named `original` and two integers `m` and `n`, the task is to check if it is possible to reshape the array into a two-dimensional array with `m` rows and `n` columns. If it is possible, the function should return the new 2D array; otherwise, it should return an empty array. This operation is commonly known as "reshaping an array."

### Approach

To solve this problem, we can follow these steps:

1. **Check the Dimensions**: First, we need to ensure that the total number of elements in the original array is equal to the product of `m` and `n`. If this condition is not met, it is impossible to reshape the array, and we should return an empty array.

2. **Constructing the 2D Array**: If the dimensions are valid, we will create a new 2D vector that will hold `m` rows, each containing `n` columns. We can achieve this by iterating through the `original` array and filling the new 2D vector with the appropriate elements.

3. **Return the Result**: Finally, we return the newly constructed 2D array.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

```cpp
class Solution {
```
- The `Solution` class encapsulates the method we will use to perform the array reshaping.

```cpp
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
```
- We define a public method `construct2DArray` that takes three parameters: a reference to a vector of integers `original`, and two integers `m` and `n`, representing the desired dimensions of the new 2D array.

```cpp
        if (m * n != original.size()) return {};
```
- The first step in the method is to check if the total number of elements (`m * n`) matches the size of the `original` array. If they do not match, it is impossible to reshape the array, so we return an empty vector (`{}`).

```cpp
        vector<vector<int>> res;
```
- If the sizes match, we create a 2D vector `res` that will hold the resulting array.

```cpp
        for (int i = 0; i < m*n; i+=n)
```
- We then start a loop that will iterate through the `original` array. The loop index `i` will range from `0` to `m*n`, incrementing by `n` with each iteration. This allows us to pick segments of the `original` array corresponding to the rows of the new 2D array.

```cpp
            res.push_back(vector<int>(original.begin()+i, original.begin()+i+n));
```
- Inside the loop, we create a new row of the 2D array by constructing a vector from a segment of the `original` array. Specifically, we use `original.begin() + i` as the starting point and `original.begin() + i + n` as the endpoint to extract the next `n` elements. This new vector is then added to the `res` 2D vector.

```cpp
        return res;
    }
};
```
- After the loop completes, we return the constructed 2D array `res`, which now contains `m` rows and `n` columns populated with the elements from the `original` array.

### Complexity

- **Time Complexity**: The time complexity of this solution is O(m * n), as we iterate through the original array and fill the new 2D array, which requires visiting each element once.
- **Space Complexity**: The space complexity is also O(m * n) because we are storing the newly constructed 2D array, which contains the same number of elements as the original array.

### Conclusion

In summary, the `construct2DArray` method provides a straightforward and efficient way to reshape a one-dimensional array into a two-dimensional array given specific dimensions. The key aspects of the implementation include checking the validity of the reshape operation, constructing the new array using a loop, and utilizing C++ STL features such as vector initializers.

This solution not only adheres to good coding practices but also ensures that it handles edge cases gracefully. By returning an empty vector when the reshape is not feasible, it maintains clarity and predictability in its behavior. The use of vector operations simplifies memory management and enhances readability, making this implementation a robust example for similar array manipulation tasks in programming challenges and real-world applications.

[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-1d-array-into-2d-array/description/)

---
{{< youtube l-VLzZ2riTc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
