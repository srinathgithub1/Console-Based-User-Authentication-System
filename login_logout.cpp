#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayMenu();
void login();
void registration();
void forgot();

int main()
{
    int choice;
    do
    {
        displayMenu();
        cout << "\n\t\t\t Please Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "\n\n\t\t\tThankYou! \n\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void displayMenu()
{
    cout << "\t\t\t_____________________________________________________\n\n\n";
    cout << "\t\t\t           Welcome To The Login Page                 \n\n\n";
    cout << "\t\t\t______________     MENU       _______________________\n\n\n";
    cout << "                                                              \n";

    cout << "\t\t\t|      Press 1 to LOGIN                       |" << endl;
    cout << "\t\t\t|      Press 2 to REGISTER                    |" << endl;
    cout << "\t\t\t|      Press 3 if you forgot your PASSWORD    |" << endl;
    cout << "\t\t\t|      Press 4 to EXIT                        |" << endl;
}

/*
    This login function reads the username and password from the user,
    checks against the records in the "records.txt" file, and displays
    a success or error message accordingly. Additionally, it waits
    for the user to press Enter before returning to the main menu for
    better user interaction.

*/

void login()
{
    int count = 0;
    string userId, password, id, pass;

    system("cls");
    cout << "\n\n\t\t\t Please enter the username and password : " << endl;
    cout << "\n\t\t\t USERNAME : ";
    cin >> userId;
    cout << "\t\t\t PASSWORD : ";
    cin >> password;

    ifstream input("records.txt");

    // Check if the file is open
    if (!input.is_open())
    {
        cout << "Error opening the records file." << endl;
        main(); // Go back to the main menu
        return;
    }

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1)
    {
        cout << "\n\n\t\t\t " << userId << "\n\t\t\t Your LOGIN is successful \n\t\t\t Thanks for logging in ! \n";
    }
    else
    {
        cout << "\n\t\t\t LOGIN ERROR \n\t\t\t Please check your username and password\n";
    }

    // Wait for user to press enter before returning to the main menu
    cout << "\n\t\t\t Press Enter to continue...";
    cin.ignore(); // Ignore any leftover newline characters
    cin.get();    // Wait for Enter key
}

/*
    In this registration function, it checks if the entered
    username already exists before allowing registration.
    If the username is already taken, it displays a message
    and returns to the main menu. Additionally, after
    successful registration, it waits for the user to
    press Enter before returning to the main menu.
*/

void registration()
{
    string ruserId, rpassword, rid, rpass;

    system("cls");
    cout << "\n\n\t\t\t Enter the username : ";
    cin >> ruserId;

    // Check if the username already exists
    ifstream checkExisting("records.txt");
    while (checkExisting >> rid >> rpass)
    {
        if (rid == ruserId)
        {
            checkExisting.close();
            cout << "\n\t\t\t Username already exists. Please choose a different username.\n";
            // Wait for user to press enter before returning to the main menu
            cout << "\n\t\t\t Press Enter to continue...";
            cin.ignore(); // Ignore any leftover newline characters
            cin.get();    // Wait for Enter key
            main();       // Go back to the main menu
            return;
        }
    }
    checkExisting.close();

    cout << "\n\t\t\t Enter the password : ";
    cin >> rpassword;

    // Open the file in append mode to add a new record
    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    f1.close();

    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";

    // Wait for user to press enter before returning to the main menu
    cout << "\n\t\t\t Press Enter to continue...";
    cin.ignore(); // Ignore any leftover newline characters
    cin.get();    // Wait for Enter key
}

/*
    This forgot function allows the user to search for their
    password by providing the username. It checks if the
    username exists in the records and displays the
    corresponding password. After the operation, it waits
    for the user to press Enter before returning to the
    main menu.
*/

void forgot()
{
    int option;
    system("cls");
    cout << "\n\n\t\t\t | You forgot the password? No worries :       |\n";
    cout << "\t\t\t | Press 1 to search your id by username.      |" << endl;
    cout << "\t\t\t | Press 2 to go back to the main menu.        |\n"
         << endl;
    cout << "\t\t\t ______________________________________________   \n"
         << endl;
    cout << "\t\t\t   Enter your choice : ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;

        cout << "\n\t\t\t   Enter the username which you remembered : ";
        cin >> suserId;

        ifstream f2("records.txt");

        // Check if the file is open
        if (!f2.is_open())
        {
            cout << "Error opening the records file." << endl;
            main(); // Go back to the main menu
            return;
        }

        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
                break;
            }
        }
        f2.close();

        if (count == 1)
        {
            cout << "\n\t\t\t   Your account is FOUND! \n";
            cout << "\n\t\t\t   Your password is : " << spass << endl;
        }
        else
        {
            cout << "\n\t\t\t   Sorry! your account is NOT FOUND! \n";
        }

        // Wait for user to press enter before returning to the main menu
        cout << "\n\t\t\t   Press Enter to continue...";
        cin.ignore(); // Ignore any leftover newline characters in buffer
        cin.get();    // Wait for Enter key

        main(); // Go back to the main menu
        break;
    }
    case 2:
        main(); // Go back to the main menu
        break;
    default:
    {
        cout << "\t\t\t   Wrong choice ! Please try again \n"
             << endl;
        cout << "\t\t\t   Press Enter to continue...";
        cin.ignore(); // Ignore any leftover newline characters in buffer
        cin.get();    // Wait for Enter key
        forgot();     // Recursive call
    }
    }
}
