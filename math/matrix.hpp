#pragma once

#include "../template.hpp"

template <typename S> struct matrix {
    using V = typename S::val_t;
    vector<vector<V>> val;
    matrix(int n, int m) : matrix(vector(n, vector(m, S::zero()))) {}
    matrix(const vector<vector<V>> &src) : val(src) {}
    vector<V> &operator[](int i) { return val[i]; }
    const vector<V> &operator[](int i) const { return val[i]; }
    int height() const { return val.size(); }
    int width() const { return val[0].size(); }
    static matrix id(int n) {
        matrix ret(n, n);
        for (int i : rep(n)) ret[i][i] = S::one();
        return ret;
    }
    void row_add(int i, int j, V a) {
        for (int k : rep(width())) { val[i][k] += val[j][k] * a; }
    }
    bool place_nonzero(int i, int j) {
        for (int k : rep(i, height())) {
            if (val[k][j] != S::zero()) {
                if (k > i) row_add(i, k, S::one());
                break;
            }
        }
        return val[i][j] != S::zero();
    }
    matrix upper_triangular() const {
        matrix ret(*this);
        for (int i = 0, j = 0; i < height() && j < width(); j++) {
            if (!ret.place_nonzero(i, j)) continue;
            for (int k : rep(i + 1, height())) ret.row_add(k, i, -ret[k][j] / ret[i][j]);
            i++;
        }
        return ret;
    }
    V det() const {
        V ret = S::one();
        matrix ut = upper_triangular();
        for (int i : rep(height())) ret *= ut[i][i];
        return ret;
    }
    matrix inv() const {
        matrix ex(height(), width() << 1);
        for (int i : rep(height())) {
            for (int j : rep(width())) { ex[i][j] = val[i][j]; }
        }
        for (int i : rep(height())) ex[i][width() + i] = S::one();
        matrix ut = ex.upper_triangular();
        for (int i : per(height())) {
            ut.row_add(i, i, S::one() / ut[i][i] - S::one());
            for (int j : rep(i)) ut.row_add(j, i, -ut[j][i] / ut[i][i]);
        }
        matrix ret(height(), width());
        for (int i : rep(height())) {
            for (int j : rep(width())) { ret[i][j] = ut[i][width() + j]; }
        }
        return ret;
    }
    matrix pow(ll k) const {
        matrix ret = matrix::id(height()), mul(*this);
        while (k) {
            if (k & 1) ret *= mul;
            mul *= mul;
            p >>= 1;
        }
        return ret;
    }
    matrix &operator+=(const matrix &a) {
        for (int i : rep(height())) {
            for (int j : rep(width())) { val[i][j] += a[i][j]; }
        }
        return *this;
    }
    matrix &operator-=(const matrix &a) {
        for (int i : rep(height())) {
            for (int j : rep(width())) { val[i][j] -= a[i][j]; }
        }
        return *this;
    }
    matrix &operator*=(const matrix &a) {
        matrix res(height(), a.width());
        for (int i : rep(height())) {
            for (int j : rep(a.width())) {
                for (int k : rep(width())) { res[i][j] += val[i][k] * a[k][j]; }
            }
        }
        val.swap(res.val);
        return *this;
    }
    matrix &operator/=(const matrix &a) { return *this *= a.inv(); }
    bool operator==(const matrix &a) const { return val == a.val; }
    bool operator!=(const matrix &a) const { return rel_ops::operator!=(*this, a); }
    matrix operator+() const { return *this; }
    matrix operator-() const { return matrix(height(), width()) -= *this; }
    matrix operator+(const matrix &a) const { return matrix(*this) += a; }
    matrix operator-(const matrix &a) const { return matrix(*this) -= a; }
    matrix operator*(const matrix &a) const { return matrix(*this) *= a; }
    matrix operator/(const matrix &a) const { return matrix(*this) /= a; }
};

struct double_field {
    using val_t = double;
    static val_t zero() { return 0.0; }
    static val_t one() { return 1.0; }
};

template <> bool matrix<double_field>::place_nonzero(int i, int j) {
    static constexpr double EPS = 1e-12;
    for (int k : rep(i + 1, height())) {
        if (abs(val[k][j]) > abs(val[i][j])) {
            swap(val[i], val[k]);
            row_add(i, i, -2.0);
        }
    }
    return abs(val[i][j]) > EPS;
}