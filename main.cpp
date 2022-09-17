#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float round(float var, int decimals)
{
    float value;
    float rounded;
    if (decimals == 1){
        value = (int)(var * 10 + .5);
        rounded = (float)value / 10;
    }
    else if (decimals == 2){
        value = (int)(var * 100 + .5);
        rounded = (float)value / 100;
    }
    else if (decimals == 3){
        value = (int)(var * 1000 + .5);
        rounded = (float)value / 1000;
    }
    else if (decimals == 4){
        value = (int)(var * 10000 + .5);
        rounded = (float)value / 10000;
    }
    return rounded;
}

float dkkToEur(int value)
{
    float dkkRate = 0.13447f;
    float rate = round(dkkRate, 3);
    float euro = 0;
    for (int i = 0; i <= value; i++) {
        euro = euro + rate;
    }
    return euro;
}

float dkkToUsd(int value)
{
    float dkkRate = 0.134626f;
    float rate = round(dkkRate, 3);
    float usd = 0;
    for (int i = 0; i <= value; i++) {
        usd = usd + rate;
    }
    return usd;
}

float dkkToGbp(float value)
{
    float dkkRate = 0.117906f;
    float rate = round(dkkRate, 3);
    float gpd = 0;
    for (int i = 0; i <= value; i++) {
        gpd = gpd + rate;
    }
    return gpd;
}

float eurToDkk(float value)
{
    float eurRate = 0.1345f;
    return value * eurRate;
}

float eurToUsd(float value)
{
    float eurRate = 0.1175f;
    return value * eurRate;
}

float eurToGbp(float value)
{
    float eurRate = 0.1175f;
    return value * eurRate;
}

int main()
{
    cout << "Do you want convert to currency? Press Y for yes and N for no." << endl;
    char answer;
    bool check;
    cin >> answer;
    cout << answer << endl;
    check = (answer == 'Y') ? true : false;
    while (answer == 'Y'){
        cout << "Which currency would you like to convert from : " << endl;
        cout << "Press 0 to exit." << endl;
        cout << "- DKK - Press 1" << endl;
        cout << "- EUR - Press 2" << endl;
        cout << "- USD - Press 3" << endl;
        cout << "- GBP - Press 4" << endl;
        int currencyChoice;
        int convertChoice;
        float value;
        cin >> currencyChoice;
        switch (currencyChoice)
        {
        case 1:
            // DKK
            cout << "Which currency would you to convert to - use menue above for reference." << endl;
            cin >> convertChoice;
            if (convertChoice == 2){
                cout << "How much would you like to convert?" << endl;
                cin >> value;
                float currency = dkkToEur(value);
                cout << value << "DKK is " << fixed << setprecision(2) << currency << "EUR." << endl;
            }
            else if (convertChoice == 3){
                cout << "How much would you like to convert?" << endl;
                cin >> value;
                float currency = dkkToUsd(value);
                cout << value << "DKK is " << fixed << setprecision(2) << currency << "USD." << endl;
            } else if (convertChoice == 4){
                cout << "How much would you like to convert?" << endl;
                cin >> value;
                float currency = dkkToGbp(value);
                cout << value << "DKK is " << fixed << setprecision(2) << currency << "GPD." << endl;
            }
            break;
        case 2:
            // EUR
            if (convertChoice == 1){
                cout << "How much would you like to convert?" << endl;
                cin >> value;
                float currency = eurToDkk(value);
                cout << value << "EUR is " << fixed << setprecision(2) << currency << "DKK." << endl;
            }
            else if (convertChoice == 3){
                cout << "How much would you like to convert?" << endl;
                cin >> value;
                float currency = dkkToUsd(value);
                cout << value << "EUR is " << fixed << setprecision(2) << currency << "USD." << endl;
            } else if (convertChoice == 4){
                cout << "How much would you like to convert?" << endl;
                cin >> value;
                float currency = eurToGbp(value);
                cout << value << "EUR is " << fixed << setprecision(2) << currency << "GPD." << endl;
            }
        }
        cout << "Do you want convert to currency? Press Y for yes and N for no." << endl;
        cin >> answer;
    }
    cout << "Thank you for using our service." << endl;
    return 0;
}