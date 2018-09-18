// Coty Hamilton : rotated squares : 10855 : cotyhamilton

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

void Rotate(vector <vector <char> > &B) {

    int size = B.size();

    vector <vector <char> > C(size, vector <char> (size));

    for(int r = 0; r < size; r++) {

        for(int c = 0; c < size; c++) {

            C[c][size - r - 1] = B[r][c];

        }

    }

    B = C;

}

int Occurences(vector <vector <char> > &A, vector <vector <char> > &B) {

    int count = 0;

    int N = A.size();
    
    int n = B.size();
    
    int bound = N - n + 1;
    
    bool contained;

    for(int r = 0; r < bound; r++) {
    
        for(int c = 0; c < bound; c++) {
    
            int R = 0;
    
            contained = true;
    
            while (contained && R < n) {
    
                int C = 0;
    
                while (contained && C < n) {
    
                    if(A[r + R][c + C] != B[R][C]) {
    
                        contained = false;
    
                    }
    
                    C++;
    
                }
    
                R++;
    
            }
    
            if (contained) {
    
                count++;
    
            }
    
        }
    
    }
    
    return count;

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int N, n;

    cin >> N >> n;

    while(N != 0) {

        vector <vector <char> > A(N, vector <char> (N));

        vector <vector <char> > B(n, vector <char> (n));

        for(int r = 0; r < N; r++) {

            for(int c = 0; c < N; c++) {

                cin >> A[r][c];

            }

        }

        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {
            
                cin >> B[r][c];
            
            }
        
        }

        for(int i = 0; i < 4; i++) {

            cout << Occurences(A,B);

            cout << (i != 3 ? " ": "");

            Rotate(B);

        }

        cout << endl;

        cin >> N >> n;

    }

    return 0;

}