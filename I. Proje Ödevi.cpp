/****************************************************************************
**								 SAKARYA ÜNİVERSİTESİ
**			           BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**							BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**							  PROGRAMLAMAYA GİRİŞİ DERSİ
**
**								ÖDEV NUMARASI:I. PROJE ÖDEVİ
**								ÖĞRENCİ ADI:SUDE ÖZKANOĞLU
**								ÖĞRENCİ NUMARASI:G201210034
**								DERS GRUBU:II. ÖĞRETİM PROGRAMLAMAYA GİRİŞ
****************************************************************************/

#include <windows.h>
#include <fstream>								//For fileing
#include <iostream>
#include <cstring>				
#include <conio.h>								//For input and output
#include <iomanip>								//For setw()
#include <string>								

using namespace std;

//Knowledges in the product.txt file
int choice_zero, i = 1;
string product_code;
string product_name;
string producer;
int lead_time;
string production_date;
float price;																		//For generally customer
float price_special;																//For special customer
string VAT_rate;
int stock_quantity;

//Knowledges in the current.txt file
int choice_first;
string company_number_first;
string company_name;
string company_phone_number;
string company_representative;
string customer_catagorize;															 //Generally and special customer
string address;

//Knowledges in the order.txt file
int choice_second, k = 1;
string company_number;
string order_date;
float order_price;
string receiver;
string answer_2 = "yes";

//Knowledges in the order_list.txt file
int choice_third, p = 1;
string products_code;
int quantity_of_products;

//Global variables
int a = 1;
int choice;
string answer = "yes";
string decision = "yes";
int specialConditionNum;

//Functions for printing out and inputs
void print()
{
	cout << setw(8) << "Product Code:" << setw(10) << product_code << endl;
	cout << setw(8) << "Product Name:" << setw(10) << product_name << endl;
	cout << setw(8) << "Producer:" << setw(10) << producer << endl;
	cout << setw(8) << "Lead Time:" << setw(10) << lead_time << endl;
	cout << setw(8) << "Production Date:" << setw(10) << production_date << endl;
	cout << setw(8) << "Price:" << setw(10) << price << endl;
	cout << setw(8) << "Special Price:" << setw(10) << price_special << endl;
	cout << setw(8) << "VAT Rate:" << setw(10) << VAT_rate << endl;
	cout << setw(8) << "Stock Quantity:" << setw(10) << stock_quantity << endl;
}

void print_2()
{
	cout << "Product Code:" << endl;
	cin >> product_code;

	cout << "Product Name(Just One Word):" << endl;
	cin >> product_name;

	cout << "Producer(Just One Word):" << endl;
	cin >> producer;

	cout << "Lead Time:" << endl;
	cin >> lead_time;

	cout << "Production Date(Just Year):" << endl;
	cin >> production_date;

	cout << "Price:" << endl;
	cin >> price;

	cout << "Special Price:" << endl;
	cin >> price_special;

	cout << "VAT Rate:" << endl;
	cin >> VAT_rate;

	cout << "Stock Quantity:" << endl;
	cin >> stock_quantity;
}
void print_3()
{
	cout << setw(8) << "Company Number:" << setw(10) << company_number_first << endl;
	cout << setw(8) << "Company Name:" << setw(10) << company_name << endl;
	cout << setw(8) << "Company Phone Number:" << setw(10) << company_phone_number << endl;
	cout << setw(8) << "Company Representative:" << setw(10) << company_representative << endl;
	cout << setw(8) << "Customer Catagorize:" << setw(10) << customer_catagorize << endl;
	cout << setw(8) << "Address:" << setw(10) << address << endl;
}
void print_4()
{
	cout << "Company Number:" << endl;
	cin >> company_number_first;

	cout << "Company Name(Just One Word):" << endl;
	cin >> company_name;

	cout << "Company Phone Number:" << endl;
	cin >> company_phone_number;

	cout << "Company Representative(Just One Word):" << endl;
	cin >> company_representative;

	cout << "Customer Catagorize(Just One Word):" << endl;
	cin >> customer_catagorize;

	cout << "Address(Just City):" << endl;
	cin >> address;
}
void print_5()
{
	int productNumCondition = 5;
	ifstream DosyaOku34("product.txt");
	while (productNumCondition != 0)
	{
		if (productNumCondition == 0)
		{
			break;
		}
		else
		{
			cout << "Product Code:" << endl;
			getline(cin >> ws, products_code);
			while (!DosyaOku34.eof())
			{
				DosyaOku34 >> product_code >> product_name >> producer >> lead_time >> production_date >> price >> price_special >> VAT_rate >> stock_quantity;

				if (DosyaOku34.eof())
				{
					break;
				}
				if (product_code == products_code)
				{
					productNumCondition = 0;
					break;
				}
			}
			if (DosyaOku34.eof() && productNumCondition != 0)
			{
				cout << "Entering that is False for Two Times" << endl;
				exit(0);
			}
		}
	}
	DosyaOku34.close();
	cout << "Quantity of Product:" << endl;
	cin >> quantity_of_products;
}

