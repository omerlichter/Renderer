//
// Created by omer on 1/19/18.
//

#ifndef RENDERER_RENDERLOG_H
#define RENDERER_RENDERLOG_H

#include <iostream>
#include "Listener.h"

using namespace std;

class RenderLog : public Listener {
public:
    virtual void notify(Event event);
private:
};


#endif //RENDERER_RENDERLOG_H
