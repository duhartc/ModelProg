/*! \file main.cpp
 *  \brief     Test l'ensemble des fonctions du fichier Dvector.cpp
 *  \author    Claudia Duhart 
 *  \author    Benjamin Ruimy
 *  \version   1.0
 *  \date      2015
 *  \warning   Usage: Dvector 
 */

#include "Dvector.h"
#include "assert.h"
#include "sstream"
#include <fstream>
#include <cmath>


bool compDoubleMain(double x, double y, double precision) {
  if (std::abs(x - y)  < precision) {
    return true;
  }
  return false;
 }

int main()
{
    
  // TP1

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

    Dvector vRandom1(3);
    vRandom1.fillRandomly();

    std::cout<<"vACopy : ";
    Dvector vACopy = vA; 
    ss.str("");
    vACopy.display(ss);
    assert(str.str() == ss.str());
    std::cout << "OK \n";

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

    std::cout<<"vFile0 :"; 
    Dvector vFile0("test0.txt");
    std::stringstream ssss; 
    vFile0.display(ssss);
    assert(ssss.str() == "2.00\n3.00\n2.20\n1.00\n");
    std::cout<<" OK \n"; 
    
    std::cout<<"vFile1 :"; 
    Dvector vFile1("tp1_test1.txt");
    ssss.str("");
    vFile1.display(ssss);
    assert(ssss.str() == "0.162182\n0.794285\n0.311215\n0.528533\n0.165649\n0.601982\n0.262971\n0.654079\n0.689214\n0.748152\n");
    std::cout<<" OK \n";
 
    std::cout<<"vFile2 :"; 
    Dvector vFile2("tp1_test2.txt");
    ssss.str("");
    vFile2.display(ssss);
    assert(vFile2.size() == 16737);
    std::cout<<" OK \n";

    std::cout<<"vFileLignesVides :";
    Dvector vFile3("tp1_lignesvides.txt");
    assert(vFile3.size() == 10);
    std::cout<<" OK \n";

    std::cout<<"vFileEspace : ";
    Dvector vFile4("tp1_espace.txt");
    assert(vFile4.size() == 11);
    std::cout<<" OK \n";


   
 //TP 2
    std::cout << "\n\n\n\n Tests sur le TP2 : \n\n\n\n";
    std::cout << "Test des opérateurs : \n\n";
    /*
    std::cout << vFile1(0) << "  " << vFile1(3) << "\n";
    assert(compDoubleMain(vFile1(0), 0.162182, 0.000001));
    //assert(vFile1(3) == 0.528533);
    */
    vA += -1.25;
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "-1.25\n-1.25\n-1.25\n");
    std::cout << "Test de l'opérateur += avec un double [PASSED]" << std::endl; 
    vA += vA;
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "-2.50\n-2.50\n-2.50\n");
    std::cout << "Test de l'opérateur += avec un vecteur [PASSED]" << std::endl;
    vA -= -1.25;
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "-1.25\n-1.25\n-1.25\n");
    std::cout << "Test de l'opérateur -= avec un double [PASSED]" << std::endl; 
    vA -= vA;
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "0.00\n0.00\n0.00\n");
    std::cout << "Test de l'opérateur -= avec un vecteur [PASSED]" << std::endl;
    
    vA += 5;
    vA *= 5.5; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "27.50\n27.50\n27.50\n");
    std::cout << "Test de l'opérateur *= avec un double [PASSED]" << std::endl; 
    vA /= 5.5; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "5.00\n5.00\n5.00\n");
    std::cout << "Test de l'opérateur /= avec un double [PASSED]" << std::endl;
    Dvector vD(3,1); 
    vA = vD; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "1.00\n1.00\n1.00\n");
    std::cout << "Test de l'opérateur = avec un vecteur [PASSED]" << std::endl;
    
    std::cout << "\n\n\nTests sur l'addition\n\n\n" << std::endl; 
    
    vA = vA + 2.25; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "3.25\n3.25\n3.25\n");
    std::cout << "Test de l'opérateur + avec un réel à droite [PASSED]" << std::endl;
    vA = 2.75 + vA; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "6.00\n6.00\n6.00\n");
    std::cout << "Test de l'opérateur + avec un réel à gauche [PASSED]" << std::endl;
    vA = vA + vA; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "12.00\n12.00\n12.00\n");
    std::cout << "Test de l'opérateur + entre deux vecteurs [PASSED]" << std::endl;
    
    
    std::cout << "\n\n\nTests sur la soustraction\n\n\n" << std::endl; 
    vA = vA - 2.25; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "9.75\n9.75\n9.75\n");
    std::cout << "Test de l'opérateur - avec un réel à droite [PASSED]" << std::endl;
    vA = 19.75 - vA; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "10.00\n10.00\n10.00\n");
    std::cout << "Test de l'opérateur - avec un réel à gauche [PASSED]" << std::endl;
    vA = vA - vD; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "9.00\n9.00\n9.00\n");
    std::cout << "Test de l'opérateur - entre deux vecteurs [PASSED]" << std::endl;
    
    std::cout << "\n\n\nTests sur la multiplication\n\n\n" << std::endl; 
    vA(0) = 1;
    vA(1) = 2; 
    vA(2) = 3; 
    vA = vA * 2; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "2.00\n4.00\n6.00\n");
    std::cout << "Test de l'opérateur * avec un réel à droite [PASSED]" << std::endl;
    vA = 2.257 * vA; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "4.514\n9.028\n13.542\n");
    std::cout << "Test de l'opérateur * avec un réel à gauche [PASSED]" << std::endl;
    
    std::cout << "\n\n\nTests sur la division\n\n\n" << std::endl; 
    
    vA(0) = 1;
    vA(1) = 2; 
    vA(2) = 4; 
    vA = vA / 2; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "0.50\n1.00\n2.00\n");
    std::cout << "Test de l'opérateur / avec un réel à droite [PASSED]" << std::endl;
    vA = 2 / vA; 
    ss.str("");
    vA.display(ss); 
    assert(ss.str() == "4.00\n2.00\n1.00\n");
    std::cout << "Test de l'opérateur / avec un réel à gauche [PASSED] \n\n\n" << std::endl;
    

    
    std::stringstream streamTest;
    Dvector vStream(3);
    streamTest << vB;
    streamTest >> vStream;
    assert(streamTest.str() == "1.00\n1.00\n1.00\n1.00\n1.00\n");
    ss.str(""); 
    vStream.display(ss); 
    assert(ss.str() == "1.00\n1.00\n1.00\n"); 
    std::cout << "Test << [PASSED]\n";
    std::cout << "Test >> [PASSED]\n\n\n";
    
    

    Dvector v5(5, 0.001);
    Dvector v3(3, 0.001);
    Dvector vDiff5(5, 0.002);
    Dvector vEq5(5, 0.001);
    assert(v5 == vEq5);
    assert(!(v5 == vDiff5));
    assert(!(v5 == v3));
    std::cout << "Test == [PASSED] \n\n\n";
    

    
    Dvector vResize(5, 1);
    vResize.resize(3);
    ss.str(""); 
    vResize.display(ss); 
    assert(ss.str() == "1.00\n1.00\n1.00\n"); 
  
    vResize.resize(7, 1.0, 1.0, 1.0, 1.0);
    ss.str(""); 
    vResize.display(ss); 
    assert(ss.str() == "1.00\n1.00\n1.00\n1.00\n1.00\n1.00\n1.00\n"); 
    std::cout << "Test resize() [PASSED]\n\n\n\n\n";
    
    Dvector vE(10000000,1); 
    Dvector vF(vE);

    //std::cout << "Test division par 0 << \n";
    //vB /= 0;
    //Dvector vBTestG(vB/0); vBTestG.display(std::cout);
    
    
    //fuite + tester toutes les affectations avec null
    Dvector vfuite(5); vfuite = Dvector(0);
    vfuite.display(std::cout);
    
    //test resize bis
    Dvector vVide;
    vVide.resize(3, 1.0);
    std::cout<< vVide << "Taille: " << vVide.size() << "\n" ;
    
    Dvector vToVide(5, 1);
    vToVide.resize(0);
    std::cout<< vToVide << "Taille: " << vToVide.size() << "\n" ;
    vToVide.resize(3);
    std::cout<< vToVide << "Taille: " << vToVide.size() << "\n" ;

    return(0);
}