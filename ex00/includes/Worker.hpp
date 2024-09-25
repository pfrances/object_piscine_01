#ifndef WORKER_HPP
#define WORKER_HPP

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include <vector>
#include <cstddef>
#include <stdexcept>

class Worker {
    private: 
        Position _position;
        Statistic _statistic;
        std::vector<Tool*> _tools;

    public:
        Worker(const Position& position, const Statistic& statistic) : _position(position), _statistic(statistic) , _tools(
            std::vector<Tool*>()
        ) {}

        void addTool(Tool* tool) {
            for ( std::vector<Tool*>::iterator it = _tools.begin();  it != _tools.end();  it++
            ) {
                if (*it == tool) {
                    _tools.erase(it);
                }
            }
            _tools.push_back(tool);
        }

        void removeTool(Tool* tool) {
            for ( std::vector<Tool*>::iterator it = _tools.begin();  it != _tools.end();  it++
            ) {
                if (*it == tool) {
                    _tools.erase(it);
                    return;
                }
            }
            throw std::invalid_argument("Tool not found");
        }

        template<class ToolType> 
        void work() {
            ToolType* tool = getTool<ToolType>();
            if (tool == NULL) {
                throw std::runtime_error("Worker does not have the required tool");
            }
            tool->use();
        }

         template<class ToolType> 
         ToolType* getTool() {
            for ( std::vector<Tool*>::iterator it = _tools.begin();  it != _tools.end();  it++
            ) {
                if (ToolType* tool = dynamic_cast<ToolType*>(*it)) {
                    return tool;  
                }
            }
            return NULL;
        }
};


#endif