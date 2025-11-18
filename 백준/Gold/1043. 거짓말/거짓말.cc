#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<bool> knowns(n+1, false);
    int known; cin >> known;
    for (int i = 0 ; i < known; i++)
    {
        int num; cin >> num;
        knowns[num] = true;
    }

    cin.ignore();
    int result = 0;
    vector<vector<int>> parties(m);
    for (int i = 0; i < m; i++)
    {
        int partysize; cin >> partysize;
        parties[i].resize(partysize);
        for (int j = 0; j < partysize; j++)
        {
            cin >> parties[i][j];
        }
    }

    while (true)
    {
        bool bUpdated = false;
        for (int i = 0; i < m; i++)
        {
            bool bIsKnowtrue = false;
            for (const int partyperson : parties[i])
            {
                if (knowns[partyperson])
                {
                    bIsKnowtrue = true;
                    break;
                }
            }

            if (bIsKnowtrue)
            {
                for (const int partyperson : parties[i])
                {
                    if (!knowns[partyperson])
                    {
                        bUpdated = true;
                        knowns[partyperson] = true;
                    }
                }
            }
        }

        if (!bUpdated)
            break;
    }

    for (int i = 0; i < m; i++)
    {
        bool bKnownstrue = false;
        for (const int partyperson : parties[i])
        {
            if (knowns[partyperson])
            {
                bKnownstrue = true;
                break;
            }
        }

        if (!bKnownstrue)
            result++;
    }
    cout << result;
}