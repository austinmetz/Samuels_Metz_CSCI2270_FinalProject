#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "Heroes.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    bool run = true;
    int choice;
    Heroes cd;
    string mychoicestr;

    ifstream inFile; //reading from our .txt file
    inFile.open("Heroes.txt");
    string line;
    string name;

    if(inFile.is_open())
    {
        while(getline(inFile,line))
        {
            unsigned long comma_pos=line.find(",");
            string name = line.substr(0,comma_pos);
            string q = line.substr(comma_pos+1,string::npos);
            unsigned long comma_pos2=q.find(",");
            string WinratE=q.substr(0,comma_pos2);
            double winrate = atof(WinratE.c_str());
            string n=q.substr(comma_pos2+1, string::npos);
            unsigned long comma_pos3=n.find(",");
            string ExperiencE=n.substr(0,comma_pos3);
            int experience=atoi(ExperiencE.c_str());
            string z=n.substr(comma_pos3+1, string::npos);
            unsigned long comma_pos4=z.find(",");
            string GolD=z.substr(0,comma_pos4);
            int gold=atoi(GolD.c_str());
            string KilldeatH= z.substr(comma_pos4+1, string::npos);
            double killdeath = atof(KilldeatH.c_str());

            cd.addHeroNode(name,winrate,experience,gold,killdeath);

        }
    }

    else
    {
        cout<<"cant read file"<<endl;
    }

    while(run == true)
    {
        cout<<"DOTA BUFF STATISTICS"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1. Print Heroes"<<endl;
        cout<<"2. Search for a Hero"<<endl;
        cout<<"3. Add a Hero"<<endl;
        cout<<"4. Edit a Hero's stats"<<endl;
        cout<<"5. Delete a Hero"<<endl;
        cout<<"6. Quit"<<endl;
        getline(cin, mychoicestr);
        stringstream(mychoicestr) >> choice;

        if(choice == 1)
        {
            cd.printHeroes();
        }
        else if(choice == 2)
        {
            cout<<"Enter a Heroes name to see their stats: ";
            //string dummy; not sure why you needed a dummy variable?
            string name;
            //getline(cin,dummy);
            getline(cin,name);
            cd.findHero(name);
            cout<<""<<endl;
        }
        else if(choice == 3)
        {
            string dummy;
            string name;
            double winrate;
            int GPM;
            int XPM;
            double KDA;
            cout<<"Enter Hero Name: ";
            //getline(cin, dummy);
            getline(cin, name);
            cout<<"Enter Hero Win Rate (Number only): ";
            cin>>winrate;
            cout<<"Enter Hero Experience Per Minute (Number only): ";
            getline(cin, dummy);
            getline(cin, mychoicestr);
            stringstream(mychoicestr) >> XPM;
            //cin>>XPM;
            cout<<"Enter Hero Gold Per Minute (Number only): ";
            getline(cin, mychoicestr);
            stringstream(mychoicestr) >> GPM;
            //cin>>GPM;
            cout<<"Enter Hero Kill Death Assist Ratio (Numbers only): ";
            cin>>KDA;
            cd.addHeroNode(name, winrate, XPM, GPM, KDA);
            getline(cin, dummy);
        }
        else if(choice == 4)
        {
            bool subRun = true;
            int subChoice;
            while(subRun == true)
            {
                cout<<"Hero Stat Editor"<<endl;
                cout<<"----------------"<<endl;
                cout<<"1. Edit Name"<<endl;
                cout<<"2. Edit Win Rate"<<endl;
                cout<<"3. Edit Experience Per Minute"<<endl;
                cout<<"4. Edit Gold Per Minute"<<endl;
                cout<<"5. Edit Kill Death Assist Ratio"<<endl;
                cout<<"6. Return to Main Menu"<<endl;
                getline(cin, mychoicestr);
                stringstream(mychoicestr) >> subChoice;
                //cin>>subChoice;
                if(subChoice == 1)
                {
                    //string dummy;
                    string name;
                    string newName;
                    cout<<"Enter hero name: ";
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new name: ";
                    getline(cin, newName);
                    cd.editName(name, newName);
                }
                else if(subChoice == 2)
                {
                    string dummy;
                    string name;
                    double winrate;
                    cout<<"Enter hero name: ";
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new win rate (Numbers only): ";
                    cin >> winrate;
                    //cin>>winrate;
                    cd.editWR(name, winrate);
                    getline(cin, dummy);
                }
                else if(subChoice == 3)
                {
                    string dummy;
                    string name;
                    int experience;
                    cout<<"Enter hero name: ";
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new experience per minute: "; //corrected error here (was "Enter new win rate")
                    getline(cin, mychoicestr);
                    stringstream(mychoicestr) >> experience;
                    //cin>>experience;
                    cd.editXPM(name, experience);
                }
                else if(subChoice == 4)
                {
                    string dummy;
                    string name;
                    int gold;
                    cout<<"Enter hero name: ";
                    //etline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new gold per minute: ";
                    getline(cin, mychoicestr);
                    stringstream(mychoicestr) >> gold;
                    //cin>>gold;
                    cd.editGPM(name, gold);
                }
                else if(subChoice == 5)
                {
                    string dummy;
                    string name;
                    double killdeath;
                    cout<<"Enter hero name: ";
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new kill death assist ratio: ";
                    getline(cin, mychoicestr);
                    stringstream(mychoicestr) >> killdeath;
                    //cin>>killdeath;
                    cd.editKDA(name, killdeath);
                }
                else if(subChoice == 6)
                {
                    subRun = false;
                }
                else
                {
                    cout<<"Sorry, wrong input"<<endl;
                    cout<<"Please re-enter your choice: "<<endl;
                    //getline(cin, mychoicestr);
                    //stringstream(mychoicestr) >> choice;
                    //cin>>choice;
                }
            }
        }
        else if(choice == 5)
        {
            cout<<"Enter a Heroes name to be deleted: ";
            string dummy;
            string name;
            //getline(cin,dummy);
            getline(cin,name);
            cd.deleteHeroNode(name);
        }
        else if(choice == 6)
        {
            cout<<"GoodBYE!"<<endl; //lol
            run = false;
        }
        else
        {
            cout<<"Sorry, wrong input"<<endl;
            cout<<"Please re-enter your choice: ";
            /*getline(cin, mychoicestr);
            stringstream(mychoicestr) >> choice;
            //cin>>choice;
            */

        }
        choice=0;
    }
    return 0;
}
