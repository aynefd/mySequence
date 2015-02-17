//
//  sequence.cpp
//  sequence
//
//  Created by Ayne Delgado on 1/10/15.
//  Copyright (c) 2015 Ayne Delgado. All rights reserved.
//

#include <stdio.h>
#include "sequence.h"
#include <cassert>
using namespace main_savitch_4;

//sequence::sequence()//default constructor
//{
//	capacity = DEFAULT_CAPACITY;
//	data = new value_type[capacity];
//	used = EMPTY;
//
//}
sequence::sequence(int initial_capacity)//paramaterized constructor
{
	capacity = initial_capacity;
	data = new value_type[capacity];
	used = EMPTY;
}
sequence::sequence(const sequence& source)//coppy constructor
{
	capacity = source.capacity;
	used = source.used;
	current_index = source.current_index;
	data = new value_type[capacity];
	for (int i = EMPTY; i<used; i++)
	{
		this->data[i] = source.data[i];
	}

}
sequence::~sequence() //default constructor
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}
void sequence::resize(int new_capacity)
{
	
	
		value_type* bigger = new value_type[new_capacity];
		for (int i = EMPTY; i < used; i++)
		{
			bigger[i] = data[i];
		}
		delete[] data;
		data = bigger;
		capacity = new_capacity;
	



}
void sequence::start()
{
	if (used == EMPTY)//if the sequence is empty...
		current_index = NO_CURRENT;
	else
		current_index = EMPTY;

}
void sequence::advance()
{
	assert(is_item() == true);
	
		if (current_index + MOVE >= capacity)
			current_index = NO_CURRENT;
		else
			current_index++;
	



}
void sequence::insert(const value_type& entry)
{

	if (used == EMPTY)
	{
		data[used] = entry;
		current_index = EMPTY;
	}

	else if (used >= capacity)
	{

		resize(capacity*GROW);
		for (int i = used; i>current_index; --i)
		{
			data[i] = data[i - MOVE];
		}
		data[current_index] = entry;

	}
	else
	{
		if (this->is_item() == false)
			current_index = EMPTY;
		for (int i = used; i>current_index; --i)
		{
			data[i] = data[i - MOVE];
		}
		data[current_index] = entry;

	}
	used++;


}
void sequence::attach(const value_type& entry)
{

	if (used == EMPTY)
		data[used] = entry;
	else if (used >= capacity)
	{
		resize(capacity*GROW);
		for (int i = used; i>current_index + MOVE; i--)
		{
			data[i] = data[i - MOVE];
		}
		data[current_index + MOVE] = entry;
		current_index++;

	}
	else if (this->is_item() == false)
	{
		data[used] = entry;
		current_index = used;
	}

	else
	{
	
		for (int i = used; i>current_index + MOVE; i--)
		{
			data[i] = data[i - MOVE];
		}
		data[current_index + MOVE] = entry;
		current_index++;

	}
	++used;

}
void sequence::remove_current()
{
	//check if there's a current item
	assert(is_item() == true);
	//if current_index==used-1 (last item)
	if (current_index == (used - MOVE))
	{
		--used;
		value_type* smaller = new value_type[capacity];
		for (int i = EMPTY; i < used; i++)
		{
			smaller[i] = data[i];
		}
		delete[] data;
		data = smaller;
		current_index = NO_CURRENT;

	}
	//else move everything up one using for loop
	else
	{
		for (int i = current_index; i<used - MOVE; i++)
		{
			data[i] = data[i + MOVE];
		}
		used--;
	}




}
void sequence::operator=(const sequence& source)
{
	//check for self-assignment
	if (this == &source)
		return;
	else
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
		capacity = source.capacity;
		used = source.used;
		current_index = source.current_index;
		data = new value_type[capacity];
		for (int i = EMPTY; i<used; i++)
		{
			this->data[i] = source.data[i];
		}


	}
}

bool sequence::is_item() const
{
	if (current_index<EMPTY || current_index >= used)
		return false;
	else
		return true;
}
value_type sequence::current()const
{

	if (this->is_item() == true)
	{
		return data[current_index];
	}
	else
		return NO_CURRENT;
}
int sequence::size() const
{
	return used;
}












