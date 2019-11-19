//****************************************************************************************************
//
//		File:					Customer.h
//		
//		Student:				Manish Bhandari
//
//		Assignment:	 			Program  # 11
//
//		Course Name:			Data Structures   II 
//
//		Course Number:			COSC 3100 - 01
//
//		Due:					Nov 17, 2019
//
//
//		This program uses a heap class to establish a priority queue of 
//		overbooked customers for an airline company.
//		
//****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

//****************************************************************************************************

struct Customer
{
	char fname[15];
	char lname[15];
	int mileage;
	int years;
	int arrivalNum;
	int priority;

	Customer();
	friend ostream & operator << (ostream & out, const Customer & data);
	bool operator == (const Customer & rhs) const;
	bool operator == (int val) const;
	bool operator != (const Customer & rhs) const;
	bool operator != (int val) const;
	bool operator < (const Customer & rhs) const;
	bool operator < (int val) const;
	bool operator > (const Customer & rhs) const;
	bool operator > (int val) const;
	bool operator <= (const Customer & rhs) const;
	bool operator <= (int val) const;
	bool operator >= (const Customer & rhs) const;
	bool operator >= (int val) const;
	Customer & operator = (int value);

};

Customer::Customer()
{
	priority = 0;

}

//*****************************************************************************************************

ostream & operator << (ostream & out, const Customer & data)
{
	out << left << setw(13) << data.lname
		<< left << setw(15) << data.fname
		<< left << setw(12) << data.years
		<< left << setw(5) <<  data.arrivalNum <<  endl;

	return out;
}
//*****************************************************************************************************

bool Customer::operator == (const Customer & rhs) const
{
	return (this->priority == rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator == (int val) const
{
	return (this->priority == val);
}

//*****************************************************************************************************

bool Customer::operator != (const Customer & rhs) const
{
	return (this->priority != rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator != (int val) const
{
	return (this->priority != val);
}

//*****************************************************************************************************

bool Customer::operator < (const Customer & rhs) const
{
	return (this->priority < rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator < (int val) const
{
	return (this->priority < val);
}

//*****************************************************************************************************

bool Customer::operator > (const Customer & rhs) const
{
	return (this->priority > rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator > (int val) const
{
	return (this->priority > val);
}

//*****************************************************************************************************

bool Customer::operator <= (const Customer & rhs) const
{
	return (this->priority <= rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator <= (int val) const
{
	return (this->priority <= val);
}

//*****************************************************************************************************

bool Customer::operator >= (const Customer & rhs) const
{
	return (this->priority >= rhs.priority);
}

//*****************************************************************************************************

bool Customer::operator >= (int val) const
{
	return (this->priority >= val);
}

//*****************************************************************************************************

Customer & Customer::operator = (int value)
{
	this->priority = value;
	return * this;

}

//*****************************************************************************************************

#endif