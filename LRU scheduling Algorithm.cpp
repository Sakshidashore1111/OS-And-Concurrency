#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4};
    int frames = 3;

    vector<int> memory;
    vector<int> recent;

    int faults = 0;

    for (int page : pages)
    {
        bool found = false;

        for (int x : memory)
        {
            if (x == page)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            faults++;

            if (memory.size() < frames)
            {
                memory.push_back(page);
            }
            else
            {
                int lru = recent[0];

                for (int i = 0; i < memory.size(); i++)
                {
                    if (memory[i] == lru)
                    {
                        memory[i] = page;
                        break;
                    }
                }

                recent.erase(recent.begin());
            }
        }

        recent.erase(remove(recent.begin(), recent.end(), page), recent.end());
        recent.push_back(page);

        cout << "Frames: ";
        for (int x : memory)
            cout << x << " ";
        cout << endl;
    }

    cout << "\nPage Faults = " << faults << endl;
}
