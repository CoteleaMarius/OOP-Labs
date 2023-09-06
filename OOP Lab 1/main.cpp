#include <iostream>
#include <string>

using namespace std;

struct country {
    string name;
    string continent;
    int numberOfPeople;
};

country *country1 = new country;
country *country2 = new country;

void setCountryName() {
    string name;
    cout << "Insert first's country name:";
    cin >> name;
    country1->name = name;
    cout << "Insert second's country name:";
    cin >> name;
    country2->name = name;
}

void setContinentName() {
    string continent;
    cout << "Insert first's country continent's name:";
    cin >> continent;
    country1->continent = continent;
    cout << "Insert second's country continent name:";
    cin >> continent;
    country2->continent = continent;
}

void setNumberOfPeople() {
    int numberOfPeople;
    cout << "Insert number of people for the first country:";
    cin >> numberOfPeople;
    country1->numberOfPeople = numberOfPeople;
    cout << "Insert number of people for the second country:";
    cin >> numberOfPeople;
    country2->numberOfPeople = numberOfPeople;
}

void editData() {
    cout << "Modify data for the country 1" << endl;
    cout << "Country 1 name: ";
    cin >> country1->name;
    cout << "Country 1 continent: ";
    cin >> country1->continent;
    cout << "Country 1 number of people: ";
    cin >> country1->numberOfPeople;
    cout << "Modify data for the country 2" << endl;
    cout << "Country 2 name: ";
    cin >> country2->name;
    cout << "Country 2 continent: ";
    cin >> country2->continent;
    cout << "Country 2 number of people: ";
    cin >> country2->numberOfPeople;
}

void compareCountries() {
    if (country1->numberOfPeople > country2->numberOfPeople) {
        cout << country1->name << " has more people than " << country2->name << endl;
    } else if (country1->numberOfPeople < country2->numberOfPeople) {
        cout << country1->name << " has less people than " << country2->name << endl;
    } else {
        cout << "The number of people is equal in both countries" << endl;
    }
}

void freeMemory() {
    delete country1;
    delete country2;
}

int main() {
    setCountryName();
    setContinentName();
    setNumberOfPeople();
    cout << country1->name << endl;
    cout << country1->continent << endl;
    cout << country1->numberOfPeople << endl;
    cout << country2->name << endl;
    cout << country2->continent << endl;
    cout << country2->numberOfPeople << endl;

    int searchByPopulation;
    string searchByName;
    int searchChoice;
    cout
            << "Do you want to search a country in the database ? (press 1 if you want to search by the name 2 if you want to search by the number of people and anything else if you don't want to search a country)"
            << endl;
    cin >> searchChoice;
    if (searchChoice == 1) {
        cout << "Insert the name of the country you want to check:";
        cin >> searchByName;
        if (searchByName == country1->name || searchByName == country2->name) {
            cout << "We have " << searchByName << " in our database" << endl;
        } else {
            cout << "Unfortunately we don't have this country in our database" << endl;
        }
    } else if (searchChoice == 2) {
        cout << "Insert the number of people of the country you want to check:";
        cin >> searchByPopulation;
        if (searchByPopulation == country1->numberOfPeople || searchByPopulation == country2->numberOfPeople) {
            cout << "We have a country with " << searchByPopulation << " people in our database" << endl;
        } else {
            cout << "Unfortunately we don't have this country in our database" << endl;
        }
    }

    cout
            << "Press 1 if you want to edit the data, press 2 if you want to compare the countries based on the number of people and anything else if you want to exit"
            << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        editData();
        cout << country1->name << endl;
        cout << country1->continent << endl;
        cout << country1->numberOfPeople << endl;
        cout << country2->name << endl;
        cout << country2->continent << endl;
        cout << country2->numberOfPeople << endl;
        freeMemory();
    } else if (choice == 2) {
        compareCountries();
        freeMemory();
    } else {
        freeMemory();
        exit(0);
    }

    return 0;
}
