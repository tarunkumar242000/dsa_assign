#include<iostream>
using namespace std;


 int maxx(int a,int b)
{
        if(a<b)
            return b;
        else
            return a;
}


class Node
{
    public:
        int val,height,count;
        Node* left;
        Node* right;
        Node* prev;

        Node()
        {
            val=0;
            height=1;
            right=NULL;
            left=NULL;
            prev=NULL;
            count=0;
        }

        Node(int value)
        {
           val=value;
           height=1;
           right=NULL;
           left=NULL;
           prev=NULL;
           count=1;
        }
};

void inorder(Node* h)
{
    if(h->left)
        inorder(h->left);
    cout<<h->val<<" ";
    if(h->right)
        inorder(h->right);
}


class bst
{
    public:

    Node* head;
    Node* tail;
    bst()
    {
        head=NULL;
    }    

   
     Node* insertnode(int vval)
     {
        Node* temp=new Node(vval);
        if(head==NULL)
        {
            head=temp;
            return head;
        }

        Node* temp1=head;
        //cout<<temp1->val<<endl;
        while(temp1)
        {if((temp1->val)>vval)
        {
            if(temp1->left!=NULL)
                temp1=temp1->left;
            else
            {
                temp1->left=temp;
                temp->prev=temp1;
                temp1=temp1->left;
                break;
            }
        }
        else if((temp1->val)==vval)
        {
            temp1->count++;
            temp->count++;
            if(temp1->right!=NULL)
                temp1=temp1->right;
            else{
                temp1->right=temp;
                temp->prev=temp1;
                temp1=temp1->right;
                break;
            }
        }
        else{
            if((temp1->right)!=NULL)
            {
                temp1=temp1->right;
            }
            else{
                temp1->right=temp;
                temp->prev=temp1;
                temp1=temp1->right;
                break;
            }
        }
        }
        tail=temp1;
        Node* tempp;
        tempp=tail;
        while((tempp->prev)!=NULL)
        {
            int h;
            h=maxx(tempp->prev->height,tempp->height+1);
           // cout<<h<<endl;
            tempp->prev->height=h;
            tempp=tempp->prev;
        }
        // inorder(head);
        // cout<<endl;
        //cout<<tail->val<<" ";
        return tail;

     }   
        
};



class AVL
{
    public:
    bst b;

