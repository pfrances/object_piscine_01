#ifndef POSITION_HPP
#define POSITION_HPP

struct Position {
    private:
        int _x;
        int _y;
        int _z;

    public:
        Position(int x, int y, int z) : _x(x), _y(y), _z(z) {}
};

#endif