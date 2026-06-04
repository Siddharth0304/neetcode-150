class Solution {
public:
    int getSum(int a, int b) {
        int carry=0,ans=0;
        for(int i=0;i<32;i++){
            int x=a&(1<<i)?1:0;
            int y=b&(1<<i)?1:0;
            int sum=x^y^carry;
            carry=(x&y)|(x&carry)|(y&carry);
            ans|=(sum<<i);
        }
        return ans;
    }
};
