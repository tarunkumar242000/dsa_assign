#include<iostream>
using namespace std;

//int size=0;

class sparse
{
    int **sp;
    int row=0;
    int col=0;
    int cap=10;
    int size=0;
    public:
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
                sparse temp1(row,col);
                int temp;
                // ss.sp[0][0]=sp[0][1];
                // ss.sp[0][1]=sp[0][0];
                ss.in_sparse(sp[0][1],sp[0][0],sp[0][2]);
                for(int i=1;i<size;i++)
                {
                    temp=i;
                    int j=i;
                    while(temp--)
                    {
                        if(sp[j][1]<ss.sp[temp][0])
                        {
                            // temp1.sp[temp][0]=ss.sp[temp][0];
                            // temp1.sp[temp][1]=ss.sp[temp][1];
                            temp1.in_sparse(ss.sp[temp][0],ss.sp[temp][1],ss.sp[temp][2]);
                            // ss.sp[temp][0]=sp[i][1];
                            // ss.sp[temp][1]=sp[i][0];
                            ss.in_sparse(sp[i][1],sp[i][0],sp[i][2]);
                            // ss.sp[j][0]=temp1.sp[temp][0];
                            // ss.sp[j][1]=temp1.sp[temp][0];
                            ss.in_sparse(temp1.sp[temp][1],temp1.sp[temp][0],temp1.sp[temp][2]);
                        }
                        else if(sp[j][0]<ss.sp[temp][1])
                        {
                            temp1.in_sparse(ss.sp[temp][0],ss.sp[temp][1],ss.sp[temp][2]);
                            // ss.sp[temp][0]=sp[i][1];
                            // ss.sp[temp][1]=sp[i][0];
                            ss.in_sparse(sp[i][1],sp[i][0],sp[i][2]);
                            // ss.sp[j][0]=temp1.sp[temp][0];
                            // ss.sp[j][1]=temp1.sp[temp][0];
                            ss.in_sparse(temp1.sp[temp][1],temp1.sp[temp][0],temp1.sp[temp][2]);
                        }
                        else
                            {
                                // ss.sp[i][0]=sp[i][1];
                                // ss.sp[i][1]=sp[i][0];
                                ss.in_sparse(sp[i][1],sp[i][0],sp[i][2]);
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
                                if(sp[index1][0]>row1 || sp[index1][1]>col1)
                                   break;
                                    
                                else if(sp[index1][0]==row1 && sp[index1][1]==col1)
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
                                if(sp2.sp[index2][0]>row2 || sp2.sp[index2][1]>col2)
                                    
                                        break;
                                        
                                else if(sp2.sp[index2][0]==row2 && sp2.sp[index2][1]==col2)
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
            // void init_size(int a)
            // {
            //     size=a;
            // }
            // void create_matrix()
            // {
            //     sparse=new int*[size];
            // }
            void display()
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
            
                                    
};






int main()
{
    int row1,column1;
    cin>>row1>>column1;
    sparse sp1(row1,column1); 
    int size_o[row1];  
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<column1;j++)
        {
            int a;
            cin>>a;
            if(a!=0)
            {
                sp1.in_sparse(i,j,a);
            }
        }
    }
    cout<<endl<<endl;
    //sp1.display();
    // int row2,column2;
    // cin>>row2>>column2;
    // sparse sp2(row2,column2);
    // for(int i=0;i<row2;i++)
    // {
    //     for(int j=0;j<column2;j++)
    //     {
    //         int a;
    //         cin>>a;
    //         if(a!=0)
    //         {
    //             sp2.in_sparse(i,j,a);
    //         }
    //     }
    // }
    //cout<<endl<<endl;
    //sp2.display();
    sparse sp3(row1,column1);
    // sp3=sp1.addition(sp2);
    // sp3=sp1.multiplication(sp2);
    sp3=sp1.transpose_matrix();
    cout<<endl<<endl;
    sp3.display();
    return 0;
}