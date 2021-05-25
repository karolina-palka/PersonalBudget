#include "XmlFile.h"

bool XmlFile:: isFileEmpty(string keyType)
{
    bool status = false;
    xml.Load(FILE_NAME);
    if (xml.FindElem(keyType)== false)
        status = true;
    return status;
}
string XmlFile:: getFileName()
{
    return FILE_NAME;
}