    void insert(int val)
    {
        int arr[2];
        int left,right;
        left=0;
        right=0;
        Node* taail;
        Node* target;
        target=NULL;
        taail=b.insertnode(val);
        //cout<<b.head->val<<endl;
        //cout<<taail->val<<endl;
        while(taail)
        {
            
            left=0;
            right=0;
            if(taail->prev!=NULL){
                taail=taail->prev;
               // cout<<taail->val<<endl;
            }
            else{
                taail=NULL;
                break;
            }
           
            if(!taail)
                break;    
            else
            {
                
                if(taail->left){
                   
                    left=taail->left->height;
                    //cout<<left<<endl;
                    }

            
                if(taail->right){
                    right=taail->right->height;
                   // cout<<right<<endl;
                }
                if((left-right)>1 || (right-left)>1)
                {
                   // cout<<left-right<<endl;
                    target=taail;
                   
                    break;
                }
            }
        }
       
        Node* temp3;
        temp3=target;
        if(taail==NULL)
            return;
        else
        {
            for(int i=0;i<2;i++)
            {if(temp3->val>=val)
            {
            
                arr[i]=1;
                temp3=temp3->left;
            }
            else
            {
                
                arr[i]=0;
                temp3=temp3->right;
            }
            }
        }
        Node* teempo;
        teempo=target;
        if(target->prev)
            teempo=target->prev;
       // cout<<target->val<<" "<<teempo->val<<endl;
        if(arr[0]==0)
        {
            if(arr[1]==0)
            {
                Node* aa=target->right;
                Node* bb=aa->left;
            
                if(target->val >= teempo->val)
                {
                   
                    aa->left=target;
                
                    target->right=bb;
            
                    if(teempo!=target)
                        teempo->right=aa;
                    else
                    {
                        b.head=aa;
                    }
                    int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    target->height=maxx(gh,ak)+1;
                    aa->height=maxx(target->height,zx)+1;
                    
                    target->prev=aa;
                    if(bb)
                        bb->prev=target;
                    if(teempo!=target)
                        aa->prev=teempo;
                    else
                    {
                        aa->prev=NULL;
                    }
                }
                else
                {
                   
                    aa->left=target;
                
                    target->right=bb;
            
                    if(teempo!=target)
                        teempo->left=aa;
                    else
                    {
                        b.head=aa;
                    }
                   int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                     target->height=maxx(gh,ak)+1;
                    aa->height=maxx(target->height,zx)+1;
                   
                    target->prev=aa;
                    if(bb)
                        bb->prev=target;
                    if(teempo!=target)
                        aa->prev=teempo;
                    else
                    {
                        aa->prev=NULL;
                    }
                }
            
            }
            else if(arr[1]==1)
            {
                Node *aa=target->right;
            
                Node* bb=aa->left;
        
                Node* a=bb->left;
    
                Node* b1=bb->right;
    
                target->right=bb;
                
                bb->right=aa;
               
                bb->left=a;
    
                aa->left=b1;
    
                if(target->val >= teempo->val)
                {
                   
                    bb->left=target;
                   
                    target->right=a;
        
                    if(teempo!=target)
                        teempo->right=bb;
                    else
                        b.head=bb;

                     int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    int hjh=0;
                    int kjjk=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                   

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    if(bb->left)
                        hjh=bb->left->height;
                    if(bb->right)
                        kjjk=bb->right->height;
                    aa->height=maxx(cd,zx)+1;
                    target->height=maxx(gh,ak)+1;
                    bb->height=maxx(aa->height,target->height)+1;
                    if(b1)
                        b1->prev=aa;
                    aa->prev=bb;
                    target->prev=bb;
                    if(a)
                        a->prev=target;

                    if(teempo!=target)
                        bb->prev=teempo;
                    else
                    {
                        bb->prev=NULL;
                    }
                }
                else{
                   
                    bb->left=target;
                
                    target->right=a;
        
                    teempo->left=bb;
                     int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    int hjh=0;
                    int kjjk=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                   

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    if(bb->left)
                        hjh=bb->left->height;
                    if(bb->right)
                        kjjk=bb->right->height;
                    aa->height=maxx(cd,zx)+1;
                    target->height=maxx(gh,ak)+1;
                    bb->height=maxx(aa->height,target->height)+1;

                    if(b1)
                        b1->prev=aa;
                    aa->prev=bb;
                    target->prev=bb;
                    if(a)
                        a->prev=target;
                        
                    if(teempo!=target)
                        bb->prev=teempo;
                    else
                    {
                        bb->prev=NULL;
                    }
                }
            }
        }
        else if(arr[0]==1)
        {
            if(arr[1]==1)
            {
        
                Node* aa=target->left;
    
                Node* bb=aa->right;

                if(target->val >= teempo->val)
                {
                    
                    aa->right=target;
                  
                    target->left=bb;
                    
                    if(teempo!=target)
                        teempo->right=bb;
                    else
                        b.head=bb;
                    int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    target->height=maxx(gh,ak)+1;
                    aa->height=maxx(cd,target->height)+1;
                    
                    target->prev=aa;
                    if(bb)
                        bb->prev=target;
                    if(teempo!=target)
                        aa->prev=teempo;
                    else
                    {
                        aa->prev=NULL;
                    }
                }
                else
                {
                    
                    aa->right=target;
                  
                    target->left=bb;
                
                    teempo->left=bb;
                    int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                         target->height=maxx(gh,ak)+1;
                    aa->height=maxx(cd,target->height)+1;
                   
                    target->prev=aa;
                    if(bb)
                        bb->prev=target;
                    if(teempo!=target)
                        aa->prev=teempo;
                    else
                    {
                        aa->prev=NULL;
                    }
                }
            }
            else if(arr[1]==0)
            {
                Node *aa=target->left;
             
                Node* bb=aa->right;
                
                Node* a=bb->right;
          
                Node* b1=bb->left;
            
                target->left=bb;
               
                bb->left=aa;
                
                bb->right=a;
           
                aa->right=b1;
               
                if(target->val >= teempo->val)
                {
                   
                    bb->right=target;
    
                    target->left=a;
                   
                    if(teempo!=target)
                        teempo->right=bb;
                    else
                        b.head=bb;
                    int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    int hjh=0;
                    int kjjk=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    if(bb->left)
                        hjh=bb->left->height;
                    if(bb->right)
                        kjjk=bb->right->height;
                    aa->height=maxx(cd,zx)+1;
                    target->height=maxx(gh,ak)+1;
                    bb->height=maxx(aa->height,target->height)+1;
                    if(b1)
                        b1->prev=aa;
                    aa->prev=bb;
                    target->prev=bb;
                    if(a)
                        a->prev=target;
                        
                    if(teempo!=target)
                        bb->prev=teempo;
                    else
                    {
                        bb->prev=NULL;
                    }

                }
                else{
                
                    bb->right=target;
                    
                    target->left=a;
                
                   teempo->left=bb;
                   int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    int hjh=0;
                    int kjjk=0;

                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    
                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    if(bb->left)
                        hjh=bb->left->height;
                    if(bb->right)
                        kjjk=bb->right->height;
                    aa->height=maxx(cd,zx)+1;
                    target->height=maxx(gh,ak)+1;
                    bb->height=maxx(aa->height,target->height)+1;

                    if(b1)
                        b1->prev=aa;
                    aa->prev=bb;
                    target->prev=bb;
                    if(a)
                        a->prev=target;
                        
                    if(teempo!=target)
                        bb->prev=teempo;
                    else
                    {
                        bb->prev=NULL;
                    }
                }
            }
        }
    }

