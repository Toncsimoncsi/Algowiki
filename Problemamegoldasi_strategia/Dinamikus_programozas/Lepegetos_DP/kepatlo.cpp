#include <iostream>

using namespace std;

struct pix
{
    int bal, fent, pont; //Adott pixelt�l balra es� feh�rek sz�ma, fel� es� feket�k sz�ma, el�rhet� legkisebb �rt�k
};

pix kep[1000][1000];

int main()
{
    int n;
    cin>>n;
    bool be;

    for(int i = 0; i < n; ++i) // Els� sor �s oszlop �rt�ke 0
    {
        kep[i][0].pont = 0;
        kep[0][i].pont = 0;
    }


    for (int i = 0; i < n-1; ++i) // Itt adjuk meg a bal �s fent �rt�keket
    {
        for (int j = 0; j < n-1; ++j)
        {
            cin>>be;
            kep[i+1][j].fent = kep[i][j].fent + !be;
            kep[i][j+1].bal = kep[i][j].bal + be;
        }
        cin>>be;
        kep[i+1][n-1].fent = kep[i][n-1].fent + !be;
    }

    for (int i = 0; i < n-1; ++i)
    {
        cin>>be;
        kep[n-1][i+1].bal = kep[n-1][i].bal + be;
    }
    cin>>be; //Utols� pixel sz�monkra nem l�nyeges, de az�rt beolvassuk


    for(int i = 1; i < n; ++i) //�rt�kek meghat�roz�sa
    {
        for (int j = 1; j < n; ++j)
        {
            kep[i][j].pont = min(kep[i-1][j].pont + kep[i][j].bal , kep[i][j-1].pont + kep[i][j].fent); // � a fontos!
        }
    }

    /* //Ez megjelen�theti a t�bl�zat fent, bal �s pont �rt�keit
    cout<<"\n\n\n";
    cout<<"Bal:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<kep[i][j].bal<<' ';
        }
        cout<<'\n';
    }

    cout<<"\n\n\n";
    cout<<"Fent:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<kep[i][j].fent<<' ';
        }
        cout<<'\n';
    }

    cout<<"\n\n\n";
    cout<<"Pont:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<kep[i][j].pont<<' ';
        }
        cout<<'\n';
    }
    cout<<"\n\n\n";
    cout<<"Eredm�ny:\n";
    */
    cout << kep[n-1][n-1].pont << endl;
    return 0;
}
