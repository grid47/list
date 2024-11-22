
+++
authors = ["grid47"]
title = "Leetcode 519: Random Flip Matrix"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 519: Random Flip Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Reservoir Sampling","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/519.webp"
youtube = "9JsC0Dg9oX8"
youtube_upload_date="2024-09-13"
youtube_thumbnail="https://i.ytimg.com/vi/9JsC0Dg9oX8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/519.webp" 
    alt="A matrix where cells are randomly flipped, with each flipped cell softly glowing as it changes state."
    caption="Solution to LeetCode 519: Random Flip Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    map<int, int> mp;
    int row, col, lmt;
public:
    Solution(int m, int n) {
        row = m;
        col = n;
        reset();
    }
    
    vector<int> flip() {
        int idx = rand()%lmt;
        lmt--;
        int x = mp.count(idx)? mp[idx] : idx;
        mp[idx] = mp.count(lmt)? mp[lmt]: lmt;
        return vector<int>{x/col, x%col};
    }
    
    void reset() {
        mp.clear();
        lmt = row*col;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to design a solution that simulates flipping a coin in an `m x n` grid and allows for resetting the grid. The objective is to randomly select a cell in the grid and return its coordinates. Once a cell is selected, it cannot be selected again until the grid is reset. The problem requires implementing two primary operations:

1. **flip()**: Randomly selects a cell from the grid and returns its coordinates. Once a cell is selected, it should not be available for future flips until the grid is reset.
2. **reset()**: Resets the grid so that all cells are available for selection again.

This solution needs to be efficient in both time and space, ensuring that the grid can handle large sizes.

### Approach

The problem can be tackled using the **reservoir sampling** technique, which allows us to randomly select an item from a stream of data without needing to store all the elements. In this case, the grid's cells can be treated as a stream where each cell is randomly chosen for flipping.

We need to make the following considerations:
- The grid is a two-dimensional `m x n` matrix, but the cell positions can be represented as a one-dimensional array of size `m * n`.
- We need a way to map each grid cell to a unique index and efficiently track which cells have already been flipped.

#### Key Concepts:
1. **Indexing the Grid**: The grid's rows and columns can be flattened into a single array with the formula `index = row * n + col`, where `row` and `col` are the row and column indices of the cell.
2. **Efficient Random Selection**: We can use the `rand()` function to randomly select an index in the range `[0, m * n - 1]`.
3. **Efficient Tracking of Flipped Cells**: A `map` (or hash map) can be used to store the mapping between flipped indices and remaining unflipped indices.

Using the **reservoir sampling** method, each index is selected with equal probability, and once selected, it is swapped with another unflipped index. The `flip()` operation can then return the coordinates of the randomly selected cell.

### Code Breakdown (Step by Step)

Let’s break down the implementation of this solution in detail:

#### 1. **Class Initialization**:
```cpp
class Solution {
    map<int, int> mp;
    int row, col, lmt;
public:
    Solution(int m, int n) {
        row = m;
        col = n;
        reset();
    }
```
- **`mp`**: A map to store the mapping between the flipped index and the remaining unflipped index.
- **`row`** and **`col`**: Store the number of rows and columns in the grid.
- **`lmt`**: The remaining number of cells that can be flipped, initialized to `m * n` (the total number of cells).

The constructor initializes the grid with `m` rows and `n` columns and calls the `reset()` function to prepare the grid for flipping.

#### 2. **flip() Method**:
```cpp
    vector<int> flip() {
        int idx = rand() % lmt; // Generate a random index
        lmt--; // Decrease the limit of remaining cells
        int x = mp.count(idx) ? mp[idx] : idx; // If the index is already flipped, get the mapped value
        mp[idx] = mp.count(lmt) ? mp[lmt] : lmt; // Map the last available index to the current one
        return vector<int>{x / col, x % col}; // Return the coordinates of the selected cell
    }
```
- **Random Index**: We randomly generate an index `idx` between `0` and `lmt - 1` using `rand() % lmt`. This ensures that each cell is selected with equal probability.
- **Mapping Flipped Cells**: If the index `idx` has already been flipped (it is found in the map `mp`), the value at `mp[idx]` is returned, indicating the index that has replaced it.
- **Mapping the Last Cell**: We then update the map to ensure that the last available cell (`lmt`) is mapped to the flipped cell `idx`. This ensures that once a cell is flipped, it’s not available again.
- **Return Coordinates**: The randomly selected index `x` is then converted to row and column coordinates using integer division and modulo operations: `x / col` gives the row, and `x % col` gives the column. These coordinates are returned as a vector of integers.

#### 3. **reset() Method**:
```cpp
    void reset() {
        mp.clear(); // Clear the map of flipped indices
        lmt = row * col; // Reset the limit to the total number of cells in the grid
    }
};
```
- **Clear the Map**: The `mp.clear()` method clears the map that tracks the flipped cells.
- **Reset the Limit**: The `lmt` variable is reset to the total number of cells in the grid (`row * col`), ensuring that all cells are available for flipping once the grid is reset.

#### 4. **Usage**:
```cpp
Solution* obj = new Solution(m, n);
vector<int> param_1 = obj->flip();
obj->reset();
```
- **Initialization**: A new instance of the `Solution` class is created with `m` rows and `n` columns.
- **Flipping**: The `flip()` method is called to randomly select a cell and return its coordinates.
- **Resetting**: The `reset()` method is called to reset the grid, making all cells available again.

### Complexity

#### Time Complexity:
- **flip() Method**: The `flip()` method involves a constant time operation of generating a random index (`rand() % lmt`), checking if the index has been flipped (`mp.count(idx)`), and updating the map (`mp[idx] = ...`). These operations are all **O(1)**, meaning the `flip()` operation runs in constant time.
- **reset() Method**: The `reset()` method clears the map and resets the limit, both of which are also **O(1)** operations.
  
Thus, both `flip()` and `reset()` methods have a time complexity of **O(1)**.

#### Space Complexity:
- The space complexity is determined by the map `mp`, which stores the flipped indices. In the worst case, all the cells could be flipped before a reset is performed, resulting in **O(m * n)** space for the map. Therefore, the space complexity of the solution is **O(m * n)**.

### Conclusion

This solution provides an efficient implementation of a random flip and reset mechanism for a grid of size `m x n`. The `flip()` operation works in constant time, and the `reset()` operation resets the grid in constant time as well. The use of a map ensures that flipped cells are tracked efficiently, and the random sampling approach ensures that each cell is selected with equal probability.

The overall time complexity for both `flip()` and `reset()` is **O(1)**, making the solution very efficient for large grids. The space complexity is **O(m * n)** due to the need to track flipped cells, which is acceptable for typical input sizes.

This approach efficiently handles the problem while maintaining optimal performance and simplicity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/random-flip-matrix/description/)

---
{{< youtube 9JsC0Dg9oX8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
