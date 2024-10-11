class Solution {
public:
    int totalMoney(int n) {
        int m=0;
        int a = 1;
        int l = min(n,7);
        while(n>0){
            //Arithmetic Progression from Monday-Sunday
            m+=(l*(2*a+l-1))/2;
            //initial amount is greater by 1 from prev
            a++;
            n-=7;
            l=min(n,7);
        }
        return m;
    }
};
