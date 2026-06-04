class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        int l=0,h=matrix.size()*m-1;
        cout<<l<<" "<<h;
        while(l<=h){
            int mid=(l+h)/2;
            if(matrix[mid/m][mid%m]>target)
                h=mid-1;
            else if(matrix[mid/m][mid%m]<target)
                l=mid+1;
            else
                return true;
        }
        return false;
    }
};
