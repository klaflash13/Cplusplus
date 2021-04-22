#ifndef Project_Two_Header_File_BankCalc_H_
#define Project_Two_Header_File_BankCalc_H_
#pragma once
class BankCalc
{
Public:
	BankCalc(); // constructor default
	void setInitialDeposit(double t_initialDeposit);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setPercentInterest(double t_percentInterest);
	void setNumberYears(int t_numberYears);
	double getInitialDeposit();
	double getMonthlyDeposit();
	double getPercentInterest();
	int getNumberYears();

	//calculate monthly balance
	double monthlyBalance(int t_months, double t_monthDeposit);
	//calculate monthly interest
	double monthlyInterest(int t_months, double t_monthDeposit);
	//calculate annual balance
	double annualBalance(int t_numYears, double t_depositAmount);
	//calculate annual interest
	double annualInterest(int numYears, double t_depositAmount);
	//display data
	void showReport(double t_monthlyDep);

private:
	double initialDeposit;
	double monthlyDeposit;
	double percentInterest;
	int numberYears;
};
#endif 