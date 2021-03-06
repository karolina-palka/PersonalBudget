#ifndef XMLFILE_H_INCLUDED
#define XMLFILE_H_INCLUDED
#include <iostream>
#include <string>
#include "Markup.h"

using namespace std;

class XmlFile
{
    const string FILE_NAME;

public:
    CMarkup xml;
    string getFileName();
    XmlFile(string fileName): FILE_NAME(fileName){};

    bool isFileEmpty(string keyType);
};

#endif // XMLFILE_H_INCLUDED
