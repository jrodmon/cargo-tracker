// RodJaron Monteagudo
// March 22, 2022
// Inheritance and Virtualization

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int maxload737 = 46000;
const int maxload767 = 116000;

class Cargo{
protected:
    string uldtype;
    string abbrev;
    string uldid;
    int aircraft;
    double weight;
    string destination;

public:
    Cargo(); ///default constructor

    Cargo(string uldtype,
          string abrv,
          string uldid,
          int aircraft,
          const double weight,
          string destination); ///constructor

    ///copy constructor
    //Cargo(const Cargo &unit);


    ~Cargo(); ///destructor


    ///setters
    void setuldtype(string);
    void setabbrev(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdestination(string);

    ///getters
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdestination() const;

    virtual void maxweight();

    void input();
    void output();
};

///Boeing 737 subclass
//************************************************************
class Boeing737 : public Cargo{      //class boeing737 inherits Cargo functions;
private:
    int total737wt;
public:
    Boeing737();

    Boeing737(const string &uldtype,
                const string &abbrev,
                const string &uldid,
                const int &aircraft,
                const double &weight,
                const string &destination);

    ~Boeing737(){};

    void maxweight(double&, double, string); // overrides maxweight from Cargo class
};

///Boeing 767 subclass
//************************************************
class Boeing767 : public Cargo{      //class boeing767 inherits Cargo functions
private:
    int total767wt;
public:
    Boeing767();

    Boeing767(const string &uldtype,
                const string &abbrev,
                const string &uldid,
                const int &aircraft,
                const double &weight,
                const string &destination);

    ~Boeing767(){};

    void maxweight(double&, double, string);
};

void input();
void checkCraft(int);
void checkType(string);
void checkAbrv(string, int);
void vectorprint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767);

int main()
{
    Cargo unit1;

    unit1.input();
}

    ///default constructor
    //*******************************************************
    Cargo::Cargo()
    {
        uldtype = "XXX";
        abbrev = "XXX";
        uldid = "xxxxxIB";
        aircraft = 0;
        weight = 0.0;
        destination = "NONE";
    }

    ///copy constructor
    //******************************************************
/*
    Cargo::Cargo(const Cargo &unit1)
    {
        uldtype = unit1.uldtype;
        abbrev = unit1.abbrev;
        uldid = unit1.uldid;
        aircraft = unit1.aircraft;
        weight = unit1.weight;
        destination = unit1.destination;
    }
*/

    ///constructor
    //********************************************************
    Cargo::Cargo(const string type,
                 const string abrv,
                 const string id,
                 const int craft,
                 const double wt,
                 const string dest)
     {
        uldtype = type;
        abbrev = abrv;
        uldid = id;
        aircraft = craft;
        weight = wt;
        destination = dest;
     }

    ///destructor
    //******************************************************
    Cargo::~Cargo()
    {
        //cout << "\nCargo destructor called\n\n";
    }

    ///setters
    //****************************************************
    void Cargo::setuldtype(string type)
    {
        uldtype = type;
    }
    void Cargo::setabbrev(string abrv)
    {
        abbrev = abrv;
    }
    void Cargo::setuldid(string id)
    {
        uldid = id;
    }
    void Cargo::setaircraft(int craft)
    {
        aircraft = craft;
    }
    void Cargo::setweight(double wt)
    {
        //char ans;
        //cout << "is weight in kilos(K) or pounds(P)? ";
        //cin >> ans;
        //if (ans == 'k' || ans == 'K')
        //{
        //    weight = kilotolb(wt);
        //}
        //else
        //{
        weight = wt;
        //}
    }
    void Cargo::setdestination(string dest)
    {
        destination = dest;
    }

    ///getters
    //*****************************************************
    string Cargo::getuldtype() const
    {
        return uldtype;
    }
    string Cargo::getabbrev() const
    {
        return abbrev;
    }
    string Cargo::getuldid() const
    {
        return uldid;
    }
    int Cargo::getaircraft() const
    {
        return aircraft;
    }
    double Cargo::getweight() const
    {
        return weight;
    }
    string Cargo::getdestination() const
    {
        return destination;
    }

    ///output
    //**********************************************
    void Cargo::output()
    {         //fixed decimal format << shows decimal point, even if .0 << num of decimals to display
        cout << fixed << showpoint << setprecision(2);
        cout << setw(19) << "Unit load type: " << getuldtype() << endl;
        cout << setw(19) << "Unit abbreviation: " << getabbrev() << endl;
        cout << setw(19) << "Unit identifier: " << getuldid() << endl;
        cout << setw(19) << "Aircraft type: " << getaircraft() << endl;
        cout << setw(19) << "Weight: " << getweight() << endl;
        cout << setw(19) << "Destination code: " << getdestination() << endl << endl;
    }

