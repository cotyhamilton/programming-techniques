// Coty Hamilton : flip flop the squarelotron : 10016 : cotyhamilton

/*

    tricks of the trade:

        stole this ceiling integer division from stack overflow

        https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

void print(vector <vector <int> > &);

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int cases, size, rings, flips, flip, UL, LR;

    cin >> cases;

    for(int x = 0; x < cases; x++) {

        cin >> size;

        vector <vector <int> > mat(size, vector <int> (size));

        for(int r = 0; r < size; r++) {

            for(int c = 0; c < size; c++) {

                cin >> mat[r][c];

            }

        }

        rings = (size + 2 - 1) / 2;
        
        for(int ring = 0; ring < rings; ring++) {

            UL = ring;

            LR = size - ring - 1;

            cin >> flips;

            for(int i = 0; i < flips; i++) {

                cin >> flip;

                switch(flip) {

                    case 1:

                    // --- Up Down --- //

                        for(int y = UL; y < size - UL; y++) {

                            swap(mat[UL][y], mat[LR][y]);

                        }

                        for(int y = UL + 1; y < size / 2; y++) {

                            swap(mat[y][LR], mat[size - y - 1][LR]);

                            swap(mat[y][UL], mat[size - y - 1][UL]);

                        }

                    break;

                    case 2:

                    // --- Left Right --- //

                        for(int y = UL; y < size - UL; y++) {

                            swap(mat[y][UL], mat[y][LR]);
                            
                        }

                        for(int y = UL + 1; y < size / 2; y++) {

                            swap(mat[LR][y], mat[LR][size - y - 1]);

                            swap(mat[UL][y], mat[UL][size - y - 1]);

                        }
                    
                    break;

                    case 3:

                    // --- Main Diagonal --- //

                        for (int y = UL + 1; y <= LR; y++) {

                            swap(mat[UL][y], mat[y][UL]);

                        }

                        for (int y = UL + 1; y < LR; y++) {

                            swap(mat[LR][y], mat[y][LR]);

                        }

                    break;

                    case 4:
                    
                    // --- Inverse Diagonal --- //

                        for(int y = UL; y < LR; y++) {

                            swap(mat[UL][y], mat[size - y - 1][LR]);
                        
                        }
                        
                        for(int y = UL + 1; y < LR; y++) {
                        
                            swap(mat[LR][y], mat[size - y - 1][UL]);
                        
                        }

                    break;

                }

            }

        }

        print(mat);

    }

    return 0;

}

void print(vector <vector <int> > &mat) {

    int size = mat.size();

    for(int r = 0; r < size; r++) {

            for(int c = 0; c < size; c++) {

                cout << mat[r][c] << (c < size - 1 ? " ": "");

            }

            cout << (r < size ? "\n" : "");

        }

}