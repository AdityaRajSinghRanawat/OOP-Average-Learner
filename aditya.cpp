#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Passenger {
public:
    string name;
    int ticketNumber;

    Passenger(string name, int ticketNumber) 
        : name(name), ticketNumber(ticketNumber) {}
};

class TicketReservationSystem {
private:
    vector<Passenger*> passengers;

public:
    void addPassenger(const string& name, int ticketNumber) {
        Passenger* newPassenger = new Passenger(name, ticketNumber);
        passengers.push_back(newPassenger);
    }

    void displayAllPassengers() {
        cout << "List of Passengers:\n";
        for (const auto& passenger : passengers) {
            cout << "Name: " << passenger->name 
                 << ", Ticket Number: " << passenger->ticketNumber << endl;
        }
    }

    Passenger* searchByTicketNumber(int ticketNumber) {
        for (const auto& passenger : passengers) {
            if (passenger->ticketNumber == ticketNumber) {
                return passenger;
            }
        }
        return nullptr;
    }

    ~TicketReservationSystem() {
        for (const auto& passenger : passengers) {
            delete passenger;
        }
    }
};

int main() {
    TicketReservationSystem system;

    system.addPassenger("Alice", 1001);
    system.addPassenger("Bob", 1002);
    system.addPassenger("Charlie", 1003);

    system.displayAllPassengers();

    int searchTicketNumber = 1002;
    Passenger* foundPassenger = system.searchByTicketNumber(searchTicketNumber);
    if (foundPassenger) {
        cout << "Found Passenger: " << foundPassenger->name 
             << " with Ticket Number: " << foundPassenger->ticketNumber << endl;
    } else {
        cout << "Passenger with Ticket Number " << searchTicketNumber << " not found." << endl;
    }

    return 0;
}


/*

    Q1.  Why do we store Passenger objects as pointers in the TicketReservationSystem class?
    Ans. Pointers make it possible for Passenger objects to have dynamic memory allocation, 
         which improves program efficiency by preventing needless copies and managing their 
         lifespan.
    
    q2.  How does the searchByTicketNumber() function work?
    Ans. It iterates over the passengers to see if the ticket number of any of them corresponds 
         to the one you're seeking. The passenger is returned if a match is found; if not, nullptr 
         is returned.
    
    Q3.  What would happen if we didn’t use an array of pointers to manage the passengers?
    Ans. Passenger objects would be copied into the vector in the absence of pointers, which 
         would result in inefficiencies and possible memory management problems, such as 
         unintentional object deletion.

*/