///Boeing737 Constructor
//************************************************
    Boeing737::Boeing737(const string &type,
                         const string &abrv,
                         const string &id,
                         const int &craft,
                         const double &wt,
                         const string &dest)
    {
        uldtype = type;
        abbrev = abrv;
        uldid = id;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }

///Boeing767 Constructor
//******************************************************
    Boeing767::Boeing767(const string &type,
                         const string &abrv,
                         const string &id,
                         const int &craft,
                         const double &wt,
                         const string &dest)
    {
        uldtype = type;
        abbrev = abrv;
        uldid = id;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }

void load737(vector<Boeing737> &vectorptr737,
             const string type,
             const string abrv,
             const string id,
             const int craft,
             const double wt,
             const string dest,
             double &totwt737)
     {
        Boeing737 unitobj737(type, abrv, id, craft, wt, dest);      //declares object of class Boeing 737
        unitobj737.maxweight(totwt737, wt, id);         //call overridden maxweight virtual function
        vectorptr737.push_back(unitobj737);             //stores unitobj737 at the back of vectorptr737
     }

void load767(vector<Boeing767> &vectorptr767,
             const string type,
             const string abrv,
             const string id,
             const int craft,
             const double wt,
             const string dest,
             double &totwt767)
     {
        Boeing767 unitobj767(type, abrv, id, craft, wt, dest);
        unitobj767.maxweight(totwt767, wt, id);
        vectorptr767.push_back(unitobj767);
     }

     void Cargo::maxweight(){}   ///cargo class maxweight function (will not used)