    void dlt(int value)
    {
        Node* temp;
        Node* temp1;
        temp1=b.head;
        cout<<1<<endl;
        if(!temp1)
            return;
        while(temp1){                   //finding whether the required node exist 
        if(temp1->val == value)
        {
            cout<<2<<endl;
            temp=temp1;
            break;
        }
        else if(temp1->val > value) 
        {
            if(temp1->left)
            {
                cout<<3<<endl;
                temp1=temp1->left;
            }
            else
            {
                cout<<4<<endl;
                return;
            }
        } 
        else
        {
            if(temp1->right)
            {
                cout<<5<<endl;
                temp1=temp1->right;
            }
            else
            {
                cout<<6<<endl;
                return;
            }
        }
        }
        cout<<7<<endl;
        int right=0;
        int left=0;
        

        if(temp->left)                         //finding inorder predecessor or successor
        {
            cout<<8<<endl;
            left=1;
            temp=temp->left;
            if(temp->right)
            {    
                cout<<9<<endl;
                temp=temp->right;
                while(temp->right)
                {
                    cout<<10<<endl;
                    temp=temp->right;
                }
            }
            
        }
        else if(temp->right)
        {
            cout<<11<<endl;
            right=1;
            temp=temp->right;
            if(temp->left)
            {
                cout<<12<<endl;
                temp=temp->left;
                while(temp->left)
                {
                    cout<<13<<endl;
                    temp=temp->left;
                }
            }
        }
        temp1->val=temp->val;
         if(temp1 == temp)                        //deleting the node from bst
        {
            cout<<14<<endl;
            if(temp1->prev)
            {
                if(temp1->prev->val > temp->val)
                {
                    cout<<15<<endl;
                     temp1->prev->left=NULL;
                     int a=0;
                     if(temp->prev->right)
                        a=temp->prev->right->height;
                     temp1->prev->height=a+1;
                    
                }
            else{
                cout<<16<<endl;
                temp1->prev->right=NULL;
                int a=0;
                if(temp->prev->left)
                    a=temp->prev->left->height;
                temp1->prev->height=a+1;
                cout<<17<<endl;
                }
        }
        else
        {
            cout<<18<<endl;
            b.head=NULL;
            return;
        }
        }
        else
        {
            cout<<19<<endl;
            cout<<"temp"<<temp->val<<endl;
            temp1->val=temp->val;
            if(temp->prev)
            {if(temp->prev->val > temp->val)
               { temp->prev->left=NULL;
                 int a=0;
                 cout<<20<<endl;
                if(temp->prev->right)
                    a=temp->prev->right->height;
                temp->prev->height=a+1;
                temp=temp->prev;
                while(temp1!=temp)
                {
                    cout<<21<<endl;
                    int left=0;
                    int right=0;
                    if(temp->prev)
                        temp=temp->prev;
                    if(temp->right)
                        right=temp->right->height;
                    if(temp->left)
                        left=temp->left->height;
                    cout<<22<<endl;
                    temp->height=maxx(left,right)+1;
                }
               }
            else{
                
                    cout<<23<<endl;
                    cout<<temp->prev->val<<"hfjghf"<<endl;
                    cout<<temp->prev->left->val<<"hello"<<endl;;
                    temp->prev->right=NULL;
                    int a=0;
                    cout<<"z"<<endl;
                    if(temp->prev->left)
                        a=temp->prev->left->height;
                    temp->prev->height=a+1;
                    if(temp->prev)
                        temp=temp->prev;
                    cout<<"aaaaa"<<temp->val<<endl;
                    cout<<24<<endl;
                
                while(temp1!=temp)
                {
                    cout<<25<<endl;
                    int left=0;
                    int right=0;
                    if(temp->prev)
                        temp=temp->prev;
                    if(temp->right)
                        right=temp->right->height;
                    if(temp->left)
                        left=temp->left->height;
                    cout<<26<<endl;
                    temp->height=maxx(left,right)+1;
                }
            }
            }
        }
                 while(b.head!=temp)
                {
                    cout<<27<<endl;
                    int left=0;
                    int right=0;
                    if(temp->prev)
                        temp=temp->prev;
                    if(temp->right)
                        right=temp->right->height;
                    if(temp->left)
                        left=temp->left->height;
                    cout<<28<<endl;
                    temp->height=maxx(left,right)+1;
                }

            
            Node* taail=temp1;
            int arr[2];

     while(taail){
            while(taail)                 //balance factor from target to root 
        {
            cout<<29<<endl;
            
            int left=0;
            int right=0;
            
           
            if(!taail)
                break;    
            else
            {
                
                if(taail->left){
                   cout<<30<<endl;
                    left=taail->left->height;
                    //cout<<left<<endl;
                    }

            
                if(taail->right){
                    right=taail->right->height;
                    cout<<31<<endl;
                   // cout<<right<<endl;
                }
                if((left-right)>1 || (right-left)>1)
                {
                   cout<<32<<endl;
                    break;
                }
            }
            if(taail->prev!=NULL){
                taail=taail->prev;
                cout<<33<<endl;
               // cout<<taail->val<<endl;
            }
            else{
                taail=NULL;
                cout<<34<<endl;
                break;
            }
        }

        Node* tarun=taail;

        if(taail==NULL)
            return;
        else
        {
            for(int i=0;i<2;i++)
            {
                int d=0;
                
                if(taail->left){
                    cout<<35<<endl;
                    left=taail->left->height;
                    }

            
                if(taail->right){
                    cout<<36<<endl;
                    right=taail->right->height;

                }
                if((left-right)>1 || (right-left)>1)
                {
                    cout<<37<<endl;
                     d=left-right;
                }
            if(d>=0)
            {
                cout<<38<<endl;
                arr[i]=1;
                taail=taail->left;
            }
            else 
            {
                cout<<39<<endl;
                arr[i]=0;
                taail=taail->right;
            }
            }
        }
        Node* teempo,*target;
        target=tarun;
        teempo=target;
        if(target->prev)
            teempo=target->prev;
       // cout<<target->val<<" "<<teempo->val<<endl;
        if(arr[0]==0)
        {
            if(arr[1]==0)
            {
                Node* aa=target->right;
                Node* bb=aa->left;
            
                if(target->val >= teempo->val)
                {
                   
                    aa->left=target;
                
                    target->right=bb;
            
                    if(teempo!=target)
                        {
                            teempo->right=aa;
                            taail=teempo;
                        }
                    else
                    {
                        b.head=aa;
                        taail=NULL;
                    }
                    int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    target->height=maxx(gh,ak)+1;
                    aa->height=maxx(target->height,zx)+1;
                    
                    target->prev=aa;
                    if(bb)
                        bb->prev=target;
                    if(teempo!=target)
                        aa->prev=teempo;
                    else
                    {
                        aa->prev=NULL;
                    }
                }
                else
                {
                   
                    aa->left=target;
                
                    target->right=bb;
            
                    if(teempo!=target)
                        {
                            teempo->left=aa;
                            taail=teempo;
                        }
                    else
                    {
                        b.head=aa;
                        taail=NULL;
                    }
                   int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                     target->height=maxx(gh,ak)+1;
                    aa->height=maxx(target->height,zx)+1;
                   
                    target->prev=aa;
                    if(bb)
                        bb->prev=target;
                    if(teempo!=target)
                        aa->prev=teempo;
                    else
                    {
                        aa->prev=NULL;
                    }
                }
            
            }
            else if(arr[1]==1)
            {
                Node *aa=target->right;
            
                Node* bb=aa->left;
        
                Node* a=bb->left;
    
                Node* b1=bb->right;
    
                target->right=bb;
                
                bb->right=aa;
               
                bb->left=a;
    
                aa->left=b1;
    
                if(target->val >= teempo->val)
                {
                   
                    bb->left=target;
                   
                    target->right=a;
        
                    if(teempo!=target)
                        {
                            teempo->right=bb;
                            taail=teempo;
                        }
                    else
                        {
                            b.head=bb;
                            taail=NULL;
                        }

                     int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    int hjh=0;
                    int kjjk=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                   

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    if(bb->left)
                        hjh=bb->left->height;
                    if(bb->right)
                        kjjk=bb->right->height;
                    aa->height=maxx(cd,zx)+1;
                    target->height=maxx(gh,ak)+1;
                    bb->height=maxx(aa->height,target->height)+1;
                    if(b1)
                        b1->prev=aa;
                    aa->prev=bb;
                    target->prev=bb;
                    if(a)
                        a->prev=target;

                    if(teempo!=target)
                        bb->prev=teempo;
                    else
                    {
                        bb->prev=NULL;
                    }
                }
                else{
                   
                    bb->left=target;
                
                    target->right=a;
                    if(teempo!=target)
                    {
                        teempo->left=bb;
                        taail=teempo;
                    }
                    else
                    {
                        b.head=bb;
                        taail=NULL;
                    }
                    teempo->left=bb;
                     int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    int hjh=0;
                    int kjjk=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                   

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    if(bb->left)
                        hjh=bb->left->height;
                    if(bb->right)
                        kjjk=bb->right->height;
                    aa->height=maxx(cd,zx)+1;
                    target->height=maxx(gh,ak)+1;
                    bb->height=maxx(aa->height,target->height)+1;

                    if(b1)
                        b1->prev=aa;
                    aa->prev=bb;
                    target->prev=bb;
                    if(a)
                        a->prev=target;
                        
                    if(teempo!=target)
                    {
                        bb->prev=teempo;
                    }
                    else
                    {
                        bb->prev=NULL;
                    }
                }
            }
        }
        else if(arr[0]==1)
        {
            if(arr[1]==1)
            {
        
                Node* aa=target->left;
    
                Node* bb=aa->right;

                if(target->val >= teempo->val)
                {
                    
                    aa->right=target;
                  
                    target->left=bb;
                    
                    if(teempo!=target)
                        {
                            teempo->right=bb;
                            taail=teempo;
                        }
                    else
                        {
                            b.head=bb;
                            taail=NULL;
                        }
                    int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    target->height=maxx(gh,ak)+1;
                    aa->height=maxx(cd,target->height)+1;
                    
                    target->prev=aa;
                    if(bb)
                        bb->prev=target;
                    if(teempo!=target)
                        aa->prev=teempo;
                    else
                    {
                        aa->prev=NULL;
                    }
                }
                else
                {
                    
                    aa->right=target;
                  
                    target->left=bb;

                    teempo->left=bb;
                    taail=teempo;
                    int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                         target->height=maxx(gh,ak)+1;
                    aa->height=maxx(cd,target->height)+1;
                   
                    target->prev=aa;
                    if(bb)
                        bb->prev=target;
                    if(teempo!=target)
                        aa->prev=teempo;
                    else
                    {
                        aa->prev=NULL;
                    }
                }
            }
            else if(arr[1]==0)
            {
                Node *aa=target->left;
             
                Node* bb=aa->right;
                
                Node* a=bb->right;
          
                Node* b1=bb->left;
            
                target->left=bb;
               
                bb->left=aa;
                
                bb->right=a;
           
                aa->right=b1;
               
                if(target->val >= teempo->val)
                {
                   
                    bb->right=target;
    
                    target->left=a;
                   
                    if(teempo!=target)
                        {
                            teempo->right=bb;
                            taail=teempo;
                        }
                    else
                        {
                            b.head=bb;
                            taail=NULL;
                        }
                    int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    int hjh=0;
                    int kjjk=0;
                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    if(bb->left)
                        hjh=bb->left->height;
                    if(bb->right)
                        kjjk=bb->right->height;
                    aa->height=maxx(cd,zx)+1;
                    target->height=maxx(gh,ak)+1;
                    bb->height=maxx(aa->height,target->height)+1;
                    if(b1)
                        b1->prev=aa;
                    aa->prev=bb;
                    target->prev=bb;
                    if(a)
                        a->prev=target;
                        
                    if(teempo!=target)
                        bb->prev=teempo;
                    else
                    {
                        bb->prev=NULL;
                    }

                }
                else{
                
                    bb->right=target;
                    
                    target->left=a;
                
                   teempo->left=bb;
                   taail=teempo;
                   int cd=0;
                    int zx=0;
                    int gh=0;
                    int ak=0;
                    int hjh=0;
                    int kjjk=0;

                    if(aa->left)
                        cd=aa->left->height;
                    if(aa->right)
                        zx=aa->right->height;

                    
                    if(target->left)
                        gh=target->left->height;
                    if(target->right)
                        ak=target->right->height;
                    if(bb->left)
                        hjh=bb->left->height;
                    if(bb->right)
                        kjjk=bb->right->height;
                    aa->height=maxx(cd,zx)+1;
                    target->height=maxx(gh,ak)+1;
                    bb->height=maxx(aa->height,target->height)+1;

                    if(b1)
                        b1->prev=aa;
                    aa->prev=bb;
                    target->prev=bb;
                    if(a)
                        a->prev=target;
                        
                    if(teempo!=target)
                        bb->prev=teempo;
                    else
                    {
                        bb->prev=NULL;
                    }
                }
            }


        
        }
     }
        
     }


    void preorder(Node* jj)
    {
        cout<<jj->val<<" ";
        if(jj->left)
            preorder(jj->left);
        if(jj->right)
            preorder(jj->right);
    }

    void inorder(Node* jj)
    {
        if(jj->left)
            inorder(jj->left);
        cout<<jj->val<<" ";
        if(jj->right)
            inorder(jj->right);
        
    }
    
};


int main()
{
    AVL avl;
    avl.insert(1);
    avl.insert(19);
    avl.insert(10);
    avl.insert(15);
    avl.insert(23);
    avl.insert(30);
    avl.insert(28);
    // avl.insert(5);
    // avl.insert(25);
    // avl.insert(19);
    avl.dlt(19);
    avl.dlt(1);
    avl.dlt(10);
    //cout<<endl;
    //cout<<avl.b.head->left->right->val<<endl;
    cout<<"inorder :"<<endl;
   avl.inorder(avl.b.head);
   cout<<endl;
   cout<<"preorder :"<<endl;
   avl.preorder(avl.b.head);
   cout<<endl;
   cout<<avl.b.head->val<<endl;
    return 0;
}