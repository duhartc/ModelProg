#include "Dvector.h"

int main()
{
  Dvector v;
  Dvector vA(3);
  Dvector vB(5,1);
  std::cout<<"v"<<"\n";
  v.display(std::cout); 
  std::cout<<"vA"<<"\n";
  vA.display(std::cout);
  std::cout<<"vB"<<"\n";
  vB.display(std::cout); 
  std::cout<<"Taille v:"<<v.size()<<"\n";
  std::cout<<"Taille vA:"<<vA.size()<<"\n";
  std::cout<<"Taille vB:"<<vB.size()<<"\n";
  Dvector vRandom1(3);
  vRandom1.fillRandomly(); 
  std::cout<<"vRandom1"<<"\n";
  vRandom1.display(std::cout);
  Dvector vACopy = vA; 
  std::cout<<"vACopy"<<"\n";
  vA.display(std::cout);
  //Cas 1 : incorrect sans surcharger =
  // fait une affectation par copie
  Dvector x1; 
  x1 = Dvector(3, 1.); //on retourne (affecte) l'objet su robjet existant
  //Dvector(3,1.) et x1 ont le meme emplacement en mémoire
  //lors de la libération on fait donc un "double free"
  std::cout<<"x1"<<"\n";
  x1.display(std::cout);
  std::cout<<"Taille x1:"<<x1.size()<<"\n";
  // pour eviter le "double free"
  x1 = vA; // on déplace x1 en mémoire par copy
  x1.display(std::cout);
  std::cout<<"Taille x1:"<<x1.size()<<"\n";
  //Cas 2
  Dvector x2 = Dvector(3, 1.); //on construit l'objet
  std::cout<<"x2"<<"\n";
  x2.display(std::cout); 
  return(0);
}
