#include "XmlFinanceFile.h"

void XmlFinanceFile:: addFinancesToXmlFile(Finance finance, string financeType)
{
        if (isFileEmpty()== true)
    {
        xml.ResetPos();
        xml.InsertNode( xml.MNT_PROCESSING_INSTRUCTION, "xml" );
        xml.SetAttrib( "version", "1.0");
        xml.SetAttrib("standalone", "no" );
        xml.AddNode( xml.MNT_DOCUMENT_TYPE, "<!DOCTYPE user SYSTEM 'users.dtd'>");

        xml.AddNode( CMarkup::MNT_COMMENT, financeType );
    }

    xml.AddElem(financeType);
    xml.IntoElem();

//    int userId = user.getId();
//    string userIdStr = AuxiliaryMethods:: convertIntToString(userId);
//    xml.AddElem("userId", userId);
    int financeId = finance.getFinanceId();
    xml.AddElem("financeId", financeId);
    xml.AddElem("financeData");
    int date = finance.getDate();
    xml.AddChildElem("date", date);
    string item = finance.getItem();
    xml.AddChildElem("item", item);
    int amount = finance.getAmount();
    xml.AddChildElem("amount", amount);
    xml.Save(XmlFile::getFileName());
}
vector <Finance> XmlFinanceFile:: loadFinancesFromFile(string financeType)
{
 //   if (isFileEmpty()== true)
    Finance finance;
    vector <Finance> finances;
    cout << "financeType: " << financeType << endl;
//    int userId;
//    string login, name, surname, password, userIdstr;
    xml.Load(XmlFile::getFileName());
//    cout << "filename: " << XmlFile::getFileName() << endl;
//    xml.FindElem("user");
//    int i =0;
    while (xml.FindElem(financeType)==true)
    {
        finance = loadFinanceFromFile();
/*        xml.IntoElem();
        xml.FindElem("financeId");
        string financeIdstr = xml.GetData();
        int financeId = AuxiliaryMethods:: convertStringToInteger(financeIdstr);
        finance.setFinanceId(financeId);
        cout << finance.getFinanceId() << endl;
        xml.FindElem("financeData");
        xml.IntoElem();
        xml.FindElem("date");
        string dateStr = xml.GetData();
        finance.setDate(AuxiliaryMethods:: convertStringToInteger(dateStr));
        cout << finance.getDate() << endl;
        xml.FindElem("item");

        finance.setItem(xml.GetData());

        cout << finance.getItem() << endl;
        xml.FindElem("amount");
        string amountStr = xml.GetData();
        finance.setAmount(AuxiliaryMethods:: convertStringToInteger(amountStr));
        cout << finance.getAmount() << endl;

        xml.OutOfElem();
        xml.OutOfElem();*/

        finances.push_back(finance);
    }
    cout << "Loaded." << endl;
    return finances;
}
Finance XmlFinanceFile:: loadFinanceFromFile()
{
    Finance finance;
    xml.IntoElem();
    xml.FindElem("financeId");
    string financeIdstr = xml.GetData();
    int financeId = AuxiliaryMethods:: convertStringToInteger(financeIdstr);
    finance.setFinanceId(financeId);
    cout << finance.getFinanceId() << endl;
    xml.FindElem("financeData");
    xml.IntoElem();
    xml.FindElem("date");
    string dateStr = xml.GetData();
    finance.setDate(AuxiliaryMethods:: convertStringToInteger(dateStr));
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
    return finance;
}
