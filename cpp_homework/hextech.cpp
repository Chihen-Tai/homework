#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class Function
{
public:
    static Function *parse(stringstream &ss); // this has been implemented
    virtual Function *differential() = 0;
    virtual double eval(double) = 0;
};



class Constant : public Function
{
public:
    static Constant *create(const double &value)
    {
        return new Constant(value);
    };
    Function *differential() override
    {
        //return Constant::create(0);
        return new Constant{0};
    }
    double eval(double) override
    {
        return value;
    }

private:
    Constant(const double &value) : value(value) {}
    double value;
};

class Variable : public Function
{
public:
    static Variable *create(const string &name)
    {
        return new Variable(name);
    }
    Function *differential() override
    {
        return Constant::create(1);
    }
    double eval(double val) override
    {
        return val;
    }

private:
    Variable(const string &name) : name(name) {}
    string name;
};

class Polynomial : public Function
{
public:
    static Polynomial *create(Function *base, Function *exp)
    {
        return new Polynomial(base, exp);
    }
    Function *differential() override;
    double eval(double val) override
    {
        return pow(base->eval(val), exp->eval(0));
    }

private:
    Polynomial(Function *_base, Function *_exp) : base(_base), exp(_exp) {}
    Function *base, *exp; // base**exp
};

class Arithmetic : public Function
{
public:
    static Arithmetic *create(Function *lhs, char op, Function *rhs)
    {
        switch (op)
        {
        case '+':
            return new Arithmetic(lhs, Type::ADD, rhs);
        case '-':
            return new Arithmetic(lhs, Type::SUB, rhs);
        case '*':
            return new Arithmetic(lhs, Type::MUL, rhs);
        case '/':
            return new Arithmetic(lhs, Type::DIV, rhs);
        default:
            cerr << "Error: Unsupported operator '" << op << "'" << endl;
            return nullptr;
        }
    }

    Function *differential() override
    {
        switch (type)
        {
        case Type::ADD:
        case Type::SUB:
            return new Arithmetic{lhs->differential(), type, rhs->differential()};
        case Type::MUL:
            return new Arithmetic{
                new Arithmetic{lhs->differential(), Type::MUL, rhs},
                Type::ADD,
                new Arithmetic{lhs, Type::MUL, rhs->differential()}};
        case Type::DIV:
            return new Arithmetic{
                new Arithmetic{
                    new Arithmetic{lhs->differential(), Type::MUL, rhs},
                    Type::SUB,
                    new Arithmetic{lhs, Type::MUL, rhs->differential()}},
                Type::DIV,
                Polynomial::create(rhs, Constant::create(2))};
        }
        return nullptr;
    }

    double eval(double val) override
    {
        switch (type)
        {
        case Type::ADD:
            return lhs->eval(val) + rhs->eval(val);
        case Type::SUB:
            return lhs->eval(val) - rhs->eval(val);
        case Type::MUL:
            return lhs->eval(val) * rhs->eval(val);
        case Type::DIV:
            return lhs->eval(val) / rhs->eval(val);
        }
    }

private:
    enum class Type
    {
        ADD,
        SUB,
        MUL,
        DIV
    };
    Arithmetic(Function *lhs, Type type, Function *rhs) : lhs(lhs), type(type), rhs(rhs) {}
    Function *lhs, *rhs;
    Type type;
};


class Sin : public Function
{
public:
    static Sin *create(Function *base)
    {
        return new Sin(base);
    }
    Function *differential() override;
    double eval(double val) override
    {
        return sin(base->eval(val));
    }

private:
    Sin(Function *base) : base(base) {}
    Function *base;
};

class Cos : public Function
{
public:
    static Cos *create(Function *base)
    {
        return new Cos(base);
    }
    Function *differential() override
    {
        return Arithmetic::create(
            Constant::create(0),
            '-',
            Arithmetic::create(Sin::create(base), '*', base->differential())
        );
    }
    double eval(double val) override
    {
        return cos(base->eval(val));
    }

private:
    Cos(Function *base) : base(base) {}
    Function *base;
};

Function *Polynomial::differential()
{
    return Arithmetic::create(
        Arithmetic::create(
            Polynomial::create(base, Arithmetic::create(exp, '-', Constant::create(1))),
            '*',
            exp),
        '*',
        base->differential());
}
// Define Sin::differential() after Cos is fully defined
Function *Sin::differential()
{
    return Arithmetic::create(Cos::create(base), '*', base->differential());
}