#include<bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> deq;
    int n,m,a,t,cas=0;
    string com;
    cin >> t;
    while(++cas<=t)
    {
        cin >> n >> m;
        cout << "Case " << cas << ":" << endl;
        for(int i=1;i<=m;i++)
        {
            cin >> com;
            if(com=="popLeft")
            {
                if(deq.empty())
                {
                     cout << "The queue is empty" << endl;
                     continue;
                }
                else
                {
                    int tmp = deq.back();
                    deq.pop_back();
                    cout << "Popped from left: " << tmp << endl;
                }
            }
            else if(com=="popRight")
            {
                if(deq.empty())
                    cout << "The queue is empty" << endl;
                else
                {
                    int tmp = deq.front();
                    deq.pop_front();
                    cout << "Popped from right: " << tmp << endl;
                }
            }
            else
            {
                cin >> a;
                if(deq.size()>=n)
                {
                    cout << "The queue is full" << endl;
                }
                else if(com=="pushLeft")
                {
                    deq.push_back(a);
                    cout << "Pushed in left: " << a << endl;
                }
                else
                {
                    deq.push_front(a);
                    cout << "Pushed in right: " << a << endl;
                }
            }
        }
        while(!deq.empty())
            deq.pop_back();
    }
    return 0;
}
