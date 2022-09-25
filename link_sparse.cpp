#include<iostream>
using namespace std;


class Node
{
    public:
        int row,col,val;
        Node* next;

        Node()
        {
            row=0;
            col=0;
            val=0;
            next=NULL;
        }

        Node(int roo,int cool,int vaal)
        {
            row=roo;
            col=cool;
            val=vaal;
            next=NULL;
        }
};

class linkedlist
{
    public:

    Node* head;
    linkedlist()
    {
        head=NULL;
    }    

     void insertnode(int ro,int coll,int vval)
     {
        Node* temp=new Node(ro,coll,vval);

        if(head==NULL)
        {
            head=temp;
            return ;
        }

        Node* temp1=head;
        while(temp1->next !=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
     }   
        
};


class link
{
    public:
        int row,col,size=0;
         linkedlist l;
            link(int a,int b)
            {
                row=a;
                col=b;
            }

            void insert(int roow,int cool,int val)
            {
                l.insertnode(roow,cool,val);
                size++;
            }

            link addition(link l2)
            {
                link l3(row,col);
                int a;
                a=0;
                Node* temp1;
                Node* temp2;
                temp1=l.head;
                //cout<<1<<endl;
                temp2=l2.l.head;
                //cout<<2<<endl;
                int index1=0,index2=0;
                for(;index1<size,index2<l2.size;a++)
                {
                    //cout<<3<<endl;
                    if(temp1->row==temp2->row)
                    {
                        //cout<<4<<endl;
                        
                        if(temp1->col==temp2->col)
                        {
                            //cout<<5<<endl;
                            //sp[index1][2]=sp[index1][2]+sp2.sp[index2][2];
                            temp1->val=temp1->val + temp2->val;
                            //cout<<6<<endl;
                            //sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                            l3.insert(temp1->row,temp1->col,temp1->val);
                            //cout<<7<<endl;
                            temp1=temp1->next;
                            //cout<<8<<endl;
                            temp2=temp2->next;
                            //cout<<9<<endl;
                            index1++;
                            index2++;
                        }
                        else if(temp1->col>temp2->col)
                        {
                            //cout<<10<<endl;
                           // sp3.in_sparse(sp2.sp[index2][0],sp2.sp[index2][1],sp2.sp[index2][2]);
                            l3.insert(temp2->row,temp2->col,temp2->val);
                            cout<<11<<endl;
                            temp2=temp2->next;
                            //cout<<12<<endl;
                            index2++;
                        }
                        else
                        {
                            //cout<<13<<endl;
                            //sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                            l3.insert(temp1->row,temp1->col,temp1->val);
                           // cout<<14<<endl;
                            temp1=temp1->next;
                            //cout<<15<<endl;
                            index1++;
                        }
                        
                    }
                    else if(temp1->row > temp2->row)
                    {
                        //cout<<16<<endl;
                        while(temp1->row > temp2->row)
                        {
                            //cout<<17<<endl;
                            //sp3.in_sparse(sp2.sp[index2][0],sp2.sp[index2][1],sp2.sp[index2][2]);
                            l3.insert(temp2->row,temp2->col,temp2->val);
                            //cout<<18<<endl;
                            temp2=temp2->next;
                           // cout<<19<<endl;
                            index2++;
                           
                        }
                    }
                    else{
                        //cout<<20<<endl;
                        while(temp1->row < temp2->row)
                        {
                          // cout<<21<<endl;
                            //sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                            l3.insert(temp1->row,temp1->col,temp1->val);
                           // cout<<22<<endl;
                            temp1=temp1->next;
                            //cout<<23<<endl;
                            index1++;
                        }
                
                    }
                   
                }
                
                while(temp1!=NULL)
                {
                   
                        //sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                        l3.insert(temp1->row,temp1->col,temp1->val);
                       // cout<<24<<endl;
                        temp1=temp1->next;
                       // cout<<25<<endl;
                            index1++;
                        

                }
                
                
                while(temp2!=NULL)
                {
                  // cout<<26<<endl;
                   // sp3.in_sparse(sp2.sp[index2][0],sp2.sp[index2][1],sp2.sp[index2][2]);
                    l3.insert(temp2->row,temp2->col,temp2->val);
                   // cout<<27<<endl;
                    temp2=temp2->next;
                   // cout<<28<<endl;
                            index2++;
                }
               
                return l3;
            }
                
            link muliplication(link l2)
            {
                link l3(row,col);
                int temp;
                int index1=0;
                int index2=0;
                Node* temp1;
                Node* temp2;
                temp1=l.head;
                temp2=l2.l.head;
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<l2.col;j++)
                    {
                        int row1,col1,row2,col2;
                        row1=i;
                        col2=j;
                        temp=0;
                        int a1,a2;

                        for(col1=0;col1<col;col1++)
                        {
                            a1=0;
                            a2=0;
                            row2=col1;
                            while(index1<size)
                            {
                                    
                              if(temp1->row == row1 && temp1->col == col1)
                                {
                                    a1=temp1->val;
                                    
                                    break;
                                }
                                else
                                    {
                                        index1++;
                                        temp1=temp1->next;
                                    }
                            }
                            index1=0;
                            temp1=l.head;
                            while(index2<l2.size)
                            {
                                
                                        
                                if(temp2->row == row2 && temp2->col == col2)
                                {
                                    a2=temp2->val;
                                    break;
                                }
                                else{
                                    temp2=temp2->next;
                                    index2++;
                                }
                            }
                            index2=0;
                            temp2=l2.l.head;
                            temp+=a1*a2;
                        }
                        l3.insert(i,j,temp);
                    }
                }
                return l3;
            }

            // link transpose()
            // {
            //     link ll(row,col);
            //     link temp1(row,col);
            //     int temp;
            //     ll.insert(l.head->row,l.head->col,l.head->val);
            //     Node* lll;
            //     Node* lo;
            //     lo=l.head; //original matrix
            //     lll=ll.l.head; //other matrix
            //     lo=lo->next;
            //     for(int i=1;i<size;i++)
            //     {
            //         temp=i;
            //         while(temp--)
            //         {
            //              if(lo->col < lll->row)
            //              {
            //                 if(ll.l.head==lll)
            //                 {
                                
            //                 }
                            
            //              }
            //         }
            //     }
            // }
            void display()
            {
                Node* temp;
                temp=l.head;
                for(int i=0;i<size;i++)
                {
                    cout<<temp->row<<" ";
                    cout<<temp->col<<" ";
                    cout<<temp->val<<" ";
                    temp=temp->next;
                    cout<<endl;
                }
            }
};


int main()
{
    int row1,col1;
    cin>>row1>>col1;
    link l1(row1,col1);
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            int a;
            cin>>a;
            if(a!=0)
            {
                l1.insert(i,j,a);
            }
        }
    }


    int row2,col2;
    cin>>row2>>col2;
    link l2(row2,col2);
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            int a;
            cin>>a;
            if(a!=0)
            {
                l2.insert(i,j,a);
            }
        }
    }
    link l3(row1,col1);
    // l3=l1.addition(l2);
    l3=l1.muliplication(l2);
    l3.display();
}