#include "AuxiliaryMethods.h"

string AuxiliaryMethods:: getTheLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}
string AuxiliaryMethods:: convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
string AuxiliaryMethods:: getTheNumber(string text, int charPosition)
{
    string number = "";
    cin.sync();
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}
int AuxiliaryMethods:: convertStringToInteger(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
char AuxiliaryMethods:: getChar()
{
    string input = "";
    char character  = {0};
    cin.sync();
    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Please type again." << endl;
    }
    return character;
}
double AuxiliaryMethods:: convertStringToDouble(string stringToBeConverted)
{
    for (int i=0; i<stringToBeConverted.length(); i++)
    {
        if (stringToBeConverted[i]==',')
        {
            stringToBeConverted[i]= '.';
        }
    }
    double number = stod(stringToBeConverted);
    return number;
}
string AuxiliaryMethods:: convertDoubleToString(double numberToBeConverted)
{
    string numberStr = to_string(numberToBeConverted);
    return numberStr;
}
