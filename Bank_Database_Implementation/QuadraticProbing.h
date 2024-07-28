#ifndef QUADRATICPROBING_H
#define QUADRATICPROBING_H

#include "BaseClass.h"
#include <iostream>
#include<vector>
using namespace std;

class QuadraticProbing : public BaseClass {
public:
    vector<Account> arr;
  int size;
  int length;
    QuadraticProbing();
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override; 
    void sorted(vector<Account>&arr,int length);
    int pov(int n,int p);
    int ht(std::string id );
    int hash(std::string id) override;
    // Other data members and functions specific to Quadratic Probing
};

#endif // QUADRATICPROBING_H
