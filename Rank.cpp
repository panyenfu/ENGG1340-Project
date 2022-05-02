//Name: Lim Yau Pan
//UID: 3035780568
//Description: Function that create a linked list and print the rank by linked list

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;

struct rankk{
  string name;
  double profit;
  rankk * next;
  rankk( string name , double profit ){
    this->name = name;
    this->profit = profit;
    this->next = nullptr;
  };
};

void insert( rankk tem , rankk * & head ){
  rankk * current = head , * temm = new rankk( tem.name , tem.profit );
  if ( current->profit < tem.profit ){
    temm->next = head;
    head = temm;
  }
  else{
    while ( current->next->profit > tem.profit ){
      if ( current->next->next == nullptr ) break;
      current = current->next;
    }
    if ( current->next->next == nullptr ){
      temm->next = current->next->next;
      current->next->next = temm;
    }
    else{
      temm->next = current->next;
      current->next = temm;
    }
  }
    return;
}

void out( rankk * head ){
  ofstream fout;
  rankk * current = head;
  fout.open("Rank_info");
  if (fout.fail()){
     exit(1);
  }
  cout << setw(4) <<"Rank"<< setw(20) << "Name" << setw(20) << "Asset" << endl;
  for ( int i = 1 ; i > 0 ; i++ ){
    if ( current == nullptr ) break;
    cout << i << '.' << setw(24) << current->name << setw(20) << fixed<< current->profit << endl;
    fout << current->name << endl << fixed << current->profit << endl;
    current = current->next;
  }
  fout.close();
  return;
}

void rankkk( string player , double asset ){
  string name , reader;
  double profit;
  rankk * head = nullptr , * tail = nullptr ;
  ifstream fin;
  fin.open( "Rank_info" );
  if ( fin.fail() ){
    exit(1);
  }
  while( getline( fin, name )){
    getline( fin , reader );
    profit = stod( reader );
    rankk *temm = new rankk( name , profit );
    if ( head == nullptr ){
      head = temm;
      tail = head;
    }
    else{ //head is not nullptr
      while ( tail->next != nullptr){
        tail = tail->next;
      }
      tail->next = temm;
    }

  }
    fin.close();
    rankk add( player , asset );
    insert( add , head );
    out( head );
}
