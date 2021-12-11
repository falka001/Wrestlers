#ifndef WRESTLER_
#define WRESTLER_
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class wrestler
{
    public:
        wrestler();
        virtual ~wrestler();
        wrestler(const wrestler& other);
        wrestler& operator=(const wrestler& other);
        bool operator>(const wrestler& rhs)const;

        int Getid() { return id; };
        void Setid(int val) { id = val; };

        int Getiqscore() { return iqscore; };
        void Setiqscore(int val) { iqscore = val; };

        int Getweight() { return weight; };
        void Setweight(int val) { weight = val; };

        wrestler * Getnext() { return next; };
        void Setnext(wrestler * val) { next = val; };

        wrestler * Gethead() { return head; };
        void Sethead(wrestler * val) { head = val; };


        wrestler * Getcurr() { return curr; };
        void Setcurr(wrestler * val) { curr = val; };

        void addwrestler(double wgt, double ascore);

        void display();

    protected:

    private:
        int id;
        double iqscore;
        double weight;
        wrestler * next;
        wrestler * head;
        wrestler * curr;
        wrestler * last;
};

#endif // WRESTLER_
