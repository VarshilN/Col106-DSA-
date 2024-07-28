#ifndef CHAINING_H
#define CHAINING_H
#include "BaseClass.h"
#include <iostream>
#include <vector>
using namespace std;

class Chaining : public BaseClass {
public:
    int size;
    int tsize;
   vector<Account>arr;
    int ht(std::string id);
    void sorted(vector<Account>&arr,int size);
    Chaining();
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;
};
#endif // CHAINING_H
