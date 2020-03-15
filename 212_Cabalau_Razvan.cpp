///Grupa 212.Cabalau Razvan

#include<iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

class Nod
{
private:
    // int info ;
    //Nod *next;
    //daca pun info si next pe private imi da eroare ca sunt argumente private
public:
    int info ;
    Nod *next;
    Nod (int x,Nod *y); //constructor
    ~Nod();            //destructor

    friend Lista_Circulara();

};
class Lista_Circulara
{

private:
    Nod* prim=NULL;
public:



    void citire();
    void inserareInceput(istream &in);
    friend istream& operator>>(istream &in, Lista_Circulara &v);  /// supraincarcare operator >>

    void afisare(ostream &out);
    friend ostream& operator<<(ostream &out, Lista_Circulara &v);  /// supraincarcare operator <<

    void stergereElementPozitie();

    void inserareElementPoz();

    friend Lista_Circulara& operator+(Lista_Circulara& v1, Lista_Circulara & v2);  ///supraincarcare operator +

    void inversareLegaturi();

    void stergereK();

};
Nod::Nod(int x=0,Nod *y=NULL)  //constructor pentru clasa nod
{
    this->info =x;
    this->next= y;

}

Nod::~Nod() //destructor pentru clasa Nod
{
    this->info=0;
    this->next=0;
}

int n;
void Lista_Circulara::citire()
{

    cout<<"Dati numarul de elemente din lista: ";
    cin>>n;

}
void Lista_Circulara::inserareInceput(istream& in)
{
    int valoare,i;

    for (i=0; i<n; i++)
    {
        cout<<"Dati o valoare: ";
        in>>valoare;
        Nod *elem=new Nod;
        elem->info=valoare;
        elem->next=prim;
        prim=elem;

    }
}

istream& operator>>(istream& in,Lista_Circulara &v)
{
    v.inserareInceput(in);
    return in;
}

void Lista_Circulara::afisare(ostream &out)
{
    Nod  *tineminte=prim;
    while(prim!=NULL)
    {
        out<<prim->info;

        cout<<"\n";
        prim=prim->next;
    }
    prim=tineminte;
}

ostream& operator<<(ostream& out, Lista_Circulara &v)
{
    v.afisare(out);
    return out;
}

void Lista_Circulara::inserareElementPoz() /// inserare dupa pozitia data
{
    int ct=1;
    int poz,nr;
    cout<<"Dati o pozitie: ";
    cin>>poz;

    if (poz>n || poz<0)
    {
        cout<<"Pozitia nu se afla in lista";
        return;
    }

    cout<<"Dati o valoare: ";
    cin>>nr;
    Nod *p;
    if(poz==1)

    {
        Nod *x;
        x=new Nod;
        x->next=prim;
        x->info=nr;

        prim=x;

    }
    else
    {
        for(p=prim;     p;       p=p->next,++ct)
            if(ct==poz)
            {
                Nod *x;
                x=new Nod;
                x->info=nr;
                x->next=p->next;
                p->next=x;

            }
    }
    if(ct<=poz)
    {
        Nod *ultim;
        Nod *x;
        x=new Nod;
        x->info=nr;
        x->next=NULL;
        ultim->next=x;
        ultim=x;
    }
    cout<<"Executati actiunea nr. 3 pentru a revedea lista \n";
}

