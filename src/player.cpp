#include "player.h"
#include "gameobject.h"

Player :: Player( float _vx, float _y ) : GameObject( _vx, 0, 0, _y )
{
}

//---------------------------------------------------

#include "minitest.h"

MINI_TEST( player )
{
	Player p1( 4 , 0);
	p1.updatePos();
	float x,y;
	p1.getPos( x, y );
	MINI_CHECK( x == 4 );
	MINI_CHECK( y == 0 );
}
