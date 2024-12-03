#include "BankAccount.h"
#include <cassert>
#include <iostream>
using namespace std;

// Unit Tests

void test_deposit() {
    cout << "Unit Tests Started" << endl; 
    BankAccount account(100.0);
    account.deposit(50.0);
    assert(account.check_balance() == 150.0);

    try {
        account.deposit(-10.0);
        assert(false); // it Should not reach here
    } catch (invalid_argument &e) {
        assert(true); // Exception thrown as expected
    }

    cout << "Test Case-1 Passed" << endl; 
}

void test_withdraw() {
    BankAccount account(100.0);
    account.withdraw(50.0);
    assert(account.check_balance() == 50.0);

    try {
        account.withdraw(200.0);
        assert(false); // Should not reach here
    } catch (runtime_error &e) {
        assert(true); // Exception thrown as expected
    }

    try {
        account.withdraw(-10.0);
        assert(false); // Should not reach here
    } catch (invalid_argument &e) {
        assert(true); // Exception thrown as expected
    }

    cout << "Test Case-2 Passed" << endl; 
}

void test_check_balance() {
    BankAccount account(200.0);
    assert(account.check_balance() == 200.0);
}

void unit_test_message(){
    cout << "All Unit Tests Cases Passed " << endl;
}

// Integration Tests
void test_deposit_then_withdraw() {
    BankAccount account(100.0);
    account.deposit(50.0);
    account.withdraw(30.0);
    assert(account.check_balance() == 120.0);
}

void test_withdraw_then_deposit() {
    BankAccount account(100.0);
    account.withdraw(30.0);
    account.deposit(50.0);
    assert(account.check_balance() == 120.0);
}

void integeration_test_message(){
    cout << "All Integration Test Cases Passed " << endl;
}

// System Test
void test_system_flow() {
    BankAccount account(0.0);
    account.deposit(100.0);
    assert(account.check_balance() == 100.0);

    account.withdraw(40.0);
    assert(account.check_balance() == 60.0);

    account.deposit(50.0);
    assert(account.check_balance() == 110.0);
    cout << "System flow test passed successfully!" << endl;
}

// White-Box Testing
//Here I am using Control Flow Testing technique to ensure all the branches in the code 
//are executed at least once. For ex testing the withdraw method to check valid and invalid paths 
void test_withdraw_control_flow() {
    BankAccount account(100.0);

    // Valid withdrawal
    account.withdraw(50.0);
    assert(account.check_balance() == 50.0);

    // Invalid withdrawal: insufficient funds
    try {
        account.withdraw(200.0);
        assert(false); // Should not reach here
    } catch (runtime_error &e) {
        assert(true); // Exception thrown as expected
    }

    // Invalid withdrawal: negative amount
    try {
        account.withdraw(-10.0);
        assert(false); // Should not reach here
    } catch (invalid_argument &e) {
        assert(true); // Exception thrown as expected
    }

    cout << "White Box Test completed";
    cout << "(Withdraw Control Flow test passed) " << endl; 
}

// Main Function
int main() {
    test_deposit();
    test_withdraw();
    test_check_balance();
    unit_test_message();
    test_deposit_then_withdraw();
    test_withdraw_then_deposit();
    integeration_test_message();
    test_system_flow();
    test_withdraw_control_flow();

    cout << "" << endl; 
    cout << "All tests passed successfully yayyyyyyy!" << endl;
    return 0;
}
