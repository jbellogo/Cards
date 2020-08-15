#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>


class Observer;

class Subject {
std::vector<std::shared_ptr<Observer> > observers;

public:
void attach(Observer *o);
void notifyObservers();
virtual int donothing() const = 0;
};

#endif
