//
// Created by omer on 1/19/18.
//

#include "RenderLog.h"

void RenderLog::notify(Event event) {
    switch (event) {
        case START_RENDERING:
            cout << "rendering..." << endl;
            break;
        case END_RENDERING:
            cout << "-end rendering-" << endl;
            break;
        case WRITE_BMP:
            cout << "write BMP file of the finale render" << endl;
            break;
    }
}