/// maxweight function for 737

     void Boeing737::maxweight(double &totwt737, double wt, string id){
        if (totwt737 > maxload737){
            totwt737 -= wt;                                             //if the total weight is more than the maxload, removes the weight that was added
            throw runtime_error("Exceeded weight capacity for 737. Removing: " + id + "\n\n");
        }
     }

     void Boeing767::maxweight(double &totwt767, double wt, string id)
     {
        if (totwt767 > maxload767)
        {
            totwt767 -= wt;
            throw runtime_error("Exceeded weight capacity for 767. Removing: " + id + "\n\n");
        }
     }

    ///input data
    //***********************************************
    void Cargo::input()
    {
        string type;
        string abrv;
        string id;
        int craft;
        double wt;
        string dest;
        double totwt737 = 0;
        double totwt767 = 0;
        string datafile;
        ifstream inputFile;
        vector<Boeing737> vectorptr737;
        vector<Boeing767> vectorptr767;     //declaring variables

        do //start of do-while loop
        {
            try
            {                    //for throw and catch to detect errors
            inputFile.clear();
            cout << "Enter name of data file:\n";
            getline(cin, datafile);
            cout << "\nYou inputted: " << datafile << endl << endl;
            inputFile.open(datafile);
            if(!inputFile)
                {
                throw runtime_error("Unable to open file\n");           //what will be displayed if error occurs here
                //std::cerr << "Unable to open file" << endl;
                }
                cout << "Opening File: " << datafile << endl << endl;
            }
            catch(runtime_error& ex)
                {
                cout << ex.what();      //displays the error that occurred
                }
        }
        while(!inputFile); // end of do-while loop

        while (inputFile >> type)
        //while (inputFile.peek() != EOF)
        {
            try
            {
                //inputFile >> type;
                inputFile >> abrv;
                inputFile >> id;
                inputFile >> craft;
                inputFile >> wt;
                inputFile >> dest;

                checkType(type);
                checkCraft(craft);     //calls functions

                if(craft == 737)
                    {
                    checkAbrv(abrv, craft);
                    }
                totwt737 += wt;
                load737(vectorptr737, type, abrv, id, craft, wt, dest, totwt737);   //calls load function and inputs variables into unitobj737 object

                if (craft == 767)
                {
                    checkAbrv(abrv,craft);
                    totwt767 += wt;
                    if (totwt767 > maxload767)
                        {
                        totwt767 -= wt;
                        throw runtime_error("too heavy for 767\n\n");
                        }
                    load767(vectorptr767, type, abrv, id, craft, wt, dest, totwt767);   //loads variables into unitobj767 to be stored in vector
                }
            }
            catch(runtime_error &ex)
            {
                cout << ex.what();      //displays errors that occurred in
            }

        }
        inputFile.close();                          //after exiting while loop, closes data.txt
        vectorprint(vectorptr737, vectorptr767);
        cout << "737 Total weight is: " << totwt737 << endl;
        cout << "767 Total weight is: " << totwt767 << endl;
    }

    /// end of cargo::input


    void checkCraft(int craft)
    {
        if (craft != 737 && craft != 767)       //if aircraft is not 737 or 767, display this error
        {
            throw runtime_error(to_string(craft) + " is an Invalid Airplane type...Removing Entry.\n\n");
        }
    }

    void checkType(string type)     //if Type is not Container or Pallet, display this error
    {
        if(type != "Container" && type != "Pallet")
        {
            throw runtime_error(type + " Input invalid. Not a container or pallet.\n\n");
        }
    }

    void checkAbrv(string abrv, int craft)
    {
        if (craft == 767)
        {
            if (abrv != "AKE" &&
                abrv != "APE" &&
                abrv != "AKC" &&
                abrv != "AQP" &&
                abrv != "AQF" &&
                abrv != "AAP" &&
                abrv != "P1P" &&
                abrv != "P6P" )
            {
                throw runtime_error(abrv + " bad type for 767.\n\n");
            }
        }
    }

    void vectorprint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767)
    {
        for(int i = 0; i < vectorptr737.size(); i++)        //displays all objects in vectorpte737
        {
            cout << "737: Unit Number: " << i + 1 << endl;
            cout << fixed << setprecision(2);
            cout << setw(19) << "Unit load type: " << vectorptr737[i].getuldtype() << endl;
            cout << setw(19) << "Unit abbreviation: " << vectorptr737[i].getabbrev() << endl;
            cout << setw(19) << "Unit identifier: " << vectorptr737[i].getuldid() << endl;
            cout << setw(19) << "Aircraft type: " << vectorptr737[i].getaircraft() << endl;
            cout << setw(19) << "Weight: " << vectorptr737[i].getweight() << endl;
            cout << setw(19) << "Destination code: " << vectorptr737[i].getdestination() << endl << endl;
        }

        for(int i = 0; i < vectorptr767.size(); i++)        //displays vectorptr767
        {
            cout << "767: Unit Number: " << i + 1 << endl;
            cout << fixed << setprecision(2);
            cout << setw(19) << "Unit load type: " << vectorptr767[i].getuldtype() << endl;
            cout << setw(19) << "Unit abbreviation: " << vectorptr767[i].getabbrev() << endl;
            cout << setw(19) << "Unit identifier: " << vectorptr767[i].getuldid() << endl;
            cout << setw(19) << "Aircraft type: " << vectorptr767[i].getaircraft() << endl;
            cout << setw(19) << "Weight: " << vectorptr767[i].getweight() << endl;
            cout << setw(19) << "Destination code: " << vectorptr767[i].getdestination() << endl << endl;
        }
    }


/*
        while (inputFile.peek() != EOF) /// while inputFile is not at the end of file, run code
        {
            inputFile >> type;
            inputFile >> abrv;
            inputFile >> id;
            inputFile >> craft;
            inputFile >> wt;
            inputFile >> dest;
            inputFile.get(); ///removes endl from the previous line of code
                             // if line 250 is not commented out, runs the last set of cargo inputs twice

            Cargo temp(type, abrv, id, craft, wt, dest);
            temp.output();
        }
        inputFile.close();
    }
*/



/*      //manually input data
        cout << "---Please input load information---";
        cout << "\nContainer or pallet? ";
        cin >> type;
            setuldtype(type);
        cout << "\nUnit abbreviation? ";
        cin >> abrv;
            setabbrev(abrv);
        cout << "\nUnit id? ";
        cin >> id;
            setuldid(id);
        cout << "\nAircraft type? ";
        cin >> craft;
            setaircraft(craft);
        cout << "\nWeight? ";
        cin >> wt;
            setweight(wt);
        cout << "\nDestination? ";
        cin >> dest;
            setdestination(dest);
        cout << endl;
*/


/*
    ///conversion function
    //double kilotolb(double &inWeight)
    //{
    //    inWeight = inWeight * 2.2;
    //return inWeight;
    //}
*/
/*
    ///comparison operator
    //*****************************************************
    bool operator == (const Cargo &lhs, const Cargo &rhs)
    {
        return (lhs.abbrev == rhs.abbrev &&
                lhs.uldid == rhs.uldid &&
                lhs.uldtype == rhs.uldtype &&
                lhs.aircraft == rhs.aircraft &&
                lhs.weight == rhs.weight &&
                lhs.destination == rhs.destination);
    }
*/
