//
// Created by omer on 1/19/18.
//

#ifndef RENDERER_LISTENER_H
#define RENDERER_LISTENER_H

enum Event {
    START_RENDERING,
    END_RENDERING,
    WRITE_BMP,
    OBJECT_INTERSECTION
};


class Listener {
public:
    virtual void notify(Event event) = 0;
};


#endif //RENDERER_LISTENER_H
