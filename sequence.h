
//  sequence.h
//  sequence
//  Created by Ayne Delgado on 1/10/15.
//	Last modified: 1/11/2015
//  CS 2420
//	Project01
//-------------------------------------------------------------------------------------------------------------

//I Ayne Delgado have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.
//--------------------------------------------------------------------------------------------------------------

// FILE: sequence2.h
// CLASS PROVIDED: sequence (part of the namespace main_savitch_4)
// There is no implementation file provided for this class since it is
// an exercise from Chapter 4 of "Data Structures and Other Objects Using C++"
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   static const int DEFAULT_CAPACITY = _____
//     sequence::DEFAULT_CAPACITY is the initial capacity of a sequence that is
//     created by the default constructor.
//
// CONSTRUCTORS for the sequence class:
//   sequence(int initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
//   sequence(const sequence& source)
//     Postcondition: the sequence has made a deep copy of the source sequence.
//
//  DESTRUCTOR:
//	 ~sequence()
//		Poscondition: all dynamically allocated memory has been destroyed.
//
//	OPERATOR:
//	  void operator =(const sequence& source);
//	  Postondition: a deep copy of the source sequence replaces the current sequence.
//                  Unused dynamic memory is deallocated.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void resize(int new_capacity)
//     Postcondition: The sequence's current capacity is changed to the
//     new_capacity (but not less that the number of items already on the
//     list). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
//
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//	   else there is no current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   int size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//


#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H


namespace main_savitch_4
{
	typedef double value_type;

	class sequence
	{
	public:
		// TYPEDEFS and MEMBER CONSTANTS
		static const int EMPTY = 0;
		static const int GROW = 2;
		static const int NO_CURRENT = -1;
		static const int MOVE = 1;

		static const int DEFAULT_CAPACITY = 5;
		// CONSTRUCTORS and DESTRUCTOR
		//sequence();
		sequence(int initial_capacity = DEFAULT_CAPACITY);
		sequence(const sequence& source);
		~sequence();
		// MODIFICATION MEMBER FUNCTIONS
		void resize(int new_capacity);
		void start();
		void advance();
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void remove_current();
		void operator =(const sequence& source);
		// CONSTANT MEMBER FUNCTIONS
		int size() const;
		bool is_item() const;
		value_type current() const;
	private:
		value_type* data;
		int used;
		int current_index;
		int capacity;
	};
}

#endif


