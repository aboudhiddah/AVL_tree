#include <bits/stdc++.h>
#include "avl_tree.h"

using namespace std;

int main()
{
    int max_n = 500000;
    int step = 10000;
    cout << "All functions work N/10 times in eàch test\n\n";
    fstream out1, out2, out3;
    out1.open("resultRemoveVal.txt");
    out2.open("resultRemoveMax.txt");
    out3.open("resultRemoveMin.txt");
    for (int n = step; n <= max_n; n += step){
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = rand();

        Node* root_1 = nullptr;
        Node* root_2 = nullptr;
        Node* root_3 = nullptr;
        for (int i = 0; i < n; i++){
            root_1 = insert(arr[i], root_1);
            root_2 = insert(arr[i], root_2);
            root_3 = insert(arr[i], root_3);
        }
        cout << "N = " << n << "\n";
        size_t startTime, endTime;
        //-------------------------------------------------RemoveVal
        startTime = clock( );
        for (int i = 0; i < n / 10; i++){
            root_1 = Remove(root_1, arr[i]);
        }
        endTime = clock( );
        out1 << n << " " << endTime - startTime << "\n";
        cout << "\tRemove val time: " << endTime - startTime << "\n";
        //-------------------------------------------------RemoveMax
        startTime = clock( );
        for (int i = 0; i < n / 10; i++){
            root_2 = RemoveMax(root_2);
        }
        endTime = clock( );
        out2 << n << " " << endTime - startTime << "\n";
        cout << "\tRemove max time: " << endTime - startTime << "\n";
        //-------------------------------------------------RemoveMin
        startTime = clock( );
        for (int i = 0; i < n / 10; i++){
            root_3 = RemoveMin(root_3);
        }
        endTime = clock( );
        out3 << n << " " << endTime - startTime << "\n";
        cout << "\tRemove min time: " << endTime - startTime << "\n";
    }
}
