#pragma once
#include <iostream>
#include <string>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<vector>
#include<fstream>
using namespace std;

void welcomepage()
{
    system("COLOR 3F");
    cout << "\n\t\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t\t\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t\t\t        |                 WELCOME                   |";
    cout << "\n\t\t\t\t\t\t        |                   TO                      |";
    cout << "\n\t\t\t\t\t\t        |            Non-Funglible Tokens           |";
    cout << "\n\t\t\t\t\t\t        |                  (NFT)                    |";
    cout << "\n\t\t\t\t\t\t        |                Marketplace                |";
    cout << "\n\t\t\t\t\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\n\t\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t***WELCOME***\n\n";
}

class Person
{
protected:
    string name;
    int age{};
    string NIC{};
    string Contact{};
    string address;
    string username;
    string password;
public:
    Person() {}
    Person(string n, int a, string nic, string c, string addr, string user, string pass) : name(n), age(a), NIC(nic), Contact(c), address(addr), username(user), password(pass) {}

    void setName(const string& n) { name = n; }
    void setAge(const int& a) { age = a; }
    void setNIC(const string& nic) { NIC = nic; }
    void setContact(const string& Con) { Contact = Con; }
    void setAddress(const string& addr) { address = addr; }
    void setUserName(const string& u) { username = u; }
    void setPassword(const string& p) { password = p; }

    const string& getName() const { return name; }
    const int& getAge() const { return age; }
    const string& getNIC() const { return NIC; }
    const string& getContact() const { return Contact; }
    const string& getAddress() const { return address; }
    const string& getUsername() const { return username; }
    const string& getPassword() const { return password; }

    virtual void display() = 0;

};

class Admin : public Person
{
    // NFT nft;
     //Ewallet ewallet;
public:

    Admin() :Person("Miss Zainab", 45, "4210123467543", "923336547895", "B-23 Malir Cant Karachi", "misszainab@nft.com", "zainab.nft") {}
    void display() {
        cout << "\t\t\t\t\t\t*************** Displaying Admin Information ***************\n" << endl;
        cout << "\t\t\t\t\t\t\t\t  Name: " << name << endl;
        cout << "\t\t\t\t\t\t\t\t  Age: " << age << endl;
        cout << "\t\t\t\t\t\t\t\t  NIC Number: " << NIC << endl;
        cout << "\t\t\t\t\t\t\t\t  Contact Number: " << Contact << endl;
        cout << "\t\t\t\t\t\t\t\t  Address: " << address << endl;
        cout << "\t\t\t\t\t\t\t\t  Username: " << username << endl;
    }
};

class User :public Person {

public:
    User() {}
    User(string a, int b, string c, string d, string e, string f, string g) :Person(a, b, c, d, e, f, g) {

    }

    void display() {
        cout << "\t\t\t\t\t\t*************** Displaying User Information ***************\n" << endl;
        cout << "\t\t\t\t\t\t\t\t  Name: " << name << endl;
        cout << "\t\t\t\t\t\t\t\t  Age: " << age << endl;
        cout << "\t\t\t\t\t\t\t\t  NIC Number: " << NIC << endl;
        cout << "\t\t\t\t\t\t\t\t  Contact Number: " << Contact << endl;
        cout << "\t\t\t\t\t\t\t\t  Address: " << address << endl;
        cout << "\t\t\t\t\t\t\t\t  Username: " << username << endl;
    }
    void store_data() {
        ofstream fout;
        fout.open("Users.txt", ios::app | ios::binary);
        fout.write((char*)this, sizeof(*this));
        fout.close();
    }
    bool login(string u, string p) {
        ifstream fin;
        fin.open("Users.txt", ios::in | ios::binary);
        if (!fin) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return false;
        }
        else {
            bool found = false;
            while (fin.read((char*)this, sizeof(*this))) {
                if (u == username && p == password) {
                    found = true;
                    break;
                }
            }
            fin.close();
            return found;
        }
    }
    void update_user(string u, int age, string contact, string addr, string user, string pass)
    {
        fstream file;
        file.open("Users.txt", ios::in | ios::out | ios::binary);
        if (!file.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return;
        }
        bool found = false;
        while (file.read((char*)this, sizeof(*this))) {
            if (username == u) {
                found = true;
                setAge(age);
                setContact(contact);
                setAddress(addr);
                setUserName(user);
                setPassword(pass);
                file.seekp(-static_cast<int>(sizeof(*this)), ios::cur);
                file.write((char*)this, sizeof(*this));
                cout << "\t\t\t\t\t\t\tuser Updated Successfully.\n";
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "\t\t\t\t\t\t\tuser not found.\n";
        }
    }
    void delete_user(string user)
    {
        ifstream fin;
        ofstream fout;
        fin.open("Users.txt", ios::in | ios::binary);
        fout.open("TEMP.txt", ios::out | ios::binary);
        if (!fin)
        {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
        }
        else
        {
            bool found = false;
            while (fin.read((char*)this, sizeof(*this)))
            {
                if (username == user)
                {
                    found = true;
                    cout << "\t\t\t\t\t\t\tUser Deleted Successfully.\n";
                }
                else
                {
                    fout.write((char*)this, sizeof(*this));
                }
            }
            fin.close();
            fout.close();
            if (!found)
            {
                cout << "\t\t\t\t\t\t\tUser not found.\n";
            }
            else
            {
                if (remove("Users.txt") != 0) {
                    cout << "Error deleting file" << endl;
                }
                if (rename("TEMP.txt", "Users.txt") != 0) {
                    cout << "Error renaming file" << endl;
                }

            }
        }
    }
};

