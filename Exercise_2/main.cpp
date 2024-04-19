#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;



int main()
{
    string inputFilePath = "./data.csv";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;   // definisco i due puntatori vuoti
    double* r = nullptr;


    if (!ImportVectors(inputFilePath, S, n, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }



    double product = DotProduct(n, w, r);
    //cout << "Il prodotto scalare dei vettori w e r vale: " << product << endl;



    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, product))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;





    delete[] w;
    delete[] r;
    return 0;
}

