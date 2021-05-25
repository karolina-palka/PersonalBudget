#ifndef XMLUSERSFILE_H_INCLUDED
#define XMLUSERSFILE_H_INCLUDED
#include "XmlFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"


using namespace std;

class XmlUsersFile: public XmlFile
{
    User loadUserDataFromFile();

public:
    XmlUsersFile(string fileName): XmlFile(fileName) {};

    void addUserToXmlFile(User user);
    vector <User> loadUsersFromFile();
    void saveNewPasswordToXmlFile(User &user);
};


#endif // XMLUSERSFILE_H_INCLUDED
