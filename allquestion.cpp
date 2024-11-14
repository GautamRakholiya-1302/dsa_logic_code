// First question 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    vector<vector<int>>ans(n);
    for(int i=0;i<n;i++)
    {
        
        ans[i][0]=1;
        ans[i][i]=1;
        for(int j=1;j<i;j++)
        {
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return;
}

// 2nd Question

ListNode* rotatelist(ListNode *head ,int k)
{
    if(!head || k==0)
    {
        return head;
    }
    int size=1;
    ListNode* tail=head;
    while(tail->next)
    {
        tail=tail->next;
        size++;
    }
    cout<<size<<endl;
    tail->next=head;
    k=k%size;

    int rmsize=size-k;
    ListNode* temp=tail;

    for(int i=0;i<rmsize;i++)
    {
        temp=temp->next;
    }
    head=temp->next;
    temp->next=nullptr;

    return head;

}



// 3rd question 



bool  pathsum(TreeNode* root ,int targetsum)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->left==nullptr && root->right==nullptr)
    {
        return root->value==targetsum;
    }
    int remaingcount=root->value-targetsum;
    return pathsum(root->left,remaingcount) || pathsum(root->right,remaingcount);
}
	
