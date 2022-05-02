//Name: Lim Yau Pan
// UID: 3035780568
// Description: The checkout function that evaluate the asset of the player
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double checkout( double security_price[6][9] , double portfolio[7] , int round_number){
  double sum = 0;
  for ( int i = 0 ; i < 6 ; i++ ){
    sum += (portfolio[i] * security_price[i][round_number]);
  }
  return sum + portfolio[6];
}
