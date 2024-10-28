struct Log {
    int id;
    string status;
    int time;
};
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<Log> stk;
        for(string log : logs) {
            stringstream ss(log);
            string num, adj, time;
            getline(ss, num,  ':');
            getline(ss, adj,  ':');
            getline(ss, time, ':');
            Log item = { stoi(num), adj, stoi(time) };

            if(item.status == "start") {
                stk.push(item);
            } else {
                assert(stk.top().id == item.id);
                int t = item.time - stk.top().time +1;
                ans[item.id] += t;
                stk.pop();
                if(!stk.empty()){
                    assert(stk.top().status == "start");
                    ans[stk.top().id] -= t;
                }
            }
        }
        return ans;
    }
};