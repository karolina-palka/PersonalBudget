#include "XmlFile.h"

bool XmlFile:: isFileEmpty()
{
    bool status = false;
    xml.Load(FILE_NAME);
    if (xml.FindElem("user")== false)
        status = true;
    return status;
}
string XmlFile:: getFileName()
{
    return FILE_NAME;
}
