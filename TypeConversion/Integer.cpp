#include "Integer.h"
#include <iostream>
Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) {
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj) {
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

Integer& Integer::operator=(const Integer& obj)
{
	std::cout<<"Integer::operator=(const Integer& obj)"<<std::endl;
	if(this == &obj)
	{
		// self assignment
		return *this;
	}

	delete m_pInt;
	m_pInt = new int(*obj.m_pInt);
	return *this;
}

Integer& Integer::operator=(Integer&& obj)
{
	std::cout << "Integer::operator=(Integer&& obj)"<<std::endl;
	if(this == &obj)
	{
		return *this;
	}
	
	delete m_pInt;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;

	return *this;
}

int Integer::GetValue() const {
	return *m_pInt;
}

void Integer::SetValue(int value) {
	*m_pInt = value;
}

Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer Integer::operator+(const Integer& rhs) const 
{
	Integer temp;
	*temp.m_pInt = *(this->m_pInt) + *rhs.m_pInt;
	return temp;
}

Integer& Integer::operator++()
{
	++(*m_pInt);
	return *this;
}

Integer Integer::operator++(int)
{
	Integer temp(*this);
	(*m_pInt)++;
	return temp;
}

bool Integer::operator==(const Integer& rhs) const
{
	return *(this->m_pInt) == *(rhs.m_pInt);
}

Integer::operator int() const
{
	std::cout << "Integer::operator int() "<< std::endl;
	return *m_pInt;
}




