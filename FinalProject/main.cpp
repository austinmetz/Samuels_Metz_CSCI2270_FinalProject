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
    string choice;
    Heroes cd;

    ifstream inFile; //reading from our .txt file
    inFile.open("Heroes.txt");
    string line;

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
        cout<<"can't read file"<<endl;
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
        getline(cin,choice);

        if(choice == "1")
        {
            cd.printHeroes();
        }
        else if(choice == "2")
        {
            cout<<"Enter a Heroes name below to see their stats: "<<endl;
            //string dummy;
            string name;
            //getline(cin,dummy);
            getline(cin,name);
            cd.findHero(name);
            //cout<<"I'm here.";
            cout<<""<<endl;
        }
        else if(choice == "3")
        {
            //string dummy;
            string name;
            double winrate;
            int GPM;
            int XPM;
            double KDA;
            cout<<"Enter Hero Name"<<endl;
            //getline(cin, dummy);
            getline(cin, name);
            cout<<"Enter Hero Win Rate (use float)"<<endl;
            cin>>winrate;
            cout<<"Enter Hero Experience Per Minute (use integer)"<<endl;
            cin>>XPM;
            cout<<"Enter Hero Gold Per Minute (use integer)"<<endl;
            cin>>GPM;
            cout<<"Enter Hero Kill Death Assist Ratio (use float)"<<endl;
            cin>>KDA;
            cd.addHeroNode(name, winrate, XPM, GPM, KDA);
        }
        else if(choice == "4")
        {
            bool subRun = true;
            string subChoice;
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
                getline(cin,subChoice);
                if(subChoice == "1")
                {
                    //string dummy;
                    string name;
                    string newName;
                    cout<<"Enter hero name:"<<endl;
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new name:"<<endl;
                    getline(cin, newName);
                    cd.editName(name, newName);
                }
                else if(subChoice == "2")
                {
                    //string dummy;
                    string name;
                    double winrate;
                    cout<<"Enter hero name:"<<endl;
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new win rate:"<<endl;
                    cin>>winrate;
                    cd.editWR(name, winrate);
                }
                else if(subChoice == "3")
                {
                    //string dummy;
                    string name;
                    int experience;
                    cout<<"Enter hero name:"<<endl;
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new win rate:"<<endl;
                    cin>>experience;
                    cd.editXPM(name, experience);
                }
                else if(subChoice == "4")
                {
                    //string dummy;
                    string name;
                    int gold;
                    cout<<"Enter hero name:"<<endl;
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new gold per minute:"<<endl;
                    cin>>gold;
                    cd.editGPM(name, gold);
                }
                else if(subChoice == "5")
                {
                    //string dummy;
                    string name;
                    double killdeath;
                    cout<<"Enter hero name:"<<endl;
                    //getline(cin, dummy);
                    getline(cin, name);
                    cout<<"Enter new kill death assist ratio:"<<endl;
                    cin>>killdeath;
                    cd.editKDA(name, killdeath);
                }
                else if(subChoice == "6")
                {
                    subRun = false;
                }
                else
                {
                    cout<<"Sorry, wrong input"<<endl;
                    cout<<"Please re-enter your choice"<<endl;
                    getline(cin,choice);
                }
            }
        }
        else if(choice == "5")
        {
            cout<<"Enter a Heroes name to be deleted: "<<endl;
            //string dummy;
            string name;
            //getline(cin,dummy);
            getline(cin,name);
            cd.deleteHeroNode(name);
        }
        else if(choice == "6")
        {
            cout<<"GoodBYE!"<<endl;
            run = false;
        }
        else
        {
            cout<<"Sorry, wrong input"<<endl;
            cout<<"Please re-enter your choice"<<endl;
            getline(cin,choice);

        }
    }
    return 0;
}
