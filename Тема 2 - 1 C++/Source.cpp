#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

double distancePointToLine(double A, double B, double C, Point p) {
    return std::abs(A * p.x + B * p.y + C) / std::sqrt(A * A + B * B);
}

bool intersectionPoint(double A1, double B1, double C1, double A2, double B2, double C2, Point& intersection) {
    double D = A1 * B2 - A2 * B1;
    if (D == 0) {
        return false;
    }
    intersection.x = (B1 * C2 - B2 * C1) / D;
    intersection.y = (A2 * C1 - A1 * C2) / D;
    return true;
}

double angleBetweenLines(double A1, double B1, double A2, double B2) {
    double cosTheta = (A1 * A2 + B1 * B2) / (std::sqrt(A1 * A1 + B1 * B1) * std::sqrt(A2 * A2 + B2 * B2));
    double angleRad = std::acos(std::clamp(cosTheta, -1.0, 1.0));
    double angleDeg = angleRad * 180.0 / M_PI;
    return angleDeg;
}

int main() {
    double A1 = 1, B1 = -2, C1 = 1;
    double A2 = -1, B2 = -1, C2 = -2;

    Point p = { 3, 2 };

    double distance1 = distancePointToLine(A1, B1, C1, p);
    std::cout << "Расстояние от точки до первой прямой = " << distance1 << std::endl;

    double distance2 = distancePointToLine(A2, B2, C2, p);
    std::cout << "Расстояние от точки до второй прямой = " << distance2 << std::endl;

    Point intersection;
    if (intersectionPoint(A1, B1, C1, A2, B2, C2, intersection)) {
        std::cout << "Точка пересечения прямых: (" << intersection.x << ", " << intersection.y << ")" << std::endl;
    }
    else {
        std::cout << "Прямые параллельны или совпадают." << std::endl;
    }

    if (intersectionPoint(A1, B1, C1, A2, B2, C2, intersection)) {
        double distanceToIntersection = std::sqrt(std::pow(p.x - intersection.x, 2) + std::pow(p.y - intersection.y, 2));
        std::cout << "Расстояние от заданной точки до точки пересечения прямых = " << distanceToIntersection << std::endl;
    }

    double angle = angleBetweenLines(A1, B1, A2, B2);
    std::cout << "Угол между прямыми = " << angle << " градусов" << std::endl;

    return 0;
}
