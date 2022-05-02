//Name: Lim Yau Pan
// UID: 3035780568
// Description: The function that sell the stocks
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void sell( double security_price[6][9] , string security_name[6] , double portfolio[7] , int round_number ){
  int code;
  string name , switch_of_while_loop = "Yes";
  double price;
  double units;
  double possess;
  cout << "Your portfolio:" << endl;
  for ( int i = 0 ; i < 6 ; i++){
    cout << i+1 << ". " << setw(25) << security_name[i] << ": " << portfolio[i] << "units ( $"
         << security_price[i][round_number]*portfolio[i] << " )"<< endl;
  }
    cout << "Which security do you want to sell? Input the code." << endl;
    while( !( cin >> code ) || code < 1 || code > 6 ){
      cin.clear();                    // Clear the error flags
      cin.ignore(100, '\n');
      cout << "Invalid input, please input it again. " << endl;
      cout << "Which security do you want to sell? Input the code." << endl;
    }
    name = security_name[code-1];
    price = security_price[code-1][round_number];
    possess = portfolio[code-1];
    cout << "How many units of " << name << " do you want to sell? (Max: "
         << possess << ')' << endl;
    while ( !( cin >> units ) || units < 0 || units > possess ){
        cin.clear();                    // Clear the error flags
        cin.ignore(100, '\n');
        cout << "Invalid input, please input it again." << endl;
        cout << "How many units of " << name << " do you want to sell? (Max: "
             << possess << ')' << endl;
    }
    cout << "You earn: $" << units*price << "." << endl;
    portfolio[code-1]-=units;
    portfolio[6] += units * price;
}
