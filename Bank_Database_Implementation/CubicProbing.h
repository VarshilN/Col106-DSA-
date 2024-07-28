#ifndef CUBICPROBING_H
#define CUBICPROBING_H
#include "BaseClass.h"
#include <iostream>
#include<vector>
using namespace std;

class CubicProbing : public BaseClass {
public:
  int size=199999;
  int length=0;
  vector<Account>arr;
    CubicProbing();
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

    // Other data members and functions specific to Quadratic Probing
};

#endif // CUBICPROBING_H
