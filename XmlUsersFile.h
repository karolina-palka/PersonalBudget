#ifndef XMLUSERSFILE_H_INCLUDED
#define XMLUSERSFILE_H_INCLUDED
#include "XmlFile.h"
#include "User.h"
//#include "Markup.h"

using namespace std;

class XmlUsersFile: public XmlFile
{
//    CMarkup xml;
public:
    XmlUsersFile(string fileName): XmlFile(fileName) {};
//    XmlUsersFile()
//    {
//        CMarkup xml;
//    }
    void addUserToXmlFile(User user);
};


#endif // XMLUSERSFILE_H_INCLUDED
