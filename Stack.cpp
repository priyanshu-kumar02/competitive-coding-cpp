#include<bits/stdc++.h>
using namespace std;

#define lli long long int
lli size=100000;

lli empty(lli stack[],lli top)
{
	if(top==-1)
	return 1;
	return 0;
}

void push(lli stack[],lli item,lli &top)
{
	if(top==size-1)
	cout<<"Stack full\n";
	
	else
	stack[++top]=item;
}



lli pop(lli stack[],lli &top)
{
	if(empty(stack,top))
	return -1;
	
	top--;
	return stack[top+1];
}

lli top(lli stack[],lli top)
{
	return stack[top];
}

void display(lli stack[],lli top)
{
	if(top==-1)
	cout<<"Empty\n";
	
	for(lli i=top;i>=0;i--)
	cout<<stack[i]<<endl;	
}

lli cur_size(lli stack[],lli top)
{
	return top+1;
}

int main()
{
	lli stack[100000];
	size=5;
	lli choice,top=-1;
	
while(1)	
{
	cout<<"\nStack:\n";display(stack,top);
	cout<<"1.Display\n2.Insert\n3.Pop\n4.size\n5.Exit\n";
	
	cin>>choice;
	
	if(choice==1)
	display(stack,top);
	
	if(choice==2)
	{
		lli tmp=0;
		cin>>tmp;
		push(stack,tmp,top);
	}
	
	if(choice==3)
	cout<<pop(stack,top);
	
	if(choice==4)
	cout<<cur_size(stack,top);
	}
}

