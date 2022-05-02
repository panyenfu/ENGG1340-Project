//Name: Lim Yau Pan
// UID: 3035780568
// Description: The purchase function
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void Buy( double security_price [][9] , string security_name[6] , double portfolio[7] , int round_number){
  int code;
  int UpperLimit;
  double units;
  string name , confirm_button , switch_of_while_loop = "Yes";
  double price;
  cout << "Your Action: " << "Purchase Securities" << endl;
  cout << "1. " << setw(30) << security_name[0] << setw(20) << "Market Price: "
       << security_price[0][round_number] << endl;
  cout << "2. " << setw(30) << security_name[1] << setw(20) << "Market Price: "
       << security_price[1][round_number] << endl;
  cout << "3. " << setw(30) << security_name[2] << setw(20) << "Market Price: "
       << security_price[2][round_number] << endl;
  cout << "4. " << setw(30) << security_name[3] << setw(20) << "Market Price: "
       << security_price[3][round_number] << endl;
  cout << "5. " << setw(30) << security_name[4] << setw(20) << "Market Price: "
       << security_price[4][round_number] << endl;
  cout << "6. " << setw(30) << security_name[5] << setw(20) << "Market Price: "
       << security_price[5][round_number] << endl;
    cout << "Which security do you want to purchase? Input the code" << endl;
    while( !( cin >> code ) || code < 1 || code > 6 ){
      cin.clear();                    // Clear the error flags
      cin.ignore(100, '\n');
      cout << "Invalid input, please input it again. " << endl;
      cout << "Which security do you want to purchase? Input the code" << endl;
    }
    name = security_name[code-1];
    price = security_price[code-1][round_number];
    UpperLimit = (portfolio[6]/price);
    cout << "How many units of " << name << " do you want to purchase? (Max: "
         << UpperLimit << ')' << endl;
    while ( !( cin >> units ) || units < 0 || units > UpperLimit ){
      cin.clear();                    // Clear the error flags
      cin.ignore(100, '\n');
        cout << "Invalid input, please input it again. " << endl;
        cout << "How many units of " << name << " do you want to purchase? (Max: "
             << UpperLimit << ')' << endl;
    }
    cout << "You have to pay: $" << units*price << "." << endl;
    cout << "Deal completed! You have to pay " << units*price <<  "." << endl;
    portfolio[code-1]+=units;
    portfolio[6]-=units*price;
}
