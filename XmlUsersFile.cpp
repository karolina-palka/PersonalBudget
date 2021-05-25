#include "XmlUsersFile.h"

void XmlUsersFile:: addUserToXmlFile(User user)
{
    if (isFileEmpty("user")== true)
    {
        xml.ResetPos();
        xml.InsertNode( xml.MNT_PROCESSING_INSTRUCTION, "xml" );
        xml.SetAttrib( "version", "1.0");
        xml.SetAttrib("standalone", "no" );
        xml.AddNode( xml.MNT_DOCUMENT_TYPE, "<!DOCTYPE user SYSTEM 'finances.dtd'>");

        xml.AddNode( CMarkup::MNT_COMMENT, "user" );
    }
    while (xml.FindElem("user")){}
    xml.AddElem("user");
    xml.IntoElem();

    int userId = user.getId();
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

    cout << "Changes saved." << endl;
    system("pause");
}
vector <User> XmlUsersFile:: loadUsersFromFile()
{
    User user;
    vector <User> users;
    int userId;
    string login, name, surname, password, userIdstr;
    xml.Load(XmlFile::getFileName());

    while (xml.FindElem("user")==true)
    {
        user = loadUserDataFromFile();
        if (user.getId() == 0)
        {
            return users;
        }
        else
        {
            users.push_back(user);
        }
    }

    return users;
}
User XmlUsersFile:: loadUserDataFromFile()
{
    User user;
    string userIdstr;
    xml.IntoElem();
    xml.FindElem("userId");
    userIdstr = xml.GetData();
    user.setId(AuxiliaryMethods:: convertStringToInteger(userIdstr));
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

    return user;
}
void XmlUsersFile:: saveNewPasswordToXmlFile(User &user)
{
    int userId = user.getId();
    string newPassword = user.getPassword();
    string userIdStr = AuxiliaryMethods:: convertIntToString(userId);

    xml.Load(XmlFile::getFileName());
    while (xml.FindElem("user")==true)
    {
        xml.IntoElem();
        xml.FindElem("userId");
        if (userIdStr == xml.GetData())
        {
            xml.FindElem("userData");
            xml.IntoElem();
            xml.FindElem("password");
            xml.RemoveElem();
            xml.AddElem("password", newPassword);
        }
        xml.OutOfElem();
    }
    xml.Save(XmlFile::getFileName());
    cout << "The new password has been saved." << endl;
}
