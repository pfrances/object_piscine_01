#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include "Worker.hpp"
#include <vector>
#include <stdexcept>


template <class ToolType>
class Workshop {
    private:
        std::vector<Worker*> _workers;

    public:
        Workshop() : _workers(
            std::vector<Worker*>()
        ) {}

        void addWorker(Worker* worker) {
            if (worker->getTool<ToolType>() == NULL) {
                throw std::invalid_argument("Worker does not have the required tool");
            }

            for (std::vector<Worker*>::iterator it = _workers.begin(); it != _workers.end(); it++) {
                if (*it == worker) {
                    throw std::invalid_argument("Worker already registered");
                }
            }

            _workers.push_back(worker);
        }

        void removeWorker(Worker* worker) {
            for (std::vector<Worker*>::iterator it = _workers.begin(); it != _workers.end(); it++) {
                if (*it == worker) {
                    _workers.erase(it);
                    return;
                }
            }
            throw std::invalid_argument("Worker not found");
        }

        void executeWorkDay() {
            for (std::vector<Worker*>::iterator it = _workers.begin(); it != _workers.end(); it++) {
                (*it)->work<ToolType>();
            }
        }
};

#endif