#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	
	string ic_no;
	int year;
	double annual_income;
	double exempt_amount;
	double installment;
	double tax_income;
	double tax_percent;
	double gross_tax;
	double tax;
	
	
	//Input
	
	cout << "Please enter the tax details: " << endl;
	
	cout << "IC NO: ";
	cin >> ic_no;
	
	cout << "Assessment Year: ";
	cin >> year;
	
	cout << "Total Annual Income   RM: ";
	cin >> annual_income;
	
	cout << "Total Exempted Amount RM: ";
	cin >> exempt_amount;
	
	cout << "Total Installment Tax Amount RM: ";
	cin >> installment;
	
	//Process
	
	tax_income = annual_income - exempt_amount;
	if (tax_income >= 0 and tax_income <= 5000){
		tax_percent = 0;
	}
	else{
		if (tax_income >= 5001 and tax_income <= 20000){
			tax_percent = 1;
		}
		else{
			if (tax_income >= 20001 and tax_income <= 35000){
				tax_percent = 3;
			}
			else{
				if (tax_income >= 35001 and tax_income <= 50000){
					tax_percent = 8;
				}
				else{
					if (tax_income >= 50001 and tax_income <= 70000){
						tax_percent = 14;
					}
					else{
						tax_percent = 21;
					}
				}
			}
		}
	}
	
	gross_tax = tax_income * static_cast<double>(tax_percent/100);
	tax = gross_tax - installment;
	
	//Output
	
	cout << "IC NO          : " << ic_no << endl;
	cout << "Assessment Year: " << year << endl << endl;
	
	cout << "Taxable Income" << setw(15) << "Tax (%)" << setw(15) << "Gross Tax" << setw(20) << "Installment" << setw(15) << "Tax" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	
	cout << setprecision(2) << fixed << showpoint;
	
	if (installment > tax){
		cout << setw(10) << tax_income << setw(15) << static_cast<int>(tax_percent) << setw(20) << gross_tax << setw(15) << installment << setw(20) << "(" << tax << ")";
	}
	else{
		cout << setw(10) << tax_income << setw(15) << static_cast<int>(tax_percent) << setw(20) << gross_tax << setw(15) << installment << setw(20) << tax;	
	}
	
	
	
	return 0;
}
