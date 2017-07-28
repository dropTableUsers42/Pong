#ifndef INC_GAMEOBJECT_H
#define INC_GAMEOBJECT_H

class GameObject
{
public:
	GameObject(float _vx, float _vy, float _x, float _y);
	void setVel( float _vx, float _vy );
	void getPos( float & _x, float & _y );
	void updatePos();
private:
	float x;
	float y;
	float vx;
	float vy;
};

#endif
