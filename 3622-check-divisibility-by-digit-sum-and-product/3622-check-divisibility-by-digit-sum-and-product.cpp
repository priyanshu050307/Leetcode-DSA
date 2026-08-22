class Solution {
public:
    bool checkDivisibility(int n) {
        int num1 = n;
        int sum = 0;
        int product = 1;
        while(num1>0){
            int temp = num1;
            int digit = num1%10;
            sum+=digit;
            product*=digit;
            num1 = num1/10;
        }
        if(n%(sum+product)==0){
            return true;
        }else{
            return false;
        }

    }
};