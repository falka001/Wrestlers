#include <iostream>
#include <ctime>
#include "weight.h"

using namespace std;

int main()
{
    wrestler w;
    weight wg;
    wrestler * grpa[14];
    wrestler * grpb[14];

    default_random_engine * gptr;
    gptr = new default_random_engine (time(NULL));

    normal_distribution<double> wdist(155, 20);
    normal_distribution<double> iqdist(100, 15);

    double W;
    double IQ;

    int numwtr;
    cout<<"how many wrestlers are in the team?"<<endl;
    cin>>numwtr;

    for (int i = 0; i<14; i++) {
        grpa[i]=NULL;
        grpb[i]=NULL;
    }

    wrestler * lead;
    for(int i=0; i<numwtr; i++) {
        W = wdist(*gptr);
        IQ = iqdist(*gptr);
        ///w.addwrestler(W, IQ);  ---- uncomment this part and comment all parts below if you want to test only one list of wrestlers

        lead = new wrestler;
        lead->Setweight(W);
        lead->Setiqscore(IQ);
        ///cout<<"wrestler has a weight of "<<lead->Getweight()<<" lbs"<<endl;
        ///cout<<"             an ability score of "<<lead->Getiqscore()<<endl<<endl;
        wg.wrestlerassig(grpa, lead->Getweight(), lead);
    }

    for(int i=0; i<numwtr; i++) {
        W = wdist(*gptr);
        IQ = iqdist(*gptr);
        ///w.addwrestler(W, IQ);  ---- uncomment this part and comment all parts below if you want to test only one list of wrestlers

        lead = new wrestler;
        lead->Setweight(W);
        lead->Setiqscore(IQ);
        ///cout<<"wrestler has a weight of "<<lead->Getweight()<<" lbs"<<endl;
        ///cout<<"             an ability score of "<<lead->Getiqscore()<<endl<<endl;
        wg.wrestlerassig(grpb, lead->Getweight(), lead);
    }

    /// Displaying wrestlers in each group
    cout<<endl<<"Wrestlers Group A:"<<endl<<endl;
    wg.lpdisplay(grpa);
    wg.lpsortgrps(grpa);

    cout<<"Group A Sorted:"<<endl<<endl;
    wg.lpdisplay(grpa);

    cout<<"-------------------------------------------------------"<<endl;
    cout<<endl<<"Wrestlers for Group B:"<<endl<<endl;
    wg.lpdisplay(grpb);
    wg.lpsortgrps(grpb);

    cout<<"Group B Sorted:"<<endl<<endl;
    wg.lpdisplay(grpb);

    wg.compete(grpa, grpb, gptr, numwtr);

    return 0;
}
