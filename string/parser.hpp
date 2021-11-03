#pragma once

#include "../template.hpp"

using state = string::const_iterator;
struct parse_error {};

void consume(state &cur, char expected) {
    if (*cur == expected) {
        ++cur;
    } else {
        cerr << "Expected '" << expected << "' but got '" << *cur << "'" << endl;
        cerr << "Rest string is '";
        while (*cur) cerr << *cur++;
        cerr << "'" << endl;
        throw parse_error();
    }
}

struct parser {
    ll expr(state &cur) {
        ll ret = term(cur);
        while (true) {
            if (*cur == '+') {
                consume(cur, '+');
                ret += term(cur);
            } else if (*cur == '-') {
                consume(cur, '-');
                ret -= term(cur);
            } else {
                break;
            }
        }
        return ret;
    }
    ll term(state &cur) {
        ll ret = factor(cur);
        while (true) {
            if (*cur == '*') {
                consume(cur, '*');
                ret *= factor(cur);
            } else if (*cur == '/') {
                consume(cur, '/');
                ret /= factor(cur);
            } else {
                break;
            }
        }
        return ret;
    }
    ll factor(state &cur) {
        if (*cur == '(') {
            consume(cur, '(');
            ll ret = expr(cur);
            consume(cur, ')');
            return ret;
        } else {
            return number(cur);
        }
    }
    ll number(state &cur) {
        ll ret = 0;
        while (isdigit(*cur)) {
            ret *= 10;
            ret += *cur - '0';
            ++cur;
        }
        return ret;
    }
};