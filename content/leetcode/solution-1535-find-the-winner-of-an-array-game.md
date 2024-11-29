
+++
authors = ["grid47"]
title = "Leetcode 1535: Find the Winner of an Array Game"
date = "2024-06-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1535: Find the Winner of an Array Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "v6On1TQfMTU"
youtube_upload_date="2020-08-04"
youtube_thumbnail="https://i.ytimg.com/vi/v6On1TQfMTU/maxresdefault.jpg"
comments = true
+++



---
You are given an array of distinct integers and an integer k. The game is played between the first two elements of the array. In each round, the larger integer wins and remains at position 0, while the smaller integer moves to the end of the array. The game ends when one integer wins k consecutive rounds. Your task is to return the integer that wins the game.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array arr and an integer k.
- **Example:** `arr = [4, 2, 6, 5, 3, 1], k = 3`
- **Constraints:**
	- 2 <= arr.length <= 10^5
	- 1 <= arr[i] <= 10^6
	- arr contains distinct integers.
	- 1 <= k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer that wins the game after winning k consecutive rounds.
- **Example:** `For arr = [4, 2, 6, 5, 3, 1] and k = 3, the output is 6.`
- **Constraints:**
	- The output is the integer that wins after k consecutive wins.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the integer that wins the game after k consecutive rounds.

- Compare the first two elements of the array, move the smaller one to the end, and repeat the process until one integer wins k rounds consecutively.
- Track the number of consecutive wins for each integer.
- Return the integer that wins k consecutive rounds.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least two elements.
- There will always be a winner as guaranteed by the problem.
{{< dots >}}
## Examples 🧩
- **Input:** `arr = [4, 2, 6, 5, 3, 1], k = 3`  \
  **Explanation:** The rounds play out as follows: 4 wins the first round, 6 wins the next two rounds, making it the winner after 3 consecutive wins.

- **Input:** `arr = [9, 3, 2, 1, 7, 5], k = 2`  \
  **Explanation:** The integer 9 wins the first two rounds consecutively and becomes the winner.

{{< dots >}}
## Approach 🚀
To solve the problem, simulate the rounds of the game and track the consecutive wins of each integer.

### Initial Thoughts 💭
- The game revolves around comparing the first two elements and shifting the smaller one to the end of the array.
- By tracking consecutive wins, we can determine when an integer wins k rounds.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least two elements in the array.
- Ensure that the solution handles large arrays efficiently (up to 10^5 elements).
- Handle the case where one integer wins all rounds quickly.
- Ensure the solution handles k values as large as 10^9.
{{< dots >}}
## Code 💻
```cpp
int getWinner(vector<int>& arr, int k) {
    int n = arr.size();

    int cnt = 0;
    int j = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[j]) {
            cnt++;
        } else {
            cnt = 1;
            j = i;
        }
        if(cnt == k) return arr[j];            
    }
    return arr[j];
}
```

This function determines the winner in a game where each element in the array is compared to the previous one, counting consecutive smaller elements. The winner is the element after `k` consecutive smaller elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int getWinner(vector<int>& arr, int k) {
	```
	This is the function declaration. The function `getWinner` takes a vector of integers `arr` and an integer `k` as input, and it returns the integer representing the winner based on the conditions.

2. **Variable Initialization**
	```cpp
	    int n = arr.size();
	```
	The variable `n` is initialized to the size of the input array `arr`. This represents the number of elements in the array.

3. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	The variable `cnt` is initialized to zero. It will keep track of how many consecutive elements are smaller than the current element.

4. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	The variable `j` is initialized to zero. It will store the index of the current smallest element in the sequence.

5. **For Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	A for loop starts from the second element (index 1) and iterates through the array `arr`.

6. **Conditional Check**
	```cpp
	        if(arr[i] < arr[j]) {
	```
	This condition checks if the current element `arr[i]` is smaller than the element at index `j`.

7. **Increment Operation**
	```cpp
	            cnt++;
	```
	If the current element is smaller, increment the `cnt` variable, which tracks the number of consecutive smaller elements.

8. **Else Statement**
	```cpp
	        } else {
	```
	If the current element is not smaller than the element at index `j`, reset the count and update `j`.

9. **Variable Reset**
	```cpp
	            cnt = 1;
	```
	The `cnt` variable is reset to 1 because the current element is smaller than the previous element.

10. **Update Index**
	```cpp
	            j = i;
	```
	The index `j` is updated to the current index `i`, since we are now considering the current element as the smallest in the sequence.

11. **Conditional Check**
	```cpp
	        if(cnt == k) return arr[j];            
	```
	This condition checks if the `cnt` reaches `k`. If so, the element at index `j` is returned as the winner.

12. **Return Statement**
	```cpp
	    return arr[j];
	```
	If no element reaches the `k` consecutive smaller elements, the element at index `j` is returned as the winner.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the array. The game ends as soon as a winner wins k consecutive rounds.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the input array size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-winner-of-an-array-game/description/)

---
{{< youtube v6On1TQfMTU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
