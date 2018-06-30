#include "gtest/gtest.h"                     // TEST, EXPECT_*
#include "smallest_circle/smallest_circle.h" // smallest_circle()
#include <vector>                            // std::vector
#include <cmath>                             // std::sqrt
#include <random>                            // rng


namespace {

static const std::size_t MAX_POINTS = 1000;
static const double      X_MIN      = -100.0;
static const double      X_MAX      = +100.0;
static const double      Y_MIN      = -100.0;
static const double      Y_MAX      = +100.0;

inline const std::vector<double>& generate_at_least_2_points()
{
    static std::vector<double>                        points;
    static std::default_random_engine                 generator;
    static std::uniform_int_distribution<std::size_t> length(2, MAX_POINTS);
    static std::uniform_real_distribution<double>     x(X_MIN, X_MAX);
    static std::uniform_real_distribution<double>     y(Y_MIN, Y_MAX);

    points.resize(length(generator) * 2);

    auto point      = points.begin();
    auto points_end = points.end();

    do {
        *point++ = x(generator);
        *point++ = y(generator);
    } while (point != points_end);

    return points;
}

inline double get_distance(double x, double y, double point_x, double point_y)
{
    double delta_x = point_x - x;
    double delta_y = point_y - y;

    return std::sqrt((delta_x * delta_x) * (delta_y * delta_y));
}

} // namespace

TEST(test_smallest_circle, single_point)
{
    static const double X_INC = (X_MAX - X_MIN) / 10.0;
    static const double Y_INC = (Y_MAX - Y_MIN) / 10.0;

    for (double point_x = X_MIN; point_x <= X_MAX; point_x += X_INC)
        for (double point_y = Y_MIN; point_y <= Y_MAX; point_y += Y_INC) {
            double x, y, r;
            double point[2] = { point_x, point_y };

            smallest_circle(&x, &y, &r, point, 1);

            ASSERT_DOUBLE_EQ(point[0], x);
            ASSERT_DOUBLE_EQ(point[1], y);
            ASSERT_DOUBLE_EQ(0.0,      r);
        }
}


TEST(test_smallest_circle, sample_at_least_2_points)
{
    for (unsigned int samples = 10; samples > 0; --samples) {
        auto points = generate_at_least_2_points();

        double x, y, r;
        double max_distance;

        max_distance = 0.0;
        smallest_circle(&x, &y, &r, points.data(), points.size());

        const auto points_begin = points.cbegin();
        const auto points_end   = points.cend();

        auto point = points_begin;
        do {
            double point_x = *point++;
            double point_y = *point++;

            double distance = get_distance(x, y, point_x, point_y);
            ASSERT_GE(r, distance);

            if (distance > max_distance)
                max_distance = distance;
        } while (point != points_end);

        r -= (max_distance / 100.0);

        point = points_begin;
        do {
            double point_x = *point++;
            double point_y = *point++;

            if (r < get_distance(x, y, point_x, point_y))
                goto NEXT_SAMPLE;
        } while (point != points_end);

        FAIL() << "not a snug fit";
NEXT_SAMPLE:
        continue;
    }
}
