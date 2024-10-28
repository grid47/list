class Solution {
    public long countPairs(int[] nums, int k) {
        long res = 0;
        HashMap<Integer, Integer> gm = new HashMap<>();
        for(int num: nums) {

            int gcd = findGCD(num, k);

            for(int node: gm.keySet()) {

                if((long) gcd * node % k == 0) 
                    res += gm.get(node);

            }

            gm.put(gcd, gm.getOrDefault(gcd, 0) + 1);
        }

        return res;
    }
    
    private int findGCD(int x, int y) {

        if (x < y) return findGCD(y, x);

        return y == 0 ? x : findGCD(y, x % y);

    }
}