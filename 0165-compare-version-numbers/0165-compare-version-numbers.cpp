class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size();
    int n2=version2.size();
    long int i=0,j=0,a=0,b=0;
    
    while((i<n1)||(j<n2))
    {
        a=0,b=0;
        while((version1[i]!='.')&&(i<n1))
        {
            a=a*10+(version1[i]-'0');
            i++;
        }
        while((version2[j]!='.')&&(j<n2))
        {
            b=b*10+(version2[j]-'0');
            j++;
        }
        
        if(a>b) return 1;
        
        else if(b>a) return -1;
        
        if(i<n1)  i++;
        
        if(j<n2)  j++;
        
    }
    return 0;
    }
};