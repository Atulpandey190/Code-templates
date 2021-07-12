/*
	Author:Atul Pandey
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
	Node(int data){
		this->data=data;
		this->left=nullptr;
		this->right=nullptr;
	}
	
};
///////////////////////////// INORDER TREE TRAVERSALS /////////////////////////////////////////
void recursive_inorder(Node * root)
{
	if(root==nullptr)return;
	recursive_inorder(root->left);
	cout<<root->data<<" " ;
	recursive_inorder(root->right);
}

void iterative_inorder(Node *root)
{
	stack <Node*> st;
	
	while(true)
	{
		while(root)
		{	
			st.push(root);
			root=root->left;
		}
		if(st.empty())break;

		root=st.top();st.pop();
		cout<<root->data<<" ";
		root=root->right;
	}

}
///////////////////////////// PREORDER TREE TRAVERSALS /////////////////////////////////////////

void recur_preorder(Node * root)
{
	if(root)
	{
		cout<<root->data;
		recur_preorder(root->left);
		recur_preorder(root->right);
	}
}

void iterative_preorder(Node *root)
{
	stack<Node *> st;
	while(true)
	{
		while(root)
		{
			st.push(root);
			cout<<root->data<<" ";
			root=root->left;
		}
		if(st.empty())break;

		root=st.top();st.pop();
		root=root->right;

	}
}



///////////////////////////// POSTORDER TREE TRAVERSALS /////////////////////////////////////////

void recur_postorder(Node *root)
{
	if(root)
	{
		recur_postorder(root->left);
		recur_postorder(root->right);
		cout<<root->data<<" ";

	}
}

void iterative_postorder1(Node* root)
{
	// two stack method
	stack<Node*> s1,s2;
	s1.push(root);
	while(!s1.empty())
	{
		Node *curr=s1.top();
		s1.pop();
		s2.push(curr);
		if(curr->left)s1.push(curr->left);
		if(curr->right)s1.push(curr->right);
	}
	while(!s2.empty())cout<<s2.top()->data<<" ",s2.pop();
}

void iterative_postorder2(Node* root)
{
	// one stack method
	/*
		
			1.1 Create an empty stack
			2.1 Do following while root is not NULL
			    a) Push root's right child and then root to stack.
			    b) Set root as root's left child.
			2.2 Pop an item from stack and set it as root.
			    a) If the popped item has a right child and the right child 
			       is at top of stack, then remove the right child from stack,
			       push the root back and set root as root's right child.
			    b) Else print root's data and set root as NULL.
			2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
	*/
	stack<Node*> s;
	while(root)
	{
		if(root->right)s.push(root->right);
		s.push(root);
		root=root->left;
	}
	while(!s.empty())
	{
		while(root)
		{
			if(root->right)s.push(root->right);
			s.push(root);
			root=root->left;
		}
		root=s.top();
		s.pop();
		if(!s.empty()&&root->right!=NULL&&root->right==s.top())
		{
			s.pop();
			s.push(root);
			root=root->right;
		}
		else 
		{
			cout<<root->data<<" ";
			root=NULL;
		}

	}
	
}




int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
   	// iterative_inorder(root);
   	// iterative_preorder(root);
   	iterative_postorder2(root);
 
    return 0;
}
