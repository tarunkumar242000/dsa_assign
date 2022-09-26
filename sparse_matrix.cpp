#include<iostream>
using namespace std;

//int size=0;


template<typename T>
class sparse
{
    public:
    T **sp;
    T row=0;
    T col=0;
    int cap=10;
    int size=0;
    
            sparse<T>(T roow,T coolumn)
            {
                row=roow;
                col=coolumn;
                sp=new T*[cap];

                for(int i=0;i<cap;i++)
                {
                    sp[i]=new T[3];
                }

            }

            void in_sparse(T roow,T col,T val)
            {
                if(size==cap)
                {
                    int a;
                    a=2*cap;
                    T **temp=new T*[a];

                    for(int i=0;i<a;i++)
                        temp[i]=new T[3];
                    

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
            sparse<T> addition(sparse<T> sp2)
            {
                sparse<T>sp3(row,col);
               // cout <<1<<endl;
                int ab=0;
                //cout<<2<<endl;
                int index1=0,index2=0;
                for( ;index1<(int)size,index2<(int)sp2.size;ab++)
                {
                    //cout<<3<<endl;
                    if((int)sp[index1][0]==(int)sp2.sp[index2][0])
                    {
                        //cout<<4<<endl;
                        if((int)sp[index1][1]==(int)sp2.sp[index2][1])
                        {
                            //<<5<<endl;
                            sp[index1][2]=sp[index1][2]+sp2.sp[index2][2];
                            //cout<<6<<endl;
                            sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                            //cout<<7<<endl;
                            index1++;
                            index2++;
                        }
                        else if((int)sp[index1][1]>(int)sp2.sp[index2][1])
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
                    else if((int)sp[index1][0]>(int)sp2.sp[index2][0])
                    {
                        //cout<<16<<endl;
                        while((int)sp[index1][0]>(int)sp2.sp[index2][0])
                        {
                            //cout<<17<<endl;
                            sp3.in_sparse(sp2.sp[index2][0],sp2.sp[index2][1],sp2.sp[index2][2]);
                           // cout<<18<<endl;
                            index2++;
                           // cout<<19<<endl;
                        }
                    }
                    else{
                        //co1<<enut<<2dl;
                        while((int)sp[index1][0]<(int)sp2.sp[index2][0])
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
                while(index1<(int)size)
                {
                   // cout<<26<<endl;
                        sp3.in_sparse(sp[index1][0],sp[index1][1],sp[index1][2]);
                            index1++;
                        //cout<<27<<endl;

                }
                while(index2<(int)sp2.size)
                {
                   // cout<<28<<endl;
                    sp3.in_sparse(sp2.sp[index2][0],sp2.sp[index2][1],sp2.sp[index2][2]);
                    //cout<<29<<endl;
                            index2++;
                }
               // cout<<30<<endl;
                return sp3;
            }
            
            sparse<T> transpose_matrix()
            {
                sparse<T>ss(row,col);
            
                int temp;
                
                ss.in_sparse(sp[0][1],sp[0][0],sp[0][2]);
                for(int i=1;i<(int)size;i++)
                {
                    temp=i;
                    int j=i;
                    int casu=0;
                    while(temp--)
                    {
                        T aaaa;
                        T bbbb;
                        
                        if(casu)
                            bbbb=ss.sp[j][1];
                        else
                            bbbb=sp[j][0];
                        
                        if(casu)
                             aaaa=ss.sp[j][0];
                        else
                             aaaa=sp[j][1];
        
                        if((int)aaaa<(int)ss.sp[temp][0])
                        {
                        
                            T a,b,c;
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
                        else if((int)aaaa==(int)ss.sp[temp][0]){
                         if((int)bbbb<(int)ss.sp[temp][1])
                        {
                        
                            T a,b,c;
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
            sparse<T> multiplication(sparse<T>sp2)
            {
                //cout<<1<<endl;
                sparse<T>sp3(row,col);
                T sum=0;
                T temp;
                int index1=0;
                int index2=0;
                for(int i=0;i<(int)row;i++)
                {
                    for(int j=0;j<(int)sp2.col;j++)
                    {
                        int row1,col1,row2,col2;
                        row1=i;
                        col2=j;
                        temp=0;
                        T a1,a2;
                        for(col1=0;col1<col;col1++)
                        {
                            a1=0;
                            a2=0;
                            row2=col1;
                            while(index1<(int)size)
                            {
                                
                                    
                                if((int)sp[index1][0]==(int)row1 && (int)sp[index1][1]==(int)col1)
                                {
                                    a1=sp[index1][2];
                                    
                                    break;
                                }
                                else
                                    index1++;
                            }
                            index1=0;
                            while((int)index2<(int)sp2.size)
                            {
                                
                                        
                                if((int)sp2.sp[index2][0]==(int)row2 && (int)sp2.sp[index2][1]==(int)col2)
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
                        sp3.in_sparse(T(i),T(j),temp);
                    }
                }
                return sp3;
            }

            void display1()
            {
                for(int i=0;i<(int)size;i++)
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
                for(int i=0;i<(int)row;i++)
                {
                    for(int j=0;j<(int)col;j++)
                    {
                        if((int)sp[m][0]==i && (int)sp[m][1]==j)
                            {
                                cout<<sp[m][2]<<" ";
                                if(i<size)
                                    m++;
                            }
        
                        else if((int)sp[m][0]==i && (int)sp[m][1]<j)
                        {
                            while(i<(int)size && (int)sp[m][0]==i && (int)sp[m][1]<j)
                            {
                                cout<<0<<" ";
                                if(i<size)
                                    i++;
                            }
                            if((int)sp[m][0]==i && (int)sp[m][1]==j)
                            {
                                cout<<sp[m][2]<<" ";
                                if(i<size)
                                    i++;
                            }
                        }
                        else
                        {
                            
                            cout<<T(0)<<" ";
                        }
                    }
                    cout<<endl;
                }
            }


            void display_transpose()
            {
               int m=0;
                for( int i=0;i<(int)col;i++)
                {
                    for(int j=0;j<(int)row;j++)
                    {
                        if((int)sp[m][0]==i && (int)sp[m][1]==j)
                            {
                                cout<<sp[m][2]<<" ";
                                if(i<size)
                                    m++;
                            }
        
                        else if((int)sp[m][0]==i && (int)sp[m][1]<j)
                        {
                            while((int)i<(int)size && (int)sp[m][0]==i && (int)sp[m][1]<j)
                            {
                                cout<<T(0)<<" ";
                                if(i<size)
                                    i++;
                            }
                            if((int)sp[m][0]==i && (int)sp[m][1]==j)
                            {
                                cout<<sp[m][2]<<" ";
                                if(i<size)
                                    i++;
                            }
                        }
                        else
                        {
                            T a=0;
                            cout<<a<<" ";
                        }
                    }
                    cout<<endl;
                }
            } 
                                    
};
template<typename T>
class Node
{
    public:
        T row,col;
        T val;
        Node* next;

        Node()
        {
            row=T(0);
            col=T(0);
            val=T(0);
            next=NULL;
        }

        Node(T roo,T cool,T vaal)
        {
            row=roo;
            col=cool;
            val=vaal;
            next=NULL;
        }
};
template<typename T>
class linkedlist
{
    public:

    Node<T>*head;
    linkedlist<T>()
    {
        head=NULL;
    }    

     void insertnode(T ro,T coll,T vval)
     {
        Node<T>*temp=new Node(ro,coll,vval);

        if(head==NULL)
        {
            head=temp;
            return ;
        }

        Node<T>*temp1=head;
        while(temp1->next !=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
     }   
        
};

template<typename T>
class link
{
    public:
        T row,col;
        int size=0;
         linkedlist<T>l;
            link<T>(T a,T b)
            {
                row=a;
                col=b;
            }

            void insert(T roow,T cool,T val)
            {
                l.insertnode(roow,cool,val);
                size++;
            }

            link<T>addition(link l2)
            {
                link<T>l3(row,col);
                int a;
                a=0;
                Node<T>*temp1;
                Node<T>*temp2;
                temp1=l.head;
                //cout<<1<<endl;
                temp2=l2.l.head;
                //cout<<2<<endl;
                int index1=0,index2=0;
                for(;index1<(int)size,index2<(int)l2.size;a++)
                {
                    //cout<<3<<endl;
                    if((int)temp1->row==(int)temp2->row)
                    {
                        //cout<<4<<endl;
                        
                        if((int)temp1->col==(int)temp2->col)
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
                        else if((int)temp1->col> (int)temp2->col)
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
                    else if((int)temp1->row > (int)temp2->row)
                    {
                        //cout<<16<<endl;
                        while((int)temp1->row > (int)temp2->row)
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
                        while((int)temp1->row < (int)temp2->row)
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
                
            link<T> muliplication(link l2)
            {
                link<T>l3(row,l2.col);
                T temp;
                int index1=0;
                int index2=0;
                Node<T>*temp1;
                Node<T>*temp2;
                temp1=l.head;
                temp2=l2.l.head;
                for(int i=0;i<(int)row;i++)
                {
                    for(int j=0;j<(int)l2.col;j++)
                    {
                        int row1,col1,row2,col2;
                        row1=i;
                        col2=j;
                        temp=0;
                        T a1,a2;

                        for(col1=0;col1<(int)col;col1++)
                        {
                            a1=0;
                            a2=0;
                            row2=col1;
                            while(index1<size)
                            {
                                
                                    
                                if((int)temp1->row == (int)row1 && (int)temp1->col == (int)col1)
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
                            while(index2<(int)l2.size)
                            {
                                
                                        
                                if((int)temp2->row == (int)row2 && (int)temp2->col == (int)col2)
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
                        l3.insert(T(i),T(j),temp);
                    }
                }
                return l3;
            }

            link<T> transpose()
            {
                link<T>ll(row,col);
                Node<T>*temp_l;
                Node<T>*temp_ll;
                temp_l=l.head;
                temp_ll=ll.l.head;
                sparse<T>linked(row,col);
                sparse<T>linked1(row,col);
                for(int i=0;i<(int)size;i++)
                {
                    linked.in_sparse(temp_l->row,temp_l->col,temp_l->val);
                    temp_l=temp_l->next;
                }
                linked1=linked.transpose_matrix();
               
                for(int i=0;i<(int)linked.size;i++)
                    ll.insert(linked1.sp[i][0],linked1.sp[i][1],linked1.sp[i][2]);
                return ll;
                
            }

            void display1()
            {
                Node<T>*temp;
                temp=l.head;
                for(int i=0;i<(int)size;i++)
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
                Node<T>*temp;
                temp=l.head;
                for(int i=0;i<(int)row;i++)
                {
                    for(int j=0;j<(int)col;j++)
                    {   if(temp){
                        if((int)temp->row==(int)i && (int)temp->col==(int)j)
                            {
                                cout<<temp->val<<" ";
                                if(temp->next)
                                    temp=temp->next;
                            }
        
                        else if((int)temp->row==i && (int)temp->col<j)
                        {
                            while(temp && (int)temp->row==i && (int)temp->col<j)
                            {
                            
                                cout<<T(0)<<" ";
                                temp=temp->next;
                                
                            }
                            if(temp){
                            if((int)temp->row==i && (int)temp->col==j)
                            {
                                cout<<temp->val<<" ";
                                if(temp->next)
                                    temp=temp->next;
                            }
                            }
                        }
                        else
                        {
                            cout<<T(0)<<" ";
                        }
                    }
                    else
                    {
                        cout<<T(0)<<" ";
                    }
                    }
                    cout<<endl;
                }
            }

           
            void t_disp()
            {
                 Node<T>*temp;
                temp=l.head;
                int m=0;
                for(int i=0;i<(int)col;i++)
                {
                    for(int j=0;j<(int)row;j++)
                    {   if(temp){
                        if((int)temp->row==i && (int)temp->col==j)
                            {
                                cout<<temp->val<<" ";
        
                                if(temp->next)
                                    {
                                        temp=temp->next;
                                        m++;
                                    }
                            
                            }
        
                        else if((int)temp->row==i && (int)temp->col<j)
                        {   
                            while(temp && (int)temp->row==i && (int)temp->col<j)
                            {
                                cout<<T(0)<<" ";

                                    temp=temp->next;
                                
                            }

                            if(temp){
                            if((int)temp->row==i && (int)temp->col==j)
                            {
                                cout<<temp->val<<" ";
        
                                if(temp->next)
                                    temp=temp->next;
                            }
                            }
                        }
                        else
                        {
                        
                            cout<<T(0)<<" ";
                        }
                    }
                    else{
                        cout<<T(0)<<" ";
                    }
                    }
                    cout<<endl;
                }
            }
            
};
template<typename T>
class d_t{
    public:
    T a;

    d_t<T>()
    {   }
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
            sparse<float>sp1(n1,m1);
            for(int i=0;i<n1;i++)
    
        for(int j=0;j<m1;j++)
        {
            d_t<float>bb;
            cin>>bb.a;
            if((int)bb.a!=0)
            {
                sp1.in_sparse(i,j,bb.a);
            }
        }
            int n2,m2;
            cin>>n2>>m2;
            sparse<float>sp2(n2,m2);
            for(int i=0;i<n2;i++)
    
            for(int j=0;j<m2;j++)
            {
                d_t<float>bb;
                cin>>bb.a;
                if((int)bb.a!=0)
                {
                    sp2.in_sparse(i,j,bb.a);
                }

            }
            sparse<float>sp3(n1,m1);
            sp3=sp1.addition(sp2);
            cout<<endl<<endl;
            sp3.display();
        }
        else if(o==2)   //transpose
        {
            int n1,m1;
            cin>>n1>>m1; 
            sparse<float>sp1(n1,m1);
            for(int i=0;i<n1;i++)
    
        for(int j=0;j<m1;j++)
        {
            d_t<float>bb;
            cin>>bb.a;
            if((int)bb.a!=0)
            {
                sp1.in_sparse(i,j,bb.a);
            }
        }
        sparse<float>sp3(m1,n1);
        sp3=sp1.transpose_matrix();
        cout<<endl<<endl;
        sp3.display_transpose();
        }
        else            //multiplication
        {
            int n1,m1;
            cin>>n1>>m1; 
            sparse<float>sp1(n1,m1);
            for(int i=0;i<n1;i++)
        {
        for(int j=0;j<m1;j++)
        {
            d_t<float>bb;
            cin>>bb.a;
            if((int)bb.a!=0)
            {
                sp1.in_sparse(i,j,bb.a);
            }
        }
        }
            int n2,m2;
            cin>>n2>>m2;
            sparse<float>sp2(n2,m2);
            for(int i=0;i<n2;i++)
            {
            for(int j=0;j<m2;j++)
            {
                d_t<float>bb;
                cin>>bb.a;
                if((int)bb.a!=0)
                {
                    sp2.in_sparse(i,j,bb.a);
                }

            }
            }
            sparse<float>sp3(n1,m2);
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
            link<float>l1(row1,col1);
            for(int i=0;i<row1;i++)
            {
                for(int j=0;j<col1;j++)
                {
                    d_t<float>bb;
                    cin>>bb.a;
                    if((int)bb.a!=0)
                    {
                        l1.insert(i,j,bb.a);
                    }
                }
            }


            int row2,col2;
            cin>>row2>>col2;
            link<float>l2(row2,col2);
            for(int i=0;i<row2;i++)
            {
                for(int j=0;j<col2;j++)
                {
                    d_t<float>bb;
                    cin>>bb.a;
                    if((int)bb.a!=0)
                    {
                        l2.insert(i,j,bb.a);
                    }
                }
            }
            link<float>l3(row1,col1);
            l3=l1.addition(l2);
            cout<<endl<<endl;
            l3.display();
        }
        else if(o==2) //transpose
        {
            int row1,col1;
            cin>>row1>>col1;
            link<float>l1(row1,col1);
            for(int i=0;i<row1;i++)
            {
                for(int j=0;j<col1;j++)
                {
                    d_t<float>bb;
                    cin>>bb.a;
                    if((int)bb.a!=0)
                    {
                        l1.insert(i,j,bb.a);
                    }
                }
            }

            link<float>l3(col1,row1);
            l3=l1.transpose();
            cout<<endl<<endl;
            l3.t_disp();
        }
        else       //multiplication
        {
            int row1,col1;
            cin>>row1>>col1;
            link<float>l1(row1,col1);
            for(int i=0;i<row1;i++)
            {
                for(int j=0;j<col1;j++)
                {
                    d_t<float>bb;
                    cin>>bb.a;
                    if((int)bb.a!=0)
                    {
                        l1.insert(i,j,bb.a);
                    }
                }
            }


            int row2,col2;
            cin>>row2>>col2;
            link<float>l2(row2,col2);
            for(int i=0;i<row2;i++)
            {
                for(int j=0;j<col2;j++)
                {
                    d_t<float>bb;
                    cin>>bb.a;
                    if((int)bb.a!=0)
                    {
                        l2.insert(i,j,bb.a);
                    }
                }
            }
            link<float>l3(row1,col1);
            l3=l1.muliplication(l2);
            cout<<endl<<endl;
            l3.display();

     }

    }
     return 0;
}