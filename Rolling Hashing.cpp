//THIS FORMS BASE FOR RABIN KARP ALGORITHM //described in photo in 'material'

    #include <iostream>
    #include<string>
    #define lli long long int
    using namespace std;

    lli table1[100009];
    lli table2[100009];
    lli p1[100009];
    lli p2[100009];
    string ss="x";
    lli b1=17,m1=31,b2=79,m2=1213,n;  //b->base for polynomial , modulus constant to avoid overflow

    void make_hash()
    {

        p1[1]=b1,p2[1]=b2;

        for(lli i=2;i<=n;i++)
        {
            p1[i]=(p1[i-1]*b1)%m1;
            p2[i]=(p2[i-1]*b2)%m2;
        }
        table1[1]=((ss.at(1)-'a')*p1[n])%m1;
        table2[1]=((ss.at(1)-'a')*p2[n])%m2;

        for(lli i=2;i<=n;i++)
        {
        table1[i]=(table1[i-1]+(ss.at(i)-'a')*p1[n-i+1])%m1;
        table2[i]=(table2[i-1]+(ss.at(i)-'a')*p2[n-i+1])%m2;
        }
    }
    
    int main()
    {
        string tmp;lli q,L1,R1,L2,R2;
        cin>>tmp;cin>>q;
        ss=ss+tmp;

        n=ss.size()-1;

        make_hash();


        while(q--)
        {    
            cin>>L1>>R1>>L2>>R2;
            
            lli hash_s1t1= L1==1 ? table1[R1] :  (p1[L1-1]*(table1[R1]-table1[L1-1]+m1))%m1;
            lli hash_s1t2= L1==1 ? table2[R1] :  (p2[L1-1]*(table2[R1]-table2[L1-1]+m2))%m2;
            lli hash_s2t1= L2==1 ? table1[R2] :  (p1[L2-1]*(table1[R2]-table1[L2-1]+m1))%m1;
            lli hash_s2t2= L2==1 ? table2[R2] :  (p2[L2-1]*(table2[R2]-table2[L2-1]+m2))%m2;

            if(hash_s1t1==hash_s2t1 and hash_s1t2==hash_s2t2)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }


    }

