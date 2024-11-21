#include <iostream>
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
    }
	Function *differential() override
    {
        return new Constant(0);
    }
	double eval(double) override
    {
        return value;
    }

    private:
    double value;
    Constant(const double &value):value(value){}
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
	double eval(double value) override
    {
        return value;
    }

    private:
    string name;
    Variable(const string &name):name(name){}
};

class Polynomial : public Function
{
	public:
	static Polynomial *create(Function * base, Function *exp)
    {
        return new Polynomial(base,exp);
    }
	Function *differential() override;
	double eval(double value) override
    {
        return pow(base->eval(value),exp->eval(0));
    }

    private:
    Function*base,*exp;
    Polynomial(Function*base,Function*exp):base(base),exp(exp){}
};

class Arithmetic : public Function
{
	public:
	static Arithmetic *create(Function *lhs , char op , Function * rhs)
    {
        switch(op)
        {
            case '+':
                return new Arithmetic(lhs,Type::ADD,rhs);
            case '-':
                return new Arithmetic(lhs,Type::SUB,rhs);
            case '*':
                return new Arithmetic(lhs,Type::MUL,rhs);
            case '/':
                return new Arithmetic(lhs,Type::DIV,rhs);
        }
    }
	Function *differential() override
    {
        switch(type)
        {
            case Type::ADD:
            case Type::SUB:
                return new Arithmetic(lhs->differential(),type,rhs->differential());
            case Type::MUL:
                return new Arithmetic(lhs)
        }
    }
	double eval(double) override;

    private:
    enum class Type
    {
        ADD,
        SUB,
        MUL,
        DIV
    };
    Function *rhs,*lhs;
    Type type;
    Arithmetic(Function*lhs,Type type,Function *rhs):lhs(lhs),rhs(rhs),type(type){}
};

class Sin : public Function
{
	public:
	static Sin *create(Function *);
	Function *differential() override;
	double eval(double) override;
};

class Cos : public Function
{
	public:
	static Cos *create(Function *);
	Function *differential() override;
	double eval(double) override;
};
