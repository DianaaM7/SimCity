#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Person{
public:
    string mName;
    uint16_t mAge;
    double mSalary;
public:
    Person(){mName=""; mAge=0; mSalary=0;}
    Person(string name, uint16_t age, double salary){
        mName = name;
        mAge = age;
        mSalary = salary;
    }
    bool operator==(const Person& p) const{
        if(mName == p.mName && mAge == p.mAge && mSalary == p.mSalary)
            return true;
        return false;
    }
    bool operator<(const Person& p) const{
        if(mName < p.mName)
            return true;
        return false;
    }
    void setmName(string name){
        mName = name;
    }
};

class Building{
protected:
    string mBuildingName, mType;
    Person mCoordinator ;
    vector<Person> mEmployees, mCitizens;
public:
    Building(){mBuildingName = "Unknown"; mType = "Unknown";}
    Building(string name, string type){
        mBuildingName = name;
        mType = type;
    }
    virtual void add(const Person& p) {}
    virtual void remove(const Person& p) {}
    virtual Building * operator+(const Person& p) =0;
    virtual Building * operator-() = 0;
    virtual Building * operator-(const Person& p) =0;
    string getBuildingName() const{
        return mBuildingName;
    };
    string getType() const{
        return mType;
    };
    uint16_t getEmployeesSize() const{
        return mEmployees.size();
    }
    uint16_t getCitizensSize() const{
        return mCitizens.size();
    }
    Person getEmployee(uint16_t index) const{
        return mEmployees[index];
    }
    Person getCitizen(uint16_t index) const{
        return mCitizens[index];
    }
    Person getCoordinator() const{
        return mCoordinator;
    }
};

class CityHall: public Building{
public:
    CityHall(string name):Building(name,"CityHall"){
        mCitizens.clear();
        Person p;
        mCoordinator = p;
    }
    Building * operator+(const Person& p) override{
        if(mCoordinator.mName.empty())
            mCoordinator = p;
        return this;
    }
    Building * operator-() override{
        Person p;
        mCoordinator = p;
        return this;
    }
    Building * operator-(const Person& p) override{
        return this;
    }
    void add(const Person& p) override{
        mCitizens.push_back(p);
    }
    void remove(const Person& p) override{
        for(int i=0; i <= mCitizens.size(); i++)
            if(mCitizens[i] == p)
                mCitizens.erase(mCitizens.begin()+i);
    }
};

class Hospital: public Building{
public:
    Hospital(string name) : Building(name,"Hospital") {
        mCitizens.clear();
        mEmployees.clear();
    }
    Building * operator+(const Person& p) override{
        mEmployees.push_back(p);
        return this;
    }
    Building * operator-(const Person& p) override{
        for(int i=0; i <= mEmployees.size(); i++)
            if(mEmployees[i] == p)
                mEmployees.erase(mEmployees.begin()+i);
        return this;
    }
    Building * operator-() override{
        return this;
    }
    void add(const Person& p) override{
        mCitizens.push_back(p);
    }
    void remove(const Person& p) override{
        for(int i=0; i <= mCitizens.size(); i++)
            if(mCitizens[i] == p)
                mCitizens.erase(mCitizens.begin()+i);
    }
};

class PoliceStation: public Building{
public:
    PoliceStation(string name) : Building(name,"PoliceStation") {
        mCitizens.clear();
        mEmployees.clear();
    }
    Building * operator+(const Person& p) override{
        mEmployees.push_back(p);
        return this;
    }
    Building * operator-(const Person& p) override{
        for(int i=0; i <= mEmployees.size(); i++)
            if(mEmployees[i] == p)
                mEmployees.erase(mEmployees.begin()+i);
        return this;
    }
    Building * operator-() override{
        return this;
    }
    void add(const Person& p) override{
        mCitizens.push_back(p);
    }
    void remove(const Person& p) override{
        for(int i=0; i <= mCitizens.size(); i++)
            if(mCitizens[i] == p)
                mCitizens.erase(mCitizens.begin()+i);
    }
};

