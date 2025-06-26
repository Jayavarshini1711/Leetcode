class Solution {
public:
    static int longestSubsequence(string& s, int k) {
        const int n=s.size();
        const int wz=33-countl_zero((unsigned)k);// window size
        vector<int> cnt0(n), suff(n);
        long long x=(s[n-1]=='1')?1:0;
        cnt0[0]=s[0]=='0', suff[n-1]=(x<=k);
        int r=n-1;
        for(int i=1; i<n; i++){
            cnt0[i]=cnt0[i-1]+(s[i]=='0');
            const int j=n-1-i;
            if(s[j]=='1') x+=(1LL<<(r-j));
            if (r-j>=wz) r--;// move r
            suff[j]=suff[j+1]+(x<=k);
            if (x>k){
                x>>=1;// if x>k, remove the least bit
                r--;
            }
        //    cout<<"j="<<j<<" suff[j]="<<suff[j]<< " x="<<x<<endl;
        }
        int ans=suff[0];
        for(int i=1; i<n; i++){
            ans=max(ans, cnt0[i-1]+suff[i]);
        }
        return ans;
    }
};
