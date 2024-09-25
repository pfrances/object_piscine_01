#ifndef STATISTIC_HPP
#define STATISTIC_HPP

struct Statistic {
    private:
        int _level;
        int _xp;

    public:
        Statistic(int level, int xp) : _level(level), _xp(xp) {}
};

#endif