void print_6(int specialConditionNum)
{
	cout << setw(8) << "Company Number:" << setw(10) << company_number << endl;
	cout << setw(8) << "Receiver:" << setw(10) << receiver << endl;
	cout << setw(8) << "Product Code:" << setw(10) << products_code << endl;
	cout << setw(8) << "Quantity of Products:" << setw(10) << quantity_of_products << endl;

	if (specialConditionNum == 1)
	{
		cout << "Special Price:" << price_special << endl;
		cout << "Total Price:" << price_special * quantity_of_products << endl;
	}
	else
	{
		cout << "Price:" << price << endl;
		cout << "Total Price:" << price * quantity_of_products << endl;
	}

	cout << "VAT Rate:" << VAT_rate << endl;
	cout << "Address:" << address << endl;
}

void print_7()
{
	int companyNumCondition = 6;
	ifstream DosyaOkuCurrent11("current.txt");
	while(companyNumCondition !=0)
	{
		if (companyNumCondition == 0)
		{
			break;
		}
		else
		{
			cout << "Company Number:" << endl;
			cin >> company_number;
			while (!DosyaOkuCurrent11.eof())
			{
				DosyaOkuCurrent11 >> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;
				if (DosyaOkuCurrent11.eof())
				{
					break;
				}
				if (company_number == company_number_first)
				{
					companyNumCondition = 0;
					break;
				}
				if (DosyaOkuCurrent11.eof() && companyNumCondition != 0)
				{
					cout << "Entering that is False for Two Times" << endl;
					exit(0);
				}
			}
		}
	}
	DosyaOkuCurrent11.close();

	cout << "Receiver(Just One Word):" << endl;
	cin >> receiver;

	cout << "Quantity of Products:" << endl;
	cin >> quantity_of_products;
}

