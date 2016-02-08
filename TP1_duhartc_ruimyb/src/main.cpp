#include "Dvector.h"
#include "assert.h"
#include "sstream"
int main()
{
    Dvector v;
    Dvector vA(3);
    Dvector vB(5,1);

    std::cout<<"v : "; 
    std::stringstream str;
    v.display(str); 
    assert(str.str() == ""); 
    assert(v.size() == 0);
    std::cout << "OK \n";

    std::cout<<"vA :";
    vA.display(str); 
    assert(str.str() == "0.00\n0.00\n0.00\n"); 
    assert(vA.size() == 3);
    std::cout << "OK \n";
    
    std::cout<<"vB : ";
    std::stringstream ss;  
    vB.display(ss); 
    assert(ss.str() == "1.00\n1.00\n1.00\n1.00\n1.00\n"); 
    assert(vB.size() == 5);
    std::cout << "OK \n";

    std::cout<<"Taille v:"<<v.size()<<"\n";
    v.display(std::cout); 
    std::cout<<"Taille vA:"<<vA.size()<<"\n";
    vA.display(std::cout); 
    std::cout<<"Taille vB:"<<vB.size()<<"\n";
    vB.display(std::cout);
    Dvector vRandom1(3);
    vRandom1.fillRandomly(); 
    std::cout<<"vRandom1"<<"\n";
    vRandom1.display(std::cout);

    Dvector vACopy = vA; 
    std::cout<<"vACopy"<<"\n";
    vA.display(std::cout);

    //Cas 1 : incorrect sans surcharger =
    // fait une affectation par copie
/*
    Dvector x1;
    x1 = Dvector(3,1.); 
    std::cout<<"x1 :"<<std::endl;  
    x1.display(std::cout); 
    std::cout<<"Taille x1:"<<x1.size()<<"\n";

*/
    //on retourne (affecte) l'objet su robjet existant
    //Dvector(3,1.) et x1 ont le meme emplacement en mémoire
    //lors de la libération on fait donc un "double free"

/*
    // pour eviter le "double free"
    x1 = vA; // on déplace x1 en mémoire par copy
    x1.display(std::cout);
    std::cout<<"Taille x1:"<<x1.size()<<"\n";
*/

    //Cas 2
    Dvector x2 = Dvector(vA); //on construit l'objet
    std::stringstream sss; 
    x2.display(sss);
    std::cout<<"x2 : ";  
    assert(sss.str() == "0.00\n0.00\n0.00\n"); 
    assert(x2.size() == 3);
    std::cout<<"OK \n";   
    std::cout<<"x2 :"<<"\n";
    x2.display(std::cout);

    std::cout<<"vFile0 :"<<""; 
    Dvector vFile0("test0.txt");
    std::stringstream ssss; 
    vFile0.display(ssss);
    assert(ssss.str() == "2.00\n3.00\n2.20\n1.00\n");
    std::cout<<" OK \n"; 
    vFile0.display(std::cout);
    std::cout<<"vFile1"<<"\n"; 
    Dvector vFile1("tp1_test1.txt");
    vFile1.display(std::cout);
    std::cout<<"vFile2"<<"\n"; 
    //Dvector vFile2("tp1_test2.txt");
    //vFile2.display(std::cout);
    std::cout<<"vFileLignesVides"<<"\n";
    Dvector vFile3("tp1_lignesvides.txt");
    vFile3.display(std::cout);
    std::cout<<"vFileEspace"<<"\n";
    Dvector vFile4("tp1_espace.txt");
    vFile4.display(std::cout);

    return(0);
}
