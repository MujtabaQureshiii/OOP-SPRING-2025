#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double p, string d, string dest)
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << " to " << destination << " on " << date << ".\n";
    }

    virtual void cancel() {
        cout << "Ticket cancellation request received for " << passengerName << ".\n";
    }

    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID
             << "\nPassenger Name: " << passengerName
             << "\nPrice: $" << price
             << "\nDate: " << date
             << "\nDestination: " << destination << endl;
    }

    virtual ~Ticket() {}
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest, string airline, string flight, string seat)
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight Number: " << flightNumber << "\nSeat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double p, string d, string dest, string train, string coach, string time)
        : Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() override {
        cout << "Train ticket reserved for " << passengerName << " on train " << trainNumber
             << " (" << coachType << ") at " << departureTime << ".\n";
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    string seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest, string company, string seat)
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        cout << "Bus ticket for " << passengerName << " is eligible for a last-minute refund.\n";
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest, string artist, string v, string seat)
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue << "\nSeat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight(101, "Mujtaba", 250, "2025-04-10", "Pakistan", "PIA Airlines", "PA123", "Business");
    TrainTicket train(202, "Ali", 60, "2025-04-12", "Lahore", "Amt 50", "Economy", "09:30 AM");
    BusTicket bus(303, "Ahmed", 30, "2025-04-15", "Peshawar", "Multan", "A12");
    ConcertTicket concert(404, "Ayesha", 120, "2025-05-01", "DHA Phase 8", "AtifAslam", "VIP Section", "Front Row");

    cout << "\n=== Ticket Details ===\n";
    flight.displayTicketInfo();
    train.reserve();
    bus.cancel();
    concert.displayTicketInfo();

    return 0;
}