class House: public Building{
private:
    uint16_t mMaxNumber;
public:
    House(string name, uint16_t nrmax) : Building(name,"House") {
        mMaxNumber = nrmax;
        mCitizens.clear();
        Person p;
        mCoordinator = p;
    }
    Building * operator+(const Person& p) override{
        if(mCoordinator.mName.empty())
            mCoordinator = p;
        return this;
    }
    Building * operator-() override{
        Person p;
        mCoordinator = p;
        return this;
    }
    Building * operator-(const Person& p) override{
        return this;
    }
    void add(const Person& p) override{
        if(mCitizens.size() < mMaxNumber) mCitizens.push_back(p);
    }
    void remove(const Person& p) override{
        for(int i=0; i < mCitizens.size(); i++)
            if(mCitizens[i] == p && p.mAge >= 18)
                mCitizens.erase(mCitizens.begin()+i);
    }
};

class Block: public Building{
private:
    uint16_t mMaxNumberPerFloor;
public:
    Block(string name, uint16_t numar_etaje, uint16_t nrmax) : Building(name,"Block") {
        mMaxNumberPerFloor = nrmax;
        mCitizens.clear();
        Person p;
        mCoordinator = p;
        mCitizens.resize(numar_etaje*mMaxNumberPerFloor);
        for(auto i : mCitizens)
            i = p;
    }
    Building * operator+(const Person& p) override{
        if(mCoordinator.mName.empty())
            mCoordinator = p;
        return this;
    }
    Building * operator-() override{
        Person p;
        mCoordinator = p;
        return this;
    }
    Building * operator-(const Person& p) override{
        return this;
    }
    void add(const Person& p) override{
        for(int i=0; i < mCitizens.size(); i++)
            if(mCitizens[i].mName.empty()){
                mCitizens[i] = p;
                break;
            }
    }
    void remove(const Person& p) override{
        Person pers;
        for(int i=0; i < mCitizens.size(); i++)
            if(mCitizens[i] == p && p.mAge >= 18)
                mCitizens[i] = pers;
    }
};

double average_salary(vector<Person> &vector){
    if(!vector.empty()) {
        double sum = 0, size = double(vector.size());
        for (auto i: vector)
            sum += i.mSalary;
        return sum / size;
    }
    else return 0;
}
double average_age(vector<Person> &vector){
    if(!vector.empty()) {
        double sum = 0, size = double(vector.size());
        for (auto i: vector)
            sum += i.mAge;
        return sum / size;
    }
    else return 0;
}

