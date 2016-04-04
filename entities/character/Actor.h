#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#include <string>
#include "sprite.h"
using namespace std;


class Actor{

    public:

    Actor();
    virtual ~Actor();


    private:

    bool m_Active;
    bool m_Mobile;

    Sprite* m_Sprite;

};



#endif // ACTOR_H_INCLUDED
