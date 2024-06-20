#include "Node.h"
#include "NodePlus.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

#include <iostream>
#include <string.h>
#include <iomanip>

void driver();
int grabInput();
int flightNum();
int passengerInput(int);
std::string passengerName();
void displayMainMenu();
void displayPassMenu(int);
void printFlightManifests(SingleLinkedList);

int main()
{
	int option = 0;
	int optionTwo = 0;

	// creating a single linked list of flights that has no nodes in it
	SingleLinkedList flights;

	do // the entire program exists inside of this do-while and can be used as long as user wants
	{
		option = grabInput();

		if (option == 1) // main menu -> make a change or reservation
		{
			int flightNumber = flightNum(); // for example 2430
			Node* flight = flights.findNode(flightNumber);

			if (flight == nullptr) // if the flight is not found, a new flight is created
			{
				flights.addNode(flightNumber);
				flight = flights.findNode(flightNumber);
			}

			do // passenger menu -> insert, remove, and view passengers on the flight
			{
				optionTwo = passengerInput(flightNumber);

				std::string passenger;

				if (optionTwo == 1) // insert a passenger into the selected flight
				{
					std::cout << "Enter the name of the passenger you want to add to flight " << flightNumber << "." << std::endl;
					passenger = passengerName();

					// add the passenger to the current flight
					flight->m_passengers->addNodeAtTail(passenger);
				}
				else if (optionTwo == 2) // remove a passenger from the selected flight
				{
					std::cout << "Enter the name of the passenger you want to remove from flight " << flightNumber << "." << std::endl;
					passenger = passengerName();

					// search flight's passenger list to find node with the passenger
					NodePlus* passengerNode = flight->m_passengers->findNode(passenger);

					if (passengerNode == nullptr) // the passenger is not found
					{
						std::cout << "The passenger you entered was not found on this flight. Please try again!\n" << std::endl;
						// the user returns to the passenger menu now
					}
					else
					{
						// remove the passenger from the list or flight
						flight->m_passengers->deleteNode(passengerNode);
						std::cout << "\nThe passenger " << passenger << " was deleted from the flight." << std::endl;
					}
				}
				else if (optionTwo == 3) // List the passengers on the selected flight
				{
					flight->m_passengers->printList();
				}
				else if (optionTwo == 4) // List the passengers on the selected flight in reverse order
				{
					flight->m_passengers->printReverseList();
				}
				else // exit the selected flight
				{
					std::cout << "Exiting flight " << flightNumber << ".\n" << std::endl;
				}
			}
			while (!(optionTwo == 0)); // end of the passenger menu do while loop
		}
		else if (option == 2) // main menu print all manifests
		{
			printFlightManifests(flights);
		}
		else if (option == 3) // executes the driver function to test the program
		{
			driver();
		}
		else // exits the program
		{
			std::cout << "Exiting the program." << std::endl;
		}
	}
	while (!(option == 0)); // end of the menu do while loop

	// waits for enter key press
	std::cin.get();
}

template <typename T>
void validateInput(T& userInput)
{
	std::cin >> std::setw(1) >> userInput; // this should mean that only one option is grabbed -> so only 1 is grabbed when '1 2' is entered

	// Input Validation
	while (!std::cin.good())
	{
		// clear the stream
		std::cin.clear(); 
		std::cin.ignore(100, '\n'); 

		// have the user re-enter input
		std::cout << "Invalid input! Please try again." << std::endl;
		std::cin >> std::setw(1) >> userInput;
	}

	// clear the stream again now good input has been recieved
	std::cin.clear();
	std::cin.ignore(100, '\n');
}

std::string validateString(std::string name)
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

void displayMainMenu()
{
	std::cout << std::setw(12) << "=== MAIN MENU ===" << std::endl;
	std::cout << "1 - Press to make or change a reservation." << std::endl;
	std::cout << "2 - Press to Print all manifests." << std::endl;
	std::cout << "3 - For Driver." << std::endl;
	std::cout << "0 - Exit program\n" << std::endl;
}
void displayPassMenu(int flight)
{
	std::cout << std::setw(12) << "=== List of passengers ===" << std::endl;
	std::cout << "1 - Insert passenger onto flight " << flight << "." << std::endl;
	std::cout << "2 - Remove passenger from flight " << flight << "." << std::endl;
	std::cout << "3 - List passengers on flight " << flight << "." << std::endl;
	std::cout << "4 - List passengers by reverse order." << std::endl;
	std::cout << "0 - Exit flight " << flight << ".\n" << std::endl;
}

int grabInput()
{
	displayMainMenu();

	int userInput = 0;
	validateInput(userInput);

	while (!(userInput >= 0 && userInput <= 3))
	{
		std::cout << "Invalid option. Please make one of the following selections:" << "\n" << std::endl;
		// display main menu
		displayMainMenu();

		validateInput(userInput);
	}
	return userInput;
}

int flightNum() // prompts user to enter a flight number until they enter a valid one
{
	std::cout << "Please Enter a Flight Number:" << std::endl;

	int userFlight = 0;
	validateInput(userFlight);

	while (!(userFlight >= 0 && userFlight <= 3000))
	{
		std::cout << "Invalid flight. Please enter a flight number between 0-3000:\n" << std::endl;
		std::cout << "Please Enter a Flight Number:" << std::endl;
		
		validateInput(userFlight);
	}
	std::cout << "\n" << "Flight " << userFlight << " was selected." << std::endl;

	return userFlight;
}

int passengerInput(int flight)
{
	displayPassMenu(flight);

	int userInput = 0;
	validateInput(userInput);

	while (!(userInput >= 0 && userInput <= 4))
	{
		std::cout << "Invalid option. Please make one of the following selections:\n" << std::endl;
		// display the passenger menu
		displayPassMenu(flight);

		validateInput(userInput);
	}
	return userInput;
}

std::string passengerName()
{
	std::string passenger, first = "", last = "";

	std::cout << "The passenger's first name: " << std::endl;
	first = validateString(first);
	std::cout << "The passenger's last name: " << std::endl;
	last = validateString(last);
	passenger = last + " " + first;

	return passenger;
}

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