class NFT {
private:
    string username;
    string ownername;
    string name;
    string description;
    double price{};
    double Bid{};
    double prev_bid{};
    string bidder;
public:
    NFT() {}
    NFT(string name, string ownername, string description, double price, string username, double bid, double prev_bid, string bidder) {
        this->name = name;
        this->ownername = ownername;
        this->description = description;
        this->price = price;
        this->username = username;
        this->Bid = Bid;
        this->prev_bid = prev_bid;
        this->bidder = bidder;
    }

    void setName(const string& name) { this->name = name; }
    void setDescription(const string& description) { this->description = description; }
    void setPrice(const double& price) { this->price = price; }
    void setUsername(const string& username) { this->username = username; }
    void setOwnername(const string& ownername) { this->ownername = ownername; }
    void setBid(const double& Bid) { this->Bid = Bid; }


    const string& getUsername() const { return username; }
    const string& getName() const { return this->name; }
    const string& getDescription() const { return this->description; }
    const double& getPrice() const { return this->price; }
    const string& getOwnername() const { return ownername; }
    const double& getBid() const { return this->Bid; }


    void storeNFT() {
        ofstream fout;
        fout.open("NFT.txt", ios::app | ios::binary);
        fout.write((char*)this, sizeof(*this));
        fout.close();
    }
    void printNFT() {
        cout << "\n\n\t\t\t\t\t\t\tNFT Details\n\n";
        cout << "\t\t\t\t\t\t\tNFT NAME: " << name << endl;
        cout << "\t\t\t\t\t\t\tNFT OWNER NAME: " << ownername << endl;
        cout << "\t\t\t\t\t\t\tNFT DESCRIPTION: " << description << endl;
        cout << "\t\t\t\t\t\t\tNFT PRICE: " << price << endl;
        cout << "\t\t\t\t\t\t\tNFT CURRENT BID: " << Bid << endl;
        cout << "\t\t\t\t\t\t\tNFT PREVIOUS BID: " << prev_bid << endl;
        cout << "\t\t\t\t\t\t\tBIDDER NAME: " << bidder << endl;
    }
    void displayNFT(User u1) {
        string u = u1.getUsername();

        ifstream fin("NFT.txt", ios::in | ios::binary);
        if (!fin.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return;
        }
        bool found = false;
        while (fin.read((char*)this, sizeof(*this))) {
            if (u == username) {
                found = true;
                printNFT();

            }
        }
        if (!found) {
            cout << "\t\t\t\t\t\t\tUser not found.\n";
        }
        fin.close();
    }
    void viewallNFT() {
        ifstream fin;
        fin.open("NFT.txt", ios::in | ios::binary);
        if (!fin) {
            cout << "\t\t\t\t\t\t\tError Opening File\n";
        }
        else {
            while (fin.read((char*)this, sizeof(*this))) {
                printNFT();
            }
        }
        fin.close();
    }
    void storeBid(User u1, double n_bid, double p_bid) {
        string u = u1.getUsername();

        fstream file;
        file.open("NFT.txt", ios::in | ios::out | ios::binary);
        if (!file.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
        }
        else {
            while (file.read(reinterpret_cast<char*>(this), sizeof(*this))) {
                if (username == u) {
                    Bid = n_bid;
                    prev_bid = p_bid;
                    file.seekp(-static_cast<int>(sizeof(*this)), ios::cur);
                    file.write(reinterpret_cast<char*>(this), sizeof(*this));
                    break;
                }
            }
            file.close();
        }
    }



