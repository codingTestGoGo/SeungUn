#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    int maxa, maxb, maxc, mina, minb, minc;
    int befmaxa, befmaxb, befmaxc, befmina, befminb, befminc;
    befmaxa = a; befmaxb = b; befmaxc = c;
    befmina = a; befminb = b; befminc = c;
    maxa = a; maxb = b; maxc = c;
    mina = a; minb = b; minc = c;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        maxa = max(befmaxa, befmaxb) + a;
        maxb = max(befmaxa, max(befmaxb, befmaxc)) + b;
        maxc = max(befmaxb, befmaxc) + c;
        befmaxa = maxa;
        befmaxb = maxb;
        befmaxc = maxc;

        mina = min(befmina, befminb) + a;
        minb = min(befmina, min(befminb, befminc)) + b;
        minc = min(befminb, befminc) + c;
        befmina = mina;
        befminb = minb;
        befminc = minc;
    }

    cout << max(maxa, max(maxb, maxc)) << ' ' << min(mina, min(minb, minc));
}