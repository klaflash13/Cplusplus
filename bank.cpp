#include "Bank.h"
#include <isotream>
#include <iomanip>
using namespace std;

//constructor default
BankCalc::BankCalc() {
	initialDeposit = 0.00;
	monthlyDeposit = 0.00;
	percentInterest = 0.00;
	numberYears = 0;
}

void BankCalc::setInitialDeposit(double t_initialDeposit) {
	initialDeposit = t_initialDeposit;
}
void BankCalc::setMonthlyDeposit(double t_monthlyDeposit) {
	monthlyDeposit = t_monthlyDeposit;
}
void BankCalc::setPercentInterest(double t_percentInterest) {
	percentInterest = t_percentInterest;
}
void BankCalc::setNumberYears(int t_numberYears) {
	numberYears = t_numberYears;
}
double BankCalc::getInitialDeposit() {
	return initialDeposit;
}
double BankCalc::getMonthlyDeposit() {
	return monthlyDeposit;
}
double BankCalc::getPercentInterest() {
	return percentInterest;
}
int BankCalc::getNumberYears() {
	return numberYears;
}
//calculat monthly balance: include months, interest
double BankCalc::monthlyBalance(int t_months, double t_monthDeposit) {
	double balAmount = getInitialDeposit();
	for (int i = 0; i < t_months; i++) {
		balAmount = balAmount + t_monthDeposit;
		balAmount = balAmount + ((balAmount * getPercentInterest() / 100) /
			12);
	}
	return balAmount;
}
//calculate monthly interest: single month interest only
double BankCalc::monthlyInterest(int t_months, double t_monthDeposit) {
	double intAmount;
	double monthlyInterestRate = (getPercentInterest() / 100) / 12;
	intAmount = (monthlyBalance(t_months - 1, t_monthDeposit) + t_monthDeposit
		) * monthlyInterestRate;
	return intAmount;
}
//calculate annual balance: running total
double BankCalc::annualBalance(int t_numYears, double t_depositAmount) {
	int numMonths;
	double annualBal = 0.00;
	numMonths = t_numYears * 12;
	for (int i = 0; i < t_numYears; i++) {
		annualBal = monthlyBalance(numMonths, t_depositAmount);
	}
	return annualBal;
}
//Annual intrest calulation
double BankCalc::annualInterest(int t_numYears, double t_depositAmount) {
	int numMonths;
	double annualInt = 0.00;
	double priorYears = 0.00;
	numMonths = t_numYears * 12;
	for (int i = 0; i < numMonths; i++) {
		annualInt = annualInt + monthlyInterest(i + 1, t_depositAmount);
	}
	for (int j = 0; j < numMonths - 12; j++) {
		priorYears = priorYears - monthlyInterest(j + 1, t_depositAmount);
	}
	annualInt = annualInt + priorYears;
	return annualInt;
}
//set display screen
void BankCalc::showReport(double t_monthlyDep) {
	cout << " Balance and Interest Without Additional Monthly Deposits " << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << " Year " << " Year End Balance " << " Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << setprecision(2) << fixed << endl; //rounds values
	for (int i = 0; i < getNumberYears(); i++) {
		cout << " " << i + 1 << " " << annualBalance(i + 1,
			t_monthlyDep) << " " << annualInterest(i + 1,
				t_monthlyDep) << endl;
	}
	return;
}