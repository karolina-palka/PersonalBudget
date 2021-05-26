#include "XmlFinanceFile.h"

void XmlFinanceFile:: addFinancesToXmlFile(Finance finance, string financeType)
{
    if (isFileEmpty(financeType)== true)
    {
        xml.ResetPos();
        xml.InsertNode( xml.MNT_PROCESSING_INSTRUCTION, "xml" );
        xml.SetAttrib( "version", "1.0");
        xml.SetAttrib("standalone", "no" );
        xml.AddNode( xml.MNT_DOCUMENT_TYPE, "<!DOCTYPE user SYSTEM 'finances.dtd'>");
        xml.AddNode( CMarkup::MNT_COMMENT, financeType );
    }

    while (xml.FindElem(financeType)){}

    xml.AddElem(financeType);
    xml.IntoElem();

    int userId = finance.getUserId();
    xml.AddElem("userId", userId);

    int financeId = finance.getFinanceId();
    xml.AddElem("financeId", financeId);
    xml.AddElem("financeData");

    int date = finance.getDate();
    xml.AddChildElem("date", date);

    string dateStr = finance.getDateStr();
    xml.AddChildElem("dateStr", dateStr);

    string item = finance.getItem();
    xml.AddChildElem("item", item);

    double amount = finance.getAmount();
    string amountStr = AuxiliaryMethods:: convertDoubleToString(amount);
    xml.AddChildElem("amount", amountStr);
    xml.Save(XmlFile::getFileName());
}

vector <Finance> XmlFinanceFile:: loadFinancesFromFile(string financeType, int loggedInUserId)
{
    Finance finance;
    vector <Finance> finances;

    xml.Load(XmlFile::getFileName());

        while (xml.FindElem(financeType)==true)
        {
            finance = loadFinanceFromFile(loggedInUserId);
            if (finance.getAmount() != 0)
            {
                finances.push_back(finance);
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

    string loggedInUserIdStr = AuxiliaryMethods:: convertIntToString(loggedInUserId);
    if (loggedInUserIdStr == xml.GetData())
    {
        int userId = AuxiliaryMethods::convertStringToInteger(xml.GetData());
        finance.setUserId(userId);

        xml.FindElem("financeId");
        string financeIdstr = xml.GetData();
        int financeId = AuxiliaryMethods:: convertStringToInteger(financeIdstr);
        finance.setFinanceId(financeId);

        xml.FindElem("financeData");
        xml.IntoElem();

        xml.FindElem("date");
        string dateStr = xml.GetData();
        int date = AuxiliaryMethods::convertStringToInteger(dateStr);
        finance.setDate(date);

        xml.FindElem("dateStr");
        dateStr = xml.GetData();
        finance.setDateStr(dateStr);

        xml.FindElem("item");
        finance.setItem(xml.GetData());

        xml.FindElem("amount");
        string amountStr = xml.GetData();
        finance.setAmount(AuxiliaryMethods:: convertStringToDouble(amountStr));

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
int XmlFinanceFile:: getNewFinanceId(string financeType)
{
    int financeId = 0;
    xml.Load(XmlFile::getFileName());

    while (xml.FindElem(financeType))
    {
        xml.IntoElem();

        xml.FindElem("financeId");
        string financeIdstr = xml.GetData();
        financeId = AuxiliaryMethods:: convertStringToInteger(financeIdstr);
        xml.OutOfElem();
    }
    return financeId + 1;
}
