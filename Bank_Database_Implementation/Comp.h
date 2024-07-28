#ifndef COMP_H
#define COMP_H
#include "BaseClass.h"
#include <iostream>
#include <vector>
using namespace std;

class Comp : public BaseClass {
public:
    Comp();
  vector<Account>vect;
  vector<Account>arr;
  int size=199999;
  int size1=100003;
  int length=0;
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int pov(int n,int p);
    int ht(std::string id);
    int databaseSize() override;
    void sorted(vector<Account>&arr,int length);
    int hash(std::string id) override;
    int helper(std::string id); 
};
#endif // COMP_H
