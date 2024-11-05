void rotate(vector<vector<int> >& a) {
    // Your code goes here
    int n=a.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        int j=0;
        int k=n-1;
        while(j<k)
        {
           int t=a[i][j];
           a[i][j]=a[i][k];
           a[i][k]=t;
           j++;
           k--;
        }
    }
}
