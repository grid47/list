
+++
authors = ["grid47"]
title = "Leetcode 1773: Count Items Matching a Rule"
date = "2024-05-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1773: Count Items Matching a Rule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "FL3vJlSmq7w"
youtube_upload_date="2021-02-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FL3vJlSmq7w/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int i;
        if(ruleKey=="type")i=0;
        if(ruleKey=="color")i=1;
        if(ruleKey=="name")i=2;
        
        int ans=0;
        for(int j=0;j<items.size();j++){
            if(items[j][i]==ruleValue)ans++;
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to count how many items in a collection match a specific criterion defined by a key-value pair. Each item in the collection is represented as a list of strings, where each string corresponds to an attribute of the item (such as type, color, or name). The problem can be outlined as follows:

- You have a list of items, where each item is described by three properties: `type`, `color`, and `name`.
- You need to check how many of these items match a given criterion, which consists of a `ruleKey` (indicating which property to check) and a `ruleValue` (the value that the specified property must match).
- The solution must efficiently count the number of matching items based on the provided rule.

### Approach

The solution to this problem involves a straightforward iterative approach. The steps can be summarized as follows:

1. **Identify the Index**: Map the `ruleKey` to an index that corresponds to the position of the attribute in the items array. The mapping is as follows:
   - `type` corresponds to index `0`
   - `color` corresponds to index `1`
   - `name` corresponds to index `2`

2. **Count Matches**: Iterate through the list of items and count how many items have the specified property matching the `ruleValue`.

3. **Return the Count**: Finally, return the total count of items that match the given rule.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided C++ code:

```cpp
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
```
- The `Solution` class contains a public method `countMatches`. This method takes in two parameters: `items`, which is a vector of vectors containing strings, and `ruleKey` and `ruleValue`, which are the key and value for the rule to be checked.

```cpp
        int i;
        if(ruleKey=="type")i=0;
        if(ruleKey=="color")i=1;
        if(ruleKey=="name")i=2;
```
- Here, an integer variable `i` is declared to hold the index corresponding to the `ruleKey`. Conditional statements are used to set `i` to `0`, `1`, or `2`, depending on whether the `ruleKey` is `"type"`, `"color"`, or `"name"`.

```cpp
        int ans=0;
```
- An integer variable `ans` is initialized to `0`. This variable will keep track of the count of items that match the specified criteria.

```cpp
        for(int j=0;j<items.size();j++){
            if(items[j][i]==ruleValue)ans++;
        }
```
- A `for` loop iterates over each item in the `items` vector. The loop variable `j` represents the index of the current item.
- Inside the loop, a conditional statement checks if the attribute at index `i` of the current item matches the `ruleValue`. If it does, the counter `ans` is incremented by `1`.

```cpp
        return ans;
    }
};
```
- Finally, the method returns the value of `ans`, which represents the total count of matching items.

### Complexity

- **Time Complexity**: The time complexity of the `countMatches` function is \(O(n)\), where \(n\) is the number of items in the `items` vector. This is because the function must iterate through each item once to count the matches.

- **Space Complexity**: The space complexity is \(O(1)\) since the solution only uses a constant amount of additional space (for the index variable `i` and the count variable `ans`) regardless of the size of the input.

### Conclusion

This solution effectively addresses the problem of counting items that match specific criteria by utilizing a simple and efficient approach. It demonstrates the use of basic programming constructs such as conditional statements and loops to filter and count elements in a collection.

In summary, the provided `countMatches` method serves as a practical implementation of filtering based on specified attributes, showcasing the power of iterative approaches in solving problems involving collections of data. Such techniques are fundamental in programming and data manipulation, making this solution relevant for various applications, including inventory management, product filtering in e-commerce, and data analysis tasks.

By encapsulating the logic within a class and providing a clear interface through the `countMatches` method, the solution adheres to good programming practices, allowing for reusability and maintainability in larger codebases. Understanding and implementing such straightforward yet effective solutions can significantly enhance problem-solving skills in programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-items-matching-a-rule/description/)

---
{{< youtube FL3vJlSmq7w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
