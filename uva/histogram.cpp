#include<bits/stdc++.h>

using namespace std;

struct nod
{
	int val,ind;
};

int main()
{
	int t, cas = 0, n,maxx,indx,area;
	FILE *fp;
	fp = fopen("file.txt","w");
	nod tmp;
	nod hist[30001];
	scanf("%d",&t);
	while(++cas<=t)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&hist[i].val);
			hist[i].ind = i;
		}
		stack<nod> st;
		maxx = 0;
		for(int i=1;i<=n;i++)
		{
			if(!st.empty())
			{
				tmp = st.top();
				if(tmp.val<=hist[i].val)
					st.push(hist[i]);
				else
				{
					indx = tmp.ind;
					while(!st.empty())
					{
						tmp = st.top();
						if(tmp.val>hist[i].val)
						{
							st.pop();
							//cout << tmp.val << endl;
							if(st.empty())
							{
								area = indx*tmp.val;
								//cout << "Y" << endl;
							}
                            else
                                area = (indx-tmp.ind+1)*tmp.val;
							if(area > maxx)
								maxx = area;
							//cout << maxx << " YES" << indx << " " << tmp.ind << endl;
						}
						else
							break;
					}
				}
				st.push(hist[i]);
			}
			else
                st.push(hist[i]);
		}
		indx = n;
		while(!st.empty())
		{
			tmp = st.top();
			st.pop();
			area = (indx-tmp.ind+1)*tmp.val;
			if(st.empty())
				area = indx*tmp.val;
			if(area > maxx)
				maxx = area;
			//cout << maxx << " NO" << endl;
		}
		fprintf(fp,"Case %d: %d\n",cas,maxx);
	}
	fclose(fp);
	return 0;
}
