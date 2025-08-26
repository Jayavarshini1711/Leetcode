class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxdiag=0,maxarea=0;
        int n=dimensions.size();
        for(int i=0;i<n;i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];
            int currdiag=l*l+w*w;
            if(currdiag>maxdiag || currdiag==maxdiag && l*w>maxarea){
                maxdiag=currdiag;
                maxarea=l*w;
            }
        }
        return maxarea;
    }
};