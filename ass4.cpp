/*
Assignment No:: 4
Title :: Construct and expression tree from postfix/prefix expression and perform 
		  recursive and nonrecursive In-order, pre-order and post-order traversals.
Name : Sanket Nale
Roll No. :: 3174516		Class:: SE-B-IT		Batch:B3
*/
/*---CODE---*/
#include<iostream>
#include<string.h>
using namespace std;
struct node
	{
		char data;
		node *left,*right;
	};
	
class stack
{
	 node *stdata[20];
	 int top;
	public:
		stack()
		{
			top=-1;
		}
							 
    	void push(node *root)
    	{
      	  	top++;
       	 	stdata[top] = root;
  	 	}		
     	node *pop()
   	 	{
     	  	 return (stdata[top--]);
 	  	}
 };

class expTree
{
	int cho1;
	node *root;
    	public:
    		expTree()
    		{
    		}
    		void createPost(char []);
    		void createPre(char []);
    		void preorder(node *root);
    		void postorder(node *root);
    		void inorder(node *root);
 };
void expTree::createPost(char exp[])
{
    			stack s;
    			char c;
    			node *top,*t1,*t2;
    			int i;
    			for(i=0;exp[i]!='\0';i++)
    			{
    				c=exp[i];
    				if(isalnum(c))
    				{
    					top=new node;
    					top->left=NULL;
    					top->right=NULL;
    					top->data=c;
    					s.push(top);
    				}
    				else
    				{
    					t2=s.pop();
    					t1=s.pop();
    					top=new node;
    					top->data=c;
    					top->left=t1;
    					top->right=t2;
    					s.push(top);
    				}
    			}
    			root=s.pop();
    			do{
				cout<<"\nSelect Choice\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit";
    			cin>>cho1;
				switch(cho1)
    			{
    				case 1:
    					cout<<"\nPreorder display:";
                       			preorder(root);
                       			break;
                       		case 2:
                       			cout<<"\nInorder display:";
                       			inorder(root);
                       			break;
                       		case 3:
                       			cout<<"\nPostorder display:";
                       			postorder(root);
                       			break;
                }
            }while(cho1!=4);
}
    					
 void expTree::createPre(char exp[])
{
    			char c;
    			stack s;
    			node *top,*t1,*t2;
    			int i;
    			for(i=(strlen(exp)-1);i>=0;i--)
    			{
    				c=exp[i];
    				if(isalnum(c))
    				{
    					top=new node;
    					top->left=NULL;
    					top->right=NULL;
    					top->data=c;
    					s.push(top);
    				}
    				else
    				{ 
    					t1=s.pop();
    					t2=s.pop();
    					
    					top=new node;
    					top->data=c;
    					top->left=t1;
    					top->right=t2;
    					s.push(top);
    				}
    			}
    			root=s.pop();
    			do{
					cout<<"\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit";
	    			cout<<"\nSelect your Choice ::";
					cin>>cho1;
					switch(cho1)
	    			{
	    				case 1:
	    					cout<<"\nPreorder display:";
	                       			preorder(root);
	                       			break;
	                       		case 2:
	                       			cout<<"\nInorder display:";
	                       			inorder(root);
	                       			break;
	                       		case 3:
	                       			cout<<"\nPostorder display:";
	                       			postorder(root);
	                       			break;
	                }
            	}while(cho1!=4);	
    		}

 void expTree::preorder(node *root)
        {
                if(root!=NULL)
                {
                        cout<<root->data;
                        preorder(root->left);
                        preorder(root->right);
                 }
        }
        
 void expTree::postorder(node *root)
        {
                if(root!=NULL)
                {
                        postorder(root->left);
                        postorder(root->right);
                        cout<<root->data;
                }
        }
 void expTree::inorder(node *root)
        {
                if(root!=NULL)
                {
                        inorder(root->left);
                        cout<<root->data;
                        inorder(root->right);
                }
        }
        
int main()
{
	expTree et;
	char exp[20];
	int ch1;
	do{
		cout<<"\n\tMENU\n1.Create Postfix tree \n2.Create Prefix tree\n3.Exit\nSelect your choice::";
		cin>>ch1;
		switch(ch1)
		{
			case 1:
				cout<<"Insert Postfix Expression::";
				cin>>exp;
				et.createPost(exp);
				break;
			
			case 2:
				cout<<"Insert Prefix Expression::";
				cin>>exp;
				et.createPre(exp);
				break;
				
		}
	}while(ch1!=3);
	return 0;
}
/*---OUTPUT---*/
/*

*/
