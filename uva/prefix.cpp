#include<bits/stdc++.h>

using namespace std;

struct nod
{
    bool val,endmark;
    nod *next[10];
    nod()
    {
        for(int i=0;i<=9;i++)
            next[i] = 0;
        val = endmark = false;
    }
};

void freeMem(nod *p)
{
    for(int i=0;i<10;i++)
    {
        if(p->next[i])
        {
            freeMem(p->next[i]);
        }
    }
    delete p;
}
int main()
{
    int t,cas=0;
    cin >> t;
    while(++cas<=t)
    {
        int n;
        string s;
        nod *root,*tmp;
        root = new nod();
        bool flag = false;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> s;
            tmp = root;
            //cout << tmp << endl;
            if(flag)
                continue;
            int len = s.size();
            for(int j=0;j<len;j++)
            {
                int x = s[j] - '0';
                //cout << tmp->next[x] << endl;
                if(!tmp->next[x])
                {
                    tmp->next[x] = new nod();
                    //cout << "no" << endl;
                    tmp->next[x]->val = true;
                    if(j==len-1)
                        tmp->next[x]->endmark = true;

                }
                else
                {
                    // cout << "yes" << endl;
                    if(tmp->next[x]->endmark==true || j==len-1)
                    {
                        flag = true;
                        continue;
                    }
                }
                tmp = tmp->next[x];
            }
        }
        if(flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        freeMem(root);

    }
    return 0;
}
