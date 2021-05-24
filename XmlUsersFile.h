#ifndef XMLUSERSFILE_H_INCLUDED
#define XMLUSERSFILE_H_INCLUDED
#include "XmlFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"
//#include "Markup.h"

using namespace std;

class XmlUsersFile: public XmlFile
{
    User loadUserDataFromFile();

public:
    XmlUsersFile(string fileName): XmlFile(fileName) {};

    void addUserToXmlFile(User user);
    vector <User> loadUsersFromFile();
};


#endif // XMLUSERSFILE_H_INCLUDED
