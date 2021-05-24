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
    string dateStr = finance.getDate();
    cout << "dateStr: " << dateStr << endl;
    xml.AddChildElem("date", dateStr);
    string item = finance.getItem();
    xml.AddChildElem("item", item);
    int amount = finance.getAmount();
    xml.AddChildElem("amount", amount);
    xml.Save(XmlFile::getFileName());
}
vector <Finance> XmlFinanceFile:: loadFinancesFromFile(string financeType, int loggedInUserId)
{
    Finance finance;
    vector <Finance> finances;
    cout << "financeType: " << financeType << endl;

    xml.Load(XmlFile::getFileName());
    string loggedInUserIdStr = AuxiliaryMethods:: convertIntToString(loggedInUserId);

    while (xml.FindElem(financeType)==true)
    {
        finance = loadFinanceFromFile(loggedInUserIdStr);
        if (finance.getAmount() == 0)
        {
            cout << "You don't have any " << financeType << "s yet." << endl;
            return finances;
        }
        else
        {
            finances.push_back(finance);
            cout << "Loaded." << endl;
        }
    }
    return finances;
}
Finance XmlFinanceFile:: loadFinanceFromFile(string loggedInUserIdStr)
{
    Finance finance;
    xml.IntoElem();
    xml.FindElem("userId");
    char dateToBeSaved[11];
    if (loggedInUserIdStr == xml.GetData())
    {
        xml.FindElem("financeId");
        string financeIdstr = xml.GetData();
        int financeId = AuxiliaryMethods:: convertStringToInteger(financeIdstr);
        finance.setFinanceId(financeId);
        cout << finance.getFinanceId() << endl;
        xml.FindElem("financeData");
        xml.IntoElem();
        xml.FindElem("date");
        string dateStr = xml.GetData();
        for (int i=0; i<11; i++)
        {
            dateToBeSaved[i] = dateStr[i];
        }
        finance.setDate(dateToBeSaved);
//        finance.setDate(AuxiliaryMethods:: convertStringToInteger(dateStr));
        cout << finance.getDate() << endl;
        xml.FindElem("item");
        finance.setItem(xml.GetData());
        cout << finance.getItem() << endl;
        xml.FindElem("amount");
        string amountStr = xml.GetData();
        finance.setAmount(AuxiliaryMethods:: convertStringToInteger(amountStr));
        cout << finance.getAmount() << endl;

        xml.OutOfElem();
        xml.OutOfElem();
    }
//    else
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
