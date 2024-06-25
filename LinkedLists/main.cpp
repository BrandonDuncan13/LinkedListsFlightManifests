#include "Node.h"
#include "NodePlus.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

#include <iostream>
#include <string.h>
#include <iomanip>


// Function Prototypes
void displayMainMenu();
void displayPassMenu(int);
int mainMenuInput();
int flightNumInput();
int passengerMenuInput(int);
std::string passengerNameInput();
void printFlightManifests(SingleLinkedList);
void driver();

int main() // Flights Manifests Program Using Doubly Linked List and Singly Linked Lists
{
	// User makes choices at main menu and passenger menu
	int mainMenuChoice = 0;
	int pasMenuChoice = 0;

	// creating a single linked list of flights that has no nodes in it
	SingleLinkedList flights;

	do // main menu -> make a change or reservation, print all manifests, driver, or exit the program
	{
		mainMenuChoice = mainMenuInput();

		if (mainMenuChoice == 1) // make a change or reservation
		{
			int flightNumber = flightNumInput(); // for example 2430
			Node* flight = flights.findNode(flightNumber);

			if (flight == nullptr) // if the flight is not found, a new flight is created
			{
				flights.addNode(flightNumber);
				flight = flights.findNode(flightNumber);
			}

			do // passenger menu -> insert, remove, and view passengers on the flight
			{
				pasMenuChoice = passengerMenuInput(flightNumber);

				std::string passenger;

				if (pasMenuChoice == 1) // insert a passenger into the selected flight
				{
					std::cout << "Enter the name of the passenger you want to add to flight " << flightNumber << "." << std::endl;
					passenger = passengerNameInput();

					// add the passenger to the current flight
					flight->m_passengers->addNodeAtTail(passenger);
				}
				else if (pasMenuChoice == 2) // remove a passenger from the selected flight
				{
					std::cout << "Enter the name of the passenger you want to remove from flight " << flightNumber << "." << std::endl;
					passenger = passengerNameInput();

					// search flight's passenger list to find node with the passenger
					NodePlus* passengerNode = flight->m_passengers->findNode(passenger);

					if (passengerNode == nullptr) // the passenger is not found
					{
						std::cout << "The passenger you entered was not found on this flight. Please try again!\n" << std::endl;
						// the user returns to the passenger menu now
					}
					else // the passenger is found
					{
						// remove the passenger from the list or flight
						flight->m_passengers->deleteNode(passengerNode);
					}
				}
				else if (pasMenuChoice == 3) // List the passengers on the selected flight
				{
					flight->m_passengers->printList();
				}
				else if (pasMenuChoice == 4) // List the passengers on the selected flight in reverse order
				{
					flight->m_passengers->printReverseList();
				}
				else if (pasMenuChoice == 5) // exit the selected flight
				{
					std::cout << "Exiting flight " << flightNumber << ".\n" << std::endl;
				}
				else if (pasMenuChoice == 0) // exits the program
				{
					std::cout << "Exiting the program." << std::endl;

					return 0;
				}
			}
			while (!(pasMenuChoice == 5)); // end of the passenger menu do while loop
		}
		else if (mainMenuChoice == 2) // main menu print all manifests
		{
			printFlightManifests(flights);
		}
		else if (mainMenuChoice == 3) // executes the driver function to test the program
		{
			driver();
		}
		else // exits the program
		{
			std::cout << "Exiting the program." << std::endl;

			return 0;
		}
	}
	while (!(mainMenuChoice == 0)); // end of the menu do while loop

	// waits for enter key press
	std::cin.get();
}


// Standard Input Validation Functions
template <typename T>
void validateInput(T& userInput) // ensures that the user enters a valid input
{
	// Input Validation
	while (!std::cin.good())
	{
		// clear the stream
		std::cin.clear(); 
		std::cin.ignore(100, '\n'); 

		// have the user re-enter input
		std::cout << "Invalid input! Please try again." << std::endl;
		// this should mean that only one option is grabbed -> so only 1 is grabbed when '1 2' is entered
		std::cin >> std::setw(1) >> userInput;
	}

	// clear the stream again now good input has been recieved
	std::cin.clear();
	std::cin.ignore(100, '\n');
}

