#include "Heroes.h"

Heroes::Heroes()
{
    root=NULL;
}

Heroes::~Heroes()
{
    deleteAll(root);
}

void Heroes::editName(string name, string newName)
{
    HeroNode *node;
    node = search(name);
    if(node != NULL)
    {
        node->name = newName;
    }
    else
    {
        cout<<"Hero not found."<<endl;
    }
}

void Heroes::editWR(string name, double newWR)
{
    HeroNode *node;
    node = search(name);
    if(node != NULL)
    {
        node->winrate = newWR;
    }
    else
    {
        cout<<"Hero not found."<<endl;
    }
}

void Heroes::editXPM(string name, int newXPM)
{
    HeroNode *node;
    node = search(name);
    if(node != NULL)
    {
        node->experience = newXPM;
    }
    else
    {
        cout<<"Hero not found."<<endl;
    }
}
void Heroes::editGPM(string name, int newGPM)
{
    HeroNode *node;
    node = search(name);
    if(node != NULL)
    {
        node->gold = newGPM;
    }
    else
    {
        cout<<"Hero not found."<<endl;
    };
}

void Heroes::editKDA(string name, double newKDA)
{
    HeroNode *node;
    node = search(name);
    if(node != NULL)
    {
        node->killdeath = newKDA;
    }
    else
    {
        cout<<"Hero not found."<<endl;
    }
}


void Heroes::printHeroes()
{
    printHeroes(root);
}

void Heroes::printHeroes(HeroNode *node)
{
    if(node->leftChild!=NULL)
    {
        printHeroes(node->leftChild);
    }
    cout<<"Hero: "<<node->name<<endl;
    if(node->rightChild!=NULL)
    {
        printHeroes(node->rightChild);
    }
}


void Heroes::addHeroNode(string name, double winrate, int experience, int gold, double killdeath)
{
    tmp=root;
    HeroNode *parent;
    HeroNode *node= new HeroNode(name, winrate, experience, gold, killdeath);
    node->parent;
    node->leftChild=NULL;
    node->rightChild=NULL;
    parent=NULL;

    while(tmp!=NULL)
    {
        parent=tmp;

        if(node->name < tmp->name)
        {
            tmp=tmp->leftChild;
        }
        else
        {
            tmp=tmp->rightChild;
        }
    }

    if(parent==NULL)
    {
        root=node;
    }
    else if(node->name.compare(parent->name)>0)
    {
       parent->rightChild=node;
       node->parent=parent;
    }
    else
    {
        parent->leftChild=node;
        node->parent=parent;
    }
}

HeroNode *Heroes::search(string text)
{
    foundHero=root;
    while(foundHero!=NULL)
    {
        if(foundHero->name.compare(text)==0)
        {
            return foundHero;
        }
        else if(foundHero->name.compare(text)>0)
        {
            foundHero=foundHero->leftChild;
        }
        else
        {
            foundHero=foundHero->rightChild;
        }
    }
    return NULL;
}

void Heroes::findHero(string name)
{
    HeroNode *foundHero;
    foundHero=search(name);
    if(foundHero!=NULL)
    {
        cout<<foundHero->name<<" statistics: "<<endl;
        cout<<"==================="<<endl;
        cout<<"Win Rate: "<<foundHero->winrate<<"%"<<endl;
        cout<<"Experience per minute: "<<foundHero->experience<<endl;
        cout<<"Gold per minute: "<<foundHero->gold<<endl;
        cout<<"Kill Death Assist Ratio: "<<foundHero->killdeath<<endl;
    }
    else
    {
        cout<<"Hero not found."<<endl;
    }
}

void Heroes::deleteHeroNode(string name)
{

    HeroNode *foundHero;
    foundHero=search(name);
    if(foundHero != NULL)
    {
        if(foundHero!=root)
        {
            if(foundHero->leftChild==NULL && foundHero->rightChild==NULL) //delete function with no children
            {
                if(foundHero->parent->rightChild==foundHero)
                {
                    foundHero->parent->rightChild=NULL;
                    //delete foundMovie;
                }
                else
                {

                    foundHero->parent->leftChild=NULL;
                   // delete foundMovie;
                }
            }

            else if(foundHero->leftChild!=NULL && foundHero->rightChild!=NULL)//delete function for two children
            {
                HeroNode *minHero=treeMinimum(foundHero->rightChild);
                if(foundHero->rightChild==minHero)
                {

                    foundHero->parent->leftChild=minHero;
                    minHero->parent=foundHero->parent;
                    foundHero->leftChild->parent=minHero;
                    minHero->leftChild=foundHero->leftChild;
                    //delete foundMovie;
                }
                else
                {
                    minHero->parent->leftChild=minHero->rightChild;
                    minHero->rightChild->parent=minHero->parent;
                    minHero->parent=foundHero->parent;
                    foundHero->parent->rightChild=minHero;
                    minHero->leftChild=foundHero->leftChild;
                    minHero->rightChild=foundHero->rightChild;
                    foundHero->rightChild->parent=minHero;
                    foundHero->leftChild->parent=minHero;
                    //delete foundMovie;
                }

            }

            else //one child
            {
                if(foundHero->leftChild == NULL)
                {
                    HeroNode *x=foundHero->rightChild;
                    if(foundHero->parent->rightChild==foundHero)
                    {
                        foundHero->parent->rightChild=x;
                    }
                    else
                    {
                        foundHero->parent->leftChild=x;
                    }
                    x->parent=foundHero->parent;
                }
                else
                {
                    HeroNode *x=foundHero->leftChild;
                    if(foundHero->parent->rightChild==foundHero)
                    {
                        foundHero->parent->rightChild=x;
                    }
                    else
                    {
                        foundHero->parent->leftChild=x;
                    }
                    x->parent=foundHero->parent;
                }
            }

          delete foundHero;
        }

        else
        {
            HeroNode *minHero=treeMinimum(foundHero->rightChild);
            if(foundHero->parent->rightChild==minHero)
            {
                minHero->leftChild=foundHero->leftChild;
                foundHero->leftChild->parent=minHero;
                root=minHero;
                //delete foundMovie;
            }
            else
            {
                minHero->rightChild->parent=minHero->parent;
                minHero->parent->leftChild=minHero->rightChild;
                minHero->leftChild=foundHero->leftChild;
                foundHero->leftChild->parent=minHero;
                root=minHero;
                delete foundHero;
            }
        }
    }

    else
    {
        cout<<"Hero not found."<<endl;
    }
}

HeroNode *Heroes::treeMinimum(HeroNode *node)
{
    while(node->leftChild!=NULL)
    {
        node=node->leftChild;
    }
    return node;
}

void Heroes::deleteAll(HeroNode *node)
{
    if(node->leftChild != NULL)
    {
        deleteAll(node->leftChild);
    }
    if(node->rightChild != NULL)
    {
        deleteAll(node->rightChild);
    }
    cout<<"Deleting: "<<node->name<<endl;
    delete node;
}
