class Solution {
public:
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
};