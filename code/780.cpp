class Solution {
public:
    
    unordered_map<long, unordered_map<long, bool>> mp;

    bool pts(int sx, int sy, int tx, int ty) {

        if(sx == tx && sy == ty) return true;
        if(sx > tx || sy > ty) return false;

        if(mp.count(sx) && mp[sx].count(sy)) return mp[sx][sy];

        bool ans = pts(sx + sy, sy, tx, ty);
        if(ans) return true;
        ans = pts(sx, sx + sy, tx, ty);
        return mp[sx][sy] = ans;
    }

    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx < tx && sy < ty) {
            if(tx < ty) {
                ty %= tx;
            } else {
                tx %= ty;
            }
        }
        
        return  (sx == tx && sy <= ty && (ty - sy) % sx == 0) ||
                (sy == ty && sx <= tx && (tx - sx) % sy == 0);
    }
};