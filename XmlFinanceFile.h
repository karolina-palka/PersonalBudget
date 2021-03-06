#ifndef XMLFINANCEFILE_H_INCLUDED
#define XMLFINANCEFILE_H_INCLUDED
#include <iostream>
#include <vector>
#include "Finance.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XmlFinanceFile: public XmlFile
{
    int financeId;
    Finance loadFinanceFromFile(int loggedInUserId);


public:
    XmlFinanceFile(string fileName): XmlFile(fileName) {};
    void addFinancesToXmlFile(Finance finance, string financeType);
    vector <Finance> loadFinancesFromFile(string financeType, int loggedInUserId);
    int getNewFinanceId(string financeType);
};


#endif // XMLFINANCEFILE_H_INCLUDED
