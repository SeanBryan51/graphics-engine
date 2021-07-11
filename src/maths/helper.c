#include "maths.h"

float to_radians(float angle) {
    return M_PI / 180.0f * angle;
}

float map(float value, float low, float high, float new_low, float new_high) {

    value -= low;
    value /= (high - low);
    value *= (new_high - new_low);
    value += new_low;

    return value;
}
