#include "XmlUsersFile.h"

void XmlUsersFile:: addUserToXmlFile(User user)
{
//    fstream file;
//    bool fileStatus;
//    char fileName[]="users.txt";
    xml.ResetPos();
    xml.InsertNode( xml.MNT_PROCESSING_INSTRUCTION, "xml" );
    xml.SetAttrib( "version", "1.0");
    xml.SetAttrib("standalone", "no" );
    xml.AddNode( xml.MNT_DOCUMENT_TYPE, "<!DOCTYPE user SYSTEM 'users.dtd'>");

    xml.AddNode( CMarkup::MNT_COMMENT, "user" );

    xml.AddElem("user");
    xml.IntoElem();
//    int userId = user.getId();
//    xml.AddElem("userId", userId);
    xml.AddElem("userData");
    string login = user.getLogin();
    xml.AddChildElem("login", login);
    string password = user.getPassword();
    xml.AddChildElem("password", password);
    string name = user.getName();
    xml.AddChildElem("name", name);
    string surname = user.getSurname();
    xml.AddChildElem("surname", surname);
    xml.Save(XmlFile::getFileName());
//    fileStatus = checkFileStatus(file);
//    if (fileStatus == true)
//    {
//        remove(fileName);
//    }
//    file.open(fileName, ios_base::out );
//    int userNumber = users.size();
//    for (int i=0; i<users.size(); i++)
//    {
//        file << users[i].id << "|" << users[i].username << "|";
//        file << users[i].password << "|" << endl;
//    }

//    file.close();

    cout << "Changes saved." << endl;
    system("pause");
}
