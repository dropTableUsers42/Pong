#include "gameobject.h"

GameObject :: GameObject( float _x, float _y, float _vx, float _vy )
	: x( _x ), y( _y ), vx( _vx ), vy( _vy )
{
}

void GameObject :: setVel( float _vx, float _vy )
{
	vx = _vx;
	vy = _vy;
}

void GameObject :: updatePos()
{
	x += vx;
	y += vy;
}

void GameObject :: getPos( float & _x, float & _y )
{
	_x = x;
	_y = y;
}

//------------------------------------

#include "minitest.h"

MINI_TEST( GameObject_velocity )
{
	GameObject go( 5, 5, 3, 4 );
	go.updatePos();
	float x,y;
	go.getPos( x, y );
	MINI_CHECK( x == 8 );
	MINI_CHECK( y == 9 );
}
