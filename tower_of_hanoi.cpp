#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    long long toh(int N, int from, int to, int aux) {
   if(N==1)
        {
            cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<endl;
           return 1;
        }
        toh(N-1,from,aux,to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(N-1,aux,to,from);
        
        return 2^N-1;
    }
};

int main() {

    int T;
    cin >> T;
    while (T--) {
        
        int N;
        cin >> N;
        
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



//input
// 1
// 2

//output
// move disk 1 from rod 1 to rod 2
// move disk 2 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 3
// 3
