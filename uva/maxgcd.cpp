#include<bits/stdc++.h>

using namespace std;

int gcdf(int a,int b) ;

int main()
{
    vector<int> st ;
    char str[1000000] ;
    int tmp,t ;
    cin >> t  ;
    cin.ignore();
   while(t--)
   {
        gets(str);
        stringstream scn(str) ;
        while(scn>>tmp)
        {
            st.push_back(tmp) ;
        }
        int mx = 0 ;
        for(int i=0;i<st.size();i++)
        {
            for(int j=i+1;j<st.size();j++)
            {
                tmp = gcdf(st[i],st[j]) ;O
                if(mx<tmp)
                    mx = tmp ;
            }
        }
        cout << mx << endl;
        st.clear();
   }
   return 0;

}

int gcdf(int a,int b)
{
    if(a%b==0)
        return b ;
    return gcdf(b,a%b) ;
}
