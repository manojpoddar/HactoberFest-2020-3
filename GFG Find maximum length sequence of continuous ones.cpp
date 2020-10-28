//Find Index of 0 to be replaced with 1 to get longest continuous sequence of 1s in a binary array | Set-2
//Given an array of 0s and 1s, find the position of 0 to be replaced with 1 to get longest continuous sequence of 1s. Expected time complexity is O(n) and auxiliary space is O(1).
//Examples:
//
//Input : arr[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1}
//Output : Index 9
//Assuming array index starts from 0, replacing 0 with 1 at 
//index 9 causes the maximum continuous sequence of 1s.
//
//Input : arr[] =  {1, 1, 1, 1, 0}
//Output : Index 4
//LINK: https://www.geeksforgeeks.org/find-index-of-0-to-be-replaced-with-1-to-get-longest-continuous-sequence-of-1s-in-a-binary-array-set-2/
#include<bits/stdc++.h>
#define ll long long
#define lli long long int
#define ull unsigned long long
#define li long int
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int zeros=0;
    int ones=0;
    int maxi=INT_MIN;
    int lastcount=0;
    int lastzero=-1;
    int maxizero=-1;
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
            ones++;
        else
        {
            if(zeros==0)
            {
                zeros++;
                lastzero=i;
            }
            else
            {
                if(maxi<(ones+1))
                {
                    maxi=ones+1;
                    maxizero=lastzero;
                }
                lastzero=i;
                while(v[lastcount]!=0)
                {
                    lastcount++;
                    ones--;
                }
                lastcount++;
            }
        }
    }
                if(maxi<(ones+1))
                {
                    maxi=ones+1;
                    maxizero=lastzero;
                }
    cout<<maxi<<" "<<maxizero;
}

