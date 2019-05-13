#include <iostream>

using namespace std;

//A gy�jt�pontok egyszer� t�rol�s�hoz sz�ks�ges strukt�ra
struct Gyujto
{
    int o;  //oszlop index
    int s;  //sor index
};

int main()
{
    //Deklar�ci� �s beolvas�s
    int H[1000][1000]={0}; //A hegyoldal ter�let�nek m�trixa
    int N;
    int M;
    cin>>N>>M;
    int K;
    cin>>K;
    int G;
    cin>>G;
    Gyujto GY[1000];

    //M�trix felt�lt�se a kincsekkel
    for (int i=0; i<K; i++)
    {
        int s; //sor index
        int o; //oszlop index
        cin>>s>>o;
        H[s-1][o-1]=1; //-1 a 0-t�l indexel�s miatt
    }

    //Gy�jt�pontok beolvas�sa, �s elhelyez�s a m�trixban
    for (int i=0; i<G; i++)
    {
        int s;  //sor index
        int o;  //oszlop index
        cin>>s>>o;
        H[s-1][o-1]=-1; //gy�jt�pont elhelyez�se a m�trixban -1 �rt�kkel
        GY[i].o=o-1;
        GY[i].s=s-1;
    }

    //Dinamikus Programoz�s, m�trix/t�bl�zat felt�lt�se a "R�szletes megold�s" r�sz alapj�n
    for(int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (H[i][j]!=-1 && (H[i-1][j]!=-1 || H[i][j-1]!=-1)) //Ha nem gy�jt�pont
            {
                if (i-1>=0 && j-1>=0)  //�ltal�nos eset
                {
                    if (H[i-1][j]>H[i][j-1])
                    {
                        H[i][j]+=H[i-1][j];
                    }
                    else
                    {
                        H[i][j]+=H[i][j-1];
                    }

                }
                else if (i-1>=0 && j==0) //Els� oszlop esete
                {
                    H[i][j]+=H[i-1][j];
                }
                else if (i==0 && j-1>=0) //Els� sor esete
                {
                    H[i][j]+=H[i][j-1];
                }

            }
        }
    }

    //Maxmimum kiv�laszt�s
    int maxi=0;  //maxim�lis kincsek
    int maxio=0; //gy�jt�hely oszlop indexe
    int maxis=0; //gy�jt�hely sor indexe
    for (int i=0; i<G; i++)
    {
        int o=GY[i].o;
        int s=GY[i].s;
        if (H[s-1][o]>maxi && s-1>=0)
        {
            maxi=H[s-1][o];
            maxio=o+1;
            maxis=s+1;
        }
        if (H[s][o-1]>maxi && o-1>=0)
        {
            maxi=H[s][o-1];
            maxio=o+1;
            maxis=s+1;
        }
    }
    if (maxi==0)  //Ha nincs oda vihet� kincs, akkor nincs hely sem
    {
        cout<<maxi<<endl;
    }
    else
    {
        cout<<maxi<<endl;
        cout<<maxis<<" "<<maxio<<endl;
    }

/*
    //T�bl�zat k��r�sa, szeml�ltet�s
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cout<<H[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    return 0;
}
