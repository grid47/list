
+++
authors = ["grid47"]
title = "Leetcode 2055: Plates Between Candles"
date = "2024-04-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2055: Plates Between Candles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Binary Search","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-1IsQyTM6Lg"
youtube_upload_date="2021-10-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-1IsQyTM6Lg/maxresdefault.webp"
comments = true
+++



---
You are tasked with processing a string of plates ('*') and candles ('|') arranged on a table. For a set of queries, you must determine the number of plates that are enclosed by candles within specified substrings of the string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` containing only '*' and '|' characters and a list of queries, where each query specifies a substring using two indices.
- **Example:** `Input: s = "|*|*|**|", queries = [[1, 5], [3, 7]]`
- **Constraints:**
	- 3 <= s.length <= 10^5
	- s consists of '*' and '|' characters.
	- 1 <= queries.length <= 10^5
	- queries[i].length == 2
	- 0 <= lefti <= righti < s.length

{{< dots >}}
### Output Specifications 📤
- **Output:** For each query, return the number of plates between candles in the specified substring.
- **Example:** `Output: [1, 2]`
- **Constraints:**
	- The result is an integer array where each element corresponds to a query.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the number of plates between candles for each query by preprocessing the input for efficient computation.

- Preprocess the string to identify the nearest candles to the left and right of each index.
- Compute the cumulative count of plates encountered up to each index.
- For each query, use the preprocessed data to calculate the number of plates enclosed by candles.
{{< dots >}}
### Problem Assumptions ✅
- Each substring query will always be within the bounds of the string.
- A valid candle must enclose plates on both sides within a query range.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "|**|**|*", queries = [[2, 7], [0, 8]]`  \
  **Explanation:** For query [2, 7], the substring is "**|**|", and the number of plates between candles is 2. For query [0, 8], the substring is "|**|**|*", and the number of plates between candles is 4.

{{< dots >}}
## Approach 🚀
Preprocess the string for efficient query resolution using arrays to store nearest candles and cumulative plate counts.

### Initial Thoughts 💭
- Plates must be enclosed by candles to be counted.
- Processing the string for every query would be computationally expensive.
- Use prefix sums and nearest candle positions for efficient computation.
{{< dots >}}
### Edge Cases 🌐
- An empty string or query list should return an empty result.
- Handle strings with maximum length and maximum number of queries efficiently.
- All plates or all candles should result in zero plates between candles for any query.
- Ensure indices in queries are within bounds.
{{< dots >}}
## Code 💻
```cpp
vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
    int n = s.length();
    vector<int> left(n, 0), right(n, 0), count(n, 0), ans(q.size(), 0);
    int node = -1;
    int cnt  = 0;
    for(int i = 0; i < n; i++) {
        
        if(s[i] == '|') {

            node = i;
            cnt++;
        }

        left[i]  = node;
        count[i] = cnt;

    }
    
    node = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '|'){
            node = i;
        }
        right[i] = node;
        
    }
    
    int idx = 0;
    for(vector<int> qr : q) {



        int r = left[qr[1]];
        int l = right[qr[0]];
       // int c = count[r] - count[l] + 1;
        
        if (r == -1 || l == -1 || r - l <= 1) {

            ans[idx] = 0;

        } else {
int c = count[r] - count[l] +1;
 ans[idx] = r - l + 1 - c;

        }
        
        idx++;
    }
    return ans;
}
```

This code implements the function to calculate the number of plates between candles for a set of queries, where candles are represented by '|' and plates by '*'. The function works by preprocessing the input string to store the positions of candles and the count of plates between them.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Main Function Declaration**
	```cpp
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
	```
	Declare the main function 'platesBetweenCandles' that takes a string 's' representing plates and candles, and a vector 'q' representing queries. It returns a vector of integers indicating the number of plates between candles for each query.

2. **Variable Declaration**
	```cpp
	    int n = s.length();
	```
	Declare a variable 'n' to store the length of the input string 's'.

3. **Variable Declaration**
	```cpp
	    vector<int> left(n, 0), right(n, 0), count(n, 0), ans(q.size(), 0);
	```
	Declare vectors 'left', 'right', 'count', and 'ans' to store the leftmost candle position, rightmost candle position, the count of plates up to each position, and the answers for each query.

4. **Variable Initialization**
	```cpp
	    int node = -1;
	```
	Initialize 'node' to -1, which will be used to track the position of candles during the processing.

5. **Variable Initialization**
	```cpp
	    int cnt  = 0;
	```
	Initialize 'cnt' to 0, which will be used to count the number of plates encountered so far.

6. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to process the input string 's' from left to right.

7. **If Statement**
	```cpp
	        if(s[i] == '|') {
	```
	Check if the current character is a candle ('|').

8. **Variable Update**
	```cpp
	            node = i;
	```
	Update the 'node' to the current position, as it now represents a candle.

9. **Counter Update**
	```cpp
	            cnt++;
	```
	Increment the 'cnt' variable as a candle is found.

10. **Vector Update**
	```cpp
	        left[i]  = node;
	```
	Store the position of the last encountered candle in the 'left' vector.

11. **Vector Update**
	```cpp
	        count[i] = cnt;
	```
	Store the cumulative count of plates encountered so far in the 'count' vector.

12. **Variable Update**
	```cpp
	    node = -1;
	```
	Reset the 'node' variable to -1 in preparation for the second pass of the string.

13. **For Loop**
	```cpp
	    for(int i = n - 1; i >= 0; i--) {
	```
	Start a loop to process the input string 's' from right to left.

14. **If Statement**
	```cpp
	        if(s[i] == '|'){
	```
	Check if the current character is a candle ('|').

15. **Variable Update**
	```cpp
	            node = i;
	```
	Update the 'node' to the current position as it represents a candle.

16. **Vector Update**
	```cpp
	        right[i] = node;
	```
	Store the position of the last encountered candle in the 'right' vector.

17. **Variable Declaration**
	```cpp
	    int idx = 0;
	```
	Declare an index 'idx' to track the current query in the queries list.

18. **For Loop**
	```cpp
	    for(vector<int> qr : q) {
	```
	Start a loop to process each query in the 'q' vector.

19. **Query Calculation**
	```cpp
	        int r = left[qr[1]];
	```
	Get the position of the leftmost candle on the right side of the query range.

20. **Query Calculation**
	```cpp
	        int l = right[qr[0]];
	```
	Get the position of the rightmost candle on the left side of the query range.

21. **If Condition**
	```cpp
	        if (r == -1 || l == -1 || r - l <= 1) {
	```
	Check if the range is invalid (either no candles found or the range is too small).

22. **Answer Update**
	```cpp
	            ans[idx] = 0;
	```
	Set the answer for the query to 0 if the range is invalid.

23. **Else Block**
	```cpp
	        } else {
	```
	If the range is valid, proceed to calculate the number of plates.

24. **Answer Calculation**
	```cpp
	int c = count[r] - count[l] +1;
	 ans[idx] = r - l + 1 - c;
	```
	Calculate the number of plates between candles by subtracting the count of plates in the range from the total number of positions in the range.

25. **Return Statement**
	```cpp
	    return ans;
	```
	Return the vector containing the answers for all the queries.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + q)
- **Average Case:** O(n + q)
- **Worst Case:** O(n + q)

Preprocessing takes O(n), and each query is resolved in O(1) for a total of O(n + q).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Additional arrays for nearest candles and cumulative plate counts require O(n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/plates-between-candles/description/)

---
{{< youtube -1IsQyTM6Lg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
