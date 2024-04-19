#pragma once

#include <string>
#include <iostream>


using namespace std;

//Importare i vettori e le informazioni su dal file
bool ImportVectors(const string& inputFilePath,
                   double& S,         // quantità investita
                   size_t& n,       //dimensione dei vettori
                   double*& w,      //vettore 1
                   double*& r);     //vettore 2


//calcolo del prodotto scalare che corrisponde a Rate of return of the portfolio
double DotProduct(const size_t& n,
                        const double* const& w,
                        const double* const& r);

// Esportare i dati in un fil e
bool ExportResult(const string& outputFilePath,
                  double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& dotProduct);
