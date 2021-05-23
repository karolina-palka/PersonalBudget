#include "XmlUsersFile.h"

void XmlUsersFile:: addUserToXmlFile(User user)
{
//    fstream file;
//    bool fileStatus;
//    char fileName[]="users.txt";
    if (isFileEmpty()== true)
    {
        xml.ResetPos();
        xml.InsertNode( xml.MNT_PROCESSING_INSTRUCTION, "xml" );
        xml.SetAttrib( "version", "1.0");
        xml.SetAttrib("standalone", "no" );
        xml.AddNode( xml.MNT_DOCUMENT_TYPE, "<!DOCTYPE user SYSTEM 'finances.dtd'>");

        xml.AddNode( CMarkup::MNT_COMMENT, "user" );
    }

    xml.AddElem("user");
    xml.IntoElem();

    int userId = user.getId();
//    string userIdStr = AuxiliaryMethods:: convertIntToString(userId);
    xml.AddElem("userId", userId);
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
    cout << "Changes saved." << endl;
    system("pause");

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
vector <User> XmlUsersFile:: loadUsersFromFile()
{
 //   if (isFileEmpty()== true)
    User user;
    vector <User> users;
    int userId;
    string login, name, surname, password, userIdstr;
    xml.Load(XmlFile::getFileName());
//    xml.FindElem("user");
//    int i =0;
    while (xml.FindElem("user")==true)
    {
        xml.IntoElem();
        xml.FindElem("userId");
        userIdstr = xml.GetData();
        userId = AuxiliaryMethods:: convertStringToInteger(userIdstr);
        user.setId(userId);
        cout << user.getId() << endl;
        xml.FindElem("userData");
        xml.IntoElem();
        xml.FindElem("login");
        user.setLogin(xml.GetData());
        cout << user.getLogin() << endl;
        xml.FindElem("password");
        user.setPassword(xml.GetData());
        cout << user.getPassword() << endl;
        xml.FindElem("name");
        user.setName(xml.GetData());
        cout << user.getName() << endl;
        xml.FindElem("surname");
        user.setSurname(xml.GetData());
        xml.OutOfElem();
        xml.OutOfElem();
        cout << user.getSurname() << endl;
        users.push_back(user);
//        i++;
    }
    return users;
}