    void changeownership(string nftname, string newownername, string newusername) {
        fstream file;
        file.open("NFT.txt", ios::in | ios::out | ios::binary);
        if (!file.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return;
        }
        bool found = false;
        while (file.read((char*)this, sizeof(*this))) {
            if (name == nftname) {
                found = true;
                setOwnername(newownername);
                setUsername(newusername);
                file.seekp(-static_cast<int>(sizeof(*this)), ios::cur);
                file.write((char*)this, sizeof(*this));
                cout << "\t\t\t\t\t\t\tOwnership Changed Successfully.\n";
                break;
            }
        }
        if (!found) {
            cout << "\t\t\t\t\t\t\tNFT not found.\n";
        }
        file.close();
    }
    void deleteNft(string n)
    {
        ifstream fin;
        ofstream fout;
        fin.open("NFT.txt", ios::in | ios::binary);
        if (!fin) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
        }
        else {
            fout.open("TEMP.txt", ios::out | ios::binary);
            while (fin.read((char*)this, sizeof(*this))) {
                if (getName() != n) {
                    fout.write((char*)this, sizeof(*this));
                }
            }
            fin.close();
            fout.close();
            if (remove("NFT.txt") != 0) {
                cout << "Error deleting file" << std::endl;
            }
            if (rename("TEMP.txt", "NFT.txt") != 0) {
                cout << "Error renaming file" << std::endl;
            }
        }
    }
    void getNftData()
    {
        cout << "Enter Name" << endl;
        cin >> name;
        setName(name);
        cout << "Enter Owner Name" << endl;
        cin >> ownername;
        setOwnername(ownername);
        cout << "Enter Description" << endl;
        cin >> description;
        setDescription(description);
        cout << "Enter Price" << endl;
        cin >> price;
        setPrice(price);

        cout << "Enter User Name" << endl;
        cin >> username;
        setUsername(username);
    }
    void updateNft(string n, string name, string ownername, string description, int price, string username) {
        fstream file;
        file.open("NFT.txt", ios::in | ios::out | ios::binary);
        if (!file.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return;
        }
        bool found = false;
        while (file.read((char*)this, sizeof(*this))) {
            if (getName() == n) {
                found = true;
                cout << "\t\t\t\t\t\t\tEnter New NFT Details:\n";
                setName(name);
                setOwnername(ownername);
                setPrice(price);
                setDescription(description);
                setUsername(username);
                file.seekp(-static_cast<int>(sizeof(*this)), ios::cur);
                file.write((char*)this, sizeof(*this));
                cout << "\t\t\t\t\t\t\tNFT Updated Successfully.\n";
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "\t\t\t\t\t\t\tNFT not found.\n";
        }
    }
    double readPrice(string t) {
        double p = 0;
        bool found = false;

        ifstream fin;
        fin.open("NFT.txt", ios::in | ios::binary);
        if (!fin)
        {
            cout << "\n-----error in opening file-----\n";
        }
        else {
            while (fin.read((char*)this, sizeof(*this)))
            {
                if (t == name) {

                    p = price;
                    found = true;
                }
            }
        }
        fin.close();
        if (!found) {
            cout << "Not Found";
        }
        return p;
    }
    double readPrevLimit(string t) {
        double p = 0;
        bool found = false;

        ifstream fin;
        fin.open("NFT.txt", ios::in | ios::binary);
        if (!fin)
        {
            cout << "\n-----error in opening file-----\n";
        }
        else {
            while (fin.read((char*)this, sizeof(*this)))
            {
                if (t == name) {

                    p = Bid;
                    found = true;
                }
            }
        }
        fin.close();
        if (!found) {
            cout << "Not Found";
        }
        return p;
    }
    string readBidder(string t) {
        string p;
        bool found = false;

        ifstream fin;
        fin.open("NFT.txt", ios::in | ios::binary);
        if (!fin)
        {
            cout << "\n-----error in opening file-----\n";
        }
        else {
            while (fin.read((char*)this, sizeof(*this)))
            {
                if (t == name) {

                    p = bidder;
                    found = true;
                }
            }
        }
        fin.close();
        if (!found) {
            cout << "Not Found";
        }
        return p;
    }
    void getwinner(string t) {
        string b;
        double amnt = 0;
        ifstream fin;
        fin.open("NFT.txt", ios::in);
        while (fin.read((char*)this, sizeof(*this)))
        {
            if (t == name) {

                amnt = Bid;
                b = bidder;
            }
        }


        fin.close();

        cout << "Auction ended. " << b << " won " << name << " for " << amnt << " crypto" << endl;
        changeownership(name, ownername, username);
    }
};
class Ewallet
{
private:
    static double conversion_rate;
    string credit_card_num{};
    double crypto{};
    double usd{};
    string username;
public:
    Ewallet() {}
    User u;
    Ewallet(string username, string credit_card_num, double usd)
    {
        this->username = username;
        this->credit_card_num = credit_card_num;
        this->usd = usd;
        this->crypto = 0.0;
    }


