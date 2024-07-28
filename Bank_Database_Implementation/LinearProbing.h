#ifndef LINEARPROBING_H
#define LINEARPROBING_H
#include "BaseClass.h"
#include <iostream>
#include<vector>
using namespace std;
class LinearProbing : public BaseClass {
public:
   int size=199999;
   int length=0;
    LinearProbing();
   vector<Account>arr;
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int pov(int n,int p);
    int ht(std::string id);
    void sorted(vector<Account>&arr,int length);
    int databaseSize() override;
    int hash(std::string id) override;
  // Other data members and functions specific to Linear Probing
};
#endif // LINEARPROBING_H
