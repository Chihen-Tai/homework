#include <iostream>
#include <cmath>
class Object
{
public:
    Object(double W) : weight{W}, vx{0}, vy{0}, x{0}, y{0}, r{0} {}
    void setCircle(double X, double Y, double R)
    {
        x = X, y = Y, r = R;
    }
    void setSpeed(double Vx, double Vy)
    {
        vx = Vx, vy = Vy;
    }
    double &getSpeedX() { return vx; }
    double &getSpeedY() { return vy; }
    double &getX() { return x; }
    double &getY() { return y; }
    double &getR() { return r; }
    const double &getWeight() const { return weight; }
    const double &getSpeedX() const { return vx; }
    const double &getSpeedY() const { return vy; }
    double getVelocity() const { return sqrt(vx * vx + vy * vy); }
    double getAngle() const { return atan2(vy, vx) * 180.0 / M_PI; }
    const double &getX() const { return x; }
    const double &getY() const { return y; }
    const double &getR() const { return r; }

private:
    double weight;
    double vx, vy;
    double x, y, r;
};
#include <vector>
#include <cmath>
class Vector
{
public:
    Vector(double X, double Y) : x{X}, y{Y} {}
    double &getX() { return x; }
    double &getY() { return y; }
    const double &getX() const { return x; }
    const double &getY() const { return y; }
    double operator*(const Vector &rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
    Vector operator*(const double &rhs) const
    {
        return Vector(x * rhs, y * rhs);
    }
    friend Vector operator*(double lhs, const Vector &rhs)
    {
        return Vector(lhs * rhs.x, lhs * rhs.y);
    }
    Vector operator+(const Vector &rhs) const
    {
        return Vector(x + rhs.x, y + rhs.y);
    }
    Vector operator-(const Vector &rhs) const
    {
        return Vector(x - rhs.x, y - rhs.y);
    }
    double operator~() const
    {
        return sqrt(x * x + y * y);
    }
    // Vector v; (~v) =? length of v;
    Vector operator-() const
    {
        return Vector(-x, -y);
    }

private:
    double x, y;
};
class PhysicEngine
{
public:
    static constexpr double G = 9.8;
    PhysicEngine() : fps{60} {}
    void setFPS(unsigned int FPS)
    {
        fps=FPS;
    }
    unsigned int getFPS() const { return fps; }
    void addObject(const Object &object)
    {
        objects.emplace_back(object);
    }
    void reset()
    {
        objects.clear();
    }
    const std::vector<Object> &getObjects() const
    {
        return objects;
    }
    void update()
    {
        double dt = 1.0 / fps;
        // object :self-update
        for (Object &object : objects)
        //direct chane ele in vector
        {
            //- consider gravity
            object.getSpeedY() -= G * dt;
            //- consider speed ->(x,y) movement
            object.getX() += object.getSpeedX() * dt;
            object.getY() = std::max(object.getR(), object.getY() + object.getSpeedY() * dt);
        }
        // object -to-object :elastic-collision
        for (size_t i = 0; i < objects.size(); ++i)
        {
            Object &obj1 = objects[i];
            for (size_t j = i + 1; j < objects.size();++j)
            {
                Object &obj2 = objects[j];
                double dx = obj1.getX() - obj2.getX();
                double dy = obj1.getY() - obj2.getY();
                double dr = obj1.getR() + obj2.getR();
                if (dx * dx + dy * dy < dr * dr)
                {
                    double w1 = obj1.getWeight();
                    double w2 = obj2.getWeight();
                    Vector v1(obj1.getSpeedX(), obj1.getSpeedY());
                    Vector v2(obj2.getSpeedX(), obj2.getSpeedY());
                    Vector dv = v1 - v2;
                    Vector dp = Vector(dx, dy);
                    Vector u1 = v1 - ((2 * w2 / (w1 + w2)) * (dv * dp / (~dp * ~dp))) * dp;
                    Vector u2 = v2 - ((2 * w1 / (w1 + w2)) * ((-dv) * (-dp) / (~dp * ~dp))) * (-dp);
                    obj1.setSpeed(u1.getX(), u1.getY());
                    obj2.setSpeed(u2.getX(), u2.getY());
                    // fix overlapping
                    double d = sqrt(dx * dx + dy * dy);
                    double overlap = dr - d;
                    double overlapX = overlap * dx / d;
                    double overlapY = overlap * dy / d;
                    obj1.getX() += overlapX / 2;
                    obj1.getY() += overlapY / 2;
                    obj2.getX() -= overlapX / 2;
                    obj2.getY() -= overlapY / 2;
                }
            }
        }
        // object -to-grounc :elastic-collision
        // object -to-ground :elastic-collision
        for (Object &object : objects)
        {
            if (object.getY()-object.getR()<= 0)
            {
                object.getSpeedY() = std::abs(object.getSpeedY());
            }
        }
    }

private:
    std::vector<Object> objects;
    unsigned int fps;
    
};