int main() {
    string comanda, numeCladire, tipCladire, a, numePersoana;
    uint16_t nrMaxLoc, etaje, varsta;
    double salariu;
    vector<Building *> v;
    while(cin >> comanda){
        if(comanda == "add"){
            cin >> a;
            if(a == "CityHall"){
                cin >> numeCladire;
                v.push_back(new CityHall(numeCladire));
            }
            if(a == "Hospital"){
                cin >> numeCladire;
                v.push_back(new Hospital(numeCladire));
            }
            if(a == "PoliceStation"){
                cin >> numeCladire;
                v.push_back(new PoliceStation(numeCladire));
            }
            if(a == "House"){
                cin >> numeCladire >> nrMaxLoc;
                v.push_back(new House(numeCladire,nrMaxLoc));
            }
            if(a == "Block"){
                cin >> numeCladire >> etaje >> nrMaxLoc ;
                v.push_back(new Block(numeCladire,etaje,nrMaxLoc));
            }
            if(a == "citizen"){
                cin >> numePersoana >> varsta >> salariu >> numeCladire;
                for(auto i : v){
                    if(i->getBuildingName() == numeCladire){
                        Person p(numePersoana,varsta,salariu);
                        i->add(p);
                    }
                }
            }
            if(a == "employee"){
                cin >> numePersoana >> varsta >> salariu >> numeCladire;
                for(auto  i : v){
                    if(i->getBuildingName() == numeCladire){
                        Person p(numePersoana,varsta,salariu);
                        i->operator+(p);
                    }
                }
            }
            if(a == "coordinator"){
                cin >> numePersoana >> varsta >> salariu >> numeCladire;
                Person p(numePersoana,varsta,salariu);
                for(auto i : v){
                    if(i->getBuildingName() == numeCladire){
                        if(i->getType() == "House" or i->getType() == "Block"){
                            if(i->getCoordinator().mAge == 0) {
                                i->operator+(p);
                                i->add(p);
                            }
                        }
                        else if(i->getType() == "CityHall"){
                            if(i->getCoordinator().mAge == 0) i->operator+(p);
                        }
                    }
                }
            }
        }
        else if(comanda == "remove"){
            cin >> a >> numePersoana >> numeCladire;
            if(a == "citizen"){
                for(auto i : v)
                    if(i->getBuildingName() == numeCladire)
                        for(int j=0; j<i->getCitizensSize(); j++)
                            if(i->getCitizen(j).mName == numePersoana)
                                i->remove(i->getCitizen(j));
            }
            else if(a == "employee"){
                for(auto i : v)
                    if(i->getBuildingName() == numeCladire)
                        for(int j=0; j<i->getEmployeesSize(); j++)
                            if(i->getEmployee(j).mName == numePersoana)
                                i->operator-(i->getEmployee(j));
            }
            else if(a == "coordinator"){
                for(auto i : v)
                    if(i->getBuildingName() == numeCladire){
                        if(i->getType() == "House" or i->getType() == "Block"){
                            for(int j=0; j<i->getCitizensSize(); j++)
                                if(i->getCitizen(j).mName == numePersoana) {
                                    i->remove(i->getCitizen(j));
                                    i->operator-();
                                }
                        }
                        else if(i->getType() == "CityHall"){
                            i->operator-();
                        }
                    }
            }
        }
    }
    int ct_cityhall=0, ct_hospital=0, ct_policestation=0, ct_house=0, ct_block=0,nr_patients_hospital=0;
    vector<string> administrators_house, administrators_block;
    vector<Person> doctors,cops,mayors,ch_employees,busted_policestation;
    map<string,int> nr_people_house;
    map<string,int> nr_people_block;
    for(auto i : v){
        if(i->getType() == "CityHall"){
            ct_cityhall++;
            if(i->getCoordinator().mAge != 0)
                mayors.push_back(i->getCoordinator());
            for(int j=0; j<i->getCitizensSize(); j++)
                ch_employees.push_back(i->getCitizen(j));
        }
        else if(i->getType() == "Hospital"){
            ct_hospital++;
            for(int j=0; j<i->getEmployeesSize(); j++)
                doctors.push_back(i->getEmployee(j));
            for(int j=0; j<i->getCitizensSize(); j++)
                nr_patients_hospital++;
        }
        else if(i->getType() == "PoliceStation"){
            ct_policestation++;
            for(int j=0; j<i->getEmployeesSize(); j++)
                cops.push_back(i->getEmployee(j));
            for(int j=0; j<i->getCitizensSize(); j++)
                busted_policestation.push_back(i->getCitizen(j));
        }
        else if(i->getType() == "House"){
            ct_house++;
            if(i->getCitizensSize() > 0)
                nr_people_house[i->getBuildingName()]+= i->getCitizensSize();
            administrators_house.push_back(i->getCoordinator().mName);
        }
        else if(i->getType() == "Block"){
            ct_block++;
            for(int j=0; j<i->getCitizensSize(); j++)
                if(i->getCitizen(j).mAge != 0) nr_people_block[i->getBuildingName()]++;
            administrators_block.push_back(i->getCoordinator().mName);
        }
    }
    if(ct_cityhall >= 3 and ct_hospital >= 2 and ct_policestation >= 3 and ct_house >= 8 and ct_block >= 4)
        cout << "Type: Capital\n";
    else if(ct_cityhall >= 2 and ct_hospital >= 1 and ct_policestation >= 2 and ct_house >= 4 and ct_block >= 1)
        cout << "Type: Town\n";
    else cout << "Type: Village\n";
    cout << "Number of patients in hospitals: " << nr_patients_hospital << endl;
    cout << "Average salary for doctors: " << average_salary(doctors) << endl;
    cout << "Average salary for cops: " << average_salary(cops) << endl;
    cout << "Average salary for mayors: " << average_salary(mayors) << endl;
    cout << "Average salary for city hall employees: " << average_salary(ch_employees) << endl;
    cout << "Average age of busted in police stations: " << average_age(busted_policestation) << endl;
    for(auto i : v){
        if(i->getType() == "House")
            cout << "Number of people in House " << i->getBuildingName() << ": " << nr_people_house[i->getBuildingName()] << endl;
        else if(i->getType() == "Block")
            cout << "Number of people in Block " << i->getBuildingName() << ": " << nr_people_block[i->getBuildingName()] << endl;
    }
    cout << "Administrators of house and block: ";
    int contor=0;
    for(auto i : administrators_house)
        for(auto j : administrators_block){
            if(i == j and i != ""){
                cout << i << " ";
                contor++;
                continue;
            }
        }
    if(contor==0) cout << "Nobody\n";
    return  0;
}