    void setUsd(double& usd) { this->usd = usd; }
    double& getUsd() { return this->usd; }

    void setCrypto(double& crypto) { this->crypto = crypto; }
    double& getCrypto() { return this->crypto; }

    void setUsername(const string username) { this->username = username; }
    string getusername()const { return username; }

    void setCreditCardNum(string& credit_card_num) { this->credit_card_num = credit_card_num; }
    string& getCreditCardNum() { return this->credit_card_num; }

    void setConversionRate(double& rate) { this->conversion_rate = rate; }
    double& getConversionRate() { return this->conversion_rate; }

    void crypto_into_usd(User u1, double amnt)
    {
        string u;
        double us = 0, crp = 0;
        u = u1.getUsername();
        ifstream fin;
        fin.open("Ewallet.txt", ios::in | ios::binary);
        if (!fin.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return;
        }
        else {

            while (fin.read((char*)(this), sizeof(*this))) {
                if (username == u) {
                    us = usd;
                    crp = crypto;
                    break;
                }
            }
            fin.close();
        }
        conversion_rate = findCurrentConversionRate();
        cout << "Current Conversion rate is 1 Crypto = " << conversion_rate << " USD\n";
        if (crp >= amnt)
        {
            crp -= amnt;
            us += amnt * conversion_rate;
            fstream file;
            file.open("Ewallet.txt", ios::in | ios::out | ios::binary);
            if (!file) {
                cout << "Error Opening File\n";
            }
            else {
                while (file.read((char*)this, sizeof(*this))) {
                    if (u == username) {
                        setUsd(us);
                        setCrypto(crp);
                        file.seekp(-static_cast<int>(sizeof(*this)), ios::cur);
                        file.write((char*)this, sizeof(*this));
                        break;
                    }
                }
            }

        }
        else
        {
            cout << "Insufficient Balance !";

        }
    }
    void usd_into_crypto(User u1, double amnt)
    {

        string u;
        double us = 0, crp = 0;
        u = u1.getUsername();
        ifstream fin;
        fin.open("Ewallet.txt", ios::in | ios::binary);
        if (!fin.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return;
        }
        else {

            while (fin.read((char*)(this), sizeof(*this))) {
                if (username == u) {
                    us = usd;
                    crp = crypto;
                    break;
                }
            }
            fin.close();
        }

        conversion_rate = findCurrentConversionRate();
        cout << "Current Conversion rate is 1 Crypto = " << conversion_rate << " USD\n";
        if (us >= amnt)
        {
            us -= amnt;
            crp += amnt / conversion_rate;

            fstream file;
            file.open("Ewallet.txt", ios::in | ios::out | ios::binary);
            if (!file) {
                cout << "Error Opening File\n";
            }
            else {
                while (file.read((char*)this, sizeof(*this))) {
                    if (username == u) {
                        setUsd(us);
                        setCrypto(crp);
                        file.seekp(-static_cast<int>(sizeof(*this)), ios::cur);
                        file.write((char*)this, sizeof(*this));
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "Insufficient Balance !";

        }

    }
    double findCurrentConversionRate() {
        double rate;
        srand((unsigned int)time(NULL));
        rate = ((rand() % 11) - 5);
        conversion_rate = conversion_rate + (conversion_rate * (rate / 100));
        return conversion_rate;
    }

    double readCrypto(User u1) {
        string u = u1.getUsername();
        double amnt = 0;
        ifstream fin;
        fin.open("Ewallet.txt", ios::in | ios::binary);
        if (!fin.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";

        }
        else {

            while (fin.read((char*)(this), sizeof(*this))) {
                if (username == u) {
                    amnt = crypto;
                    break;
                }
            }
            fin.close();
        }

        return amnt;
    }
    void storeEwallet() {
        ofstream fout("Ewallet.txt", ios::app | ios::binary);
        if (fout.is_open()) {
            fout.write((char*)this, sizeof(*this));
            fout.close();
        }
        else {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
        }
    }
    void printewallet() {
        cout << "\n\n\t\t\t\t\t\t\tE-Wallet Details\n\n";
        cout << "\t\t\t\t\t\t\tUsername: " << getusername() << endl;
        cout << "\t\t\t\t\t\t\tCredit Card Number: " << getCreditCardNum() << endl;
        cout << "\t\t\t\t\t\t\tUSD Balance: " << getUsd() << endl;
        cout << "\t\t\t\t\t\t\tCrypto Balance: " << getCrypto() << endl;
    }
    void displayEwallet(User u1) {
        string u = u1.getUsername();
        ifstream fin("Ewallet.txt", ios::in | ios::binary);
        if (!fin.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return;
        }
        while (fin.read((char*)this, sizeof(*this))) {
            if (u == username) {
                printewallet();
                break;
            }
        }

        fin.close();
    }
    void delete_Ewallet(string n)
    {
        ifstream fin;
        ofstream fout;
        fin.open("Ewallet.txt", ios::in | ios::binary);
        if (!fin) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
        }
        else {
            fout.open("TEMP.txt", ios::out | ios::binary);
            while (fin.read((char*)this, sizeof(*this))) {
                if (username != n) {
                    fout.write((char*)this, sizeof(*this));
                }
            }
            fin.close();
            fout.close();
            if (remove("Ewallet.txt") != 0) {
                cout << "Error deleting file" << endl;
            }
            if (rename("TEMP.txt", "Ewallet.txt") != 0) {
                cout << "Error renaming file" << endl;
            }
        }
    }
    void update_ewallet(User u1, string creditNum, double usd)
    {
        string user;
        user = u1.getUsername();
        fstream file;
        file.open("Ewallet.txt", ios::in | ios::out | ios::binary);
        if (!file.is_open()) {
            cout << "\t\t\t\t\t\t\tError Opening File.\n";
            return;
        }
        bool found = false;
        while (file.read((char*)this, sizeof(*this))) {
            if (username == user) {
                found = true;
                setCreditCardNum(creditNum);
                setUsd(usd);
                file.seekp(-static_cast<int>(sizeof(*this)), ios::cur);
                file.write((char*)this, sizeof(*this));
                cout << "\t\t\t\t\t\t\tEwallet Updated Successfully.\n";
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "\t\t\t\t\t\t\tewallet not found.\n";
        }
    }

};

double Ewallet::conversion_rate = 150.5;


class Seller : public User
{
    friend class Admin;

public:
    void SellNFT(User u1) {
        string u = u1.getUsername();
        string o = u1.getName();
        string name, description, bidder = "None";
        double price, bid = 0, p_bid = 0;
        while (getchar() != '\n');
        cout << "Enter The name of NFT: ";
        getline(cin, name);
        cout << "Enter Description for the NFT: ";
        getline(cin, description);
        cout << "Enter The Minimum Amount In Crypto Coins at which you want to sell your NFT:";
        cin >> price;
        NFT nft(name, o, description, price, u, bid, p_bid, bidder);
        nft.storeNFT();
    }

};
class NftAuction {
private:
    bool isActive = false;
    time_t startTime{};
    time_t endTime{};
    string N;
    Ewallet e1;
    NFT nft;
public:

    NftAuction(string nftName, int biddingTime) {

        this->isActive = true;
        this->startTime = time(nullptr);
        this->endTime = startTime + biddingTime;
    }
    void addBid(User u1) {
        string user = u1.getUsername();

        double newBid = 0, prevBid = 0, selLimit = 0, crpto = 0;
        selLimit = nft.readPrice(N);
        prevBid = nft.readPrevLimit(N);
        cout << "Enter The bid you Want to Enter: \n";
        cin >> newBid;
        crpto = e1.readCrypto(u1);
        if (isActive && time(nullptr) < endTime && newBid < crpto) {
            if (newBid > selLimit) {
                if (newBid > prevBid) {
                    cout << endl << " Bid accepted from " << user << " for " << newBid << " crypto" << endl;
                    ofstream fout;
                    fout.open("buyer.txt", ios::app);
                    fout << user << newBid;
                    fout.close();
                    nft.storeBid(u1, newBid, prevBid);
                }
                else {
                    cout << endl << user << " your bid is :" << newBid << " !! amount must be higher than the current highest bid." << endl;
                }
            }
            else {
                cout << endl << "*****your bid must be greater then the minimum amount set by seller*****\n ";
            }
        }
        else {
            cout << "** Auction is not active Time over **." << endl;
        }
    }

};