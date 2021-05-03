#include "../template.hpp"

template <typename S> struct matrix {
    using V = typename S::val_t;
    vector<vector<V>> val;
    matrix(int n, int m) : matrix(vector(n, vector(m, S::zero()))) {}
    matrix(vector<vector<V>> src) : val(src) {}
    vector<V> &operator[](int i) { return val[i]; }
    int height() { return val.size(); }
    int width() { return val[0].size(); }
    static matrix id(int n) {
        matrix ret(n, n);
        rep(i, n) ret[i][i] = S::one();
        return ret;
    }
    void row_add(int i, int j, V a) {
        rep(k, width()) { val[i][k] += val[j][k] * a; }
    }
    void place_nonzero(int i, int j) {
        for (int k = i; k < height(); k++) {
            if (val[k][j] != S::zero()) {
                val[i].swap(val[k]);
                break;
            }
        }
    }
    matrix upper_triangular() {
        matrix ret(val);
        for (int i = 0, j = 0; i < height() && j < width(); j++) {
            ret.place_nonzero(i, j);
            if (ret[i][j] == S::zero()) continue;
            for (int k = i + 1; k < height(); k++) { ret.row_add(k, i, -ret[k][j] / ret[i][j]); }
            i++;
        }
        return ret;
    }
    V det() {
        V ret = S::one();
        matrix ut = upper_triangular();
        rep(i, height()) ret *= ut[i][i];
        return ret;
    }
    matrix inv() {
        matrix ex(height(), width() << 1);
        rep(i, height()) {
            rep(j, width()) { ex[i][j] = val[i][j]; }
        }
        rep(i, height()) ex[i][width() + i] = S::one();
        matrix ut = ex.upper_triangular();
        for (int i = height() - 1; i >= 0; i--) {
            ut.row_add(i, i, S::one() / ut[i][i] - S::one());
            rep(j, i) ut.row_add(j, i, -ut[j][i] / ut[i][i]);
        }
        matrix ret(height(), width());
        rep(i, height()) {
            rep(j, width()) { ret[i][j] = ut[i][width() + j]; }
        }
        return ret;
    }
    matrix &operator+=(matrix a) {
        rep(i, height()) {
            rep(j, width()) { val[i][j] += a[i][j]; }
        }
        return *this;
    }
    matrix &operator-=(matrix a) {
        rep(i, height()) {
            rep(j, width()) { val[i][j] -= a[i][j]; }
        }
        return *this;
    }
    matrix &operator*=(matrix a) {
        matrix res(height(), a.width());
        rep(i, height()) {
            rep(j, a.width()) {
                rep(k, width()) { res[i][j] += val[i][k] * a[k][j]; }
            }
        }
        val.swap(res.val);
        return *this;
    }
    matrix &operator/=(matrix a) { return *this *= a.inv(); }
    matrix &operator^=(ll p) {
        matrix res = matrix::id(height());
        while (p) {
            if (p & 1) res *= *this;
            *this *= *this;
            p >>= 1;
        }
        val.swap(res.val);
        return *this;
    }
    matrix operator+() { return *this; }
    matrix operator-() { return matrix(height(), width()) -= *this; }
    matrix operator*(matrix a) { return matrix(val) *= a; }
    matrix operator/(matrix a) { return matrix(val) /= a; }
};

struct double_field {
    using val_t = double;
    static val_t zero() { return 0.0; }
    static val_t one() { return 1.0; }
};

template <> void matrix<double_field>::place_nonzero(int i, int j) {
    for (int k = i + 1; k < height(); k++) {
        if (abs(val[k][j]) > abs(val[i][j])) val[i].swap(val[k]);
    }
};