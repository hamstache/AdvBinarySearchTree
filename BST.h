//
//  BST.h
//  cpsc131-project 9 BST
//
//  Created by Josh on 10/28/14.
//  Copyright (c) 2014 Josh. All rights reserved.
//

#ifndef cpsc131_project_9_BST_BST_h
#define cpsc131_project_9_BST_BST_h
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class BST
{
private:
    
    struct NODE
    {
        string info;
        int days;
        NODE* left;
        NODE* right;
    };
    NODE *root;
    
public:
    BST(){root=nullptr;}
    void insert(NODE *&p, string name, int days)
    {
        if(p==nullptr){
            p=new NODE; p->info = name; p->days = days;
            p->left = nullptr; p->right = nullptr;
        }
        else
        {
            if(name<p->info){insert(p->left, name, days);}
            if(name>p->info){insert(p->right, name, days);}
        }
    }
    void insert(string x, int y){insert(root, x, y);}
    //Display the tree
    void Display(NODE *p)
    {
        if(p != nullptr)
        {
            //Inorder traversal
            
            Display(p->left);//LC
            cout << p->info << " " << p->days << endl;//P
            Display(p->right);//RC
        }
    }
    void DisplayPost(NODE *p)
    {
        if(p !=nullptr)
        {
            //Postorder traversal
            
            Display(p->left);//LC
            Display(p->right);//RC
            cout << p->info<<" ";//P
        }
    }
    void DisplayPre(NODE *p)
    {
        if(p!=nullptr)
        {
            //Preorder traversal
            
            cout << p->info;
            cout<<" | " << p->days << endl;//P
            Display(p->left);//LC
            Display(p->right);//RC
        }
    }
    void display(){
        Display(root);cout << endl;
        //cout << "Postorder: ";DisplayPost(root);cout << endl;
        //cout << "Preorder: "; DisplayPre(root);cout << endl;
    }
    //Display leaves
    void DisplayLeaves(NODE *r)
    {
        if(r != nullptr)
        {
            DisplayLeaves(r->left);
            if(r->left == nullptr && r->right == nullptr){cout << r->info << " ";}
            DisplayLeaves(r->right);
        }
    }
    void DisplayLeaves(){DisplayLeaves(root);}
    
    //display parents with two children
    void displayp2c(NODE *r)
    {
        if (r!=nullptr && r->left !=nullptr && r->right !=nullptr)
        {
            cout <<r->info<< " "; displayp2c(r->left); displayp2c(r->right);
        }
        
    }
    void displayp2c(){displayp2c(root);}
    //display parents with only one child
    void displayp1c(NODE *r)
    {
        if (r!=nullptr)
        {
            if ((r->left != nullptr && r->right == nullptr)||(r->left == nullptr && r->right!=nullptr)){
                cout <<r->info<< " ";
            }
            displayp1c(r->left); displayp1c(r->right);
        }
        
    }
    void displayp1c(){displayp1c(root);}
    
    //entered name of month and must search BST to display number of days in that month
    int findDays(NODE *r, string name)
    {
        if (r != nullptr && r->info == name){return r->days;}
        else {findDays(r->left,name); findDays(r->right,name);}
        return 0;
    }
    int findDays(string name){return findDays(root, name);}
    //count number of nodes
    int CountNodes(NODE* p)
    {
        if(p == nullptr) return 0;
        else return 1+CountNodes(p->left)+CountNodes(p->right);
    }
    int CountNodes(){return CountNodes(root);}
    
    //Tree height
    int HeightTree(NODE *t)
    {
        if(t == nullptr) return 0;
        else return 1+max(HeightTree(t->left), HeightTree(t->right));
    }
    int max(int x, int y){return ((x>y)?x:y);}
    
    int HeightTree(){return HeightTree(root);}
    
};

#endif