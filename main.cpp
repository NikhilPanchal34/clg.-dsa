#include <iostream>
#include <stack>
using namespace std;

struct Ticket {
    string name;
    int seatNo;
};

int main() {
    stack<Ticket> bookingStack;
    int choice;
    int seatCounter = 1;

    do {
        cout << "\n===== Ticket Booking System (Stack) =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Last Ticket\n";
        cout << "3. Show Last Booking\n";
        cout << "4. Show All Bookings\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Ticket t;
                cout << "Enter Name: ";
                cin >> t.name;
                t.seatNo = seatCounter++;

                bookingStack.push(t);
                cout << "Ticket Booked! Seat No: " << t.seatNo << endl;
                break;
            }

            case 2: {
                if (!bookingStack.empty()) {
                    cout << "Cancelled Ticket of "
                         << bookingStack.top().name << endl;
                    bookingStack.pop();
                } else {
                    cout << "No bookings to cancel!\n";
                }
                break;
            }

            case 3: {
                if (!bookingStack.empty()) {
                    Ticket t = bookingStack.top();
                    cout << "Last Booking: " << t.name
                         << " | Seat No: " << t.seatNo << endl;
                } else {
                    cout << "No bookings yet!\n";
                }
                break;
            }

            case 4: {
                if (bookingStack.empty()) {
                    cout << "No bookings available!\n";
                } else {
                    stack<Ticket> temp = bookingStack;
                    cout << "\nAll Bookings:\n";
                    while (!temp.empty()) {
                        Ticket t = temp.top();
                        cout << t.name << " | Seat No: " << t.seatNo << endl;
                        temp.pop();
                    }
                }
                break;
            }

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