int main()
{
	//Loop is that what we want to do 
	do
	{
		cout << "What do you want do?" << endl;
		cout << "1-Product Related Transactions" << endl;
		cout << "2-Files of Customers Transactions" << endl;
		cout << "3-Order Transactions" << endl;
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3);

	//Loop is that for choice 1
	if (choice == 1)
	{
		do
		{
			cout << "What Do You Want Do?" << endl;
			cout << "1-Add New Product" << endl;
			cout << "2-Search Product" << endl;
			cout << "3-List the Products" << endl;
			cout << "4-Correction the Product" << endl;
			cout << "5-Delete the Product" << endl;
			cin >> choice_zero;
		} while (choice_zero != 1 && choice_zero != 2 && choice_zero != 3 && choice_zero != 4 && choice_zero != 5);

		//Loop is that for add new product
		if (choice_zero == 1)
		{
			ofstream DosyaYaz;
			DosyaYaz.open("product.txt", ios::app);
			do
			{
				print_2();
				DosyaYaz << product_code << " " << product_name << " " << producer << " " << lead_time << " " << production_date << " " << price << " " << price_special << " " << VAT_rate << " " << stock_quantity << " " << endl;

				cout << "Do You Want to Add Other Product?" << endl;
				cin >> answer;
			} while (answer != "no");
			DosyaYaz.close();

			cout << "New Product is Added..." << endl;

			_getch();
			system("cls");
			return main();
		}

		//Loop is that for search product
		if (choice_zero == 2)
		{
			string WantedProduct = "";
			cout << "Enter the Code of Product That You Want to Find,Please" << endl;
			cin >> WantedProduct;
			ifstream DosyaOku2("product.txt");
			while (!DosyaOku2.eof())
			{
				DosyaOku2 >> product_code >> product_name >> producer >> lead_time >> production_date >> price >> price_special >> VAT_rate >> stock_quantity;

				if (DosyaOku2.eof())
				{
					break;
				}
				if (WantedProduct == product_code)
				{
					cout << "\n Information of the Product Found\n";
					print();
				}
				if (WantedProduct != product_code && DosyaOku2.eof())
				{
					cout << "Product Code Did Not Match!" << endl;
				}
			}
			DosyaOku2.close();
			_getch();
			system("cls");
			return main();
		}

		//Loop is that for list the products
		if (choice_zero == 3)
		{
			int i = 1;
			ifstream DosyaOku3("product.txt");
			while (!DosyaOku3.eof())
			{
				DosyaOku3 >> product_code >> product_name >> producer >> lead_time >> production_date >> price >> price_special >> VAT_rate >> stock_quantity;
				if (DosyaOku3.eof())
				{
					break;
				}
				else
				{
					cout << "\n Products " << i << ". record \n";
					print();
					i++;
				}
			}
			DosyaOku3.close();
			_getch();
			system("cls");
			return main();
		}

		//Loop is that for correction product
		if (choice_zero == 4)
		{
			string WantedProduct;
			cout << "Enter the Code of Product That You Want to Correction" << endl;
			cin >> WantedProduct;
			ifstream DosyaOku4("product.txt");
			ofstream DosyaYaz4("product.tmp");
			while (!DosyaOku4.eof())
			{
				DosyaOku4 >> product_code >> product_name >> producer >> lead_time >> production_date >> price >> price_special >> VAT_rate >> stock_quantity;
				if (DosyaOku4.eof())
				{
					i = 5;
					break;
				}
				if (WantedProduct == product_code)
				{
					cout << "\n Record in the File \n";
					print();

					cout << "\n Enter the New Information Related to Product\n";
					print_2();

					DosyaYaz4 << product_code << " " << product_name << " " << producer << " " << lead_time << " " << production_date << " " << price << " " << price_special << " " << VAT_rate << " " << stock_quantity << "\n";
					cout << "Correction is Completed!" << endl;
				}
				else
				{
					if (i == 5)
					{
						break;
					}
					else
					{
						DosyaYaz4 << product_code << " " << product_name << " " << producer << " " << lead_time << " " << production_date << " " << price << " " << price_special << " " << VAT_rate << " " << stock_quantity << "\n";
						
						if (i != 5 && DosyaOku4.eof())
						{
							cout << "Product Code Did Not Match!" << endl;
						}
					}
				}
			}
			DosyaOku4.close();
			DosyaYaz4.close();
			remove("product.txt");
			rename("product.tmp", "product.txt");
			return 0;
		}

		//Loop is that delete the product
		if (choice_zero == 5)
		{
			string WantedProduct;
			cout << "Enter the Product Code That You Want to Delete" << endl;
			cin >> WantedProduct;
			ifstream DosyaOku5("product.txt");
			ofstream DosyaYaz5("product.tmp");
			while (!DosyaOku5.eof())
			{
				DosyaOku5 >> product_code >> product_name >> producer >> lead_time >> production_date >> price >> price_special >> VAT_rate >> stock_quantity;

				if (WantedProduct == product_code)
				{
					cout << "\n Record in the File \n";
					print();
					cout << "Product is Deleted!" << endl;
					i = 3;
					break;
				}
				else
				{
					if (i == 3)
					{
						break;
					}
					else
					{
						DosyaYaz5 << product_code << " " << product_name << " " << producer << " " << lead_time << " " << production_date << " " << price << " " << price_special << " " << VAT_rate << " " << stock_quantity << "\n";
						if (i != 3 && DosyaOku5.eof())
						{
							cout << "Product Code Did Not Match!" << endl;
						}
					}
				}
			}
			DosyaYaz5.close();
			DosyaOku5.close();
			remove("product.txt");
			rename("product.tmp", "product.txt");
			return 0;
		}
	}

	//Loop is that for choice 2
	if (choice == 2)
	{
		//Menu is that what we want to do about customer
		do
		{
			cout << "What do you want do?" << endl;
			cout << "1-Add New Customer" << endl;
			cout << "2-Search Customer" << endl;
			cout << "3-Correction the Information of Customer" << endl;
			cout << "4-Delete the Customer" << endl;
			cin >> choice_first;
		} while (choice_first != 1 && choice_first != 2 && choice_first != 3 && choice_first != 4);

		//Loop is that add new customer
		if (choice_first == 1)
		{
			ofstream DosyaYaz6;
			DosyaYaz6.open("current.txt", ios::app);

			do
			{
				print_4();
				DosyaYaz6 << company_number_first << " " << company_name << " " << company_phone_number << " " << company_representative << " " << customer_catagorize << " " << address << " " << endl;

				cout << "Do You Want to Add Other Customer?" << endl;
				cin >> answer;
			} while (answer != "no");

			DosyaYaz6.close();
			cout << "New Customer is  Added..." << endl;
			_getch();
			system("cls");
			return main();
		}

		//Loop is that search customer
		if (choice_first == 2)
		{
			string WantedCustomer = "";
			cout << "Enter the Company Number That You Want to Find,Please" << endl;
			cin >> WantedCustomer;
			ifstream DosyaOku7("current.txt");
			while (!DosyaOku7.eof())
			{
				DosyaOku7 >> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;

				if (DosyaOku7.eof())
				{
					break;
				}
				if (WantedCustomer == company_number_first)
				{
					cout << "\n Information of the Customer Found\n";
					print_3();
				}
				if (WantedCustomer != company_number_first && DosyaOku7.eof())
				{
					cout << "Company Number Did Not Match!" << endl;
				}
			}
			DosyaOku7.close();
			_getch();
			system("cls");
			return main();
		}

		//Loop is that correction the customer
		if (choice_first == 3)
		{
			string WantedCustomer;
			cout << "Enter the Company Number That You Want to Correction" << endl;
			cin >> WantedCustomer;
			ifstream DosyaOku8("current.txt");
			ofstream DosyaYaz8("current.tmp");
			while (!DosyaOku8.eof())
			{
				DosyaOku8 >> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;

				if (DosyaOku8.eof())
				{
					i = 7;
					break;
				}
				if (WantedCustomer == company_number_first)
				{
					cout << "\n Record in the File \n";
					print_3();

					cout << "\n Enter the New Information Related to Customer\n";
					print_4();

					DosyaYaz8 << company_number_first << " " << company_name << " " << company_phone_number << " " << company_representative << " " << customer_catagorize << " " << address << " " << endl;

					cout << "Correction is Completed!" << endl;
				}
				else
				{
					if (i == 7)
					{
						break;
					}
					else
					{
						DosyaYaz8 << company_number_first << " " << company_name << " " << company_phone_number << " " << company_representative << " " << customer_catagorize << " " << address << " " << endl;
						if (i != 7 && DosyaOku8.eof())
						{
							cout << "Company Number Did Not Match!" << endl;
						}
					}
				}
			}
			DosyaOku8.close();
			DosyaYaz8.close();
			remove("current.txt");
			rename("current.tmp", "current.txt");
			return 0;
		}
	}

	//Loop is that delete the customer
	if (choice_first == 4)
	{
		string WantedCustomer;
		cout << "Enter the Company Number that You Want to Delete" << endl;
		cin >> WantedCustomer;
		ifstream DosyaOku9("current.txt");
		ofstream DosyaYaz9("current.tmp");
		while (!DosyaOku9.eof())
		{
			DosyaOku9 >> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;

			if (WantedCustomer == company_number_first)
			{
				cout << "\n Record in the File \n";
				print_3();
				cout << "Customer is Deleted!" << endl;
				i = 4;
				break;
			}
			else
			{
				if (i == 4)
				{
					break;
				}
				else
				{
					DosyaYaz9 << company_number_first << " " << company_name << " " << company_phone_number << " " << company_representative << " " << customer_catagorize << " " << address << " " << endl;
					if (i != 4 && DosyaOku9.eof())
					{
						cout << "Company Number Did Not Match!" << endl;
					}
				}
			}
		}
		DosyaYaz9.close();
		DosyaOku9.close();
		remove("current.txt");
		rename("current.tmp", "current.txt");
		return 0;
	}

	//Loop is that choice 3 
	if (choice == 3)
	{
		//Menu is that what we want to do for order
		do
		{
			cout << "What Do You Want Do?" << endl;
			cout << "1-Create New Order" << endl;
			cout << "2-Search Order" << endl;
			cout << "3-Correction the Order" << endl;
			cout << "4-Delete the Order" << endl;
			cout << "5-Report the Order" << endl;
			cin >> choice_second;
		} while (choice_second != 1 && choice_second != 2 && choice_second != 3 && choice_second != 4 && choice_second != 5);

		//Loop is that create new order
		if (choice_second == 1)
		{
			int companyNumCondition = 7;
			string specialCondition;
			string name;

			cout << "Write the Product Name that You Want to Buy..." << endl;
			cin >> name;

			ifstream DosyaOku10("product.txt");
			ifstream DosyaOkuCurrent11("current.txt");
			while (!DosyaOku10.eof())
			{
				DosyaOku10 >> product_code >> product_name >> producer >> lead_time >> production_date >> price >> price_special >> VAT_rate >> stock_quantity;
				DosyaOkuCurrent11 >> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;
				
				if (name == product_name)
				{
					i = 3;
					break;
				}
			}

			if (i==3)
			{
				cout << "Founded Product:" << endl;
				cout << " " << product_name << endl;

				cout << "Do You Want to See Knowledges of Product?" << endl;
				cin >> answer_2;

				if (answer_2 == "yes")
				{
					print();
					DosyaOku10.close();
				}

				cout << "Do You Want to Add This Product to Your Order List ?" << endl;
				cin >> answer_2;

				if (answer_2 == "yes")
				{
					ofstream DosyaYaz40;
					DosyaYaz40.open("order_list.txt", ios::app);
					print_5();
					DosyaYaz40 << " " << products_code << " " << quantity_of_products << endl;
					DosyaYaz40.close();
					cout << "Product Added Your Order List!" << endl;
				}
				ofstream DosyaYaz10;
				DosyaYaz10.open("order.txt", ios::app);

				ifstream DosyaOkuCurrent11("current.txt");
				while (companyNumCondition != 0)
				{
					if (companyNumCondition == 0)
					{
						break;
					}
					else
					{
						cout << "Company Number:" << endl;
						cin >> company_number;
						while (!DosyaOkuCurrent11.eof())
						{
							DosyaOkuCurrent11 >> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;
							if (DosyaOkuCurrent11.eof())
							{
								break;
							}
							if (company_number == company_number_first)
							{
								companyNumCondition = 0;
								break;
							}
							if (DosyaOkuCurrent11.eof() && companyNumCondition != 0)
							{
								cout << "Entering that is False for Two Times" << endl;
								exit(0);
							}
						}
					}
				} 
				DosyaOkuCurrent11.close();

				cout << "Receiver ( Just One Word):" << endl;
				cin >> receiver;

				ifstream DosyaOku12("product.txt");
				DosyaOku12 >> product_code >> product_name >> producer >> lead_time >> production_date >> price >> price_special >> VAT_rate >> stock_quantity;

				cout << "Are You a Special Customer?" << endl;
				cin >> specialCondition;

				if (specialCondition == "yes")
				{
					specialConditionNum = 1;
				}
				else
				{
					specialConditionNum = 0;
				}

				DosyaYaz10 << " " << company_number << " " << receiver << " " << price << " " << price_special << " " << VAT_rate << endl;
				DosyaYaz10.close();
				DosyaOku12.close();

				cout << "Knowledges is Added!" << endl;

				ifstream DosyaOku13("order.txt");
				DosyaOku13 >> company_number >> receiver >> price >> price_special >> VAT_rate;

				ifstream DosyaOku14("order_list.txt");
				DosyaOku14 >> products_code >> quantity_of_products;

				ifstream DosyaOku15("current.txt");
				DosyaOku15 >> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;

				print_6(specialConditionNum);

				DosyaOku13.close();
				DosyaOku14.close();
				DosyaOku15.close();

				cout << "Your Order is Completed!" << endl;
			}
			else
			{
				if (name != product_name && DosyaOku10.eof())
				{
					cout << "Product Name Did Not Match!" << endl;
				}
			}
			_getch();
			system("cls");
			return main();
		}

		//Loop is that search the order
		if (choice_second == 2)
		{
			string WantedOrder = "";
			cout << "Enter the Company Number for Searcing the Order" << endl;
			cin >> WantedOrder;
			ifstream DosyaOku16("order.txt");
			ifstream DosyaOku17("order_list.txt");
			ifstream DosyaOku30("current.txt");
			while (!DosyaOku16.eof())
			{
				DosyaOku16 >> company_number >> receiver >> price >> price_special >> VAT_rate;
				DosyaOku17 >> products_code >> quantity_of_products;
				DosyaOku30>> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;

				if (DosyaOku16.eof())
				{
					break;
				}
				if (WantedOrder == company_number)
				{
					cout << "\n Information of the Order Found\n";
					print_6(specialConditionNum);
				}
				if (WantedOrder != company_number && DosyaOku16.eof())
				{
					cout << "Company Number Did Not Found!" << endl;
				}
			}
			DosyaOku16.close();
			DosyaOku17.close();
			DosyaOku30.close();
			_getch();
			system("cls");
			return main();
		}

		//Loop is that correction the order
		if (choice_second == 3)
		{
			string WantedOrder;
			cout << "Enter the Company Number for Correcting the Knowledge of Order" << endl;
			cin >> WantedOrder;
			ifstream DosyaOku18("order.txt");
			ifstream DosyaOku19("order_list.txt");
			ifstream DosyaOku31("current.txt");
			ofstream DosyaYaz18("order.tmp");
			ofstream DosyaYaz19("order_list.tmp");
			while (!DosyaOku18.eof())
			{
				DosyaOku18 >> company_number >> receiver >> price >> price_special >> VAT_rate;
				DosyaOku19 >> products_code >> quantity_of_products;
				DosyaOku31>> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;

				if (DosyaOku18.eof())
				{
					i = 9;
					break;
				}
				if (WantedOrder == company_number)
				{
					cout << "\n Record in the File \n";
					print_6(specialConditionNum);

					cout << "\n Enter the New Information Related to Order\n";
					print_7();

					DosyaYaz18 << " " << company_number << " " << receiver << " " << price << " " << price_special << " " << VAT_rate << endl;
					DosyaYaz19 << " " << products_code << " " << quantity_of_products << endl;

				}
				else
				{
					if (i == 9)
					{
						break;
					}
					else
					{
						DosyaYaz18 << " " << company_number << " " << receiver << " " << price << " " << price_special << " " << VAT_rate << endl;
						DosyaYaz19 << " " << products_code << " " << quantity_of_products << endl;
						if (i != 9 && DosyaOku18.eof())
						{
							cout << "Company Number Did Not Match!" << endl;
						}
					}
				}
			}
			DosyaOku18.close();
			DosyaOku19.close();
			DosyaOku31.close();
			DosyaYaz18.close();
			DosyaYaz19.close();
			remove("order.txt");
			rename("order.tmp", "order.txt");
			remove("order_list.txt");
			rename("order_list.tmp", "order_list.txt");
			return 0;
		}

		//Loop is that delete the order
		if (choice_second == 4)
		{
			string WantedOrder;
			cout << "Enter the Company Number for Deleting Order" << endl;
			cin >> WantedOrder;
			ifstream DosyaOku20("order.txt");
			ifstream DosyaOku21("order_list.txt");
			ifstream DosyaOku32("current.txt");
			ofstream DosyaYaz20("order.tmp");
			ofstream DosyaYaz21("order_list.tmp");
			while (!DosyaOku20.eof())
			{
				DosyaOku20 >> company_number >> receiver >> price >> price_special >> VAT_rate;
				DosyaOku21 >> products_code >> quantity_of_products;
				DosyaOku32>> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;

				if (WantedOrder == company_number)
				{
					cout << "\n Record in the File \n";
					print_6(specialConditionNum);
					cout << "Order is Deleted!" << endl;
					i = 6;
					break;
				}
				else
				{
					if (i == 6)
					{
						break;
					}
					else
					{
						DosyaYaz20 << " " << company_number << " " << receiver << " " << price << " " << price_special << " " << VAT_rate << endl;
						DosyaYaz21 << " " << products_code << " " << quantity_of_products << endl;
						if (i != 6 && DosyaOku20.eof())
						{
							cout << "Company Number Did Not Match!" << endl;
						}
					}
				}
			}
			DosyaYaz20.close();
			DosyaYaz21.close();
			DosyaOku20.close();
			DosyaOku21.close();
			DosyaOku32.close();
			remove("order.txt");
			rename("order.tmp", "order.txt");
			remove("order_list.txt");
			rename("order_list.tmp", "order_list.txt");
			return 0;
		}

		//Loop is that report the order
		if (choice_second == 5)
		{
			string WantedOrder;
			cout << "Enter the Company Number for Reporting the Order" << endl;
			cin >> WantedOrder;

			ifstream DosyaOku22("order.txt");
			ifstream DosyaOku23("order_list.txt");
			ifstream DosyaOku33("current.txt");
			while (!DosyaOku22.eof())
			{
				DosyaOku22 >> company_number >> receiver >> price >> price_special >> VAT_rate;
				DosyaOku23 >> products_code >> quantity_of_products;
				DosyaOku33>> company_number_first >> company_name >> company_phone_number >> company_representative >> customer_catagorize >> address;

				if (DosyaOku22.eof())
				{
					break;
				}
				if (WantedOrder == company_number)
				{
					cout << "\n Order " << a << ". record \n";
					print_6(specialConditionNum);
					a++;
				}
				if (WantedOrder != company_number || DosyaOku22.eof())
				{
					cout << "Company Number Did Not Match!" << endl;
					break;
				}
			}
			DosyaOku22.close();
			DosyaOku23.close();
			DosyaOku33.close();
		}
	}
}

