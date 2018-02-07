//
// Created by omer on 1/19/18.
//

#ifndef RENDERER_NOTIFIER_H
#define RENDERER_NOTIFIER_H

#include <vector>
#include "Listener.h"

using namespace std;

class Notifier {
public:
    virtual void notifyAll(Event event) {
        for (vector<Listener *>::iterator it = this->listeners.begin();
             it != this->listeners.end(); it++) {
            (*it)->notify(event);
        }
    }
    virtual void addListener(Listener &listener) {
        this->listeners.push_back(&listener);
    }
    virtual void removeListener(Listener &listener) {
        for (vector<Listener *>::iterator it = this->listeners.begin();
             it != this->listeners.end(); it++) {
            if (*it == &listener) {
                this->listeners.erase(it);
                break;
            }
        }
    }
private:
    vector<Listener *> listeners;
};


#endif //RENDERER_NOTIFIER_H
