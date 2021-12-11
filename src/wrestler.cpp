#include "wrestler.h"

wrestler::wrestler()
{
    next = NULL;
    head = NULL;
    curr = NULL;
}

wrestler::~wrestler()
{
    //dtor
}

wrestler::wrestler(const wrestler& other)
{
    weight = other.weight;
    iqscore = other.iqscore;
    next = other.next;
}

wrestler& wrestler::operator=(const wrestler& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    else {
        weight = rhs.weight;
        iqscore = rhs.iqscore;
    }
    return *this;
}

bool wrestler::operator> (const wrestler& rhs)const
{
    if(this->iqscore >= rhs.iqscore) { return true; }
    else { return false; }
}

void wrestler::addwrestler(double wgt, double ascore)
{
    if (head == NULL) {
        head = new wrestler;
        head ->Setweight(wgt);
        head ->Setiqscore(ascore);
        last = head;
    }
    else {
        curr = new wrestler;
        curr -> Setweight(wgt);
        curr -> Setiqscore(ascore);
        last -> Setnext(curr);
        last = curr;
    }
    cout<<"wrestler"<<endl;
}

void wrestler::display()
{
    wrestler * temp = NULL;
    temp = head;
    while (temp != NULL) {
        cout<<temp->Getweight()<<" lbs  --  "<<temp->Getiqscore()<<" iq"<<endl;
        temp = temp->Getnext();
    }
}
