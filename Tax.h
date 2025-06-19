#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class account {
protected:
    std::string log = "0";
    std::string password = "0";
    std::string income = "0";
    std::string home = "0";
    std::string age = "0";

public:
    virtual void input_data();
    virtual void calculate_taxes() = 0;
    virtual void account_info() const = 0;
    virtual ~account() = default;

    std::string get_login() const { return log; }
    std::string get_password() const { return password; }

    
    void set_income(const std::string& inc) { income = inc; }               //for gtest
    void set_home(const std::string& h) { home = h; }
    void set_age(const std::string& a) { age = a; }

    std::string get_income() const { return income; }
    std::string get_home() const { return home; }
    std::string get_age() const { return age; }
};


class pl : public account {
public:
    std::string income_taxes;
    std::string estate_taxes;

    void calculate_taxes() override;
    void account_info() const override;
};


class ua : public account {
public:
    std::string income_taxes;
    std::string estate_taxes;

    void calculate_taxes() override;
    void account_info() const override;
};

#endif // ACCOUNT_H