std::string validateString(std::string name) // ensures that the user enters a valid input string
{
	std::getline(std::cin, name); // the whole line entered is grabbed

	// Input Validation
	while ((!std::cin.good()) || name == " ") // the only thing this doesn't handle is when the user enters numbers
	{
		// have the user re-enter input
		std::cout << "Invalid input! Please try again." << std::endl;
		std::getline(std::cin, name);
	}

	return name;
}


// Display Functions
void displayMainMenu() // main menu with options
{
	std::cout << std::setw(12) << "====== FLIGHT MANIFESTS - MAIN MENU ======" << std::endl;
	std::cout << "1 - Press to make or change a reservation." << std::endl;
	std::cout << "2 - Press to print all manifests." << std::endl;
	std::cout << "3 - For driver." << std::endl;
	std::cout << "0 - Exit program\n" << std::endl;
	std::cout << "Enter your choice:" << std::endl;
}

void displayPassMenu(int flight) // passenger menu with options
{
	std::cout << std::setw(12) << "=========== FLIGHT PASSENGERS ===========" << std::endl;
	std::cout << "1 - Insert passenger onto flight " << flight << "." << std::endl;
	std::cout << "2 - Remove passenger from flight " << flight << "." << std::endl;
	std::cout << "3 - List passengers on flight " << flight << "." << std::endl;
	std::cout << "4 - List passengers by reverse order." << std::endl;
	std::cout << "5 - Exit flight " << flight << "." << std::endl;
	std::cout << "0 - Exit program\n" << std::endl;
	std::cout << "Enter your choice:" << std::endl;
}


// User Input Functions
int mainMenuInput() // prompts user to enter a main menu option until they enter a valid one
{
	displayMainMenu();

	// asks user to enter a main menu option and validates input
	int userInput = 0;
	std::cin >> std::setw(1) >> userInput;
	validateInput(userInput);

	while (!(userInput >= 0 && userInput <= 3)) // main menu options are between 0 and 3
	{
		std::cout << "Invalid option. Please make one of the following selections:" << "\n" << std::endl;
		
		// make the user give input until they enter a valid option
		displayMainMenu();
		validateInput(userInput);
	}

	return userInput;
}

int flightNumInput() // prompts user to enter a flight number until they enter a valid one
{
	std::cout << "Please Enter a Flight Number:" << std::endl;

	// asks user to enter a flight number and validates input
	int userFlight = 0;
	std::cin >> std::setw(1) >> userFlight;
	validateInput(userFlight);

	while (!(userFlight >= 0 && userFlight <= 3000)) // flight numbers are between 0 and 3000
	{
		std::cout << "Invalid flight. Please enter a flight number between 0-3000:\n" << std::endl;
		std::cout << "Please Enter a Flight Number:" << std::endl;
		
		validateInput(userFlight);
	}
	std::cout << "\n" << "Flight " << userFlight << " was selected." << std::endl;

	return userFlight;
}

int passengerMenuInput(int flight) // prompts user to enter a passenger menu option until they enter a valid one
{
	displayPassMenu(flight);

	// asks user to enter a passenger menu option and validates input
	int userInput = 0;
	std::cin >> std::setw(1) >> userInput;
	validateInput(userInput);

	while (!(userInput >= 0 && userInput <= 4)) // passenger menu options are between 0 and 4
	{
		std::cout << "Invalid option. Please make one of the following selections:\n" << std::endl;
		// display the passenger menu
		displayPassMenu(flight);

		validateInput(userInput);
	}

	return userInput;
}

std::string passengerNameInput() // prompts user to enter a passenger name until they enter a valid one
{
	std::string passenger, first = "", last = "";

	// get a valid first name
	std::cout << "The passenger's first name: " << std::endl;
	first = validateString(first);
	// then get a valid last name
	std::cout << "The passenger's last name: " << std::endl;
	last = validateString(last);
	passenger = last + " " + first;

	return passenger;
}


