#include "Dvector.h"
#include <cstddef> 
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

Dvector::Dvector() 
{
    cout << "[APPEL AU CONSTRUCTEUR PAR DEFAUT POUR L'OBJET : " << this << endl; 
    vsize = 0;
    v = NULL;
}

Dvector::Dvector(unsigned int s, double optionalInitVal) {
    //optionalInitVal = 0 if no value
    cout << "[APPEL AU CONSTRUCTEUR A DEUX PARAMETRES POUR L'OBJET : " << this << " ] " <<endl; 
    vsize = s;
    v = new double[vsize];
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = optionalInitVal;
    }
}

Dvector::~Dvector() {
    cout << "[APPEL AU DESTRUCTEUR de l'objet :"<<this<< " ]" << endl; 
    delete [] v;
}

unsigned int nbDecimal(double d){
    string s_dec;
    stringstream ssConvert;
    ssConvert << d;
    ssConvert >> s_dec;
    return(s_dec.substr(s_dec.find(".") + 1).size());
}
void Dvector::display(ostream& str) {
    for (unsigned int i = 0; i < vsize ; i++) {
        if (nbDecimal(v[i]) < 2) {
            str << fixed << setprecision(2) << v[i]<<"\n";
        }
        else {
            str << setprecision(nbDecimal(v[i])) << v[i] << "\n";
        }
    }
}

int Dvector::size() {
    //le int retourné sera non signé 
    return vsize;
}

double randomUniform() {
    //srand(time(NULL)); // Réinitialise le rand() 
    rand(); 
    //retourne toujours la meme séquence pour l'instant
    return rand()/(double)RAND_MAX;
}
void Dvector::fillRandomly() {
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = randomUniform();
    }
}

Dvector::Dvector(const Dvector &vect) {
    std::cout<<"[APPEL AU CONSTRUCTEUR PAR COPIE POUR L'OBJET : "<<this<<" ]"<<endl;
    vsize = vect.vsize;
    if (vsize==0) return;
    v = new double[vsize];
    for (unsigned int i = 0; i < vsize ; i++) {
        v[i] = vect.v[i]; //copy
    }
} 

Dvector::Dvector(string str) {
    ifstream file(str.c_str());
    if (!file) {
        vsize = 0;
        v = NULL;
    }
    else {
        //on compte le nombre d'éléments
        size_t nbElem = distance(istream_iterator<string>(file), 
                istream_iterator<string>());

        //on crée le vecteur
        vsize = nbElem;
        v = new double[vsize];

        //on retourne au début du fichier
        file.clear();
        file.seekg(0,ios::beg);

        //on insère ces éléments dans le vecteur
        string line;
        stringstream ssConvert;
        double convert;
        string emptyLine = "";
        nbElem = 0;
        while (getline(file, line)) {
            if (emptyLine.compare(line) != 0) {
                ssConvert << line;
                while (ssConvert >> convert) {
                    v[nbElem] = convert;
                    nbElem++;
                }
                ssConvert.clear();
            }
        } 
    }
    file.close();
}