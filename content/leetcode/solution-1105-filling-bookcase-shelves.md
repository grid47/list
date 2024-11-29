
+++
authors = ["grid47"]
title = "Leetcode 1105: Filling Bookcase Shelves"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1105: Filling Bookcase Shelves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lFYPPPTp8qE"
youtube_upload_date="2024-07-31"
youtube_thumbnail="https://i.ytimg.com/vi/lFYPPPTp8qE/maxresdefault.jpg"
comments = true
+++



---
You are given an array of books where each book is represented by a pair of integers [thickness, height]. Additionally, you have a shelf with a fixed width. Your goal is to arrange the books on the shelves such that each shelf's total thickness is less than or equal to the shelf width, and the height of each shelf is determined by the tallest book placed on it. The books must be placed in the same order as they appear in the input array. The objective is to minimize the total height of the bookshelf.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `books` where each element is a pair `[thickness, height]` indicating the thickness and height of a book. You are also given an integer `shelfWidth`, which represents the width of the shelf.
- **Example:** `books = [[1, 2], [3, 5], [2, 2], [1, 3]], shelfWidth = 6`
- **Constraints:**
	- 1 <= books.length <= 1000
	- 1 <= thicknessi <= shelfWidth <= 1000
	- 1 <= heighti <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the minimum possible height of the bookshelf after placing all the books on the shelves.
- **Example:** `Output: 8`
- **Constraints:**
	- The books must be placed in the same order as they appear in the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the total height of the bookshelf by optimally placing books onto the shelves.

- Start with an empty bookshelf and iterate over the books.
- For each book, check if it can be placed on the current shelf without exceeding the shelf width. If yes, place it on the shelf.
- If the book cannot fit, start a new shelf, keeping track of the height of the tallest book on each shelf.
- At each step, keep track of the total height of the bookshelf.
{{< dots >}}
### Problem Assumptions ✅
- All input values are within the defined constraints.
- The books must be placed on the shelf in the order given.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: books = [[1, 2], [3, 5], [2, 2], [1, 3]], shelfWidth = 6`  \
  **Explanation:** In this example, the first shelf can hold books [1, 2] and [3, 5] because their combined thickness is 4, which is less than the shelfWidth of 6. The second shelf holds books [2, 2] and [1, 3] with a combined thickness of 3. The final height is 8 (2 from the first shelf, and 5 from the second shelf).

{{< dots >}}
## Approach 🚀
To minimize the total height of the bookshelf, we need to dynamically compute the best way to arrange the books while respecting the width constraints of the shelf.

### Initial Thoughts 💭
- We need to calculate the height of the bookshelf after arranging all the books.
- This is a dynamic programming problem where we keep track of the height of the bookshelf at each step.
- Start with the first book and place books on the shelf until you cannot fit another book. Once the shelf is full, move to the next shelf and repeat the process.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees at least one book, so no need to handle empty inputs.
- The solution should be efficient enough to handle large inputs, such as arrays with 1000 books.
- If there is only one book, it will occupy a single shelf, and the height will be the book's height.
- The total thickness of the books should not exceed the `shelfWidth` at any point on a shelf.
{{< dots >}}
## Code 💻
```cpp
int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int n = books.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + books[i][1];
        int sum = 0, height = 0;
        for(int j = i; j >= 0; j--) {
            sum += books[j][0];
            if(sum > shelfWidth) break;
            else {
                height = max(height, books[j][1]);
                dp[i + 1] = min(dp[j] + height, dp[i+1]);
            }
        }
    }
    return dp[n];        
}
```

This is the solution for the problem of determining the minimum height of shelves required to store books with specified widths and heights. It uses dynamic programming (DP) to keep track of the minimum height required for each configuration of books.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
	```
	The function `minHeightShelves` takes a 2D vector `books`, where each element contains the width and height of a book, and an integer `shelfWidth` that specifies the maximum width of a shelf. It returns the minimum total height required to arrange all books.

2. **Variable Declaration**
	```cpp
	    int n = books.size();
	```
	The variable `n` is initialized to the number of books, representing the total number of elements in the `books` vector.

3. **Dynamic Programming Array**
	```cpp
	    vector<int> dp(n + 1, 0);
	```
	The dynamic programming array `dp` is initialized to store the minimum height required to arrange books from 0 to `i`. It has a size of `n + 1` to handle the base case.

4. **Base Case Initialization**
	```cpp
	    dp[0] = 0;
	```
	The base case is initialized by setting `dp[0] = 0`, indicating that if no books are placed on shelves, the height is 0.

5. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop starts from `i = 0` and iterates over each book in the `books` vector to calculate the minimum height required to arrange books from the start up to book `i`.

6. **Initial Height Calculation**
	```cpp
	        dp[i + 1] = dp[i] + books[i][1];
	```
	Initially, the height required for placing book `i` on a new shelf is set to the height of the previous shelf (`dp[i]`) plus the height of the current book.

7. **Sum and Height Variables**
	```cpp
	        int sum = 0, height = 0;
	```
	Two variables are initialized: `sum` to track the total width of books placed on the current shelf, and `height` to track the maximum height of books on the shelf.

8. **Inner Loop Start**
	```cpp
	        for(int j = i; j >= 0; j--) {
	```
	An inner loop starts from `i` and iterates backwards through the books, calculating the possible configurations of books on the current shelf.

9. **Width Accumulation**
	```cpp
	            sum += books[j][0];
	```
	The width of the book at index `j` is added to the `sum` variable to calculate the total width of the books placed on the current shelf.

10. **Width Check**
	```cpp
	            if(sum > shelfWidth) break;
	```
	If the total width `sum` exceeds the shelf width `shelfWidth`, the loop breaks because no more books can fit on the current shelf.

11. **Height Update**
	```cpp
	            else {
	```
	If the current configuration of books fits on the shelf, the maximum height of the books on the shelf is updated.

12. **Max Height Calculation**
	```cpp
	                height = max(height, books[j][1]);
	```
	The `height` variable is updated to be the maximum of the current `height` and the height of the book at index `j`.

13. **Dynamic Programming Update**
	```cpp
	                dp[i + 1] = min(dp[j] + height, dp[i+1]);
	```
	The DP array is updated by comparing the current minimum height with the new height calculated by placing the books from `j` to `i` on the same shelf.

14. **Return Statement**
	```cpp
	    return dp[n];
	```
	The function returns the minimum height required to store all books, which is stored in `dp[n]` after the loops complete.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to the dynamic programming approach where for each book, we check all previous books to calculate the optimal placement.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we use a dynamic programming array to store the minimum heights for up to `n` books.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/filling-bookcase-shelves/description/)

---
{{< youtube lFYPPPTp8qE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
