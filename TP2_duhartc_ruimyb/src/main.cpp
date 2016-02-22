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
    
    std::cout << "Test sur l'addition\n";
    std::cout << vFile1(0) << "  " << vFile1(3) << "\n";
    assert(compDoubleMain(vFile1(0), 0.162182, 0.000001));
    //assert(vFile1(3) == 0.528533);
    vB += 1;
    vB.display(std::cout);
    vB += vB;
    vB.display(std::cout);
    Dvector vBAddG(0.5+vB); vBAddG.display(std::cout);
    Dvector vBAddD(vB+(-3)); vBAddD.display(std::cout);
    Dvector vBAdd(vB+vB); vBAdd.display(std::cout);
    std::cout << "Test << :\n";
    std::cout << vB;
    std::cout<<" OK \n";
     
    Dvector vBAffect;
    std::cout << "Test affectation : \n";
    vB = vB; 
    std::cout << "Autoaffectation : \n";
    std::cout << vB;
    std::cout<<" OK \n";
    vBAffect = vB;
    std::cout << "vecteur 1: \n";
    std::cout << vB;
    std::cout << " = vecteur 2: \n";
    std::cout << vBAffect;
    std::cout<<" OK \n";

    std::cout << "Test sur la soustraction\n";
    vB -= 1;
    vB.display(std::cout);
    vB -= 6 *vB;
    vB.display(std::cout);
    Dvector vBSubG(0.5-vB); vBSubG.display(std::cout);
    Dvector vBSubD(vB-(-3)); vBSubD.display(std::cout);
    Dvector vBSub(vB-vB); vBSub.display(std::cout);
    std::cout << "Test << \n";
    std::cout << vB;
    
    std::cout << "Test sur la multiplication\n";
    vB *= 1;
    vB.display(std::cout);
    vB *= vB;
    vB.display(std::cout);
    Dvector vBMultG(0.5*vB); vBMultG.display(std::cout);
    Dvector vBMultD(vB*(-3)); vBMultD.display(std::cout);
    Dvector vBMult(vB*vB); vBMult.display(std::cout);
    std::cout << "Test << \n";
    std::cout << vB;
    std::cout<<" OK \n";
    
    std::cout << "Test sur la division\n";
    vB /= 8;
    vB.display(std::cout);
    vB /= vB;
    vB.display(std::cout);
    Dvector vBDivG(0.5/vB); vBDivG.display(std::cout);
    Dvector vBDivD(vB/(-3)); vBDivD.display(std::cout);
    Dvector vBDiv(vB/vB); vBDiv.display(std::cout);

    std::cout << "Test << \n";
    std::cout << vB;

    std::cout << "Test >> \n";
    std::stringstream streamTest;
    Dvector vStream(3);
    streamTest << vB;
    streamTest >> vStream;
    vStream.display(std::cout);

    std::cout << "Test == \n";
    Dvector v5(5, 0.001);
    Dvector v3(3, 0.001);
    Dvector vDiff5(5, 0.002);
    Dvector vEq5(5, 0.001);
    assert(v5 == vEq5);
    assert(!(v5 == vDiff5));
    assert(!(v5 == v3));
    std::cout<<" OK \n";
    
    std::cout << "Test resize() \n";
    Dvector vResize(5, 1);
    std::cout << "Test 3\n";
    vResize.resize(3);
    std::cout << vResize;
    std::cout << "Test 7 - > 1\n";
    vResize.resize(7, 1.0, 1.0, 1.0, 1.0);
    std::cout << vResize;

    //std::cout << "Test division par 0 << \n";
    //vB /= 0;
    //Dvector vBTestG(vB/0); vBTestG.display(std::cout);
    
    
    
    

    return(0);
    //Questions :
    // assert qui marche pas > pourquoi?
    // les exceptions (dans les assert) try catch avec assert true false
    // deuxieme metode affectation ? avec boucle for 
}
