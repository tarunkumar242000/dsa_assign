#include<iostream>
using namespace std;

//int size=0;



class sparse
{
    public:
    int **sp;
    int row=0;
    int col=0;
    int cap=10;
    int size=0;
    
            sparse(int roow,int coolumn)
            {
                row=roow;
                col=coolumn;
                sp=new int*[cap];

                for(int i=0;i<cap;i++)
                {
                    sp[i]=new int[3];
                }

            }

            void in_sparse(int roow,int col,int val)
            {
                if(size==cap)
                {
                    int a;
                    a=2*cap;
                    int **temp=new int*[a];

                    for(int i=0;i<a;i++)
                        temp[i]=new int[3];
                    

                    for(int i=0;i<cap;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            temp[i][j]=sp[i][j];
                        }
                    }
                    temp[cap][0]=roow;
                    temp[cap][1]=col;
                    temp[cap][2]=val;
                    size++;
                    cap=a;
                    sp=temp;

                }
                else
                {
                    sp[size][0]=roow;
                    sp[size][1]=col;
                    sp[size][2]=val;
                    size++;
                }

            }
            sparse addition(sparse sp2)
            {
                sparse sp3(row,col);
               // cout <<1<<endl;
                int ab=0;
                //cout<<2<<endl;
                int index1=0,index2=0;
                for( ;index1<size,index2<sp2.size;ab++)
                {
                    //cout<<3<<endl;
                    if(sp[index1][0]==sp2.sp[index2][0])
                    {
                        //cout<<4<<endl;
                        if(sp[index1][1]==sp2.sp[index2][1])
                        {
                            //<<5<<endl;
                            sp[index1][2]=sp[index1][2]+sp2.sp[index2][2];
                            //cout<<6<<endl;
                            sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                            //cout<<7<<endl;
                            index1++;
                            index2++;
                        }
                        else if(sp[index1][1]>sp2.sp[index2][1])
                        {
                            //cout<<9<<endl;
                            sp3.in_sparse(sp2.sp[index2][0],sp2.sp[index2][1],sp2.sp[index2][2]);
                            //cout<<10<<endl;
                            index2++;
                        }
                        else
                        {
                            //cout<<12<<endl;
                            sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                            //cout<<13<<endl;
                            index1++;
                        }
                        //cout<<14<<endl;
                    }
                    else if(sp[index1][0]>sp2.sp[index2][0])
                    {
                        //cout<<16<<endl;
                        while(sp[index1][0]>sp2.sp[index2][0])
                        {
                            //cout<<17<<endl;
                            sp3.in_sparse(sp2.sp[index2][0],sp2.sp[index2][1],sp2.sp[index2][2]);
                           // cout<<18<<endl;
                            index2++;
                           // cout<<19<<endl;
                        }
                    }
                    else{
                        //cout<<21<<endl;
                        while(sp[index1][0]<sp2.sp[index2][0])
                        {
                           // cout<<21<<endl;
                            sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                          //  cout<<22<<endl;
                            index1++;
                        }
                       // cout<<23<<endl;
                    }
                   // cout<<24<<endl;
                }
                //cout<<25<<endl;
                while(index1<size)
                {
                   // cout<<26<<endl;
                        sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                            index1++;
                        //cout<<27<<endl;

                }
                while(index2<sp2.size)
                {
                   // cout<<28<<endl;
                    sp3.in_sparse(sp2.sp[index2][0],sp2.sp[index2][1],sp2.sp[index2][2]);
                    //cout<<29<<endl;
                            index2++;
                }
               // cout<<30<<endl;
                return sp3;
            }
            
            sparse transpose_matrix()
            {
                sparse ss(row,col);
            
                int temp;
                
                ss.in_sparse(sp[0][1],sp[0][0],sp[0][2]);
                for(int i=1;i<size;i++)
                {
                    temp=i;
                    int j=i;
                    int casu=0;
                    while(temp--)
                    {
                        int aaaa=0;
                        int bbbb=0;
                        
                        if(casu)
                            bbbb=ss.sp[j][1];
                        else
                            bbbb=sp[j][0];
                        
                        if(casu)
                             aaaa=ss.sp[j][0];
                        else
                             aaaa=sp[j][1];
        
                        if(aaaa<ss.sp[temp][0])
                        {
                        
                            int a,b,c;
                            a=ss.sp[temp][0];
                            b=ss.sp[temp][1];
                            c=ss.sp[temp][2];
                    
                            
                           if(casu)
                           {ss.sp[temp][0]=ss.sp[j][0];
                           ss.sp[temp][1]=ss.sp[j][1];
                           ss.sp[temp][2]=ss.sp[j][2];}
                            else
                            {
                             ss.sp[temp][0]=sp[j][1];
                           ss.sp[temp][1]=sp[j][0];
                           ss.sp[temp][2]=sp[j][2];   
                            }
                           
                            if(casu==0)
                                ss.in_sparse(a,b,c);
                            else
                                {
                                    ss.sp[temp+1][0]=a;
                                    ss.sp[temp+1][1]=b;
                                    ss.sp[temp+1][2]=c;
                                }
                            casu=1;
                            j--;
                        }
                        else if(aaaa==ss.sp[temp][0]){
                         if(bbbb<ss.sp[temp][1])
                        {
                        
                            int a,b,c;
                            a=ss.sp[temp][0];
                            b=ss.sp[temp][1];
                            c=ss.sp[temp][2];
                           
                            if(casu)
                            {ss.sp[temp][0]=ss.sp[j][0];
                            ss.sp[temp][1]=ss.sp[j][1];
                            ss.sp[temp][2]=ss.sp[j][2];}
                            else
                            {
                                ss.sp[temp][0]=sp[j][1];
                                ss.sp[temp][1]=sp[j][0];
                                ss.sp[temp][2]=sp[j][2];
                            }
                           
                            if(casu==0)
                                  ss.in_sparse(a,b,c);
                            else
                            {
                                ss.sp[temp+1][0]=a;
                                ss.sp[temp+1][1]=b;
                                ss.sp[temp+1][2]=c;   
                            }
                            casu=1;
                            j--;
                        }
                        else
                            {
                               
                                    if(casu==0)
                                        ss.in_sparse(sp[j][1],sp[j][0],sp[j][2]);

                                break;
                            }
                        }
                        else
                        {
                               
                                if(casu==0)
                                    ss.in_sparse(sp[j][1],sp[j][0],sp[j][2]);

                                break;
                        }
                    }
                }
                return ss;
                
            }
            sparse multiplication(sparse sp2)
            {
                //cout<<1<<endl;
                sparse sp3(row,col);
                int sum=0;
                int temp;
                int index1=0;
                int index2=0;
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<sp2.col;j++)
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
                                
                                    
                                if(sp[index1][0]==row1 && sp[index1][1]==col1)
                                {
                                    a1=sp[index1][2];
                                    
                                    break;
                                }
                                else
                                    index1++;
                            }
                            index1=0;
                            while(index2<sp2.size)
                            {
                                
                                        
                                if(sp2.sp[index2][0]==row2 && sp2.sp[index2][1]==col2)
                                {
                                    a2=sp2.sp[index2][2];
                                    break;
                                }
                                else{
                                    index2++;
                                }
                            }
                            index2=0;
                            temp+=a1*a2;
                        }
                        sp3.in_sparse(i,j,temp);
                    }
                }
                return sp3;
            }

            void display1()
            {
                for(int i=0;i<size;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        cout<<sp[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            

            void display()
            {

               int m=0;
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<col;j++)
                    {
                        if(sp[m][0]==i && sp[m][1]==j)
                            {
                                cout<<sp[m][2]<<" ";
                                if(i<size)
                                    m++;
                            }
        
                        else if(sp[m][0]==i && sp[m][1]<j)
                        {
                            while(i<size && sp[m][0]==i && sp[m][1]<j)
                            {
                                cout<<0<<" ";
                                if(i<size)
                                    i++;
                            }
                            if(sp[m][0]==i && sp[m][1]==j)
                            {
                                cout<<sp[m][2]<<" ";
                                if(i<size)
                                    i++;
                            }
                        }
                        else
                        {
                            cout<<0<<" ";
                        }
                    }
                    cout<<endl;
                }
            }


            void display_transpose()
            {
               int m=0;
                for(int i=0;i<col;i++)
                {
                    for(int j=0;j<row;j++)
                    {
                        if(sp[m][0]==i && sp[m][1]==j)
                            {
                                cout<<sp[m][2]<<" ";
                                if(i<size)
                                    m++;
                            }
        
                        else if(sp[m][0]==i && sp[m][1]<j)
                        {
                            while(i<size && sp[m][0]==i && sp[m][1]<j)
                            {
                                cout<<0<<" ";
                                if(i<size)
                                    i++;
                            }
                            if(sp[m][0]==i && sp[m][1]==j)
                            {
                                cout<<sp[m][2]<<" ";
                                if(i<size)
                                    i++;
                            }
                        }
                        else
                        {
                            cout<<0<<" ";
                        }
                    }
                    cout<<endl;
                }
            } 
                                    
};

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
                link l3(row,l2.col);
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

            link transpose()
            {
                link ll(row,col);
                Node* temp_l;
                Node* temp_ll;
                temp_l=l.head;
                temp_ll=ll.l.head;
                sparse linked(row,col);
                sparse linked1(row,col);
                for(int i=0;i<size;i++)
                {
                    linked.in_sparse(temp_l->row,temp_l->col,temp_l->val);
                    temp_l=temp_l->next;
                }
                linked1=linked.transpose_matrix();
               
                for(int i=0;i<linked.size;i++)
                    ll.insert(linked1.sp[i][0],linked1.sp[i][1],linked1.sp[i][2]);
                return ll;
                
            }

            void display1()
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

            void display()
            {
                Node* temp;
                temp=l.head;
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<col;j++)
                    {
                        if(temp->row==i && temp->col==j)
                            {
                                cout<<temp->val<<" ";
                                if(i<size)
                                    temp=temp->next;
                            }
        
                        else if(temp->row==i && temp->col<j)
                        {
                            while(i<size && temp->row==i && temp->col<j)
                            {
                                cout<<0<<" ";
                                if(i<size)
                                    i++;
                            }
                            if(temp->row==i && temp->col==j)
                            {
                                cout<<temp->val<<" ";
                                if(i<size)
                                    i++;
                            }
                        }
                        else
                        {
                            cout<<0<<" ";
                        }
                    }
                    cout<<endl;
                }
            }

                void t_disp()
            {
                 Node* temp;
                temp=l.head;
                for(int i=0;i<col;i++)
                {
                    for(int j=0;j<row;j++)
                    {
                        if(temp->row==i && temp->col==j)
                            {
                                cout<<temp->val<<" ";
                                if(i<size)
                                    temp=temp->next;
                            }
        
                        else if(temp->row==i && temp->col<j)
                        {
                            while(i<size && temp->row==i && temp->col<j)
                            {
                                cout<<0<<" ";
                                if(i<size)
                                    i++;
                            }
                            if(temp->row==i && temp->col==j)
                            {
                                cout<<temp->val<<" ";
                                if(i<size)
                                    i++;
                            }
                        }
                        else
                        {
                            cout<<0<<" ";
                        }
                    }
                    cout<<endl;
                }
            }
            
};




