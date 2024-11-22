
+++
authors = ["grid47"]
title = "Leetcode 1366: Rank Teams by Votes"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1366: Rank Teams by Votes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> count(26, vector<int> (27));
        for(char &c: votes[0])
        count[c - 'A'][26] = c;

        for(string& vote: votes)
        for(int i =0; i < vote.size(); i++)
        --count[vote[i] - 'A'][i];
        
        sort(count.begin(), count.end());
        string res;
        for(int i = 0; i < votes[0].length(); i++)
            res += count[i][26];
        
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem involves ranking teams based on votes received from a group of voters. Each voter casts a ranked vote for a set of teams (represented by uppercase letters). The goal is to determine the final ranking of teams based on these votes, with ties broken by lexicographical order.

### Approach
To achieve the desired ranking, we can follow these steps:
1. **Count Votes**: For each team (denoted by letters), maintain a count of their rankings based on the votes. The ranking is such that the higher the rank (lower index), the more negative the score.
2. **Store Team Information**: Use a 2D array to store the score and character for each team, enabling easy sorting.
3. **Sort Teams**: Sort the teams based on the negative ranking scores and lexicographically to break ties.
4. **Construct Result**: Extract the sorted team characters to form the final ranking string.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // Initialize a count array to store rankings for each team
        vector<vector<int>> count(26, vector<int>(27));
        
        // Store the team character for each index in the last position of the subarray
        for(char &c: votes[0])
            count[c - 'A'][26] = c;

        // Iterate through each vote and adjust the ranking scores
        for(string& vote: votes)
            for(int i = 0; i < vote.size(); i++)
                --count[vote[i] - 'A'][i];
        
        // Sort the count array to determine final rankings
        sort(count.begin(), count.end());
        
        // Construct the resulting ranking string
        string res;
        for(int i = 0; i < votes[0].length(); i++)
            res += count[i][26];
        
        return res;
    }
};
```

1. **Class Definition**:
   - The `Solution` class contains a single public method named `rankTeams`.

2. **Initialization of the Count Array**:
   - A 2D vector `count` is created to hold the rankings of the 26 teams (A-Z). Each sub-array holds 27 integers where the first 26 indices represent the negative rankings and the last index (26) stores the team character.

3. **Storing Team Characters**:
   - The first loop iterates over the first vote string to initialize the last element of each sub-array with the corresponding team character. For example, for team 'A', it sets `count[0][26] = 'A'`.

4. **Adjusting Rankings**:
   - The second nested loop processes each vote, decrementing the count for the corresponding team's rank position. This means that higher-ranked teams will accumulate more negative scores.

5. **Sorting the Teams**:
   - The `sort` function sorts the `count` array based on the first 26 elements (the scores). Since the sort is based on the vector's natural ordering, teams with higher negative scores (i.e., better rankings) will come first. In case of a tie in scores, the lexicographical order of team characters (stored in the last position) will be used to break ties.

6. **Building the Result**:
   - The final loop constructs the result string `res` by appending the team characters in the order determined by the sorted `count` array.

7. **Return Statement**:
   - Finally, the method returns the constructed ranking string.

### Complexity Analysis
- **Time Complexity**:
  - The time complexity of this algorithm is \(O(V + T \log T)\), where \(V\) is the total number of votes and \(T\) is the number of teams (which is fixed at 26). Sorting the teams dominates the complexity due to the sorting operation, but since \(T\) is a constant, this can be simplified to \(O(V)\) for practical input sizes.
  
- **Space Complexity**:
  - The space complexity is \(O(1)\) in terms of extra space, as the size of the `count` array is constant (26 for teams). However, the space used to store the input (votes) can be considered \(O(V)\).

### Conclusion
The `rankTeams` function efficiently calculates the final rankings of teams based on voters' preferences using a systematic counting and sorting approach. By representing the rankings as negative scores and leveraging lexicographical ordering to resolve ties, the algorithm ensures accurate and fair rankings. This solution is particularly well-suited for scenarios involving ranked voting systems, providing a clear demonstration of using data structures like arrays and sorting algorithms in competitive programming.

This comprehensive breakdown elucidates the code's logic and performance, making it accessible for readers interested in understanding how to solve ranking problems in programming contests.


[`Link to LeetCode Lab`](https://leetcode.com/problems/rank-teams-by-votes/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
