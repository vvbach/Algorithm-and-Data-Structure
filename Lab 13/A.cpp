#include <iostream>
#include <vector>

using namespace std;

int hashFunc(long long int key, int i, int size)
{
    return (key + i * i) % size;
}

void insert(vector<pair<long long int, int>> &tableX, vector<pair<long long int, int>> &tableY, long long int x, long long int y, int size)
{
    int i = 0;
    int key;
    bool inserted = false;
    while (1)
    {
        key = hashFunc(x, i, size);
        if (tableX[key].first == -1)
        {
            break;
        }
        if (tableX[key].first == x) {
            tableX[key].second++;
            inserted = true;
            break;
        }
        i++;
    }
    if (!inserted) tableX[key] = {x, 1};
    inserted = false;
    i = 0;
    while (1)
    {
        key = hashFunc(y, i, size);
        if (tableY[key].first == -1)
        {
            break;
        }
        if (tableY[key].first == y) {
            tableY[key].second++;
            inserted = true;
            break;
        }
        i++;
    }
    if (!inserted) tableY[key] = {y, 1};
}

int search(vector<pair<long long int, int>> &table, int coordinate, int size)
{
    int count = 0;
    int i = 0;
    int key;
    while (1)
    {
        key = hashFunc(coordinate, i, size);
        if (table[key].first == -1)
        {
            break;
        }
        else if (table[key].first == coordinate)
        {
            return table[key].second;
        }
        i++;
    }
    return 0;
}

int main()
{   
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int maxSize = 500000;
    vector<pair<long long int, int>> tableX(maxSize, {-1, -1}), tableY(maxSize, {-1, -1});
    int a, b;
    vector<pair<long long int, long long int>> point;
    vector<bool> deleted;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        insert(tableX, tableY, a, b, maxSize);
        point.push_back({a, b});
    }
    int result = 0;
    for (int k = 0; k < 3; k++)
    {
        if (point.size() == 0) continue;
        int choice;
        int MaxPairX = 0;
        int x;
        for (int i = 0; i < point.size(); i++)
        {

            int t = search(tableX, point[i].first, maxSize);
            if (MaxPairX < t)
            {
                MaxPairX = t;
                x = point[i].first;
            }
        }
        int MaxPairY = 0;
        int y;
        for (int i = 0; i < point.size(); i++)
        {
            int t = search(tableY, point[i].second, maxSize);
            if (MaxPairY < t)
            {
                MaxPairY = t;
                y = point[i].second;
            }
        }
        if (MaxPairX >= MaxPairY)
        {
            choice = 1;
        }
        else
            choice = 2;

        if (choice == 1)
        {
            int i = 0;
            
            while (1)
            {   
                int key = hashFunc(x, i, maxSize);
                if (tableX[key].first == x)
                {
                    tableX[key].first = -2;
                    tableX[key].second = -2;
                    break;
                }
                i++;
            }
            auto iter = point.begin();
            while (iter != point.end()){
                if (iter->first == x){  
                    point.erase(iter);
                    continue;
                }
                iter++;
            }
            result += MaxPairX;
        }
        else
        {
            int i = 0;
            while (1)
            {
                int key = hashFunc(y, i, maxSize);
                if (tableY[key].first == y)
                {
                    tableY[key].first = -2;
                    tableY[key].second = -2;
                    break;
                }
                i++;
            }
            auto iter = point.begin();
            while (iter != point.end()){
                if (iter->second == y){
                    point.erase(iter);
                    continue;
                }
                iter++;
            }
            result += MaxPairY;
        }
    }
    cout << ((point.size() == 0) ? "YES" : "NO");
}