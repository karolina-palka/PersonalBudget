#ifndef XMLFILE_H_INCLUDED
#define XMLFILE_H_INCLUDED
#include <iostream>
#include "User.h"
#include "Markup.h"

class XmlFile
{
    const string FILE_NAME;
    CMarkup xml;

public:
    bool isFileEmpty();
};

#endif // XMLFILE_H_INCLUDED
