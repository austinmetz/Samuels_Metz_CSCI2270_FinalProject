#ifndef HEROES_H
#define HEROES_H
#include <iostream>

using namespace std;

struct HeroNode
{
    double winrate;
    int experience;
    int gold;
    double killdeath;
    string name;
    HeroNode *parent;
    HeroNode *leftChild;
    HeroNode *rightChild;

    HeroNode(){};

    HeroNode(string in_name, double in_winrate, int in_experience, int in_gold, double in_killdeath)
    {
        name = in_name;
        winrate = in_winrate;
        experience = in_experience;
        gold = in_gold;
        killdeath = in_killdeath;
    }
};


class Heroes
{
    public:
        Heroes();
        ~Heroes();
        void addHeroNode(string name, double winrate, int experience, int gold, double killdeath);
        void printHeroes();
        void findHero(string name);
        void deleteHeroNode(string name);
        void editName(string name, string newName);
        void editWR(string name, double newWR);
        void editXPM(string name, int newXPM);
        void editGPM(string name, int newGPM);
        void editKDA(string name, double newKDA);
    protected:
    private:
        void deleteAll(HeroNode *node);
        void printHeroes(HeroNode *node);
        HeroNode* search(string text);
        HeroNode *root;
        HeroNode *node;
        HeroNode *tmp;
        HeroNode *foundHero;
        HeroNode* treeMinimum(HeroNode *node);
        HeroNode* treeMaximum(HeroNode *node);
};

#endif // HEROES_H
