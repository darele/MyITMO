typedef struct pol {
    ll p[lim];
    int grade;
    pol() {
        grade = 0;
        REP(0, lim){
            p[i] = 0;
        }
    }
    pol(int n) {
        grade = n;
        REP(0, lim){
            p[i] = 0;
        }
    }

    ll operator[] (int index) {
        return index >= 0 && index <= grade ? p[index] : 0;
    }

    void reduce() {
        for (int i = grade; i >= 0; i--) {
            if (p[i] == 0) {
                grade--;
            } else {
                break;
            }
        }
    }

    void add(pol other) {
        for (int i = 0; i <= other.grade; i++) {
            p[i] += other[i];
            p[i] %= mod;
        }
        reduce();
    }

    void multiply(pol other) {
        int n = grade + other.grade;
        ll temp[n + 1];
        REP(0, n + 1) {
            temp[i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                temp[i] += ((*this)[j] * other[i - j]) % mod;
                temp[i] %= mod;
            }
        }
        REP(0, n + 1) {
            p[i] = temp[i];
        }
        grade = n;
        reduce();
    }
    void print() {
        cout << grade << "\n";
        for (int i = 0; i <= grade; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
} pol;