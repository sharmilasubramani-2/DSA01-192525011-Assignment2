#include <iostream>
#include <string>
using namespace std;

class BusTicket {
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    explicit BusTicket(const string& n) : seat(0), name(n) {
        if (issued < CAPACITY) {
            issued++;
            seat = issued;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        cout << name << ": "
             << (seat ? "Seat " + to_string(seat) : string("Waiting"))
             << '\n';
    }
};

int BusTicket::issued = 0;

void createAdditionalTickets() {
    BusTicket extra1("Extra Passenger 1");
    BusTicket extra2("Extra Passenger 2");

    extra1.print();
    extra2.print();

    cout << "Issued inside function: " << BusTicket::count() << '\n';
}

class Token {
    static int next;
    int id;

public:
    Token() {
        id = ++next;
    }

    int get() const {
        return id;
    }

    static int issued() {
        return next - 100;
    }
};

int Token::next = 100;

int main() {
    cout << "TOKEN OUTPUT PREDICTION" << endl;

    Token counter[3];
    Token extra;

    cout << counter[0].get() << ' '
         << counter[2].get() << ' '
         << extra.get() << ' '
         << Token::issued() << '\n';

    cout << "\nCOLLEGE BUS TICKET SYSTEM" << endl;

    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (const BusTicket& ticket : trip) {
        ticket.print();
    }

    cout << "Issued: " << BusTicket::count() << '\n';

    cout << "\nCREATING TICKETS INSIDE A FUNCTION" << endl;

    createAdditionalTickets();
    createAdditionalTickets();

    cout << "Final Issued Count: " << BusTicket::count() << '\n';

    return 0;
}