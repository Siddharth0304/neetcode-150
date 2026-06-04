class Solution {
public:
    int getSum(int a, int b) {
        int sum=0,carry=0,ans=0;
        for(int i=0;i<32;i++){
            int x=a&(1<<i)?1:0;
            int y=b&(1<<i)?1:0;
            sum=x^y^carry;
            if(x&y || x&carry || y&carry)
                carry=1;
            else
                carry=0;
            cout<<sum<<" "<<carry<<endl;
            ans|=(sum<<i);
        }
        return ans;
    }
};
