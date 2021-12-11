#include "weight.h"
#include <cmath>

weight::weight()
{
    //ctor
}

weight::~weight()
{
    //dtor
}

void weight::wrestlerassig(wrestler * arr[], int wtrweight, wrestler * val)
{
    int index;
    if (wtrweight>87 && wtrweight<=106) { index = 0; }
    else if (wtrweight>107 && wtrweight<=113) { index = 1; }
    else if (wtrweight>114 && wtrweight<=120) { index = 2; }
    else if (wtrweight>121 && wtrweight<=126) { index = 3; }
    else if (wtrweight>127 && wtrweight<=132) { index = 4; }
    else if (wtrweight>133 && wtrweight<=138) { index = 5; }
    else if (wtrweight>139 && wtrweight<=145) { index = 6; }
    else if (wtrweight>146 && wtrweight<=152) { index = 7; }
    else if (wtrweight>153 && wtrweight<=160) { index = 8; }
    else if (wtrweight>161 && wtrweight<=170) { index = 9; }
    else if (wtrweight>171 && wtrweight<=180) { index = 10; }
    else if (wtrweight>181 && wtrweight<=195) { index = 11; }
    else if (wtrweight>196 && wtrweight<=220) { index = 12; }
    else if (wtrweight>221 && wtrweight<=285) { index = 13; }

    weight::addwrestler(arr, index, val);
}

void weight::addwrestler(wrestler * arr[], int index, wrestler * val)
{
    if(arr[index]==NULL) { arr[index] = val; }
    else { val->Setnext(arr[index]);
            arr[index] = val; }
}

void weight::sortgrps(wrestler * arr[], int index)
{
    wrestler * prev;
    wrestler * prev2;

    prev = arr[index];
    prev2 = arr[index];
    if (prev == NULL) { return; }
    follow = prev->Getnext();

    if (follow == NULL) { return; }
    while(follow != NULL) {
        if(*prev > *follow){prev2 = prev;
                            prev = follow;
                            follow = follow->Getnext();}
        else {
            if(prev == arr[index]) {
                prev->Setnext(follow->Getnext());
                follow->Setnext(prev);
                arr[index] = follow;

                ///----start over
                prev = arr[index];
                prev2 = arr[index];
                follow = arr[index]->Getnext();
            }
            else{
                ///swap prev and follow
                prev2->Setnext(follow);
                prev->Setnext(follow->Getnext());
                follow->Setnext(prev);

                ///-----start over
                prev = arr[index];
                prev2 = arr[index];
                follow = arr[index]->Getnext();
            }
        }
    }
}

void weight::lpsortgrps(wrestler * arr[])
{
    for(int i=0; i<14; i++) {
        weight::sortgrps(arr, i);
    }
}

void weight::display(wrestler * arr[], int index)
{
    wrestler * temp = NULL;
    temp = arr[index];
    int j = 1;
    cout<<"Wrestlers belonging to group #"<<index<<endl;
    while (temp != NULL) {
        cout<<"Wrestler #"<<j<<endl;
        cout<<"           has a weight: "<<temp->Getweight()<<" lbs"<<endl;
        cout<<"           has an ability score: "<<temp->Getiqscore()<<" iq"<<endl;
        temp = temp->Getnext();
        j++;
    }
}

void weight::lpdisplay(wrestler * arr[])
{
    cout<<"-------------------------------------------------------"<<endl;
    /// Displaying groups and assigned wrestlers
    for (int i=0; i<14; i++) {
        weight::display(arr, i);
        cout<<endl;
    }
}

void weight::compete(wrestler * grpa[], wrestler * grpb[], default_random_engine * gptr, int numwtr)
{
    double score1;
    double score2;
    int difference;
    int points;
    int tptsa = 0, tptsb = 0;
    for (int i=0; i<14; i++) {
        if(grpa[i] != NULL && grpb[i] != NULL) {
            double ab1 = grpa[i] ->Getiqscore();
            double ab2 = grpb[i] ->Getiqscore();
            normal_distribution<double> d1dist(ab1, 15);
            normal_distribution<double> d2dist(ab2, 15);
            score1 = d1dist(*gptr);
            score2 = d2dist(*gptr);
            cout<<endl<<"Wrestlers with the highest ability score from each team will compete:"<<endl;
            cout<<endl<<"          first wrestler from Group #"<<i<<" from Team A:"<<endl;
            cout<<"                     has a weight: "<<grpa[i]->Getweight()<<" lbs"<<endl;
            cout<<"                     has an ability score: "<<grpa[i]->Getiqscore()<<" iq"<<endl;
            cout<<endl<<"          first wrestler from Group #"<<i<<" from Team B:"<<endl;
            cout<<"                     has a weight: "<<grpb[i]->Getweight()<<" lbs"<<endl;
            cout<<"                     has an ability score: "<<grpb[i]->Getiqscore()<<" iq"<<endl<<endl;
            difference = score1 - score2;
            if(difference>0){
                /// Team A
                if(difference>=1 && difference<=5) { points = 3; }
                else if (difference>=6 && difference<=8) { points = 4; }
                else if (difference>=9 && difference<=14) { points = 5; }
                else if (difference>= 15) { points = 6; }
                cout<<"Wrestler from Team A won with "<<points<<" points"<<endl;
                cout<<"-----------------------------------------------------------------------------"<<endl;
                tptsa = tptsa + points;
            }
            else if (difference<0){
                /// Team B
                if(difference>=1 && difference<=5) { points = 3; }
                else if (difference>=6 && difference<=8) { points = 4; }
                else if (difference>=9 && difference<=14) { points = 5; }
                else if (difference>= 15) { points = 6; }
                cout<<"Wrestler from Team B won with "<<points<<" points"<<endl;
                cout<<"-----------------------------------------------------------------------------"<<endl;
                tptsb = tptsb + points;
            }
            else if (difference=0){
                cout<<"It's a tie!"<<endl;
                cout<<"-----------------------------------------------------------------------------"<<endl;
            }
        }
        else {
            if(grpa[i] == NULL && grpb[i] != NULL) { points = 6; }
            else if (grpa[i] != NULL && grpb[i] == NULL) { points = -6; }
            else if (grpa[i] == NULL && grpb[i] == NULL) { points = 0; }

            if(points > 0) { cout<<"No Wrestlers exist in this group for Team B"<<endl<<endl<<"Wrestler from Team A won with 6 points"<<endl;
                            cout<<"-----------------------------------------------------------------------------"<<endl;
                            tptsa = tptsa + points; }
            else if(points < 0) { cout<<"No Wrestlers exist in this group for Team A"<<endl<<endl<<"Wrestler from Team B won with 6 points"<<endl;
                                cout<<"-----------------------------------------------------------------------------"<<endl;
                                tptsb = tptsb + abs(points); }
            else if(points = 0) { cout<<"No Wrestlers exist in this group"<<endl;
                                cout<<"-----------------------------------------------------------------------------"<<endl;}
        }
    }
    cout<<endl<<"Team A has a total of: "<<tptsa<<" points"<<endl;
    cout<<endl<<"Team B has a total of: "<<tptsb<<" points"<<endl;
    if(tptsa > tptsb) { cout<<endl<<"Team A is the winner"<<endl; }
    else { cout<<endl<<"Team B is the winner"<<endl; }
}
