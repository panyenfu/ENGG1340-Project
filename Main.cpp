// Name: Lee Hong Yuen
// UID: 3035492317
// Description: Main + Outputinterface + PriceChange + PriceChange_Evaluation

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "Checkout.h"
#include "Buy.h"
#include "Rank.h"
#include "Sell.h"
using namespace std;

struct scenario {
  string description;
  string tips;
  int HSI;
  int SP500;
  int NIK;
  int FTSE;
  int Gold;
  int Bond;
};

string security_name[7] = { "Hang Seng Index", "S&P 500", "Nikkei 225 Index", "FSTE 100", "Gold", "US 10 Year Treasury Bond", "Cash"};

//change the price according to the pre-determined indicator
double PriceChange_Evaluation( double security_price , int indicator ){
  srand(time(NULL));
  double change_index;
  switch ( indicator ) {
    case -2: // Decrease the price by 10~20%
      security_price *= (rand()%11 + 80);
      security_price /= 100;
      break;
    case -1: // Decrease the price by 5~10%
      security_price *= (rand()%6 + 90);
      security_price /= 100;
      break;
    case 0: // Increase or decrease the price by 0~5%
      security_price *= (rand()%11 + 95);
      security_price /= 100;
      break;
    case 1: // Increase the price by 5~10%
      security_price *= (rand()%6 + 105);
      security_price /= 100;
      break;
    case 2:
      security_price *= (rand()%11 + 110);
      security_price /= 100;
      break;
    }
    return security_price;
  }

void PriceChange( double security_price[][9] , int round_number , struct scenario random_event ){
  int next_round = round_number + 1;
  security_price[0][next_round] = PriceChange_Evaluation( security_price[0][round_number] , random_event.HSI );
  security_price[1][next_round] = PriceChange_Evaluation( security_price[1][round_number] , random_event.SP500 );
  security_price[2][next_round] = PriceChange_Evaluation( security_price[2][round_number] , random_event.NIK );
  security_price[3][next_round] = PriceChange_Evaluation( security_price[3][round_number] , random_event.FTSE );
  security_price[4][next_round] = PriceChange_Evaluation( security_price[4][round_number] , random_event.Gold );
  security_price[5][next_round] = PriceChange_Evaluation( security_price[5][round_number] , random_event.Bond );
  return;
}

//output the interface of the game
void interface(scenario event[], int event_index, double portfolio[], string user_name, int &round, bool &hired_analyst, double security_price[][9], string security_name[]) {

  char recruitment_choice;
  int i;
  int action;
  double total_value = portfolio[6];

  cout << "__________________________________________________" <<  endl; //50 underscores act as seperation for previous output and current output
  cout << "Name: " <<  user_name <<  endl;
  cout << "Round: " <<  round <<  endl <<  endl;
  cout << "Your Portfolio: " << endl;
  //use the following for loop to output the portfolio
  for (int i = 0; i < 7; i++) {
    if (i == 6) //
      cout << (i+1) << ". " << setw(30) << security_name[i] << ": " << fixed << portfolio[i] << endl;
    else if (portfolio[i] != 0)
      cout << (i+1) << ". " << setw(30) <<  security_name[i] <<  ": " << setw(5) << portfolio[i]
           << " unit(s), Value: " << security_price[i][round]*portfolio[i] << endl;
  }
  for (int i = 0; i < 6; i++) {
    total_value = total_value + security_price[i][round]*portfolio[i];
  }
  cout << endl << "Total Value of Portfolio: " << total_value << endl;

  cout << endl << endl;

  cout <<  "Securities Available for Purchase:" <<  endl;
  for (int i = 0; i < 6; i++) {
    cout << (i+1) << ". " << setw(30) <<  security_name[i] <<  ": " << setw(20) <<fixed << security_price[i][round];
    if (round != 0) {
      cout << ", ";
      if (security_price[i][round] - security_price[i][round-1] > 0)
        cout << "Up for ";
      else
        cout << "Down for ";
      cout << setprecision(2) << abs ((security_price[i][round] - security_price[i][round-1])*100/security_price[i][round-1]) << "%";
    }
    cout << endl;
  }

  cout << endl << "Latest News:" << endl;
  cout << event[event_index].description << endl;
  if (hired_analyst) { //output the analysis if Player has already hired an analyst
    cout << "The following is the analysis done by your employee:" << endl;
    cout << event[event_index].tips << endl;
  }
    cout << endl;
    cout << "You can:" << endl;
    cout << "1. Hire an analyst (which costs you $1,000) to analyse and explain the news to you." << endl;
    cout << "2. Buy securities." << endl;
    cout << "3. Sell securities." << endl;
    cout << "4. End this round." << endl << endl;
    cout << "Input your action (1/2/3/4):" << endl;

    while( !( cin >> action ) || action != 1 && action != 2 && action != 3 && action != 4 ){
      cin.clear();                    // Clear the error flags
      cin.ignore(100, '\n');
      cout << "Invalid action. Input your action again (1/2/3/4): ";
    }

    switch (action) {
      case 1 :
        if (hired_analyst) { //check if Player has hired an analyst
          cout << "You already hired an analyst. The following is the analysis done by your employee:" << endl;
          cout << event[event_index].tips << endl;
        }
        else {
          cout << "Do you want to pay $1,000 to hire an analyst to explain the news to you (Y/N)? " << endl;
          cin >> recruitment_choice;
          //avoid an invalid input with the following while-loop
          while (recruitment_choice != 'Y' && recruitment_choice != 'N') {
            cout << "Invalid choice. Input your choice again (Y/N): ";
            cin >> recruitment_choice;
          }
          if (recruitment_choice == 'Y') {
            if (portfolio[6] >= 1000) {
              portfolio[6] = portfolio[6] - 1000;
              hired_analyst = true;
              cout << "The following is the analysis done by your employee:" << endl;
              cout << event[event_index].tips << endl;
            }
            else {
              cout << "You don't have enough money to hire an analyst." << endl;
            }
          }
      }
      break;
    case 2 :
    //function buy
      Buy( security_price , security_name , portfolio , round );
      break;
    case 3 :
    //function Sell
      sell( security_price , security_name , portfolio , round );
      break;
    case 4 :
      //change the prices for next round
      PriceChange( security_price , round , event[event_index] );
      //add 1 to round so that the function can exit the while loop in main
      round = round + 1;
      break;
  }
}

