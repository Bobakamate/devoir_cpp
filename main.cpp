#include <iostream>



using namespace  std ;
class ElementPile {
public:
    int valeur;
    ElementPile *suivant;
    ElementPile(int _valeur) : valeur(_valeur) ,suivant(nullptr){}

};

class Stack{
public :
    ElementPile *sommet ;
       int taille_maximale ;
    Stack(int _taille_maximale = 20) :sommet(nullptr),taille_maximale(_taille_maximale){}
   Stack & operator<<  (int n ){
        /*ajout d un element en haut de la pile avec l operateur <<*/
       if(!pile_est_pleine())
       {
           ElementPile *nouveau = new ElementPile(n);
           nouveau->suivant = sommet;
           sommet = nouveau;
       } else{
           cout<<"la pile est deja pleine impossible d'ajouter un element "<<endl;
       }
       return *this;
   }
    Stack & operator>> (int &n)
   {
        n = sommet->valeur;
        ElementPile *temp = sommet->suivant;
        delete sommet;
        sommet = temp;
       return *this;

   }
   int  operator ++(){
        if(pile_est_pleine())
        {
            return  1;
        }
       return 0;

    }
    int  operator --(){
        if(is_empty())
        {
            return  1;
        }
        return 0;

    }
    void operator = (Stack &autre_pile) {
        try {
            throw "Impossible de faire l affectation entre deux pile ";
        }
        catch (const char * err )
        {
            cout <<err<<endl;
        }

    }
   void afficher_pile()
   {
        ElementPile *temp = sommet;
        while (temp)
        {
            cout<<temp->valeur<<endl;
            temp = temp->suivant;
        }
   }
   bool is_empty ()
   {
        return sommet == nullptr;
   }
   bool pile_est_pleine()
   {
        ElementPile *temp = sommet ;
        int compteur = 0;
        while (temp)
        {
            temp = temp->suivant;
            compteur++;
        }
        if(compteur == taille_maximale)
        {
            return true;
        }
       return false;
   }
   ~Stack(){
        while  (!is_empty())
        {
            ElementPile *temp = sommet->suivant;
            delete sommet;
            sommet = temp;

        }

    }
};

int main() {
     Stack mapile ;
    Stack mapile2 ;
  mapile<<10<<20<<30;
  int valeur ;
    mapile.afficher_pile();
    cout<<"\n---------------------------\n";
  mapile>>valeur;
  mapile = mapile2;

    mapile.afficher_pile();
cout<<"le contenue de valeur est : "<<valeur;






    return 0;
}
