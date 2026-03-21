#include <iostream>
#include <cmath>
#include "Pyramid.h"

using namespace std;

template<typename T>
bool approxEqual(T a, T b, T eps = 0.001) {
    return fabs(a - b) < eps;
}

int main() {
    int failed = 0;

    cout << "=== UNIT TESTS ===" << endl;

    // ✅ 1. Happy path
    {
        ShapeParam<float> param;
        param.set_attrib(PARAM_WIDTH, 4);
        param.set_attrib(PARAM_HEIGHT, 6);
        param.set_attrib(PARAM_DEPTH, 4);

        Pyramid<float> p(param);
        auto result = p.compute();

        float expected = (4 * 4 * 6) / 3.0;

        if (!approxEqual(result.get_attrib(RESULT_VOLUME), expected)) {
            cout << "FAIL: Happy path" << endl;
            failed++;
        } else {
            cout << "PASS: Happy path" << endl;
        }
    }

    // ✅ 2. Boundary (zero)
    {
        ShapeParam<float> param;
        param.set_attrib(PARAM_WIDTH, 0);
        param.set_attrib(PARAM_HEIGHT, 0);
        param.set_attrib(PARAM_DEPTH, 0);

        Pyramid<float> p(param);
        auto result = p.compute();

        if (result.get_attrib(RESULT_VOLUME) != 0) {
            cout << "FAIL: Zero case" << endl;
            failed++;
        } else {
            cout << "PASS: Zero case" << endl;
        }
    }

    // ✅ 3. Large values
    {
        ShapeParam<float> param;
        param.set_attrib(PARAM_WIDTH, 1e6);
        param.set_attrib(PARAM_HEIGHT, 1e6);
        param.set_attrib(PARAM_DEPTH, 1e6);

        Pyramid<float> p(param);
        auto result = p.compute();

        if (result.get_attrib(RESULT_VOLUME) <= 0) {
            cout << "FAIL: Large values" << endl;
            failed++;
        } else {
            cout << "PASS: Large values" << endl;
        }
    }

    // ❌ 4. Invalid (negative)
    try {
        ShapeParam<float> param;
        param.set_attrib(PARAM_WIDTH, -1);
        param.set_attrib(PARAM_HEIGHT, 5);
        param.set_attrib(PARAM_DEPTH, 5);

        Pyramid<float> p(param);
        p.compute();

        cout << "FAIL: Negative values" << endl;
        failed++;
    } catch (...) {
        cout << "PASS: Negative values exception" << endl;
    }

    cout << "\nFAILED: " << failed << endl;

    return failed;
}