// Print Function
void printFlightManifests(SingleLinkedList flights)
{
	Node* flight = flights.m_head;

	if (flight == nullptr) // when there are no flights found return some text
	{
		std::cout << "There are currently no flights to print." << std::endl;
	}

	while (flight != nullptr) // runs while a flight is being pointed to
	{
		NodePlus* passenger = flight->m_passengers->m_head;

		if (passenger != nullptr) // the flight will be printed if at least one passenger exists on it
		{
			std::cout << "\n" << "Flight Number : " << flight->m_data << std::endl;

			while (passenger != nullptr) // cycles through flight's passengers list, printing each passenger
			{
				std::cout << "Name: " << passenger->m_name << std::endl;
				passenger = passenger->m_next;
			}
		}
		flight = flight->m_next; // goes to the next flight in the linked list
	}
	std::cout << "\n";
}



// Program Driver (Test) Function
void driver() // used to test the program by hardcoding values
{
	SingleLinkedList flightList;

	int flightNumber = 2430;

	// first flight #2430 changes and reservations, then printing passengers
	flightList.addNode(flightNumber);
	Node* flight = flightList.findNode(flightNumber); // the node is at the head of the singly linked list

	std::cout << "Current Flight: " << flightNumber << std::endl;

	std::string passenger;
	passenger = "Hamilton Dale";
	flight->m_passengers->addNodeAtTail(passenger);

	passenger = "Hamilton Leslie";
	flight->m_passengers->addNodeAtTail(passenger);

	passenger = "Hamilton Jonathan";
	flight->m_passengers->addNodeAtTail(passenger);

	passenger = "Hamilton Nicholas";
	flight->m_passengers->addNodeAtTail(passenger);

	passenger = "Hamilton Annalisa";
	flight->m_passengers->addNodeAtTail(passenger);
	std::cout << "\n";

	std::cout << "\n" << "Flight Number : " << flight->m_data << std::endl;
	flight->m_passengers->printList();
	std::cout << "\n";

	// second flight #2515 changes and reservations, then printing passengers
	flightNumber = 2515;

	flightList.addNode(flightNumber);
	flight = flightList.findNode(flightNumber);

	std::cout << "Current Flight: " << flightNumber;

	passenger = "Absorka Thor";
	flight->m_passengers->addNodeAtTail(passenger);

	passenger = "Snowwispe Nora";
	flight->m_passengers->addNodeAtTail(passenger);

	passenger = "Loki the Mutt";
	flight->m_passengers->addNodeAtTail(passenger);
	std::cout << "\n";

	std::cout << "\n" << "Flight Number : " << flight->m_data << std::endl;
	flight->m_passengers->printList();

	// removing Loki from the flight
	NodePlus* passengerNode = flight->m_passengers->findNode(passenger);
	flight->m_passengers->deleteNode(passengerNode);
	std::cout << "\n" << passenger << " successfully saved from running in an Iditerod" << "\n\n" << std::endl;

	// third flight #2750 changes and reservations
	flightNumber = 2750;

	flightList.addNode(flightNumber);
	flight = flightList.findNode(flightNumber);

	std::cout << "Current Flight: " << flightNumber;

	passengerNode = flight->m_passengers->findNode(passenger);

	flight->m_passengers->addNodeAtTail(passenger); // loki the mutt is added to flight
	std::cout << "\n\n";

	// printing passengers for flights 2515 and 2750
	flightNumber = 2515;
	flight = flightList.findNode(flightNumber);
	std::cout << "Current Flight: " << flightNumber;
	std::cout << "\n" << "Flight Number : " << flight->m_data << std::endl;
	flight->m_passengers->printList();
	std::cout << "\n";

	flightNumber = 2750;
	flight = flightList.findNode(flightNumber);
	std::cout << "Current Flight: " << flightNumber;
	std::cout << "\n" << "Flight Number : " << flight->m_data << std::endl;
	flight->m_passengers->printList();
}