int main()
{
    int t;
    cin >>t;
    if(t==0)
    {
        int o;
        cin>>o;
        if(o==1)        //addition
        {
            int n1,m1;
            cin>>n1>>m1; 
            sparse sp1(n1,m1);
            for(int i=0;i<n1;i++)
    
        for(int j=0;j<m1;j++)
        {
            int a;
            cin>>a;
            if(a!=0)
            {
                sp1.in_sparse(i,j,a);
            }
        }
            int n2,m2;
            cin>>n2>>m2;
            sparse sp2(n2,m2);
            for(int i=0;i<n2;i++)
    
            for(int j=0;j<m2;j++)
            {
                int a;
                cin>>a;
                if(a!=0)
                {
                    sp2.in_sparse(i,j,a);
                }

            }
            sparse sp3(n1,m1);
            sp3=sp1.addition(sp2);
            cout<<endl<<endl;
            sp3.display();
        }
        else if(o==2)   //transpose
        {
            int n1,m1;
            cin>>n1>>m1; 
            sparse sp1(n1,m1);
            for(int i=0;i<n1;i++)
    
        for(int j=0;j<m1;j++)
        {
            int a;
            cin>>a;
            if(a!=0)
            {
                sp1.in_sparse(i,j,a);
            }
        }
        sparse sp3(m1,n1);
        sp3=sp1.transpose_matrix();
        cout<<endl<<endl;
        sp3.display_transpose();
        }
        else            //multiplication
        {
            int n1,m1;
            cin>>n1>>m1; 
            sparse sp1(n1,m1);
            for(int i=0;i<n1;i++)
        {
        for(int j=0;j<m1;j++)
        {
            int a;
            cin>>a;
            if(a!=0)
            {
                sp1.in_sparse(i,j,a);
            }
        }
        }
            int n2,m2;
            cin>>n2>>m2;
            sparse sp2(n2,m2);
            for(int i=0;i<n2;i++)
            {
            for(int j=0;j<m2;j++)
            {
                int a;
                cin>>a;
                if(a!=0)
                {
                    sp2.in_sparse(i,j,a);
                }

            }
            }
            sparse sp3(n1,m2);
            sp3=sp1.multiplication(sp2);
            cout<<endl<<endl;
            sp3.display();
        }
    }
    else
    {
        int o;
        cin>>o;
        if(o==1)    //addition
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
            l3=l1.addition(l2);
            cout<<endl<<endl;
            l3.display();
        }
        else if(o==2) //transpose
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

            link l3(col1,row1);
            l3=l1.transpose();
            cout<<endl<<endl;
            l3.t_disp();
        }
        else       //multiplication
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
            l3=l1.muliplication(l2);
            cout<<endl<<endl;
            l3.display();

     }

    }
     return 0;
}