
+++
authors = ["grid47"]
title = "Leetcode 2899: Last Visited Integers"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2899: Last Visited Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vWwJsOGGKu8"
youtube_upload_date="2023-10-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/vWwJsOGGKu8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>v;
        vector<int>ans;
        int count=0;
        for(int i=0;i<words.size();i++){
            if(words[i]=="prev"){
                count++;
                if(count>v.size()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(v[v.size()-count]);
                }
            }
            else{
                count=0;
                v.push_back(stoi(words[i]));
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The function `lastVisitedIntegers` takes a vector of strings called `words`. Each element in `words` represents either an integer (stored as a string) or the keyword `"prev"`. If the element is an integer, it is added to a history of previously encountered integers. When `"prev"` appears, the function should return the last visited integer based on how many `"prev"` commands have been issued consecutively. If there is no valid last integer for a `"prev"` command, it should return `-1`. 

### Approach

This function manages a history of integers and allows for quick lookup of previous values in that history. It utilizes a vector `v` to store integer values and another vector `ans` to store the results for each `"prev"` command or integer in the input `words`. The approach involves iterating through the list of `words` and processing each word according to whether it’s an integer or the command `"prev"`.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Helper Variables

```cpp
vector<int>v;          // Stores the history of integers.
vector<int>ans;        // Stores the result for each word in words.
int count=0;           // Tracks consecutive "prev" commands.
```

- `v` holds the history of integers added from `words`.
- `ans` stores the output values, which will be returned at the end.
- `count` is used to track the number of consecutive `"prev"` commands, allowing access to previously visited integers in `v`.

#### Step 2: Iterate Through `words` Vector

```cpp
for(int i=0; i < words.size(); i++) {
    if(words[i] == "prev") {
```

- We iterate through each word in `words`. If the current word is `"prev"`, we need to retrieve the previously visited integer based on `count`.

#### Step 3: Handle "prev" Commands

```cpp
count++;
if(count > v.size()) {
    ans.push_back(-1);
} else {
    ans.push_back(v[v.size() - count]);
}
```

- For each `"prev"` command:
  - Increment `count` to keep track of how far back to look.
  - If `count` exceeds the size of `v`, it means we are trying to access an out-of-bounds index in the history, so we add `-1` to `ans`.
  - Otherwise, we access the element `v[v.size() - count]`, representing the integer `count` positions back in history, and add it to `ans`.

#### Step 4: Handle Integer Words

```cpp
} else {
    count = 0;
    v.push_back(stoi(words[i]));
}
```

- If the current word is an integer, `count` is reset to zero, indicating that the history lookup (`"prev"` commands) has been interrupted.
- The integer is converted from string to integer using `stoi()` and added to `v`.

#### Step 5: Return the Result

```cpp
return ans;
```

- After processing all words, `ans` contains the result for each `"prev"` command or integer entry in `words`. It is returned as the final result.

### Complexity

- **Time Complexity**: The time complexity is `O(n)`, where `n` is the number of words in the `words` vector. We iterate through `words` once, and operations like accessing elements in a vector or converting strings to integers are constant time.
  
- **Space Complexity**: The space complexity is `O(n)` because we store both `v` and `ans`, each of which can grow to a size of `n` in the worst case.

### Conclusion

This solution effectively manages a history of integers, allowing efficient retrieval of previously visited values based on consecutive `"prev"` commands. It achieves this with minimal complexity by leveraging a vector and efficient conditional checks to manage edge cases (such as accessing out-of-bounds indices). The solution’s simplicity and efficiency make it well-suited for scenarios requiring retrieval of recently encountered values with interruptions.

[`Link to LeetCode Lab`](https://leetcode.com/problems/last-visited-integers/description/)

---
{{< youtube vWwJsOGGKu8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
