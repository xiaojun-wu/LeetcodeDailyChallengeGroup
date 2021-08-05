// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int val = 0;
        do{
            val = ((rand7() - 1) * 7) + rand7();
        }while(val > 40);
        return val % 10 + 1;
    }
};

// https://tinyurl.com/4cppxby4