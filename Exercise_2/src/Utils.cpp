#include "Utils.hpp"

#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   double& S,
                   size_t& n,
                   double*& w,
                   double*& r)
{
    // Apertura del file
    ifstream file(inputFilePath);

    if (!file.is_open())
    {
        cerr << "Impossibile aprire il file " << inputFilePath << endl;
        return false;
    }

    // Lettura di S
    string line;
    getline(file, line);
    istringstream ss(line);
    ss.ignore(2); // Ignora i primi due caratteri, che sappiamo essere "S;"
    ss >> S;

    // Lettura di n
    getline(file, line);
    ss.clear();
    ss.str(line);
    ss.ignore(2); // Ignora i primi due caratteri, che sappiamo essere "n;"
    ss >> n;


    getline(file,line); //legge la riga con i w;r che però no svolgendo operazioni viene saltata

    // Allocazione di memoria per i vettori w e r
    w = new double[n];
    r = new double[n];

    // Lettura dei vettori w e r
    for (size_t i = 0; i < n; ++i)
    {
        getline(file, line);
        ss.clear();
        ss.str(line);

        // Legge il valore prima del carattere ";" in w e quello dopo in r, per poi passare alla riga successiva
        string temp;
        getline(ss, temp, ';');
        w[i] = stod(temp);
        getline(ss, temp);
        r[i] = stod(temp);
    }

    return true;
}


double DotProduct(const size_t& n,
                  const double* const& w,
                  const double* const& r)
{
    double dotProduct = 0;
    for (unsigned int i = 0; i < n; i++)
        dotProduct += w[i] * r[i];

    return dotProduct;
}

bool ExportResult(const string& outputFilePath,
                  double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& dotProduct)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }


    file<< "S = "<<fixed<<setprecision(2)<<S<<", n = "<<n<< endl;
    file << "w = [ ";
    for (size_t i = 0; i < n; i++)
    {
        file << w[i];
        if (i != n - 1)
            file << " ";
    }
    file << " ]" << endl;

    // Scrivi il vettore r sulla stessa riga
    file << "r = [ ";
    for (size_t i = 0; i < n; i++)
    {
        file << r[i];
        if (i != n - 1)
            file << " ";
    }
    file << " ]" << endl;

    file<< "Rate of return of the portfolio: "<<fixed<<setprecision(4)<<dotProduct<< endl;

    file << fixed << setprecision(2);
    file<<"V: " <<(1+dotProduct)*S<<endl;

    // Close File
    file.close();

    return true;
}