//initialise event and secuity price
void variable_initialisation(scenario event[], double security_price[][9]) {
  string eventfilename = "event.txt";
  string securitiesfile = "securitiesfile.txt";
  //read the data about different events
  ifstream eventfile;
  eventfile.open(eventfilename.c_str());
  if (eventfile.fail()) {
    cout << "Error in file opening." << endl;
    exit(1);
  }
  for (int i = 0; i < 16; i++) {
    //use the following string dummy variables for getline operation
    string hsi = "", sp500 = "", nik = "", ftse = "", gold = "", bond = "";
    getline(eventfile, event[i].description);
    getline(eventfile, event[i].tips);
    getline(eventfile, hsi);
    getline(eventfile, sp500);
    getline(eventfile, nik);
    getline(eventfile, ftse);
    getline(eventfile, gold);
    getline(eventfile, bond);
    //change the dummy variables from string to integer
    event[i].HSI = atoi(hsi.c_str());
    event[i].SP500 = atoi(sp500.c_str());
    event[i].NIK = atoi(nik.c_str());
    event[i].FTSE = atoi(ftse.c_str());
    event[i].Gold = atoi(gold.c_str());
    event[i].Bond = atoi(bond.c_str());
  }
  eventfile.close();

  //read the initial prices from file
  ifstream securitiesinfo;
  securitiesinfo.open(securitiesfile.c_str());
  if (securitiesinfo.fail()) {
    cout << "Error in file opening." << endl;
    exit(1);
  }
  for (int i = 0; i < 6; i++) {
    securitiesinfo >> security_price[i][0];
  }
  securitiesinfo.close();

}

int main() {
  string user_name;
  scenario event[16];
  int round = 0;
  bool hired_analyst;
  //initislise portfolio, which refers to the corresponding securities as in security_name
  //0 to 5 is unit of securities, 6 = amount of cash
  double portfolio[7] = {0, 0, 0, 0, 0, 0, 1000000};
  double security_price[6][9];
  double sum; // the total amount of money earned
  int event_index;

  variable_initialisation(event, security_price);

  cout << "What is your name? ";
  getline( cin , user_name );
  cout << "Hi " << user_name << ", you are an asset manager. You have to manage a portfolio of 1,000,000 cash." << endl;
  cout << "There are a fews securities available to you for purchase." << endl;
  cout << "They have different performance under different situatins." << endl;
  cout << "Your goal is to increase the value of your client's portfolio as much as possible. " << endl;

  for (int i = 0; i < 8; i++) {
    hired_analyst = false; //initialise this variable each round as hiring an analyst only valid for 1 round
    srand(time(NULL));
    event_index = rand() % 16;
    while (i == round){ //keep output the interface unless Player wants to exit a round
      interface(event, event_index, portfolio, user_name, round, hired_analyst, security_price, security_name);
    }
  }

  sum = checkout(security_price , portfolio , round);

  cout << endl << "You have finished this game." << endl;
  cout << "The current value of your portfolio is " << fixed << sum << endl;
  rankkk(user_name, sum);


}
