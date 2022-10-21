// cst116-Proj1-wilson-bugged.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Jacob Wilson, cst116, Project 1, Bugged, jacob.wilson@oit.edu

#include <iostream>
#include <iomanip>

using namespace std;

main()
{
	string student1_name;
	string student2_name;
	string student3_name;
	string student4_name;

	float student1_income = 0.0;
	float student2_income = 0.0;
	float student3_income = 0.0;
	float student4_income = 0.0;

	float student1_gpa = 0.0;
	float student2_gpa = 0.0;
	float student3_gpa = 0.0;
	float student4_gpa = 0.0;

	{
		cout << "What is your first name: ";
		cin >> student1_name;

		cout << "What is your income to the nearest cent: ";
		cin >> student1_income;

		cout << "What is your gpa  decimal places: ";
		cin >> student1_gpa;
	}
	{
		cout << "What is your first name: ";
		cin >> student2_name;

		cout << "What is your income to the nearest cent: ";
		cin >> student2_income;

		cout << "What is your gpa  decimal places: ";
		cin >> student2_gpa;
	}
	{
		cout << "What is your first name: ";
		cin >> student3_name;

		cout << "What is your income to the nearest cent: ";
		cin >> student3_income;

		cout << "What is your gpa  decimal places: ";
		cin >> student3_gpa;
	}
	{
		cout << "What is your first name: ";
		cin >> student4_name;

		cout << "What is your income to the nearest cent: ";
		cin >> student4_income;

		cout << "What is your gpa  decimal places: ";
		cin >> student4_gpa;
	}
	{
		cout << "\nStudent #" << setw(15) << "Name" << setw(5) << "Income" << setw(15) << "GPA\n";

		cout << "student 1" << setw(15) << student1_name << setw(15) << setprecision(2) << fixed << student1_income << setw(15) << setprecision(2) << fixed << student1_gpa << endl;

		cout << "student 2" << setw(15) << student2_name << setw(15) << setprecision(2) << fixed << student2_income << setw(15) << setprecision(2) << fixed << student2_gpa << endl;

		cout << "student 3" << setw(15) << student3_name << setw(15) << setprecision(2) << fixed << student3_income << setw(15) << setprecision(2) << fixed << student3_gpa << endl;

		cout << "student 4" << setw(15) << student4_name << setw(15) << setprecision(2) << fixed << student4_income << setw(15) << setprecision(2) << fixed << student4_gpa << endl << endl;
	}
	{
		string student5_name;
		string student6_name;
		string student7_name;
		string student8_name;

		float student5_income = 0.0;
		float student6_income = 0.0;
		float student7_income = 0.0;
		float student8_income = 0.0;

		float student5_age = 0.0;
		float student6_age = 0.0;
		float student7_age = 0.0;
		float student8_age = 0.0;

		{
			cout << "What is your first name: ";
			cin >> student5_name;

			cout << "What is your income to the nearest cent: ";
			cin >> student5_income;

			cout << "What is your age decimal places: ";
			cin >> student5_age;
		}
		{
			cout << "What is your first name: ";
			cin >> student6_name;

			cout << "What is your income to the nearest cent: ";
			cin >> student6_income;

			cout << "What is your age  decimal places: ";
			cin >> student6_age;
		}
		{
			cout << "What is your first name: ";
			cin >> student7_name;

			cout << "What is your income to the nearest cent: ";
			cin >> student7_income;

			cout << "What is your age  decimal places: ";
			cin >> student7_age;
		}
		{
			cout << "What is your first name: ";
			cin >> student8_name;

			cout << "What is your income to the nearest cent: ";
			cin >> student8_income;

			cout << "What is your age  decimal places: ";
			cin >> student8_age;
		}
		{
			cout.width(15);
			cout << "\nStudent #";
			cout.width(15);
			cout << "Name";
			cout.width(15);
			cout << "Income";
			cout.width(15);
			cout << "age" << endl;

			cout << "student 5";
			cout.width(15);
			cout << student5_name;
			cout.width(15);
			cout << student5_income;
			cout.width(15);
			cout << student5_age << endl;

			cout << "student 6";
			cout.width(15);
			cout << student6_name;
			cout.width(15);
			cout << student6_income;
			cout.width(15);
			cout << student6_age << endl;

			cout << "student 7";
			cout.width(15);
			cout << student7_name;
			cout.width(15);
			cout << student7_income;
			cout.width(15);
			cout << student7_age << endl;

			cout << "student 8";
			cout.width(15);
			cout << student8_name;
			cout.width(15);
			cout << student8_income;
			cout.width(15);
			cout << student8_age << endl;
		}
		return 0;
	}
}