/*
Assignment No:: 1
Title :: Implement stack as an abstract data type using linked list and use this ADT for conversion of
         infix expression to postfix, prefix and evaluation of postfix and prefix expression.
*/
/*---CODE---*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
struct node
{
	char data;
	struct node *next;
};

class Stack
{
	node *top=NULL;
	public:
	void push(char);
	char pop();
	void display();
	int isEmpty();
	char getTop();
};


void Stack::push(char value)
{
	node *newnode;
	newnode=new node();
	newnode->data=value;
	newnode->next=NULL;
	if(top==NULL)
		top=newnode;
	else
		{
		newnode->next=top;
		top=newnode;
		}	
	}
	
	int Stack::isEmpty()
	{
		if(top==NULL)
			return 1;
		else 
			return 0;	
	}
	
	char Stack::getTop()
	{
		char d;
		node *temp=top;
		d=top->data;
		return d;
	}
	char Stack::pop()
	{
		node *temp=top;
		top=top->next;	
		char x=temp->data;
		delete temp;
		return x;
	}
	
	void Stack::display()
	{
		while(top!=NULL)
			{
				cout<<top->data;
				top=top->next;
			}
	}
	
	char isp(char ch)
	{
		switch(ch)
		{
			case '+':
			case '-':return 1;
			case '*':
			case '/':return 2;
			case '^':return 3;
			case '(':return 0;
	 		case ')':return -2;
		}
	
	}
	
	char icp(char ch)
	{
		switch(ch)
		{
			case '+':
			case '-':return 1;
			case '*':
			case '/':return 2;
			case '^':return 3;
			case '(':return 4;
		}
	
	}
	
	void infix_to_postfix(char infix[20],char postfix[20])
	{
		int i=0,j=0;
		char ch,x;
		Stack S;
		S.push(')');
		while(infix[i]!='\0')
		{
			ch=infix[i];
			i++;
			if(ch>='A'&&ch<='Z')
			{
				postfix[j]=ch;
				j++;
			}
			else 
			{
				if(ch==')')
				{
					while(S.getTop()!='(')
					{
						x=S.pop();
						postfix[j]=x;
						j++;
					}
					x=S.pop();
					postfix[j]=x;
					j++;			
				}
				else
					while(isp(S.getTop())>=icp(ch))
					{
						x=S.pop();
						postfix[j]=x;
						j++;
					}
				S.push(ch);
			}
			
		}	
	while(!S.isEmpty())	
	{
		x=S.pop();
		if(x!=')')
		{
			postfix[j]=x;
			j++;
		}
	}
	postfix[j]='\0';
	cout<<"\nPostfix Expresion"<<postfix;
	}
	
	void infix_to_prefix(char infix[20],char prefix[20])
	{
		int i=0,j=0,k=0;
		i=strlen(infix)-1;
		Stack S;
		char prefixnew[20];
		char ch,x;
		S.push(')');
		while(infix[k]!='\0')
		{
			if(infix[k]=='(')
				{
				infix[k]=')';
				}	
			else if(infix[k]==')')
				{
				infix[k]='(';
				}
			k++;		
		}
		while(i!=-1)
		{
			ch=infix[i];
			i--;
				if(ch>='A'&&ch<='Z')
				{
					prefix[j]=ch;
					j++;
				}
				else
				{
					if(ch==')')
					{
						while(S.getTop()!='(')
						{
							x=S.pop();
							prefix[j]=x;
							j++;					
						}
						x=S.pop();
					}
					else
					{
						while(isp(S.getTop())>icp(ch))
						{
							x=S.pop();
							prefix[j]=x;
							j++;
						}
					S.push(ch);	
					}
				}	
		}
	while(!S.isEmpty())
	{
		x=S.pop();
		if(x!=')')
		{
			prefix[j]=x;
			j++;
		}
	}
	
	k=0;
	for(i=(j-1);i>=0;i--)
	{
		prefixnew[k]=prefix[i];
		k++;
	}
	prefixnew[k]='\0';
	cout<<"\nPrefix Expresion"<<prefixnew;
	}
	
	
	int evaluate(char x,int op1,int op2)
	{
	if(x=='+')
		return(op1+op2);	 
	if(x=='-')
		return(op1+op2);
	if(x=='*')
		return(op1*op2);
	if(x=='/')
		return(op1/op2);
	if(x=='%')
		return(op1%op2);	
	}
	
	void postorder()
	{
		Stack S;
		char x;
		int i=0,op1,op2,val;
		char postfix[20];
		
		cout<<"\nEnter the Postfix Expression";
		cin>>postfix;	
		while(postfix[i]!='\0')
		{
			x=postfix[i];
			if(isdigit(x))
				{
				S.push(x-48);
				}
			else
			{
				op2=S.pop();
				op1=S.pop();
				val=evaluate(x,op1,op2);
				S.push(val);
			}	
		i++;	
		}
		val=S.pop();
		cout<<"\nValue Of Expression="<<val;
	}
	
	
	void preorder()
	{
		Stack S;
		char x;
		int i,op1,op2,val;
		char prefix[20];
		cout<<"\nEnter the prefix Expression";
		cin>>prefix;
		i=strlen(prefix)-1;
		while(prefix[i]!='\0')
		{
			x=prefix[i];
			if(isdigit(x))
			{
				S.push(x-48);
			}
			else
			{
				op1=S.pop();
				op2=S.pop();
				val=evaluate(x,op1,op2);
				S.push(val);
			}	
		i--;	
		}
		val=S.pop();
		cout<<"\nValue Of Expression="<<val;
	}

int main()
{
int ch;
Stack S;
char data,x;
char infix[20],postfix[20],prefix[20];
do
{
	cout<<"\n\tMenu";
	cout<<"\n1.Push\n2.Pop\n3.Display the Stack\n4.Conversion Infix to Postfix\n5.Infix to Prefix\n6.Postfix Evalution\n7.Prefix Evalution";
	cout<<"\n8.Exit\nEnter the choice::";	
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\nEnter the element in the stack::";
			cin>>data;
			S.push(data);
			cout<<"\nInseration Sucessfull::";				
		break;
		case 2:
			cout<<"\nElements Deleted from Stack::";
			x=S.pop();
			cout<<x;
		break;
		case 3:
			S.display();
		break;
		case 4:
			cout<<"\nEnter the infix expression::";
			cin>>infix;
			infix_to_postfix(infix,postfix);
		break;
		case 5:
			cout<<"\nEnter the infix expression::";
			cin>>infix;
			infix_to_prefix(infix,prefix);
		break;
		case 6:
			postorder();
		break;
		case 7:
			preorder();
		break;
	}
}while(ch!=8);
return 0;
}

/*---OUTPUT---*/
/*

*/
