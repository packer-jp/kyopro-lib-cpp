#pragma once

#include "../template.hpp"
#include "khan.hpp"

struct offline_dag_reachability {
    vector<vector<int>> g;
    offline_dag_reachability(int n) : g(n) {}
    vector<bool> get(vector<pair<int, int>> &qs) {}
};