#include "XmlFinanceFile.h"

void XmlFinanceFile:: addFinancesToXmlFile(Finance finance, string financeType)
{
    if (isFileEmpty(financeType)== true)
    {
        xml.ResetPos();
        xml.InsertNode( xml.MNT_PROCESSING_INSTRUCTION, "xml" );
        xml.SetAttrib( "version", "1.0");
        xml.SetAttrib("standalone", "no" );
        xml.AddNode( xml.MNT_DOCUMENT_TYPE, "<!DOCTYPE user SYSTEM 'users.dtd'>");

        xml.AddNode( CMarkup::MNT_COMMENT, financeType );
    }
//    xml.FindElem
//    xml.FindPrevElem(financeType);
    while (xml.FindElem(financeType)){}

    xml.AddElem(financeType);
    xml.IntoElem();

    int userId = finance.getUserId();
    xml.AddElem("userId", userId);
    int financeId = finance.getFinanceId();
    xml.AddElem("financeId", financeId);
    xml.AddElem("financeData");
    int date = finance.getDate();
//    cout << "dateStr: " << dateStr << endl;
    xml.AddChildElem("date", date);
    string dateStr = finance.getDateStr();
    xml.AddChildElem("dateStr", dateStr);
    string item = finance.getItem();
    xml.AddChildElem("item", item);
    double amount = finance.getAmount();
    cout << "Amount: " << amount << endl;
    string amountStr = AuxiliaryMethods:: convertDoubleToString(amount);
    xml.AddChildElem("amount", amountStr);
    xml.Save(XmlFile::getFileName());
}
/* bool XmlFinanceFile:: isAnyFinanceSaved(string financeType, int loggedInUserId)
 {
//    int financeId = 0;
    bool status=false;
    xml.Load(XmlFile::getFileName());
//    xml.FindElem(financeType);
    cout << "fileName: " << XmlFile::getFileName() << endl;
    cout << "financeType: " << financeType << endl;
    string loggedInUserIdStr = AuxiliaryMethods:: convertIntToString(loggedInUserId);

    while(xml.FindElem(financeType)==true)
    {
        xml.IntoElem();
        xml.FindElem("userId");
        if (loggedInUserIdStr == xml.GetData())
        {
            status = true;
        }
        xml.OutOfElem();
    }
    return status;
 }*/
// void openXmlFile()
// {
//     xml.Load(XmlFile::getFileName());
// }
vector <Finance> XmlFinanceFile:: loadFinancesFromFile(string financeType, int loggedInUserId)
{
    Finance finance;
    vector <Finance> finances;
//    finances.clear();
    cout << "financeType: " << financeType << endl;

    xml.Load(XmlFile::getFileName());
//    string loggedInUserIdStr = AuxiliaryMethods:: convertIntToString(loggedInUserId);

    while (xml.FindElem(financeType)==true)
    {
        finance = loadFinanceFromFile(loggedInUserId);
        if (finance.getAmount() != 0)
        {
            finances.push_back(finance);
            cout << "Loaded." << endl;
        }
    }
    if (finances.empty()==true)
        cout << "You don't have any " << financeType << "s yet." << endl;
    return finances;
}
Finance XmlFinanceFile:: loadFinanceFromFile(int loggedInUserId)
{
    Finance finance;
    xml.IntoElem();
    xml.FindElem("userId");
//    char dateToBeSaved[11];
    string loggedInUserIdStr = AuxiliaryMethods:: convertIntToString(loggedInUserId);
    if (loggedInUserIdStr == xml.GetData())
    {
//        cout << "Udalo sie tu dostac!" << endl;
        int userId = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        finance.setUserId(userId);
        cout << finance.getUserId() << endl;
        xml.FindElem("financeId");
        string financeIdstr = xml.GetData();
        int financeId = AuxiliaryMethods:: convertStringToInteger(financeIdstr);
        finance.setFinanceId(financeId);
        cout << finance.getFinanceId() << endl;
        xml.FindElem("financeData");
        xml.IntoElem();
        xml.FindElem("date");
        string dateStr = xml.GetData();
        int date = AuxiliaryMethods::convertStringToInteger(dateStr);

        finance.setDate(date);
//        finance.setDate(AuxiliaryMethods:: convertStringToInteger(dateStr));
        cout << finance.getDate() << endl;
        xml.FindElem("dateStr");
        dateStr = xml.GetData();
        finance.setDateStr(dateStr);
        cout << finance.getDateStr() << endl;
        xml.FindElem("item");
        finance.setItem(xml.GetData());
        cout << finance.getItem() << endl;
        xml.FindElem("amount");
        string amountStr = xml.GetData();
        finance.setAmount(AuxiliaryMethods:: convertStringToDouble(amountStr));
        cout << finance.getAmount() << endl;

        xml.OutOfElem();
        xml.OutOfElem();
    }
    else
    {
        xml.OutOfElem();
        xml.OutOfElem();
        finance.setUserId(0);
        finance.setFinanceId(0);
        finance.setDate(0);
        finance.setDateStr("");
        finance.setItem("");
        finance.setAmount(0.0);
    }
    return finance;
}
int XmlFinanceFile:: getNewFinanceId(string financeType, int loggedInUserId)
{
    int financeId = 0;
    xml.Load(XmlFile::getFileName());
    string loggedInUserIdStr = AuxiliaryMethods:: convertIntToString(loggedInUserId);
    cout << "loggedInUserIdStr: " << loggedInUserIdStr << endl;

    while (xml.FindElem(financeType))
    {
        xml.IntoElem();
        xml.FindElem("userId");
//        cout << "Jestem tutaj" << endl;
        if (loggedInUserIdStr == xml.GetData())
        {
            xml.FindElem("financeId");
            string financeIdstr = xml.GetData();
            cout << "financeIdstr: " << financeIdstr << endl;
            financeId = AuxiliaryMethods:: convertStringToInteger(financeIdstr);
        }
        xml.OutOfElem();
    }
    cout << "financeId: " << financeId << endl;
    return financeId + 1;
}