Nod *cautarePozitie(Nod *prim,int pozitie)
{
    int i=0;
    while (prim!=NULL && i<pozitie)
    {
        prim=prim->next;
        i++;
    }
    if (i==pozitie)
        return prim;
    else
        return NULL;



}
void stergereElement(Nod * predecesor)
{

    Nod *victima=predecesor->next;
    cout<<"Elementul sters este:"<<predecesor->info<<"\n";
    predecesor->next=predecesor->next->next;
    delete victima;


}
int q=0; //acesta este pentru a numara cate elemente sterg din lista
void Lista_Circulara:: stergereElementPozitie()
{

    int pozitie;
    cout<<"Dati o pozitie: ";
    cin>>pozitie;

    if (pozitie>=n-q || pozitie<0)
    {
        cout<<"Pozitia nu se afla in lista";
        return;
    }
    q++;

    if (pozitie==0)
    {
        Nod *victima=prim;
        cout<<"Elementul sters este:"<<prim->info<<"\n";
        prim=prim->next;
        delete victima;


    }
    else
    {

        Nod * predecesor=cautarePozitie(prim,pozitie-1);
        stergereElement(predecesor);
    }


}
void Lista_Circulara:: stergereK()
{
    int i,k;
    cout<<"Dati un numar K: ";
    cin>>k;

    if (k>=n-q || k<=0)
    {
        cout<<"Pozitie incorecta! Mai incearca ";
        return;
    }
    q++;
    if (k==1)
    {
        for(i=0; i<n; i++)
        {
            Nod *victima=prim;
            cout<<"Elementul sters este:"<<prim->info<<"\n";
            prim=prim->next;
            delete victima;
        }
    }
    else
    {
        int f=0;
        Nod *victima=prim;
        cout<<"Elementul sters este:"<<prim->info<<"\n";
        prim=prim->next;
        delete victima;
        i=1;

        while( i<=n)
        {
            i=i*k;
            Nod * predecesor=cautarePozitie(prim,i-1);
            stergereElement(predecesor);
            f=f+1;
        }
///se strge ce ramane
        for(i=0; i<n-f; i++)
        {
            Nod *victima=prim;
            cout<<"Elementul sters este:"<<prim->info<<"\n";
            prim=prim->next;
            delete victima;

        }

    }

}
/// e doar antetul
inline Lista_Circulara& operator+(Lista_Circulara &v1, Lista_Circulara &v2)
{
    Lista_Circulara *v = new Lista_Circulara;


    //return *v;

}
///e doar antetul
void Lista_Circulara:: inversareLegaturi(){




}

void menu_output()
{
    cout<<"\n Cabalau Razvan Grupa 212 - Proiect 6- Clasa -Lista_circulara- (implementata dinamic): \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Numarul elementelor din lista circulara. ";
    cout<<"\n";
    cout<<"2. Inserare elemente in lista. ";//aici se creeaza o lista circulara
    cout<<"\n";
    cout<<"3. Afisati elementele listei. ";
    cout<<"\n";
    cout<<"4. Stergeti un element din lista. ";
    cout<<"\n";
    cout<<"5. Adaugati un element pe o pozitie. ";
    cout<<"\n";
    cout<<"6. Stergere din k in k elemente. ";
    cout<<"\n";
    cout<<"7. Concatenare a doua liste. ";
    cout<<"\n";
    cout<<"8. Inversare legaturi. ";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n===========================================\n";

}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    Lista_Circulara v;
    int j=0,l=0,i,k;

    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {


            v.citire();
            j=1;

        }
        if (option==2)
        {
            if (j==1)
            {
                cin>>v;
                l=1;
            }
            else
                cout<<"\nDati mai intai numarul de elemente din lista circulara\nApasati tasta 1.\n";

        }
        if (option==3)
        {
            if (j==1 && l==1)
                cout<<v;
            else
                cout<<"\nDati mai intai numarul de elemente din lista circulara\nExecutati actiunea nr.1 si actinea nr. 2.\n";
        }
        if (option==4)
        {
            if (j==1 && l==1)
                v.stergereElementPozitie();
            else
                cout<<"\nDati mai intai numarul de elemente din lista circulara\nExecutati actiunea nr.1 si actinea nr. 2.\n";
        }
        if (option==5)
        {

            v.inserareElementPoz();
        }
        if (option==6)
        {
            cout<<"Merge sa sterg doar din pozitia 0 si 1\n";
            v.stergereK();

        }
        if (option==7)
        {
            cout<<"Nu am facut-o!\n";
            Lista_Circulara v1,v2;
            Lista_Circulara v=v1+v2;
        }
        if (option==8)
        {
            cout<<"Nu am facut-o!\n";
        }

        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>8)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}

int main()
{

    menu();
    return 0;

}
