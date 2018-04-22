/*
Assignment No:: 3
Title :: Create Binary tree and perform following operations:
		a. Insert		b. Display		c. Depth of a tree	d. Display leaf-nodes	e. Create a copy of a tree.
Name :: Sanket Nale
Roll No. :: 3174516		Class:: SE-B-IT		Batch:B3
*/
/*---CODE---*/
#include<iostream>
#include<math.h>
using namespace std;
template<class T>
class bt
{
        public:
        struct node
        {
                node *left,*right;
                T data;
        };
        struct node *root,*newroot,*root1,temp;
        int depthl,depthr;
        bt()
        {
                root=NULL;
                depthl=depthr=0;
                newroot=NULL;
        }
        bool isempty()
        {
                if(root==NULL)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
        void create(T data)
        {
                if(root==NULL)
                {
                        root=new node();
                        root->left=NULL;
                        root->right=NULL;
                        root->data=data;
                }
             //   return root;
        }
        void insert(T data,T key)
        {
                char ch;
                if(root!=NULL)
                {
                        node *temp=search(root,key);
                        if(temp!=NULL)
                        {
                                node *n=new node();
                                n->data=data;
                                n->left=NULL;
                                n->right=NULL;
                                
                                cout<<"\nWhere u want to insert l/r::";
                                cin>>ch;
                                if(temp->left==NULL&&ch=='l')
                                {
                                        temp->left=n;
                                }
                                else if(temp->right==NULL&&ch=='r')
                                {
                                        temp->right=n;
                                }
                                else
                                {
                                        cout<<"location full";
                                }
                        }
                        else
                        {
                                cout<<"key doesnt exist";
                        }
                }
        }
        node *search(node *root,T key)
        {
                if(root!=NULL)
                {
                        if(root->data==key)
                        {
                                return root;
                        }
                        else
                        {
                                node *tempa=search(root->left,key);
                                node *tempb=search(root->right,key);
                                if(tempa!=NULL)
                                {
                                        return tempa;
                                }
                                else
                                {
                                        return tempb;
                                }
                        }
                }
                else
                {
                        return NULL;
                }
        }
        void preorder(node *root)
        {
                if(root!=NULL)
                {
                        cout<<root->data<<"\t";
                        preorder(root->left);
                        preorder(root->right);
                 }
        }
        void postorder(node *root)
        {
                if(root!=NULL)
                {
                        postorder(root->left);
                        postorder(root->right);
                        cout<<root->data<<"\t";
                }
        }
         void inorder(node *root)
        {
                if(root!=NULL)
                {
                        inorder(root->left);
                        cout<<root->data<<"\t";
                        inorder(root->right);
                }
        }
        void display()
        {
                int ch1;
                do
                {
                     cout<<"\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit";
                     cout<<"\nEnter display choice::";
                     cin>>ch1;
                     switch(ch1)
                                        {
                                                case 1:
                                                        cout<<"\nPreorder display:";
                                                        preorder(root);
                                                        break;
                                                        
                                                case 2:
                                                        cout<<"\nInorder display";
                                                        inorder(root);
                                                        break;
                                                        
                                                case 3:
                                                        cout<<"\nPostorder display";
                                                        postorder(root);
                                                        break;
                                        }
                                        
                                }while(ch1<=3);
        }
        void depth()
        {                      
        	int d=depth(root);
        	cout<<"\nDepth of tree is:"<<d;
       	}
       	
       	int depth(node *root)
       	{
       		if(root==NULL)
       		{
       			return 0;	
       		}
       		return max(depth(root->left),depth(root->right))+1;
       	}
        
        void leaf(node *root)
        {
                if(root!=NULL)
                {
                        if((root->left==NULL)&&(root->right==NULL))
                        {
                                cout<<root->data<<"\t";
                        }
                        else
		        		{
                       		 leaf(root->left);
                        	 leaf(root->right);
               		}
                }  
        }
        
        void display_leaf()
        {
        	cout<<"\nleaf nodes are:";
        	leaf(root);
        }
        
		node* copytree(node *root,node *newroot)
		{
			if(root==NULL)
				return NULL;
			else
			{
				node *tempa=new node;
				node *tempb=new node;
				newroot=new node;	
				newroot->data=root->data;
				newroot->left=copytree(root->left,tempa);
				newroot->right=copytree(root->right,tempb);
			}	
			return newroot;
		}
	
		void copytreecall()
		{
			node *nr;
			nr=copytree(root,newroot);
			cout<<"Tree Copy Successsfull..";
			display();
		}
};

int main()
{
        bt <int>b; 
        int a,key;
        int ch;
        do
        {
                cout<<"\n\t MENU \n1.Create\n2.Insert\n3.Display\n4.Depth\n5.leaf Node\n6.Copy\n7.Exit";
                cout<<"\nEnter your choice::";
                cin>>ch;
                switch(ch)
                {
                        case 1:
                                cout<<"\nEnter element of tree:\n";
                                cin>>a;
                               b.create(a);
                                cout<<"\nTree created successfully";
                                break;
                         case 2:
                                if(!b.isempty())
                                {
                                        cout<<"\nEnter the element to be inserted in tree:";
                                        cin>>a;
                                        cout<<"\nEnter key value to insert:";
                                        cin>>key;
                                        b.insert(a,key);
                                        cout<<"\nNew element inserted successfully";
                                }                 
                                else
                                {
                                        cout<<"\nFirst create tree";
                                }
                                break;
                         case 3:
                         	b.display();
                                break;                              
                         case 4:
                                b.depth();
                         		break;
                         case 5:
                        	b.display_leaf();
                                break; 
                         case 6:
                           	 b.copytreecall(); 
                           	 break;                 	
                }
        }while(ch!=7);
        return 0;
}
/*---OUTPUT---*/
/*

*/
