//练习 7.57：编写你自己的 Account 类。

#include <string>

class Account {
   private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate;

   public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
};

void Account::rate(double newRate) {
    interestRate = newRate;
}

