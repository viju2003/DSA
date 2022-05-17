#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
        int d;
        node *l;
        node *r;
        node(){
            l=NULL;
            r=NULL;
        }
};

class bstree{
    public:
        node* create(int q){
            node* k=new node;
            k->d=q;
            k->r=NULL;
            k->l=NULL;
            return k;
        }
        void insert(int i,node* root){
            node *t=new node;
            t=create(i);
            int f=0;
            if(root->d<i){
                if(root->r==NULL){
                    root->r=t;
                    f=1;
                }
                else{
                    insert(i,root->r);
                }
            }
            else{
                if(root->d>i){
                    if(root->l==NULL){
                        root->l=t;
                        f=1;
                    }
                    else{
                        insert(i,root->l);
                    }                    
                }
                else{
                    cout<<"\n !!Duplicate nodes not allowed!!";
                }

            }
            if(f==1)cout<<"\n NODE INSERTED";
        }
        void mindata(node* root){
            if(root->l!=NULL){
                mindata(root->l);
            }
            else{
                cout<<"\n Minimum Data in the tree is: "<<root->d;
            }
        }
        void search(int k,node* root){
            if(root->d==k){
                cout<<"\n Data found";
            }
            else{
                if(root->d<k){
                    if(root->r!=NULL)
                    search(k,root->r);
                    else cout<<"\nData not found";
                }
                else{
                    if(root->d>k)
                    if(root->l!=NULL)
                    search(k,root->l);
                    else cout<<"\nData not found";
                }
            }
        }

        node* swaprole(node* root){
            node* t;
            if(root==NULL){
                return NULL;
            }
            t=root->l;
            root->l=root->r;
            root->r=t;
            swaprole(root->l);
            swaprole(root->r);
            return NULL;
        }

        void display(node* root){
            if(root!=NULL){
                display(root->l);
                cout<<root->d<<" ";
                display(root->r);
            }
        }
        int longpath(node* root){
            if(root==NULL){
                return 0;
            }
            int right=longpath(root->r);
            int left=longpath(root->l);
            if(left>right){
                return (left+1);
            }
            else{
                return (right+1);
            }
        }
};

int main(){
    int c,i,k,f=0;
    bstree B;
    node *n=new node;
    while(true){
        cout<<"\n\t\t\t MENU\n\t1. Insert Node\n\t2. Find number of nodes in longest path\n\t3. Minimum data value found in the tree\n\t4. Mirror Image\n\t5. Search Value\n\t6. Display tree\n\t7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"\nEnter number to insert: ";
                cin>>i;
                if(f==0){
                    n=B.create(i);
                    cout<<"\nRoot node created";
                    f=1;
                }
                B.insert(i,n);
                break;
            case 2:
                k=B.longpath(n);
                cout<<k<<endl;
                break;
            case 3:
                B.mindata(n);
                break;
            case 4:
                B.swaprole(n);
                break;
            case 5:
                cout<<"\nEnter number to search: ";
                cin>>i;
                B.search(i,n);
                break;
            case 6:
                B.display(n);
                break;
            case 7:exit(0); 
        }
    }
    return 0;
}