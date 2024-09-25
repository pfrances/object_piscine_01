#include "Workshop.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"

int main() {
    Workshop<Hammer> workshop;
    Worker worker1(Position(1, 2, 3), Statistic(1, 0));
    Worker worker2(Position(4, 5, 6), Statistic(1, 0));

    Hammer hammer;
    Shovel shovel;
    worker1.addTool(&hammer);
    worker2.addTool(&shovel);

    workshop.addWorker(&worker1);
    try {
        workshop.addWorker(&worker2);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    workshop.executeWorkDay();

    return 0;
}