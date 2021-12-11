#ifndef WEIGHT_
#define WEIGHT_
#include "wrestler.h"


class weight
{
    public:
        weight();
        virtual ~weight();

        char Getwgtclass() { return wgtclass; }
        void Setwgtclass(char val) { wgtclass = val; }

        void wrestlerassig(wrestler * arr[], int wtrweight, wrestler * val);

        void addwrestler(wrestler * arr[], int index, wrestler * val);

        void lpsortgrps(wrestler * arr[]);

        void sortgrps(wrestler * arr[], int index);

        void lpdisplay(wrestler * arr[]);

        void display(wrestler * arr[], int index);

        void compete(wrestler * grpa[], wrestler * grpb[], default_random_engine * gptr, int numwtr);

    protected:

    private:
        char wgtclass;
        wrestler * lead;
        wrestler * follow;
};

#endif // WEIGHT_
