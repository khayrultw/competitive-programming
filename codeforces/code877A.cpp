#include<bits/stdc++.h>

using namespace std;

bool findName(char p[], char s[])
{
	//cout << p << " " << s << endl;
	if(strlen(p)<strlen(s))
		return false;
	int l = strlen(s);
	char tmp[101];
	strcpy(tmp, p);
	*(tmp+l) = '\0';
	if(strcmp(tmp, s)==0)
		return true;
	return findName(p+1, s);
}

int main()
{
	char d[] = "Danil", o[] = "Olya", s[] = "Slava", a[] = "Ann", n[] = "Nikita";
	char str[101];
	cin >> str;
	int sum = 0;
	if(findName(str, d))
		sum++;
	if(findName(str, o))
		sum++;
	if(findName(str, s))
		sum++;
	if(findName(str, a))
		sum++;
	if(findName(str, n))
		sum++;
	if(sum==1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	//cout << sum << endl;
	return 0;
}


	
