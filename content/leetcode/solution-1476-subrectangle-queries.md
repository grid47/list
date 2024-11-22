
+++
authors = ["grid47"]
title = "Leetcode 1476: Subrectangle Queries"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1476: Subrectangle Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Design","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cMBkZMNVDdE"
youtube_upload_date="2020-06-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/cMBkZMNVDdE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class SubrectangleQueries {
public:
    vector<vector<int>> rec;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i++)
        for(int j = col1; j <= col2; j++)
            rec[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
{{< /highlight >}}
---

### Problem Statement

The problem is to implement a class `SubrectangleQueries` that manages a rectangular grid of integers (a 2D array) with the ability to update values in a specific subrectangle and retrieve the value at any given cell. The operations include:
1. **Updating a Subrectangle**: Changing all the values within a specified subrectangle to a new value.
2. **Getting a Value**: Retrieving the value at a specific position in the rectangle.

### Approach

To solve this problem, we can utilize a straightforward approach using a 2D vector to represent the rectangle. The core idea is to maintain the rectangle as a member variable and implement two primary methods:

1. **Update Method**: This method iterates over the specified subrectangle and updates all the elements to the new value.
2. **Get Value Method**: This method directly accesses the rectangle to retrieve the value at the specified coordinates.

Given that the updates can involve multiple elements, the update method operates in a nested loop, while the get value method directly accesses an element. This leads to an intuitive and simple implementation.

### Code Breakdown (Step by Step)

Here is the breakdown of the provided code:

1. **Class Declaration**:
   ```cpp
   class SubrectangleQueries {
   public:
   ```
   - The `SubrectangleQueries` class is defined to encapsulate the functionality of managing the rectangular grid.

2. **Member Variables**:
   ```cpp
   vector<vector<int>> rec;
   ```
   - A 2D vector `rec` is declared to store the values of the rectangle.

3. **Constructor**:
   ```cpp
   SubrectangleQueries(vector<vector<int>>& rectangle) {
       rec = rectangle;
   }
   ```
   - The constructor takes a 2D vector `rectangle` as an argument and initializes the member variable `rec` with this input. This sets up the initial state of the rectangle.

4. **Update Method**:
   ```cpp
   void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
       for(int i = row1; i <= row2; i++)
           for(int j = col1; j <= col2; j++)
               rec[i][j] = newValue;
   }
   ```
   - The `updateSubrectangle` method takes the corners of the subrectangle (defined by `(row1, col1)` and `(row2, col2)`) and the `newValue` to be assigned.
   - It uses two nested loops to iterate through each cell in the specified subrectangle and updates the value at each position to `newValue`.

5. **Get Value Method**:
   ```cpp
   int getValue(int row, int col) {
       return rec[row][col];
   }
   ```
   - The `getValue` method retrieves and returns the value from the rectangle at the specified coordinates `(row, col)`.

6. **Example Usage**:
   ```cpp
   /**
    * Your SubrectangleQueries object will be instantiated and called as such:
    * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
    * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
    * int param_2 = obj->getValue(row,col);
    */
   ```
   - This comment block illustrates how to instantiate the `SubrectangleQueries` object and use its methods. 

### Complexity

- **Time Complexity**:
  - The `updateSubrectangle` method runs in \(O((row2 - row1 + 1) \times (col2 - col1 + 1))\) time, as it iterates over every element in the specified subrectangle. In the worst case, this could cover all elements in the rectangle if the specified range encompasses the entire rectangle.
  - The `getValue` method runs in \(O(1)\) time, as it directly accesses a specific element in the rectangle.

- **Space Complexity**:
  - The space complexity is \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns in the rectangle, since we need to store the entire grid in the `rec` vector.

### Conclusion

The implementation of the `SubrectangleQueries` class effectively handles the required operations with a clear and intuitive approach. The use of a 2D vector to represent the rectangle allows for straightforward updates and retrievals of values. Key takeaways from this solution include:

1. **Simplicity**: The implementation is easy to understand and follow, making it suitable for those new to data structures and algorithms.

2. **Efficiency**: While the update operation may become costly for larger subrectangles, the overall design provides a good balance between functionality and complexity for typical use cases.

3. **Flexibility**: The solution can be easily extended or modified to incorporate additional features, such as more complex querying operations or different update strategies.

In conclusion, the `SubrectangleQueries` class serves as an excellent example of how to manage and manipulate a 2D data structure effectively, fulfilling the problem's requirements while maintaining clarity and efficiency.

[`Link to LeetCode Lab`](https://leetcode.com/problems/subrectangle-queries/description/)

---
{{< youtube cMBkZMNVDdE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
