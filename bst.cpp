#include<iostream>
using namespace std;
class node
{

	public:
		int data;
		node *left;
		node *right;
		

};

class BST
{

	public:
		node *root;
		int cnt;
		BST()
		{
			root =NULL;
			cnt=0;		
		}
		
		void insert();
		int search(int key);
		void preorder(node *root);
		void inorder(node *root);
		void postorder(node *root);
		void small(node *root);
		void great(node *root);
		void mirror(node *root);
		int height(node *root);
};
void BST::insert()
{

	int flag=0;
	node *new_node,*temp;
	new_node=new node();
	new_node->left=NULL;
	new_node->right=NULL;
	cout<<"\n\tEnter node data :";
	cin>>new_node->data;
	
	if (root==NULL)
	{
	
	root=new_node;
	
	}
	else
	{
	
		temp=root;
		
		while (flag==0)
		{
		
			if (new_node->data<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=new_node;
					flag=1;
				}
				else
				{
					temp=temp->left;
				}
			}
			
			else if(new_node->data>temp->data)
			{
			
				if(temp->right==NULL)
				{
					temp->right=new_node;
					flag=1;
				}
				else
				{
					temp=temp->right;
				}
			
			}
			else
			{
				cout<<"\n\tData already exits";
				break;				
			}
		}

	}
}
int BST::search(int key)
{

	node *temp;
	temp=root;
	while(1)
	{
	
		if (key<temp->data)
		{
			if(temp->left!=NULL)
				temp=temp->left;
			else
				return 0;
		}
		else if (key>temp->data)
		{
		
			if (temp->right!=NULL)
			{
				temp=temp->right;
			}
			else 
				return 0;
				 
		}
		else
			return 1;
	}

}

void BST::inorder(node *root)
{

	if (root!=NULL)
	{
		inorder(root->left);
		cout<<" "<<root->data;
		inorder(root->right);
	}
}

void BST::preorder(node *root)
{

	if (root!=NULL)
	{
		cout<<" "<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}	

void BST::postorder(node *root)
{

	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<" "<<root->data;
	}
}

void BST::small(node *root)
{

	node *temp;
	temp= root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	cout<<"\n\tSmallest data element :- "<<temp->data;
	

}

void BST::great(node *root)
{

	node *temp;
	temp= root;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	cout<<"\n\tGreatest data element :- "<<temp->data;
	

}

void BST::mirror(node *root)
{

	node *temp;
	if (root!=NULL)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirror(root->left);
		mirror(root->right);
	}

}

int BST::height(node *root)
{

	if(root==NULL)
		
		return 0;
		
	else if (root->left==NULL && root->right==NULL)
		
		return 0;
		
	int lheight=height(root->left);
	int rheight=height(root->right);
	
	if (lheight>rheight)
		
		return lheight+1;
	else 
		return rheight+1;

}

int main()
{

	BST b;
	int ch;
	do
	{
		cout<<"\n\t***Main Menu***";
		cout<<"\n\t1:Insert BST";
		cout<<"\n\t2:Search node";
		cout<<"\n\t3:Preorder BST";
		cout<<"\n\t4:Inorder BST";
		cout<<"\n\t5:Postorder BST";
		cout<<"\n\t6:Smallest BST";
		cout<<"\n\t7:Greatest BST";
		cout<<"\n\t8:Mirror BST";
		cout<<"\n\t9:Height of BST";
		cout<<"\n\t10:Exit";
		cout<<"\n\tEnter the Choice:";
		cin>>ch;
		switch(ch)
		{
		
			case 1:
				b.insert();
			break;
			
			case 2:
				int val;
				cout<<"\n\tEnter data to be search: ";
				cin>>val;
				
				if(b.search(val)!=1)
				{
					cout<<"\n\tData not found ";
				} 
				else
					cout<<"\n\tData found successfully";
					
			break;

			case 3:
				b.preorder(b.root);
			break;

			case 4:
				b.inorder(b.root);
			break;

			case 5:
				b.postorder(b.root);
			break;

			case 6:
				b.small(b.root);
			break;
			
			case 7:
				b.great(b.root);
			break;
			
			case 8:
				cout<<"\n\tOriginal BST:- \n\t";
				b.inorder(b.root);
				b.mirror(b.root);
				cout<<"\n\tMirror BST:- \n\t";
				b.inorder(b.root);
				b.mirror(b.root);
					
			break;
			
			case 9:
				cout<<"\n\tHeight of BST :- "<<b.height(b.root);
			break;
			
			case 10:
				cout<<"\n\tEnd of Program...!!";
			break;

			default:
				cout<<"\n\tInvalid Choice..!";
			break;
		}		
	}while(ch!=10);
	return 0;
}

