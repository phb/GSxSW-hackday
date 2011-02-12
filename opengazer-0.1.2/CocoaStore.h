#pragma once
#include "OutputMethods.h"
#include "GraphicalPointer.h"


class WindowStore: public AbstractStore {
 public:
    WindowStore(const WindowPointer::PointerSpec& pointerspec,
		const WindowPointer::PointerSpec& targetspec);
    ~WindowStore();
    virtual void store(const TrackerOutput &output);
};
