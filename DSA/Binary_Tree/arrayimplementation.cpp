#include<bits/stdc++.h>
using namespace std;

char tree[10];
void root(char x)
{
	if(tree[0] != '\0')
		cout<<"Root Exist";
	else
		tree[0]=x;
}

void setleft(char x, int p)
{
	if(tree[p]=='\0')
		cout<<"Cannot set child";
	else
		tree[(p*2)+1]=x;
}

void setright(char x, int p)
{
	if(tree[p]=='\0')
		cout<<"Cannot set child";
	else
		tree[(p*2)+2]=x;
}

void printtree()
{
	cout<<"\n";
	
	for(int i=0;i<10;i++)
	{
		if(tree[i]!='\0')
			cout<<i;
		else
			cout<<"-";
	}
	cout<<"\n";

	for(int i=0;i<10;i++)
	{
		if(tree[i]!='\0')
			cout<<tree[i];
		else
			cout<<"-";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	root('A'); 
	setleft('B',0);
    setright('C', 0); 
    //setleft('D', 1); 
    setright('E', 1); 
    setright('F', 2); 
    printtree(); 
    return 0;


	return 0;
}