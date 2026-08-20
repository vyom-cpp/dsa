#include <iostream>
using namespace std;

void pattern_one(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0;j<n;j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void pattern_two(int n){
    for(int i=0; i < n; i++){
        for(int j=0; j<=i; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void pattern_three(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern_four(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern_five(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void pattern_six(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= n-i+1; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern_seven(int n){
    for(int i = 0; i < n; i++){
        // space-one 
        for(int j = 0; j <= n-i+1; j++){
            cout << " ";
        }
        
        // stars
        for(int j = 0; j < 2*i + 1; j++){
            cout << "*";
        }

        // space-two
        for(int j = 0; j <= n-i+1; j++){
            cout << " ";
        }
        cout << endl;
    } 
}

void pattern_eight(int n){
    for(int i=0; i<n; i++){
        // space-one
        for(int j=0; j<i; j++){
            cout << " ";
        }

        // stars
        for(int j=0; j<(2*n - (2*i + 1)); j++){
            cout << "*";
        }

        // space-three
        for(int j=0; j<i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern_nine(int n){
    for(int i = 0; i < n; i++){
        // space-one 
        for(int j = 0; j <= n-i+1; j++){
            cout << " ";
        }
        
        // stars
        for(int j = 0; j < 2*i + 1; j++){
            cout << "*";
        }

        // space-two
        for(int j = 0; j <= n-i+1; j++){
            cout << " ";
        }
        cout << endl;
    } 


    for(int i=0; i<n; i++){
        // space-one
        for(int j=0; j<i; j++){
            cout << " ";
        }

        // stars
        for(int j=0; j<(2*n - (2*i + 1)); j++){
            cout << "*";
        }

        // space-three
        for(int j=0; j<i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern_ten(int n){
    // upper part of the pattern
    for(int i = 1; i <= 2*n - 1; i++){
        int stars = i;
        if(i > n)   stars = 2*n - i;
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern_eleven(int n){
    int start = 1;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0)  start = 0;
        else    start = 1;
        for(int j = 0; j <= i; j++){
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void pattern_twelve(int n){
    int spaces = 2*(n-1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j;
        }

        // spaces
        for(int j = 1; j<= spaces; j++){
            cout << " ";
        }

        // numbers
        for(int j = i; j >= 1; j--){
            cout << j;
        }
        cout << endl;
        spaces -= 2;
    }
}

void pattern_13(int n){
    int num = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            cout << num;
            num++;
        }
        cout << endl;
    }
}

void pattern_14(int n){
    for(int i = 0; i < n; i++){
        char ch = 'A';
        for(int j = 0; j <= i; j++){
            cout << ch;
            ch++;
        }
        cout << endl;
    }
}

void pattern_15(int n){
    for(int i = 1; i <= n; i++){
        char ch = 'A';
        for(int j = 1; j <= n-i+1; j++){
            cout << ch;
            ch++;
        }
        cout << endl;
    }
}

void pattern_16(int n){
    for(int i = 0; i < n; i++){
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++){
            cout << ch;
        }
        cout << endl;
    }
}

void pattern_17(int n){
    for(int i = 0; i < n; i++){
        // spaces
        for(int j = 0; j <n-i-1; j++){
            cout << " ";
        }
        
        // alphabets
        char ch = 'A';
        int breakpoint = i; // The peak of the pyramid row
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << ch;
            if (j < breakpoint) {
                ch++; // Increment up to the middle
            } else {
                ch--; // Decrement after the middle
            }
        }
    
        // spaces
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern_18(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'E' - i; ch <= 'E'; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern_19(int n){
    int spaces = 0;
    for(int i = 0; i < n; i++){
        // stars
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }

        // spaces
        for(int j = 0; j < spaces; j++){
            cout << " ";
        }

        // stars
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }
        spaces += 2;
        cout << endl;
    }

    // reversing it
    spaces = 2*n - 2;
    for(int i = 0; i < n; i++){
        // stars
        for(int j = 0; j <= i; j++){
            cout << "*";
        }

        // spaces
        for(int j = 0; j < spaces; j++){
            cout << " ";
        }

        // stars
        for(int j = 0; j <= i; j++){
            cout << "*";
        }
        spaces -= 2;
        cout << endl;
    }
}

void pattern_20(int n){
    int spaces = 2*n - 2;
    for(int i = 1; i <= 2*n - 1; i++){
        int stars = i;
        if(i > n)   stars = 2*n - i;

        // stars
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }

        // spaces
        for(int j = 1; j <= spaces; j++){
            cout << " ";
        }

        // stars
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }
        cout << endl;
        if(i < n)   spaces -= 2;
        else spaces += 2;
    }
}

void pattern_21(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1)    cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

void pattern_22(int n){
    
}



int main() {
    int n;
    cin >> n;
    // pattern_one(n);
    // pattern_two(n);
    // pattern_three(n);
    // pattern_four(n);
    // pattern_five(n);
    // pattern_six(n);
    // pattern_seven(n);
    // pattern_eight(n);
    // pattern_nine(n);
    // pattern_ten(n);
    // pattern_eleven(n);
    // pattern_twelve(n);
    // pattern_13(n);
    // pattern_14(n);
    // pattern_15(n);
    // pattern_16(n);
    // pattern_17(n);
    // pattern_18(n);
    // pattern_19(n);
    // pattern_20(n);
    // pattern_21(n);
    pattern_22(n);
    return 0;
}