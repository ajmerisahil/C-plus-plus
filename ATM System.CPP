/*
Project Name :- ATM System
Developed By :- Sahil Ajmeri
For          :- Brain TechLabs
Technology   :- Turbo C++
Version      :- 1.0
Date         :- 29-April-2021
*/

// Header files
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>


class Account
{
	private:
		long total_balance;
	public:
		long view_ac_balance();
		long get_balance();

		void set_db_balance(long);
		void set_cr_balance(long);

		long withdraw();
		long deposit();

	Account()
	{
		total_balance=10000;
	}
};

// Functions Defined of the Account Class
long Account::view_ac_balance()
{ 	return total_balance; 	}

long Account::get_balance()
{  	return total_balance;	}

void Account::set_db_balance(long amt)
{
	total_balance = total_balance-amt;
	cout<<"\n"<<amt<<" is successfully debited from your account";
	cout<<"\nYour Balance is "<<get_balance();
}

void Account::set_cr_balance(long amt)
{
	total_balance = total_balance+amt;
	cout<<"\n"<<amt<<" is successfully credited to your account";
	cout<<"\nYour Balance is "<<get_balance();
}

long Account::withdraw()
{
	long withdrawal_amt = 0;
	cout<<"\n\nEnter the Amount you want to Withdraw : ";
	cin>>withdrawal_amt;
	return withdrawal_amt;
}

long Account::deposit()
{
	long deposit_amt = 0;
	cout<<"\n\nEnter the Amount you want to Deposit : ";
	cin>>deposit_amt;
	return deposit_amt;
}

// To show the Menu
void menu()
{

	cout<<"\n\n|----------------------------------------------------------------------------|\n";
		cout<<"\t\t\t   Welcome to the ATM \n";
	cout<<"|----------------------------------------------------------------------------|\n";

		cout<<"\n\t\t  Choose the following options to Transact \n\n";

	cout<<"|////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~////////////////|\n";
		cout<<"|\n";
		cout<<"|\n";

		cout<<"|\t1. View Balance \n";
		cout<<"|\t2. Debit Amount from the Balance \n";
		cout<<"|\t3. Credit Amount in the existing Balance \n";

		cout<<"|\t0. Exit \n";

		cout<<"|\n";
		cout<<"|\n";
	cout<<"|////////////////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~////////////////|\n\n\n";



}

void main()
{
	// To clear the screen
	clrscr();

	int choice=0;
	Account ac_holder_1;

	do
	{
		menu();

		cout<<"Enter Your Choice :-   ";
		cin>>choice;

		switch(choice)
		{
			// Shows The Balance
			case 1:
				clrscr();
				cout<<"\n\t\t |---------------------------------------|";
				cout<<"\n\t\t\tYour total balance is "<<ac_holder_1.view_ac_balance();
				cout<<"\n\t\t |---------------------------------------|";
				cout<<endl;
				break;

			//Withdraws the amount from the existing Balance
			case 2:
				clrscr();
				long avail_balance = ac_holder_1.get_balance();

				if(avail_balance!=0)
				{
					long amt_to_withdraw = ac_holder_1.withdraw();

						if( amt_to_withdraw > avail_balance)
						{
							cout<<"\n\nYou don't have sufficient balance !! \n";
						}
						else
						{
							cout<<"\n\nSelect Types of Notes\n";

								cout<<"\nA.  2000  = ";
								int two_thousand = 0;
								cin>>two_thousand;

								cout<<"\nB.  500   = ";
								int five_hundred = 0;
								cin>>five_hundred;

								cout<<"\nC.  100   = ";
								int one_hundred = 0;
								cin>>one_hundred;

							long sum_of_withdraw = ( (2000*two_thousand)+(500*five_hundred)+(100*one_hundred)  );
							cout<<"\n\nTotal Amount to be withdrawn is "<<sum_of_withdraw;

							if(amt_to_withdraw==sum_of_withdraw)
							{
								ac_holder_1.set_db_balance(amt_to_withdraw);
							}
							else
							{
								cout<<"\nThe Total of Notes you entered Doesn't Match !!\n";
							}

						}
				}
				else
				{
					cout<<"\nYour Account doesn't have Balance";
				}

				break;


			//Deposit the amount to the existing Balance
			case 3:
				clrscr();

					long amt_to_deposit = ac_holder_1.deposit();

						cout<<"\n\nSelect Types of Notes\n";

							cout<<"\nA.  2000  = ";
							int two_thousand = 0;
							cin>>two_thousand;

							cout<<"\nB.  500   = ";
							int five_hundred = 0;
							cin>>five_hundred;

							cout<<"\nC.  100   = ";
							int one_hundred = 0;
							cin>>one_hundred;

					 long sum_of_deposit = ( (2000*two_thousand)+(500*five_hundred)+(100*one_hundred)  );
					 cout<<"\n\nTotal Amount to be Deposited is "<<sum_of_deposit;

						if(amt_to_deposit==sum_of_deposit)
						{
							ac_holder_1.set_cr_balance(amt_to_deposit);
						}
						else
						{
							cout<<"\nThe Total of Notes you entered Doesn't Match !!\n";
						}

				break;

			// End point of the Transaction
			case 0:
				cout<<"\n\t\t\t Thank You";
				exit(0);

			// IF user is entering wrong choice
			default:
				clrscr();
				cout<<"\n\nPlease enter an valid choice !!";
		}

	}while(choice!=0);

	// to await the screen exits after key-pressing
	getch();
}