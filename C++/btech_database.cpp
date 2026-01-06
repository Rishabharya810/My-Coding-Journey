#include <iostream>
using namespace std;

class Btech
{
public:
    // private:
    int rollno;
    string name;
    int dbms, coa, am, cs, oops, toc;

    // public:
    int getroll()
    {
        return this->rollno;
    }

    string getname()
    {
        return this->name;
    }

    int getdbms()
    {
        return this->dbms;
    }

    int getcoa()
    {
        return this->coa;
    }

    int getam()
    {
        return this->am;
    }

    int getcs()
    {
        return this->cs;
    }

    int getoops()
    {
        return this->oops;
    }

    int gettoc()
    {
        return this->toc;
    }

    void setroll(int roll)
    {
        this->rollno = roll;
    }

    void setname(string name)
    {
        this->name = name;
    }

    void setdbms(int dbms)
    {
        this->dbms = dbms;
    }

    void setcoa(int coa)
    {
        this->coa = coa;
    }

    void setam(int am)
    {
        this->am = am;
    }

    void setcs(int cs)
    {
        this->cs = cs;
    }

    void setoops(int oops)
    {
        this->oops = oops;
    }

    void settoc(int toc)
    {
        this->toc = toc;
    }
};

class student : public Btech
{
    int a;
};

class year_2nd : public student
{
    int b;
};

class semester_4th : public year_2nd
{
};

int main()
{

    semester_4th abcd[100];
    int ch = 1, n = 0, r = 0, a = 0, x = 0, y = 0;
    int rollno;
    string name;
    int dbms, coa, am, cs, oops, toc;

    cout << "________________________________________________________________________________________________________________________________________________________________" << endl
         << endl;
    cout << "-----------------------------------------------------------------    WELCOME TO THE PROGRAM    -----------------------------------------------------------------" << endl;
    cout << "________________________________________________________________________________________________________________________________________________________________" << endl
         << endl;

    do
    {

        cout << "Press the required option to perform:" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Update" << endl;
        cout << "4. Show" << endl;
        cout << "5. End program" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            do
            {
                cout << "Enter the number of records you want to Enter" << endl;
                cin >> n;
                y = 0;
                if (n > 0 && n < 6)
                {
                    for (int i = 0; i < n; i++)
                    {

                        cout << endl
                             << "Enter name:" << endl;
                        cin >> name;
                        abcd[i].setname(name);
                        cout << "Enter roll number:" << endl;
                        cin >> rollno;
                        abcd[i].setroll(rollno);
                        cout << "Enter marks in DBMS:" << endl;
                        cin >> dbms;
                        abcd[i].setdbms(dbms);
                        cout << "Enter marks in COA:" << endl;
                        cin >> coa;
                        abcd[i].setcoa(coa);
                        cout << "Enter marks in AM:" << endl;
                        cin >> am;
                        abcd[i].setam(am);
                        cout << "Enter marks in CS:" << endl;
                        cin >> cs;
                        abcd[i].setcs(cs);
                        cout << "Enter marks in OOPS:" << endl;
                        cin >> oops;
                        abcd[i].setoops(oops);
                        cout << "Enter marks in TOC:" << endl;
                        cin >> toc;
                        abcd[i].settoc(toc);
                        cout << "Adding new data" << endl;
                    }
                }
                else
                {
                    y++;
                }
            } while (y != 0);

            break;

        case 2:
            cout << "Enter roll number to delete" << endl;
            cin >> r;
            x = 0;
            for (int i = 0; i < n; i++)
            {
                x = abcd[i].getroll();
                if (x != r)
                {
                    i++;
                }
                else
                {
                    a = i;
                    i = n;
                }
            }
            cout << endl
                 << "Deleting the data with roll number " << r << endl
                 << endl;
            for (int i = a; i < n; i++)
            {
                abcd[a] = abcd[a + 1];
            }

            break;

        case 3:
            int u;
            cout << "Enter roll number to update";
            cin >> r;

            x = 0;
            for (int i = 0; i < n; i++)
            {
                x = abcd[i].getroll();
                if (x != r)
                {
                    i++;
                }
                else
                {
                    a = i;
                    i = n;
                    // cout<<" a "<<a<<" i "<<i;
                }
            }

            cout << " What do you want to update ?" << endl;
            cout << "------------------------------" << endl;
            cout << "1. Update name" << endl;
            cout << "2. Update roll number " << endl;
            cout << "3. Update marks in DBMS" << endl;
            cout << "4. Update marks in COA" << endl;
            cout << "5. Update marks in AM" << endl;
            cout << "6. Update marks in CS" << endl;
            cout << "7. Update marks in OOPS" << endl;
            cout << "8. Update marks in TOC" << endl;
            cin >> u;

            switch (u)
            {
            case 1:
                cout << "Enter new name: " << endl;
                cin >> name;
                abcd[a].setname(name);
                break;

            case 2:
                cout << "Enter new roll number: " << endl;
                cin >> rollno;
                abcd[a].setroll(rollno);
                break;

            case 3:
                cout << "Enter new marks in DBMS " << endl;
                cin >> dbms;
                abcd[a].setdbms(dbms);
                break;

            case 4:
                cout << "Enter new marks in COA " << endl;
                cin >> coa;
                abcd[a].setcoa(coa);
                break;

            case 6:
                cout << "Enter new marks in AM: " << endl;
                cin >> am;
                abcd[a].setam(am);
                break;

            case 7:
                cout << "Enter new marks in CS: " << endl;
                cin >> cs;
                abcd[a].setcs(cs);
                break;
            case 8:
                cout << "Enter marks in OOPS: " << endl;
                cin >> oops;
                abcd[a].setoops(cs);
                break;

            default:
                cout << "Wrong input" << endl;
                break;
            }

            break;

        case 4:
            cout << "Enter the roll number to show" << endl;
            cin >> r;
            x = 0;
            for (int i = 0; i < n; i++)
            {
                x = abcd[i].getroll();
                if (x != r)
                {
                    i++;
                }
                else
                {
                    a = i;
                    i = n;
                }
            }
            if (abcd[a].getroll() == 0)
            {
                cout << "NO such data found " << endl;
            }
            else
            {
                cout << "Displaying data.." << endl
                     << endl;
                cout << "Name: " << abcd[a].getname() << endl;
                cout << "Roll number: " << abcd[a].getroll() << endl;
                cout << "DBMS: " << abcd[a].getdbms() << endl;
                cout << "COA: " << abcd[a].getcoa() << endl;
                cout << "AM: " << abcd[a].getam() << endl;
                cout << "CS: " << abcd[a].getcs() << endl;
                cout << "OOPS: " << abcd[a].getoops() << endl;
                cout << "TOC: " << abcd[a].gettoc() << endl
                     << endl;
            }
            break;

        case 5:
            cout<<"n "<<n<<endl;
            for(int i=0;i<n;i++)
            {   
                cout << "Displaying data.." << endl
                     << endl;
                cout << "Name: " << abcd[i].getname() << endl;
                cout << "Roll number: " << abcd[i].getroll() << endl;
                cout << "DBMS: " << abcd[i].getdbms() << endl;
                cout << "COA: " << abcd[i].getcoa() << endl;
                cout << "AM: " << abcd[i].getam() << endl;
                cout << "CS: " << abcd[i].getcs() << endl;
                cout << "OOPS: " << abcd[i].getoops() << endl;
                cout << "TOC: " << abcd[i].gettoc() << endl
                     << endl;

            }
            // ch = 5;
             break;

        default:
            cout << "Wrong input" << endl;
            break;
        }
    } while (ch <= 4);

    cout << "Program runs successfully";
    return 0;
}