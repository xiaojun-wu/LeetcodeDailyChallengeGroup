class Solution {
    public int findComplement(int num) {
        int res = 0;
        int bit = 0;
        while(num > 0){
            if((num & 1) != 1)
                res+= (1 << bit);
            bit++;
            num>>= 1;
        }
        return res;
    }
}
// https://tinyurl.com/2p8bzkcn