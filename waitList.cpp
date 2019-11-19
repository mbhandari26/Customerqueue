

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#include "Customer.h"
#include "Heap.h"

//****************************************************************************************************

void getData(Heap<Customer> & waitList);
void printWaitList(Heap<Customer> & waitList);

//****************************************************************************************************

int main()
{
	Heap<Customer> waitList;
	getData(waitList);
	printWaitList(waitList);

	return 0;
}

//****************************************************************************************************

void getData(Heap<Customer> & waitList)
{
	Customer cust;
	ifstream inFile;
	inFile.open("overbooked.bin", ios::binary);

	while (inFile.read((char*) & cust, sizeof(cust)))
	{
		cust.priority = cust.mileage / 1000 + cust.years - cust.arrivalNum;
		waitList.insert(cust);
	}

	inFile.close();
}

//****************************************************************************************************

void printWaitList(Heap<Customer> & waitList)
{
	Customer cust;
	ofstream outFile("waitList.txt"); 
	outFile << "SAINT LOUIS LAMBERT AIRPORT" << endl;
	outFile <<  "\tAMERICAN AIRLINES" << endl;
	outFile << "\tFlight Number: 123" << endl;
	outFile << "\tDeparting to: Dallas-Fort Worth Airport" << endl;
	outFile << "\tScheduled: 9:17 PM " << " Nov-18-2019" << endl << endl;
	outFile << setw(35) << "Customer Waitlist" << endl;
	outFile << "=============================================================" 
			<< endl;
	outFile << left << setw(12) << "Priority" <<  left << setw(12) << "Last Name" 
			<< left << setw(12) << "First Name" << left << setw(14) 
			<< "Flier Years" << left << setw(12) << "Arrival No." <<  endl;
	outFile << "=============================================================" 
			<< endl;

	int i = 1;

	while (waitList.remove(cust))
	{
		outFile << "  " << right <<  setfill('0') << setw(2) << i 
				<< setfill('\0') << "         "	<< cust;
		i++;
	}
}

//****************************************************************************************************


